#include <stdio.h>
 
int board[65][65];
int turn;
 
int my_pow(int num, int p)
{
    int tmp;
    if (p == 1)
        return num;
    tmp = my_pow(num, p / 2);
    if (p % 2)
        return tmp * tmp * num;
    else
        return tmp * tmp;
}
 
int pos(int cx, int cy, int dx, int dy)
{
    if (dx <= cx)
    {
        if (dy <= cy)
            return 1;
        else
            return 3;
    }
    else
    {
        if (dy <= cy)
            return 2;
        else
            return 4;
    }
}
 
void blocking(int lx, int ly, int rx, int ry, int dx, int dy)
{
    int cx = (lx + rx) / 2, cy = (ly + ry) / 2;
    int i, j;
 
    if (rx - lx == 1)
    {
        for (i = ly; i <= ry; ++i)
        {
            for (j = lx; j <= rx; ++j)
            {
                if ((i == dy) && (j == dx))
                    continue;
                board[i][j] = turn;
            }
        }
        ++turn;
        return;
    }
    switch (pos(cx, cy, dx, dy))
    {
    case 1:
        board[cy][cx + 1] = turn;
        board[cy + 1][cx] = turn;
        board[cy + 1][cx + 1] = turn;
        ++turn;
        blocking(lx, ly, cx, cy, dx, dy);//
        blocking(cx + 1, ly, rx, cy, cx + 1, cy);
        blocking(lx, cy + 1, cx, ry, cx, cy + 1);
        blocking(cx + 1, cy + 1, rx, ry, cx + 1, cy + 1);
        break;
    case 2:
        board[cy][cx] = turn;
        board[cy + 1][cx] = turn;
        board[cy + 1][cx + 1] = turn;
        ++turn;
        blocking(lx, ly, cx, cy, cx, cy);
        blocking(cx + 1, ly, rx, cy, dx, dy);//
        blocking(lx, cy + 1, cx, ry, cx, cy + 1);
        blocking(cx + 1, cy + 1, rx, ry, cx + 1, cy + 1);
        break;
    case 3:
        board[cy][cx] = turn;
        board[cy][cx + 1] = turn;
        board[cy + 1][cx + 1] = turn;
        ++turn;
        blocking(lx, ly, cx, cy, cx, cy);
        blocking(cx + 1, ly, rx, cy, cx + 1, cy);
        blocking(lx, cy + 1, cx, ry, dx, dy);//
        blocking(cx + 1, cy + 1, rx, ry, cx + 1, cy + 1);
        break;
    case 4:
        board[cy][cx] = turn;
        board[cy][cx + 1] = turn;
        board[cy + 1][cx] = turn;
        ++turn;
        blocking(lx, ly, cx, cy, cx, cy);
        blocking(cx + 1, ly, rx, cy, cx + 1, cy);
        blocking(lx, cy + 1, cx, ry, cx, cy + 1);
        blocking(cx + 1, cy + 1, rx, ry, dx, dy);//
        break;
    }
 
}
 
int main()
{
    int T, test_case;
    int N, x, y;
    int tmp;
    int i, j;
 
    scanf("%d", &test_case);
    for (T = 0; T < test_case; ++T)
    {
        turn = 1;
        scanf("%d %d %d", &N, &x, &y);
        board[x][y] = 0;
        tmp = my_pow(2, N);
        blocking(1, 1, tmp, tmp, y, x);
        for (i = 1; i <= tmp; ++i)
        {
            for (j = 1; j <= tmp; ++j)
                printf("%d ", board[i][j]);
            printf("\n");
        }
    }
 
    return 0;
}
