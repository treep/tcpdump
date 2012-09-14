
/*
 * Coloring routes in the `tcpdump' output using ANSI terminal codes.
 */

#ifndef COLOR_ROUTE_H
#define COLOR_ROUTE_H

extern int color_flag;

enum term_color {
	BLACK 		= 0,
	RED		= 1,
	GREEN		= 2,
	YELLOW		= 3,
	BLUE		= 4,
	MAGENTA		= 5,
	CYAN		= 6,
	WHITE		= 7,
	NONE		= -1
};

void print_route(const char *from, const char *to, enum term_color fg);
void print_route2(const char *from, const char *from_port, const char *to,
		  const char *to_port, enum term_color fg);

#endif /* COLOR_ROUTE_H */
