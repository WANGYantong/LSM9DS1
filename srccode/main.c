#include <stdio.h>
#include "global.h"

S32 main(void)
{
		DEV_HardwareInit();
		while(1)
		{
				printf("\r\nThis is a test for USART2!\r\n");
				DEV_DelayMs(1000);
		}
		
		return 0;
}
