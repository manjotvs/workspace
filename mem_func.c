#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef struct student
{
	float marks;
	int roll_num;
	char name[30];
}student;


void my_memcpy(void *const dest, const void* src, size_t len)
{
	//printf("Size: %d\n",len);
	const uint8_t* srcptr = (const uint8_t*)src;
	uint8_t*const destptr = ( uint8_t*const)dest;
	size_t i = 0;
	while(i<len)
	{
		//printf("0x%02X\n",(0xFF&*(srcptr+i)));
		*(destptr+i) = *(srcptr+i);
		i++;
	}
}


int main()
{
	char *name = "MAnjot";
	int roll_num = 127893;
	float percentage = 99.99;
	student stu;
	{
		my_memcpy(stu.name, name, ((strlen(name)+1)*sizeof(char)));
		my_memcpy(&(stu.roll_num), &roll_num, sizeof(int));
		my_memcpy(&(stu.marks), &percentage, sizeof(float));

		printf("%s %d %f\n", stu.name, stu.roll_num, stu.marks);
	}

	return 0;
}