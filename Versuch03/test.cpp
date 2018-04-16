/**
 * @file test.cpp
 *
 * Provides a function for testing the program and some other functions in order to provide this.
 */

#include <iostream>
#include "test.h"
#include "config.h"

extern void show_field(const int field[SIZE_Y][SIZE_X]);
extern int winner(const int field[SIZE_Y][SIZE_X]);
extern bool on_field(const int pos_x, const int pos_y);
extern bool turn_valid(const int field[SIZE_Y][SIZE_X],  const int player, const int pos_x, const int pos_y);
extern void execute_turn(int field[SIZE_Y][SIZE_X], const int player, const int pos_x, const int pos_y);
extern int possible_turns(const int field[SIZE_Y][SIZE_X], const int player);

/**
 * Function for testing the winner function.
 *
 * @param field The field which will be tested.
 * @param winner_code The estimated winner.
 * @param test_number Current number of the test running
 * @return True if the calculated winner equals the estimated winner. False else.
 */
bool test_winner(const int field[SIZE_Y][SIZE_X], const int winner_code, const int test_number)
{
	std::cout << "Running test " << test_number + 1 << " for 'winner'..." << std::endl;
	std::cout << "----------------------------" << std::endl << std::endl;
	int result = winner(field);
	if (result == winner_code)
	{
		std::cout << "Test " << test_number + 1 << " passed!" << std::endl << std::endl;
		return true;
	}
	else
	{
		std::cout << "Test " << test_number + 1 << " failed!" << std::endl << std::endl;
		if (VERBOSE == 1)
		{
		    show_field(field);
			std::cout << std::endl << "Calculated result: " << result << std::endl << "Right result: " << winner_code
					  << std::endl << std::endl;
		}
		return false;
	}
}

bool test_on_field(const int pos_x, const int pos_y, const bool valid, const int test_number)
{
	// check if given position is on the field
	return 0;
}

bool test_turn_valid(const int field[SIZE_Y][SIZE_X], const int player, const int pos_x,
					 const int pos_y, const bool valid, const int test_number)
{
	// check for a given field whether a turn is valid
	// if VERBOSE is 1 additionaly show the field and the invalid position
	return 0;
}

bool test_execute_turn(int input[SIZE_Y][SIZE_X], const int output[SIZE_Y][SIZE_X],
					   const int player, const int pos_x, const int pos_y, const int test_number)
{
	// check for a given field whether the execution of a turn is valid
	// if VERBOSE is 1 additionaly show both fields	
	return 0;
}

bool test_possible_turns(const int field[SIZE_Y][SIZE_X], const int player,
						 const int count_possible_turns, const int test_number)
{
	// very if your function finds all possible turns
	// if VERBOSE is 1 additionaly show the field and the correct turns and the invalid turns
	return 0;
}

