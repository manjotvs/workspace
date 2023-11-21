#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MALLOC_SIZE (1024)
unsigned char malloc_block[MALLOC_SIZE];


typedef struct free_space
{
	int size; // this holds the total available space or currently allocated space
	struct free_space *next; // This tells the next free block
	struct free_space *prev; // This tells the next free block
	unsigned char* buffer; // This points to the buffer which can be allocated excluding the freespace header
}free_space_t;
free_space_t *free_space_g;

void* mymalloc(int size)
{
	if(size % 8)
	{
		size += 8-(size%8);
		printf("New 8-byte Aligned Size: %d\n",size);
	}
	// Check available free space
	free_space_t* free_space = free_space_g;
	while(free_space->size<size)
	{
		printf("Find free space block\n");
		if(free_space->next== NULL)
		{
			printf("Can't find enough space\n");
			return NULL;
		}
		free_space = free_space->next;
	}
	printf("Currently available space: %d\n",free_space->size);
	free_space->buffer = (unsigned char*)free_space + sizeof(free_space_t);
	free_space_t *free_space_l;
	if(free_space->next)
	{
		free_space_l = free_space->next;
		printf("Next available space: %d\n",free_space_l->size);
	}
	else
	{
		// Update the next free block.
		free_space_l = (free_space_t*)(free_space->buffer + size );
		free_space_l->size = free_space->size - (size + sizeof(free_space_t));
		printf("New available space: %d\n",free_space_l->size);
		free_space_l->prev = NULL;
		free_space_l->next = NULL;
		free_space_l->buffer = NULL;
	}
	// Update the current allocated block.
	free_space->size = size;
	// Find the memory location needs to return to the caller
	void *p = free_space->buffer;
	
	// Update the global free space pointer
	free_space_g = free_space_l;
	//printf("Boundaries matching: %d\n", (free_space == free_space_g));
	return p;
}

void myfree(void* p)
{
	if(p==NULL)
	{
		return;
	}
	printf("free some memory\n");
	// Update the given pointer to access malloc bufferer
	p = p - sizeof(free_space_t);
	// Get the free buffer to find the allocated space for given pointer
	free_space_t* freeing_space = (free_space_t*)p;
	// Set everything to 0;
	memset(freeing_space->buffer, 0x00, freeing_space->size);

	// if current freeing memory buffer end share the boundary with global free memory pointer
	// then combine them into one
	if((freeing_space->buffer+freeing_space->size) == (unsigned char*)free_space_g)
	{
		printf("Collasecing\n");
		freeing_space->size += free_space_g->size + sizeof(free_space_t);
	}
	else if((freeing_space->buffer+freeing_space->size) == (unsigned char*)free_space_g->next)
	{
		printf("Collasecing2\n");
		freeing_space->size += free_space_g->size + 2*sizeof(free_space_t)+free_space_g->next->size;
		//freeing_space = free_space_g;
	}
	else
	{
		printf("Update next free block\n");
		freeing_space->next = free_space_g;
		free_space_g->prev = freeing_space;
		//freeing_space->size = size;
	}
	printf("Total free size: %d\n", freeing_space->size);
	free_space_g = freeing_space;

}


void malloc_init()
{
	printf("Size of free space structure: %lu\n", sizeof(free_space_t));
	free_space_g = (free_space_t*) malloc_block;
	free_space_g->size = MALLOC_SIZE - sizeof(free_space_t);
	free_space_g->next = NULL;
	free_space_g->prev = NULL;
	free_space_g->buffer = NULL;
}

int main()
{
	malloc_init();
	// Add some logic to prevent the read/write access for unallocated memory.

	int size = 10;
	unsigned char*p = mymalloc(size);
	unsigned char*p1 = mymalloc(size);
	unsigned char*p2 = mymalloc(size);
	if(p == NULL)
	{
		printf("Not enough space\n");
		return 0;
	}
	for(int i=0;i<size;i++)
	{
		p[i] = i;
		//p1[i] = i+size;
	}

	for(int i=0;i<size;i++)
	{
		printf("%d ",p[i]);
	}
	//myfree(p);

	// myfree(p);
	// myfree(p1);

	unsigned char*p3 = mymalloc(size);
	unsigned char*p4 = mymalloc(size);
	// myfree(p2);
	// myfree(p3);
 myfree(p4);
 myfree(p2);
 myfree(p3);
 myfree(p);
 myfree(p1);

	// for(int i=0;i<size;i++)
	// {
	// 	printf("%d ",p1[i]);
	// }
	// free(p);
	// for(int i=0;i<size;i++)
	// {
	// 	printf("%d ",p[i]);
	// }
	// for(int i=0;i<size;i++)
	// {
	// 	printf("%d ",p1[i]);
	// }
	// free(p1);
	// for(int i=0;i<size;i++)
	// {
	// 	printf("%d ",p[i]);
	// }
	// for(int i=0;i<size;i++)
	// {
	// 	printf("%d ",p1[i]);
	// }
	return 0;


	
}