#ifndef IO_H
#define IO_H

#include "analyze.h"

// read_line reads at least one and at most n-2 characters from stdin, writing a
// null-terminated result to buf; possible overflows are handled and and the
// length of buf is returned, e.g., 5 for "hello" and 0 on error.
int read_line(char *buf, int n);
char** build_headline(time_complexity_t t_c);

#endif
