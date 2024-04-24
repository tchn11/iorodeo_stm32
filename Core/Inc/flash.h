#ifndef INC_FLASH_STORE_DATA_H_
#define INC_FLASH_STORE_DATA_H_

#include "stdio.h"
#include "main.h"

void store_flash_memory(uint32_t memory_address, uint8_t *data, uint16_t data_length);
void read_flash_memory(uint32_t memory_address, uint8_t *data, uint16_t data_length);


#endif /* INC_FLASH_STORE_DATA_H_ */
