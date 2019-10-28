#include <iostream>
#include "pieces.h"
#include "board.h"
#include <sstream>
#include <ctype.h>
#include <cmath>
#include <Windows.h>

using namespace std;

void chessStart();
bool legalMove(string);
bool legalMoveRule(string, board[8][8], int);
void gameWindow(board[8][8]);
int main() {
	chessStart();
}

void chessStart() {
	board location[8][8]; //this is declaring the chess board as an array of "board"
	
	//player 1/white's pieces
	pieces k10("King", 1); //the first number of the x##'s is which player the piece belongs to, 1 for player 1 or white and 2 for player 2 or black.
	pieces q10("Queen", 1); //the second number in the x##'s or the number after the player number is the pieces unique code. this is needed due to there being more than one of each piece per player
	pieces r10("Rook", 1); //the string part of each piece is necessary so the program knows what piece is what
	pieces r11("Rook", 1);
	pieces b10("Bishop", 1);
	pieces b11("Bishop", 1);
	pieces n10("Knight", 1); // we are going to be using n for knight because it is easier to type n rather than kn, also we wont be using the name when making the piece move
	pieces n11("Knight", 1);
	pieces p10("Pawn", 1);
	pieces p11("Pawn", 1);
	pieces p12("Pawn", 1);
	pieces p13("Pawn", 1);
	pieces p14("Pawn", 1);
	pieces p15("Pawn", 1);
	pieces p16("Pawn", 1);
	pieces p17("Pawn", 1);
	
	//black/player 2's pieces
	pieces k20("King", 2);
	pieces q20("Queen", 2);
	pieces r20("Rook", 2);
	pieces r21("Rook", 2);
	pieces b20("Bishop", 2);
	pieces b21("Bishop", 2);
	pieces n20("Knight", 2);
	pieces n21("Knight", 2);
	pieces p20("Pawn", 2);
	pieces p21("Pawn", 2);
	pieces p22("Pawn", 2);
	pieces p23("Pawn", 2);
	pieces p24("Pawn", 2);
	pieces p25("Pawn", 2);
	pieces p26("Pawn", 2);
	pieces p27("Pawn", 2);

	//this puts the pieces onto the board for white/player 1
	location[0][0].piece = &r10;
	location[0][1].piece = &n10;
	location[0][2].piece = &b10;
	location[0][3].piece = &q10;
	location[0][4].piece = &k10;
	location[0][5].piece = &b11;
	location[0][6].piece = &n11;
	location[0][7].piece = &r11;
	location[1][0].piece = &p10;
	location[1][1].piece = &p11;
	location[1][2].piece = &p12;
	location[1][3].piece = &p13;
	location[1][4].piece = &p14;
	location[1][5].piece = &p15;
	location[1][6].piece = &p16;
	location[1][7].piece = &p17;

	//this places the pieces onto the board for player 2/black
	location[7][0].piece = &r20;
	location[7][1].piece = &n20;
	location[7][2].piece = &b20;
	location[7][3].piece = &q20;
	location[7][4].piece = &k20;
	location[7][5].piece = &b21;
	location[7][6].piece = &n21;
	location[7][7].piece = &r21;
	location[6][0].piece = &p20;
	location[6][1].piece = &p21;
	location[6][2].piece = &p22;
	location[6][3].piece = &p23;
	location[6][4].piece = &p24;
	location[6][5].piece = &p25;
	location[6][6].piece = &p26;
	location[6][7].piece = &p27;

	int playerTurn = 2; //atarts at 2 in order to make the switch start it on player 1's turn
	int p1Pieces = 16; //player 1 pieces and player 2 pieces are going to be used for one of the conditions to make the game end, that being are all of one players pieces are gone
	int p2Pieces = 16;
	string move; //move to be parsed

	//main game
	while (true) {
		//The if else statment is a switch for every move, when playerTurn = 1, after the move is made it switches to playerTurn = 2
		if (playerTurn == 1)
			playerTurn = 2;
		else
			playerTurn = 1;
		system("cls");
		gameWindow(location);
		cout << "P" << playerTurn << " enter your move: ";
		getline(cin, move);
		//the while loops check if the move is legal and possible
		while (legalMove(move) == false) {
			cout << "That is not a move. Please re-enter a legal move: " << endl;
			getline(cin, move);
		}
		while (legalMoveRule(move, location, playerTurn) == false) {
			cout << "That is not a move. Please re-enter a legal move: " << endl;
			getline(cin, move);
		}
	}
}

