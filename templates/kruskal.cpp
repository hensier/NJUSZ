// 洛谷 P3366 【模板】最小生成树
// Submission: https://www.luogu.com.cn/record/181225200
// Time: 2024-10-10 15:53:21
#include <bits/stdc++.h>
using namespace std;
int N, M, cnt, ans, f[5001];
int find(int x) {
    if (f[x] == x) return x;
    return f[x] = find(f[x]);
}
struct edge {
    int u, v, w;
    bool operator<(const edge &x) const {
        return w < x.w;
    }
} e[200001];
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
    read(N), read(M);
    for (int i = 1; i <= N; i++) f[i] = i;
    for (int i = 1; i <= M; i++) read(e[i].u), read(e[i].v), read(e[i].w);
    sort(e + 1, e + M + 1);
    for (int i = 1; i <= M; i++) {
        int x = find(e[i].u), y = find(e[i].v);
        if (x != y) {
            f[x] = y;
            ans += e[i].w;
            if (++cnt == N - 1) {
                printf("%d", ans);
                return 0;
            }
        }
    }
    printf("orz");
    return 0;
}