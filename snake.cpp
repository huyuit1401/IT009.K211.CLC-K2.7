#include <iostream>
#include <conio.h>
#include <string>
#include <windows.h>
using namespace std;

struct Point {
	int x, y;
	int x0, y0;
};

bool gameover;
bool shutDown;
const int width = 20;
const int height = 20;
int fruitX, fruitY, score;
Point snake[100];
int snakeLength;
enum eDirection { STOP, LEFT, RIGHT, UP, DOWN };
eDirection dir;

void spawnFruit()
{
	fruitX = rand() % width;
	fruitY = rand() % height;
}

void initGame()
{
	gameover = false;
	shutDown = false;
	dir = RIGHT;
	snake[0].x = width / 2;
	snake[0].y = height / 2;
	spawnFruit();
	score = 0;
	snakeLength = 1;
}


void drawSnake()
{
	// Ve ran
}

void changeDir()
{
	if (_kbhit()) {
		switch (_getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'x':
			gameover = true;
			break;
		}
	}
}

void moveSnake()
{
	// Ran di
}

int main()
{
	initGame();
	while (!gameover)
	{
		drawSnake();
		changeDir();
		moveSnake();
		Sleep(100);
	}
	return 0;
}
