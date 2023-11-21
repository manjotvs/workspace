#include <stdio.h>
#include <stdint.h>




// size is 8, 4 + 1, then round to multiple of 4 (int's size),
struct stu_a {
    int i;
    char c;
};

// size is 16, 8 + 1, then round to multiple of 8 (long's size),
struct stu_b {
    long l;
    char c;
};

// size is 24, l need padding by 4 before it, then round to multiple of 8 (long's size),
struct stu_c {
    int i;
    long l;
    char c;
};

// size is 16, 8 + 4 + 1, then round to multiple of 8 (long's size),
struct stu_d {
    long l;
    int i;
    char c;
};

// size is 16, 8 + 4 + 1, then round to multiple of 8 (double's size),
struct stu_e {
    double d;
    int i;
    char c;
};

// size is 24, d need align to 8, then round to multiple of 8 (double's size),
struct stu_f {
    int i;
    double d;
    char c;
};

// size is 4,
struct stu_g {
    int i;
};

// size is 8,
struct stu_h {
    long l;
};


// test - padding within a single struct,
int test_struct_padding() {
    printf("%s: %ld\n", "stu_a", sizeof(struct stu_a));
    printf("%s: %ld\n", "stu_b", sizeof(struct stu_b));
    printf("%s: %ld\n", "stu_c", sizeof(struct stu_c));
    printf("%s: %ld\n", "stu_d", sizeof(struct stu_d));
    printf("%s: %ld\n", "stu_e", sizeof(struct stu_e));
    printf("%s: %ld\n", "stu_f", sizeof(struct stu_f));

    printf("%s: %ld\n", "stu_g", sizeof(struct stu_g));
    printf("%s: %ld\n", "stu_h", sizeof(struct stu_h));


    return 0;
}


//#pragma pack(4)
typedef struct ab
{
	uint8_t count;
	uint16_t name;
    uint32_t timestamp;
    uint8_t serial_num;
}ab_t;
// test - address of struct,
int test_struct_values() {
   
	ab_t nw;
	nw.count = 0xaa;
	//nw.data[0] = 0xbbcc;
	//nw.data[1] = 0xddee;
	nw.name = 0xfc90;
	nw.timestamp = 0xdeadbeef;
	nw.serial_num = 0x11;

	uint8_t* p= &nw;
	for(int i=0;i<sizeof(ab_t);i++)
	{
		printf("0x%02X\n", *(p+i));
	}
    return 0;
}


typedef struct
{
    uint8_t count;
    uint16_t data[2];
    uint32_t timestamp;
} packet_S;

// a) What are the values of each member of myPacket?
// count = 0x6F
// data[0] = 0x9E70
// data[1] = 0x9994
// timestamp = 0xB2CABA4A


//
int main()
{
	uint64_t a = 0x1122334455667788;
	printf("%d\n",sizeof(void*));
	// 64 bit system because sizeof void* is 8 bytes.

	// find out endianess of the system
	uint8_t *n = &a;
	//printf("0x%02X\n", *(n)); // little endian 88 stores first/

	ab_t nw;
	// nw.count = 0xaa;
	// //nw.data[0] = 0xbbcc;
	// //nw.data[1] = 0xddee;
	// nw.timestamp = 0xdeadbeef;
	// nw.serial_num = 0xCC;
	//nw.serial_num = 0x1122334455667788;

	printf("structure size : %d\n",sizeof(nw));
	//uint8_t *np = &nw;



//test_struct_padding();
   // test_struct_values();


    packet_S packet;
    packet.count = 0x6F;
	packet.data[0] = 0x9E70;
	packet.data[1] = 0x9994;
	packet.timestamp = 0xE632B2CA;

		uint8_t* pk= &packet;
	for(int i=0;i<sizeof(packet);i++)
	{
		printf("0x%02X\n", *(pk+i));
	}

	return 0;
}
//0xFF00000000000000
//0x1122334455667788