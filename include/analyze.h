#ifndef ANALYZE_H
#define ANALYZE_H

#define SIZE_START 512
#define ITERATIONS 7

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


typedef struct{
	int size;
	double time_s;
	double time_logn_s;
	double time_n_s;
	double time_nlogn_s;
	double time_n_squared_s;
	double time_n_cubed_s;
} time_analysis_struct;


typedef enum{
	O_1,
	O_LOGN,
	O_N,
	O_NLOGN,
	O_N_SQUARED,
	O_N_CUBED
} time_complexity_t;

// benchmark benchmarks an algorithm a for a specific case c, writing n results
// to the result buffer buf
void benchmark(const algorithm_t a, const case_t c, result_t *buf, int n);

void simulate_sort(sort_func sfunc, array_func afunc, result_t* buf, int n);

void simulate_search(search_func sfunc, array_search_func afunc, result_t* buf, int n);

long int time_sort_function(sort_func sfunc, int* array, int size);

long int time_search_function(search_func sfunc, array_and_value* a_v, int size);

double average_time_sort_function(sort_func sfunc, array_func afunc, int size);

double average_time_search_function(search_func sfunc, array_search_func afunc, int size);

time_analysis_struct** do_time_analysis(result_t* buf, int n);

time_complexity_t determineTimeComplexity(time_analysis_struct** t_a_array, int n);

#endif
