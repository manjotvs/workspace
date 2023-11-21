#include <stdio.h>
#include <stdlib.h>

typedef struct ll
{
	char data;
	struct ll *next_node;
}ll_g;

ll_g *unique_list[10];

// ll ll_Init(void *i)
// {

// }


char traversal(ll_g *k)
{
	char i =0;
	while(k)
	{
		printf("node_data: %d\n",k->data );
		k = k->next_node;
	}
	return 0;
}


char hash_function(ll_g *k)
{
	char i =0;
	while(unique_list[i] != 0)
	{
		if(unique_list[i] == k)
			return 1;
		i++;
	}
	unique_list[i] = k;
	return 0;
}
char detect_loop1( ll_g *l)
{
	while(l)
	{
		printf("Data: %d\n",l->data);
		if(hash_function(l) == 1)
		{
			printf("Duplicate element\n");
			return 1;
		}
		l=l->next_node;
	}
	return 0;
}

void remove_loop(ll_g *lp_node, ll_g *l)
{
	ll_g *n;
	n = lp_node;
	while( l )
	{
		n=lp_node;
		printf("Hi: %d %d\n",n->data, l->data);
		while(n->next_node != lp_node && n->next_node != l)
		{
			printf("Hello: %d %d\n",n->data, l->data);
			n = n->next_node;
		}
		if(n->next_node == l)
		{
			break;
		}
		l = l->next_node;
		//lp_node = lp_node->next_node;
	}
	printf("Detected Node: %d\n",n->data);
	n->next_node = NULL;
}

char detect_loop2( ll_g *l)
{
	ll_g *i;
	ll_g *j;
	i=l;
	j=l;
	while(i && j->next_node && j)
	{
		i = i->next_node;
		j = j->next_node->next_node;
		if(i == j)
		{
			printf("Detected loop node %d\n",l->data );
			remove_loop(i, l);
			return 1;
		}
	}
	return 0;
}

int main()
{
	ll_g *a;
	ll_g *b;
	ll_g *c;
	ll_g *d;
	ll_g *e;
	a = malloc(sizeof(ll_g));
	b = malloc(sizeof(ll_g));
	c = malloc(sizeof(ll_g));
	d = malloc(sizeof(ll_g));
	e = malloc(sizeof(ll_g));
	a->data = 2;
	a->next_node = b;
	b->data = 3;
	b->next_node = c;
	c->data = 4;
	c->next_node = d;
	d->data = 5;
	d->next_node = e;
	e->data = 6;
	e->next_node = b;

	//printf("Add: %u\n", c->next_node );
	if(detect_loop2(a))
	{
		printf("loop detected\n");
	}
	else
		printf("loop not detected\n");

	traversal(a);

	return 0;
}