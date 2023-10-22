#ifndef __BULLETENTITY_H_
#define __BULLETENTITY_H_

#include <raylib.h>
#include <raymath.h>

typedef struct BulletEntity {
    int id;
    Vector2 pos;
    Vector2 dir;
    float moveSpeed;
    float radius;
    Color color;
} BulletEntity;

inline void BulletEntity_Move(BulletEntity *bullet, float dt) {
    Vector2 dir = Vector2Normalize(bullet->dir);
    dir = Vector2Scale(dir, bullet->moveSpeed * dt); // vector2 * float
    bullet->pos = Vector2Add(bullet->pos, dir);        // vec2 + vec2
}

inline void BulletEntity_Draw(BulletEntity *bullet) {
    DrawCircleV(bullet->pos, bullet->radius, bullet->color);
}

#endif