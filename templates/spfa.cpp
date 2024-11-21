// 洛谷 P3371 【模板】单源最短路径（弱化版）
// Submission: https://www.luogu.com.cn/record/185423843
// Time: 2024-10-28 17:30:37
#include <bits/stdc++.h>
using namespace std;
int n, m, s, cnt, head[10001], dis[10001];
bool vis[10001];
queue<int> q;
struct edge {
    int nxt, to, w;
} e[500001];
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
        char ch = gc();
        while (!isdigit(ch)) ch = gc();
        while (isdigit(ch)) {
            x = (x << 3) + (x << 1) + (ch ^ 48);
            ch = gc();
        }
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
        if (x > 9) write(x / 10);
        pc(x % 10 + 48);
    }
} using namespace IO;
int main() {
    read(n), read(m), read(s);
    for (int i = 1, u, v, w; i <= m; i++) {
        read(u), read(v), read(w);
        add_edge(u, v, w);
    }
    for (int i = 1; i <= n; i++) dis[i] = INT_MAX;
    dis[s] = 0;
    q.push(s);
    while (q.size()) {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for (int i = head[u]; i; i = e[i].nxt) {
            int v = e[i].to;
            if (dis[v] > dis[u] + e[i].w) {
                dis[v] = dis[u] + e[i].w;
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