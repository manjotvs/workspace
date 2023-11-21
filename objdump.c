#include <stdio.h>
/* BSS(Block Started by Symbol) */ 
/* Will not be allocated in BSS until initialized in any fucntion */
static int b1;
static int c1;
static int d1;
// will allocate e1 into constant section of the memory under DATA type but
// Will not allocate anything in memory until being used in some function
const static int e1; 
const static int f1=5; // Will not allocate anything in memory not sure what happens here??
static int *p; // Will not allocate anything in memory until being used in some function
int h1; // Will allocate memory in common section of BSS type
int h12; // Will allocate memory in common section of BSS type
int *j1; // Will allocate memory in common section of BSS type (8 bytes)
int k1=0; // Will allocate memory in common section of BSS type
int *l1=NULL; // Will allocate memory in common section of BSS type
const int o1; // Will allocate memory in common section of BSS type

/* DATA segment */ 
int i1=2; // allocate memory in data section of DATA type
const int m1=2;//or 0; // allocate memory in const section of DATA type
int *n1 = &k1;
static int g1 = 23; // Will not allocate anything in memory until being used in some function

// static int n1;
// static int o1;
// static int p1;

/* static funcytions are accesible only inside this file */
int sum()
{
	b1=0; // Allocate b1 into BSS section of BSS type
	static const int z=0; // allocate memory in const section of data type
	static const int z1;
	static int y=0; // allocate memory in bss section of bss type
	static int y1=9; // allocate memory in data section of data type
	const int y2;
    int y3 = y2;
	//z = 1;// illegal operaion
	return 89;
}


int main()
{
	/* BSS(Block Started by Symbol) */
	static int b; //1
	static int c;
	static int d;
	static int e;
	static int f;
	static int g;
	static int h;
	static int i;
	static int j;
	static int k;
	static int l;
	static int m;
	static int n;
	static int o; //14
	// 14 * 4(sizeof(int)) = 56 = 0x38

	// To allocate memory for global defined static variables, they have to be intialized
	//c1 =0;
	// Allocate d1 into BSS section of BSS type
	d1 = e1; // will allocate e1 into constant section of the memory under DATA type
	d1 = f1;
	//e1++; // illegal operation
	//o1= e1; // illegal operation - const variables are only readable variables

	/* DATA segment */ 
	// allocate memory in data section of DATA type
	static int p=9;
	g1=78;

	/* checking z defined in sum, is it usable outside the function */
	//printf("%d",z); //cannot use z local variable to function
	//printf("%d",y); //cannot use y local variable to function


	return 0;
}