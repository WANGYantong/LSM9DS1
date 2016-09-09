
#ifndef  GLOBAL_H
#define  GLOBAL_H


#include "stm32f10x.h"


typedef char                        U8;  
typedef unsigned short              U16;
typedef unsigned int                U32;
typedef signed char                 S8;
typedef short                       S16;
typedef int                         S32;


extern void DEV_HardwareInit(void);
extern void DEV_PutChar(U8 ucchar);
extern void DEV_DelayMs(U32 uiMs);


#endif

