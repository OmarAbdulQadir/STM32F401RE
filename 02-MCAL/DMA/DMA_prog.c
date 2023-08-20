/******************************************************************************************/

#include "../Inc/STD_TYPES.h"
#include "../Inc/BIT_MATH.h"

#include "../Inc/DMA_private.h"
#include "../Inc/DMA_config.h"
#include "../Inc/DMA_interface.h"

/******************************************************************************************/
void ( *DMA_CallBackChannel1 )( void ) = NULL;
DMA_t * DMA_xbaseAdd[2] = {DMA_1, DMA_2};

void DMA_vInit(u8 Copy_u8DMA_ID, u8 Copy_u8SreamID, DMA_Stream_config* DMA_Stream_config)
{
	if((Copy_u8DMA_ID < MAX_DMAID) && (Copy_u8SreamID <= MAX_StreamID) && (((u32) (DMA_Stream_config -> CR_CHSEL)) <= Max_channelID)){
		/* 1- Before Any Config The Bit Of EN Must = 0 ,It must Be Disable*/
		/* Use Stream NUM = 0 */
		/* If Enable Bit == 1 */
		CLR_BIT(DMA_xbaseAdd[Copy_u8DMA_ID]-> StreamID[Copy_u8SreamID].CR, DMAx_Sx_CR_EN);
		/* 2- Select The Channel (Used For Connect Peripheral To Memory) In stream  But From Memory To Memory Not Use*/
		DMA_xbaseAdd[Copy_u8DMA_ID] -> StreamID[Copy_u8SreamID].CR &= DMAx_Sx_CR_mask;
		DMA_xbaseAdd[Copy_u8DMA_ID] -> StreamID[Copy_u8SreamID].CR |= (((u32) (DMA_Stream_config -> CR_CHSEL)) << DMAx_Sx_CR_CHSEL);
		/* 3-SoftWare Priority Stream :{ LOW , Medium , High , VeryHigh} BIT(16 , 17)---> VeryHigh  */
		DMA_xbaseAdd[Copy_u8DMA_ID] -> StreamID[Copy_u8SreamID].CR |= (((u32) (DMA_Stream_config -> CR_PL)) << DMAx_Sx_CR_PL);
		/* 4- Set DIR Mode :{ (MTM) ,PTM ,MTP} BIT (6,7) */
		DMA_xbaseAdd[Copy_u8DMA_ID] -> StreamID[Copy_u8SreamID].CR |= (((u32) (DMA_Stream_config -> CR_DIR)) << DMAx_Sx_CR_DIR);
		/* 5- Set M & M SIZE BIT(13,14) ,(11,12) :{Byte , HaveWord , (Word)}*/
		/* 	As Word 32 For Source	*/
		DMA_xbaseAdd[Copy_u8DMA_ID] -> StreamID[Copy_u8SreamID].CR |= (((u32) (DMA_Stream_config -> CR_MSIZE)) << DMAx_Sx_CR_MSIZE);
		/* 	As Word 32 For Destination	*/
		DMA_xbaseAdd[Copy_u8DMA_ID] -> StreamID[Copy_u8SreamID].CR |= (((u32) (DMA_Stream_config -> CR_PSIZE)) << DMAx_Sx_CR_PSIZE);
		/* 6- Disable Direct Mode to used FIFO  */
		DMA_xbaseAdd[Copy_u8DMA_ID] -> StreamID[Copy_u8SreamID].FCR &= (~((u32) (DMAx_Sx_FCR_mask)));
		DMA_xbaseAdd[Copy_u8DMA_ID] -> StreamID[Copy_u8SreamID].FCR |= (((u32) (DMA_Stream_config -> FCR_DMDIS)) << DMAx_Sx_FCR_DMDIS);
		/* 7-Set FIFO Threshold {(1/4),(1/2),(3/4),full} */
		/* Use (1/2)*/
		DMA_xbaseAdd[Copy_u8DMA_ID] -> StreamID[Copy_u8SreamID].FCR |= ((u32) (DMA_Stream_config -> FCR_FTH));
		/* 8-SRC & DIS increment For Both */
		DMA_xbaseAdd[Copy_u8DMA_ID] -> StreamID[Copy_u8SreamID].CR |= (((u32) (DMA_Stream_config -> CR_MINC)) << DMAx_Sx_CR_MINC);
		DMA_xbaseAdd[Copy_u8DMA_ID] -> StreamID[Copy_u8SreamID].CR |= (((u32) (DMA_Stream_config -> CR_PINC)) << DMAx_Sx_CR_PINC);
		/* 9- EN interrupt Of transfer complete */
		DMA_xbaseAdd[Copy_u8DMA_ID] -> StreamID[Copy_u8SreamID].CR |= (((u32) (DMA_Stream_config -> CR_TCIE)) << DMAx_Sx_CR_TCIE);
	}
}



void DMA_vSetAddress(u8 Copy_u8DMA_ID, u8 Copy_u8SreamID, u32 *Ptr_u32SrcAdd , u32 *Ptr_u32DistAdd , u32 Copy_u32Size )
{
	if((Copy_u8DMA_ID < MAX_DMAID) && (Copy_u8SreamID <= MAX_StreamID)){
		CLR_BIT(DMA_xbaseAdd[Copy_u8DMA_ID] -> StreamID[Copy_u8SreamID].CR, DMAx_Sx_CR_EN);
		DMA_xbaseAdd[Copy_u8DMA_ID] -> StreamID[Copy_u8SreamID].NDTR = Copy_u32Size;
		DMA_xbaseAdd[Copy_u8DMA_ID] -> StreamID[Copy_u8SreamID].PAR = (u32)Ptr_u32SrcAdd;
		DMA_xbaseAdd[Copy_u8DMA_ID] -> StreamID[Copy_u8SreamID].M0AR = (u32)Ptr_u32DistAdd;
	}
}

void DMA_vStreamEnable(u8 Copy_u8DMA_ID, u8 Copy_u8SreamID )
{
	/* All Flag == 0 or make them =0 */
	SET_BIT((DMA_xbaseAdd[Copy_u8DMA_ID] -> StreamID[Copy_u8SreamID].CR), DMAx_Sx_CR_EN);
}


void DMA_VidSetCallBackChannel1( void ( *Ptr ) ( void ) ){

	DMA_CallBackChannel1 = Ptr ;

}

void DMA1_Channel1_IRQHandler(void){

	DMA_CallBackChannel1();

}
/******************************************************************************************/

/********************************
DMA STEPS
*********************************
	/*Enable clock access to DMA*/

	/*Disable DMA1 Stream6*/ //CR

    /*Wait until DMA1 Stream 6 is disabled */ //CR

	/*Clear all interrupt flags of Stream6*/ //HIFCR

	/*Set the destination buffer*/  //PAR

	/*Set the source buffer*/  //M0AR

	/*Set length*/  //NDTR

	/*Select Stream6 CH4*/ //CR

	/*Enable memory increment*/  //CR

	/*Configure transfer direction*/  //CR

	/*Enable DMA transfer complete interrupt*/  //CR

	/*Enable direct mode and disable FIFO*/  //FCR

	/*Enable DMA1 Stream6*/  //CR

	/*Enable UART2 transmitter DMA*/  // UART DMA

	/*DMA Interrupt enable in NVIC*/// NVIC_EnableIRQ(DMA1_Stream6_IRQn);

/*******************************/

