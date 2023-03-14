#include <stdio.h>
#include <stdlib.h>

int **alloc_grid(int, int);
void free_grid(int **, int);

/**
 * main - check the code .
 *
 * Return: Always 0.
 */
int main(void)
{
	int **grid;
	int h;
	int w;

	h = 10;
	w = 20;
	grid = alloc_grid(w, h);
	if (grid == NULL)
	{
		return (1);
	}
	free_grid(grid, h);
	return (0);
}

