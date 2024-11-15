#ifndef ANALYZE_H
#define ANALYZE_H

#define SIZE_START 512
#define ITERATIONS 4

#include "../include/arraygeneration.h"
#include <stdbool.h>

//
// Typedefs
//

typedef void (*sort_func)(int*, int);
typedef bool (*search_func)(const int*, int, int);
typedef int* (*array_func)(int);
typedef array_and_value* (*array_search_func)(int);

// algorithm_t defines different algorithms
typedef enum {
	bubble_sort_t,
	insertion_sort_t,
	quick_sort_t,
	linear_search_t,
	binary_search_t
} algorithm_t;

// case_t defines different cases
typedef enum {
	best_t,
	worst_t,
	average_t,
} case_t;

// result_t defines a timed measurement for a given array size
typedef struct {
	int size;
	double time;
} result_t;

// benchmark benchmarks an algorithm a for a specific case c, writing n results
// to the result buffer buf
void benchmark(const algorithm_t a, const case_t c, result_t *buf, int n);

void simulate_sort(sort_func sfunc, array_func afunc, result_t* buf, int n);

void simulate_search(search_func sfunc, array_search_func afunc, result_t* buf, int n);

int time_sort_function(sort_func sfunc, int* array, int size);

int time_search_function(search_func sfunc, array_and_value* a_v, int size);

int average_time_sort_function(sort_func sfunc, array_func afunc, int size);

int average_time_search_function(search_func sfunc, array_search_func afunc, int size);

#endif
