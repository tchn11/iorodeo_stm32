/*
 * external_analog.cpp
 *
 *  Created on: Apr 16, 2024
 *      Author: akona
 */

#include "stm32f4xx_hal_spi.h"
#include "exteranl_analog.h"

spi_analog::spi_analog()
{
	SPIx = ANALOG_SPI;
	pin_cs1 = REF_ELECT_UNI_cs_pin;
	GPIOx_cs1 = REF_ELECT_UNI_cs_GPIO_Port;
	pin_rd1 = REF_ELECT_UNI_rd_pin;
	GPIOx_rd1 =  REF_ELECT_UNI_rd_GPIO_Port;
	pin_cs2 = TIA_OUT_UNI_cs_pin;
	GPIOx_cs2 = TIA_OUT_UNI_cs_GPIO_Port;
	pin_rd2 = TIA_OUT_UNI_rd_pin;
	GPIOx_rd2 =  TIA_OUT_UNI_rd_GPIO_Port;

	HAL_GPIO_WritePin(GPIOx_cs1, pin_cs1, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOx_cs2, pin_cs2, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOx_cs1, pin_cs1, GPIO_PIN_RESET);
	HAL_SPI_Transmit(SPIx, 0x08, 1, 128);
	HAL_SPI_Transmit(SPIx, 0x200A, 2, 128);
	HAL_GPIO_WritePin(GPIOx_cs1, pin_cs1, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOx_cs2, pin_cs1, GPIO_PIN_RESET);
	HAL_SPI_Transmit(SPIx, 0x08, 1, 128);
	HAL_SPI_Transmit(SPIx, 0x200A, 2, 128);
	HAL_GPIO_WritePin(GPIOx_cs2, pin_cs1, GPIO_PIN_SET);
}

void spi_analog::work()
{
	if (HAL_GPIO_ReadPin(GPIOx_rd1, pin_rd1))
	{
		HAL_GPIO_WritePin(GPIOx_cs1, pin_cs1, GPIO_PIN_RESET);
		HAL_SPI_Transmit(SPIx, 0x58, 1, 128);
		HAL_SPI_Receive(SPIx, value1, 2, 128);
		HAL_GPIO_WritePin(GPIOx_cs1, pin_cs1, GPIO_PIN_SET);
	}

	if (HAL_GPIO_ReadPin(GPIOx_rd2, pin_rd2))
	{
		HAL_GPIO_WritePin(GPIOx_cs2, pin_cs2, GPIO_PIN_RESET);
		HAL_SPI_Transmit(SPIx, 0x58, 1, 128);
		HAL_SPI_Receive(SPIx, value1, 2, 128);
		HAL_GPIO_WritePin(GPIOx_cs2, pin_cs2, GPIO_PIN_SET);
	}
}
