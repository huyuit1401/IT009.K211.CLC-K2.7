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
	// Tao thuc an
}

void initGame()
{
	// Khoi tao game
}


void drawSnake()
{
	// Ve ran
}

void changeDir()
{
	// Doi huong di
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