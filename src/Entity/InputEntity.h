#ifndef __INPUT_H_
#define __INPUT_H_

#include <raylib.h>

typedef struct InputEntity {
    Vector2 moveAxis;
    bool isShoot;
} InputEntity;

void InputEntity_Process(InputEntity *input) {
    input->moveAxis.x = IsKeyDown(KEY_D) - IsKeyDown(KEY_A);
    input->moveAxis.y = IsKeyDown(KEY_S) - IsKeyDown(KEY_W);
    input->isShoot = IsMouseButtonDown(MOUSE_LEFT_BUTTON);
}

#endif