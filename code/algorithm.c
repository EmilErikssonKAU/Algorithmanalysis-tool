#include "algorithm.h"

//
// Private
//

static int partition(int* a, int low, int high){
	
}

static void quick_sort_recursion(int* a, int low, int high){
	if(low < high){
		int piv = partition(a, low, high);

		// sort left of pivot
		quick_sort_recursion(a, low, piv-1);

		// sort right of pivot
		quick_sort_recursion(a, piv+1, high);

	}
}

//
// Public
//
void bubble_sort(int *a, int n)
{
	// Pre:		'a' is an array of n integers 
	// Post:	'a' is a sorted array, in ascending order, of n integers
	bool swapped;

	for(int i=n-1; i >= 0; i--){
		swapped = false;
		for(int j=0; j < i; j++){
			if(a[j] > a[j+1]){
				//swap
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp; 
				swapped = true;
			}
		}
		if(!swapped)
			break;
	}
}

void insertion_sort(int *a, int n)
{
	// Pre:		'a' is an array of n integers 
	// Post:	'a' is a sorted array, in ascending order, of n integers

	for(int i=1; i<n; i++){
		int curr_val = a[i];
		int j = i-1;

		while(j >= 0 && a[j] > curr_val){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = curr_val;
	}
	
}

void quick_sort(int *a, int n)
{
	// Pre:		'a' is an array of n integers 
	// Post:	'a' is a sorted array, in ascending order, of n integers
	quick_sort_recursion(a, 0, n-1);

}

bool linear_search(const int *a, int n, int v)
{
	// Pre: 'a' is an array of n integers, v is the value to be searched for
	// Post: returns 'true' if v is in 'a', returns 'false' if not

	for(int i=0; i<n; i++){
		if(a[i]==v)
			return true;
	}
	return false;
}

bool binary_search(const int *a, int n, int v)
{
	// Pre: 'a' is a sorted array of n integers, v is the value to be searched for
	// Post: returns 'true' if v is in 'a', returns 'false' if not
	int low = 0;
	int high =  n-1;
	int middle;

	while(low <= high){
		middle = (low + high)/2;
		if(a[middle] == v)
			return true;
		else if(a[middle] < v)
			low = middle + 1;
		else
			high = middle -1;
	}

	return false;

}
