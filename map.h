#ifndef MAP_H
#define MAP_H

#define MAP_WIDTH 10
#define MAP_HEIGHT 7
#define TITLE_SIZE 64

extern int map[MAP_HEIGHT][MAP_WIDTH];
int loadMap(const char* filePath);

#endif
