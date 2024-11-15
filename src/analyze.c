#include "../include/analyze.h"
#include "../include/algorithm.h"
#include "../include/arraygeneration.h"
#include "../include/ui.h"

#define _POSIX_C_SOURCE 199309L

#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
    

//
// Private
//



//
// Public
//

/**
 * @brief 
 * 
 * @param a Algorithm to be simulated.
 * @param c Case to test.
 * @param buf Array of result_t, stores information about size, runtime.
 * @param n Number of unique runs.
 * 
 * @pre
 * @post
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
                    printf("Handling bubble sort in average case.\n");
                    break;
            }
            break;

        case insertion_sort_t:
            switch (c) {
                case best_t:
                    printf("Handling insertion sort in best case.\n");
                    break;
                case worst_t:
                    printf("Handling insertion sort in worst case.\n");
                    break;
                case average_t:
                    printf("Handling insertion sort in average case.\n");
                    break;
            }
            break;

        case quick_sort_t:
            switch (c) {
                case best_t:
                    printf("Handling quick sort in best case.\n");
                    break;
                case worst_t:
                    printf("Handling quick sort in worst case.\n");
                    break;
                case average_t:
                    printf("Handling quick sort in average case.\n");
                    break;
            }
            break;

        case linear_search_t:
            switch (c) {
                case best_t:
                    printf("Handling linear search in best case.\n");
                    break;
                case worst_t:
                    printf("Handling linear search in worst case.\n");
                    break;
                case average_t:
                    printf("Handling linear search in average case.\n");
                    break;
            }
            break;

        case binary_search_t:
            switch (c) {
                case best_t:
                    printf("Handling binary search in best case.\n");
                    break;
                case worst_t:
                    printf("Handling binary search in worst case.\n");
                    break;
                case average_t:
                    printf("Handling binary search in average case.\n");
                    break;
            }
            break;

        default:
            printf("Unknown algorithm type.\n");
            break;
    }

    ui_print_results(buf, n);
}


void simulate_sort(sort_func sfunc, array_func afunc, result_t* buf, int n)
{
    // TODO: warmup

    int size = SIZE_START;
    for(int i=0; i<n; i++){
        buf[i].size = size;
        buf[i].time = average_time_sort_function(sfunc, afunc, size);
        size *= 2;
    }

}

void simulate_search(search_func sfunc, array_search_func afunc, result_t* buf, int n)
{
    // TODO: warmup



}


int time_sort_function(sort_func sfunc, int* array, int size){
    struct timespec start, end;

    clock_gettime(CLOCK_MONOTONIC, &start);
    (*sfunc)(array, size);
    clock_gettime(CLOCK_MONOTONIC, &end);

    return end.tv_nsec - start.tv_nsec;

}

int time_search_function(search_func sfunc, array_and_value* a_v, int size){
    struct timespec start, end;    
        
    clock_gettime(CLOCK_MONOTONIC, &start);
    (*sfunc)(a_v->array, a_v->element, size);
    clock_gettime(CLOCK_MONOTONIC, &end);

    return end.tv_nsec - start.tv_nsec;
}

int average_time_sort_function(sort_func sfunc, array_func afunc, int size){
    int sum_ns = 0;
    for(int i=0; i < ITERATIONS; i++){
        int* array = (*afunc)(size);
        sum_ns += time_sort_function(sfunc, array, size);
        free(array);
    }
    return sum_ns/ITERATIONS;
}

int average_time_search_function(search_func sfunc, array_search_func afunc, int size){
    int sum_ns = 0;
    for(int i=0; i < ITERATIONS; i++){
        array_and_value* a_v= (*afunc)(size);
        sum_ns += time_search_function(sfunc, a_v, size);
        // continue ...
        //
    }
    return sum_ns/ITERATIONS;
}







