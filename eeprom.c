/*
 * eeprom.c
 *
 */

#include "eeprom.h"

cyhal_spi_t mSPI;

/** Initializes the IO pins used to control the CS of the
 *  EEPROM
 *
 * @param
 *
 */
cy_rslt_t eeprom_cs_init(void)
{
}

/** Determine if the EEPROM is busy writing the last
 *  transaction to non-volatile storage
 *
 * @param
 *
 */
cy_rslt_t eeprom_wait_for_write(void)
{
}

/** Enables Writes to the EEPROM
 *
 * @param
 *
 */
cy_rslt_t eeprom_write_enable(void)
{
}

/** Disable Writes to the EEPROM
 *
 * @param
 *
 */
cy_rslt_t eeprom_write_disable(void)
{
}


/** Writes a single byte to the specified address
 *
 * @param address -- 16 bit address in the EEPROM
 * @param data    -- value to write into memory
 *
 */
cy_rslt_t eeprom_write_byte(uint16_t address, uint8_t data)
{
	return cyhal_spi_send(address, data);
}

/** Reads a single byte to the specified address
 *
 * @param address -- 16 bit address in the EEPROM
 * @param data    -- value read from memory
 *
 */
cy_rslt_t eeprom_read_byte(uint16_t address, uint8_t *data)
{
	return cyhal_spi_recv(address, data);
}


/** Tests Writing and Reading the EEPROM
 *
 * @param
 *
 */
cy_rslt_t eeprom_test(void)
{
	uint8_t i;
	uint16_t addr;
	cy_rslt_t   rslt;
	uint8_t data;
	uint8_t expected_data;

	// Write the data to the eeprom.
	addr = 0x20;
	data = 0x10;
	for(i = 0; i < 20; i++)
	{
		rslt = eeprom_write_byte(addr, data);
		if(rslt != CY_RSLT_SUCCESS)
		{
			printf("* -- EEPROM WRITE FAILURE\n\r");
			return -1;
		}
		addr++;
		data++;
	}

	// Read the data back and verify everything matches what was written
	addr = 0x20;
	expected_data = 0x10;
	for(i = 0; i < 20; i++)
	{
		rslt = eeprom_read_byte(addr, &data);
		if(rslt != CY_RSLT_SUCCESS)
		{
			printf("* -- EEPROM READ FAILURE\n\r");
			return -1;
		}
		if(expected_data != data)
		{
			printf("* -- EEPROM READ DATA DOES NOT MATCH\n\r");
			return -1;
		}

		addr++;
		expected_data++;
	}
	printf("* -- EEPROM Test Passed\n\r");
	return CY_RSLT_SUCCESS;
}
