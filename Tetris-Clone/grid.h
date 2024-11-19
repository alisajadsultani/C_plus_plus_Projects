#pragma once
#include <raylib.h>
#include <vector>

class Grid
{
public:
    Grid();
    void initialize();
    void print();
    void Draw();
    int grid[20][10];
    bool IsCellOutside(int row, int cols);
    bool IsCellEmpty(int row, int col);
    int ClearFullRows();

private:
    //Making sure when the row is complete it dispears and the above rows comes down
    bool IsRowFull(int row);
    void ClearRow(int row);
    void MoveRowDown(int row, int numRows);
    int numRows;
    int numCols;
    int cellSize;
    std::vector<Color> colors;
};