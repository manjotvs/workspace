#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

uint8_t* construct_packets(uint8_t *buff, uint16_t *len)
{

	uint16_t total_len = *len + (*len/3) + 1;

	uint8_t *data = calloc((total_len), sizeof(uint8_t));
	int i = 0;
	int j = 0;
	uint8_t mask = 0x03;
	uint8_t rem_bits = 0x00;
	uint8_t prev_rem_bits = 0x01;
	uint8_t shift = 1;
	uint8_t rem_shift = 3;
	while(i< *len)
	{
		//printf("Org Byte: 0x%02X 0x%02X\n",buff[i],shift);
		//printf("Mask Bit: 0x%02X\n",mask);
		rem_bits = (buff[i] & mask);
		//printf("Rem Bits: 0x%02X\n",rem_bits);
		
		/* Add start, stop and remaining bits from prebious data byte */
		data[j] = (buff[i] >> shift) | prev_rem_bits;
		//printf("New Byte: 0x%02X\n",data[j]);
		prev_rem_bits = (rem_bits << (8 - rem_shift)) | 0x01;
		//printf("Pre Bits: 0x%02X\n\n",prev_rem_bits);
		mask = (mask << 0x02) | 0x3;
		rem_shift+=2;
		shift+=2;
		if( shift == 7)
		{
			//printf("reset\n");
			mask = 0x03;
			rem_bits = 0x00;
			shift = 1;
			rem_shift = 3;
			data[++j] = prev_rem_bits;
			prev_rem_bits = 0x01; 
		}
		i++;
		j++;
	}
	if(shift > 1)
	{
		data[j++] = prev_rem_bits;
	}
	*len = total_len;
	return data;
}

uint8_t* deconstruct_packets(uint8_t *buff, uint16_t *len)
{

	uint16_t total_len = 0;

	total_len = *len - (*len/4) -1;
	
	uint8_t *data = calloc((total_len), sizeof(uint8_t));
	int i = 0; 
	int j = 0;
	uint8_t mask = 0x03;
	uint8_t rem_bits = 0x00;
	uint8_t prev_rem_bits = 0x01;
	uint8_t shift = 2;
	buff[j] = ((buff[i] & 0x7E) << 0x01);
	while(i< *len-1)
	{
		//printf("\nOrg Byte: 0x%02X 0x%02X\n",buff[i], buff[i+1]);
		
		/* Add start, stop and remaining bits from previous data byte */
		data[j] = buff[i];
		buff[i+1] = ((buff[i+1] & 0x7E) << 0x01);
		//printf("1.New Byte1: 0x%02X\n",data[j]);
		//printf("1. New Byte2: 0x%02X\n",buff[i+1]);
		data[j] = data[j] | (buff[i+1]  >> (8-shift));
		buff[i+1] = (buff[i+1] << shift) & 0xFF;
		//printf("2. New Byte1: 0x%02X\n",data[j]);
		//printf("2. New Byte2: 0x%02X\n",buff[i+1]);
		//printf("i: %d Shift: %d\n",i,shift );
		
		shift+=2;
		if(shift > 6 )
		{
			//printf("\nCHANGE: %d %d\n",i,j);
			shift = 2;
			i+=2;
			j++;
			buff[i] = ((buff[i] & 0x7E) << 0x01);
	
			//i+=1;
			//buff[i+1] = 0x00;
			//data[i] = ((buff[i+1] & 0x7E) >> shift);
		}
		else
		{	
		j++;

		i++;
	}
	}
	*len = total_len;
	return data;
}

