#include <stdio.h>
#include <stdlib.h>

int *arr;
int MAX1, MAX2;
int *create(int);
void display(int *, int);
void sort (int *, int);
int *merge(int *, int *);
void del(int *, int pos);


int main()
{
	int *a, *b, *c;
	int pos;
	
	printf("Enter the number of Elements for Array ONE: ");
	scanf("%d", &MAX1);
	printf("\nEnter the elements for the first array: \n");
	a = create(MAX1);
	
	printf("\nEnter the number of elemtns for Array TWO: ");
	scanf("%d", &MAX2);
	printf("\nEnter the elements for the second array: \n");
	b = create(MAX2);
	
	printf("\nFirst Array: \n");
	display(a, MAX1);
	printf("\nSecond Array: \n");
	display(b, MAX2);
	
	c = merge(a, b);
	printf("\nDisplay the Mergng Two Arrays\n");
	display(c, MAX1 + MAX2);
	
	sort(a, MAX1);
	sort(b, MAX2);
	
	printf("\nFirst Array Sorted: \n");
	display(a, MAX1);
	printf("\nSecond Array Sorted: \n");
	display(b, MAX2);
	
	c = merge(a, b);
	printf("\nMerging after Sorting a and b\n");
	display(c, MAX1 + MAX2);

	printf("\n\n Select the Position that of Element that you want to Delete from the Array: ");
	scanf("%d", &pos);
	del(c, pos);
	printf("\nArray After deleting element on positon %d: \n",pos);
	display(c, MAX1+MAX2);

	free(a);
	free(b);
	free(c);
	return 0;
}

int *create(int size)
{
	int i;
	arr =(int *) malloc(size * sizeof(int));
	
	for(i = 0; i < size; i++)
	{
		printf("enter the element no. [%d]: ", i + 1);
		scanf("%d", &arr[i]);
	}
	return arr;
}

/* Siplays the contents of the Array */
void display(int *arr, int size)
{
	int i;
	for(i=0;i<size;i++)
		printf("%d\t", arr[i]);
	
}

/* Sorts the Array in Ascending oRder */
void sort(int *arr, int size)
{
	int i, j, temp;
	for(i = 0; i < size; i++)
	{
		for(j = i + 1; j < size; j++)
		{
			if(arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int *merge(int *a, int *b)
{
	int i, j;
	int size = MAX1 + MAX2;
	arr =(int *) malloc(sizeof(int) *(size));
	for(i=0; i<MAX1; i++)
	{
		arr[i]=a[i];
	}
	for (i=MAX1, j=0; i<size , j<MAX2; i++, j++)
	{
		arr[i]=b[j];
	}
	return arr;
}

void del(int *arr, it pos){
	int i;
	for (int i = pos; i < MAX1+MAX2; i++)
	{
		arr[i - 1] = arr[i];
		arr[i - 1] = 0;
	}
}