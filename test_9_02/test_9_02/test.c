#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define EASY_COUNT 10

void IntiBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            board[i][j] = set;
        }

    }

}
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
    int i = 0;
    int j = 0;
    for (i = 0; i <= col; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
    for (i = 1; i <= row; i++)
    {
        printf("%d ", i);
        for (j = 1; j <= col; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}
void SetBoard(char board[ROWS][COLS], int row, int col)
{
    int count = EASY_COUNT;
    int x = 0;
    int y = 0;
    while (count)
    {
        x = rand() % ROW + 1;
        y = rand() % COL + 1;
        if (board[x][y] == '0')
        {
            board[x][y] = '1';
            count--;
        }

    }
}
int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
    return mine[x - 1][y] + mine[x - 1][y - 1] +
        mine[x - 1][y + 1] + mine[x][y - 1] +
        mine[x][y + 1] + mine[x + 1][y] +
        mine[x + 1][y - 1] + mine[x + 1][y + 1] -
        8 * '0';

}
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
    int x = 0;
    int y = 0;
    int win = 0;
    while (win < row * col - EASY_COUNT)
    {
        printf("请输入排除雷的坐标\n");
        scanf("%d%d", &x, &y);
        if (x >= 1 && x <= row && y >= 1 && y <= col)
        {
            if (mine[x][y] == '1')
            {
                printf("你被雷炸死了，游戏结束\n");
                DisplayBoard(mine, ROW, COL);
                break;
            }
            else
            {
                int count = get_mine_count(mine, x, y);
                show[x][y] = count + '0';
                DisplayBoard(show, ROW, COL);
                win++;
            }

        }
        else
        {
            printf("坐标非法，请重新输入\n");
        }
    }
    if (win == row * col - EASY_COUNT)
    {
        printf("恭喜你排雷成功\n");
    }
}

void meun()
{
    printf("**********************\n");
    printf("****  1. play   ******\n");
    printf("****  0.eixt    ******\n");
    printf("**********************\n");
}
void game()//游戏运算逻辑
{
    printf("扫雷游戏\n");
    char mine[ROWS][COLS] = { 0 }; //自己的11*11
    char show[ROWS][COLS] = { 0 }; //显示的9*9
    IntiBoard(mine, ROWS, COLS, '0');//初始化
    IntiBoard(show, ROWS, COLS, '*');
    //DisplayBoard(mine,ROW,COL);//打印棋盘格
    DisplayBoard(show, ROW, COL);
    //布置雷
    SetBoard(mine, ROW, COL);
    //DisplayBoard(mine,ROW,COL);
    FindMine(mine, show, ROW, COL);
}
void test()
{
    srand((unsigned int)time(NULL));
    int input = 0;
    do
    {
        meun();
        printf("请输入>:");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            game();
            break;
        case 0:
            printf("退出游戏");
            break;
        default:
            printf("选择错误，请重新输入");
            break;

        }
    } while (input);
}
int main()
{
    test();
    return 0;
}
