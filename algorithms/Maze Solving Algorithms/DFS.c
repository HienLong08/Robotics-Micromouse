#include <stdio.h>

#define MAX 100

int Stack[MAX];
int Top = -1;

void Push(int x){
    if (Top == MAX - 1) {
        printf("Stack is full\n");
    }
    else{
        Top++;
        Stack[Top] = x;
    }
}

void Pop(){
    if (Top == -1) {
        printf("Stack is empty\n");
    }
    else{
        printf("%d\n", Stack[Top]);
        Top--;
    }
}

int DFS(int GoalX, int GoalY, int X, int Y) {
    int N = 5;
    int Map[N][N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            Map[i][j] = 0;
        }
    }

    dx[4] = {1, -1, 0, 0};
    dy[4] = {0, 0, 1, -1};

    for (int i = 0; i = 4; i++) {
        int NewX =  X + dx[i];
        int NewY =  Y + dy[i];

        if (NewX )
    }


}