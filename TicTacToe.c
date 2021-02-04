#include <stdio.h>
char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}};
/*
win cons 
0-1-2, 10-11-12,20-21-22, 0-10-20, 1-11-20, 2-12-22, 0-11-22, 2-11-20
 */
char winCheck(char board[3][3])
{
    char winner = '0';
    if (board[0][0] == board[0][1]&&board[0][0] == board[0][2] && (board[0][0] == 'X' || board[0][0] == 'O'))
        winner = board[0][0];
    else if (board[1][0] == board[1][1]&&board[1][0] == board[1][2] && (board[1][0] == 'X' || board[1][0] == 'O'))
        winner = board[1][0];
    else if (board[2][0] == board[2][1]&&board[2][0] == board[2][2] && (board[2][0] == 'X' || board[2][0] == 'O'))
        winner = board[2][0];
    else if (board[0][0] == board[1][0]&&board[1][0] == board[2][0] && (board[0][0] == 'X' || board[0][0] == 'O'))
        winner = board[0][0];
    else if (board[0][1] == board[1][1]&&board[1][1] == board[2][1] && (board[0][1] == 'X' || board[0][1] == 'O'))
        winner = board[0][1];
    else if (board[0][2] == board[1][2]&&board[0][2] == board[2][2] && (board[0][2] == 'X' || board[0][2] == 'O'))
        winner = board[0][2];
    else if (board[0][0] == board[1][1]&&board[0][0] == board[2][2] && (board[0][0] == 'X' || board[0][0] == 'O'))
        winner = board[0][0];
    else if (board[0][2] == board[1][1]&&board[1][1] == board[2][0] && (board[0][2] == 'X' || board[0][2] == 'O'))
        winner = board[0][2];
    else
    {
        _Bool found = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] != 'X' && board[i][j] != 'O')
                {
                    found = 1;
                    break;
                }
                if (found == 1)
                    break;
            }
        }
        if (found == 0)
            winner = 'D';
    }
    //printf("\nwincheck %c\n", winner);
    return winner;
}
void drawBoard(char board[3][3])
{
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("-----------\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("-----------\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}
int playerMove(char board[3][3])
{
    unsigned move = 0;

    printf("please choose a move 1-9\n");
    scanf("%i", &move);
    return move;
    //1-3, 4-6, 7-9
}
int main()
{
    int i;
    int j;
    int move;
    char player = 'X';
    _Bool gameOver = 0;
    while (gameOver != 1)
    {
        drawBoard(board);
        move = playerMove(board);
        switch (move)
        {
        case 1:
            i = j = 0;
            break;
        case 2:
            i = 0;
            j = 1;
            break;
        case 3:
            i = 0;
            j = 2;
            break;
        case 4:
            i = 1;
            j = 0;
            break;
        case 5:
            i = 1;
            j = 1;
            break;
        case 6:
            i = 1;
            j = 2;
            break;
        case 7:
            i = 2;
            j = 0;
            break;
        case 8:
            i = 2;
            j = 1;
            break;
        case 9:
            i = 2;
            j = 2;
            break;
        }
        if (board[i][j] == 'X' || board[i][j] == 'O')
        {
            printf("that position has been already chosen, please choose again\n");
        }
        else
        {
            board[i][j] = player;
            if (player == 'X')
                player = 'O';
            else
                player = 'X';
        }
        char w = winCheck(board);
        if (w == 'X' || w == 'O' || w == 'D')
        {
            gameOver = 1;
            printf("Game over!\n");
            if (w=='D')
                printf("Cat's game!");
            else
                printf("%C was the winner!\n",w);
            break;
        }
    }
    
    
    // 1. Draw board. 2. player move. 3. check for win. 4 end game if win.

    return 0;
}