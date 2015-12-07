//Author Dom Modica
//Purpose Complete Final Project for servo library
#include <bcm2835.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MODE_READ 0
#define MODE_WRITE 1

#define MAX_LEN 32

uint16_t clk_div = BCM2835_I2C_CLOCK_DIVIDER_148;
uint8_t slave_address = 0x40;

int startup_i2c() {

    if (!bcm2835_init()) return 1;
    bcm2835_i2c_begin();
    bcm2835_i2c_setSlaveAddress(slave_address);
    bcm2835_i2c_setClockDivider(clk_div);
    fprintf(stderr, "Clock divider set to: %d\n", clk_div);
    fprintf(stderr, "Slave address set to: %d\n", slave_address);   
    return 0;
}

void end_i2c()
{
    bcm2835_i2c_end();
    bcm2835_close();

}



void read (char buf[],uint32_t len)
{   
    int i;
    uint8_t data;
    for (i=0; i<MAX_LEN; i++) buf[i] = 'n';
    data = bcm2835_i2c_read(buf, len);
    printf("Read Result = %d\n", data);   
    for (i=0; i<MAX_LEN; i++) {
        if(buf[i] != 'n') printf("Read Buf[%d] = %x\n", i, buf[i]);
    }    
}

void write (char wbuf[],uint32_t len)
{   
    int i;
    uint8_t data;
    data = bcm2835_i2c_write(wbuf, len);
    printf("Write Result = %d\n", data);
    

}

int main(){

    char test_write_buffer={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    if (startup_i2c()==1) exit(0);
    write(test_write_buffer,16);
    end_i2c();





    return 0;
}