#include <bits/stdc++.h>
using namespace std;
const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
int T, n, m, k, x, y, d;
char s[1001][1001];
bool vis[1001][1001];
int main() {
    #ifndef ONLINE_JUDGE
        freopen("explore.in", "r", stdin);
        freopen("explore.out", "w", stdout);
    #endif
    cin >> T;
    while (T--) {
        cin >> n >> m >> k >> x >> y >> d;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> s[i][j];
            }
        }
        memset(vis, false, sizeof(vis));
        vis[x][y] = true;
        for (int i = 1; i <= k; i++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && s[nx][ny] == '.') {
                vis[nx][ny] = true;
                x = nx;
                y = ny;
            }
            else d = (d + 1) % 4;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                ans += vis[i][j];
            }
        }
        cout << ans << endl;
    }
    return 0;
}