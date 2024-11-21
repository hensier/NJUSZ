// 洛谷 P5960 【模板】差分约束
// Submission: https://www.luogu.com.cn/record/185435846
// Time: 2024-10-28 18:41:54
#include <bits/stdc++.h>
using namespace std;
int n, m, cnt, head[5001], dis[5001], edges[5001];
bool vis[5001];
queue<int> q;
struct edge {
    int nxt, to, w;
} e[5001];
void add_edge(int u, int v, int w) {
    e[++cnt] = (edge){head[u], v, w};
    head[u] = cnt;
}
namespace IO {
    char buf[1 << 21], *p1 = buf, *p2 = buf, obuf[1 << 21], *p3 = obuf;
    char gc() {
        if (p1 == p2) {
            p1 = buf;
            p2 = buf + fread(buf, 1, 1 << 21, stdin);
        }
        return p1 == p2 ? EOF : *p1++;
    }
    template<typename T> void read(T &x) {
        x = 0;
        T f = 1;
        char ch = gc();
        while (!isdigit(ch)) {
            if (ch == '-') f = -1;
            ch = gc();
        }
        while (isdigit(ch)) {
            x = (x << 3) + (x << 1) + (ch ^ 48);
            ch = gc();
        }
        x *= f;
    }
    void pc(char c) {
        if (p3 - obuf < (1 << 21)) *p3++ = c;
        else {
            fwrite(obuf, p3 - obuf, 1, stdout);
            p3 = obuf;
            *p3++ = c;
        }
    }
    template<typename T> void write(T x) {
        if (x < 0) {
            pc('-');
            x = -x;
        }
        if (x > 9) write(x / 10);
        pc(x % 10 + 48);
    }
} using namespace IO;
int main() {
    read(n), read(m);
    for (int i = 1; i <= n; i++) add_edge(0, i, 0);
    for (int i = 1, c, C, y; i <= m; i++) {
        read(c), read(C), read(y);
        add_edge(c, C, -y);
    }
    memset(dis, ~0x3f, sizeof(dis));
    dis[0] = 0;
    q.push(0);
    while (q.size()) {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for (int i = head[u]; i; i = e[i].nxt) {
            int v = e[i].to;
            if (dis[v] < dis[u] + e[i].w) {
                dis[v] = dis[u] + e[i].w;
                edges[v] = edges[u] + 1;
                if (edges[v] > n) {
                    printf("NO");
                    return 0;
                }
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        write(dis[i]);
        pc(' ');
    }
    fwrite(obuf, p3 - obuf, 1, stdout);
    return 0;
}