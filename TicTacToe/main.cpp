#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;


bool running = true;
int contents = 0;
int userSizeBoard;
int** board = new int*[userSizeBoard];
int player = -1;

void InitBoard()
{
	cin >> userSizeBoard;

	for (int x = 0; x < userSizeBoard; ++x)
	{
		board[x] = new int[userSizeBoard];

		for (int y = 0; y < userSizeBoard; ++y)
		{
			board[x][y] = x * userSizeBoard + y;
		}
	}
}

void PrintBoard()
{
	for (int x = 0; x < userSizeBoard; ++x)
	{
		for (int y = 0; y < userSizeBoard; ++y)
		{
			cout << "" << (board[x][y] >= 0? std::to_string(board[x][y]+1): board[x][y] == -1? "X":"O") <<" ";
			
		}
		cout << endl;
		if (userSizeBoard - 2 > 0)
		{
			cout << "-------" << endl;
		}
	}
}

bool CheckWin()
{
	bool win = false;
	int rowCounter = 0;
	int colCounter = 0;
	int diaCounter = 0;
	int dia2Counter = 0;
	for (int x = 0; x < userSizeBoard && !win; ++x)
	{
		colCounter = 0;
		rowCounter = 0;
		for (int y = 0; y < userSizeBoard-1; ++y)
		{
			if (board[x][y] == board[x][y+1])
			{
				rowCounter++;
			}

			if (board[y][x] == board[y+1][x])
			{
				colCounter++;
			}

			
		}
		//Only excute diagnol check if x<size-1 due to the loo ahead.
		if (x < userSizeBoard - 1)
		{
			if (board[x][x] == board[x + 1][x + 1])
			{
				diaCounter++;
			}

			if (board[userSizeBoard - x - 1][x] == board[userSizeBoard - x - 2][x + 1])
			{
				dia2Counter++;
			}
		}
		

		if (rowCounter == userSizeBoard - 1 || colCounter == userSizeBoard-1 || diaCounter == userSizeBoard - 1 || dia2Counter == userSizeBoard - 1)
		{
			win = true;
		}
	}

	

	return win;
}

int main()
{
	int currentTurns = userSizeBoard * 2;
	InitBoard();
	int playerInput = 0;
	
	while (running)
	{
		PrintBoard();

		cout << "Player " << (player == -1 ? "1" : "2") << " is your turn!" << endl;;

		cout << "Enter a number to place your " << (player == -1 ? "X" : "O") << ".\n";
		cin >> playerInput;

		playerInput = playerInput - 1;

		board[playerInput / userSizeBoard][playerInput%userSizeBoard] = player;

		bool result = CheckWin();

		if (result == true)
		{
			cout << "Player " << (player == -1 ? "X" : "O") << "wins." << endl;

			running = false;
		}

		player = player == -1 ? player = -2 : player = -1;
	}

	return 0;
}