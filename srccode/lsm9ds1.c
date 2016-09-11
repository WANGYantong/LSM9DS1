
#include "lsm9ds1.h"
#include "lsm9ds1_register.h"

U8 LSM9DS1_Identify(void)
{
	U8 status;
	U8 who_am_i_AG, who_am_i_M;

	who_am_i_AG = LSM9DS1_Identify_AG();
	DEV_DelayMs(10);

	who_am_i_M = LSM9DS1_Identify_M();
	DEV_DelayMs(10);

	if ((who_am_i_AG == WHO_AM_I_RTN) && (who_am_i_M == WHO_AM_I_M_RTN))
		status = 1;
	else
		status = 0;

	return status;
}

U8 LSM9DS1_Identify_AG(void)
{
	U8 buffer[1];
	I2C_BufferRead(buffer, SAD_AG_SA0_1_R, WHO_AM_I, 1);
	return buffer[0];
}

U8 LSM9DS1_Identify_M(void)
{
	U8 buffer[1];
	I2C_BufferRead(buffer, SAD_M_SA1_1_R, WHO_AM_I_M, 1);
	return buffer[0];
}

void LSM9DS1_Init(void)
{
	LSM9DS1_AG_Init();
	LSM9DS1_M_Init();
}

void LSM9DS1_AG_Init(void)
{
	U8 buffer[1];

	//item 7.12 in datasheet
	buffer[0] = 0xC1;
	I2C_BufferWrite(buffer, SAD_AG_SA0_1_W, CTRL_REG1_G, 1);
	DEV_DelayMs(10);

	//item 7.13 in datasheet
	buffer[0] = 0x00;
	I2C_BufferWrite(buffer, SAD_AG_SA0_1_W, CTRL_REG2_G, 1);
	DEV_DelayMs(10);

	//item 7.14 in datasheet
	buffer[0] = 0x00;
	I2C_BufferWrite(buffer, SAD_AG_SA0_1_W, CTRL_REG3_G, 1);
	DEV_DelayMs(10);

	//item 7.22 in datasheet
	buffer[0] = 0x38;
	I2C_BufferWrite(buffer, SAD_AG_SA0_1_W, CTRL_REG4, 1);
	DEV_DelayMs(10);

	//item 7.15 in datasheet
	buffer[0] = 0x00;
	I2C_BufferWrite(buffer, SAD_AG_SA0_1_W, ORIENT_CFG_G, 1);
	DEV_DelayMs(10);

	//item 7.23 in datasheet
	buffer[0] = 0x38;
	I2C_BufferWrite(buffer, SAD_AG_SA0_1_W, CTRL_REG5_XL, 1);
	DEV_DelayMs(10);

	//item 7.24 in datasheet
	buffer[0] = 0xD0;
	I2C_BufferWrite(buffer, SAD_AG_SA0_1_W, CTRL_REG6_XL, 1);
	DEV_DelayMs(10);
}

void LSM9DS1_M_Init(void)
{
	U8 buffer[1];

	buffer[0] = 0xA1;
	I2C_BufferWrite(buffer, SAD_M_SA1_1_W, CTRL_REG1_M, 1);
	DEV_DelayMs(10);
}

void LSM9DS1_GetSensorData(S32 * pBuffer, U8 DeviceAddr, U8 RegisterAddr)
{
	U8 buffer[6];

	I2C_BufferRead(buffer, DeviceAddr, RegisterAddr, 6);

	pBuffer[0] = (buffer[1] << 8) | buffer[0];
	pBuffer[1] = (buffer[3] << 8) | buffer[2];
	pBuffer[2] = (buffer[5] << 8) | buffer[4];
}

void LSM9DS1_Accelerometer(S32 * pBuffer)
{
	LSM9DS1_GetSensorData(pBuffer, SAD_AG_SA0_1_R, OUT_X_L_G);
}

void LSM9DS1_Gyroscope(S32 * pBuffer)
{
	LSM9DS1_GetSensorData(pBuffer, SAD_AG_SA0_1_R, OUT_X_L_XL);
}

void LSM9DS1_Magnetometer(S32 * pBuffer)
{
	LSM9DS1_GetSensorData(pBuffer, SAD_M_SA1_1_R, OUT_X_L_M);
}
