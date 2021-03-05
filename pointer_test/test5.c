#include <stdio.h>
#include <string.h>

typedef struct {
	int c;
}data_t;

void *func(int a)
{
	data_t data1;
	data1.c = a;

	void *e = &data1;
	return e;
}

int main(int argc, char* argv[])
{
	void *e = func(10);

	printf("%d\n", ((data_t*)e)->c);

    return 0;
}