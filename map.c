#include <stdio.h>
#include <stdlib.h>
#include "map.h"


//initialize the map with default values
int map[MAP_HEIGHT][MAP_WIDTH] = {0};

int loadMap(const char *filePath)
{
	FILE *file = fopen(filePath, "r");

	if (!file)
	{
		fprintf(stderr, "Error: Could not open map file %s\n", filePath);
		return (-1);
	}

	// Read the map file line by line
	for (int y = 0; y < MAP_HEIGHT; ++y)
	{
		for (int x = 0; x < MAP_WIDTH; ++x)
		{
			int c = fgetc(file);

			if (c == EOF)
			{
				fprintf(stderr, "Error: Unexpected end of map file %s\n", filePath);
				fclose(file);
				return (-1);
			}
			if (c == '1' || c == '0')
			{
				map[y][x] = c - '0';
			}
			else if (c == '\n' || c == '\r')
			{
				x--;
			}
			else
			{
				fprintf(stderr, "Error: Invalid character '%c' in map file %s\n", c, filePath);
				fclose(file);
				return (-1);
			}
		}
		while (fgetc(file) != '\n' && !feof(file));
	}
	fclose(file);
	return (0);
}
