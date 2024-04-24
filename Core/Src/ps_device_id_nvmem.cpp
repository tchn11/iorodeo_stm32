#include "ps_device_id_nvmem.h"
#include "stm32f4xx.h"
#include "stm32f4xx_hal_flash.h"
#include "flash.h"
#include "string"
using namespace std;

#define FLASH_ADDRESS_COUNTER 0x080FF800

namespace ps
{

#if defined DEVBOARD_TEENSY
    DeviceId_NVMEM::DeviceId_NVMEM(uint32_t address)
    {
        address_ = address;
    }
#elif defined DEVBOARD_ITSY_BITSY
    //FlashStorage(Storage,uint32_t);
    DeviceId_NVMEM::DeviceId_NVMEM() {}
#endif

    ReturnStatus DeviceId_NVMEM::set(JsonObject &jsonMsg, JsonObject &jsonDat)
    {
        ReturnStatus status;
        if (!jsonMsg.containsKey(DeviceIdKey))
        {
            status.success = false;
            status.message = string("json does not contain key: ") + DeviceIdKey;
            return status;
        }

        if (!jsonMsg[DeviceIdKey].is<uint32_t>())
        {
            status.success = false;
            status.message = string("deviceId is not integer");
            return status;
        }
        uint32_t device_id = jsonMsg.get<uint32_t>(DeviceIdKey);
	#if defined DEVBOARD_TEENSY
			EEPROM.put(address_,device_id);
	#elif defined DEVBOARD_ITSY_BITSY
			//Storage.write(device_id);
			store_flash_memory(FLASH_ADDRESS_COUNTER, (uint8_t*)&device_id, 4);
	#endif
        get(jsonDat);
        return status;
    }


    void DeviceId_NVMEM::get(JsonObject &jsonDat)
    {
        uint32_t device_id;
#if defined DEVBOARD_TEENSY
        EEPROM.get(address_,device_id);
#elif defined DEVBOARD_ITSY_BITSY
        read_flash_memory(FLASH_ADDRESS_COUNTER, (uint8_t*)&device_id, 4);
        //device_id = Storage.read();
#endif
        jsonDat.set(DeviceIdKey,device_id);
    }

} // namespace ps
