#include "../include/ui.h"
#include "../include/io.h"
#include "../include/analyze.h"

#include <stdbool.h>
#include <stdio.h>
#include <math.h>

//
// Private
//

/**
 * @brief Display bad input message.
 * 
 */

static void ui_invalid_input()
{
	printf("info> bad input\n");
}

/**
 * @brief Display exit message.
 * 
 */

static void ui_exit()
{
	printf("info> bye\n");
}


/**
 * @brief Displays prompt. Then reads up to 2 characters from stdin.
 * 
 * @return The first character read if successfull. 0 if unsucessfull.
 */

static char ui_get_choice()
{
	char buf[3];

	printf("input> ");
	return read_line(buf, 3) ? buf[0] : 0;
}


/**
 * @brief Prints 'n' chars of type 'c'. Print newline.
 * 
 * @param c The char to be printed.
 * @param n Number of times to print the char.
 */

static void ui_line(char c, int n)
{
	while (n-- > 0) {
		putchar(c);
	}
	putchar('\n');
}


/**
 * @brief Prints a list of menu options with alphabetic labels.
 * 
 * @param options An array of strings.
 * @param num_options The number of strings to be printed from the array.
 */

static void ui_menu_options(const char *options[], int num_options)
{
	int i;

	for (i=0; i<num_options; i++) {
		printf("    %c) %s\n", 'a'+i, options[i]);
	}
}


/**
 * @brief Prints the menu options available to the user.
 * 
 */


static void ui_menu()
{
	const char *options[] = {
		"Menu",
		"Exit\n",
		"Bubble sort best case",
		"Bubble sort worst case",
		"Bubble sort average case\n",
		"Insertion sort best case",
		"Insertion sort worst case",
		"Insertion sort average case\n",
		"Quick sort best case",
		"Quick sort worst case",
		"Quick sort average case\n",
		"Linear search best case",
		"Linear search worst case",
		"Linear search average case\n",
		"Binary search best case",
		"Binary search worst case",
		"Binary search average case"


		// TODO: complete menu
	};

	ui_line('=', MENU_WIDTH);
	ui_menu_options(options, sizeof(options) / sizeof(char *));
	ui_line('-', MENU_WIDTH);
}

//
// Public
//


/**
 * @brief Main ui loop
 * 
 */

void ui_run()
{
	bool running, show_menu;
	result_t result[RESULT_ROWS];
	
	show_menu = true;
	running = true;
	while (running) {
		if (show_menu) {
			show_menu = false;
			ui_menu();
		}
		switch (ui_get_choice()) {
			// House keeping
			case 'a':
				show_menu = true;
				break;
			case 'b':
				running = false;
				break;
			// Bubble sort
			case 'c':
				benchmark(bubble_sort_t, best_t, result, RESULT_ROWS);
				break;
			case 'd': 
				benchmark(bubble_sort_t, worst_t, result, RESULT_ROWS);
				break;
			case 'e': 
				benchmark(bubble_sort_t, average_t, result, RESULT_ROWS);
				break;
			case 'f':
				benchmark(insertion_sort_t, best_t, result, RESULT_ROWS);
				break;
			case 'g':
				benchmark(insertion_sort_t, worst_t, result, RESULT_ROWS);
				break;
			case 'h':
				benchmark(insertion_sort_t, average_t, result, RESULT_ROWS);
				break;
			case 'i':
				benchmark(quick_sort_t, best_t, result, RESULT_ROWS);
				break;
			case 'j':
				benchmark(quick_sort_t, worst_t, result, RESULT_ROWS);
				break;
			case 'k':
				benchmark(quick_sort_t, average_t, result, RESULT_ROWS);
				break;
			case 'l':
				benchmark(linear_search_t, best_t, result, RESULT_ROWS);
				break;
			case 'm':
				benchmark(linear_search_t, worst_t, result, RESULT_ROWS);
				break;
			case 'n':
				benchmark(linear_search_t, average_t, result, RESULT_ROWS);
				break;
			case 'o':
				benchmark(binary_search_t, best_t, result, RESULT_ROWS);
				break;
			case 'p':
				benchmark(binary_search_t, worst_t, result, RESULT_ROWS);
				break;
			case 'q':
				benchmark(binary_search_t, average_t, result, RESULT_ROWS);
				break;
				
			// Invalid input
			default:
				show_menu = false;
				ui_invalid_input();
				break;
		}
	}
	ui_exit();
}


void ui_print_results(time_analysis_struct* t_a, int n){

	const char* equations[] = {
		"T(s)",
		"T/logn",
		"T/n",
		"T/nlogn"
		"T/n²",
		"T/n³"
	};

	ui_line('*', MENU_WIDTH);
	// TODO: print algorithm name
	ui_line('-', MENU_WIDTH);
	// TODO: print headlines

}
