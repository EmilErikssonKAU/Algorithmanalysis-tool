#include "../include/analyze.h"
#include "../include/algorithm.h"
#include <stddef.h>

//
// Typedefs
//

typedef void (*sort_func)(int*, int);
typedef bool (*search_func)(const int*, int, int);
typedef void (*array_func)(int);

//
// Private
//

/**
 * @brief Get pointer to algorithm function
 * 
 * @param a Type of algorithm 
 * @return Pointer to algorithm function matching 'a'. Null if no match exists.
 */

static void* getAlgoritm(const algorithm_t a)
{
    switch (a)
    {
    case bubble_sort_t:
        return (sort_func) &bubble_sort;
    case insertion_sort_t:
        return (sort_func) &insertion_sort;
    case quick_sort_t:
        return (sort_func) &quick_sort;
    case linear_search_t:
        return (search_func) &linear_search;
    case binary_search_t:
        return (search_func) &binary_search;
    default:
        return NULL;
    }
}


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
                    printf("Handling bubble sort in best case.\n");
                    break;
                case worst_t:
                    printf("Handling bubble sort in worst case.\n");
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
}


void simulate_sort(sort_func* sfunc, array_func* afunc, result_t* buf, int n)
{

}

void simulate_search(search_func* func, array_func* afunc, result_t* buf, int n)
{
    
}
