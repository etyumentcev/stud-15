#include "Header.h"

using namespace std;

map::coordinate zero;  // ������ // ��������� ��������� �������� ��������

void map::create_right_map() // ������� ���������� ����� ���������� �� �������
{
	for (unsigned i = 0; i < SIZE; i++)
	{
		for (unsigned j = 0; j < SIZE; j++)
			right_map[i][j] = right_value++;
	}
	right_map[SIZE - 1][SIZE - 1] = 0; // ������� ������� � ������ ������ ����
}

void map::create_game_map() // �������� ������� ������� �����
{
	vector<int> temporary; // ��������� ������ �� �������� ����� ����� �������� � ������� �����
	for (unsigned i = 0; i < limit; i++)
		temporary.push_back(i);

	for (unsigned i = 0; i < SIZE; i++)
	{
		for (unsigned j = 0; j < SIZE; j++)
		{
			value = rand() % limit--;
			game_map[i][j] = temporary[value];
			if (temporary[value] == 0) // ��������� ���������� �������� ��������
			{
				zero.x = j;
				zero.y = i;
			}
			temporary.erase(temporary.begin() + value);
		}
	}
}

bool map::check_map() // ��������� ������� � ���������� ����� ��� ����������� ����� ����
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

void map::up_move() // ��� ����� (������� ������� ����)
{
	if (zero.y < SIZE - 1)
	{
		game_map[zero.y][zero.x] = game_map[zero.y + 1][zero.x];
		zero.y++;
		game_map[zero.y][zero.x] = 0;
	}
}

void map::down_move() // ��� ���� (������� ������� �����)
{
	if (zero.y > 0)
	{
		game_map[zero.y][zero.x] = game_map[zero.y - 1][zero.x];
		zero.y--;
		game_map[zero.y][zero.x] = 0;
	}
}

void map::right_move() // ��� ������ (������� ������� �����)
{
	if (zero.x > 0)
	{
		game_map[zero.y][zero.x] = game_map[zero.y][zero.x - 1];
		zero.x--;
		game_map[zero.y][zero.x] = 0;
	}
}

void map::left_move() // ��� ����� (������� ������� ������)
{
	if (zero.x < SIZE - 1)
	{
		game_map[zero.y][zero.x] = game_map[zero.y][zero.x + 1];
		zero.x++;
		game_map[zero.y][zero.x] = 0;
	}
}

void map::screen() // ������� ������ �� �����
{
	system("cls");
	for (unsigned i = 0; i < SIZE; i++)
	{
		for (unsigned j = 0; j < SIZE; j++)
		{
			if (game_map[i][j] != 0)
				cout << std::setw(2) << std::setfill('0') << game_map[i][j] << ' ';
			else
				cout << "   "; // ������� �������
		}
		cout << '\n';
	}
}