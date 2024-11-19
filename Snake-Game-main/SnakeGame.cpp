#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <ctime>
#include <cstdlib>
#include <conio.h>

using namespace std;

enum eDirention {STOP, LEFT, RIGHT, DOWN, UP};
eDirention dir;
bool gameOver = false;
const int windowHeight = 20;
const int windowWidth = 35;
int speedY = 1, speedX = 1;
int tailX[100], tailY[100];
int nTail;
int score = 0;

class Player
{
public:
	
	int orignal_snake_posY = windowHeight / 2;
	int orignal_snake_posX = windowWidth / 2;
	int snake_posY = orignal_snake_posY;
	int snake_posX = orignal_snake_posX;

	int ballY = 0;
	int ballX = 0;

	Player() {
		srand(static_cast<unsigned int>(time(0)));
		RandomValueGenerator();
	}
	void RandomValueGenerator()
	{
		srand((unsigned)time(NULL));
		ballY = rand() % windowHeight;
		ballX = rand() % windowWidth;
	}

	void boarder()
	{
		system("cls");
		for (int i = 0; i < windowWidth; ++i)
		{
			cout << "\xB2";
		}
		cout << endl;
		for (int i = 0; i < windowHeight; ++i)
		{
			for (int j = 0; j < windowWidth; ++j)
			{

				if (i == ballY && j == ballX)
				{
					cout << "F";
				}
				if (i == snake_posY && j == snake_posX)
				{
					cout << "O";
				}
				if (j == 0 || j == windowWidth - 1)
				{
					cout << "\xB2";
				}
				else {
					bool print = false;
					for (int k = 0; k < nTail; k++)
					{
						
						if (tailX[k] == j && tailY[k] == i)
						{
							cout << "o";
							print = true;
						}
					}
					if (!print)
					{
						cout << " ";
					}
				}
			}
			cout << endl;
		}

		for (int i = 0; i < windowWidth; ++i)
		{
			cout << "\xB2";
		}
		cout << endl;
		cout << "Score: " << score << endl;
	}
	void through_wall()
	{
		if (snake_posY >= windowHeight)
		{
			snake_posY = 0;
		}
		else if (snake_posY <= 0)
		{
			snake_posY = windowHeight;
		}
		if (snake_posX <= 0)
		{
			snake_posX = windowWidth;
		}
		else if (snake_posX >= windowWidth)
		{
			snake_posX = 0;
		}
	}

	void colision()
	{
		if (snake_posX <= 0 || snake_posX >= windowWidth - 1)
		{
			gameOver = true;
		}
		if (snake_posY <= 0 || snake_posY >= windowHeight)
		{
			gameOver = true;
		}
	}

	void snake_ball_colision()
	{
		if (ballX == snake_posX && ballY == snake_posY)
		{
			score++;
			RandomValueGenerator();
			nTail++;
		}
	}

	void snake_Tail()
	{
		for (int i = 0; i < nTail; i++)
		{
			if (tailX[i] == snake_posX && tailY[i] == snake_posY)
			{
				gameOver = true;
			}
		}
	}

	void direction()
	{
		int prevX = tailX[0];
		int prevY = tailY[0];
		int prev2X, prev2Y;
		tailX[0] = snake_posX;
		tailY[0] = snake_posY;
		for (int i = 1; i < nTail; i++)
		{
			prev2X = tailX[i];
			prev2Y = tailY[i];
			tailX[i] = prevX;
			tailY[i] = prevY;
			prevX = prev2X;
			prevY = prev2Y;
		}
		switch (dir)
		{
		case UP:
			if (snake_posY >= 1)
			{
				snake_posY -= speedY;
			}
			break;
		case DOWN:
			if (snake_posY <= windowHeight - 1)
			{
				snake_posY += speedY;
			}
			break;
		case RIGHT:
			if (snake_posX <= windowWidth - 1)
			{
				snake_posX += speedX;
			}
			break;
		case LEFT:
			if (snake_posX >= 1)
			{
				snake_posX -= speedX;
			}
			break;
		default:
			break;
		}
	}

	void snakeMovement()
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			case 'w':
				dir = UP;
				break;
			case 's':
				dir = DOWN;
				break;
			case 'd':
				dir = RIGHT;
				break;
			case 'a':
				dir = LEFT;
				break;
			default:
				break;
			}
		}
	}
};


int main()
{
	Player obj;
	
	while (!gameOver)
	{
		system("cls");
		obj.boarder();
		obj.snakeMovement();
		obj.direction();
		obj.through_wall();
		obj.snake_ball_colision();
		obj.snake_Tail();
		//obj.colision();
		std::this_thread::sleep_for(std::chrono::milliseconds(70));
	}
	if (gameOver)
	{
		cout << "You lost, try again!" << endl;
	}
	return 0;
}