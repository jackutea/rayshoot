#ifndef __ROLEENTITY_H_
#define __ROLEENTITY_H_

#include <raylib.h>
#include <raymath.h>

struct RoleEntity {
    Vector2 pos;
    float moveSpeed;
    float radius;
    Color color;
};
typedef struct RoleEntity RoleEntity;

inline void RoleEntity_Move(RoleEntity *role, Vector2 moveAxis, float dt) {
    Vector2 dir = Vector2Normalize(moveAxis);
    dir = Vector2Scale(dir, role->moveSpeed * dt); // vector2 * float
    role->pos = Vector2Add(role->pos, dir);        // vec2 + vec2
}

inline void RoleEntity_Draw(RoleEntity *role) {
    DrawCircleV(role->pos, role->radius, role->color);
}

#endif