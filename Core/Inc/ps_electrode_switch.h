#ifndef PS_ELECTRODE_SWITCH_H
#define PS_ELECTRODE_SWITCH_H
#include "ps_hardware_defs.h"
#include "stm32f4xx.h"
#include "stm32f4xx_hal_gpio.h"

#if defined HARDWARE_VERSION_0P2

namespace ps 
{
    class ElectrodeSwitch
    {
        public:
            ElectrodeSwitch();
            void initialize();

            bool connected(GPIO_TypeDef* GPIOx, int pin);
            void setConnected(GPIO_TypeDef* GPIOx, int pin, bool value);

            bool ctrConnected();
            void setCtrConnected(bool value);

            bool refConnected();
            void setRefConnected(bool value);

            bool wrkConnected();
            void setWrkConnected(bool value);

            bool allConnected();
            void setAllConnected(bool value);

    };

}
#endif // if defined HARDWARE_VERSION
#endif // ifndef PS_ELECTRODE_SWITCH_H
