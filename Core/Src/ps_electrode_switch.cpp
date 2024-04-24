#include "ps_electrode_switch.h"
#include "ps_pin_map.h"

#if defined HARDWARE_VERSION_0P2

namespace ps
{
    ElectrodeSwitch::ElectrodeSwitch() {}

    void ElectrodeSwitch::initialize() 
    {
        //pinMode(SW_CTR_ELECT, OUTPUT);
        //pinMode(SW_REF_ELECT, OUTPUT);
        //pinMode(SW_WRK_ELECT, OUTPUT);

    }

    bool ElectrodeSwitch::connected(GPIO_TypeDef* GPIOx, int pin)
    {
        uint8_t value = HAL_GPIO_ReadPin(GPIOx, pin);
        if (value == GPIO_PIN_SET)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    void ElectrodeSwitch::setConnected(GPIO_TypeDef* GPIOx, int pin, bool value)
    {
        if (value)
        {
            HAL_GPIO_WritePin(GPIOx, pin, GPIO_PIN_RESET);
        } 
        else
        {
            HAL_GPIO_WritePin(GPIOx, pin, GPIO_PIN_SET);
        }
    }


    bool ElectrodeSwitch::ctrConnected()
    {
        return connected(SW_CTR_ELECT_GPIO_Port, SW_CTR_ELECT_Pin);
    }

    void ElectrodeSwitch::setCtrConnected(bool value)
    {
        setConnected(SW_CTR_ELECT_GPIO_Port, SW_CTR_ELECT_Pin, value);
    }

    bool ElectrodeSwitch::refConnected()
    {
        return connected(SW_REF_ELECT_GPIO_Port, SW_REF_ELECT_Pin);
    }

    void ElectrodeSwitch::setRefConnected(bool value)
    {
        setConnected(SW_REF_ELECT_GPIO_Port, SW_REF_ELECT_Pin, value);
    }

    bool ElectrodeSwitch::wrkConnected()
    {
        return connected(SW_REF_ELECT_GPIO_Port, SW_REF_ELECT_Pin);
    }

    void ElectrodeSwitch::setWrkConnected(bool value)
    {
        setConnected(SW_REF_ELECT_GPIO_Port, SW_REF_ELECT_Pin, value);
    }

    bool ElectrodeSwitch::allConnected()
    {
        return ctrConnected() && refConnected() && wrkConnected();
    }

    void ElectrodeSwitch::setAllConnected(bool value)
    {
        setCtrConnected(value);
        setRefConnected(value);
        setWrkConnected(value); 
    }
}

#endif // if defined HARDWARE_VERSION_0P2
