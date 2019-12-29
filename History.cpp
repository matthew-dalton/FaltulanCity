#include "History.h"
#include "City.h"
#include <iostream>

History::History(int nRows, int nCols)
: m_rows(nRows), m_cols(nCols), m_numspots(0)
{
    // we can assume that nRows and nCols are both valid, so there is no need to do anything inside the constructor
}

bool History::record(int r, int c)
{
    // we cannot assume that r and c are valid and so we must make sure
    if(r < 1 || r > m_rows || c < 1 || c > m_cols)
        return false;
    
    m_rowspot[m_numspots] = r;
    m_colspot[m_numspots] = c;
    m_numspots++;
    
    return true;
}

void History::display() const
{
    // Position (row,col) in the city coordinate system is represented in
    // the array element grid[row-1][col-1]
    char grid[MAXROWS][MAXCOLS];
    int r, c;
    
    // Fill the grid with dots
    for (r = 0; r < m_rows; r++)
        for (c = 0; c < m_cols; c++)
            grid[r][c] = '.';
    
    // Indicate each unconverted Flatulan's position
    for (int k = 0; k < m_numspots; k++)
    {
        char& gridChar = grid[m_rowspot[k]-1][m_colspot[k]-1];
        switch (gridChar)
        {
            case '.':  gridChar = 'A'; break;
            case 'Z':  break;
            default:   gridChar++; break;  // 'A' through 'Y'
        }
    }
    
    // Draw the grid
    clearScreen();
    for (r = 0; r < m_rows; r++)
    {
        for (c = 0; c < m_cols; c++)
            std::cout << grid[r][c];
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
