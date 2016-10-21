#include <stdio.h> 
 
int board[64][64], C;
 
void go(int n, int lx, int ly, int ux, int uy, int x, int y)
{
    if (n == 0) return;
    int mx = (lx + ux) / 2;
    int my = (ly + uy) / 2;
 
    int num = C++;
    bool xin = lx <= x && x < mx;
    bool yin = ly <= y && y < my;
    if (xin && yin) go(n - 1, lx, ly, mx, my, x, y);
    else
    {
        board[mx - 1][my - 1] = num;
        go(n - 1, lx, ly, mx, my, mx - 1, my - 1);
    }
 
    if (xin && !yin) go(n - 1, lx, my, mx, uy, x, y);
    else
    {
        board[mx - 1][my] = num;
        go(n - 1, lx, my, mx, uy, mx - 1, my);
    }
 
    if (!xin && yin) go(n - 1, mx, ly, ux, my, x, y);
    else
    {
        board[mx][my - 1] = num;
        go(n - 1, mx, ly, ux, my, mx, my - 1);
    }
 
    if (!xin && !yin) go(n - 1, mx, my, ux, uy, x, y);
    else
    {
        board[mx][my] = num;
        go(n - 1, mx, my, ux, uy, mx, my);
    }
}
 
 
int main()
{
    int T;
    //freopen("input.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d", &T);
 
    while (T--)
    {
        int N, x, y;
        scanf("%d %d %d", &N, &x, &y);
        board[--x][--y] = 0;
        C = 1;
        go(N, 0, 0, (1 << N), (1 << N), x, y);
        for (int i = 0; i < (1 << N); i++)
        {
            for (int j = 0; j < (1 << N); j++)
            {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
 
 
    }
    return 0;
}
