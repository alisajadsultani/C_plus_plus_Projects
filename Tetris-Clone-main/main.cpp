#include <raylib.h>
#include "game.h"
#include "colors.h"
#include <iostream>

double lastUpdateTime = 0;

bool EventTriggerd(double integral)
{
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= integral)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}
int main()
{
    const int screenWidth = 500;
    const int screenHeight = 620;

    InitWindow(screenWidth, screenHeight, "Tetris");
    if (!IsWindowReady())
    {
        std::cerr << "Failed to initialize the window!" << std::endl;
        return -1;
    }

    Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);
    if (font.baseSize == 0)
    {
        std::cerr << "Failed to load font!" << std::endl;
        CloseWindow();
        return -1;
    }
    Game game = Game();

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        UpdateMusicStream(game.music);
        game.HandleInput();
        if (EventTriggerd(0.2))
        {
            game.MoveBlockDown();
        }
        BeginDrawing();
        ClearBackground(darkBlue);
        DrawTextEx(font, "Score", {355, 15}, 38, 2, WHITE);
        DrawTextEx(font, "Next", {365, 175}, 38, 2, WHITE);
        if (game.gameOver)
        {
            DrawTextEx(font, "GAME OVER", {315, 450}, 30.5, 2, WHITE);
        }
        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, lightBlue);

        char scoreText[10];
        sprintf(scoreText, "%d", game.score);
        Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);

        DrawTextEx(font, scoreText, {300 + (170 - textSize.x) / 2, 65}, 38, 2, WHITE);
        DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, lightBlue);
        game.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}