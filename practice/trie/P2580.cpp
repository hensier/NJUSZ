#include <bits/stdc++.h>
using namespace std;
int n, m, cnt = 1, t[500001][26], exist[500001];
char s[51];
void insert(char *s) {
    int p = 1;
    for (int i = 0; s[i]; i++) {
        int c = s[i] - 'a';
        if (t[p][c] == 0) t[p][c] = ++cnt;
        p = t[p][c];
    }
    exist[p] = 1;
}
int find(char *s) {
    int p = 1;
    for (int i = 0; s[i]; i++) {
        int c = s[i] - 'a';
        if (t[p][c] == 0) return 0;
        p = t[p][c];
    }
    if (exist[p] == 0) return exist[p];
    return exist[p]++;
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s);
        insert(s);
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        scanf("%s", s);
        switch (find(s)) {
            case 0: {
                puts("WRONG");
                break;
            }
            case 1: {
                puts("OK");
                break;
            }
            default: {
                puts("REPEAT");
                break;
            }
        }
    }
    return 0;
}