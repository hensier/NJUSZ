#include <bits/stdc++.h>
using namespace std;
int n, m, k, maxa, cnt, head[20001][101], dis[20001][101];
bool vis[20001][101];
struct edge {
    int nxt, to1, to2, a;
} e[2000001];
struct node {
    int id1, id2;
};
void add_edge(int u1, int u2, int v1, int v2, int a) {
    e[++cnt] = (edge){head[u1][u2], v1, v2, a};
    head[u1][u2] = cnt;
}
bool bfs(int s1, int s2, int t) {
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, false, sizeof(vis));
    dis[s1][s2] = 0;
    queue<node> q;
    q.push((node){s1, s2});
    while (q.size()) {
        int u1 = q.front().id1, u2 = q.front().id2;
        q.pop();
        if (vis[u1][u2]) continue;
        vis[u1][u2] = true;
        for (int i = head[u1][u2]; i; i = e[i].nxt) {
            int v1 = e[i].to1, v2 = e[i].to2;
            if (dis[u1][u2] <= t - e[i].a - 1 && dis[v1][v2] > dis[u1][u2] + 1) {
                dis[v1][v2] = dis[u1][u2] + 1;
                if (!vis[v1][v2]) q.push((node){v1, v2});
            }
        }
    }
    return dis[1][0] < 0x3f3f3f3f;
}
int solve(int l, int r) {
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (bfs(n, 0, mid * k)) r = mid - 1;
        else l = mid + 1;
    }
    return l > 2000000 ? -1 : l * k;
}
int main() {
    #ifndef ONLINE_JUDGE
        freopen("bus.in", "r", stdin);
        freopen("bus.out", "w", stdout);
    #endif
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1, u, v, a; i <= m; i++) {
        scanf("%d%d%d", &u, &v, &a);
        for (int j = 0; j < k; j++) add_edge(v, j, u, (j + 1) % k, a);
    }
    printf("%d", solve(0, 2000000));
    return 0;
}