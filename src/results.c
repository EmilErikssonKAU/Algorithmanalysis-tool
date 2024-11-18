#include "../include/ui.h"
#include "../include/analyze.h"
#include "../include/results.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * @brief 
 * 
 * @param t_c 
 * @param t_a 
 * @param n 
 * @return double*** 
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
 * @brief 
 * 
 * @param t_c 
 * @return int 
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
 * @brief Prepare result for print
 * 
 */

void prepareResult(result_t *buf, int n){
    time_analysis_struct** t_a = do_time_analysis(buf, n);
    time_complexity_t t_c = determineTimeComplexity(t_a,n);

    char** headline = build_headline(t_c);

    for(int i=0; i <RESULT_FIELDS; i++){
        printf("%s  ", headline[i]);
    }

    printf("\n\n");

    double*** result_lines = build_result_lines(t_c, t_a, n);

    for(int i=0; i<n; i++){
        for(int j=0; j<RESULT_FIELDS; j++){
            if(j==0){
                printf("%d   ", (int)*result_lines[i][j]);
                continue;
            }
            if(j==1){
                printf("%.9lf  ", *result_lines[i][j]);
                continue;
            }
            printf("%e   ", *result_lines[i][j]);
        }
        printf("\n");
    }
}

/**
 * @brief 
 * 
 * @param t_c 
 * @return char** 
 */

char** build_headline(time_complexity_t t_c){
    char* titles [] = {
        "Size",
        "T(n)",
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