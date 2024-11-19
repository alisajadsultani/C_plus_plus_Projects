#include "Character.h"
#include "raymath.h"

Character::Character(int winWidth, int winHeight) : windowHeight(winHeight), windowWidth(winWidth)
{
    width = texture.width / maxFrame;
    height = texture.height;
};

Vector2 Character::getScreenPos()
{
    return Vector2
    {
        static_cast<int>(windowWidth) / 2.0f - scale * (0.5f * width),
        static_cast<int>(windowHeight) / 2.0f - scale * (0.5f * height)
    };
}
void Character::tick(float deltaTime)
{
    // Movement
    if (IsKeyDown(KEY_A))
        velocity.x -= 1.0;
    if (IsKeyDown(KEY_D))
        velocity.x += 1.0;
    if (IsKeyDown(KEY_W))
        velocity.y -= 1.0;
    if (IsKeyDown(KEY_S))
        velocity.y += 1.0;

    BaseCharacter::tick(deltaTime);

    if(!getAlive()) return;
    Vector2 origin{};
    Vector2 offset{};
    float rotation{};
    if(rightLeft > 0.f)
    {
        origin = {0.f, weapon.height * scale};
        offset = {35.f, 55.f};
        weaponCollisionRec = 
        {
            getScreenPos().x + offset.x,
            getScreenPos().y + offset.y - weapon.height * scale,
            weapon.width * scale,
            weapon.height * scale

        };
        rotation = IsMouseButtonDown(MOUSE_LEFT_BUTTON) ? 35 : 0;
    }
    else
    {
        origin = {weapon.width * scale, weapon.height * scale};
        offset = {25.f, 55.f};
        weaponCollisionRec = 
        {
            getScreenPos().x + offset.x - weapon.width * scale,
            getScreenPos().y + offset.y - weapon.height * scale,
            weapon.width * scale,
            weapon.height * scale
        };
        rotation = IsMouseButtonDown(MOUSE_LEFT_BUTTON) ? -35 : 0;

    }

    //draw the sword
    Rectangle source{0.f, 0.f, static_cast<float>(weapon.width) * rightLeft, static_cast<float>(weapon.height)};
    Rectangle dest{getScreenPos().x + offset.x, getScreenPos().y + offset.y, weapon.width * scale, weapon.height * scale};
    DrawTexturePro(weapon, source, dest, origin, rotation, WHITE);
}

void Character::takeDamage(float damage)
{
    health -= damage;
    if(health <= 0.f)
    {
        setAlive(false);
    }
}
