// 洛谷 P3385 【模板】负环
// Submission: https://www.luogu.com.cn/record/185426978
// Time: 2024-10-28 17:47:16
#include <bits/stdc++.h>
using namespace std;
int T, n, m, cnt, head[2001], dis[2001], edges[2001];
bool vis[2001];
queue<int> q;
struct edge {
    int nxt, to, w;
} e[6001];
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
        if (x > 9) write(x / 10);
        pc(x % 10 + 48);
    }
} using namespace IO;
int main() {
    read(T);
    while (T--) {
        read(n), read(m);
        cnt = 0;
        memset(head, 0, sizeof(head));
        memset(dis, 0x3f, sizeof(dis));
        memset(edges, 0, sizeof(edges));
        memset(vis, false, sizeof(vis));
        for (int i = 1, u, v, w; i <= m; i++) {
            read(u), read(v), read(w);
            add_edge(u, v, w);
            if (w >= 0) add_edge(v, u, w);
        }
        dis[1] = 0;
        q.push(1);
        bool flag = false;
        while (q.size()) {
            int u = q.front();
            q.pop();
            vis[u] = false;
            for (int i = head[u]; i; i = e[i].nxt) {
                int v = e[i].to;
                if (dis[v] > dis[u] + e[i].w) {
                    dis[v] = dis[u] + e[i].w;
                    edges[v] = edges[u] + 1;
                    if (edges[v] >= n) {
                        flag = true;
                        break;
                    }
                    if (!vis[v]) {
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }
            if (flag) break;
        }
        puts(flag ? "YES" : "NO");
    }
    return 0;
}