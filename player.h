#ifndef PLAYER_H
#define PLAYER_H

#define MOVE_SPEED 5.0f
#define ROTATE_SPEED 5.0f

extern float playerX;
extern float playerY;
extern float playerAngle;

void movePlayer(const Uint8* keyState);

#endif
