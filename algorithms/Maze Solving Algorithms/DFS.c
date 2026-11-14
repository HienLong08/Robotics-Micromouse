#include <stdio.h>

#define N 5
#define MAX 100

int StackX[MAX];
int StackY[MAX];
int Top = -1;

int Map[N][N] = {
    {0, 0, 1, 0, 0},
    {1, 0, 1, 0, 1},
    {0, 0, 0, 0, 0},
    {0, 1, 1, 1, 0},
    {0, 0, 0, 0, 0}
};

bool Visited[N][N] = {false};

void Push(int x, int y) {
    Top++;
    StackX[Top] = x;
    StackY[Top] = y;
}

void Pop(int &x, int &y) {
    x = StackX[Top];
    y = StackY[Top];
    Top--;
}

bool DFS(int StartX, int StartY, int GoalX, int GoalY) {

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    Push(StartX, StartY);
    Visited[StartX][StartY] = true;

    while (Top != -1) {

        int X, Y;
        Pop(X, Y);

        if (X == GoalX && Y == GoalY) {
            return true;
        }

        for (int i = 0; i < 4; i++) {

            int NewX = X + dx[i];
            int NewY = Y + dy[i];

            if (NewX < 0 || NewX >= N || NewY < 0 || NewY >= N) {
                continue;
            }

            if (Map[NewX][NewY] == 1 || Visited[NewX][NewY]) {
                continue;
            }

            Visited[NewX][NewY] = true;

            Push(NewX, NewY);
        }
    }

    return false;
}
