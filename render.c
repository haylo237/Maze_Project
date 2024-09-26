#include <SDL2/SDL.h>
#include <math.h>
#include "render.h"
#include "map.h"
#include "player.h"
#include "constants.h"

// Draw the mini-map
void drawMinimap(SDL_Renderer* renderer) {
    int minimapScale = 10; // Scale of the mini-map
    int offsetX = 20; // Offset for mini-map from the window edge
    int offsetY = 20;

    // Draw the map grid
    for (int y = 0; y < MAP_HEIGHT; ++y) {
        for (int x = 0; x < MAP_WIDTH; ++x) {
            SDL_Rect tileRect = { offsetX + x * minimapScale, offsetY + y * minimapScale, minimapScale, minimapScale };

            if (map[y][x] == 1) {
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Wall color
            } else {
                SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255); // Empty space color
            }

            SDL_RenderFillRect(renderer, &tileRect);
        }
    }

    // Draw the player on the mini-map
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Player color
    SDL_Rect playerRect = { offsetX + (int)(playerX / TILE_SIZE) * minimapScale, offsetY + (int)(playerY / TILE_SIZE) * minimapScale, minimapScale / 2, minimapScale / 2 };
    SDL_RenderFillRect(renderer, &playerRect);

    // Draw the player's line of sight
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255); // Line of sight color
    SDL_RenderDrawLine(renderer, offsetX + playerX / TILE_SIZE * minimapScale, offsetY + playerY / TILE_SIZE * minimapScale,
                       offsetX + (playerX + cos(playerAngle * M_PI / 180) * 30) / TILE_SIZE * minimapScale,
                       offsetY + (playerY + sin(playerAngle * M_PI / 180) * 30) / TILE_SIZE * minimapScale);
}

void render(SDL_Renderer* renderer, int showMinimap) {
    SDL_SetRenderDrawColor(renderer, 135, 206, 235, 255);
    SDL_RenderClear(renderer);

    // Draw the 3D view
    for (int x = 0; x < SCREEN_WIDTH; ++x) {
        float rayAngle = (playerAngle - 30) + (x / (float)SCREEN_WIDTH) * 60;
        float rayX = playerX;
        float rayY = playerY;
        float rayDirX = cos(rayAngle * M_PI / 180);
        float rayDirY = sin(rayAngle * M_PI / 180);

        int hit = 0;
        int wallHeight = 0;
        int isVerticalHit = 0;

        while (!hit) {
            rayX += rayDirX;
            rayY += rayDirY;

            int mapX = (int)(rayX / TILE_SIZE);
            int mapY = (int)(rayY / TILE_SIZE);

            if (map[mapY][mapX] == 1) {
                hit = 1;
                float distance = sqrt(pow(rayX - playerX, 2) + pow(rayY - playerY, 2));
                wallHeight = (TILE_SIZE / distance) * 277;

                if (fabs(rayDirX) > fabs(rayDirY)) {
                    isVerticalHit = 1;
                }
            }
        }

        // Draw wall slice with orientation-based color
        if (isVerticalHit) {
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        } else {
            SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        }
        SDL_RenderDrawLine(renderer, x, (SCREEN_HEIGHT / 2) - (wallHeight / 2), x, (SCREEN_HEIGHT / 2) + (wallHeight / 2));
    }

    // Draw mini-map if enabled
    if (showMinimap) {
        drawMinimap(renderer);
    }

    SDL_RenderPresent(renderer);
}
