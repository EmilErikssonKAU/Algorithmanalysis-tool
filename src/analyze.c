#include "../include/analyze.h"
#include "../include/algorithm.h"
#include "../include/arraygeneration.h"
#include "../include/ui.h"
#include "../include/results.h"

#define _POSIX_C_SOURCE 199309L

#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//
// Public
//

/**
 * @brief Simulates a case of an algorithm. 
 * 
 * @param a Algorithm to be simulated.
 * @param c Case to test.
 * @param buf Array of result_t, stores information about size, runtime.
 * @param n Number of unique runs.
 * 
 */

void benchmark(const algorithm_t a, const case_t c, result_t *buf, int n)
{
    switch (a) {
        case bubble_sort_t:
            switch (c) {
                case best_t:
                    simulate_sort(bubble_sort, getBestCaseBubbleSort, buf, n);
                    break;
                case worst_t:
                    simulate_sort(bubble_sort, getWorstCaseBubbleSort, buf, n);
                    break;
                case average_t:
                    simulate_sort(bubble_sort, getRandomizedArray, buf, n);
                    break;
            }
            break;

        case insertion_sort_t:
            switch (c) {
                case best_t:
                    simulate_sort(insertion_sort, getBestCaseInsertionSort, buf, n);
                    break;
                case worst_t:
                    simulate_sort(insertion_sort, getWorstCaseInsertionSort, buf, n);
                    break;
                case average_t:
                    simulate_sort(insertion_sort, getRandomizedArray, buf, n);
                    break;
            }
            break;

        case quick_sort_t:
            switch (c) {
                case best_t:
                    simulate_sort(quick_sort, getBestCaseQuickSortHigh, buf, n);
                    break;
                case worst_t:
                    simulate_sort(quick_sort, getWorstCaseQuickSortHigh, buf, n);
                    break;
                case average_t:
                    simulate_sort(quick_sort, getRandomizedArray, buf, n);
                    break;
            }
            break;

        case linear_search_t:
            switch (c) {
                case best_t:
                    simulate_search(linear_search, getBestCaseLinearSearch, buf, n);
                    break;
                case worst_t:
                    simulate_search(linear_search, getWorstCaseLinearSearch, buf, n);
                    break;
                case average_t:
                    simulate_search(linear_search, getAverageCaseSearch, buf, n);
                    break;
            }
            break;

        case binary_search_t:
            switch (c) {
                case best_t:
                    simulate_search(binary_search, getBestCaseBinarySearch, buf,n);
                    break;
                case worst_t:
                    simulate_search(binary_search, getWorstCaseBinarySearch, buf, n);
                    break;
                case average_t:
                    simulate_search(binary_search, getAverageCaseSearch, buf, n);
                    break;
            }
            break;

        default:
            printf("Unknown algorithm type.\n");
            break;
    }

    prepareResult(a,c,buf,n);

}

/**
 * @brief Simulates sorting of arrays of multiple sizes. Stores data about sizes and execution time in buf.
 * 
 * @param sfunc Sorting-function to use.
 * @param afunc Array-generating function to use.
 * @param buf Struct for storing array-size and average execution time.
 * @param n Number of array-sizes to simulate.
 */

void simulate_sort(sort_func sfunc, array_func afunc, result_t* buf, int n)
{
    warmup();

    int size = SIZE_START;
    for(int i=0; i<n; i++){
        buf[i].size = size;
        buf[i].time = average_time_sort_function(sfunc, afunc, size);
        size *= 2;
    }

}


/**
 * @brief Simulates searching of arrays of multiple sizes. Stores data about sizes and execution time in buf.
 * 
 * @param sfunc Sorting-function to use.
 * @param afunc Array- and value-generating function to be used.
 * @param buf Struct for storing array-size and average execution time.
 * @param n Number of array-sizes to simulate.
 */


void simulate_search(search_func sfunc, array_search_func afunc, result_t* buf, int n)
{
    // TODO: warmup

    int size = SIZE_START;
    for(int i=0; i<n; i++){
        buf[i].size = size;
        buf[i].time = average_time_search_function(sfunc, afunc,size);
        size *= 2;
    }

}

/**
 * @brief Records the time of a sort-function to sort a give array.
 * 
 * @param sfunc Sort-function.
 * @param array Array to be sorted.
 * @param size Size of the array.
 * @return Execution time in nanoseconds.
 */

long int time_sort_function(sort_func sfunc, int* array, int size){
    struct timespec start, end;
    long int result;

    clock_gettime(CLOCK_MONOTONIC, &start);
    (*sfunc)(array, size);
    clock_gettime(CLOCK_MONOTONIC, &end);

    result = (end.tv_nsec - start.tv_nsec) + (end.tv_sec-start.tv_sec)*pow(10,9);

    return result;

}
/**
 * @brief Records the time of a search-function to search an array for a given element.
 * 
 * @param sfunc Search-function.
 * @param a_v Struct with an array and the element to find within it.
 * @param size Size of the array.
 * @return Execution time in nanoseconds.
 */

