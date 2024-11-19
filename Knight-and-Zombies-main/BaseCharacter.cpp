#include "BaseCharacter.h"
#include "raymath.h"

BaseCharacter::BaseCharacter(){};

Rectangle BaseCharacter::getCollisionRec()
{
    return Rectangle{
        getScreenPos().x,
        getScreenPos().y,
        width * scale,
        height * scale
    };
}

void BaseCharacter::tick(float deltaTime)
{
    worldPosLastFrame = worldPos;

    // update animation frame
    runningTime += deltaTime;
    if (runningTime >= updateTime)
    {
        runningTime = 0.0;
        frame++;
        if (frame > maxFrame)
            frame = 0.0;
    }

    if (Vector2Length(velocity) != 0.0)
    {
        // set worldPos = worldPos - direction
        worldPos = Vector2Add(worldPos, Vector2Scale(Vector2Normalize(velocity), speed));
        velocity.x < 0.f ? rightLeft = -1 : rightLeft = 1;
        texture = run;
    }
    else
    {
        texture = idle;
    }
    velocity = {};
    // Draw the chracter
    Rectangle source{frame * width, 0.f, rightLeft * width, height};
    Rectangle dest{getScreenPos().x, getScreenPos().y, scale * width, scale * height};
    DrawTexturePro(texture, source, dest, Vector2{}, 0.f, WHITE);
}

void BaseCharacter::undoMovement()
{
    worldPos = worldPosLastFrame;
}