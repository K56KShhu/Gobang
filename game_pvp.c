#include <stdio.h>
#include <stdlib.h>
#define N 15
void welcome(void);
void printchess(void);
void playchess(void);
int checkgame(int, int, int);
char board[N + 1][N + 1] = {  };

int main(void)
{
    printchess();

    while(1)
        playchess();

    return 0;
}

void printchess(void)
{
    int i, j;

    for (i = 0; i <= N; i++)
    {
        putchar('\n');
        for(j = 0; j <= N; j++)
        {
            if (i == 0)
                printf("%5d", j);
            else if (j == 0)
                printf("%5d", i);
            else if (board[i][j] == 1)
                printf("    O");
            else if (board[i][j] == 2)
                printf("    @");
            else
                printf("    .");
        }
        putchar('\n');
    }
    putchar('\n');
}

void playchess(void)
{
    static int player = 1;
    int i, j;

    if (player % 2 == 1)
    {
        printf("(O)Player 1: ");
        scanf("%d %d", &i, &j);
        while (i > N || i < 1 || j > N || j < 1)
        {
            printf("error: Not suitable! Try again: ");
            scanf("%d %d", &i, &j);
        }
        while (board[i][j] != 0)
        {
            printf("error: Occupied! Try again: ");
            scanf("%d %d", &i, &j);
        }
        board[i][j] = 1;
    }
    else
    {
        printf("(@)Player 2: ");
        scanf("%d %d", &i, &j);
        while (i > N || i < 1 || j > N || j < 1)
        {
            printf("error: Not suitable! Try again: ");
            scanf("%d %d", &i, &j);
        }
        while (board[i][j] != 0)
        {
            printf("error: Occupied! Try again: ");
            scanf("%d %d", &i, &j);
        }
        board[i][j] = 2;
    }

    system("cls");
    printchess();
    if(checkgame(i, j, player))
    {
        if (player % 2 == 1)
            puts("Winner: Player1");
        else
            puts("Winner: Player2");
        exit(EXIT_SUCCESS);
    }

    player++;
}

int checkgame(int x, int y, int people)
{
    int i, j, t;

    if (people % 2 == 1)
        t = 1;
    else
        t = 2;

    for (i = x, j = y - 4; j <= y; j++)
        if (j >= 1 && j <= N && t == board[i][j] && t == board[i][j + 1] && t == board[i][j + 2] &&
                                t == board[i][j + 3] && t == board[i][j + 4])
            return 1;

    for (j = y, i = x - 4; i <= x; i++)
        if (i >= 1 && i <= N && t == board[i][j] && t == board[i + 1][j] && t == board[i + 2][j] &&
                                t == board[i + 3][j] && t == board[i + 4][j])
            return 1;

    for (i = x - 4, j = y - 4; i <= x, j <= y; i++, j++)
        if (i >= 1 && i <= N && j >= 1 && j <= N &&
                                t == board[i][j] && t == board[i + 1][j + 1] && t == board[i + 2][j + 2] &&
                                t == board[i + 3][j + 3] && t == board[i + 4][j + 4])
            return 1;

    for (i = x + 4, j = y - 4; i >= x, j <= y; i--, j++)
        if (i >= 1 && i <= N && j >= 1 && j < N &&
                                t == board[i][j] && t == board[i - 1][j + 1] && t == board[i - 2][j + 2] &&
                                t == board[i - 3][j + 3] && t == board[i - 4][j + 4])
            return 1;

    return 0;
}



























