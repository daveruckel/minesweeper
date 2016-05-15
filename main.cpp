#include "MINESWEEPER_H.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>


using namespace std;

struct input_t{
	char operation;			// 'm'= mark,'u' = unmark, 'r' = reveal 
	int  row;
	int  column;
};


void playTime(minesweeper& play);
void viewStatistics();
void loadGameFromFile();
input_t loadGameFromProgram();
input_t getUserInput( );
void processInput(minesweeper& play, input_t input);

vector<vector<int> > mineField;
int rows=0;
int columns=0;
int mines=0;

minesweeper m(rows, columns, mines, mineField);

int main()
{

	 
     int option, file_or_program;

     while (1)
     {
         cout<<"Enter 1 to start game:\n"
               "Enter 2 to view the statistics:\n"
               "Enter 3 to quit the game: "<<endl;
         cin>>option;
         switch(option)
         {
             case 1:
                 cout<<"Enter 1 to play from a program:\n"
                       "Enter 2 to play from a file:"<<endl;
                 cin>>file_or_program;
                 switch(file_or_program)
                 {
                     case 1:
                         loadGameFromProgram();
                         break;
                     case 2:
                         loadGameFromFile();
                         break;
                     default:
                         cout<<"error";
                         return 0;
                 }
                      break;
             case 2:
                     viewStatistics();
                       break;
             case 3: 
                  exit(EXIT_SUCCESS );
                 break;
             default:
                 cout<<"That was not a valid input. Please try again: "<<endl;
                 break;
         }
  }
    return 0;
}

void loadGameFromFile(){
    int row, col, numOfMines;
    vector <vector<int> > minefield;
    
    ifstream fin("minesweeper.txt");
    if (fin.fail())
    {
        cerr<<"Failed to open input file minesweeper.txt."<<endl;
        exit(1);
    }
        
    fin.seekg(14);
    fin>>row;
    fin.seekg(32);
    fin>>col;
    fin.seekg(49);
    fin>>numOfMines;
        
    fin.close();
    minesweeper m(row, col, numOfMines, minefield);
    getUserInput();
    m.displayGameBoard();
}

input_t loadGameFromProgram()
{
    input_t load;
    int mines;
    vector <vector<int> > minefield;
    cout<<"Generate a minefield \nHow many columns?"<<endl;
    cin>>load.column;
    cout<<"How many rows?"<<endl;
    cin>>load.row;
    cout<<"How many mines should be hidden?"<<endl;
    cin>>mines;
    minesweeper m(load.row, load.column, mines, minefield);
    getUserInput();
    //m.displayGameBoard();
}

void playTime(minesweeper& play)
{
	cout<<" The game is Setup!! Let us Play "<<endl;
        m.displayGameBoard();
}

input_t getUserInput()
{
    input_t move;
    cout<<"Make your move"<<endl;
    cout<<"'m'= mark,'u' = unmark, 'r' = reveal"<<endl;
    cout<<" Then enter a row and a column."<<endl;
    cin>>move.operation;
    cin>>move.row;
    cin>>move.column;
    processInput(m, move);
}

void processInput(minesweeper& play, input_t input)
{
    switch(input.operation)
    {
            case 'm':
                m.markLocation(input.column, input.row);
                ///markLocation(input.column, input.row);
                break;
                
            case 'u':
                m.unmarkLocation(input.column, input.row);
                break;
                
            case 'r':
                m.revealLocation(input.column, input.row);
                break;		
        default:
            cout<<"error";
            break;
    }

    playTime(play);
    //m.displayGameBoard();
}

void viewStatistics()
{
    
}