//this checks to see if the move is correct based on the formatting
bool legalMove(string move) {
	//this checks to see if your move contains the 8 characters required to declare a move
	if (move.length() != 8) {
		return false;
	}
	
	//the following if statements make sure that the input for the moves is correct
	//this checks to see if the user has entered a valid range of inputs
	if (move[0] != 'a' && move[0] != 'b' && move[0] != 'c' && move[0] != 'd' && move[0] != 'e' && move[0] != 'f' && move[0] != 'g' && move[0] != 'h') {
		return false;
	}

	//this makes sure the number of the board index is vaild
	if (move[1] != '0' && move[1] != '1' && move[1] != '2' && move[1] != '3' && move[1] != '4' && move[1] != '5' && move[1] != '6' && move[1] != '7') {
		return false;
	}

	//this part is mildly unecessary but its still nice to help prevent game breaking
	if (move[3] != 'l' || move[4] != 'o') {
		return false;
	}

	//this is the valid range of inputs for the letter location index
	if (move[6] != 'a' && move[6] != 'b' && move[6] != 'c' && move[6] != 'd' && move[6] != 'e' && move[6] != 'f' && move[6] != 'g' && move[6] != 'h') {
		return false;
	}

	//this is the valid range of inputs for the number location index
	if (move[7] != '0' && move[7] != '1' && move[7] != '2' && move[7] != '3' && move[7] != '4' && move[7] != '5' && move[7] != '6' && move[7] != '7') {
		return false;
	}

	else return true;
}

