#include "grid.h"
#include <iostream>
#include "colors.h"

Grid::Grid()
{
    numRows = 20;
    numCols = 10;
    cellSize = 30;
    initialize();
    colors = GetCellColors();
}

void Grid::initialize()
{
    for (int row = 0; row < numRows; row++)
    {
        for (int cols = 0; cols < numCols; cols++)
        {
            grid[row][cols] = 0;
        }
    }
}

void Grid::print()
{
    for (int row = 0; row < numRows; row++)
    {
        for (int cols = 0; cols < numCols; cols++)
        {
            std::cout << grid[row][cols] << " ";
        }
        std::cout << std::endl;
    }
}

void Grid::Draw()
{
    for(int row = 0; row < numRows; row++)
    {
        for(int cols = 0; cols < numCols; cols++)
        {
            int cellValue = grid[row][cols];
            DrawRectangle(cols * cellSize + 11, row * cellSize + 11, cellSize - 1, cellSize - 1, colors[cellValue]);
        }
    }
}

bool Grid::IsCellOutside(int row, int cols)
{
    if(row >= 0 && row < numRows && cols >= 0 && cols < numCols)
    {
        return false;
    }
    return true;
}

bool Grid::IsCellEmpty(int row, int col)
{
    if(grid[row][col] == 0)
    {
        return true;
    }
    return false;
}

int Grid::ClearFullRows()
{
    int completed = 0;
    for(int row = numRows-1; row >= 0; row--)
    {
        if(IsRowFull(row))
        {
            ClearRow(row);
            completed++;
        }
        else if(completed > 0)
        {
            MoveRowDown(row, completed);
        }
    }
    return completed;

}

bool Grid::IsRowFull(int row)
{
    for(int col = 0; col < numCols; col++)
    {
        if(grid[row][col] == 0)
        {
            return false;
        }
    }
    return true;
}

void Grid::ClearRow(int row)
{
    for(int col = 0; col < numCols; col++)
    {
        grid[row][col] = 0;
    }
}

void Grid::MoveRowDown(int row, int numRows)
{
    for(int col = 0; col < numCols; col++)
    {
        grid[row + numRows][col] = grid[row][col];
        grid[row][col] = 0;
    }
}