bool run_full_test(void)
{
	bool result = true;


// ---------- CHECK WINNER ---------- //

	int winner_matrix[3][8][8] = {
		{   {1, 2, 1, 2, 1, 2, 1, 2},
			{1, 2, 1, 2, 1, 2, 1, 2},
			{1, 2, 1, 2, 1, 2, 1, 2},
			{1, 2, 1, 2, 1, 2, 1, 2},
			{1, 2, 1, 2, 1, 2, 1, 2},
			{1, 2, 1, 2, 1, 2, 1, 2},
			{1, 2, 1, 2, 1, 2, 1, 2},
			{1, 2, 1, 2, 1, 2, 1, 2}
		},

		{   {1, 1, 2, 1, 1, 2, 1, 1},
			{2, 1, 1, 2, 1, 1, 2, 1},
			{1, 2, 1, 1, 2, 1, 1, 2},
			{1, 1, 2, 1, 1, 2, 1, 1},
			{2, 1, 1, 2, 1, 1, 2, 1},
			{1, 2, 1, 1, 2, 1, 1, 2},
			{1, 1, 2, 1, 1, 2, 1, 1},
			{2, 1, 1, 2, 1, 1, 2, 1}
		},

		{   {1, 2, 2, 1, 2, 2, 1, 2},
			{2, 1, 2, 2, 1, 2, 2, 1},
			{2, 2, 1, 2, 2, 1, 2, 2},
			{1, 2, 2, 1, 2, 2, 1, 2},
			{2, 1, 2, 2, 1, 2, 2, 1},
			{2, 2, 1, 2, 2, 1, 2, 2},
			{1, 2, 2, 1, 2, 2, 1, 2},
			{2, 1, 2, 2, 1, 2, 2, 1}
		}
	};

	int winner_code[3] = {0, 1, 2};

	for (int i = 0; i < 3; ++i)
	{
		bool tmp_result = test_winner(winner_matrix[i], winner_code[i], i);
		if (result == true && tmp_result == false)
		{
			result = false;
		}
	}

	std::cout << "End of test for 'winner'" << std::endl << std::endl;


// ---------- CHECK FIELD POSITION ---------- //

	int position[6][2] = { {2, 3}, {0, 8}, {-1, 7}, {2, -1}, {8, 5}, {-1,8} };   // pos_x, pos_y
	bool onfield_valid[6] = {true, false, false, false, false, false};
	
	for (int i = 0; i < 6; ++i)
	{
		// TODO: Call the check function
	}

	
// ---------- CHECK TURN VALID ---------- //

	int turnvalid_matrix[7][8][8] = {
			{   {1, 0, 2, 0, 0, 1, 1, 1},
				{0, 0, 2, 0, 0, 0, 0, 1},
				{0, 0, 0, 0, 0, 1, 2, 2},
				{2, 2, 0, 2, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 2, 2, 0},
				{0, 0, 0, 2, 1, 1, 0, 2},
				{1, 0, 0, 1, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 1, 0, 1}
			},

			{   {1, 0, 2, 0, 0, 1, 1, 1},
				{0, 0, 2, 0, 0, 1, 0, 0},
				{0, 0, 2, 0, 0, 2, 1, 1},
				{0, 0, 0, 2, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 2, 2, 0},
				{0, 0, 0, 2, 1, 1, 0, 2},
				{1, 0, 0, 1, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 1, 0, 1}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 1, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 2, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 1, 0, 0, 2, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 1, 0},
				{2, 0, 1, 2, 0, 2, 0, 0},
				{0, 2, 0, 2, 2, 2, 2, 2},
				{0, 0, 0, 0, 0, 0, 0, 1},
				{1, 0, 0, 0, 0, 2, 2, 2},
				{0, 2, 0, 0, 0, 0, 0, 0},
				{0, 1, 0, 1, 1, 1, 0, 0}
			},

			{   {2, 1, 0, 0, 2, 1, 1, 1},
				{0, 2, 0, 0, 0, 0, 0, 0},
				{1, 0, 0, 2, 0, 0, 0, 1},
				{0, 1, 1, 1, 0, 1, 0, 0},
				{1, 0, 0, 1, 1, 0, 0, 2},
				{0, 0, 0, 0, 0, 0, 0, 1},
				{1, 1, 0, 0, 0, 0, 2, 0},
				{1, 1, 2, 0, 0, 2, 2, 1}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 1, 0, 0, 0, 0},
				{0, 0, 0, 0, 1, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},
			
			{
				{1, 2, 2, 2, 2, 2, 2, 2},
				{1, 2, 1, 1, 2, 2, 2, 2},
				{1, 1, 1, 2, 2, 2, 2, 2},
				{1, 1, 1, 2, 2, 2, 2, 2},
				{1, 1, 1, 1, 2, 2, 2, 2},
				{1, 1, 1, 0, 2, 2, 2, 2},
				{1, 0, 0, 0, 2, 0, 0, 2},
				{0, 0, 0, 0, 0, 0, 0, 0},
			}

		};

	int turnvalid_player[7] = {1, 2, 2, 1, 2, 1, 1};
	int turnvalid_pos[7][2] = { {2, 3}, {0, 3}, {4, 3}, {3, 4}, {3, 5}, {3, 4}, {5, 7} };  // pos_x, pos_y
	bool turnvalid_valid[7] = {false, false, false, true, true, false, false};

	for (int i = 0; i < 7; ++i)
	{
		// TODO: Call the check function
	}


