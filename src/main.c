#include <raylib.h>
#include <raymath.h>
#include "Entity/RoleEntity.h"
#include "Entity/InputEntity.h"
#include "Factory/Factory.h"
#include "Context/Context.h"

int main() {

    int screenWidth = 800;
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "cw");

    // 创建存储
    Context* ctx = Context_Create(10000);

    // Input
    InputEntity input = (InputEntity){0};

    // 创建 me
    Factory_CreateRole(ctx, Vector2Zero(), 50, 10, RED);

    while (!WindowShouldClose()) {

        float dt = GetFrameTime();

        // 获取输入
        // Input: Move / Shoot
        InputEntity_Process(&input);

        // Role: Move
        RoleEntity *me = Context_GetMe(ctx);
        RoleEntity_Move(me, input.moveAxis, dt);

        // Role: Shoot
        if (input.isShoot) {
            Factory_CreateBullet(ctx, me->pos, (Vector2){0, -1}, 500, 5, BLUE);
        }

        // 遍历子弹
        // Bullet: Logic
        for (int i = 0; i < ctx->bulletCountInUse; i += 1) {
            BulletEntity* bullet = &ctx->bullets[i];
            BulletEntity_Move(bullet, dt);
        }

        BeginDrawing();

        ClearBackground(BLACK);

        // Bullet: Draw
        for (int i = 0; i < ctx->bulletCountInUse; i += 1) {
            BulletEntity* bullet = &ctx->bullets[i];
            BulletEntity_Draw(bullet);
        }

        // Role: Draw
        RoleEntity_Draw(me);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}