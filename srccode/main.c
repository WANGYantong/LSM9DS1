#include <stdio.h>
#include "global.h"

S32 main(void)
{
	U8 result;
	S32 acc_buffer[3], gyro_buffer[3], mag_buffer[3];

	DEV_HardwareInit();
	DEV_PeripheralInit();

	printf("\r\n ++++++++++++++++++++++++++++++++++++++++ \n");
	printf("\r\n Test version %s \n", SOFTWARE_VERSION);
	printf("\r\n ++++++++++++++++++++++++++++++++++++++++ \r\n");

	result = LSM9DS1_Identify();

	if (result == 1)
		printf("\r\n LSM9DS1 can be identified!\r\n");
	else
		printf("\r\n LSM9DS1 can not be identified!\r\n");

	while (1) {
		LSM9DS1_Accelerometer(acc_buffer);
		printf("\r\n AX = %d | AY = %d | AZ = %d \r\n", acc_buffer[0], acc_buffer[1], acc_buffer[2]);

		LSM9DS1_Gyroscope(gyro_buffer);
		printf("\r\n GX = %d | GY = %d | GZ = %d \r\n", gyro_buffer[0], gyro_buffer[1], gyro_buffer[2]);

		LSM9DS1_Magnetometer(mag_buffer);
		printf("\r\n MX = %d | MY = %d | MZ = %d \r\n", mag_buffer[0], mag_buffer[1], mag_buffer[2]);

		DEV_DelayMs(1000);

	}

	return 0;
}