// ---------- CHECK EXECUTE TURN ---------- //

	int executeturn_matrix_in[10][8][8] = {
			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 1, 2, 2},
				{2, 2, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 2, 1, 1},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 1, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 2, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 1, 0},
				{0, 0, 0, 2, 0, 2, 0, 0},
				{0, 0, 0, 2, 2, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 2, 0, 0, 0, 0},
				{0, 0, 0, 1, 0, 1, 0, 0},
				{0, 0, 0, 1, 1, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 1, 0, 0, 0, 0},
				{0, 0, 0, 0, 1, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 1, 0, 0, 1, 0},
				{0, 0, 0, 2, 0, 2, 0, 0},
				{0, 0, 0, 2, 2, 0, 0, 0},
				{0, 1, 2, 0, 2, 2, 1, 0},
				{0, 0, 0, 2, 2, 0, 0, 0},
				{0, 0, 0, 1, 0, 1, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 2, 0, 0},
				{0, 0, 0, 0, 1, 0, 0, 0},
				{0, 0, 0, 1, 0, 0, 0, 0},
				{0, 0, 0, 1, 1, 1, 1, 0},
				{0, 0, 1, 0, 0, 0, 0, 0},
				{0, 0, 2, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 1, 0, 0, 0, 0, 0, 0},
				{0, 1, 0, 0, 0, 0, 2, 1},
				{1, 0, 1, 1, 2, 0, 0, 0},
				{0, 0, 1, 0, 0, 0, 0, 0},
				{0, 0, 0, 1, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},
			
			{   {0, 0, 0, 0, 0, 1, 0, 1},
				{0, 0, 0, 0, 0, 2, 2, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 2, 2, 0, 0},
				{0, 0, 0, 1, 0, 1, 0, 0},
				{0, 0, 2, 0, 0, 2, 0, 0},
				{0, 1, 0, 0, 0, 1, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			}
		};

	int executeturn_matrix_out[10][8][8] {
			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 1, 2, 2},
				{2, 2, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 2, 1, 1},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 1, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 2, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 1, 0},
				{0, 0, 0, 2, 0, 1, 0, 0},
				{0, 0, 0, 2, 1, 0, 0, 0},
				{0, 0, 0, 1, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 2, 0, 0, 0, 0},
				{0, 0, 0, 2, 0, 1, 0, 0},
				{0, 0, 0, 2, 1, 0, 0, 0},
				{0, 0, 0, 2, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 1, 0, 0, 0, 0},
				{0, 0, 0, 0, 1, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 1, 0, 0, 1, 0},
				{0, 0, 0, 1, 0, 1, 0, 0},
				{0, 0, 0, 1, 1, 0, 0, 0},
				{0, 1, 1, 1, 1, 1, 1, 0},
				{0, 0, 0, 1, 1, 0, 0, 0},
				{0, 0, 0, 1, 0, 1, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 2, 0, 0},
				{0, 0, 0, 0, 2, 0, 0, 0},
				{0, 0, 0, 2, 0, 0, 0, 0},
				{0, 0, 2, 1, 1, 1, 1, 0},
				{0, 0, 2, 0, 0, 0, 0, 0},
				{0, 0, 2, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 1, 0, 0, 0, 0, 0, 0},
				{0, 1, 0, 0, 0, 0, 2, 1},
				{1, 2, 2, 2, 2, 0, 0, 0},
				{0, 0, 1, 0, 0, 0, 0, 0},
				{0, 0, 0, 1, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},
			{   {0, 0, 0, 0, 0, 1, 0, 1},
				{0, 0, 0, 0, 0, 1, 1, 0},
				{0, 0, 0, 0, 0, 1, 0, 0},
				{0, 0, 0, 0, 1, 1, 0, 0},
				{0, 0, 0, 1, 0, 1, 0, 0},
				{0, 0, 2, 0, 0, 2, 0, 0},
				{0, 1, 0, 0, 0, 1, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			}
		};

	int executeturn_player[10]={0,0,0,1,2,0,1,2,2,1};
	int executeturn_pos[10][2]=
				{	
	                {0,0},
					{0,0},
					{0,0},
					{3,4},
					{3,5},
					{0,0},
					{3,4},
					{2,4},
					{1,4},
					{5,2}
				};

	for (int i = 0; i < 10; ++i)
	{
		// TODO: Call the check function
	}


// ---------- CHECK POSSIBLE TURNS ---------- //

	int possibleturns_matrix[2][8][8] {
			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 1, 2, 0, 0, 0},
				{0, 0, 0, 2, 1, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 2, 1, 0, 0, 0},
				{0, 0, 0, 2, 1, 1, 0, 0},
				{0, 0, 0, 2, 1, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			}
		};

	int possibleturns_player[2] = {1, 1};
	int possibleturns_count[2] = {4, 5};

	for (int i = 0; i < 2; ++i)
	{
		// TODO: Call the check function
	}

	return result;
}
