
#ifndef __LSM9DS1_H_
#define __LSM9DS1_H_

#include "global.h"

//WHO_AM_I & WHO_AM_I_M responses
#define WHO_AM_I_RTN            0x68
#define WHO_AM_I_M_RTN          0x3D

//table 19 & 20 on datasheet
#define SAD_AG_SA0_0_R          0xD5
#define SAD_AG_SA0_0_W          0xD4
#define SAD_AG_SA0_1_R          0xD7
#define SAD_AG_SA0_1_W         0xD6

#define SAD_M_SA1_0_R           0x39
#define SAD_M_SA1_0_W           0x38
#define SAD_M_SA1_1_R           0x3D
#define SAD_M_SA1_1_W           0x3C


extern void LSM9DS1_AG_Init(void);
extern void LSM9DS1_M_Init(void);
extern void LSM9DS1_GetSensorData(S32 * pBuffer, U8 DeviceAddr, U8 RegisterAddr);
extern U8 LSM9DS1_Identify_AG(void);
extern U8 LSM9DS1_Identify_M(void);


#endif
