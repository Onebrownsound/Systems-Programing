//Author Dom Modica
//Purpose Complete Final Project for servo library
#include <bcm2835.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <linux/i2c-dev.h>
#include <fcntl.h>

//Setup macros for Register constants from PYTHON lib
#define  __MODE1 				0x00
#define  __MODE2 				0x01
#define  __SUBADR1 			0x02
#define  __SUBADR2 			0x03
#define  __SUBADR3		   0x04
#define  __PRESCALE 			0xFE
#define  __LED0_ON_L  		0x06
#define  __LED0_ON_H 		0x07
#define  __LED0_OFF_L 		0x08
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



int setup()
{
	int file;
	int adapter_nr = 1; /* needs to be looked up in /dev/i2c-NUMBERISHERE for me it is 1 */
	char *filename = "/dev/i2c-1";

	snprintf(filename, 19, "/dev/i2c-%d", adapter_nr);
	file = open(filename, O_RDWR);
	if (file < 0) {
	 /* ERROR HANDLING;*/
	 exit(1);
	}

	int addr = 0x40; /* The I2C address this is my address from sudo i2cdetect -y 1 */

	if (ioctl(file, I2C_SLAVE, addr) < 0) {
	 /* ERROR HANDLING; you can check errno to see what went wrong */
	 exit(1);
	}
	return file;
}




int main(){
	int file_number;
  file_number=setup();
  i2c_smbus_write_byte(file_number, __LED0_ON_H);

  

  

  

return 0;
}



