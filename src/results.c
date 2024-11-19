#include "../include/ui.h"
#include "../include/analyze.h"
#include "../include/results.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/**
 * @brief Builds result lines from a time_analysis_struct.
 * 
 * @param t_c Time complexity from the result.
 * @param t_a The time anlysis data.
 * @param n Number of array sizes examined.
 * @return The result lines.
 */

double*** build_result_lines(time_complexity_t t_c, time_analysis_struct** t_a, int n){
	// size, T(s), vary, vary+1, vary+2

	int t_a_index = tc_to_index_start(t_c);

	// Convert time_anlysis_struct data to array

	double t_a_array[n][7];
	for(int i=0; i<n; i++){
		t_a_array[i][0] = t_a[i] ->size;
	}
	for(int i=0; i<n; i++){
		t_a_array[i][1] = t_a[i] ->time_s;
	}
	for(int i=0; i<n; i++){
		t_a_array[i][2] = t_a[i] ->time_logn_s;
	}
	for(int i=0; i<n; i++){
		t_a_array[i][3] = t_a[i] ->time_n_s;
	}
	for(int i=0; i<n; i++){
		t_a_array[i][4] = t_a[i] ->time_nlogn_s;
	}
	for(int i=0; i<n; i++){
		t_a_array[i][5] = t_a[i] ->time_n_squared_s;
	}
	for(int i=0; i<n; i++){
		t_a_array[i][6] = t_a[i] ->time_n_cubed_s;
	}


	// Allocate space for pointers to lines
	double*** result_lines = malloc(n * sizeof(double**));

	// Allocate space for pointers to fields
	for(int i=0; i<n; i++){
		double** line = malloc(RESULT_FIELDS*sizeof(double*));
		result_lines[i] = line;

		// Allocate space for the fields
		for(int j=0; j < RESULT_FIELDS; j++){
			double* field = malloc(sizeof(double));
			result_lines[i][j] = field;

			// Set value of field
			if(j<2){
				*field = t_a_array[i][j];
			}
			else{
				*field = t_a_array[i][j+t_a_index];
			}
		}
	}

	return result_lines;

}

/**
 * @brief Convert a given time comlexity to corresponding start index.
 * 
 * The index calculated is the start-index for displaying the desired three time complexities
 * in the result summary.
 * 
 * @param t_c Time complexity.
 * @return Index.
 */

int tc_to_index_start(time_complexity_t t_c){
	int quotient_start;
	switch(t_c)
	{
		case O_1:
			quotient_start = 0;
			break;
		case O_LOGN:
			quotient_start = 0;
			break;
		case O_N:
			quotient_start = 0;
			break;
		case O_NLOGN:
			quotient_start = 1;
			break;
		case O_N_SQUARED:
			quotient_start = 2;
			break;
		case O_N_CUBED:
			quotient_start = 2;
			break;
		default:
			quotient_start = 2;
			break;
	}
	return quotient_start;
}


/**
 * @brief Create the lines to be printed by ui_print_result.
 * 
 */

void prepareResult(const algorithm_t a, const case_t c, result_t *buf, int n){
    time_analysis_struct** t_a = do_time_analysis(buf, n);
    time_complexity_t t_c = determineTimeComplexity(t_a,n);
    char** headline = build_headline(t_c);
    double*** result_lines = build_result_lines(t_c, t_a, n);
    char* title = algorithm_to_string(a,c);
    ui_print_result(headline, result_lines, title, n);
}

/**
 * @brief Constructs a headline for the ui based on time complexity of case.
 * 
 * @param t_c Time complexity.
 * @return Headline.
 */

char** build_headline(time_complexity_t t_c){
    char* titles [] = {
        "Size",
        "T(s)",
        "T/logn",
        "T/n",
        "T/nlogn",
        "T/n²",
        "T/n³"
    };

    int t_c_index = tc_to_index_start(t_c);

     
    char** headline = malloc(RESULT_FIELDS*sizeof(char*));

    for(int i=0; i < RESULT_FIELDS; i++){
        char* title = malloc(MAX_FIELD_LENGTH*sizeof(char));
        if(i==0)
            strcpy(title, titles[0]);
        else if(i==1)
            strcpy(title, titles[1]);
        else{
            strcpy(title, titles[i+t_c_index]);
        }
        headline[i] = title;
    }

    return headline;
}


/**
 * @brief Converts the algorithm and the case analyzed to a string.
 * 
 * @param a Algorithm.
 * @param c Case.
 * @return Corresponding string-
 */

char* algorithm_to_string(const algorithm_t a, const case_t c){
    switch (a) {
        case bubble_sort_t:
            switch (c) {
                case best_t:
                    return "Bubble sort best case";
                case worst_t:
                    return "Bubble sort worst case";
                case average_t:
                    return "Bubble sort average case";
            }
            break;

        case insertion_sort_t:
            switch (c) {
                case best_t:
                    return "Insertion sort best case";
                case worst_t:
                    return "Insertion sort worst case";
                case average_t:
                    return "Insertion sort average case";
            }
            break;

        case quick_sort_t:
            switch (c) {
                case best_t:
                    return "Quick sort best case";
                case worst_t:
                    return "Quick sort worst case";
                case average_t:
                    return "Quick sort average case";
            }
            break;

        case linear_search_t:
            switch (c) {
                case best_t:
                    return "Linear search best case";
                case worst_t:
                    return "Linear search worst case";
                case average_t:
                    return "Linear search average case";
            }
            break;

        case binary_search_t:
            switch (c) {
                case best_t:
                    return "Binary search best case";
                case worst_t:
                    return "Binary search worst case";
                case average_t:
                    return "Binary search average case";
            }
            break;

        default:
            return "Unknown algorithm";
    }
    return NULL;
}