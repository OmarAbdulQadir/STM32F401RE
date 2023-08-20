
/*************************************************************************************
*************************************************************************************/

#ifndef DMA_INTERFACE_H
#define DMA_INTERFACE_H

#define DMA_1ID		0
#define	DMA_2ID		1

typedef struct {
	u32 CR_CHSEL	: 3;		// Channel selection
	u32 CR_PL		: 2;		// Priority selection
	u32	CR_MSIZE	: 2;		// Memory size
	u32 CR_PSIZE	: 2;		// Peripheral size
	u32 CR_MINC		: 1;		// Memory increment
	u32 CR_PINC		: 1;		// Peripheral increment
	u32 CR_DIR		: 2;		// Direction
	u32 CR_TCIE		: 1;		// Transfer complete interrupt
	u32 FCR_FTH		: 2;		// FIFO threshold selection
	u32 FCR_DMDIS	: 1;		// Direct mode disable
}DMA_Stream_config;

/* DMA init */
void DMA_vInit(u8 Copy_u8DMA_ID, u8 Copy_u8SreamID, DMA_Stream_config* DMA_Stream_config);
/* Function to set source and destination */
void DMA_vSetAddress(u8 Copy_u8DMA_ID, u8 Copy_u8SreamID, u32 *Ptr_u32SrcAdd , u32 *Ptr_u32DistAdd , u32 Copy_u32Size );
/* Func To enable DMA */
void DMA_vStreamEnable(u8 Copy_u8DMA_ID, u8 Copy_u8SreamID );



#endif 
/*************************************************************************************/
