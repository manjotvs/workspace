#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
typedef struct str1{
	//uint32_t *ip;
	 uint8_t *cp;
	uint8_t name[10];
	uint8_t nums[11];
	// struct str4 *ptr; // 8
	// uint32_t ip;

	struct str4 *ptr56; // 8 
}str1_t;

#pragma pack(1)

typedef struct str2{
	uint64_t data1;
	uint8_t data2;
	uint64_t data5;
	uint8_t data3;
	uint32_t data6;
	uint16_t data4;
	uint8_t data7;
	struct str4 *ptr; // 8
}str2_t;

// same as above.
struct str6{
	uint64_t data1;
	uint8_t data2;
	uint64_t data5;
	uint8_t data3;
	uint32_t data6;
	uint16_t data4;
	uint8_t data7;
	struct str6 *ptr; // 8
}__attribute__((packed));


#pragma pack(2)
typedef struct str3{
	uint64_t data1;
	uint8_t data2;
	uint64_t data5;
	uint8_t data3;
	uint32_t data6;
	uint16_t data4;
	uint8_t data7;
	struct str4 *ptr; // 8
}str3_t;


//#pragma pack(2)
#pragma pack(4)  //24
typedef struct str5{
	uint8_t data1;
	uint32_t data8;
	uint8_t data2;
	uint8_t data5;
	uint8_t data3;
	uint8_t data6;
	uint8_t data4;
	uint8_t data7;
	struct str5 *ptr; // 8
}str5_t;


//#pragma pack(4)  // 40

//#pragma pack(8) //48
typedef struct str4{
	uint64_t data1;
	uint8_t data2;
	uint64_t data5;
	uint8_t data3;
	uint32_t data6;
	uint16_t data4;
	uint8_t data7;
	struct str4 *ptr; // 8
}str4_t;

struct foo6 {
    short s;
    char c;
    int flip:1;
    int nybble:4;
    int septet:7;
};

#pragma pack(4)
typedef struct
{
    uint8_t count;
    uint16_t data[2];
    uint32_t timestamp;
} packet_S;


int main()
{
	int *p;
	printf("%lu\n", sizeof(p));
	printf("Size: %lu\n", sizeof(str1_t));
	printf("Size: %lu\n", sizeof(str2_t));
	printf("Size: %lu\n", sizeof(str3_t));
	printf("Size: %lu\n", sizeof(str5_t));
	printf("Size: %lu\n", sizeof(str4_t));

	packet_S packet;
	printf("%lu %lu %lu %lu\n", offsetof(packet_S, count), offsetof(packet_S, data[0]), offsetof(packet_S, data[1]), offsetof(packet_S, timestamp));
	packet.count = 0x6F;
    packet.data[0] = 0x9E70;
    packet.data[1] = 0x9994;
    packet.timestamp = 0xE632B2CA;
    uint8_t *byte=(uint8_t*)(&packet);
    for(int i=0;i<sizeof(packet_S);i++)
    {
    	printf("0x%02X\n",byte[i]);
    }

	return 0;
}