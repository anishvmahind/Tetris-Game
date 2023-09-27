#pragma once
#include "grid.h"
#include "blocks.cpp"

class Game
{
public:
    Game();
    ~Game();
    void Draw();
    void HandleInput();
    void MoveBlockDown();
    bool gameOver;
    int score;
    Music music;

private:
    Block GetRandomBlock();
    vector<Block> getAllBlocks();
    void MoveBlockLeft();
    void MoveBlockRight();
    bool isBlockOutside();
    void RotateBlock();
    void LockBlock();
    bool blockFits();
    void Reset();
    void UpdateScore(int linesCleared);
    vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;
    Grid grid;
    Sound rotateSound;
    Sound clearSound;
};