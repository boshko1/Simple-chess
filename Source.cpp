#include<iostream>
#include <stdlib.h> 
#include<iomanip>
using namespace std;

void RandomPositions(int& CompKingX, int& CompKingY, int& KingX, int& KingY, int& Rook1X, int& Rook1Y, int& Rook2X, int& Rook2Y, int& BoardSize)
{
	CompKingX = rand() % BoardSize;
	CompKingY = rand() % BoardSize;

	KingX = rand() % BoardSize;
	KingY = rand() % BoardSize;

	while ((KingX == CompKingX && KingY == CompKingY) || (KingX == CompKingX + 1) || (KingX == CompKingX - 1) || (KingY == CompKingY + 1) || (KingY == CompKingY - 1) || (KingY == CompKingY + 1 && KingX == CompKingX + 1) || (KingY == CompKingY + 1 && KingX == CompKingX - 1) || (KingY == CompKingY - 1 && KingX == CompKingX - 1) || (KingY == CompKingY - 1 && KingX == CompKingX + 1))
	{
		KingX = rand() % BoardSize;
		KingY = rand() % BoardSize;
	}

	Rook1X = rand() % BoardSize;
	Rook1Y = rand() % BoardSize;

	while ((Rook1X == CompKingX && Rook1Y == CompKingY) || (Rook1X == KingX && Rook1Y == KingY) || (Rook1X == CompKingX) || (Rook1Y == CompKingY))
	{
		Rook1X = rand() % BoardSize;
		Rook1Y = rand() % BoardSize;
	}

	Rook2X = rand() % BoardSize;
	Rook2Y = rand() % BoardSize;

	while ((Rook2X == CompKingX && Rook2Y == CompKingY) || (Rook2X == KingX && Rook2Y == KingY) || (Rook2X == Rook1X && Rook2Y == Rook1Y) || (Rook2X == CompKingX) || (Rook2Y == CompKingY))
	{
		Rook2X = rand() % BoardSize;
		Rook2Y = rand() % BoardSize;
	}
}

void BoardPrint(int size, int CompKingX, int CompKingY, int KingX, int KingY, int Rook1X, int Rook1Y, int Rook2X, int Rook2Y)
{
	system("CLS");

	cout << "  " << " ";
	for (int i = 0; i < size; i++)
		cout << setw(2) << i << " ";

	cout << endl;

	for (int i = 0; i < size; i++)
	{
		cout << setw(2) << char(i + 97) << " ";
		for (int a = 0; a < size; a++)
		{
			if (a == CompKingX && i == CompKingY)
			{
				cout << setw(2) << "P" << " ";
				continue;
			}
			else if (a == KingX && i == KingY)
			{
				cout << setw(2) << "K" << " ";
				continue;
			}
			else if (a == Rook1X && i == Rook1Y)
			{
				cout << setw(2) << 1 << " ";
				continue;
			}
			else if (a == Rook2X && i == Rook2Y)
			{
				cout << setw(2) << 2 << " ";
				continue;
			}
			cout << setw(2) << "_" << " ";
		}
		cout << endl;
	}
}

