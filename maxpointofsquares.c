#include <stdio.h>
#define MAX(a,b) ( ((a)>(b))? (a):(b))
int N, M;
long long S[303][303], A[303][303];
 
 
int main(void)
{
    int test_case;
    int T;
    int i, j, k;
    setbuf(stdout, NULL);
    scanf("%d", &T);
    for (test_case = 1; test_case <= T; ++test_case)
    {
        scanf("%d %d", &N, &M);
 
        for (i = 1; i <= N; i++){
            for (j = 1; j<= M; j++){
                scanf("%lld", &S[i][j]);
                S[i][j] += S[i - 1][j];
 
            }
        }
 
        //init data
        for (i = 0; i <= N; i++){
            for (j = 0; j <= M; j++){
                A[i][j] = -1e12;
 
            }
        }
        A[0][0] = 0;
 
        for (i = 1; i <= N; i++){
            for (j = 0; j < i; j++){
                //가장 큰 직사각형 값을 찾기 위한 변수
                long long mx = -1e12;
                //모든 열에 대해서
                for (k = 1; k <= M; k++){
                    //기존에 가장 큰값 보다 왼쪽 값이 큰지 확인 후 대입
                    mx = MAX(mx, A[j][k - 1]);
                    mx += S[i][k] - S[j][k];
                    //A[i][k]가 max보다 큰지 작은지 확인후 대입
                    A[i][k] = MAX(mx, A[i][k]);
 
                }
 
            }
 
        }
 
        printf("%lld\n", A[N][M]);
    }
    return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
