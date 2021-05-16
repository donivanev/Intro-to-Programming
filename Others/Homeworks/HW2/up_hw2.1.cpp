#include <iostream>
using namespace std;

int min(int row, int col)
{
	return row < col ? row : col;
}

void initilizeMatrix(int rows, int cols, char arr[][40])
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			arr[i][j] = ' ';
		}
	}
}

void printMatrix(int rows, int cols, char arr[][40])
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			cout << "|";
			cout << arr[i][j];
		}
		cout << "|\n";
	}
}

void rowWin(char arr[][40], int rows, int cols, int counter, bool& flag1, bool& flag2)
{
	int player1Counter = 1, player2Counter = 1;
	bool player1Win = false, player2Win = false;

	for (int i = rows - 1; i >= 0; i--)
	{
		for (int j = 0; j < cols; j++)
		{
			if (counter % 2 == 0)
			{
				if (arr[i][j] == 'O')
				{
					if (player1Counter == 4)
					{
						player1Win = true;
						break;
					}
					player1Counter++;
				}
			}
			else
			{
				if (arr[i][j] == 'X')
				{
					if (player2Counter == 4)
					{
						player2Win = true;
						break;
					}
					player2Counter++;
				}
			}
		}
		if (player1Win || player2Win)
		{
			break;
		}
		player1Counter = 1;
		player2Counter = 1;
	}

	if (player1Counter == 4 && player1Win)
	{
		cout << "Player 1 wins!";
		flag1 = true;
	}
	else if (player2Counter == 4 && player2Win)
	{
		cout << "Player 2 wins!";
		flag2 = true;
	}
}

void colWin(char arr[][40], int rows, int cols, int counter, bool& flag1, bool& flag2)
{
	int player1Counter = 1, player2Counter = 1;
	bool player1Win = false, player2Win = false;

	for (int j = 0; j < cols; j++)
	{
		for (int i = rows - 1; i >= 0; i--)
		{
			if (counter % 2 == 0)
			{
				if (arr[i][j] == 'O')
				{
					if (player1Counter == 4)
					{
						player1Win = true;
						break;
					}
					player1Counter++;
				}
				else if (arr[i][j] == 'X')
				{
					player1Counter = 1;
				}
			}
			else
			{
				if (arr[i][j] == 'X')
				{
					if (player2Counter == 4)
					{
						player2Win = true;
						break;
					}
					player2Counter++;
				}
				else if (arr[i][j] == 'O')
				{
					player2Counter = 1;
				}
			}
		}
		if (player1Win || player2Win)
		{
			break;
		}
		player1Counter = 1;
		player2Counter = 1;
	}

	if (player1Counter == 4 && player1Win)
	{
		cout << "Player 1 wins!";
		flag1 = true;
	}
	else if (player2Counter == 4 && player2Win)
	{
		cout << "Player 2 wins!";
		flag2 = true;
	}
}