bool legalMoveRule(string move, board location[8][8], int playerTurn) {
	stringstream stream;
	int l1;
	int n1;

	stream << move[1];
	stream >> n1;
	stream.clear(); //clears the stream
	
	int l2;
	int n2;
	
	stream << move[7];
	stream >> n2;

	//these statements convert the letter into a number so it can be used as an index
	if (move[0] == 'a')
		l1 = 0;
	else if (move[0] == 'b')
		l1 = 1;
	else if (move[0] == 'c')
		l1 = 2;
	else if (move[0] == 'd')
		l1 = 3;
	else if (move[0] == 'e')
		l1 = 4;
	else if (move[0] == 'f')
		l1 = 5;
	else if (move[0] == 'g')
		l1 = 6;
	else
		l1 = 7;

	if (move[6] == 'a')
		l2 = 0;
	else if (move[6] == 'b')
		l2 = 1;
	else if (move[6] == 'c')
		l2 = 2;
	else if (move[6] == 'd')
		l2 = 3;
	else if (move[6] == 'e')
		l2 = 4;
	else if (move[6] == 'f')
		l2 = 5;
	else if (move[6] == 'g')
		l2 = 6;
	else
		l2 = 7;

	if (location[n1][l1].piece == nullptr) {
		cout << "There is no piece at this location" << endl << endl;
		return false;
	}

	//checks to see if the piece you are trying to move is actually yours
	if (location[n1][l1].piece != nullptr && playerTurn == location[n1][l1].piece->player) {
		cout << "That is not your piece" << endl << endl;
		return false;
	}
	
	//checks to see if you have a piece at that location
	if (location[n2][l2].piece != nullptr && playerTurn == location[n2][l2].piece->player) {
		cout << "You already have a piece there" << endl << endl;
		return false;
	}

	//x and y differences
	int rowDiff = n1 - n2;
	int colDiff = l1 - l2;

	//rules for player 1's pawn
	if (location[n1][l1].piece->naam.compare("Pawn") == 0 && playerTurn == 1) {

		//this is for pawns moving 2 moves on the first turn
		if (n1 != 1 && rowDiff <= -2) {
			cout << "Not a legal pawn move" << endl << endl;
			return false;
		}

		//this is to stop people moving the pawns more than 2 spaces on the first move
		else if (n1 == 1 && rowDiff < -2) {
			cout << "Pawns can only move 2 spaces on their first move" << endl << endl;
			return false;
		}

		//rawDiff must me negative to keep pawns moving legally
		else if (rowDiff >= 0) {
			cout << "Not a legal pawn move" << endl << endl;
			return false;
		}

		//pawns can only move one space at a time
		else if (abs(colDiff) > 1) {

			cout << "Not a legal pawn move" << endl << endl;
			return false;

		}

		//if you try to move diagonally without taking
		else if (abs(colDiff) == 1 && rowDiff == -1 && location[n2][l2].piece == nullptr) {
			cout << "There needs to be an enemy piece " << l2 << n2 << " to move there" << endl << endl;
			return false;
		}

		//if you try to move forward into an enemy
		else if (rowDiff == -1 && colDiff == 0 && location[n2][l2].piece != nullptr && location[n2][l2].piece->player == 2) {
			cout << "There is a enemy in your way" << endl << endl;
			return false;
		}

		//if they move diagonally into an enemy piece
		else if (rowDiff == -1 && abs(colDiff) == 1 && location[n2][l2].piece->player == 2) {
			cout << "You have taken the opponent's " << location[n2][l2].piece->naam << " nice" << endl << endl;
			location[n2][l2].piece = location[n1][l1].piece;
			location[n1][l1].piece = nullptr;
			Sleep(2000);
			return true;
		}

		//legal move forward
		else {
			cout << "Move successful!" << endl << endl;
			location[n2][l2].piece = location[n1][l1].piece;
			location[n1][l1].piece = nullptr;
			Sleep(2000);
			return true;
		}
	}
	else if (location[n1][l1].piece->naam.compare("Pawn") == 0 && playerTurn == 2) {

		if (n1 != 6 && rowDiff >= 2) {
			cout << "Not a legal pawn move" << endl << endl;
			return false;	
		}

		else if (n1 == 6 && rowDiff > 2) {
			cout << "Pawns can move 2 spaces on their first move" << endl << endl;
			return false;
		}

		else if (rowDiff <= 0) {
			cout << "Not a legal pawn move" << endl << endl;
			return false;
		}

		else if (abs(colDiff) > 1) {
			cout << "Not a legal pawn move" << endl << endl;
			return false;
		}

		else if (abs(colDiff) == 1 && rowDiff == 1 && location[n2][l2].piece == nullptr) {
			cout << "There needs to be an enemy piece  " << l2 << n2 << " to move there" << endl << endl;
			return false;
		}

		else if (rowDiff == 1 && colDiff == 0 && location[n2][l2].piece != nullptr && location[n2][l2].piece->player == 1) {
			cout << "An enemy piece is in the way" << endl << endl;
			return false;
		}

		else if (rowDiff == 1 && abs(colDiff) == 1 && location[n2][l2].piece->player == 1) {
			cout << "You have taken the opponents's " << location[n2][l2].piece->naam << " nice" << endl << endl;
			location[n2][l2].piece = location[n1][l1].piece;
			location[n1][l1].piece = nullptr;
			Sleep(2000);
			return true;
		}

		else {
			cout << "Move successful" << endl << endl;
			location[n2][l2].piece = location[n1][l1].piece;
			location[n1][l1].piece = nullptr;
			Sleep(2000);
			return true;
		}
	}
	else if (location[n1][l1].piece->naam.compare("King") == 0) {
		if (abs(rowDiff) > 1 || abs(colDiff) > 1) {
			cout << "Not a legal king move" << endl << endl;
			return false;
		}

		if (location [n2] [l2] .piece != nullptr && location[n2][l2].piece->player != playerTurn) {
			cout << "You have taken the opponents's " << location[n2][l2].piece->naam << " nice" << endl << endl;
			location[n2][l2].piece = location[n1][l1].piece;
			location[n1][l1].piece = nullptr;
			Sleep(2000);
			return true;
		}

		else {
			cout << "Move successful" << endl << endl;
			location[n2][l2].piece = location[n1][l1].piece;
			location[n1][l1].piece = nullptr;
			Sleep(2000);
			return true;
		}
	}
	else if (location[n1][l1].piece->naam.compare("Queen") == 0) {
		//if they try to move to a random location
		if (abs(rowDiff) != abs(colDiff) && rowDiff != 0 && colDiff != 0) {
			cout << "Not a legal queen move" << endl << endl;
			return false;
		}

		//collision check
		if (rowDiff > 0 && colDiff > 0) {
			for (int i = n1 - 1; i > n2; i--) {
				for (int j = l1 - 1; j > l2; j--) {
					if (location[i][j].piece != nullptr) {
						cout << "There's a piece in the way" << endl << endl;
						return false;
					}
				}
			}
		}

		else if (rowDiff < 0 && colDiff < 0) {
			for (int i = n1 + 1; i < n2; i++) {
				for (int j = l1 + 1; j < l2; j++) {
					if (location[i][j].piece != nullptr) {
						cout << "There's a piece in the way" << endl << endl;
						return false;
					}
				}
			}
		}

		else if (rowDiff > 0 && colDiff < 0) {
			for (int i = n1 - 1; i > n2; i--) {
				for (int j = l1 + 1; j < l2; j++) {
					if (location[i][j].piece != nullptr) {
						cout << "There's a piece in the way" << endl << endl;
						return false;
					}
				}
			}
		}

		else if (rowDiff < 0 && colDiff > 0) {
			for (int i = n1 + 1; i < n2; i++) {
				for (int j = l1 - 1; j > l2; j--) {
					if (location[i][j].piece != nullptr) {
						cout << "There's a piece in the way" << endl << endl;
						return false;
					}
				}
			}
		}
		else if (rowDiff == 0 && colDiff > 0) {
			for (int i = l1 - 1; i > l2; i--) {
				if (location[n1][i].piece != nullptr) {
					cout << "There's a piece in the way" << endl << endl;
					return false;
				}
			}
		}
		else if (rowDiff == 0 && colDiff < 0) {
			for (int i = l1 + 1; i < l2; i++) {
				if (location[n1][i].piece != nullptr) {
					cout << "There's a piece in the way" << endl << endl;
					return false;
				}
			}
		}
		else if (rowDiff > 0 && colDiff == 0) {
			for (int i = n1 - 1; i > n2; i--) {
				if (location[i][l1].piece != nullptr) {
					cout << "There's a piece in the way" << endl << endl;
					return false;
				}
			}
		}
		else if (rowDiff < 0 && colDiff == 0) {
			for (int i = n1 + 1; i < n2; i++) {
				if (location[i][l1].piece != nullptr) {
					cout << "There's a piece in the way" << endl << endl;
					return false;
				}
			}
		}
		if (location[n2][l2].piece != nullptr && location[n2][l2].piece->player != playerTurn) {
			cout << "You have taken the opponents's " << location[n2][l2].piece->naam << " nice" << endl << endl;
			location[n2][l2].piece = location[n1][l1].piece;
			location[n1][l1].piece = nullptr;
			Sleep(2000);
			return true;
		}
		else {
			cout << "Move successful" << endl << endl;
			location[n2][l2].piece = location[n1][l1].piece;
			location[n1][l1].piece = nullptr;
			Sleep(2000);
			return true;
		}
	}
	else if (location[n1][l1].piece->naam.compare("Knight") == 0) {
		//beyond hell to do but knight movement
		if (abs(rowDiff) * abs(colDiff) != 2) {
			cout << "Not a legal knight move" << endl << endl;
			return false;
		}
		if (location[n2][l2].piece != nullptr && location[n2][l2].piece->player != playerTurn) {
			cout << "You have taken the opponent's " << location[n2][l2].piece->naam << " nice" << endl << endl;
			location[n2][l2].piece = location[n1][l1].piece;
			location[n1][l1].piece = nullptr;
			Sleep(2000);
			return true;
		}
		else {
			cout << "Move successful" << endl << endl;
			location[n2][l2].piece = location[n1][l1].piece;
			location [n1] [l1] .piece = nullptr;
			Sleep(2000);
			return true;
		}
	}
	else if (location[n1][l1].piece->naam.compare("Bishop") == 0) {
		//diagonal move check
		if (abs(rowDiff) != abs(colDiff)) {
			cout << "Not a legal bishop move" << endl;
			return false;
		}
		//collision check
		if (rowDiff > 0 && colDiff > 0) {
			for (int i = n1 - 1; i > n2; i--) {
				for (int j = l1 - 1; j > l2; j--) {
					if (location[i][j].piece != nullptr) {
						cout << "There's a piece in the way" << endl << endl;
						return false;
					}
				}
			}
		}
		else if (rowDiff < 0 && colDiff < 0) {
			for (int i = n1 + 1; i < n2; i++) {
				for (int j = l1 + 1; j < l2; j++) {
					if (location[i][j].piece != nullptr) {
						cout << "There's a piece in the way" << endl << endl;
						return false;
					}
				}
			}
		}
		else if (rowDiff > 0 && colDiff < 0) {
			for (int i = n1 - 1; i > n2; i--) {
				for (int j = l1 + 1; j < l2; j++) {
					if (location[i][j].piece != nullptr) {
						cout << "There's a piece in the way" << endl << endl;
						return false;
					}
				}
			}
		}
		else if (rowDiff < 0 && colDiff > 0) {
			for (int i = n1 + 1; i < n2; i++) {
				for (int j = l1 - 1; j > l2; j--) {
					if (location[i][j].piece != nullptr) {
						cout << "There's a piece in the way" << endl << endl;
						return false;
					}
				}
			}
		}
		//code for yeeting the pieces out of the game
		if (location[n2][l2].piece != nullptr && location[n2][l2].piece->player != playerTurn) {
			cout << "You have taken the opponent's " << location[n2][l2].piece->naam << " nice" << endl << endl;
			location[n2][l2].piece = location[n1][l1].piece;
			location[n1][l1].piece = nullptr;
			Sleep(2000);
			return true;
		}
		else {
			cout << "Move successful" << endl << endl;
			location[n2][l2].piece = location[n1][l1].piece;
			location[n1][l1].piece = nullptr;
			Sleep(2000);
			return true;
		}
	}
	else if (location[n1][l1].piece->naam.compare("Rook") == 0) {
		if (rowDiff != 0 && colDiff != 0) {
			cout << "That is not a legal Rook move" << endl << endl;
			return false;
		}
		//if statement that checks collision
		if (rowDiff == 0 && colDiff > 0) {
			for (int i = l1 - 1; i > l2; i--) {
				if (location[n1][i].piece != nullptr) {
					cout << "There's a piece in your way" << endl << endl;
					return false;
				}
			}
		}
		else if (rowDiff == 0 && colDiff < 0) {
			for (int i = l1 + 1; i < l2; i++) {
				if (location[n1][i].piece != nullptr) {
					cout << "There's a piece in your way" << endl << endl;
					return false;
				}
			}
		}
		else if (rowDiff > 0 && colDiff == 0) {
			for (int i = n1 - 1; i > n2; i--) {
				if (location[i][l1].piece != nullptr) {
					cout << "There's a piece in your way" << endl << endl;
					return false;
				}
			}
		}
		else if (rowDiff < 0 && colDiff == 0) {
			for (int i = n1 + 1; i < n2; i++) {
				if (location[i][l1].piece != nullptr) {
					cout << "There's a piece in your way" << endl << endl;
					return false;
				}
			}
		}
		if (location[n2][l2].piece != nullptr && location[n2][l2].piece->player != playerTurn) {
			cout << "You have taken the opponents's " << location[n2][l2].piece->naam << " nice" << endl << endl;
			location[n2][l2].piece = location[n1][l1].piece;
			location[n1][l1].piece = nullptr;
			Sleep(2000);
			return true;
		}
		else {
			cout << "Move successful" << endl << endl;
			location[n2][l2].piece = location[n1][l1].piece;
			location[n1][l1].piece = nullptr;
			Sleep(2000);
			return true;
		}
	}
	else return false;
}

