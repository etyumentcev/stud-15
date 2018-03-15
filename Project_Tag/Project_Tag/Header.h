#ifndef Header_h
#define Header_h
#include <iostream>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include <conio.h>

using namespace std;

class map {
private:
	const unsigned SIZE = 4;
	unsigned right_value = 1;
public:
	map(unsigned, unsigned) {
		vector<int> in_map(SIZE);
		vector<vector<int>> game_map(SIZE, in_map);
		vector<vector<int>> right_map(SIZE, in_map);
	}
	void create_right_map();
	void create_game_map();
	void left_move();
	void right_move();
	void down_move();
	void up_move();
	void screen();
	bool check_map();
	unsigned limit = SIZE * SIZE;
	int value;
	struct coordinate {
		unsigned x;
		unsigned y;
	};
};


#endif  Header_h
