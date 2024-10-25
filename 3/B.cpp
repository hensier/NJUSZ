#include <bits/stdc++.h>
using namespace std;
int t, n, m;
pair<int, int> xy, xY, Xy, XY, yx, yX, Yx, YX;
char s[501];
bool b[501][501];
bool check(bool f) {
    xy = yx = {n, m};
    xY = Yx = {n, 1};
    Xy = yX = {1, m};
    XY = YX = {1, 1};
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (b[i][j] == f) {
                if (i < xy.first || (i == xy.first && j < xy.second)) xy = {i, j};
                if (i < xY.first || (i == xY.first && j > xY.second)) xY = {i, j};
                if (i > Xy.first || (i == Xy.first && j < Xy.second)) Xy = {i, j};
                if (i > XY.first || (i == XY.first && j > XY.second)) XY = {i, j};
                if (j < yx.second || (j == yx.second && i < yx.first)) yx = {i, j};
                if (j < yX.second || (j == yX.second && i > yX.first)) yX = {i, j};
                if (j > Yx.second || (j == Yx.second && i < Yx.first)) Yx = {i, j};
                if (j > YX.second || (j == YX.second && i > YX.first)) YX = {i, j};
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (b[i][j] == !f) {
                if (i >= xy.first && j >= xy.second && i <= XY.first && j <= XY.second) continue;
                if (i >= xy.first && j >= xy.second && i <= YX.first && j <= YX.second) continue;
                if (i >= yx.first && j >= yx.second && i <= XY.first && j <= XY.second) continue;
                if (i >= yx.first && j >= yx.second && i <= YX.first && j <= YX.second) continue;
                if (i <= Xy.first && j >= Xy.second && i >= xY.first && j <= xY.second) continue;
                if (i <= Xy.first && j >= Xy.second && i >= Yx.first && j <= Yx.second) continue;
                if (i <= yX.first && j >= yX.second && i >= xY.first && j <= xY.second) continue;
                if (i <= yX.first && j >= yX.second && i >= Yx.first && j <= Yx.second) continue;
                return false;
            }
        }
    }
    return true;
}
int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) {
            scanf("%s", s + 1);
            for (int j = 1; j <= m; j++) b[i][j] = (s[j] == 'W');
        }
        puts((check(false) || check(true)) ? "YES": "NO");
    }
    return 0;
}