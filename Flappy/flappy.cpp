#include "raylib.h"
#include "raymath.h"
#include <iostream>
#include <string>
#include <vector>

class Data
{
public:
    std::vector<Texture2D> listFrame;
    Rectangle rec;
    Vector2 pos;
    float runningTime = 0.0f;
    float updateTime = 1.f / 10.f;
    int frame = 0;
    int currentFrame = 0;
};

bool isOnGround(int windowHeight, const Data &anim)
{
    return anim.pos.y >= windowHeight - anim.rec.height * 0.1f;
}

bool topCheck(int windowHeight, const Data &anim)
{
    return anim.pos.y >= 0;
}

void drawBackground(float deltaTime, const Texture2D &backgroundDay, const Texture2D &backgroundNight, const Texture2D &ground, bool &changeBackground, float &timer, float switchTime)
{
    static float dayBackgroundX = 0.0f;
    static float nightBackgroundX = 0.0f;
    static float groundX = 0.0f;
    float scale = 1.35f;

    timer += deltaTime;
    if (timer >= switchTime)
    {
        changeBackground = !changeBackground;
        timer = 0.0f;
    }

    if (changeBackground)
    {
        dayBackgroundX -= 85.0f * deltaTime;
        if (dayBackgroundX <= -backgroundDay.width * scale)
        {
            dayBackgroundX = 0.0f;
        }
        Vector2 dayPos1{dayBackgroundX, 0.0f};
        Vector2 dayPos2{dayBackgroundX + backgroundDay.width * scale, 0.0f};
        DrawTextureEx(backgroundDay, dayPos1, 0.0f, scale, WHITE);
        DrawTextureEx(backgroundDay, dayPos2, 0.0f, scale, WHITE);
    }
    else
    {
        nightBackgroundX -= 85.0f * deltaTime;
        if (nightBackgroundX <= -backgroundNight.width * scale)
        {
            nightBackgroundX = 0.0f;
        }
        Vector2 nightPos1{nightBackgroundX, 0.0f};
        Vector2 nightPos2{nightBackgroundX + backgroundNight.width * scale, 0.0f};
        DrawTextureEx(backgroundNight, nightPos1, 0.0f, scale, WHITE);
        DrawTextureEx(backgroundNight, nightPos2, 0.0f, scale, WHITE);
    }

    groundX -= 85.0f * deltaTime;
    if (groundX <= -ground.width * 1.1f)
    {
        groundX = 0.0f;
    }
    Vector2 groundPos1{groundX, 595.f};
    Vector2 groundPos2{groundX + ground.width * 1.1f, 595.f};
    DrawTextureEx(ground, groundPos1, 0.0f, 1.1f, WHITE);
    DrawTextureEx(ground, groundPos2, 0.0f, 1.1f, WHITE);
}

Data updateFrame(Data bird, float dT, int maxFrame)
{
    bird.runningTime += dT;
    while (bird.runningTime >= bird.updateTime)
    {
        bird.runningTime = 0.0;
        bird.currentFrame++;
        if (bird.currentFrame > maxFrame)
        {
            bird.currentFrame = 0;
        };
    };
    return bird;
}

void drawScore(int score)
{
    DrawText(std::to_string(score).c_str(), 20, 20, 40, RED);
}

void handleCollision(Data &birdData, Data pipeData[], Data pipeDataTwo[], Data coins[], int pipesTotal, int &score, bool &gameOver, float velocity)
{
    Rectangle birdRect = {
        birdData.pos.x + 19,
        birdData.pos.y,
        birdData.rec.width * 0.1f + 70,
        birdData.rec.height * 0.1f + 64};
    // Check collision with pipes
    for (int i = 0; i < pipesTotal; i++)
    {
        Rectangle pipeUpRect = {pipeDataTwo[i].pos.x, pipeDataTwo[i].pos.y, pipeDataTwo[i].rec.width, pipeDataTwo[i].rec.height};
        Rectangle pipeDownRect = {pipeData[i].pos.x, pipeData[i].pos.y, pipeData[i].rec.width, pipeData[i].rec.height * -1};

        if (CheckCollisionRecs(pipeUpRect, birdRect) || CheckCollisionRecs(pipeDownRect, birdRect))
        {
            gameOver = true;
        }
    }

    for (int i = 0; i < pipesTotal; i++)
    {
        Rectangle coinRect = {coins[i].pos.x, coins[i].pos.y, coins[i].rec.width, coins[i].rec.height};
        if (CheckCollisionRecs(coinRect, birdRect))
        {
            score++;
            coins[i].pos.y += 1000;
        }
    }
}

