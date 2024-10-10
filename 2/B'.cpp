// Original Problem: https://www.luogu.com.cn/problem/P1985
// Difficulty: Blue
// Submission: https://codeforces.com/group/fVoe9GOJPd/contest/525673/submission/284308898
// Verdict: Accepted
#include <bits/stdc++.h>
using namespace std;
int M, N, minf = 226, a[15][15], A[15][15], b[15][15], B[15][15];
int main() {
    scanf("%d%d", &M, &N);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < (1 << N); i++) {
        memcpy(A, a, sizeof(a));
        for (int j = 0; j < N; j++) b[0][j] = i >> (N - j - 1) & 1;
        for (int j = 0; j < M; j++) {
            if (j > 0) {
                for (int k = 0; k < N; k++) {
                    A[j][k] ^= b[j-1][k];
                }
            }
            for (int k = 0; k < N; k++) {
                if (k > 0) A[j][k-1] ^= b[j][k];
                A[j][k] ^= b[j][k];
                if (k < N - 1) A[j][k+1] ^= b[j][k];
            }
            if (j < M - 1) memcpy(b[j+1], A[j], sizeof(A[j]));
        }
        bool flag = true;
        for (int j = 0; j < N; j++) {
            if (A[M-1][j]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            int cur = 0;
            for (int j = 0; j < M; j++) {
                for (int k = 0; k < N; k++) {
                    cur += b[j][k];
                }
            }
            if (cur < minf) {
                minf = cur;
                memcpy(B, b, sizeof(b));
            }
        }
    }
    if (minf == 226) printf("IMPOSSIBLE");
    else {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) printf("%d ", B[i][j]);
            putchar('\n');
        }
    }
    return 0;
}