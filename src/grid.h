#pragma once
#include <vector>
#include <raylib.h>

class Grid{
public:
    Grid();
    void Initialize();
    void Print();
    void Draw();
    bool isCellOut(int row, int col);
    bool isCellEmpty(int row, int col);
    int ClearFullRows();
    int grid[20][10];

private:
    bool IsRowFull(int row);
    void ClearRow(int row);
    void MoveRowDown(int row, int num);
    int numRows;
    int numCols;
    int cellSize;
    std::vector<Color> colors;
};