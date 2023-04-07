#include <iostream>
#include "header.hpp"
#include <string>
using namespace std;

Board::Board()
{
	height = 5;
	length = 10;
	map = new char* [height];
	for (int i = 0; i < height; i++)
		map[i] = new char[length];

	for (int i = 0; i < height; i++)
		for (int j = 0; j < length; j++)
		{
			if (i == (height - 1) || i == 0)
				map[i][j] = '-';
			else if (j == 0 || j == (length - 1))
				map[i][j] = '|';
			else
				map[i][j] = ' ';
		}
}

void Board::print()
{
	cout << " ";
	for(int k=1;k<length-1;k++)
		cout << k;
	cout << endl;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < length; j++)
		{
			cout << map[i][j];
		}
		cout << endl;
	}
	cout << " ";
	for (int k = 1; k < length-1; k++)
		cout << k ;
	cout << endl;


	cout << endl;
}

int Board::set_mines()
{
	int num_of_mines = ((height-2) * (length-2)) / 4;
	int tmp = num_of_mines;
	while (num_of_mines)
	{
		int i = rand() % (height - 2) + 1;
		int j = rand() % (length - 2) + 1;
		//cout << i << "-" << j<<endl;
		map[i][j] = '*';
		num_of_mines--;
	}
	return tmp;
}


void Board::check_mines_around()
{
	int num = 0;
	for (int i = 1; i < height - 1; i++)
	{
		for (int j = 1; j < length - 1; j++)
		{
			num = 0;
			if (map[i][j] == '*')
				continue;
			else
			{
				for (int x = i - 1; x < i + 2; x++)
					for (int y = j - 1; y < j + 2; y++)
						if (map[x][y] == '*')
							num++;
			}
			char ch = num + '0';
			map[i][j] = ch;
		}
		cout << endl;
	}
}

bool Board::check_for_mine(int x, int y)
{
	if (map[x][y] == '*')
		return true;
	return false;
}

char Board::check_number(int x, int y)
{
	return map[x][y];
}


bool Board::check_empty(int x, int y)
{
	if (map[x][y] == ' ')
		return true;
	return false;
}

bool Board::game_over()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < length; j++)
		{
			if (map[i][j] == ' ')
				return false;
		}
	}
	return true;
}

void Board::flag_the_mine(int x, int y)
{
	map[x][y] = 'X';
}

void Board::reveal(int* p1, int* p2, char* num)
{
	do
	{
		*p1 = rand() % (height - 2) + 1;
		*p2 = rand() % (length - 2) + 1;
		*num = map[*p1][*p2];
	} while (map[*p1][*p2] == '*');
}

void Board::add_number(int x, int y, char num)
{
	map[x][y] = num;
}

int Board::get_num_of_cells()
{
	return (height - 2) * (length - 2);
}

void Board::get_height_length(int* h, int* l)
{
	*h = height;
	*l = length;
}