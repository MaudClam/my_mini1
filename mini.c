
#include "header.h"

void	ft_bzero(void *s, size_t n)
{
	char	*a;
	
	a = s;
	while (n--)
		*(a++) = 0;
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

char	find_char(t_canvas c, t_circle *cr)
{
	int	i;
	
	i = c.figs - 1;
	while (i >= 0)
	{
		if (cr[i].t == 'C' && sqrt((c.x - cr[i].x) * (c.x - cr[i].x) + \
			(c.y - cr[i].y) * (c.y - cr[i].y)) < cr[i].r)
			return (cr[i].f);
		else if (cr[i].t == 'c' && sqrt((c.x - cr[i].x) * (c.x - cr[i].x) + \
			(c.y - cr[i].y) * (c.y - cr[i].y)) < cr[i].r && \
			!(sqrt((c.x - cr[i].x) * (c.x - cr[i].x) + \
			(c.y - cr[i].y) * (c.y - cr[i].y)) < cr[i].r - 1.00000000))
			return (cr[i].f);
		i--;
	}
	
	return (c.b);
}

int main(int argc, const char * argv[])
{
	FILE		*file;
	int			scan;
	t_canvas	c;
	t_circle	cr[1000];

	ft_bzero(&c, sizeof(t_canvas));
	ft_bzero(&cr, sizeof(t_circle) * 1000);
	if (argc != 2)
	{
		write(1, "Error: argument\n", 16);
		return (1);
	}
	if (!(file = fopen(argv[1], "r")))
	{
		write(1, "Error: Operation file corrupted\n", 32);
		return (1);
	}
	if ((scan = fscanf(file, "%d %d %c\n", &c.w, &c.h, &c.b)) != 3 ||\
		c.w <=0 || c.h <= 0 || c.w > 300 || c.h > 300)
	{
		write(1, "Error: Operation file corrupted\n", 32);
		fclose(file);
		return (1);
	}
	while ((scan = fscanf(file, "%c %f %f %f %c\n", \
		&cr[c.figs].t, &cr[c.figs].x, &cr[c.figs].y, &cr[c.figs].r, &cr[c.figs].f)) == 5)
	{
		if ((cr[c.figs].t != 'C' && cr[c.figs].t != 'c') || cr[c.figs].r <= 0.00000000)
		{
			write(1, "Error: Operation file corrupted\n", 32);
			fclose(file);
			return (1);
		}
		c.figs++;
	}
	if (scan != -1)
	{
		write(1, "Error: Operation file corrupted\n", 32);
		fclose(file);
		return (1);
	}
	fclose(file);
	while (c.y < c.h)
	{
		c.x = 0;
		while (c.x < c.w)
		{
			ft_putchar (find_char(c, cr));
			c.x++;
		}
		ft_putchar ('\n');
		c.y++;
	}
	return (0);
}