long int time_search_function(search_func sfunc, array_and_value* a_v, int size){
    struct timespec start, end;  
    long int result;  
        
    clock_gettime(CLOCK_MONOTONIC, &start);
    (*sfunc)(a_v->array, size, a_v->element);
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    result = (end.tv_nsec - start.tv_nsec) + (end.tv_sec-start.tv_sec)*pow(10,9);

    return result;
}


/**
 * @brief Calculates the average result of multiple executions of a sort-function.
 * 
 * @param sfunc Sort-function.
 * @param afunc Function for array generation.
 * @param size Size of the array.
 * @return Average execution time in seconds.
 */

double average_time_sort_function(sort_func sfunc, array_func afunc, int size){
    double sum_ns = 0;
    double sum_s;
    for(int i=0; i < ITERATIONS; i++){
        int* array = (*afunc)(size);
        sum_ns += time_sort_function(sfunc, array, size);
        free(array);
    }
    sum_ns /= ITERATIONS;
    sum_s = sum_ns / pow(10,9);
    return sum_s;
}


/**
 * @brief Calculates the average result of multiple executions of a search-function.
 * 
 * @param sfunc Search-function.
 * @param afunc Function for array generation.
 * @param size Size of the array.
 * @return Average execution time in seconds.
 */

double average_time_search_function(search_func sfunc, array_search_func afunc, int size){
    double sum_ns = 0;
    double sum_s;
    for(int i=0; i < ITERATIONS; i++){
        array_and_value* a_v= (*afunc)(size);
        sum_ns += time_search_function(sfunc, a_v, size);
        free(a_v->array);
        free(a_v);
    }
    sum_ns /= ITERATIONS;
    sum_s = sum_ns / pow(10,9);
    return sum_s;
}

/**
 * @brief Fills a time_analysis_struct with quotients of the time divided by n-based factors.
 * 
 * @param buf Struct containing size and execution-time.
 * @param n The number of entries in 'buf'
 * @return pointer to time_analysis_struct containing result of all divisions
 */

time_analysis_struct** do_time_analysis(result_t* buf, int n){
    time_analysis_struct** t_a_array = malloc(sizeof(time_analysis_struct*)*n);

    for(int i=0; i <n; i++){
        time_analysis_struct* t_a = malloc(sizeof(time_analysis_struct));
        int n = buf[i].size;
        double time = buf[i].time;

        t_a->size = n;
        t_a->time_s = time;
        t_a->time_logn_s = time/log2(n);
        t_a->time_n_s = time/n;
        t_a->time_nlogn_s = time/(n*log2(n));
        t_a->time_n_squared_s = time/(pow(n,2));
        t_a->time_n_cubed_s = time/(pow(n,3)); 

        t_a_array[i] = t_a;
    }
    return t_a_array;
}

/**
 * @brief Function to determine the time-complexity of function with data from an array of time_analysis_structs
 * 
 * @param t_a_array Array of time_anlysis_structs
 * @param n Number of elements in the array
 * @return The corresponding time-complexity
 * 
 * @pre The time complexity of the function is between O(1) and O(n^3)
 * @post The time complexity is returned.
 */

time_complexity_t determineTimeComplexity(time_analysis_struct** t_a_array, int n){

    time_analysis_struct* t_a_largest = t_a_array[n-1];
    time_analysis_struct* t_a_second_largest = t_a_array[n-2];

    double const_dif = fabs(t_a_second_largest->time_s/t_a_largest->time_s - 1);
    double logn_dif = fabs(t_a_second_largest->time_logn_s/t_a_largest->time_logn_s - 1);
    double n_dif = fabs(t_a_second_largest->time_n_s/t_a_largest->time_n_s - 1);
    double nlogn_dif = fabs(t_a_second_largest->time_nlogn_s/t_a_largest->time_nlogn_s - 1);
    double n_squared_dif = fabs(t_a_second_largest->time_n_squared_s/t_a_largest->time_n_squared_s - 1);
    double n_cubed_dif = fabs(t_a_second_largest->time_n_cubed_s/t_a_largest->time_n_cubed_s - 1);

    double diffs[] = {const_dif, logn_dif, n_dif, nlogn_dif, n_squared_dif, n_cubed_dif};
    time_complexity_t enums[] = {O_1, O_LOGN, O_N, O_NLOGN, O_N_SQUARED, O_N_CUBED};

    double min_diff = diffs[0];
    time_complexity_t min_enum = enums[0];

    for (int i = 1; i < 5; i++) {
        if (diffs[i] < min_diff) {
            min_diff = diffs[i];
            min_enum = enums[i];
        }
    }

    return min_enum;
}

/**
 * @brief Warmup function.
 * 
 *  Getting the CPU to work before we start timing it.
 * 
 */

void warmup(){
    int size = SIZE_START;
    for(int i=0; i<3; i++){
        int* array = getRandomizedArray(size);
        bubble_sort(array, size);
        size *=2;
        free(array);
    }
}