void CompKingMove(int BoardSize, int& CompKingX, int& CompKingY, int KingX, int KingY, int Rook1X, int Rook1Y, int Rook2X, int Rook2Y, bool& end)
{
	if (CompKingX + 1 != Rook1X && CompKingY != Rook1Y && CompKingX + 1 != Rook2X && CompKingY != Rook2Y && CompKingX + 1 != BoardSize && CompKingX + 2 != KingX && CompKingY != KingY && CompKingX + 2 != KingX && CompKingY + 1 != KingY && CompKingX + 2 != KingX && CompKingY - 1 != KingY)
		CompKingX++;
	else if (CompKingX + 1 != Rook1X && CompKingY + 1 != Rook1Y && CompKingX + 1 != Rook2X && CompKingY + 1 != Rook2Y && CompKingX + 1 != BoardSize && CompKingY + 1 != BoardSize && CompKingX + 2 != KingX && CompKingY != KingY && CompKingX + 2 != KingX && CompKingY + 1 != KingY && CompKingX + 2 != KingX && CompKingY + 2 != KingY && CompKingX + 1 != KingX && CompKingY + 2 != KingY && CompKingX != KingX && CompKingY + 2 != KingY)
	{
		CompKingX++;
		CompKingY++;
	}
	else if (CompKingX != Rook1X && CompKingY + 1 != Rook1Y && CompKingX != Rook2X && CompKingY + 1 != Rook2Y && CompKingY + 1 != BoardSize && CompKingX + 1 != KingX && CompKingY + 2 != KingY && CompKingX != KingX && CompKingY + 2 != KingY && CompKingX - 1 != KingX && CompKingY + 2 != KingY)
		CompKingY++;
	else if (CompKingX - 1 != Rook1X && CompKingY + 1 != Rook1Y && CompKingX - 1 != Rook2X && CompKingY + 1 != Rook2Y && CompKingX - 1 >= 0 && CompKingY + 1 != BoardSize && CompKingX - 2 != KingX && CompKingY != KingY && CompKingX - 2 != KingX && CompKingY + 1 != KingY && CompKingX - 2 != KingX && CompKingY + 2 != KingY && CompKingX - 1 != KingX && CompKingY + 2 != KingY && CompKingX != KingX && CompKingY + 2 != KingY)
	{
		CompKingX--;
		CompKingY++;
	}
	else if (CompKingX - 1 != Rook1X && CompKingY != Rook1Y && CompKingX - 1 != Rook2X && CompKingY != Rook2Y && CompKingX - 1 >= 0 && CompKingX - 2 != KingX && CompKingY != KingY && CompKingX - 2 != KingX && CompKingY + 1 != KingY && CompKingX - 2 != KingX && CompKingY - 1 != KingY)
		CompKingX--;
	else if (CompKingX - 1 != Rook1X && CompKingY - 1 != Rook1Y && CompKingX - 1 != Rook2X && CompKingY - 1 != Rook2Y && CompKingX - 1 >= 0 && CompKingY - 1 >= 0 && CompKingX - 2 != KingX && CompKingY != KingY && CompKingX - 2 != KingX && CompKingY - 1 != KingY && CompKingX - 2 != KingX && CompKingY - 2 != KingY && CompKingX - 1 != KingX && CompKingY - 2 != KingY && CompKingX != KingX && CompKingY - 2 != KingY)
	{
		CompKingX--;
		CompKingY--;
	}
	else if (CompKingX != Rook1X && CompKingY - 1 != Rook1Y && CompKingX != Rook2X && CompKingY - 1 != Rook2Y && CompKingY - 1 >= 0 && CompKingX + 1 != KingX && CompKingY - 2 != KingY && CompKingX != KingX && CompKingY - 2 != KingY && CompKingX - 1 != KingX && CompKingY - 2 != KingY)
		CompKingY--;
	else if (CompKingX + 1 != Rook1X && CompKingY - 1 != Rook1Y && CompKingX + 1 != Rook2X && CompKingY - 1 != Rook2Y && CompKingX + 1 != BoardSize && CompKingY - 1 >= 0 && CompKingX + 2 != KingX && CompKingY != KingY && CompKingX + 2 != KingX && CompKingY - 1 != KingY && CompKingX + 2 != KingX && CompKingY - 2 != KingY && CompKingX + 1 != KingX && CompKingY - 2 != KingY && CompKingX != KingX && CompKingY - 2 != KingY)
	{
		CompKingX++;
		CompKingY--;
	}
	else
		end = 1;
}

