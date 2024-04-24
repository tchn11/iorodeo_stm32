#ifndef PS_CONSTANTS_H
#define PS_CONSTANTS_H

#include "ps_hardware_defs.h"
#include "ps_volt_range.h"
#include "ps_curr_range.h"
#include "ps_filter.h"
#include "Array.h"
#include "string"
#include "stdint.h"
using namespace std;
//#if defined DEVBOARD_ITSY_BITSY
//    #include "FlashStorage.h"
//#endif


namespace ps
{
    extern const string FirmwareVersion;
    extern const string HardwareVariant;
#if defined HARDWARE_VERSION_0P2
    extern const string HardwareVersion;
#endif

    // Command tabe parameters
    const uint32_t CommandTableMaxSize = 50;
    
    // Buffer parameters
    const uint32_t DataBufferSize = 1000;
    const uint32_t SerialBufferSize = 2000; 
    const uint32_t JsonMessageBufferSize = 4000;
    const uint32_t JsonTestDataBufferSize = 4000;

#if defined DEVBOARD_TEENSY
    // Device ID EEPROM address
    extern const uint32_t EEPROM_DeviceIdAddress;
#endif

    // Serial parameters
    extern const uint32_t UsbSerialBaudrate;

    // Json message keys 
    extern const string CommandKey;
    extern const string ResponseKey;
    extern const string MessageKey;
    extern const string SuccessKey;
    extern const string TimeKey;
    extern const string VoltKey;
    extern const string CurrKey;
    extern const string ChanKey;
    extern const string RefVoltKey;
    extern const string ParamKey;
    extern const string VoltRangeKey;
    extern const string CurrRangeKey;
    extern const string QuietValueKey;
    extern const string QuietTimeKey;
    extern const string DurationKey;
    extern const string ValueKey;
    extern const string StartValueKey;
    extern const string FinalValueKey;
    extern const string StepValueKey;
    extern const string AmplitudeKey;
    extern const string OffsetKey;
    extern const string PeriodKey;
    extern const string NumCyclesKey;
    extern const string ShiftKey;
    extern const string WindowKey;
    extern const string DeviceIdKey;
    extern const string SamplePeriodKey;
    extern const string TestDoneTimeKey;
    extern const string StepArrayKey;
    extern const string TestNameArrayKey;
    extern const string VersionKey;
    extern const string VariantKey;
    extern const string MuxEnabledKey;
    extern const string MuxChannelKey;
    extern const string ConnectedKey;
#if defined HARDWARE_VERSION_0P2
    extern const string ElectAutoConnectKey;
#endif


    // Json command strings
    extern const string RunTestCmd;
    extern const string StopTestCmd;
    extern const string GetVoltCmd;
    extern const string SetVoltCmd;
    extern const string GetCurrCmd;
    extern const string GetRefVoltCmd;
    extern const string SetParamCmd;
    extern const string GetParamCmd;
    extern const string SetVoltRangeCmd;
    extern const string GetVoltRangeCmd;
    extern const string SetCurrRangeCmd;
    extern const string GetCurrRangeCmd;
    extern const string SetDeviceIdCmd;
    extern const string GetDeviceIdCmd;
    extern const string SetSamplePeriodCmd;
    extern const string GetSamplePeriodCmd;
    extern const string GetTestDoneTimeCmd;
    extern const string GetTestNamesCmd;
    extern const string GetVersionCmd;
    extern const string GetVariantCmd;
    extern const string SetMuxEnabledCmd;
    extern const string GetMuxEnabledCmd;
    extern const string SetEnabledMuxChanCmd;
    extern const string GetEnabledMuxChanCmd;
    extern const string GetMuxTestNamesCmd;
    extern const string SetMuxRefElectConnCmd;
    extern const string GetMuxRefElectConnCmd;
    extern const string SetMuxCtrElectConnCmd;
    extern const string GetMuxCtrElectConnCmd;
    extern const string SetMuxWrkElectConnCmd;
    extern const string GetMuxWrkElectConnCmd;
    extern const string DisconnAllMuxElectCmd;
#if defined HARDWARE_VERSION_0P2
    extern const string SetRefElectConnCmd;
    extern const string GetRefElectConnCmd;
    extern const string SetCtrElectConnCmd;
    extern const string GetCtrElectConnCmd;
    extern const string SetWrkElectConnCmd;
    extern const string GetWrkElectConnCmd;
    extern const string SetAllElectConnCmd;
    extern const string GetAllElectConnCmd;
    extern const string SetElectAutoConnCmd;
    extern const string GetElectAutoConnCmd;
    extern const string SetRefElectVoltRangeCmd;
    extern const string GetRefElectVoltRangeCmd;
    extern const string GetHardwareVersionCmd;
#endif

    // Ranges for output voltage
    extern const VoltRangeDac VoltRangeDac1V; 
    extern const VoltRangeDac VoltRangeDac2V; 
    extern const VoltRangeDac VoltRangeDac5V; 
    extern const VoltRangeDac VoltRangeDac10V; 

    const uint8_t NumVoltRangeDac = 4;
    extern Array<VoltRangeDac,NumVoltRangeDac> VoltRangeDacArray;
    extern const float SignDac; 

    // Range for reference electrode analog input
    extern const VoltRangeAdc VoltRangeAdc1V;
    extern const VoltRangeAdc VoltRangeAdc2V;
    extern const VoltRangeAdc VoltRangeAdc5V;
    extern const VoltRangeAdc VoltRangeAdc10V;

    const uint8_t NumVoltRangeAdc = 4;
    extern Array<VoltRangeAdc,NumVoltRangeAdc> VoltRangeAdcArray;
    extern const float SignAdc; 

    // Ranges for input current
    extern const CurrRange CurrRange1uA; 
    extern const CurrRange CurrRange10uA; 
    extern const CurrRange CurrRange100uA; 
    extern const CurrRange CurrRange1000uA; 

    const uint8_t NumCurrRange = 4;
    extern Array<CurrRange,NumCurrRange> CurrRangeArray;
    extern const float SignCurr;

    // Timer parameters
    extern const uint32_t TestTimerPeriod;      // us
    extern const uint32_t DefaultSamplePeriod;  // us
    extern const uint32_t MinimumSamplePeriod;  // us
    extern const uint32_t MaximumSamplePeriod;  // us

    // Low pass filter params for current samples
    extern const LowPassParam CurrLowPassParam;

    // Test parameters
    const uint32_t AvailableTestsMaxSize = 20;
    const uint32_t MultiStepMaxSize = 50;

    enum SampleMethod {SampleGeneric, SampleCustom};

    // Multiplexer Parameters
#if defined MUX_CAPABLE
    const uint8_t NumMuxChan = 7;
    const uint8_t NumMuxPin = 16;
#else
    const uint8_t NumMuxChan = 1;
    const uint8_t NumMuxPin = 1;
#endif

} // namespace ps

#endif
