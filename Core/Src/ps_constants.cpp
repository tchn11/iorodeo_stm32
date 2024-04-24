#include "ps_constants.h"
#include "ps_analog_subsystem.h"
#include <initializer_list>
#include <string>
#include <stdint.h>
using namespace std;

namespace ps
{ 
    const string FirmwareVersion = string("FW0.0.9");
#if defined HARDWARE_VERSION_0P1
    const string HardwareVersion = string("V0.1");
#elif defined HARDWARE_VERSION_0P2
    const string HardwareVersion = string("V0.2");
#else
    #error "VOLTAGE_VARIANT must be selected"
#endif

    // Serial parameters
    const uint32_t UsbSerialBaudrate = 115200;

#if defined DEVBOARD_TEENSY
    // Device ID EEPROM address
    const uint32_t EEPROM_DeviceIdAddress = 0;
#endif

    // Json message keys 
    const string CommandKey = string("command");
    const string ResponseKey = string("response");
    const string MessageKey = string("message");
    const string SuccessKey = string("success");
    const string TimeKey = string("t");
    const string VoltKey = string("v");
    const string CurrKey = string("i");
    const string ChanKey = string("n");
    const string RefVoltKey = string("r");
    const string ParamKey = string("param");
    const string VoltRangeKey = string("voltRange");
    const string CurrRangeKey = string("currRange");
    const string QuietValueKey = string("quietValue");
    const string QuietTimeKey = string("quietTime");
    const string DurationKey = string("duration");
    const string ValueKey = string("value");
    const string StartValueKey = string("startValue");
    const string FinalValueKey = string("finalValue");
    const string StepValueKey = string("stepValue");
    const string AmplitudeKey = string("amplitude");
    const string OffsetKey = string("offset");
    const string PeriodKey = string("period");
    const string NumCyclesKey = string("numCycles");
    const string ShiftKey = string("shift");
    const string WindowKey = string("window");
    const string DeviceIdKey = string("deviceId");
    const string SamplePeriodKey = string("samplePeriod");
    const string TestDoneTimeKey = string("testDoneTime");
    const string StepArrayKey = string("step");
    const string TestNameArrayKey = string("testNames");
    const string VersionKey = string("version");
    const string VariantKey = string("variant");
    const string MuxEnabledKey = string("muxEnabled");
    const string MuxChannelKey = string("muxChannel");
    const string ConnectedKey = string("connected");
#if defined HARDWARE_VERSION_0P2
    const string ElectAutoConnectKey = string("autoConnect");
#endif

    // Json command strings
    const string RunTestCmd = string("runTest");
    const string StopTestCmd = string("stopTest");
    const string GetVoltCmd = string("getVolt");
    const string SetVoltCmd = string("setVolt");
    const string GetCurrCmd = string("getCurr");
    const string GetRefVoltCmd = string("getRefVolt");
    const string SetParamCmd = string("setParam");
    const string GetParamCmd = string("getParam");
    const string SetVoltRangeCmd = string("setVoltRange");
    const string GetVoltRangeCmd = string("getVoltRange");
    const string SetCurrRangeCmd = string("setCurrRange");
    const string GetCurrRangeCmd = string("getCurrRange");
    const string SetDeviceIdCmd = string("setDeviceId");
    const string GetDeviceIdCmd = string("getDeviceId");
    const string SetSamplePeriodCmd = string("setSamplePeriod");
    const string GetSamplePeriodCmd = string("getSamplePeriod");
    const string GetTestDoneTimeCmd = string("getTestDoneTime");
    const string GetTestNamesCmd = string("getTestNames");
    const string GetVersionCmd = string("getVersion");
    const string GetVariantCmd = string("getVariant");
    const string SetMuxEnabledCmd = string("setMuxEnabled");
    const string GetMuxEnabledCmd = string("getMuxEnabled");
    const string SetEnabledMuxChanCmd = string("setEnabledMuxChannels");
    const string GetEnabledMuxChanCmd = string("getEnabledMuxChannels");
    const string GetMuxTestNamesCmd = string("getMuxTestNames");
    const string SetMuxRefElectConnCmd = string("setMuxRefElectConnected");
    const string GetMuxRefElectConnCmd = string("getMuxRefElectConnected");
    const string SetMuxCtrElectConnCmd = string("setMuxCtrElectConnected");
    const string GetMuxCtrElectConnCmd = string("getMuxCtrElectConnected");
    const string SetMuxWrkElectConnCmd = string("setMuxWrkElectConnected");
    const string GetMuxWrkElectConnCmd = string("getMuxWrkElectConnected");
    const string DisconnAllMuxElectCmd = string("disconnectAllMuxElect");
#if defined HARDWARE_VERSION_0P2
    const string SetRefElectConnCmd = string("setRefElectConnected");
    const string GetRefElectConnCmd = string("getRefElectConnected");
    const string SetCtrElectConnCmd = string("setCtrElectConnected");
    const string GetCtrElectConnCmd = string("getCtrElectConnected");
    const string SetWrkElectConnCmd = string("setWrkElectConnected");
    const string GetWrkElectConnCmd = string("getWrkElectConnected");
    const string SetAllElectConnCmd = string("setAllElectConnected");
    const string GetAllElectConnCmd = string("getAllElectConnected");
    const string SetElectAutoConnCmd = string("setElectAutoConnect");
    const string GetElectAutoConnCmd = string("getElectAutoConnect");
    const string SetRefElectVoltRangeCmd = string("setRefElectVoltRange");
    const string GetRefElectVoltRangeCmd = string("getRefElectVoltRange");
    const string GetHardwareVersionCmd = string("getHardwareVersion");
#endif


