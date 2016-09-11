
#ifndef __DEVICE_H_
#define __DEVICE_H_

#include "global.h"

#define I2C1_OWN_ADDRESS7           0x0A
#define I2C_Speed                   40000

extern void DEV_UartInit(void);
extern void DEV_I2CInit(void);
extern void I2C_GPIO_Config(void);
extern void I2C_Mode_Config(void);
extern void DEV_CSEnable(void);


#endif