uint8_t* construct_packets_way(uint8_t *buff, uint16_t *len)
{

	uint16_t total_len = *len + (*len/4) + 1;

	uint8_t *data = calloc((total_len), sizeof(uint8_t));
	int i = 0;
	int j = 0;
	uint8_t mask = 0x01;
	uint8_t rem_bits = 0x00;
	uint8_t prev_rem_bits = 0x00;
	uint8_t shift = 1;
	while(i< *len)
	{
		//printf("Org Byte: 0x%02X 0x%02X\n",buff[i],shift);
		//printf("Mask Bit: 0x%02X\n",mask);
		// Get the LBSs of the packet, 1LSB, 3LSB, 5LSB, 7LSBs 
		// mask will vary like 0x01, 0x07, 0x1F, 0x7F
		rem_bits = (buff[i] & mask);
		printf("Rem Bits: 0x%02X\n",rem_bits);
		
		/* Add start, stop and remaining bits from prebious data byte */
		// Remove the rem_bits from packet by shifting it to right
		//Shift values 1, 3, 5, 7
		// Also add the prev_rem_bits
		data[j] = (buff[i] >> shift) | prev_rem_bits;
		//printf("New Byte: 0x%02X\n",data[j]);
		// Construct the prev_rem_bits by combining rem_bits and startbit
		prev_rem_bits = (rem_bits << (8 - shift)) | 0x01 <<(8 - (shift+1));
		//printf("Pre Bits: 0x%02X\n\n",prev_rem_bits);
		mask = (mask << 0x02) | 0x3;
		printf("SHIFT Bits: 0x%02X\n",shift);
		shift+=2;
		if( shift > 7)
		{
			//printf("reset\n");
			mask = 0x01;
			rem_bits = 0x00;
			shift = 1;
			data[++j] = prev_rem_bits;
			prev_rem_bits = 0x00; 
		}
		i++;
		j++;
	}
	if(shift > 1)
	{
		data[j++] = prev_rem_bits;
	}
	*len = total_len;
	return data;
}

uint8_t* deconstruct_packets_way(uint8_t *buff, uint16_t *len)
{

	uint16_t total_len = 0;

	total_len = *len - (*len/5) -1;
	
	uint8_t *data = calloc((total_len), sizeof(uint8_t));
	int i = 0; 
	int j = 0;
	uint8_t mask = 0x03;
	uint8_t rem_bits = 0x00;
	uint8_t prev_rem_bits = 0x01;
	uint8_t shift = 1;
	uint8_t oshift = 2;
	while(i< *len-1)
	{
		// Shift left buff[i] by 1(or) OR Shift right buff[i+1] by (8-shift)
		data[j] = (buff[i] << 0x01) | (buff[i+1] >> (8-shift));
		buff[i+1] = (buff[i+1] << oshift) & 0xFF;
		//printf("2. New Byte1: 0x%02X\n",data[j]);
		//printf("2. New Byte2: 0x%02X\n",buff[i+1]);
		//printf("i: %d Shift: %d\n",i,shift );
		
		shift+=2;
		oshift+=2;
		if(shift > 7 )
		{
			shift = 1;
	        oshift = 2;
			i+=1;
			//j++;
		}
		j++;
		i++;
	}
	*len = total_len;
	return data;
}


int main()
{
	int i = 0;
	//uint8_t buffer[] = {0x, 0x55, 0x00, 0x01, 0x02, 0x03};
	// uint8_t buffer[] = {0x23, 0xFF, 0xFF, 0x1F, 0XFF, 0xFF,0x55};//, 0xFF, 0xFF,0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
	// uint16_t len = sizeof(buffer)/sizeof(char);

	uint16_t len = 5;
	uint8_t *buffer;
	
	buffer = (uint8_t*)malloc(sizeof(uint8_t)*len);
	memset((void*)buffer, 0xFF, sizeof(uint8_t)*len);
	// for(i=0;i<len;i++)
	// 	buffer[i] = (1+i);
	printf("len: %d\n",len );
	uint8_t *data = construct_packets_way(buffer, &len);
	printf("Total Len: %d\n",len);
	i = 0;
	printf("Constructed data:");
	while(i<len)
		printf(" 0x%02X",data[i++]);
	printf("\n\n");

	data = deconstruct_packets_way(data, &len);
	printf("Total Len: %d\n",len);
	i = 0;
	printf("Deconstructed data:");
	while(i<len)
		printf(" 0x%02X",data[i++]);
	printf("\n\n");
	return 0;

}