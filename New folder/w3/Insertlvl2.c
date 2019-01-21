#include <stdio.h>
#include <stdlib.h>

int *arr;
int MAX1, MAX2;
int *create(int);
void display(int *, int);
void sort (int *, int);
int *merge(int *, int *);
void insert(int*, int pos, int num);

int main()
{
	int *a, *b, *c;
	int pos, num;
	
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
	
	printf("\nSelect the position of value of the array: \n");
	scanf("%d", &pos);
	printf("\nInsert the value on the %d position : \n",pos);
	scanf("%d", &num);
	insert(c, pos, num);
	printf("\nArray after insert: \n");
	display(c, MAX1+MAX2);
	
	free(a);
	free(b);
	free(c);
	return 0; 
}

/* Creates Array of Given Size, Dynamically*/
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

//Merges two arrays of different Size
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

void insert (int *arr, int pos, int num)
{
 //shift elements to right
 int i;
 for (i = MAX1+MAX2 -1 ; i >= pos; i--)
 {
//printf("%d\t%d\n",arr[i], arr[i-1]);
 arr[i] = arr [i -1];
}
//fill up the number that we insert 
 arr[i] = num;

}
