/*
 * Seeed_HM330X.h
 * Driver for Seeed PM2.5 Sensor(HM300)
 *  
 * Copyright (c) 2018 Seeed Technology Co., Ltd.
 * Website    : www.seeed.cc
 * Author     : downey
 * Create Time: August 2018
 * Change Log :
 *
 * The MIT License (MIT)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef _SEEED_HM330X_H
#define _SEEED_HM330X_H

#include "Arduino.h"
#include "Wire.h"

#define CHECK_RESULT(a,b)   do{if(a=b)  {    \
                            Serial.print(__FILE__);    \
                            Serial.print(__LINE__);   \
                            Serial.print(" error code =");  \
                            Serial.println(a);                   \
                            return a;   \
                            }}while(0)

typedef int s32;
typedef long unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;

#define DEFAULT_IIC_ADDR  0x40


#define SELECT_COMM_CMD    0X88


typedef enum
{
    NO_ERROR=0,
    ERROR_PARAM=-1,
    ERROR_COMM =-2,
    ERROR_OTHERS=-128,
}err_t;

class IIC_OPRTS
{
    public:
        
        err_t IIC_write_byte(u8 reg,u8 byte);
        err_t IIC_read_byte(u8 reg,u8* byte);
        void set_iic_addr(u8 IIC_ADDR);
        err_t IIC_read_16bit(u8 start_reg,u16 *value);
        err_t IIC_write_16bit(u8 reg,u16 value);

        err_t IIC_read_bytes(u8 start_reg,u8 *data,u32 data_len);

        err_t IIC_SEND_CMD(u8 CMD);
        
    private:
        u8 _IIC_ADDR;
};

class HM330X:public IIC_OPRTS
{
    public:
        HM330X(u8 IIC_ADDR=DEFAULT_IIC_ADDR);
        err_t init();
        err_t select_comm();
        err_t read_sensor_value(u8 *data,u32 data_len);
    private:

};




#endif