    // Ranges for output voltage
#if defined VOLTAGE_VARIANT_10V
    const string VoltageVariant = string("10V");
    const VoltRangeDac VoltRangeDac1V(string("1V"), -1.0, 1.0, VoltGain1X, AnalogSubsystem::MaxValueDac);
    const VoltRangeDac VoltRangeDac2V(string("2V"), -2.0, 2.0, VoltGain2X, AnalogSubsystem::MaxValueDac);
    const VoltRangeDac VoltRangeDac5V(string("5V"), -5.0, 5.0, VoltGain5X, AnalogSubsystem::MaxValueDac);
    const VoltRangeDac VoltRangeDac10V(string("10V"), -10.0, 10.0, VoltGain10X, AnalogSubsystem::MaxValueDac);
    VoltRangeDac DacArrayTmp[NumVoltRangeDac] = {VoltRangeDac1V, VoltRangeDac2V, VoltRangeDac5V, VoltRangeDac10V};
#elif defined VOLTAGE_VARIANT_AD8250
    const string VoltageVariant = string("AD8250");
    const VoltRangeDac VoltRangeDac1V(string("1V"), -1.0, 1.0, VoltGain1X, AnalogSubsystem::MaxValueDac);
    const VoltRangeDac VoltRangeDac2V(string("2V"), -2.0, 2.0, VoltGain2X, AnalogSubsystem::MaxValueDac);
    const VoltRangeDac VoltRangeDac5V(string("5V"), -5.0, 5.0, VoltGain5X, AnalogSubsystem::MaxValueDac);
    const VoltRangeDac VoltRangeDac10V(string("10V"), -10.0, 10.0, VoltGain10X, AnalogSubsystem::MaxValueDac);
    VoltRangeDac DacArrayTmp[NumVoltRangeDac] = {VoltRangeDac1V, VoltRangeDac2V, VoltRangeDac5V, VoltRangeDac10V};
#elif defined VOLTAGE_VARIANT_AD8251
    const string VoltageVariant = string("AD8251");
    const VoltRangeDac VoltRangeDac1V(string("1V"), -1.0, 1.0, VoltGain1X, AnalogSubsystem::MaxValueDac);
    const VoltRangeDac VoltRangeDac2V(string("2V"), -2.0, 2.0, VoltGain2X, AnalogSubsystem::MaxValueDac);
    const VoltRangeDac VoltRangeDac4V(string("4V"), -4.0, 4.0, VoltGain4X, AnalogSubsystem::MaxValueDac);
    const VoltRangeDac VoltRangeDac8V(string("8V"), -8.0, 8.0, VoltGain8X, AnalogSubsystem::MaxValueDac);
    VoltRangeDac DacArrayTmp[NumVoltRangeDac] = {VoltRangeDac1V, VoltRangeDac2V, VoltRangeDac4V, VoltRangeDac8V};
#else
    #error "VOLTAGE_VARIANT must be selected"
#endif 
    Array<VoltRangeDac,NumVoltRangeDac> VoltRangeDacArray(DacArrayTmp);
    const float SignDac = -1.0; 

    // Range for reference electrode analog input
    const VoltRangeAdc VoltRangeAdc1V(string("1V"), -1.0, 1.0, VoltGain1X, AnalogSubsystem::MaxValueAin);
    const VoltRangeAdc VoltRangeAdc2V(string("2V"), -2.0, 2.0, VoltGain2X, AnalogSubsystem::MaxValueAin);
    const VoltRangeAdc VoltRangeAdc5V(string("5V"), -5.0, 5.0, VoltGain5X, AnalogSubsystem::MaxValueAin);
    const VoltRangeAdc VoltRangeAdc10V(string("10V"), -10.0, 10.0, VoltGain10X, AnalogSubsystem::MaxValueAin);
    VoltRangeAdc AdcArrayTmp[NumVoltRangeAdc] = {VoltRangeAdc1V, VoltRangeAdc2V, VoltRangeAdc5V, VoltRangeAdc10V};
    Array<VoltRangeAdc,NumVoltRangeAdc> VoltRangeAdcArray(AdcArrayTmp);
    const float SignAdc = 1.0; 

