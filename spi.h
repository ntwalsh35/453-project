/*
 */

#ifndef SPI_H__
#define SPI_H__

#include "cy_pdl.h"
#include "cyhal.h"
#include "cybsp.h"

/* Macros */
/* ADD CODE */
#define PIN_MCU_SPI_MOSI	0
#define PIN_MCU_SPI_MISO	0
#define PIN_MCU_SPI_CLK		0
#define PIN_MCU_SPI_CS		0

#define SPI_FREQ			1000000

/* Public Global Variables */
extern cyhal_spi_t mSPI;



/* Public API */
cy_rslt_t spi_init(void);

#endif 
