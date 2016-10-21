//N*M size, num of squares

#include <stdio.h>
#define min(a, b)  (((a) < (b)) ? (a) : (b)) 
#define MAX 202
int cnt[MAX][MAX];
char map[MAX][MAX];
int N, M, ans;
 
int main() {
    int tc_no;
 
    //freopen("sample_input.txt", "r", stdin);
    setbuf(stdout, NULL);
     
    scanf("%d", &tc_no);
 
    for (int tc = 1; tc <= tc_no; tc++) {
 
        scanf("%d %d", &N, &M);
 
        for (int i = 0; i < N; i++)
            scanf("%s", map[i]);   //char로 디파인하고 &없이 s형태로 앞에 map[i]형태로 입력
 
        for (int i = N - 1; i >= 0; i--) {   //Y축을 N사이즈부터 줄여나가면서 Y축의 직사각형 사이즈을 count
            for (int j = 0; j < M; j++) {
               //처음은 Y축으로 N과 N-1을 비교해서 같은 색이면 cnt맵에 값을 증가시킨다.
               //그러면서 X축으로 j을 증가시키면서 값을 구한다.
               // 이경우 0(R)0(R) 이되고 다시 Y축이 N-1과 N-2을 비교하면서 값이 같다면 정사각형갯수가 누적되므로
                //       1(R)1(B)
                //  2(R)0(R) 가되고, 두번째는 값이 다르므로 누적안되고 1증가. 2(R)1(R)
                //  1(R)1(B)                                                  1(R)1(B)
                cnt[i][j] = 1;   //cnt[N-1][0] , cnt[N-1][1] 
                if (i < N - 1 && map[i][j] == map[i + 1][j]) 
                    cnt[i][j] += cnt[i + 1][j];
            }
        }
 
        ans = 0;
 
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                //Y측으로만 조사된 값이 저장된 cnt을 H에 저장
                int H = cnt[i][j];
                //X측을 조사한다.
                //J==K일때는 한칸, J, K=K+1이런식으로 증가하면서 같은 색인지 찾는다.
                for (int k = j; k < M; k++) {  
                    if (map[i][j] != map[i][k]) //같은색이 아니라면 break
                        break;
                    H = min(H, cnt[i][k]); //같은색이라면, X축으로 값을 더한다.
                    ans += H;
                }
            }
        }
 
        printf("%d\n", ans);
    }
 
    return 0;
}
