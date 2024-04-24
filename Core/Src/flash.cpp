#include "flash.h"
#include "stdint.h"
#include "stm32f4xx.h"
#include "stm32f4xx_it.h"


typedef uint64_t flash_datatype;
#define DATA_SIZE sizeof(flash_datatype)


void store_flash_memory(uint32_t memory_address, uint8_t *data, uint16_t data_length)
{
   uint8_t double_word_data[DATA_SIZE];
   FLASH_EraseInitTypeDef flash_erase_struct = {0};
   HAL_FLASH_Unlock();
   // defining the members of a struct
   flash_erase_struct.TypeErase = FLASH_TYPEERASE_SECTORS;
   // defining an onset number page to be erased

   // erase the pages, this step is mandatory
   //HAL_FLASHEx_Erase(&flash_erase_struct, &error_status);
   int i = 0;
   // using while loop, convey all data to the flash memory
   while ( i <= data_length)
   {
	double_word_data[i % DATA_SIZE] = data[i];
	i++;
	if (i % DATA_SIZE == 0)
	{
	  HAL_FLASH_Program(FLASH_TYPEPROGRAM_DOUBLEWORD, memory_address + i -
		DATA_SIZE, *((uint64_t *)double_word_data));

	}
   }
   // convey data if something left
   if (i % DATA_SIZE != 0)
   {
	HAL_FLASH_Program(FLASH_TYPEPROGRAM_DOUBLEWORD, memory_address + i
		- i % DATA_SIZE, *((flash_datatype *)double_word_data));
   }
	// lock the memory
   HAL_FLASH_Lock();
}

void read_flash_memory(uint32_t memory_address, uint8_t *data, uint16_t data_length)
{
    for(int i = 0; i < data_length; i++)
    {
	*(data + i) = (*(uint8_t *)(memory_address + i));
    }
}

