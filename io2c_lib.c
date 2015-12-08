//Author Dom Modica
//Purpose Complete Final Project for servo library
#include <unistd.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <linux/i2c-dev.h>
#include <fcntl.h>
//Setup macros for Register constants from PYTHON lib
#define  __MODE1           0x00
#define  __MODE2	   0x01
#define  __SUBADR1     	   0x02
#define  __SUBADR2	   0x03
#define  __SUBADR3         0x04
#define  __PRESCALE 	   0xFE
#define  __LED0_ON_L  	   0x06
#define  __LED0_ON_H   	   0x07
#define  __LED0_OFF_L 	   0x08
#define  __LED0_OFF_H      0x09
#define  __ALL_LED_ON_L    0xFA
#define  __ALL_LED_ON_H    0xFB
#define  __ALL_LED_OFF_L   0xFC
#define  __ALL_LED_OFF_H   0xFD

// Bit constants
#define  __RESTART  			0x80
#define  __SLEEP    			0x10
#define  __ALLCALL  			0x01
#define  __INVRT   			0x10
#define  __OUTDRV  			0x04

#define ON 0
#define SERVO_MIN 150
#define SERVO_MAX 600
#define CHANNEL 0


int setup() //setup tells the kernel i2c driver which i2c to use
{	printf("Attempting to setup i2c file");
	int file;
	int adapter_nr = 1; /* needs to be looked up in /dev/i2c-NUMBERISHERE for me it is 1 */
	char *filename = "/dev/i2c-1";
	file = open(filename, O_RDWR);
	if (file < 0) {
	 /* ERROR HANDLING;*/
	 exit(1);
	}

	int addr = 0x40; /* The I2C address this is my address from sudo i2cdetect -y 1 */

	if (ioctl(file, I2C_SLAVE, addr) < 0) { /*I2C_SLAVE is a constant in the library used 
	for denoting we are going to set it to this address*\

	 /* ERROR HANDLING; you can check errno to see what went wrong */
	 exit(1);
	}
	return file; //returns fd just in case we need it
}




int main (int argc, char * argv [] )
{
printf("Hello");
int file_number;
file_number=setup();
printf("The file_number is  %i /n",file_number);
while(1){
//write byte data to (file,register,value)
i2c_smbus_write_byte_data (file_number,__LED0_ON_L, SERVO_MIN & 0xFF);
i2c_smbus_write_byte_data(file_number,__LED0_ON_H, SERVO_MIN >> 8);
i2c_smbus_write_byte_data(file_number,__LED0_OFF_L, SERVO_MAX & 0xFF);
i2c_smbus_write_byte_data(file_number,__LED0_OFF_H, SERVO_MAX >> 8);
}

return 0;
}



