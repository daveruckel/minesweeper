#include "MINESWEEPER_H.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

minesweeper::minesweeper()
{
    colNum=rowNum=9;
    minesNum=10;
    displayGameBoard();
    setupGameBoard();
}



minesweeper::minesweeper(int row, int col, int numOfMines, vector<vector<int> >&mineField)
{
    rowNum = row;
    colNum = col;
    minesNum = numOfMines;
    
    setupGameBoard();
}

minesweeper::~minesweeper()
{
    
}

int minesweeper::getRowNum()
{
    return rowNum;
}

int minesweeper::getColNum()
{
    return colNum;
}

int minesweeper::getMinesNum()
{
    return minesNum;
}

void minesweeper::calculateSurrounding(int row, int col)
{    
    incrementCellValue(row, col);
}

void minesweeper::incrementCellValue(int row, int col)
{
//    int CellValue;
//    row++, col;
//    row--, col;
//    row, col++;
//    row, col--;
//    row++, col++;
//    row--, col--;
//    row++, col--;
//    row--, col++;
}

void minesweeper::setupGameBoard()
{
    
//    int x(0), y(0);
//
//    for (y=0; y<rowNum; y++)
//    {
//        for (x=0; x<colNum; x++)
//        {
//            calculateSurrounding(y, x);
//        }
//    }
}

void minesweeper::revealLocation(int x, int y)
{

}

void minesweeper::markLocation(int x, int y)
{
//    if (mineField[x][y]=1)
//    {
//        return 0;
//    }
//    else
//    {
//        mineField[x][y]>>0;
//    }
	   
}

void minesweeper::unmarkLocation(int x,int y)
{
	  
}

int minesweeper::endGame()
{
    
    displayMines();
    return cout<<"You lose.";

}

int minesweeper::valueOf(int x, int y)
{    
    return cout<<"value"; 
}

void minesweeper::unmask(int row,int col)
{

}

void minesweeper::displayGameBoard()
{
    cout<<"\t";
            
    for (int j=1; j<=colNum; j++)
    {
        cout<<j<<"\t";
    }
    cout<<endl;
    for (int h=0; h<=colNum; h++)
    {
        cout<<"========";
    }
    cout<<endl;
    for (int k=1; k<=rowNum; k++)
    {
        cout<<k<<"\t";
        for (int i=1; i<=colNum; i++)
        {
            cout<<"#\t";
        }
        cout<<endl<<endl;
    }   
}

void minesweeper::displayMines()
{
		
}
