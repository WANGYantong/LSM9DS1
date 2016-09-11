
#ifndef  GLOBAL_H
#define  GLOBAL_H


#include "stm32f10x.h"

#define SOFTWARE_VERSION            "001.001.002.001"

typedef char                        U8;
typedef unsigned short              U16;
typedef unsigned int                U32;
typedef signed char                 S8;
typedef short                       S16;
typedef int                         S32;


extern void DEV_HardwareInit(void);
extern void DEV_PeripheralInit(void);
extern U8 LSM9DS1_Identify(void);
extern void LSM9DS1_Init(void);
extern void LSM9DS1_Accelerometer(S32 * pBuffer);
extern void LSM9DS1_Gyroscope(S32 * pBuffer);
extern void LSM9DS1_Magnetometer(S32 * pBuffer);
extern void DEV_DelayMs(U32 uiMs);
extern void DEV_PutChar(U8 ucChar);
extern void I2C_BufferRead(U8 * pBuffer, U8 DeviceAddr, U8 RegisterAddr, U16 NumByte_Read);
extern void I2C_BufferWrite(U8 * pBuffer, U8 DeviceAddr, U8 RegisterAddr, U16 NumByte_Read);



#endif

