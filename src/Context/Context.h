#ifndef __CONTEXT_H_
#define __CONTEXT_H_

#include <stdlib.h>
#include "../Entity/RoleEntity.h"
#include "../Entity/BulletEntity.h"

// 存储游戏中的所有数据
typedef struct Context {
    RoleEntity* me; // ptr
    BulletEntity* bullets; // ptr array
    int bulletCountInUse;
} Context;

inline Context* Context_Create(int maxBulletCount) {
    Context* ctx = (Context*)calloc(1, sizeof(Context));
    ctx->me = 0x00;

    ctx->bullets = (BulletEntity*)calloc(maxBulletCount, sizeof(BulletEntity));
    ctx->bulletCountInUse = 0;
    return ctx;
}

// Me
inline void Context_SetMe(Context* ctx, RoleEntity* me) {
    ctx->me = me;
}
inline RoleEntity* Context_GetMe(Context* ctx) {
    return ctx->me;
}

// Bullet
inline void Context_AddBullet(Context* ctx, BulletEntity bullet) {
    // 0, 1, 2, 3, ......
    // b, n, n, n,
    // ↑
    //    1
    ctx->bullets[ctx->bulletCountInUse] = bullet;
    ctx->bulletCountInUse += 1;
}

inline void Context_RemoveBullet(Context *ctx, BulletEntity bullet) {
    // ar: 0, 1, 2, 3, ......
    // id: 0, 3, 2, n, n, n
    //     ↑
    //        1
    for (int i = 0; i < ctx->bulletCountInUse; i += 1) {
        BulletEntity *b = &ctx->bullets[i];
        if (b->id == bullet.id) {
            // 交换
            BulletEntity temp = ctx->bullets[i];
            ctx->bullets[i] = ctx->bullets[ctx->bulletCountInUse - 1];
            ctx->bullets[ctx->bulletCountInUse - 1] = temp;

            ctx->bulletCountInUse -= 1;
            break;
        }
    }
}

#endif