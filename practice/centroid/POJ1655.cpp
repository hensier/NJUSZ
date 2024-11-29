#include <bits/stdc++.h>
using namespace std;
int t, n, cnt, ans1, ans2, head[20001], siz[20001];
struct node {
    int nxt, to;
} e[39999];
void add_edge(int u, int v) {
    e[++cnt] = (node){head[u], v};
    head[u] = cnt;
}
void dfs(int u, int fa) {
    siz[u] = 1;
    int w = 0;
    for (int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].to;
        if (v != fa) {
            dfs(v, u);
            siz[u] += siz[v];
            w = max(w, siz[v]);
        }
    }
    w = max(w, n - siz[u]);
    if (w <= n / 2) {
        ans1 = min(ans1, u);
        ans2 = w;
    }
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
    read(t);
    while (t--) {
        read(n);
        cnt = 0;
        ans1 = n;
        ans2 = n;
        memset(head, 0, sizeof(head));
        for (int i = 1, u, v; i < n; i++) {
            read(u), read(v);
            add_edge(u, v);
            add_edge(v, u);
        }
        dfs(1, 0);
        printf("%d %d\n", ans1, ans2);
    }
    return 0;
}