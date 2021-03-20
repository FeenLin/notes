#include<stdio.h>
#include<stdlib.h>

struct obj
{
	char  member1;
	short member2;
	int   member3;
	long  member4;
};

int main(int argc, char *argv[])
{
	/* 1. Variable (basic types) */
	char  data1 = 1;
	short data2 = 2;
	int   data3 = 3;
	long  data4 = 4;
	char  *ptr1 = &data1;
	short *ptr2 = &data2;
	int   *ptr3 = &data3;
	long  *ptr4 = &data4;

	printf("1. Variable (basic types)\n\n");
	printf("   &data1 = %p\n", &data1);
	printf("   ptr1   = %p\n", ptr1);
	printf("   data1  = %d\n", data1);
	printf("   *ptr1  = %d\n\n", *ptr1);
	printf("   &data2 = %p\n", &data2);
	printf("   ptr2   = %p\n", ptr2);
	printf("   data2  = %d\n", data2);
	printf("   *ptr2  = %d\n\n", *ptr2);
	printf("   &data3 = %p\n", &data3);
	printf("   ptr3   = %p\n", ptr3);
	printf("   data3  = %d\n", data3);
	printf("   *ptr3  = %d\n\n", *ptr3);
	printf("   &data4 = %p\n", &data4);
	printf("   ptr4   = %p\n", ptr4);
	printf("   data4  = %ld\n", data4);
	printf("   *ptr4  = %ld\n\n", *ptr4);

	*ptr1 = 10;
	*ptr2 = 20;
	*ptr3 = 30;
	*ptr4 = 40;

	printf("   After assigning values to pointer\n");
	printf("   data1  = %d\n", data1);
	printf("   data2  = %d\n", data2);
	printf("   data3  = %d\n", data3);
	printf("   data4  = %ld\n\n", data4);

	/* 2. Array */
	int   array1[5] = {0, 1, 2, 3, 4};
	int   *ptr_a1 = array1;

	printf("2. Array\n\n");
	printf("   array1 = %p\n", array1);
	printf("   ptr_a1 = %p\n", ptr_a1);
	printf("   array1 = {%d %d %d %d %d}\n", array1[0], array1[1], array1[2], array1[3], array1[4]);
	printf("   ptr_a1[2] = %d\n\n", ptr_a1[2]);

	ptr_a1[2] = 20;
	printf("   After assigning values to pointer\n");
	printf("   array1 = {%d %d %d %d %d}\n\n", array1[0], array1[1], array1[2], array1[3], array1[4]);

	/* 3. Struct */
	printf("3. Struct\n\n");
	struct obj object;
	object.member1 = 11;
	object.member2 = 12;
	object.member3 = 13;
	object.member4 = 14;
	struct obj *ptr_s = &object;

	printf("   &object          = %p\n", &object);
	printf("   ptr_s            = %p\n", ptr_s);
	printf("   object.member1   = %d\n", object.member1);
	printf("   object.member2   = %d\n", object.member2);
	printf("   object.member3   = %d\n", object.member3);
	printf("   object.member4   = %ld\n", object.member4);
	printf("   ptr_s->member2   = %d\n\n", ptr_s->member2);

	ptr_s->member2 = 120;
	printf("   After assigning values to pointer\n");
	printf("   object.member1   = %d\n", object.member1);
	printf("   object.member2   = %d\n", object.member2);
	printf("   object.member3   = %d\n", object.member3);
	printf("   object.member4   = %ld\n\n", object.member4);

	/* 4. Pointer */
	int data5 = 50;
	int *ptr5 = &data5;
	//two-dimensional pointer
	int **pptr = &ptr5;

	printf("4. Pointer\n\n");
	printf("   &data5 = %p\n", &data5);
	printf("   ptr5   = %p\n", ptr5);
	printf("   &ptr5  = %p\n", &ptr5);
	printf("   pptr   = %p\n", pptr);
	printf("   *pptr  = %p\n", *pptr);

	printf("   data5  = %d\n", data5);
	printf("   *ptr5  = %d\n", *ptr5);
	printf("   **pptr = %d\n", **pptr);

	return 0;
}