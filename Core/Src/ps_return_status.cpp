#include "ps_return_status.h"
#include "string"
#include "stdint.h"
using namespace std;

namespace ps
{
    void ReturnStatus::appendToMessage(string value)
    {
        if (message.length() > 0)
        {
            message += ", ";
        }
        message += value;
    }

} // namespace ps
