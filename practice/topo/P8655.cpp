#include <bits/stdc++.h>
using namespace std;
int N, cnt, head[100001], deg[100001];
bool vis[100001];
queue<int> q;
struct node {
    int nxt, to;
} e[200001];
void add_edge(int u, int v) {
    e[++cnt] = (node){head[u], v};
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
    read(N);
    for (int i = 1, u, v; i <= N; i++) {
        read(u), read(v);
        add_edge(u, v);
        add_edge(v, u);
        deg[u]++;
        deg[v]++;
    }
    for (int i = 1; i <= N; i++) {
        if (deg[i] == 1) {
            q.push(i);
        }
    }
    while (q.size()) {
        int u = q.front();
        q.pop();
        vis[u] = true;
        for (int i = head[u]; i; i = e[i].nxt) {
            int v = e[i].to;
            if (--deg[v] == 1 && !vis[v]) q.push(v);
        }
    }
    for (int i = 1; i <= N; i++) {
        if (!vis[i]) {
            write(i);
            pc(' ');
        }
    }
    fwrite(obuf, p3 - obuf, 1, stdout);
    return 0;
}