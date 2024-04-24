#ifndef PS_CURR_RANGE_H
#define PS_CURR_RANGE_H

#include "ps_range.h"
#include "ps_gains.h"
#include "string"
#include "stdint.h"
using namespace std;

namespace ps
{

    class CurrRange : public Range<CurrGainPath,uint16_t> 
    {
        public: 
            CurrRange() : Range<CurrGainPath,uint16_t>()  {};

            CurrRange(string name, float minValue, float maxValue, CurrGainPath currGainPath, uint16_t maxInt)
                : Range<CurrGainPath,uint16_t>(name, minValue, maxValue, currGainPath, maxInt) {};
    
    };

} 

#endif