void updatePipes(Data pipeData[], Data pipeDataTwo[], int pipesTotal, float deltaTime, Texture2D pipeUpTexture, Texture2D pipeDownTexture, Texture2D coin, Data coins[])
{
    for (int i = 0; i < pipesTotal; ++i)
    {
        pipeData[i].pos.x -= 70.0f * deltaTime;
        pipeDataTwo[i].pos.x -= 70.0f * deltaTime;
        coins[i].pos.x -= 70.f * deltaTime;

        DrawTextureRec(pipeDownTexture, pipeData[i].rec, pipeData[i].pos, WHITE);
        DrawTextureRec(pipeUpTexture, pipeDataTwo[i].rec, pipeDataTwo[i].pos, WHITE);
        DrawTextureRec(coin, coins[i].rec, coins[i].pos, WHITE);
    }
}

void resetGame(Data &birdData, Data pipeData[], Data pipeDataTwo[], int pipesTotal, int windowWidth)
{
    birdData.pos = {185, 320}; // Reset bird position
    for (int i = 0; i < pipesTotal; ++i)
    {
        pipeData[i].pos.x = windowWidth + i * 350.0f;
        pipeDataTwo[i].pos.x = windowWidth + i * 350.0f;
    }
}

int main()
{
    const int windowHeight = 640;
    const int windowWidth = 460;
    InitWindow(windowWidth, windowHeight, "Flappy Bird");

    Image icon = LoadImage("pictures/Flappy_Bird_icon.png");
    SetWindowIcon(icon);

    Texture2D tapDirLeft = LoadTexture("pictures/tap_dir_left.png");
    Data tapLeft = {{}, {0, 0, static_cast<float>(tapDirLeft.width), static_cast<float>(tapDirLeft.height)}, {260, 420}};

    Texture2D tapDirRight = LoadTexture("pictures/tap_dir_right.png");
    Data tapRight = {{}, {0, 0, static_cast<float>(tapDirRight.width), static_cast<float>(tapDirRight.height)}, {135, 420}};

    Texture2D gameOverTex = LoadTexture("pictures/gameover.png");
    Data gameOverData = {{}, {0, 0, static_cast<float>(gameOverTex.width), static_cast<float>(gameOverTex.height)}, {120, 280}};

    Texture2D getReadyTex = LoadTexture("pictures/getready.png");
    Data getReadyData = {{}, {0, 0, static_cast<float>(getReadyTex.width), static_cast<float>(getReadyTex.height)}, {120, 465}};

    Texture2D ground = LoadTexture("pictures/ground.png");

    Data birdData;
    std::vector<std::string> birdFrames = {
        "characters/frame-1.png", "characters/frame-2.png", "characters/frame-3.png",
        "characters/frame-4.png", "characters/frame-5.png", "characters/frame-6.png",
        "characters/frame-7.png", "characters/frame-8.png"};
    for (const auto &frame : birdFrames)
    {
        birdData.listFrame.push_back(LoadTexture(frame.c_str()));
    }
    int numFrames = birdData.listFrame.size();
    birdData.pos = {185, windowHeight / 2.0f};

    float jumpValue = -270.0f;
    float velocity = 0.0f;
    int gravity = 500;
    float scale = 3.f;
    int score = 0;
    int highestScore = 0;

    // Loading and resizing images of coins and pipes
    Image imageUp = LoadImage("pictures/pipe.png");
    int newWidth = static_cast<int>(imageUp.width * scale);
    int newHeight = static_cast<int>(imageUp.height * scale);

    ImageResize(&imageUp, newWidth, newHeight);
    Texture2D pipeUpTexture = LoadTextureFromImage(imageUp);
    Texture2D pipeDownTexture = LoadTextureFromImage(imageUp);

    Image imageCoin = LoadImage("pictures/coin.png");
    int newWidthCoin = static_cast<int>(imageCoin.width * 1.2);
    int newHeightCoin = static_cast<int>(imageCoin.height * 1.2);

    ImageResize(&imageCoin, newWidthCoin, newHeightCoin);
    Texture coin = LoadTextureFromImage(imageCoin);

    const int pipesTotal = 100;
    Data coins[pipesTotal];
    Data pipeData[pipesTotal];
    Data pipeDataTwo[pipesTotal];

    for (int i = 0; i < pipesTotal; ++i)
    {
        pipeData[i] = {{}, {0, 0, static_cast<float>(pipeDownTexture.width), static_cast<float>(pipeDownTexture.height * -1)}, {windowWidth + i * 350.0f, static_cast<float>(GetRandomValue(-120.0f, -80.0f))}};
        pipeDataTwo[i] = {{}, {0, 0, static_cast<float>(pipeUpTexture.width), static_cast<float>(pipeUpTexture.height)}, {windowWidth + i * 350.0f, static_cast<float>(GetRandomValue(360.0f, 500.0f))}};
        coins[i] = {{}, {0, 0, static_cast<float>(coin.width), static_cast<float>(coin.height)}, {windowWidth + i * 400.0f, static_cast<float>(GetRandomValue(140.0f, 360.0f))}};
    }

    Texture2D backgroundNight = LoadTexture("pictures/background_night.png");
    Texture2D backgroundDay = LoadTexture("pictures/background_day.png");

    SetTargetFPS(60);
    bool start = false;
    bool changeBackground = true;
    bool gameOver = false;
    float switchTime = 20.0f;
    float timer = 0.0f;

    while (!WindowShouldClose())
    {
        float deltaTime = GetFrameTime();

        BeginDrawing();
        ClearBackground(WHITE);

        if (isOnGround(windowHeight, birdData))
        {
            birdData.pos.y = windowHeight - birdData.rec.height * 0.1f;
            velocity = 0.0f;
            gameOver = true;
        }

        gravity = topCheck(windowHeight, birdData) ? 500 : 1000;

        if (gameOver)
        {
            drawBackground(deltaTime, backgroundDay, backgroundNight, ground, changeBackground, timer, switchTime);
            if(score > highestScore)
            {
                highestScore = score;
            }
            std::string scoreTracker = "Highest Score: ";
            scoreTracker.append(std::to_string(highestScore), 0, 5);
            DrawText(scoreTracker.c_str(), 140, 240, 30.f, RED);
            DrawTextureEx(gameOverTex, gameOverData.pos, 0.0, 1.f, WHITE);
            DrawText("PRESS ENTER", 80, 335, 40.f, RED);
        }
        else
        {
            drawBackground(deltaTime, backgroundDay, backgroundNight, ground, changeBackground, timer, switchTime);

            birdData = updateFrame(birdData, deltaTime, numFrames - 1);

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsKeyPressed(KEY_SPACE))
            {
                start = true;
            }

            if (!start)
            {
                DrawTextureEx(tapDirLeft, tapLeft.pos, 0.0, 1.5f, WHITE);
                DrawTextureEx(tapDirRight, tapRight.pos, 0.0, 1.5f, WHITE);
                DrawTextureEx(getReadyTex, getReadyData.pos, 0.0, 1.f, WHITE);
            }

            if (start)
            {
                velocity += gravity * deltaTime;
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsKeyPressed(KEY_SPACE))
                {
                    velocity = jumpValue;
                }
                birdData.pos.y += velocity * deltaTime;

                updatePipes(pipeData, pipeDataTwo, pipesTotal, deltaTime, pipeUpTexture, pipeDownTexture, coin, coins);
            }

            DrawTextureEx(birdData.listFrame[birdData.currentFrame], birdData.pos, 0.0f, 0.1f, WHITE);
            drawScore(score);
            handleCollision(birdData, pipeData, pipeDataTwo, coins, pipesTotal, score, gameOver, velocity);
        }

        if (IsKeyPressed(KEY_ENTER) && gameOver)
        {
            gameOver = false;
            start = false;
            score = 0;
            resetGame(birdData, pipeData, pipeDataTwo, pipesTotal, windowWidth);
        }

        EndDrawing();
    }

    UnloadTexture(pipeUpTexture);
    UnloadTexture(pipeDownTexture);
    UnloadTexture(backgroundNight);
    UnloadTexture(backgroundDay);
    UnloadTexture(tapDirLeft);
    UnloadTexture(tapDirRight);
    UnloadTexture(gameOverTex);
    UnloadTexture(getReadyTex);
    for (const auto &frame : birdData.listFrame)
    {
        UnloadTexture(frame);
    }
    UnloadImage(imageUp);
    UnloadImage(icon);
    CloseWindow();

    return 0;
}