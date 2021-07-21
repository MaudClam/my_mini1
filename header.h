#ifndef HEADER_H
#define HEADER_H

# include <unistd.h>
# include <stdio.h>
# include <math.h>

typedef struct	s_canvas
{
	int			w;
	int			h;
	int			x;
	int			y;
	char		b;
	int			figs;
}				t_canvas;

typedef struct	s_circle
{
	char		t;
	float		x;
	float		y;
	float		r;
	char		f;
}				t_circle;

#endif
