#include "../include/algorithm.h"

//
// Private
//


/**
 * @brief Swaps the values of two integers.
 *
 * @param a Pointer to the first integer.
 * @param b Pointer to the second integer.
 *
 * @pre 'a' and 'b' are valid pointers to integers.
 * @post The values pointed to by 'a' and 'b' are exchanged.
 */

static void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}


/**
 * @brief Partitions an array segment around a pivot element chosen as the last element.
 *
 * @param a Pointer to an array of integers.
 * @param low Starting index of the segment to partition.
 * @param high Ending index of the segment to partition.
 * @return The index of the pivot element after partitioning.
 *
 * @pre 'a' is an array of integers with at least 'high' elements, and 'low' and 'high' are valid indices.
 * @post Elements less than the pivot are moved to the left, and elements greater than or equal to the pivot are moved to the right.
 */

static int partition(int* a, int low, int high) {
    int pivot = a[high];
    int i = low - 1;

    for(int j = low; j <= high - 1; j++) {
        if(a[j] < pivot) {
            i++;
            swap(a + i, a + j);
        }
    }
    swap(a + i + 1, a + high);
    return i + 1;
}


/**
 * @brief Recursively applies quick sort to sort an array segment.
 *
 * @param a Pointer to an array of integers.
 * @param low Starting index of the segment to sort.
 * @param high Ending index of the segment to sort.
 *
 * @pre 'a' is an array of integers with at least 'high' elements, and 'low' and 'high' are valid indices within the array.
 * @post The array segment from 'low' to 'high' is sorted in ascending order.
 */

static void quick_sort_recursion(int* a, int low, int high) {
    if(low < high) {
        int piv = partition(a, low, high);

        // Sort left side of the pivot
        quick_sort_recursion(a, low, piv - 1);

        // Sort right side of the pivot
        quick_sort_recursion(a, piv + 1, high);
    }
}


//
// Public
//


/**
 * @brief Sorts an integer array using bubblesort algorithm.
 * 
 * @param a Pointer to an array of integers.
 * @param n Number of elements in the array.
 * 
 * @pre 'a' is an array of 'n' integers 
 * @post 'a' is sorted in ascending order
 */

void bubble_sort(int *a, int n)
{
	bool swapped;

	for(int i=n-1; i >= 0; i--){
		swapped = false;
		for(int j=0; j < i; j++){
			if(a[j] > a[j+1]){
				swap(a+j,a+j+1);
				swapped = true;
			}
		}
		if(!swapped)
			break;
	}
}

/**
 * @brief Sorts an array of integers in ascending order using insertion sort.
 *
 * @param a Pointer to an array of integers.
 * @param n Number of elements in the array.
 *
 * @pre 'a' is an array of 'n' integers.
 * @post 'a' is sorted in ascending order.
 */

void insertion_sort(int *a, int n)
{
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


/**
 * @brief Sorts an array of integers in ascending order using quick sort.
 *
 * @param a Pointer to an array of integers.
 * @param n Number of elements in the array.
 *
 * @pre 'a' is an array of 'n' integers.
 * @post 'a' is sorted in ascending order.
 */

void quick_sort(int *a, int n)
{
	quick_sort_recursion(a, 0, n-1);
}


/**
 * @brief Searches for a specific value in an array using linear search.
 *
 * @param a Pointer to an array of integers.
 * @param n Number of elements in the array.
 * @param v The value to search for in the array.
 * @return true if 'v' is found in the array, false otherwise.
 *
 * @pre 'a' is an array of 'n' integers, and 'v' is the value to be searched.
 * @post Returns true if 'v' is in 'a', false otherwise.
 */

bool linear_search(const int *a, int n, int v)
{
	for(int i=0; i<n; i++){
		if(a[i]==v)
			return true;
	}
	return false;
}


/**
 * @brief Searches for a specific value in a sorted array using binary search.
 *
 * @param a Pointer to a sorted array of integers.
 * @param n Number of elements in the array.
 * @param v The value to search for in the array.
 * @return true if 'v' is found in the array, false otherwise.
 *
 * @pre 'a' is a sorted array of 'n' integers, and 'v' is the value to be searched.
 * @post Returns true if 'v' is in 'a', false otherwise.
 */

bool binary_search(const int *a, int n, int v)
{
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
