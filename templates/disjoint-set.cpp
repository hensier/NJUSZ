// 洛谷 P3367 【模板】并查集
// Submission: https://www.luogu.com.cn/record/181221837
// Time: 2024-10-10 15:36:18
#include <bits/stdc++.h>
using namespace std;
int N, M, f[10001];
int find(int x) {
    if (f[x] == x) return x;
    return f[x] = find(f[x]);
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
    read(N), read(M);
    for (int i = 1; i <= N; i++) f[i] = i;
    for (int i = 1, Z, X, Y; i <= M; i++) {
        read(Z), read(X), read(Y);
        if (Z == 1) f[find(X)] = find(Y);
        else puts(find(X) == find(Y) ? "Y" : "N");
    }
    return 0;
}