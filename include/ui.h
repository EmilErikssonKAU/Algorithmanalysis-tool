#ifndef UI_H
#define UI_H

#include "../include/analyze.h"

// INCREASE TO IMPROVE PRECISION, BUT LOWER PERFORMANCE
#define RESULT_ROWS 6

// DO NOT TOUCH
#define MENU_WIDTH 80
#define RESULT_FIELDS 5
#define MAX_FIELD_LENGTH 7

// ui_run starts a terminal-based user interface
void ui_run();
void ui_print_result(char** headline, double*** resultlines, char* title, int nlines);

#endif
