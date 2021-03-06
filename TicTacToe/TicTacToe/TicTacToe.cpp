// TicTacToe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

void PlayerMove(int rowInput, int columnInput, char playerTurn, char TicTacToeBoard[3][3]);
char CheckWinner(char TicTacToeBoard[3][3]);


int main()
{
	char X = 'X';
	char O = 'O';
	char TicTacToeBoard[3][3];
	int columnInput;
	int rowInput;
	char playerTurn = 'X';
	bool gameOver = false;
	int turnCount = 0;

	/*
	This loop generates the board and marks the empty spaces as 'E' so that the 
	players know which spaces are still available
	*/
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			TicTacToeBoard[i][j] = 'E';
			cout << "  ";
			cout << TicTacToeBoard[i][j];
		}
		cout << "\n";
	}

	do
	{
		if (playerTurn == 'X' && turnCount < 9)
		{
			cout << "It is player " << playerTurn << "'s turn!  Select a position on the board using numbers 1 - 3 for both row and column.\n";
			cout << "Row: ";
			cin >> rowInput;
			cout << "\nColumn: ";
			cin >> columnInput;

			if (TicTacToeBoard[rowInput-1][columnInput-1] != 'X' && TicTacToeBoard[rowInput-1][columnInput-1] != 'O')
			{
				
				PlayerMove(rowInput, columnInput, playerTurn, TicTacToeBoard);
				turnCount++;
				CheckWinner(TicTacToeBoard);
				if (CheckWinner(TicTacToeBoard) == 'X')
				{
					cout << "X is the winner!";
					cout << "\n";
					gameOver = true;
				}
				else
				{
					playerTurn = 'O';
				}	
			}
			else if (TicTacToeBoard[rowInput - 1][columnInput - 1] != 'X' || TicTacToeBoard[rowInput - 1][columnInput - 1] != 'O')
			{
				turnCount = turnCount;
				playerTurn = playerTurn;
			}
		}
		else if (playerTurn == 'O' && turnCount < 9)
		{
			cout << "It is player " << playerTurn << "'s turn!  Select a position on the board using numbers 1 - 3 for both row and column.\n";

			cout << "Row: ";
			cin >> rowInput;
			cout << "\nColumn: ";
			cin >> columnInput;

			if (TicTacToeBoard[rowInput - 1][columnInput - 1] != 'X' && TicTacToeBoard[rowInput - 1][columnInput - 1] != 'O')
			{
				PlayerMove(rowInput, columnInput, playerTurn, TicTacToeBoard);
				turnCount++;
				CheckWinner(TicTacToeBoard);
				if (CheckWinner(TicTacToeBoard) == 'O')
				{
					cout << "O is the winner!";
					cout << "\n";
					gameOver = true;
				}
				else
				{
					playerTurn = 'X';
				}
			}
			else if (TicTacToeBoard[rowInput - 1][columnInput - 1] != 'X' || TicTacToeBoard[rowInput - 1][columnInput - 1] != 'O')
			{
				turnCount = turnCount;
				playerTurn = playerTurn;
			}
		}
		else if (turnCount == 9)
		{
			gameOver = true;
			cout << "It's a cat's game!\n";
			break;
		}
	} while (gameOver == false);
    return 0;
}

/**
This function allows the player to make a move in any empty space on the board by taking 
the input the user entered for their row and column choice.
*/
void PlayerMove(int rowInput, int columnInput, char playerTurn, char TicTacToeBoard[3][3])
{

	TicTacToeBoard[rowInput - 1][columnInput - 1] = playerTurn;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << "  ";
			cout << TicTacToeBoard[i][j];
		}
		cout << "\n";
	}
}

char CheckWinner(char TicTacToeBoard[3][3])
{
	char winner = 'E';

	// Checks for horizontal win
	for (int i = 0; i < 3; ++i)
	{
		if (*TicTacToeBoard[i] == TicTacToeBoard[i][1] && TicTacToeBoard[i][1] == TicTacToeBoard[i][2])
		{
			if ((winner = *TicTacToeBoard[i]) != 'E')
			{
				return winner;
			}
		}
	}

	// Checks for vertical win
	for (int i = 0; i < 3; ++i)
		if (TicTacToeBoard[0][i] == TicTacToeBoard[1][i] && TicTacToeBoard[1][i] == TicTacToeBoard[2][i])
			if ((winner = TicTacToeBoard[0][i]) != 'E')
				return winner;

	// Check for diagonal win (upper left to bottom right)
	if (**TicTacToeBoard == TicTacToeBoard[1][1] && TicTacToeBoard[1][1] == TicTacToeBoard[2][2])
		if ((winner = **TicTacToeBoard) != 'E')
			return winner;

	// Check for diagonal win (upper right to bottom left)
	if (TicTacToeBoard[0][2] == TicTacToeBoard[1][1] && TicTacToeBoard[1][1] == TicTacToeBoard[2][0])
		if ((winner = TicTacToeBoard[0][2]) != 'E')
			return winner;

	return winner;
}

