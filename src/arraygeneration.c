#include "../include/algorithm.h"
#include "../include/arraygeneration.h"
#include <stdlib.h>
#include <time.h>
static void reverseQuickSortHigh(int* array, int low, int high);

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
 * @brief Genereate array with integers in ascending order
 * 
 * @param size Number of integers
 * @return The array
 */

static int* getFilledArray(int size){
    int* array = malloc(size * sizeof(int));
    for(int i=0; i<size; i++){
        array[i] = i;
    }
    return array;
}


/**
 * @brief Genereate array with integers in descending order
 * 
 * @param size Number of integers
 * @return The array
 */

static int* getFilledArrayReverse(int size){
    int* array = malloc(size * sizeof(int));
    int nextelem = size - 1;
    for(int i=0; i < size; i++){
        array[i] = nextelem;
        nextelem--;
    }
    return array;
}


/**
 * @brief Randomly shuffles order of array
 * 
 * @param array The array
 * @param size Size of array
 */

static void shuffleArray(int* array, int size){
    // Seed the random number generator
    srand(time(NULL));

    for (int i=size-1; i > 0; i--) {
        int j = rand() % (i+1);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

/**
 * @brief Shuffles array so that it becomes the fastest array for quicksort, with high pivot, to sort.
 * 
 * @param array The array.
 * @param low The lower boundary index of 'array'.
 * @param high The higher boundary index of 'array'.
 * 
 * @pre Array is sorted in ascending order.
 */


static void reverseQuickSortHigh(int* array, int low, int high){
    if(high <= low){
        return;
    }
    int size = high-low+1;
    int middle_index = low + (size-1)/2;
    swap(array+middle_index, array+ high);
    reverseQuickSortHigh(array, low, middle_index-1);
    reverseQuickSortHigh(array, middle_index+1, high-1);
}


//
// Public
//


/**
 * @brief Get the fastest array of size n for bubblesort to sort
 * 
 * @param size Size of array
 * @return The array
 */

int* getBestCaseBubbleSort(int size){
    int* array = getSortedAscendingArray(size);
    return array;
}

/**
 * @brief Get the slowest array of size n for bubblesort to sort
 * 
 * @param size Size of array
 * @return The array
 */

int* getWorstCaseBubbleSort(int size){
    int* array = getSortedDescendingArray(size);
    return array;
}

/**
 * @brief Get the fastest array of size n for inserationsort to sort
 * 
 * @param size Size of array
 * @return The array
 */

int* getBestCaseInsertionSort(int size){
    int* array = getSortedAscendingArray(size);
    return array;
}


/**
 * @brief Get the slowest array of size n for insertionsort to sort
 * 
 * @param size Size of array
 * @return The array
 */

int* getWorstCaseInsertionSort(int size){
    int* array = getSortedDescendingArray(size);
    return array;
}


/**
 * @brief Get The fastest array of size n for quicksort to sort
 * 
 * @param size Size of array
 * @return The array
 */

int* getBestCaseQuickSortHigh(int size){
    int*array = getSortedAscendingArray(size);
    reverseQuickSortHigh(array, 0, size-1);
    return array;
}


/**
 * @brief Get The slowest array of size n for quicksort to sort
 * 
 * @param size Size of array
 * @return The array
 */

int* getWorstCaseQuickSortHigh(int size){
    int* array = getSortedAscendingArray(size);
    return array;
}


/**
 * @brief Get an array sorted in ascending order
 * 
 * @param size Size of array
 * @return The array
 */


int* getSortedAscendingArray(int size){
    int* array = getFilledArray(size);
    return array;
}


/**
 * @brief Get an array sorted in descending order
 * 
 * @param size Size of array
 * @return The array
 */

int* getSortedDescendingArray(int size){
    int * array = getFilledArrayReverse(size);
    return array;
}


/**
 * @brief Get an array with randomized order of elements
 * 
 * @param size Size of array
 * @return The array
 */

int* getRandomizedArray(int size){
    int* array = getFilledArray(size);
    shuffleArray(array, size);
    return array;
}


/**
 * @brief Get array and fastest element for linear search to find.
 * 
 * @param size Size of array.
 * @return Struct with array and fastest element to find.
 */

array_and_value* getBestCaseLinearSearch(int size){
    array_and_value* a_v = malloc(sizeof(array_and_value));
    a_v->array = getSortedAscendingArray(size);
    a_v->element = 0;
    return a_v;
}


/**
 * @brief Get array and slowest element for linear search to find.
 * 
 * @param size Size of array.
 * @return Struct with array and slowest element to find.
 */

array_and_value* getWorstCaseLinearSearch(int size){
    array_and_value* a_v = malloc(sizeof(array_and_value));
    a_v->array = getSortedDescendingArray(size);
    a_v->element = 0;    
    return a_v;
}


/**
 * @brief Get array and fastest element for binary search to find.
 * 
 * @param size Size of array.
 * @return Struct with array and fastest element to find.
 */

array_and_value* getBestCaseBinarySearch(int size){
    array_and_value* a_v = malloc(sizeof(array_and_value));
    a_v->array = getSortedAscendingArray(size);
    a_v->element = (size-1)/2; 
    return a_v;
}


/**
 * @brief Get array and slowest element for binary search to find.
 * 
 * @param size Size of array.
 * @return Struct with array and slowest element to find.
 */

array_and_value* getWorstCaseBinarySearch(int size){
    array_and_value* a_v = malloc(sizeof(array_and_value));
    a_v->array = getSortedAscendingArray(size);
    a_v->element = 0; 
    return a_v;
}

/**
 * @brief Get an array, sorted in ascending order, with a random value in that array.
 * 
 * @param size Size of the array
 * @return Struct with the array and a random value from the array. 
 */

array_and_value* getAverageCaseSearch(int size){
    srand(time(NULL));

    array_and_value* a_v = malloc(sizeof(array_and_value));
    a_v->array = getSortedAscendingArray(size);
    a_v->element = rand() % size;
    return a_v;
}
