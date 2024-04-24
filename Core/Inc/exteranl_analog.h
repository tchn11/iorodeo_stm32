/*
 * exteranl_analog.h
 *
 *  Created on: Apr 16, 2024
 *      Author: akona
 */

#ifndef INC_EXTERANL_ANALOG_H_
#define INC_EXTERANL_ANALOG_H_

#include "stm32f4xx.h"

#include "stm32f4xx_hal_gpio.h"
#include "stm32f4xx_hal_spi.h"
#include "ps_pin_map.h"

class spi_analog {
private:
	uint16_t value1;
	uint16_t value2;
	SPI_HandleTypeDef* SPIx;
	GPIO_TypeDef* GPIOx_cs1;
	uint16_t pin_cs1;

	GPIO_TypeDef* GPIOx_rd1;
	uint16_t pin_rd1;

	GPIO_TypeDef* GPIOx_cs2;
	uint16_t pin_cs2;

	GPIO_TypeDef* GPIOx_rd2;
	uint16_t pin_rd2;

public:
	spi_analog();
	uint16_t getVal1() const
	{ return value1; }
	uint16_t getVal2() const
	{ return value2; }

	void work();
};

#endif /* INC_EXTERANL_ANALOG_H_ */
