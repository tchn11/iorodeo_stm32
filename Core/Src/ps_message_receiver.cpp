#include "ps_message_receiver.h"
#include "usbd_cdc_if.h"
#include "string"
using namespace std;

namespace ps
{
    MessageReceiver::MessageReceiver() 
    { }

    void MessageReceiver::reset()
    {
        overflow_ = false;
        messageCnt_ = 0;
    }


    void MessageReceiver::readData()
    {
        //while(Serial.available() > 0)
        //{
            uint8_t byte;
            uint32_t len = 1;
            CDC_Receive_FS(&byte, &len);
            if (!serialBuffer_.full())
            {
                serialBuffer_.push_back(byte);
                if (byte == '\n')
                {
                    messageCnt_++;
                    totalMessageCnt_++;
                }
            }
            else
            {
                overflow_ = true;
            }
        //}
    }


    string MessageReceiver::next()
    {
        string message("");
        if (messageCnt_ > 0)
        {
            {  // Begin atomic block  
                while (!serialBuffer_.empty())
                {
                    char byte = serialBuffer_.front();
                    serialBuffer_.pop_front();
                    if (byte == '\n')
                    {
                        break;
                    }
                    message.append(string(&byte));
                }
                messageCnt_--;
            } // End atomic block
        }
        return message;
    }


    bool MessageReceiver::available() const
    {
        return (messageCnt_ > 0);
    }


    uint32_t MessageReceiver::getMessageCnt() const
    {
        return messageCnt_;
    }


    uint32_t MessageReceiver::getTotalMessageCnt() const
    {
        return totalMessageCnt_;
    }


} // namespace ps
