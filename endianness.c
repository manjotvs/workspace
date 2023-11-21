#include <stdio.h>
#include <stdint.h>



int change_endianess(int a)
{
	a = ((( a << 16) & 0xffff0000 )| ((a>>16) & 0x0000FFFF));
	a = (((a << 8) & 0xff00ff00) | ((a >> 8) & 0x00ff00ff));
	return a;
}



/*num = 0x12345678

  
  memory adress - 0x00
  Little Endian:
  0x00 - 0x78
  0x01 - 0x56
  0x02 - 0x34
  0x03 - 0x12
    
  Big Endian:*/

// Return Values
// 0 - Little Endian
// 1 - Big Endian
void detectEndian()
{
  int n = 0x12345678;
  uint8_t *num = (uint8_t*)&n;
  if(*(num) == 0x78)
    printf("Little\n");
  else
    printf("Big\n");
}


int main()
{
	const int a = 0xE59C823B;
  detectEndian();
	//printf("0x%0X\n", change_endianess(a));

	return 0;
}



  
  
  