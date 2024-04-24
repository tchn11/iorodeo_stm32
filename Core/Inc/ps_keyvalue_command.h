#ifndef PS_KEYVALUE_COMMAND_H
#define PS_KEYVALUE_COMMAND_H

#include "ps_constants.h"
#include "string"
#include "stdint.h"
using namespace std;

namespace ps
{

    template<typename T>
    class KeyValueCommand
    {
        public:
            KeyValueCommand() {};
            KeyValueCommand(string key, string value, ReturnStatus (T::*method)(JsonObject&,JsonObject&));

            string key();
            void setKey(string key);

            string value();
            void setValue(string value);

            void setMethod(ReturnStatus (T::*method)(JsonObject&,JsonObject&));
            ReturnStatus applyMethod(T* client, JsonObject &jsonMsg, JsonObject &jsonDat);

        protected:
            string key_;
            string value_;
            ReturnStatus (T::*method_)(JsonObject&,JsonObject&) = nullptr;
    };


    template<typename T>
    KeyValueCommand<T>::KeyValueCommand(string key, string value, ReturnStatus (T::*method)(JsonObject&,JsonObject&))
        : key_(key), value_(value), method_(method) 
    {}


    template<typename T>
    string KeyValueCommand<T>::key()
    {
        return key_;
    }


    template<typename T>
    void KeyValueCommand<T>::setKey(string key)
    {
        key_ = key;
    }


    template<typename T>
    string KeyValueCommand<T>::value()
    {
        return value_;
    }


    template<typename T>
    void KeyValueCommand<T>::setValue(string value)
    {
        value_ = value;
    }


    template<typename T>
    void KeyValueCommand<T>::setMethod(ReturnStatus (T::*method)(JsonObject&,JsonObject&))
    {
        method_ = method;
    }


    template<typename T>
    ReturnStatus KeyValueCommand<T>::applyMethod(T *client, JsonObject &jsonMsg, JsonObject &jsonDat)
    {
        ReturnStatus status;
        if (method_ != nullptr)
        {
            status = ((*client).*(method_))(jsonMsg,jsonDat);
        }
        else
        {
            status.success = false;
            status.message = "KeyValueCommand: method is nullptr";
        }
        return status;
    }


} // namespace ps

#endif
