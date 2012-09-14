
#include <stdio.h>

#include "color-route.h"

enum term_mode {
	NORMAL		= 0,
	BRIGHT 		= 1,
	DIM		= 2,
	UNDERLINE 	= 3,
	BLINK		= 4,
	REVERSE		= 7,
	HIDDEN		= 8
};

static void term_set_mode(enum term_mode mode)
{
	printf("\x1B[%dm", mode);
}

static void term_set_fg(enum term_color fg)
{
	if (fg != NONE) printf("\x1B[%dm", 30 + fg);
}

/* 
 * static void term_set_bg(enum term_color bg)
 * {
 * 	if (bg != NONE) printf("\x1B[%dm", 40 + bg);
 * }
 */

static void term_reset(void)
{
	term_set_mode(NORMAL);
}

void print_route(const char *from, const char *to, enum term_color fg)
{
	if (fg != NONE) {
		term_set_fg(fg);
		printf("%s", from);
		term_reset();
		printf(" > ");
		term_set_fg(fg);
		printf("%s", to);
		term_reset();
		printf(": ");
	} else {
		printf("%s > %s: ", from, to);
	}
}

void print_route2(const char *from, const char *from_port, const char *to,
		  const char *to_port, enum term_color fg)
{
	if (fg != NONE) {
		term_set_fg(fg);
		printf("%s", from);
		term_reset();
		printf(".%s > ", from_port);
		term_set_fg(fg);
		printf("%s", to);
		term_reset();
		printf(".%s: ", to_port);
	} else {
		printf("%s.%s > %s.%s: ", from, from_port, to, to_port);
	}
}
