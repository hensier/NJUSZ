// 洛谷 P8306 【模板】字典树
// Submission: https://www.luogu.com.cn/record/190105372
// Time: 2024-11-21 10:42:28
#include <bits/stdc++.h>
using namespace std;
int T, n, q, cnt, t[3000001][62], siz[3000001];
char s[3000001];
int get_id(char c) {
    if (islower(c)) return c - 'a';
    if (isupper(c)) return c - 'A' + 26;
    return c - '0' + 52;
}
void insert(char *s) {
    for (int i = 0, p = 1; s[i]; i++) {
        int c = get_id(s[i]);
        if (t[p][c] == 0) t[p][c] = ++cnt;
        p = t[p][c];
        siz[p]++;
    }
}
int solve(char *s) {
    int p = 1;
    for (int i = 0; s[i]; i++) {
        int c = get_id(s[i]);
        if (t[p][c] == 0) return 0;
        p = t[p][c];
    }
    return siz[p];
}
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &q);
        cnt = 1;
        for (int i = 1; i <= n; i++) {
            scanf("%s", s);
            insert(s);
        }
        for (int i = 1; i <= q; i++) {
            scanf("%s", s);
            printf("%d\n", solve(s));
        }
        for (int i = 1; i <= cnt; i++) {
            siz[i] = 0;
            for (int j = 0; j < 62; j++) t[i][j] = 0;
        }
    }
    return 0;
}