void diagonalWin(char arr[][40], int rows, int cols, int counter, bool& flag1, bool& flag2)
{
	int player1Counter = 1, player2Counter = 1;
	bool player1Win = false, player2Win = false;
	int minDiagonal = min(rows, cols);

	for (int i = 0; i < rows; i++)
	{
		int row = 0, col = i;
		while (col >= 0)
		{
			if (row > rows)
			{
				break;
			}
			if (counter % 2 == 0)
			{
				if (arr[row][col] == 'O')
				{
					if (player1Counter == 4)
					{
						player1Win = true;
						break;
					}
					player1Counter++;
				}
				else if (arr[row][col] == 'X')
				{
					player1Counter = 1;
				}
			}
			else
			{
				if (arr[row][col] == 'X')
				{
					if (player2Counter == 4)
					{
						player2Win = true;
						break;
					}
					player2Counter++;
				}
				else if (arr[row][col] == 'O')
				{
					player2Counter = 1;
				}
			}
			row++;
			col--;
		}
		if (player1Counter == 4 || player2Counter == 4)
		{
			break;
		}
		player1Counter = 1;
		player2Counter = 1;
	}

	if (player1Counter == 4 && player1Win)
	{
		cout << "Player 1 wins!";
		flag1 = true;
	}
	else if (player2Counter == 4 && player2Win)
	{
		cout << "Player 2 wins!";
		flag2 = true;
	}

	player1Counter = 1;
	player2Counter = 1;

	for (int j = 1; j < rows; j++)
	{
		int col = rows - 1, row = j;
		while (row < rows)
		{
			if (counter % 2 == 0)
			{
				if (arr[row][col] == 'O')
				{
					if (player1Counter == 4)
					{
						player1Win = true;
						break;
					}
					player1Counter++;
				}
				else if (arr[row][col] == 'X')
				{
					player1Counter = 1;
				}
			}
			else
			{
				if (arr[row][col] == 'X')
				{
					if (player2Counter == 4)
					{
						player2Win = true;
						break;
					}
					player2Counter++;
				}
				else if (arr[row][col] == 'O')
				{
					player2Counter = 1;
				}
			}
			row++;
			col--;
		}
		if (player1Counter == 4 || player2Counter == 4)
		{
			break;
		}
		player1Counter = 1;
		player2Counter = 1;
	}

	if (player1Counter == 4 && player1Win)
	{
		cout << "Player 1 wins!";
		flag1 = true;
	}
	else if (player2Counter == 4 && player2Win)
	{
		cout << "Player 2 wins!";
		flag2 = true;
	}

	player1Counter = 1;
	player2Counter = 1;

	//other diagonal

	for (int i = 0; i < rows; i++)
	{
		int row = rows - 1, col = i;
		while (col >= 0)
		{
			if (row > rows)
			{
				break;
			}
			if (counter % 2 == 0)
			{
				if (arr[row][col] == 'O')
				{
					if (player1Counter == 4)
					{
						player1Win = true;
						break;
					}
					player1Counter++;
				}
				else if (arr[row][col] == 'X')
				{
					player1Counter = 1;
				}
			}
			else
			{
				if (arr[row][col] == 'X')
				{
					if (player2Counter == 4)
					{
						player2Win = true;
						break;
					}
					player2Counter++;
				}
				else if (arr[row][col] == 'O')
				{
					player2Counter = 1;
				}
			}
			row--;
			col--;
		}
		if (player1Counter == 4 || player2Counter == 4)
		{
			break;
		}
		player1Counter = 1;
		player2Counter = 1;
	}

	if (player1Counter == 4 && player1Win)
	{
		cout << "Player 1 wins!";
		flag1 = true;
	}
	else if (player2Counter == 4 && player2Win)
	{
		cout << "Player 2 wins!";
		flag2 = true;
	}

	player1Counter = 1;
	player2Counter = 1;

	for (int j = 1; j < rows; j++)
	{
		int col = rows - 1, row = rows - j - 1;
		while (row >= 0)
		{
			if (row > rows)
			{
				cout << "in";
				break;
			}
			if (counter % 2 == 0)
			{
				if (arr[row][col] == 'O')
				{
					if (player1Counter == 4)
					{
						player1Win = true;
						break;
					}
					player1Counter++;
				}
				else if (arr[row][col] == 'X')
				{
					player1Counter = 1;
				}
			}
			else
			{
				if (arr[row][col] == 'X')
				{
					if (player2Counter == 4)
					{
						player2Win = true;
						break;
					}
					player2Counter++;
				}
				else if (arr[row][col] == 'O')
				{
					player2Counter = 1;
				}
			}
			row--;
			col--;
		}
		if (player1Counter == 4 || player2Counter == 4)
		{
			break;
		}
		player1Counter = 1;
		player2Counter = 1;
	}

	if (player1Counter == 4 && player1Win)
	{
		cout << "Player 1 wins!";
		flag1 = true;
	}
	else if (player2Counter == 4 && player2Win)
	{
		cout << "Player 2 wins!";
		flag2 = true;
	}
}

void processTurn(int playerTurn, bool end, int rows, int cols, char arr[][40], int counter)
{
	if (playerTurn > rows || playerTurn > cols)
	{
		cout << "Invalid input. Please enter a number in the bounds of the table." << endl;
	}

	bool endTurn = false;

	for (int i = rows - 1; i >= 0; i--)
	{
		for (int j = 0; j < cols; j++)
		{
			if (arr[i][playerTurn - 1] == ' ')
			{
				counter % 2 == 0 ? arr[i][playerTurn - 1] = 'O' : arr[i][playerTurn - 1] = 'X';
				endTurn = true;
			}
		}
		if (endTurn)
		{
			break;
		}
	}
}

bool isDraw(char arr[][40], int rows, int cols)
{
	bool draw = true;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (arr[i][j] == ' ')
			{
				draw = false;
			}
		}
	}

	return draw;
}

int main()
{
	const unsigned MAX_ROWS = 20, MAX_COLS = 40;
	unsigned n, m, player1Turn, player2Turn, counter = 0;
	bool end = false, flag1 = false, flag2 = false, draw = false;
	char arr[MAX_ROWS][MAX_COLS];

	do
	{

		cin >> n >> m;

	} while (!((n > 3 && n < 20) && (m > 3 && m < 40)));

	initilizeMatrix(n, m, arr);
	printMatrix(n, m, arr);

	while (end != true)
	{
		if (isDraw(arr, n, m))
		{
			cout << "Draw!";
			break;
		}
		if (counter % 2 == 0)
		{
			cin >> player1Turn;
			processTurn(player1Turn, end, n, m, arr, counter);
			printMatrix(n, m, arr);
			rowWin(arr, n, m, counter, flag1, flag2);

			if (flag1) break;
			if (flag2) break;

			flag1 = false, flag2 = false;

			colWin(arr, n, m, counter, flag1, flag2);

			if (flag1) break;
			if (flag2) break;

			flag1 = false, flag2 = false;

			diagonalWin(arr, n, m, counter, flag1, flag2);

			if (flag1) break;
			if (flag2) break;

			flag1 = false, flag2 = false;
		}
		else
		{
			cin >> player2Turn;
			processTurn(player2Turn, end, n, m, arr, counter);
			printMatrix(n, m, arr);
			rowWin(arr, n, m, counter, flag1, flag2);

			if (flag1) break;
			if (flag2) break;

			flag1 = false, flag2 = false;

			colWin(arr, n, m, counter, flag1, flag2);

			if (flag1) break;
			if (flag2) break;

			flag1 = false, flag2 = false;

			diagonalWin(arr, n, m, counter, flag1, flag2);

			if (flag1) break;
			if (flag2) break;

			flag1 = false, flag2 = false;
		}

		counter++;
	}

	return 0;
}