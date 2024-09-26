#include <SDL2/SDL.h>
#include "render.h"
#include "player.h"
#include "map.h"
#include "constants.h"
#include <math.h>

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s <path to map file>\n", argv[0]);
		return (1);
	}

	// Load the map from the specified file
	if (loadMap(argv[1]) != 0)
	{
		return (1);
	}

	// SDL Initialization
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not be initialized! SDL Error: %s\n", SDL_GetError());
		return (1);
	}

	SDL_Window *window = SDL_CreateWindow("Njike's Maze Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (window == NULL)
	{
		printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
		return (1);
	}

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	int quit = 0;
	int showMinimap = 1;  // Boolean to control the mini-map state
	SDL_Event e;

	while (!quit)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				quit = 1;
			}
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_m)
			{
				showMinimap = !showMinimap;  // Toggle mini-map
			}
		}

		const Uint8 *keyState = SDL_GetKeyboardState(NULL);
		movePlayer(keyState);  // Pass the key state to movePlayer
		render(renderer, showMinimap);  // Pass the mini-map state to the render function

		SDL_Delay(16); // Approx. 60FPS
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return (0);
}
