#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

const int roadWidth = 20;
const int roadLength = 50;

int playerPos = roadWidth / 2;
int score = 0;
int speed = 100;

void drawRoad() {
    for (int i = 0; i < roadWidth; i++) {
        cout << "|";
        for (int j = 0; j < roadLength - 2; j++) {
            if (i == roadWidth - 1) cout << "_";
            else cout << " ";
        }
        cout << "|" << endl;
    }
}

void updatePlayerPos(int move) {
    playerPos += move;
    if (playerPos < 1) playerPos = 1;
    if (playerPos > roadWidth - 2) playerPos = roadWidth - 2;
}

void drawPlayer() {
    for (int i = 0; i < roadWidth; i++) {
        if (i == roadWidth - 1) cout << "|";
        else if (i == playerPos) cout << "O";
        else cout << " ";
    }
    cout << endl;
}

void updateScore() {
    score++;
    if (score % 10 == 0 && speed > 50) speed -= 10;
}

void drawScore() {
    cout << "Score: " << score << endl;
}

void update() {
    updateScore();
    drawRoad();
    drawPlayer();
    drawScore();
}

void gameLoop() {
    while (true) {
        if (_kbhit()) {
            char input = _getch();
            if (input == 'a') updatePlayerPos(-1);
            if (input == 'd') updatePlayerPos(1);
            if (input == 'q') break;
        }
        update();
        Sleep(speed);
        system("cls");
    }
}

int main() {
    drawRoad();
    drawPlayer();
    drawScore();
    gameLoop();
    return 0;
}