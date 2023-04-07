class Board
{
	int height;
	int length;
	char** map;
public:
	Board();
	void print();
	int set_mines();
	void check_mines_around();
	bool check_for_mine(int x, int y);
	char check_number(int x, int y);
	void add_number(int x,int y,char num);
	bool check_empty(int x, int y);
	bool game_over();
	void flag_the_mine(int x, int y);
	void reveal(int* p1, int* p2, char* num);
	int get_num_of_cells();
	void get_height_length(int* h, int* l);
};

