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
	system("cls");
	for (int i = 0; i < width + 2; i++) {
		cout << "#";
	}
	cout << endl;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0)
				cout << "#";

			if (i == snake[0].y && j == snake[0].x)
				cout << "O";

			else if (i == fruitY && j == fruitX)
				cout << "F";

			else {
				bool print = false;
				for (int k = 1; k < snakeLength; k++) {
					if (snake[k].x == j && snake[k].y == i) {
						cout << "o";
						print = true;
					}
				}
				if (!print)
					cout << " ";
			}

			if (j == width - 1)
				cout << "#";
		}
		cout << endl;
	}
	for (int i = 0; i < width + 2; i++) {
		cout << "#";
	}
	cout << endl;
	cout << "Score: " << score << endl;
	
	//Show moving guide
	cout << "\n|MOVING GUIDE|\n";
	cout << "W: move up\n";
	cout << "A: move left\n";
	cout << "S: move down\n";
	cout << "D: move right\n";
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
	for (int i = 0; i < snakeLength; i++) {
			if (i == 0) {
				snake[0].x0 = snake[0].x; snake[0].y0 = snake[0].y;
			}
			else
			{
				snake[i].x0 = snake[i].x; snake[i].y0 = snake[i].y;
				snake[i].x = snake[i - 1].x0; snake[i].y = snake[i - 1].y0;
			}
	}

	switch (dir)
	{
	case LEFT:
		snake[0].x--;
		break;
	case RIGHT:
		snake[0].x++;
		break;
	case UP:
		snake[0].y--;
		break;
	case DOWN:
		snake[0].y++;
		break;
	}
	if (snake[0].x > width || snake[0].x < 0 || snake[0].y > height || snake[0].y < 0) {
		gameover = true;
		initGame();
	}

	for (int i = 1; i < snakeLength; i++) {
		if (snake[i].x == snake[0].x && snake[i].y == snake[0].y)
			gameover = true;
	}

	if (snake[0].x == fruitX && snake[0].y == fruitY) {
		score++;
		snakeLength++;
		spawnFruit();
	}
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
