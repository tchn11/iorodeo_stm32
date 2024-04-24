#ifndef PS_GAINS_H
#define PS_GAINS_H

#include "ps_hardware_defs.h"
#include "string"
#include "stdint.h"
using namespace std;

namespace ps
{

#if defined(VOLTAGE_VARIANT_AD8250) || defined(VOLTAGE_VARIANT_10V)

    enum VoltGain // Analog output voltage scaling factor 
    {
        VoltGain1X  = 0,   // [-1V,  +1V]   
        VoltGain2X  = 1,   // [-2V,  +2V]
        VoltGain5X  = 2,   // [-5V,  +5V]
        VoltGain10X = 3,   // [-10V, +10V]
        NumVoltGain = 4
    };

    const string VoltGainStringArray[NumVoltGain] =
    {
        string("VoltGain1X"),
        string("VoltGain2X"),
        string("VoltGain5X"),
        string("VoltGain10X")
    };

#elif defined VOLTAGE_VARIANT_AD8251

    enum VoltGain // Analog output voltage scaling factor 
    {
        VoltGain1X  = 0,   // [-1V,  +1V]   
        VoltGain2X  = 1,   // [-2V,  +2V]
        VoltGain4X  = 2,   // [-4V,  +4V]
        VoltGain8X  = 3,   // [-8V,  +8V]
        VoltGain10X = 4,   // [-10V, +10V] // used for reference input
        NumVoltGain = 5
    };

    const string VoltGainStringArray[NumVoltGain] =
    {
        string("VoltGain1X"),
        string("VoltGain2X"),
        string("VoltGain4X"),
        string("VoltGain8X"),
        string("VoltGain10X")
    };

#else
#   error "VOLTAGE_VARIANT must be specified"
#endif

    enum CurrGainPath // TransImpedance Amplifiler Current gain path
    {
        CurrGainPathIn1 = 0,  // [-1uA,    +1uA]    w/ default resistors
        CurrGainPathIn2 = 1,  // [-10uA,   +10uA]   
        CurrGainPathIn3 = 2,  // [-100uA,  +100uA]  
        CurrGainPathIn4 = 3,  // [-1000uA, +1000uA] 
        CurrGainPathErr = 4,  // Incorrect path setting
        NumCurrGainPath = 5
    };


    const string CurrGainPathStringArray[NumCurrGainPath] =
    {
        string("CurrGainPathIn1"),
        string("CurrGainPathIn2"),
        string("CurrGainPathIn3"),
        string("CurrGainPathIn4"),
        string("CurrGainPathErr")
    };

    string voltGainToString(VoltGain value);

    string currGainPathToString(CurrGainPath value);

}
#endif
