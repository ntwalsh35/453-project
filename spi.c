/*
 * spi.c
 *
 */

#include <spi.h>


cyhal_spi_t mSPI;

cy_rslt_t spi_init(void)
{
	cy_rslt_t   rslt;
    // Configuring the  SPI master:  Specify the SPI interface pins, frame size,
    // SPI Motorola mode and master mode
	rslt = cyhal_spi_init(&mSPI, PIN_MCU_SPI_MOSI, PIN_MCU_SPI_MISO, PIN_MCU_SPI_CLK, PIN_MCU_SPI_CS, NULL,
	                          8, CYHAL_SPI_MODE_00_MSB, false);
	CY_ASSERT(rslt == CY_RSLT_SUCCESS);
        
    // Set the data rate to 1 Mbps
	rslt = cyhal_spi_set_frequency(&mSPI, SPI_FREQ);
	CY_ASSERT(rslt == CY_RSLT_SUCCESS);
}