int MovesCounter = 1;
void turn(int BoardSize, int CompKingX, int CompKingY, int& KingX, int& KingY, int& Rook1X, int& Rook1Y, int& Rook2X, int& Rook2Y)
{
	char Y, Figure;
	int X;
	bool GameHasEnded = 0;

back:
	cin >> Figure >> Y >> X;

	while (!GameHasEnded)
	{
		if ((Figure != '1') && (Figure != 'K') && (Figure != '2'))
		{
			cout << "Invalid figure! Please try again: ";
			goto back;
		}
		if (Figure == 'K')
		{
			while (X > KingX + 1 || X<KingX - 1 || int(Y - 97)>KingY + 1 || int(Y - 97) < KingY - 1 || (X == Rook1X && int(Y - 97) == Rook1Y) || (X == Rook2X && int(Y - 97) == Rook2Y) || X >= BoardSize || int(Y - 97) >= BoardSize || X < 0 || int(Y - 97) < 0 || (X == CompKingX + 1 && int(Y - 97) == CompKingY) || (X == CompKingX + 1 && int(Y - 97) == CompKingY - 1) || (X == CompKingX && int(Y - 97) == CompKingY - 1) || (X == CompKingX - 1 && int(Y - 97) == CompKingY - 1) || (X == CompKingX - 1 && int(Y - 97) == CompKingY) || (X == CompKingX - 1 && int(Y - 97) == CompKingY + 1) || (X == CompKingX && int(Y - 97) == CompKingY + 1) || (X == CompKingX + 1 && int(Y - 97) == CompKingY + 1))
			{
				cout << endl;
				cout << "Invalid move! Please try again: ";
				goto back;
			}
			system("CLS");

			KingX = X;
			KingY = int(Y - 97);

			CompKingMove(BoardSize, CompKingX, CompKingY, KingX, KingY, Rook1X, Rook1Y, Rook2X, Rook2Y, GameHasEnded);
			BoardPrint(BoardSize, CompKingX, CompKingY, KingX, KingY, Rook1X, Rook1Y, Rook2X, Rook2Y);
		}
		if (Figure == '1')
		{
			while ((Rook1X != X && Rook1Y != int(Y - 97)) || (X == KingX && int(Y - 97) == KingY) || (X == Rook2X && int(Y - 97) == Rook2Y) || (X == CompKingX && int(Y - 97) == CompKingY) || X >= BoardSize || int(Y - 97) >= BoardSize || X < 0 || int(Y - 97) < 0)
			{
			invalid:
				cout << endl;
				cout << "Invalid move! Please try again: ";
				goto back;
			}
			if (Rook1Y == Rook2Y || Rook1Y == KingY || Rook1Y == CompKingY)
			{
				if (Rook1Y == Rook2Y)
				{
					if (Rook1X > Rook2X)
					{
						if (X < Rook2X)
							goto invalid;
					}
					else
						if (X > Rook2X)
							goto invalid;
				}
				else if (Rook1Y == KingY)
				{
					if (Rook1X > KingX)
					{
						if (X < KingX)
							goto invalid;
					}
					else
						if (X > KingX)
							goto invalid;
				}
			}
			if (Rook1X == Rook2X || Rook1X == KingX || Rook1X == CompKingY)
			{
				if (Rook1X == Rook2X)
				{
					if (Rook1Y > Rook2Y)
					{
						if (int(Y - 97) < KingY)
							goto invalid;
					}
					else
						if (int(Y - 97) > Rook2Y)
							goto invalid;
				}
				if (Rook1X == KingX)
				{
					if (Rook1Y > KingY)
					{
						if (int(Y - 97) < KingY)
							goto invalid;
					}
					else
						if (int(Y - 97) > KingY)
							goto invalid;
				}
			}
			system("CLS");

			Rook1X = X;
			Rook1Y = int(Y - 97);

			CompKingMove(BoardSize, CompKingX, CompKingY, KingX, KingY, Rook1X, Rook1Y, Rook2X, Rook2Y, GameHasEnded);

			if (GameHasEnded)
			{
				cout << "You won with " << MovesCounter << " moves!";
				return;
			}
			BoardPrint(BoardSize, CompKingX, CompKingY, KingX, KingY, Rook1X, Rook1Y, Rook2X, Rook2Y);
		}
		if (Figure == '2')
		{
			while ((Rook2X != X && Rook2Y != int(Y - 97)) || (X == Rook1X && int(Y - 97) == Rook1Y) || (X == KingX && int(Y - 97) == KingY) || (X == CompKingX && int(Y - 97) == CompKingY) || X >= BoardSize || int(Y - 97) >= BoardSize || X < 0 || int(Y - 97) < 0)
			{
				cout << endl;
				cout << "Invalid move! Please try again: ";
				goto back;
			}
			if (Rook2Y == Rook1Y || Rook2Y == KingY || Rook2Y == CompKingY)
			{
				if (Rook2Y == Rook1Y)
				{
					if (Rook2X > Rook1X)
					{
						if (X < Rook1X)
							goto invalid;
					}
					else
						if (X > Rook1X)
							goto invalid;
				}
				else if (Rook1Y == KingY)
				{
					if (Rook2X > KingX)
					{
						if (X < KingX)
							goto invalid;
					}
					else
						if (X > KingX)
							goto invalid;
				}
			}
			if (Rook2X == Rook1X || Rook2X == KingX || Rook2X == CompKingY)
			{
				if (Rook1X == Rook2X)
				{
					if (Rook2Y > Rook1Y)
					{
						if (int(Y - 97) < Rook1Y)
							goto invalid;
					}
					else
						if (int(Y - 97) > Rook2Y)
							goto invalid;
				}
				if (Rook2X == KingX)
				{
					if (Rook2Y > KingY)
					{
						if (int(Y - 97) < KingY)
							goto invalid;
					}
					else
						if (int(Y - 97) > KingY)
							goto invalid;
				}
			}
			system("CLS");

			Rook2X = X;
			Rook2Y = int(Y - 97);

			CompKingMove(BoardSize, CompKingX, CompKingY, KingX, KingY, Rook1X, Rook1Y, Rook2X, Rook2Y, GameHasEnded);

			if (GameHasEnded)
			{
				cout << "You won with " << MovesCounter << " moves!";
				return;
			}
			BoardPrint(BoardSize, CompKingX, CompKingY, KingX, KingY, Rook1X, Rook1Y, Rook2X, Rook2Y);
		}
		MovesCounter++;
		cin >> Figure >> Y >> X;
	}
}

