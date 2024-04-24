#ifndef PS_MESSAGE_PARSER_H
#define PS_MESSAGE_PARSER_H

#include "ps_constants.h"
#include "ArduinoJson.h"
#include "string"
#include "stdint.h"
using namespace std;

namespace ps
{

    class MessageParser
    {

        public:

            MessageParser();
            JsonObject& parse(string &message, StaticJsonBuffer<JsonMessageBufferSize> &jsonBuffer);

    };

} // namespace ps

#endif
