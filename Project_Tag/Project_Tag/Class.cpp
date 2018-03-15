#include "Header.h"

using namespace std;

map::coordinate zero;  // объект // хранилище координат нулевого элемента

void map::create_right_map() // создаем правильную карту заполненую по порядку
{
	for (unsigned i = 0; i < SIZE; i++)
	{
		for (unsigned j = 0; j < SIZE; j++)
			right_map[i][j] = right_value++;
	}
	right_map[SIZE - 1][SIZE - 1] = 0; // нулевой элемент в нижний правый угол
}

void map::create_game_map() // рандомно создаем игровую карту
{
	vector<int> temporary; // временный массив из которого будем брать значения в игровую карту
	for (unsigned i = 0; i < limit; i++)
		temporary.push_back(i);

	for (unsigned i = 0; i < SIZE; i++)
	{
		for (unsigned j = 0; j < SIZE; j++)
		{
			value = rand() % limit--;
			game_map[i][j] = temporary[value];
			if (temporary[value] == 0) // сохраняем координаты нулевого элемента
			{
				zero.x = j;
				zero.y = i;
			}
			temporary.erase(temporary.begin() + value);
		}
	}
}

bool map::check_map() // сравнение игровой и правильной карты для определения конца игры
{
	if (game_map == right_map)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void map::up_move() // ход вверх (нулевой элемент вниз)
{
	if (zero.y < SIZE - 1)
	{
		game_map[zero.y][zero.x] = game_map[zero.y + 1][zero.x];
		zero.y++;
		game_map[zero.y][zero.x] = 0;
	}
}

void map::down_move() // ход вниз (нулевой элемент вверх)
{
	if (zero.y > 0)
	{
		game_map[zero.y][zero.x] = game_map[zero.y - 1][zero.x];
		zero.y--;
		game_map[zero.y][zero.x] = 0;
	}
}

void map::right_move() // ход вправо (нулевой элемент влево)
{
	if (zero.x > 0)
	{
		game_map[zero.y][zero.x] = game_map[zero.y][zero.x - 1];
		zero.x--;
		game_map[zero.y][zero.x] = 0;
	}
}

void map::left_move() // ход влево (нулевой элемент вправо)
{
	if (zero.x < SIZE - 1)
	{
		game_map[zero.y][zero.x] = game_map[zero.y][zero.x + 1];
		zero.x++;
		game_map[zero.y][zero.x] = 0;
	}
}

void map::screen() // выводим массив на экран
{
	system("cls");
	for (unsigned i = 0; i < SIZE; i++)
	{
		for (unsigned j = 0; j < SIZE; j++)
		{
			if (game_map[i][j] != 0)
				cout << std::setw(2) << std::setfill('0') << game_map[i][j] << ' ';
			else
				cout << "   "; // нулевой элемент
		}
		cout << '\n';
	}
}