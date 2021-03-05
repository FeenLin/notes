#include <stdio.h>

typedef struct {
	int a;
}data_t;

void *func(void *void_ptr)
{
	((data_t *)void_ptr)->a = 10;
	return void_ptr; 
}

int main(int argc, char* argv[])
{
	data_t data1;
	data_t *data_ptr;

	data_ptr = ((data_t *)func(&data1));

	printf("value: %d\n", data_ptr->a);

    return 0;
}