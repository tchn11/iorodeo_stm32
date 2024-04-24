/*
 * external_analog.cpp
 *
 *  Created on: Apr 16, 2024
 *      Author: akona
 */
#include "stm32f4xx.h"

#include "stm32f4xx_hal_spi.h"
#include "exteranl_analog.h"
#include "main.h"

static uint8_t config_adress = 0x08;
static uint16_t config = 0x200A;
static uint8_t data_adress = 0x58;

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
	HAL_SPI_Transmit(SPIx, &config_adress, 1, 128);
	HAL_SPI_Transmit(SPIx, (uint8_t*)&config, 2, 128);
	HAL_GPIO_WritePin(GPIOx_cs1, pin_cs1, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOx_cs2, pin_cs1, GPIO_PIN_RESET);
	HAL_SPI_Transmit(SPIx, &config_adress, 1, 128);
	HAL_SPI_Transmit(SPIx, (uint8_t*)&config, 2, 128);
	HAL_GPIO_WritePin(GPIOx_cs2, pin_cs1, GPIO_PIN_SET);
}

void spi_analog::work()
{
	if (HAL_GPIO_ReadPin(GPIOx_rd1, pin_rd1))
	{
		HAL_GPIO_WritePin(GPIOx_cs1, pin_cs1, GPIO_PIN_RESET);
		HAL_SPI_Transmit(SPIx, &data_adress, 1, 128);
		HAL_SPI_Receive(SPIx, (uint8_t*)&value1, 2, 128);
		HAL_GPIO_WritePin(GPIOx_cs1, pin_cs1, GPIO_PIN_SET);
	}

	if (HAL_GPIO_ReadPin(GPIOx_rd2, pin_rd2))
	{
		HAL_GPIO_WritePin(GPIOx_cs2, pin_cs2, GPIO_PIN_RESET);
		HAL_SPI_Transmit(SPIx, &data_adress, 1, 128);
		HAL_SPI_Receive(SPIx, (uint8_t*)&value1, 2, 128);
		HAL_GPIO_WritePin(GPIOx_cs2, pin_cs2, GPIO_PIN_SET);
	}
}
