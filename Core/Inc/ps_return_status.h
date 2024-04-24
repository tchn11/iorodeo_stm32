#ifndef PS_RETURN_STATUS_H
#define PS_RETURN_STATUS_H

#include "string"
#include "stdint.h"
using namespace std;

namespace ps
{

    class ReturnStatus
    {

        public:

            ReturnStatus() { };
            void appendToMessage(string value);

            bool success = true;;
            string message;

    };


} // namespace ps


#endif
