#include <stdio.h>
#define MAX 5

//Name:				Trideep Lal Das
//Matrix Number:	MC170103673

// Note: we're creating static arrays
void display(int *);
void insert(int *, int pos, int num);
void main()
{
	int arr[5] = {1, 2, 3, 2, 1};
	printf ("\nElements of Array: ");
	display(arr);
	insert(arr, 1, 11);
	printf ("\nElements of Array: ");
	display(arr);
	insert(arr, 3, 33);
	printf ("\nElements of Array: ");
	display(arr);
}

//displays contents of array
void display(int *arr)
{
	//transverse the entire array
	int i;
	for (i = 0; i < MAX; i++)
		printf("%d\t", arr[i]);
}

//inserts an element "num" at given position "pos"
void insert(int *arr, int pos, int num)
{
	//shifts elements to right
	int i;
	for (i = MAX - 1; i >= pos; i--)
	{
		//printf ("%d\t%d\n", arr[i], arr[i-1]);
		arr[i] = arr[i-1];
	}
	arr[i] = num;		
}
