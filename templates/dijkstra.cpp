// 洛谷 P4779 【模板】单源最短路径（标准版）
// Submission: https://www.luogu.com.cn/record/185421940
// Time: 2024-10-28 17:22:56
#include <bits/stdc++.h>
using namespace std;
int n, m, s, cnt, head[100001], dis[100001];
bool vis[100001];
struct edge {
    int nxt, to, w;
} e[200001];
struct node {
    int id, dis;
    bool operator<(const node &x) const {
        return dis > x.dis;
    }
}; priority_queue<node> q;
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
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    q.push((node){s, 0});
    while (q.size()) {
        int u = q.top().id;
        q.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (int i = head[u]; i; i = e[i].nxt) {
            int v = e[i].to;
            if (dis[v] > dis[u] + e[i].w) {
                dis[v] = dis[u] + e[i].w;
                if (!vis[v]) q.push((node){v, dis[v]});
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