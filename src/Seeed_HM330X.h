/*
    Seeed_HM330X.h
    Driver for Seeed PM2.5 Sensor(HM300)

    Copyright (c) 2018 Seeed Technology Co., Ltd.
    Website    : www.seeed.cc
    Author     : downey
    Create Time: August 2018
    Change Log : 
      21st December 2022 by Marcin Jahn - Make the `select_comm` method private

    The MIT License (MIT)

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
*/

#ifndef _SEEED_HM330X_H
#define _SEEED_HM330X_H

#include "Arduino.h"
#include "HM330XErrorCode.h"
#include "I2COperations.h"


#define DEFAULT_IIC_ADDR  0x40
#define SELECT_COMM_CMD   0X88


class HM330X : public I2COperations {
  public:
    HM330X(uint8_t IIC_ADDR = DEFAULT_IIC_ADDR);

    HM330XErrorCode init();

    HM330XErrorCode read_sensor_value(uint8_t* data, uint32_t data_len);

  private:
    HM330XErrorCode select_comm();
};


#endif