    // Ranges for input current
#if defined CURRENT_VARIANT_NANO_AMP
    const string CurrentVariant = string("nanoAmp");
    const CurrRange CurrRange1uA("1uA", -1.0, 1.0, CurrGainPathIn1, AnalogSubsystem::MaxValueAin); 
    const CurrRange CurrRange10uA("10uA", -10.0, 10.0, CurrGainPathIn2, AnalogSubsystem::MaxValueAin); 
    const CurrRange CurrRange60nA("60nA", -0.06, 0.06, CurrGainPathIn3, AnalogSubsystem::MaxValueAin); 
    const CurrRange CurrRange100nA("100nA", -0.1, 0.1, CurrGainPathIn4, AnalogSubsystem::MaxValueAin); 
    CurrRange currRangeArrayTmp[NumCurrRange] = {CurrRange1uA, CurrRange10uA, CurrRange60nA, CurrRange100nA};
#elif defined CURRENT_VARIANT_MICRO_AMP
    const string CurrentVariant = string("microAmp");
    const CurrRange CurrRange1uA("1uA", -1.0, 1.0, CurrGainPathIn1, AnalogSubsystem::MaxValueAin); 
    const CurrRange CurrRange10uA("10uA", -10.0, 10.0, CurrGainPathIn2, AnalogSubsystem::MaxValueAin); 
    const CurrRange CurrRange100uA("100uA", -100.0, 100.0, CurrGainPathIn3, AnalogSubsystem::MaxValueAin); 
    const CurrRange CurrRange1000uA("1000uA", -1000.0, 1000.0, CurrGainPathIn4, AnalogSubsystem::MaxValueAin); 
    CurrRange currRangeArrayTmp[NumCurrRange] = {CurrRange1uA, CurrRange10uA, CurrRange100uA, CurrRange1000uA};
#elif defined CURRENT_VARIANT_MILL10_AMP
    const string CurrentVariant = string("10MilliAmp");
    const CurrRange CurrRange10uA("10uA", -10.0, 10.0, CurrGainPathIn1, AnalogSubsystem::MaxValueAin); 
    const CurrRange CurrRange100uA("100uA", -100.0, 100.0, CurrGainPathIn2, AnalogSubsystem::MaxValueAin); 
    const CurrRange CurrRange1000uA("1000uA", -1000.0, 1000.0, CurrGainPathIn3, AnalogSubsystem::MaxValueAin); 
    const CurrRange CurrRange10000uA("10000uA", -10000.0, 10000.0, CurrGainPathIn4, AnalogSubsystem::MaxValueAin); 
    CurrRange currRangeArrayTmp[NumCurrRange] = {CurrRange10uA, CurrRange100uA, CurrRange1000uA, CurrRange10000uA};
#elif defined CURRENT_VARIANT_MILL24_AMP
    const string CurrentVariant = string("24MilliAmp");
    const CurrRange CurrRange100uA("100uA", -100.0, 100.0, CurrGainPathIn3, AnalogSubsystem::MaxValueAin); 
    const CurrRange CurrRange1000uA("1000uA", -1000.0, 1000.0, CurrGainPathIn4, AnalogSubsystem::MaxValueAin); 
    const CurrRange CurrRange12000uA("12000uA", -12024.0, 12024.0, CurrGainPathIn1, AnalogSubsystem::MaxValueAin); 
    const CurrRange CurrRange24000uA("24000uA", -24048.0, 24048.0, CurrGainPathIn2, AnalogSubsystem::MaxValueAin); 
    CurrRange currRangeArrayTmp[NumCurrRange] = {CurrRange100uA, CurrRange1000uA, CurrRange12000uA, CurrRange24000uA};
#else
    #error "CURRENT_VARIANT must be selected"
#endif
    const string HardwareVariant = VoltageVariant + string("_") + CurrentVariant + HardwareVersion;
    Array<CurrRange,NumCurrRange>  CurrRangeArray(currRangeArrayTmp);

#if defined HARDWARE_VERSION_0P1
    const float SignCurr =  1.0;
#elif defined HARDWARE_VERSION_0P2
    const float SignCurr = -1.0;
#else
    #error "HARDWARE_VERSION must be specified"
#endif

    // Timer parameters
    const uint32_t TestTimerPeriod = 200;                // us
    const uint32_t DefaultSamplePeriod = 10000;          // us
    extern const uint32_t MinimumSamplePeriod = 1000;    // us
    extern const uint32_t MaximumSamplePeriod = 1000000; // us

    // Low pass filter params for current samples
    const LowPassParam CurrLowPassParam = {200.0, 0.0, 2}; // cutoff freq (Hz), initial value, order

} // namespace ps
