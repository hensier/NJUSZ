// Submission: https://codeforces.com/group/fVoe9GOJPd/contest/567353/submission/292700200
// Verdict: Accepted
#include <bits/stdc++.h>
using namespace std;
int t, n, m, cnt, head[100001], deg[100001];
bool vis[100001], rvis[100001];
unsigned long long h[100000];
const unsigned long long mask = mt19937_64(time(nullptr))();
struct node {
    int nxt, to;
} e[200001];
void add_edge(int u, int v) {
    e[++cnt] = (node){head[u], v};
    head[u] = cnt;
}
unsigned long long shift(unsigned long long x) {
    x ^= mask;
    x ^= x << 13;
    x ^= x >> 7;
    x ^= x << 17;
    x ^= mask;
    return x;
}
unsigned long long dfs(int u, int fa) {
    unsigned long long h = 1;
    for (int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].to;
        if (v != fa && vis[v]) h += shift(dfs(v, u));
    }
    return h;
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
        read(n), read(m);
        cnt = 0;
        for (int i = 1; i <= n; i++) {
            head[i] = 0;
            deg[i] = 0;
            vis[i] = false;
            rvis[i] = false;
        }
        for (int i = 1, u, v; i <= m; i++) {
            read(u), read(v);
            add_edge(u, v);
            add_edge(v, u);
            deg[u]++;
            deg[v]++;
        }
        if (m == n - 1) {
            puts("YES");
            continue;
        }
        if (m > n) {
            puts("NO");
            continue;
        }
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (deg[i] == 1) {
                q.push(i);
            }
        }
        int rcnt = n;
        while (q.size()) {
            int u = q.front();
            q.pop();
            vis[u] = true;
            rcnt--;
            for (int i = head[u]; i; i = e[i].nxt) {
                int v = e[i].to;
                if (!vis[v] && --deg[v] == 1) q.push(v);
            }
        }
        int r = 0;
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                rvis[i] = true;
                r = i;
                break;
            }
        }
        for (int i = 0; i < rcnt; i++) {
            h[i] = dfs(r, 0);
            for (int j = head[r]; j; j = e[j].nxt) {
                int v = e[j].to;
                if (!vis[v] && !rvis[v]) {
                    rvis[v] = true;
                    r = v;
                    break;
                }
            }
        }
        bool flag = true;
        for (int i = 0; i < rcnt; i++) {
            if (h[i] != h[(i+2)%rcnt]) {
                flag = false;
                break;
            }
        }
        puts(flag ? "YES" : "NO");
    }
    return 0;
}