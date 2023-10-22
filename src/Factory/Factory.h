#ifndef __FACTORY_H_
#define __FACTORY_H_

#include <stdlib.h>
#include "../Context/Context.h"
#include "../Entity/BulletEntity.h"
#include "../Entity/RoleEntity.h"

static int bulletIDRecord = 0;

inline RoleEntity* Factory_CreateRole(Context* ctx, Vector2 pos, float moveSpeed, float radius, Color color) {
    // calloc 把数据开在堆内存上
    // 堆内存持久存储
    RoleEntity* role = (RoleEntity*)calloc(1, sizeof(RoleEntity));
    role->pos = pos;
    role->moveSpeed = moveSpeed;
    role->radius = radius;
    role->color = color;

    Context_SetMe(ctx, role);
    return role;
}

inline BulletEntity Factory_CreateBullet(Context* ctx, Vector2 pos, Vector2 dir, float moveSpeed, float radius,
                                         Color color) {
    // 数据开在栈内存 0x99
    BulletEntity bullet;
    bullet.id = bulletIDRecord;
    bullet.pos = pos;
    bullet.dir = dir;
    bullet.moveSpeed = moveSpeed;
    bullet.radius = radius;
    bullet.color = color;

    bulletIDRecord += 1;

    Context_AddBullet(ctx, bullet);
    return bullet;
}

#endif