void Display(board location[8][8]) {
	//a friend helped me make the ascii for the chess board and the logic for the code
	char displayBoard[38][53] = {
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', 'A', ' ', ' ', ' ', ' ', ' ', 'B', ' ', ' ', ' ', ' ', ' ', 'C', ' ', ' ', ' ', ' ', ' ', 'D', ' ', ' ', ' ', ' ', ' ', 'E', ' ', ' ', ' ', ' ', ' ', 'F', ' ', ' ', ' ', ' ', ' ', 'G', ' ', ' ', ' ', ' ', ' ', 'H', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
	{' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
	{' ', ' ', '7', ' ', '#', ' ', ' ', 'R', ' ', ' ', '#', ' ', ' ', 'N', ' ', ' ', '#', ' ', ' ', 'B', ' ', ' ', '#', ' ', ' ', 'Q', ' ', ' ', '#', ' ', ' ', 'K', ' ', ' ', '#', ' ', ' ', 'B', ' ', ' ', '#', ' ', ' ', 'N', ' ', ' ', '#', ' ', ' ', 'R', ' ', ' ', '#'},
	{' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
	{' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
	{' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
	{' ', ' ', '6', ' ', '#', ' ', ' ', 'P', ' ', ' ', '#', ' ', ' ', 'P', ' ', ' ', '#', ' ', ' ', 'P', ' ', ' ', '#', ' ', ' ', 'P', ' ', ' ', '#', ' ', ' ', 'P', ' ', ' ', '#', ' ', ' ', 'P', ' ', ' ', '#', ' ', ' ', 'P', ' ', ' ', '#', ' ', ' ', 'P', ' ', ' ', '#'},
	{' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
	{' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
	{' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
	{' ', ' ', '5', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
	{' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
	{' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
	{' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
	{' ', ' ', '4', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
	{' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
	{' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
	{' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
	{' ', ' ', '3', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
	{' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
	{' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
	{' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
	{' ', ' ', '2', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
	{' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
	{' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
	{' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
	{' ', ' ', '1', ' ', '#', ' ', ' ', 'P', ' ', ' ', '#', ' ', ' ', 'P', ' ', ' ', '#', ' ', ' ', 'P', ' ', ' ', '#', ' ', ' ', 'P', ' ', ' ', '#', ' ', ' ', 'P', ' ', ' ', '#', ' ', ' ', 'P', ' ', ' ', '#', ' ', ' ', 'P', ' ', ' ', '#', ' ', ' ', 'P', ' ', ' ', '#'},
	{' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
	{' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
	{' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
	{' ', ' ', '0', ' ', '#', ' ', ' ', 'R', ' ', ' ', '#', ' ', ' ', 'N', ' ', ' ', '#', ' ', ' ', 'B', ' ', ' ', '#', ' ', ' ', 'Q', ' ', ' ', '#', ' ', ' ', 'K', ' ', ' ', '#', ' ', ' ', 'B', ' ', ' ', '#', ' ', ' ', 'N', ' ', ' ', '#', ' ', ' ', 'R', ' ', ' ', '#'},
	{' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
	{' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
	};

	int dR0 = 31;
	int dR1 = 27;
	int dR2 = 23;
	int dR3 = 19;
	int dR4 = 15;
	int dR5 = 11;
	int dR6 = 7;
	int dR7 = 3;
	int dC0 = 7;
	int dC1 = 13;
	int dC2 = 19;
	int dC3 = 25;
	int dC4 = 31;
	int dC5 = 37;
	int dC6 = 43;
	int dC7 = 49;
	int tempRow = 0;
	int tempColumn = 0;

	//pain in the ass, this took me 2 hours with the help of a friend
	for (int i = 0; i < 8; i++) {
		if (i == 0)
			tempRow = dR0;
		else if (i == 1)
			tempRow = dR1;
		else if (i == 2)
			tempRow = dR2;
		else if (i == 3)
			tempRow = dR3;
		else if (i == 4)
			tempRow = dR4;
		else if (i == 5)
			tempRow = dR5;
		else if (i == 6)
			tempRow = dR6;
		else
			tempRow = dR7;

		for (int j = 0; j < 8; j++) {
			if (j == 0)
				tempColumn = dC0;
			else if (j == 1)
				tempColumn = dC1;
			else if (j == 2)
				tempColumn = dC2;
			else if (j == 3)
				tempColumn = dC3;
			else if (j == 4)
				tempColumn = dC4;
			else if (j == 5)
				tempColumn = dC5;
			else if (j == 6)
				tempColumn = dC6;
			else
				tempColumn = dC7;

			//updates the board display whenever a piece is moved
			if (location[i][j].piece == nullptr)
				displayBoard[tempRow][tempColumn] = ' ';
			else if (location[i][j].piece->naam.compare("Pawn") == 0)
				displayBoard[tempRow][tempColumn] = 'P';
			else if (location[i][j].piece->naam.compare("King") == 0)
				displayBoard[tempRow][tempColumn] = 'K';
			else if (location[i][j].piece->naam.compare("Queen") == 0)
				displayBoard[tempRow][tempColumn] = 'Q';
			else if (location[i][j].piece->naam.compare("Bishop") == 0)
				displayBoard[tempRow][tempColumn] = 'B';
			else if (location[i][j].piece->naam.compare("Knight") == 0)
				displayBoard[tempRow][tempColumn] = 'N';
			else
				displayBoard[tempRow][tempColumn] = 'R';
		}
	}
	for (int i = 0; i < 34; i++) {
		cout << endl;
		for (int j = 0; j < 53; j++) {
			cout << displayBoard[i][j];
		}
	}
	cout << endl << endl;
}