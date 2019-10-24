#include<iostream>
#include "ascii_art.h"
using namespace std;

//Board Array
int board[8][8]=
{
{ 12, 13, 14, 16, 15, 14, 13, 12 },
{ 11,11,11, 11,11, 11, 11, 11 },
{ 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 1, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0 },
{ 1, 1, 1, 1, 1, 1, 1, 1 },
{ 2, 3, 4, 5, 6, 4, 3, 2 }
};
//Main Function
int main()
{
	//Title Screen
	title();
	system("pause");	//Wait for user input
	system("CLS");	//Clear Console
	//----------------------------------------------------------------------------------------------------------------------------------------------------------------
	//Game
	for (int elementx=0; elementx <= 7; elementx++)
	{
		cout << elementx<< "	"<<"|";
		for (int elementy=0; elementy <= 7; elementy++)
		{
			cout << pieces(board[elementx][elementy])<< "	";
		}
		cout << "\n"<<"\n";
	}
	//Bottom Row
	cout << "       -----------------------------------------------------------"<<"\n"<<"	0	" << "1	" << "2	" << "3	" << "4	" << "5	" << "6	" << "7	"<<"\n";
	//----------------------------------------------------------------------------------------------------------------------------------------------------------------












	//System Pause
	system("pause");
	//Return
	return 0;
}

//Movement
/*int move()
{

}*/