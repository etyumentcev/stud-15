#include "Header.h"

int main()
{
	map objmap(4,4);
	srand(static_cast<int>(time(NULL)));

	objmap.create_right_map(); // создание игровых карт
	do
	{
		objmap.create_game_map();
	} while (objmap.check_map());

	objmap.screen();
	_getch();
}