#include "ps_gains.h"
#include "string"
using namespace std;

namespace ps 
{
    string voltGainToString(VoltGain value)
    {
        string rval("");
        if (value < NumVoltGain)
        {
            rval = VoltGainStringArray[value];
        }
        return rval;
    }

    string currGainPathToString(CurrGainPath value)
    {
        string rval("");
        if (value < NumCurrGainPath)
        {
            rval = CurrGainPathStringArray[value];
        }
        return rval;
    }

}
