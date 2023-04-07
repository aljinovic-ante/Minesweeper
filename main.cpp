#include <iostream>
#include "header.hpp"
#include <string>
using namespace std;

int main()
{
	srand(time(0));

	Board game_board;
	Board mine_board;

	int h, l;
	mine_board.get_height_length(&h, &l);
	int num_of_mines=mine_board.set_mines();
	mine_board.check_mines_around();
	int mines = game_board.get_num_of_cells() / 3;
	//cout << mines << endl;

	while (mines)
	{
		int p1, p2;
		char n;
		mine_board.reveal(&p1, &p2, &n);
		//cout << p1 << p2 << n << endl;
		if (game_board.check_empty(p1, p2))
		{
			game_board.add_number(p1, p2, n);
			mines--;
		}
	}
	while (true)
	{
		int x, y;
		game_board.print();

		while (1)
		{
			cout << "Pick a row [1-"<<h - 2 <<"]!" << endl;
			cin >> x;
			if (cin.fail())
			{
				cin.clear(); // deletes error flag that cin.fail creates
				cin.ignore(10000, '\n'); // ignores next 10000 lines in buffer but stops when comes to \n
				cout << "Wrong input! Try again: " << endl;
				continue;
			}
			cout << "Pick a column [1-"<< l - 2 <<"]!" << endl;
			cin >> y;
			if (cin.fail())
			{
				cin.clear(); // deletes error flag that cin.fail creates
				cin.ignore(10000, '\n'); // ignores next 10000 lines in buffer but stops when comes to \n
				cout << "Wrong input! Try again: " << endl;
				continue;
			}
			if (x < 1 || x>10 || y < 1 || y>21)
			{
				cout << "Cell out of range! Pick a cell between x:[1-"<< h - 2 <<"],y:[1-"<< l - 2 <<"]!" << endl;
				continue;
			}
			
			if (game_board.check_empty(x, y))
				break;
			cout << "Cell full! Pick another cell!" << endl;;
		}
		char status='N';
		while (1 && num_of_mines)
		{
			cout << "You have " << num_of_mines << " flags left!" << endl;
			cout << "Do you want to flag the mine? Press Y for yes or N for no.\n[Be careful! Once you flag the mine you wont be able to remove the flag!]" << endl;
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clears input buffer
			cin >> status;
			status = toupper(status);
			if (cin.fail())
			{
				cin.clear(); //deletes error flag that cin.fail made
				cout << "Wrong input! Try again: " << endl;
				continue;
			}
			if (status != 'Y' && status != 'N') 
			{
				cout << "Wrong input! Try again: " << endl;
				continue;
			}
			if(status == 'Y')
				num_of_mines--;
			break;
		}
		if (status == 'Y')
		{
			game_board.flag_the_mine(x, y);
		}
		else if (mine_board.check_for_mine(x, y))
		{
			cout << endl;
			cout << "Mine! You lost!"<<endl;
			cout << "Board revealed: "<<endl;
			cout << endl;

			mine_board.print();
			break;
		}
		else
		{
			char num = mine_board.check_number(x, y);
			game_board.add_number(x, y, num);
		}
		if (game_board.game_over())
		{
			cout << endl;
			cout << "You won! Board revealed: " << endl;
			game_board.print();
			cout << endl;
			break;
		}
	}
}
