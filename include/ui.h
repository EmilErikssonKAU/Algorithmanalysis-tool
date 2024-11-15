#ifndef UI_H
#define UI_H

#include "../include/analyze.h"

#define MENU_WIDTH 40
#define RESULT_ROWS 6

// ui_run starts a terminal-based user interface
void ui_run();
void ui_print_results(result_t* buf, int n);

#endif
