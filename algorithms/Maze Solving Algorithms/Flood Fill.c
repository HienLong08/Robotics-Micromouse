#include <stdio.h>

#define N 5

int Map[N][N];

int StackX[100];
int StackY[100];

int Top = 0;

int Dx[4] = {-1, 1, 0, 0};
int Dy[4] = {0, 0, -1, 1};

void DFS(int StartX, int StartY, int GoalX, int GoalY) {

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            Map[i][j] = -1;
        }
    }

    StackX[Top] = StartX;
    StackY[Top] = StartY;
    Top++;

    Map[StartX][StartY] = 0;

    while (Top > 0) {

        Top--;

        int X = StackX[Top];
        int Y = StackY[Top];

        if (X == GoalX && Y == GoalY) {
            return;
        }

        for (int k = 0; k < 4; k++) {

            int NewX = X + Dx[k];
            int NewY = Y + Dy[k];

            if (NewX < 0 || NewX >= N ||
                NewY < 0 || NewY >= N) {
                continue;
            }

            if (Map[NewX][NewY] == -1) {

                Map[NewX][NewY] = Map[X][Y] + 1;

                StackX[Top] = NewX;
                StackY[Top] = NewY;
                Top++;
            }
        }
    }
}
