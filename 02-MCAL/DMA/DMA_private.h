
/*************************************************************************************
*************************************************************************************/ 


#ifndef DMA_PRIVATE_H
#define DMA_PRIVATE_H


/***********************************************************************************
----->STRUCT
*  Register Map :SYSCFG
************************************************************************************/


typedef struct 
{
	volatile u32 CR;
	volatile u32 NDTR;
	volatile u32 PAR;
	volatile u32 M0AR;
	volatile u32 M1AR;
	volatile u32 FCR;
	
}DMA_STREAM_t;


typedef struct 
{
	volatile u32 LISR;
	volatile u32 HISR;
	volatile u32 LIFCR;
	volatile u32 HIFCR;
	volatile DMA_STREAM_t StreamID[8];
	
}DMA_t;

/***********************************************************************************
	-----> Macros
			*  Base_Address DMA_2       --> 0x4002 6400 	
			*  Base_Address DMA_2       --> 0x4002 6000
************************************************************************************/

#define DMA_1           		((volatile DMA_t* ) 0x40026000u)
#define DMA_2           		((volatile DMA_t* ) 0x40026400u)

#define MAX_DMAID				2
#define MAX_StreamID			7
#define Max_channelID			7
#define	DMAx_Sx_CR_mask			0
#define DMAx_Sx_FCR_mask		0b111u

/* Control register */
#define DMAx_Sx_CR_EN			0
#define DMAx_Sx_CR_TCIE			4
#define DMAx_Sx_CR_DIR			6
#define	DMAx_Sx_CR_PINC			9
#define	DMAx_Sx_CR_MINC			10
#define DMAx_Sx_CR_PSIZE		11
#define DMAx_Sx_CR_MSIZE		13
#define DMAx_Sx_CR_PL			16
#define	DMAx_Sx_CR_CHSEL		25


#define DMAx_Sx_FCR_DMDIS		2

#endif 
/***********************************************************************************/
