/*
    Seeed_HM330X.cpp
    Driver for Seeed PM2.5 Sensor(HM300)

    Copyright (c) 2018 Seeed Technology Co., Ltd.
    Website    : www.seeed.cc
    Author     : downey
    Create Time: August 2018
    Change Log :

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

#include "Seeed_HM330X.h"

HM330X::HM330X(uint8_t IIC_ADDR) {
    set_iic_addr(IIC_ADDR);
}

HM330XErrorCode HM330X::select_comm() {
    return IIC_SEND_CMD(SELECT_COMM_CMD);
}

HM330XErrorCode HM330X::init() {
    Wire.begin();
    return select_comm();
}

HM330XErrorCode HM330X::read_sensor_value(uint8_t* data, uint32_t data_len) {
    uint32_t time_out_count = 0;
    HM330XErrorCode ret = NO_ERROR;
    Wire.requestFrom(0x40, 29);
    while (data_len != Wire.available()) {
        time_out_count++;
        if (time_out_count > 10) {
            return ERROR_COMM;
        }
        delay(1);
    }
    for (int i = 0; i < data_len; i++) {
        data[i] = Wire.read();
    }
    return ret;
}
