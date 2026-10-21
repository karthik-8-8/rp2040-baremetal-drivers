#include <stdio.h>
#include <stdint.h>

#define reg_32(addr)      *(volatile uint32_t *)(addr)


#define RESET_BASE 0x4000C000UL
#define I2C0_BASE  0x40044000UL
#define IO_BANK0_BASE 0x40014000UL



#define RESET   reg_32(RESET_BASE+0x0)
#define RESET_DONE reg_32(RESET_BASE+0x8)


#define IC_CON  reg_32(I2C0_BASE+0x00)
#define IC_TAR  reg_32(I2C0_BASE+0x04)
#define IC_DATA_CMD reg_32(I2C0_BASE+0x10)
#define IC_ENABLE reg_32(I2C0_BASE+0x6C)
#define IC_FS_SCL_HCNT reg_32(I2C0_BASE+0x1C)
#define IC_FS_SCL_LCNT reg_32(I2C0_BASE+0x20)
#define IC_STATUS reg_32(I2C0_BASE+0x70)



#define GPIO16_CTRL reg_32(IO_BANK0_BASE+0x084)
#define GPIO17_CTRL reg_32(IO_BANK0_BASE+0x08C)


void IC_write(int c)
  {
    while(!(IC_STATUS&(1<<1)))
      {
      }
    
    IC_DATA_CMD=c;
  }

char IC_read()
  {
    IC_DATA_CMD=(1<<8)|(1<<9);
    while(!(IC_STATUS &(1<<3)))
    {     
    }

  return ((uint8_t) (IC_DATA_CMD & (0x0FF)));
  }





int main()
{
RESET &=~(1<<3);
while(!(RESET_DONE&(1<<3)))
  {
  }

GPIO16_CTRL=3;
GPIO17_CTRL=3;

IC_ENABLE=0;

IC_CON=((IC_CON & (~(5<<0)) )|(5<<0));
IC_CON|=(3<<5);

IC_TAR=0x68;

IC_ENABLE=1;

IC_write(0x55);
uint8_t data = IC_read();
while(1)
  {
  }




}

