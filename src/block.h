#pragma once
#include "position.h"
#include <vector>
#include <map>
#include "colors.h"
using namespace std;

class Block
{
public:
    Block();
    void Draw(int offsetX, int offsetY);
    void Move(int rows, int cols);
    std::vector<Position> GetCellPositions();
    void Rotate();
    void UndoRotate();
    int id;
    map<int, vector<Position>> cells;
private:
    int cellSize;
    int rotationState;
    vector<Color> colors;
    int rowOffset;
    int colOffset;

};