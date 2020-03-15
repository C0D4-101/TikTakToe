/*********************************************************************************************
	C0D4 - 2020
	A SIMPLE TICKTAKTOE GAME FOR EDUCATIONAL PURPOSES
	I DOUBT THIS FOLLOWS ANYTHING REMOTELY CLOSE TO BEST PRACTISES, BUT IT WORKS.
**********************************************************************************************/
#include <map>
#include <string>
#include <iostream>
#include <cmath>

char square[10] = { 'o','1','2','3','4','5','6','7','8','9' };

std::map<int, std::string> playerNames = { 
	{1, "Player1"},
	{2, "Player2"}
};

int checkwin();
void renderBoard();

int main()
{
	int player = 1, i, choice;
	char mark;
	do
	{
		renderBoard();
		player = (player % 2) ? 1 : 2;

		std::cout << playerNames[player] << ", pick a number:  ";
		std::cin >> choice;

		mark = (player == 1) ? 'X' : 'O';

		if (choice == 1 && square[1] == '1')
			square[1] = mark;
		else if (choice == 2 && square[2] == '2')
			square[2] = mark;
		else if (choice == 3 && square[3] == '3')
			square[3] = mark;
		else if (choice == 4 && square[4] == '4')
			square[4] = mark;
		else if (choice == 5 && square[5] == '5')
			square[5] = mark;
		else if (choice == 6 && square[6] == '6')
			square[6] = mark;
		else if (choice == 7 && square[7] == '7')
			square[7] = mark;
		else if (choice == 8 && square[8] == '8')
			square[8] = mark;
		else if (choice == 9 && square[9] == '9')
			square[9] = mark;
		else
		{
			std::cout << "Invalid move ";
			player--; //return to previous player in order for current player to try again from ++ below
			std::cin.ignore();
			std::cin.get();
		}

		i = checkwin();
		player++;
		
	} while (i == -1);
	
	renderBoard();

	if (i == 1)
		std::cout << "==>\t" << playerNames[--player] << " wins ";
	else
		std::cout << "==>\aGame draw";

	std::cin.ignore();
	std::cin.get();

	return 0;
}

/*********************************************
	FUNCTION TO RETURN GAME STATUS
	1 FOR GAME IS OVER WITH RESULT
	-1 FOR GAME IS IN PROGRESS
	O GAME IS OVER AND NO RESULT
**********************************************/

int checkwin()
{
	if (square[1] == square[2] && square[2] == square[3]) {
		square[1] = 'W';
		square[2] = 'I';
		square[3] = 'N';
		return 1;
	}
	else if (square[4] == square[5] && square[5] == square[6]) {
		square[4] = 'W';
		square[5] = 'I';
		square[6] = 'N';
		return 1;
	}
	else if (square[7] == square[8] && square[8] == square[9]) {
		square[7] = 'W';
		square[8] = 'I';
		square[9] = 'N';
		return 1;
	}
	else if (square[1] == square[4] && square[4] == square[7]) {
		square[1] = 'W';
		square[4] = 'I';
		square[7] = 'N';
		return 1;
	}
	else if (square[2] == square[5] && square[5] == square[8]) {
		square[2] = 'W';
		square[5] = 'I';
		square[8] = 'N';
		return 1;
	}
	else if (square[3] == square[6] && square[6] == square[9]) {
		square[3] = 'W';
		square[6] = 'I';
		square[9] = 'N';
		return 1;
	}
	else if (square[1] == square[5] && square[5] == square[9]) {
		square[1] = 'W';
		square[5] = 'I';
		square[9] = 'N';
		return 1;
	}
	else if (square[3] == square[5] && square[5] == square[7]) {
		square[7] = 'W';
		square[5] = 'I';
		square[3] = 'N';
		return 1;
	}
	else if (square[1] != '1' && square[2] != '2' && square[3] != '3'
		&& square[4] != '4' && square[5] != '5' && square[6] != '6'
		&& square[7] != '7' && square[8] != '8' && square[9] != '9')
		return 0;
	else
		return -1;
} 

/**********************************************************************************
	 FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK INSIDE THE CONSOLE
	 IM SURE THERES A BETTER WAY TO DRAW THE GRID xD
***********************************************************************************/

void renderBoard()
{
	system("cls");
	std::cout << "\n\n\tTic Tac Toe\n\n";
	std::cout << "Player 1 (X)  -  Player 2 (O)" << std::endl << std::endl;
	std::cout << std::endl;

	std::cout << "     |     |     " << std::endl;
	std::cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << std::endl;

	std::cout << "_____|_____|_____" << std::endl;
	std::cout << "     |     |     " << std::endl;

	std::cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << std::endl;

	std::cout << "_____|_____|_____" << std::endl;
	std::cout << "     |     |     " << std::endl;

	std::cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << std::endl;

	std::cout << "     |     |     " << std::endl << std::endl;
}

/*******************************************************************
				END OF PROJECT
********************************************************************/