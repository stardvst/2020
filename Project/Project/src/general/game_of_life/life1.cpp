#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int row, col;
int *board = NULL;

int powInt(int x, int y)
{
	int i;
	for (i = 0; i < y; i++)
		x *= 10;
	return x;
}

int parseInt(char *chars)
{
	int sum = 0;
	int x;
	int len = strlen(chars);
	for (x = 0; x < len; x++)
	{
		int n = chars[len - (x + 1)] - '0';
		sum = sum + powInt(n, x);
	}
	return sum;
}

void initialize_board()
{
	/* create the board */
	board = (int *)malloc(row * col * sizeof(int));
	int i, j;

	/* intiialize all cells to 0 */
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			int idx = i * col + j;
			*(board + idx) = 0;
		}
	}
}

int read_file(const char *fileName)
{
	FILE *f;
	int	j;
	char s[100];
	int r, c;

	f = fopen(fileName, "r");
	int cellCount = 0;

	/* read a line */
	if (fgets(s, 100, f))
	{
		/* first line is alive cell count */
		sscanf(s, "%d", &cellCount);

		/* read alive cell coordinates */
		for (j = 0; j < cellCount; j++)
		{
			fgets(s, 100, f);
			sscanf(s, "%d %d", &r, &c);

			/* make sure cell is within board boundaries */
			if (!(c > 0 && c <= col && r > 0 && r < row))
			{
				fprintf(stderr, "Cell is outside the board\n");
				return -1;
			}

			/* mark alive cell in the board */
			*(board + r * col + c) = 1;
		}
	}

	fclose(f);
	return 0;
}

void print()
{
	int	i, j;

	/* preint first row */
	printf("*");
	for (i = 0; i < col; ++i)
		printf("-");
	printf("*\n");

	/* preint the board */
	for (i = 0; i < row; i++)
	{
		printf("|");

		for (j = 0; j < col; j++)
			printf("%c", *(board + i * col + j) ? 'X' : ' ');
		printf("|\n");
	}

	/* preint last row */
	printf("*");
	for (i = 0; i < col; ++i)
		printf("-");
	printf("*\n");
}

void next()
{
	int	i, j;
	int *newboard = (int *)malloc(row * col * sizeof(int));

	/* get alive neighbour count for each cell */
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			int aliveNeighbours = 0;

			/* next column */
			if (j + 1 < col) aliveNeighbours += *(board + i * col + (j + 1));

			if (i + 1 < row)
			{
				/* next row */
				aliveNeighbours += *(board + (i + 1) * col + j);

				/* next row and next column */
				if (j + 1 < col) aliveNeighbours += *(board + (i + 1) * col + (j + 1));
			}

			if (j - 1 >= 0)
			{
				/* previous column */
				aliveNeighbours += *(board + i * col + (j - 1));

				/* previous column and next row */
				if (i + 1 < row) aliveNeighbours += *(board + (i + 1) * col + (j - 1));
			}

			if (i - 1 >= 0)
			{
				/* previous row */
				aliveNeighbours += *(board + (i - 1) * col + j);

				/* previous row and previous column */
				if (j - 1 >= 0) aliveNeighbours += *(board + (i - 1) * col + (j - 1));

				/* previous row and next column */
				if (j + 1 < col) aliveNeighbours += *(board + (i - 1) * col + (j + 1));
			}

			/* current cell dies from loneliness */
			if ((*(board + i * col + j) == 1) && (aliveNeighbours < 2))
				*(newboard + i * col + j) = 0;

			/* current cell dies from overcrowding */
			else if ((*(board + i * col + j) == 1) && (aliveNeighbours > 3))
				*(newboard + i * col + j) = 0;

			/* current dead cell will become alive */
			else if ((*(board + i * col + j) == 0) && (aliveNeighbours == 3))
				*(newboard + i * col + j) = 1;

			/* otherwise it stays the same */
			else
				*(newboard + i * col + j) = (*(board + i * col + j));
		}
	}

	/* copy the new board to current board */
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
			*(board + i * col + j) = *(newboard + i * col + j);

	free(newboard);
}

int main(const int argc, char *argv[])
{
	int generations, i;

	if (argc != 5)
	{
		fprintf(stderr, "Usage: <program> <file> <width> <height> <rounds>");
		return -1;
	}

	/* get generation count */
	sscanf(argv[4], "%d", &generations);

	/* get board width and height */
	sscanf(argv[3], "%d", &row);
	sscanf(argv[2], "%d", &col);

	/* initialize the board */
	initialize_board();

	/* read the file for alive cells */
	if (read_file(argv[1]) != 0)
		return -1;

	/* print the initial board */
	print();

	/* process next generations */
	for (i = 0; i < generations; ++i)
	{
		/* print 2 blank lines after each generation */
		printf("\n\n");

		/* get next generation */
		next();

		/* print new generation */
		print();
	}

	/* print Finished */
	printf("\nFinished\n");

	free(board);
	return 0;
}
