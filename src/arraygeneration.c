#include "../include/algorithm.h"
#include "../include/arraygeneration.h"
#include <stdlib.h>
#include <time.h>

//
// Private
//

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

    return array;
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
    return NULL;
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
    int* array = getFilledArray(size);
    bubble_sort_descending(array, size);
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