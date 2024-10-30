#include <bits/stdc++.h>
using namespace std;
int T, n, m, q;
struct node {
    int color, id;
} row[100001], col[100001];
int main() {
    #ifndef ONLINE_JUDGE
        freopen("paint.in", "r", stdin);
        freopen("paint.out", "w", stdout);
    #endif
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &n, &m, &q);
        for (int i = 1, opt, x, c; i <= q; i++) {
            scanf("%d%d%d", &opt, &x, &c);
            if (opt == 0) row[x] = (node){c, i};
            else col[x] = (node){c, i};
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (row[i].id > col[j].id) printf("%d ", row[i].color);
                else printf("%d ", col[j].color);
            }
            putchar('\n');
        }
        for (int i = 1; i <= q; i++) {
            row[i] = (node){0, 0};
            col[i] = (node){0, 0};
        }
    }
    return 0;
}