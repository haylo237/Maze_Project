#include <SDL2/SDL.h>
#include <math.h>
#include "player.h"
#include "constants.h"
#include "map.h"

//Player Properties
float playerX = 128;
float playerY = 128;
float playerAngle = 0;
const float playerRadius = 5.0;

void movePlayer(const Uint8* keyState)
{
	// Store the player's current position
	float newX = playerX;
	float newY = playerY;

	if (keyState[SDL_SCANCODE_W])
	{
		// Move Forward
		newX += cos(playerAngle * M_PI / 180) * MOVE_SPEED;
		newY += sin(playerAngle * M_PI / 180) * MOVE_SPEED;
	}
	if (keyState[SDL_SCANCODE_S])
	{
		// Move Backward
		newX -= cos(playerAngle * M_PI / 180) * MOVE_SPEED;
		newY -= sin(playerAngle * M_PI / 180) * MOVE_SPEED;
	}
	if (keyState[SDL_SCANCODE_A])
	{
		// Rotate Left
		playerAngle -= ROTATE_SPEED;
	}
	if (keyState[SDL_SCANCODE_D])
	{
		// Rotate right
		playerAngle += ROTATE_SPEED;
	}

	// Collision detection
	int mapX = (int)(newX / TILE_SIZE);
	int mapY = (int)(newY / TILE_SIZE);

	if (map[mapY][mapX] == 0)
	{
		playerX = newX;
		playerY = newY;
	}
	else 
	{
		int playerMapX = (int)(playerX / TILE_SIZE);
		int playerMapY = (int)(playerY / TILE_SIZE);

		if (map[playerMapY][mapX] == 0)
		{
			playerX = newX;
		}
		if (map[mapY][playerMapX] == 0)
		{
			playerY = newY;
		}
	}	
}
