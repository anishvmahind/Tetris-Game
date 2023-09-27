#include <raylib.h>
#include "game.h"
#include "colors.h"
#include <iostream>

double lastUpdateTime = 0;

bool EventTriggered(double interval)
{
    double currentTime = GetTime();
    if(currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main()
{
    InitWindow(500, 620, "Tetris");
    SetTargetFPS(60);

    Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);

    Game game = Game();

    while (WindowShouldClose() == false)
    {
        UpdateMusicStream(game.music);
        game.HandleInput();
        if(EventTriggered(0.3))
        {
            game.MoveBlockDown();
        }
        BeginDrawing();
        ClearBackground(darkBlue); // typically done at start of game so previous is wiped out wuth given color

        DrawTextEx(font, "Score", {365, 15}, 38, 2, WHITE);
        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, lightBlue);

        char scoreText[10];
        sprintf(scoreText, "%d", game.score);   
        Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2); // gives height and width of text in pixels
        DrawTextEx(font, scoreText, {320 + (170 - textSize.x)/2, 66}, 38, 2, WHITE);

        DrawTextEx(font, "Next", {370, 175}, 38, 2, WHITE);
        DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, lightBlue);

        if(game.gameOver)
        {
            DrawTextEx(font, "GAME OVER!", {320, 450}, 38, 2, WHITE);
            DrawTextEx(font, "Press any key", {325, 490}, 20, 2, red);
            DrawTextEx(font, "to continue..", {325, 520}, 20, 2, red);
        }
        game.Draw();
        EndDrawing();
    }
    

    CloseWindow();
    return 0;
}
/*
    while(WindowShouldClose() == false)
    {
        int keyPressed = GetKeyPressed();
        BeginDrawing();
        ClearBackground(darkBlue);
        DrawTextEx(font, "Select Difficulty", {37, 5}, 25, 2, WHITE);
        DrawTextEx(font, "Easy - press E", {75, 125}, 25, 2, WHITE);
        DrawTextEx(font, "Medium - press M", {50, 245}, 25, 2, WHITE);
        DrawTextEx(font, "Hard - press H", {75, 345}, 25, 2, WHITE);
        switch (keyPressed)
        {
        case KEY_E:
            difficulty = 0.4;
            break;
        case KEY_M:
            difficulty = 0.3;
            break;
        case KEY_H:
            difficulty = 0.2;
            break;
        default:
            break;
        }
        if(keyPressed != 0)
        {
            break;
        }
        EndDrawing();
    }
*/
