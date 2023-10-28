#include <iostream>
#include <conio.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

using namespace std;

const int width = 20;
const int height = 10;

class Snake {
public:
    Snake();
    void update();
    bool isAlive() const;
    void changeDirection(char newDirection);
    void eatFood();
    void display();
private:
    int headX, headY;
    int tailLength;
    vector<int> tailX, tailY;
    char direction;
    bool alive;
};

Snake::Snake() {
    srand(static_cast<unsigned>(time(nullptr));
    headX = width / 2;
    headY = height / 2;
    tailLength = 0;
    direction = ' ';
    alive = true;
}

void Snake::update() {
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = headX;
    tailY[0] = headY;
    
    for (int i = 1; i < tailLength; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    if (direction == 'w') headY--;
    else if (direction == 's') headY++;
    else if (direction == 'a') headX--;
    else if (direction == 'd') headX++;

    if (headX < 0 || headX >= width || headY < 0 || headY >= height)
        alive = false;

    for (int i = 0; i < tailLength; i++) {
        if (tailX[i] == headX && tailY[i] == headY)
            alive = false;
    }
}

bool Snake::isAlive() const {
    return alive;
}

void Snake::changeDirection(char newDirection) {
    if ((newDirection == 'w' && direction != 's') ||
        (newDirection == 's' && direction != 'w') ||
        (newDirection == 'a' && direction != 'd') ||
        (newDirection == 'd' && direction != 'a')) {
        direction = newDirection;
    }
}

void Snake::eatFood() {
    tailLength++;
    tailX.push_back(-1);
    tailY.push_back(-1);
}

void Snake::display() {
    system("clear"); // Clear the screen (for Linux)
    
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == headY && j == headX)
                cout << "O";
            else if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
                cout << "#";
            else {
                bool print = false;
                for (int k = 0; k < tailLength; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        cout << "o";
                        print = true;
                    }
                }
                if (!print) cout << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    Snake snake;
    char input;
    bool gameOver = false;

    while (!gameOver) {
        snake.display();
        input = _getch(); // Use _getch() for Linux

        switch (input) {
            case 'w':
            case 's':
            case 'a':
            case 'd':
                snake.changeDirection(input);
                break;
            case 'q':
                gameOver = true;
                break;
        }

        snake.update();

        if (!snake.isAlive())
            gameOver = true;

        // Add logic to generate and check for food
    }

    return 0;
}
