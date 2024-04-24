#ifndef PS_VOLT_RANGE_H
#define PS_VOLT_RANGE_H

#include "ps_range.h"
#include "ps_gains.h"
#include "string"
#include "stdint.h"
using namespace std;

namespace ps
{
    class VoltRange : public Range<VoltGain,uint16_t> 
    {
        public: 
            VoltRange() : Range<VoltGain,uint16_t>()  {};

            VoltRange(string name, float minValue, float maxValue, VoltGain voltGain, uint16_t maxInt)
                : Range<VoltGain,uint16_t>(name, minValue, maxValue, voltGain, maxInt) {};
    
    };

    class VoltRangeDac : public VoltRange 
    {
        //using VoltRange::VoltRange;
        
        public: 
            VoltRangeDac() : VoltRange()  {};

            VoltRangeDac(string name, float minValue, float maxValue, VoltGain voltGain, uint16_t maxInt)
                : VoltRange(name, minValue, maxValue, voltGain, maxInt) {};
    };

    class VoltRangeAdc : public VoltRange 
    {
        //using VoltRange::VoltRange;
        
        public: 
            VoltRangeAdc() : VoltRange()  {};

            VoltRangeAdc(string name, float minValue, float maxValue, VoltGain voltGain, uint16_t maxInt)
                : VoltRange(name, minValue, maxValue, voltGain, maxInt) {};
    };

} 

#endif
