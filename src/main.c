#define _POSIX_C_SOURCE 199309L

#include "../include/ui.h"
#include "../include/algorithm.h"
#include "../include/results.h"
#include "../include/analyze.h"

#include <stdio.h>
#include <limits.h> 
#include <math.h>
#include <unistd.h>
#include <time.h>

void printArray(int* array, int size){
	for(int i=0; i<size; i++){
		printf("%d  ", array[i]);
	}
}

int main()
{
	// struct timespec start, end;    
        
    // clock_gettime(CLOCK_MONOTONIC, &start);

	// int size = 16384;
	// int* array = getWorstCaseBubbleSort(size);
	// printArray(array, size);
	// printf("\n\n");
	// bubble_sort(array, size);

	// clock_gettime(CLOCK_MONOTONIC, &end);

	// printArray(array, size);

	// printf("\n\nEND: Seconds: %ld, Nanoseconds: %ld\n", end.tv_sec, end.tv_nsec);
	// printf("START: Seconds: %ld, Nanoseconds: %ld\n", start.tv_sec, start.tv_nsec);

	ui_run();

	return 0;
}

