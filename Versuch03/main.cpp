/**
 * @file main.cpp
 *
 * Provides functions for the game Reversi
 */

/**
* @mainpage Reversi
*
* Dokumentation des Spiels Reversi im Rahmen des Praktikums Informatik 1.
*
*/

#include <iostream>
#include <stdlib.h>
#include "test.h"
#include "config.h"
#include "Reversi_KI.h"

/**
 * @brief Function providing first initialization of a new field
 *
 * This function fills an existing field with zeros and creates the starting pattern.
 *
 * @param field The field which will be initialized
 */
void initialize_field(int field[SIZE_Y][SIZE_X])
{
	for (int j = 0; j < SIZE_Y; ++j)
		{
			for(int i = 0; i < SIZE_X; ++i)
			{
				field[j][i] = 0;
			}
		}
		field[SIZE_Y / 2 - 1][SIZE_X / 2 - 1] = 1;
		field[SIZE_Y / 2][SIZE_X / 2 - 1] = 2;
		field[SIZE_Y / 2 - 1][SIZE_X / 2] = 2;
		field[SIZE_Y / 2][SIZE_X / 2] = 1;
}



/**
* @brief Prints the playing field to the console.
*
* This function gets the current playing field as parameter (two dimensional array)
* with entries of 0 (field is empty), 1 (field belongs to player 1), 2 (field belongs to player 2).
* <br>The function prints the playing field, grid included, to the console.
* Crosses symbolize player 1 while circles symbolize player 2.
*
*  @param field  The field which is going to be printed
*/
void show_field(const int field[SIZE_Y][SIZE_X])
{
	std::cout << "   | ";

	//Start at ASCII 65 = A
	for (int i = 65; i < 65 + SIZE_X; ++i)
		std::cout << ((char) i) << " | " ;

	std::cout << std::endl;

	for (int j = 0; j < SIZE_Y; ++j)
	{
		for(int i = 0; i < SIZE_X; ++i)
		{
			std::cout << "---+";
		}
		std::cout << "---+" << std::endl;

		std::cout << " " << j + 1 << " |";
		for (int i = 0; i < SIZE_X; ++i)
		{
			switch (field[j][i])
			{
				case 0:
					std::cout << "   " ;
					break;
				case 1:
					std::cout << " X ";
					break;
				case 2:
					std::cout << " O ";
					break;
				default:
					std::cout << "Inconsistent data in field!" << std::endl;
					std::cout << "Aborting .... " << std::endl;
					exit(0);
					break;
			}
			std::cout << "|";
		};//for i
		std::cout <<  std::endl;
	}//for j
}

/**
 * @brief Checks who is the winner
 *
 * This function gets the final playing field as parameter (two dimensional array)
 * with entries 1 (field belongs to player 1), 2 (field belongs to player 2).
 * <br>This function looks at every fieldelement to count the claimed fields of
 * player 1 and 2. After that it checks which player has the most to return the winner,
 * or just in case a draw.
 *
 * @param field	The field which has to be checked
 * @return The number of the winning player (1 or 2) or 0 for draw.
 */
int winner(const int field[SIZE_Y][SIZE_X])
{
	int count_p1 = 0;
	int count_p2 = 0;

	for (int j = 0; j < SIZE_Y; ++j)
	{
		for (int i = 0; i < SIZE_X; ++i)
		{
			//loop through all fields + counting of X (1) and O (2)
			if (field[j][i] == 1)
			{
				++count_p1;
			}
			if (field[j][i] == 2)
			{
				++count_p2;
			}

		}
	}
	if (count_p1 == count_p2)
	{
		return 0;
	}
	if (count_p1 < count_p2)
	{
		return 2;
	}
	else
	{
		return 1;
	}
}

/**
* @brief Checks for two index parameters, if they adress a position on the field
*
* This function takes the given parameters and compares them to the constant borders of the playtable.
* The playable field is between the indices 0 to SIZE_X and 0 to SIZE_Y.
* Are the coordinates of the given point out of the playground, the function will return false.
*
* @param pos_x	Position on the x-axis.
* @param pos_y	Position on the y-axis.
* @return true	If the given point lays on playable ground.
* @return false If the given point does not lay on playable ground.
*/
bool on_field(const int pos_x, const int pos_y)
{

	if (0 <= pos_x && pos_x < SIZE_X)
	{
		if (0 <= pos_y && pos_y < SIZE_Y)
		{
			return true;
		}
	}

	return false;
}



bool turn_valid(const int field[SIZE_Y][SIZE_X], const int player, const int pos_x, const int pos_y)
{
	// Process all possible directions
	int opponent = 3 - player; // the same as: if player = 1 -> opponent = 2 else
							   // if player = 2 -> opponent = 1

	if (field[pos_y][pos_x] != 0) //check if field is currently empty
	{
		return false;
	}

	for (int j = -1; j <= 1; ++j)
	{
		for (int i = -1; i <= 1; ++i)
		{
			//check if you can find an opponents stone in a neighboring field
			//then check if in this direction all stones are opponent stones until
			//the line is terminated by one of your own stone
			//in that case return true otherwise not
		}
	}
	return false;
}

void execute_turn(int field[SIZE_Y][SIZE_X], const int player, const int pos_x, const int pos_y)
{
	int opponent = 3 - player;
	
	for (int j = -1; j <= 1; ++j)
	{
		for (int i = -1; i <= 1; ++i)
		{
			// similar to function "turn_valid" - just take care that all opponent
			// stones are changed to yours
		}
	}

}

int possible_turns(const int field[SIZE_Y][SIZE_X], const int player)
{
	return 0;
}

bool human_turn(int field[SIZE_Y][SIZE_X], const int player)
{
	if (possible_turns(field, player) == 0)
	{
		return false;
	}

	int pos_x;
	int pos_y;

	while (true)
	{
		std::string input;
		std::cout << std::endl << "Your move (e.g. A1): " ;
		std::cin >> input;
		pos_x = (int) input[0] % 32 -1;  // it also works for small types
		pos_y = (int) input[1] - 49;

		if (turn_valid(field, player, pos_x, pos_y))
		{
			//accept turn;
			break;
		}
		else
		{
			std::cout << std::endl << "Invalid input !" << std::endl;
		}
	}

	execute_turn(field, player, pos_x, pos_y);

	return true;
}

void game(const int player_typ[2])
{

	int field[SIZE_Y][SIZE_X];

	//Create starting pattern
	initialize_field(field);

	int current_player = 1;
	show_field(field);
	//let each player make its moves until no further moves are possible

	switch (winner(field))
	{

	}
}

int main(void)
{
	if (TEST == 1)
	{
		bool result = run_full_test();
		if (result == true)
		{
			std::cout << "ALL TESTS PASSED!" << std::endl << std::endl;
		}
		else
		{
			std::cout << "TEST FAILED!" << std::endl;
		}
		std::cout << std::endl << std::endl;
	}

	int field[SIZE_Y][SIZE_X];

	initialize_field(field);

	show_field(field);

	// int player_type[2] = { HUMAN, HUMAN };  //Contains information wether players are HUMAN(=1) or COPMUTER(=2)
	// game(player_type);
	return 0;
}
