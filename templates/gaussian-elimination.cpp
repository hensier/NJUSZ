// 洛谷 P3389 【模板】高斯消元法
// Submission: https://www.luogu.com.cn/record/192885278
// Time: 2024-12-05 11:44:09
#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
int n;
double m[101][102];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n + 1; j++) {
            scanf("%lf", &m[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        int r = i;
        for (int j = i + 1; j <= n; j++) {
            if (fabs(m[j][i]) > fabs(m[r][i])) {
                r = j;
            }
        }
        if (fabs(m[r][i]) < eps) {
            printf("No Solution");
            return 0;
        }
        swap(m[r], m[i]);
        double tmp = m[i][i];
        for (int j = 1; j <= n + 1; j++) m[i][j] /= tmp;
        for (int j = 1; j <= n; j++) {
            if (i != j) {
                tmp = m[j][i] / m[i][i];
                for (int k = i; k <= n + 1; k++) m[j][k] -= m[i][k] * tmp;
            }
        }
    }
    for (int i = 1; i <= n; i++) printf("%.2lf\n", m[i][n+1]);
    return 0;
}