#ifndef PS_SAMPLE_H
#define PS_SAMPLE_H

#include "string"
#include "stdint.h"
using namespace std;

namespace ps
{

    class Sample 
    {
        public:

            uint64_t t;
            float volt;
            float curr;
            uint8_t chan;
    };

}

#endif
