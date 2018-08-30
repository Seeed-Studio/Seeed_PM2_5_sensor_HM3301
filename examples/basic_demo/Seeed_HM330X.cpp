#include "Seeed_HM330X.h"


HM330X::HM330X(u8 IIC_ADDR)
{
    IIC_begin();
    set_iic_addr(IIC_ADDR);
}


err_t HM330X::select_comm()
{
    return IIC_SEND_CMD(SELECT_COMM_CMD);
}

err_t HM330X::init()
{
    err_t ret=NO_ERROR;
    CHECK_RESULT(ret,select_comm());
    return ret;
}

err_t HM330X::read_sensor_value(u8 *data,u32 data_len)
{
    u32 time_out_count=0;
    err_t ret=NO_ERROR;
    Wire.requestFrom(0x40,29);
    while(data_len!=Wire.available())
    {
        time_out_count++;
        if(time_out_count>10)  return ERROR_COMM;
        delay(1);
    }
    for(int i=0;i<data_len;i++)
    {
        data[i]=Wire.read();
    }
    return ret;
}












/**********************************************************************************************************/
/************************************************IIC PART************************************************/
/**********************************************************************************************************/


/**@brief I2C write byte
 * @param reg :Register address of operation object
 * @param byte :The byte to be wrote.
 * @return result of operation,non-zero if failed.
 * */
err_t IIC_OPRTS::IIC_write_byte(u8 reg,u8 byte)
{
    s32 ret=0;
    Wire.beginTransmission(_IIC_ADDR);
    Wire.write(reg);
    Wire.write(byte);
    ret=Wire.endTransmission();
    if(!ret)
        return NO_ERROR;
    else
        return ERROR_COMM;
}


/**@brief I2C write 16bit value
 * @param reg: Register address of operation object
 * @param value: The 16bit value to be wrote .
 * @return result of operation,non-zero if failed.
 * */
err_t IIC_OPRTS::IIC_write_16bit(u8 reg,u16 value)
{
    s32 ret=0;
    Wire.beginTransmission(_IIC_ADDR);
    Wire.write(reg);
    
    Wire.write((u8)(value>>8));
    Wire.write((u8)value);
    ret=Wire.endTransmission();
    if(!ret)
        return NO_ERROR;
    else
        return ERROR_COMM;
}



/**@brief I2C read byte
 * @param reg: Register address of operation object
 * @param byte: The byte to be read in.
 * @return result of operation,non-zero if failed.
 * */
err_t IIC_OPRTS::IIC_read_byte(u8 reg,u8* byte)
{
    err_t ret=NO_ERROR;
    u32 time_out_count=0;
    Wire.beginTransmission(_IIC_ADDR);
    Wire.write(reg);
    Wire.endTransmission(false);

    Wire.requestFrom(_IIC_ADDR,(u8)1);
    while(1!=Wire.available())
    {
        time_out_count++;
        if(time_out_count>10)  return ERROR_COMM;
        delay(1);
    }
    *byte=Wire.read();
    return NO_ERROR;
}

/**@brief I2C read 16bit value
 * @param reg: Register address of operation object
 * @param byte: The 16bit value to be read in.
 * @return result of operation,non-zero if failed.
 * */
err_t IIC_OPRTS::IIC_read_16bit(u8 start_reg,u16 *value)
{
    err_t ret=NO_ERROR;
    u32 time_out_count=0;
    u8 val=0;
    *value=0;
    Wire.beginTransmission(_IIC_ADDR);
    Wire.write(start_reg);
    Wire.endTransmission(false);

    Wire.requestFrom(_IIC_ADDR,sizeof(u16));
    while(sizeof(u16)!=Wire.available())
    {
        time_out_count++;
        if(time_out_count>10)  return ERROR_COMM;
        delay(1);
    }
    val=Wire.read();
    *value|=(u16)val<<8;
    val=Wire.read();
    *value|=val;
    return NO_ERROR;
}


/**@brief I2C read some bytes
 * @param reg: Register address of operation object
 * @param data: The buf  to be read in.
 * @param data_len: The length of buf need to read in.
 * @return result of operation,non-zero if failed.
 * */
err_t IIC_OPRTS::IIC_read_bytes(u8 start_reg,u8 *data,u32 data_len)
{
    err_t ret=NO_ERROR;
    u32 time_out_count=0;
    Wire.beginTransmission(_IIC_ADDR);
    Wire.write(start_reg);
    Wire.endTransmission(false);

    Wire.requestFrom(_IIC_ADDR,data_len);
    while(data_len!=Wire.available())
    {
        time_out_count++;
        if(time_out_count>10)  return ERROR_COMM;
        delay(1);
    }
    
    for(int i=0;i<data_len;i++)
    {
        data[i]=Wire.read();
    }
    return ret;
}


/**@brief change the I2C address from default.
 * @param IIC_ADDR: I2C address to be set 
 * */
void IIC_OPRTS::set_iic_addr(u8 IIC_ADDR)
{
    _IIC_ADDR=IIC_ADDR;
}


err_t IIC_OPRTS::IIC_SEND_CMD(u8 CMD)
{
    int ret=0;
    Wire.beginTransmission(_IIC_ADDR);
    Wire.write(CMD);
    ret=Wire.endTransmission();
    if(!ret)
        return NO_ERROR;
    else
        return ERROR_COMM;
}
