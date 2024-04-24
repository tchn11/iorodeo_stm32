#ifndef PS_BASE_TEST_H
#define PS_BASE_TEST_H

#include "ps_sample.h"
#include "ps_constants.h"
#include "ps_return_status.h"
#include "ArduinoJson.h"
#include "string"
#include "stdint.h"
using namespace std;

namespace ps
{

    class BaseTest
    {

        public:

            BaseTest();

            virtual bool isDone(uint64_t t) const; 
            virtual uint64_t getDoneTime() const;
            virtual void reset();

            virtual float getValue(uint64_t t) const; 
            virtual float getMaxValue() const; 
            virtual float getMinValue() const; 

            virtual void setQuietTime(uint64_t quietTime);
            virtual uint64_t getQuietTime() const;

            virtual void setQuietValue(float value);
            virtual void setQuietValueToStart();
            virtual float getQuietValue() const;

            virtual void setSamplePeriod(uint64_t samplePeriod);
            virtual uint64_t getSamplePeriod() const;

            virtual void setName(string name);
            virtual string getName();

            virtual void setSampleMethod(SampleMethod sampleMethod);
            virtual SampleMethod getSampleMethod() const;
            virtual bool updateSample(Sample sampleRaw, Sample &sampleTest); 

            virtual void getParam(JsonObject &jsonDat);
            virtual ReturnStatus setParam(JsonObject &jsonMsg, JsonObject &jsonDat);

            virtual bool isMuxCompatible();
            virtual void setMuxCompatible(bool value);

        protected:

            uint64_t quietTime_ = 0;
            float quietValue_ = 0.0;
            uint64_t samplePeriod_ = 0;
            uint32_t sampleModulus_ = 0;
            string name_ = string("base");
            SampleMethod sampleMethod_ = SampleGeneric;
            bool muxCompatible_ = false;

            JsonObject &getParamJsonObject(JsonObject &json, ReturnStatus &status);
            void setQuietValueFromJson(JsonObject &jsonMsgPrm, JsonObject &jsonDatPrm, ReturnStatus &status);
            void setQuietTimeFromJson(JsonObject &jsonMsgPrm, JsonObject &jsonDatPrm, ReturnStatus &status);


    };

}

#endif