int main()
{
	for (int i = 1; i > 0; i++)
	{
		if (i > 1)
			cout << endl << endl;

		cout << "To start a new game enter  (1)" << endl;
		cout << "To change the size of the board enter (2) (The default board size is 8x8)" << endl;
		cout << "For exit enter (3)" << endl << endl;

		int MenuChoice, BoardSize = 8;
		cin >> MenuChoice;
		cout << endl;

		while (MenuChoice != 1 && MenuChoice != 2 && MenuChoice != 3)
		{
			cout << "Invalid choice! Please select again." << endl;
			cin >> MenuChoice;
		}

		srand(time(NULL));
		int CompKingX, CompKingY, KingX, KingY, Rook1X, Rook1Y, Rook2X, Rook2Y;

		if (MenuChoice == 1)
		{
			RandomPositions(CompKingX, CompKingY, KingX, KingY, Rook1X, Rook1Y, Rook2X, Rook2Y, BoardSize);

			BoardPrint(BoardSize, CompKingX, CompKingY, KingX, KingY, Rook1X, Rook1Y, Rook2X, Rook2Y);

			turn(BoardSize, CompKingX, CompKingY, KingX, KingY, Rook1X, Rook1Y, Rook2X, Rook2Y);
		}
		else if (MenuChoice == 2)
		{
			cout << "Please enter the new board size: ";
		back2:
			cin >> BoardSize;
			while (BoardSize > 26)
			{
				cout << "Board size too large! Please enter a new value: ";
				goto back2;
			}
			while (BoardSize < 3)
			{
				cout << "Board size too small! Please enter a new value: ";
				goto back2;
			}

			RandomPositions(CompKingX, CompKingY, KingX, KingY, Rook1X, Rook1Y, Rook2X, Rook2Y, BoardSize);

			BoardPrint(BoardSize, CompKingX, CompKingY, KingX, KingY, Rook1X, Rook1Y, Rook2X, Rook2Y);

			turn(BoardSize, CompKingX, CompKingY, KingX, KingY, Rook1X, Rook1Y, Rook2X, Rook2Y);
		}
		else if (MenuChoice == 3)
			return 0;
	}

	return 0;
}