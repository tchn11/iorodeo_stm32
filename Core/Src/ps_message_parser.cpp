#include "ps_message_parser.h"
#include "string"
using namespace std;

namespace ps
{ 
    MessageParser::MessageParser()
    { }

    JsonObject &MessageParser::parse(string &message, StaticJsonBuffer<JsonMessageBufferSize> &jsonBuffer)
    { 
        return jsonBuffer.parseObject((char *)(message.c_str()));
    }

} // namespace ps
