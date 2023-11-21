#include<stdio.h>
#include<string.h>

typedef struct data
{
	int num;
	char name[10];
	float x;
}data_t;

void print_struct(data_t *d)
{
	printf("num: %d\n", d->num);
	printf("name: %s\n", d->name);
	printf("x: %f\n", d->x);
}


void (*func_ptr[3])(void);



void funca()
{
	printf("HI A\n");
}
void funcb()
{
printf("HI B\n");
}

void funcc()
{
printf("HI C\n");
}


void display_value(void* p, char c)
{
	if(c == 1)
	{
		printf("%d\n",*((int*)p));
	}
	else if(c == 2)
	{
		printf("%s\n",(char*)p);
	}
	else if(c == 3)
	{
		printf("%f\n",*((float*)p));
	}
}


typedef struct example
{
       int id1; // 4 byte
       int id2; // 4 bytes
       char name; // 1  byte + 3 bytes 
       char c; //   1  byte + 3 bytes 
       float percentage; // 4 bytes
}example_t;


// 20 bytes

// int 4 bytes, char 1 byte, float 4 bytes

int main()
{



	example_t ex;
	printf("%d\n",sizeof(ex));

	int p = 12;
	int *q = &p;
	int **r = &q;

	data_t d;
	d.num =2;
	d.x = 2.4;
	strcpy(d.name, "Pawan");


	print_struct(&d);

	printf("%d %d %d\n", p, *q, **r );


	func_ptr[0] = funca;
	func_ptr[1] = funcb;
	func_ptr[2] = funcc;

	for(int i=0;i<3;i++)
	{
		(*(func_ptr[i]))();
	}
	display_value((void*)&d.num, 1);
	display_value((void*)&d.name, 2);
	display_value((void*)&d.x, 3);

	//printf("typeof %d", typeof(d.num));



	return 0;
}


