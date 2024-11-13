#include "io.h"
#include <stdio.h>
#include <string.h>

//
// Private
//

/**
 * @brief Empty the input buffer until EOF or '\n' is reached
 * 
 */

static void empty_stream()
{
	int c;

	while ((c = getchar()) != EOF && c != '\n')
		;
}

//
// Public
//

/**
 * @brief Read line
 * 
 * @param buf Pointer to char array
 * @param n Length of char array
 * @return The number of chars read, 0 if error occurs
 * 
 */

int read_line(char *buf, int n)
{
	int buf_size;

	if (!fgets(buf, n, stdin)) {
		empty_stream();
		return 0; // overflow
	}

	buf_size = strlen(buf);
	if (buf[buf_size-1] != '\n') {
		empty_stream();
		return 0; // overflow
	}

	// remove new line
	buf[buf_size-1] = '\0';
	return buf_size-1;
}
