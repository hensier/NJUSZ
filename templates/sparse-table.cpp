// 洛谷 P3865 【模板】ST 表 && RMQ 问题
// Submission: https://www.luogu.com.cn/record/184721228
// Time: 2024-10-25 15:34:21
#include <bits/stdc++.h>
using namespace std;
int N, M, st[100001][17];
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
    for (int i = 1; i <= N; i++) read(st[i][0]);
    for (int j = 1; (1 << j) <= N; j++) {
        for (int i = 1; i + (1 << j) - 1 <= N; i++) {
            st[i][j] = max(st[i][j-1], st[i+(1<<(j-1))][j-1]);
        }
    }
    for (int i = 1, l, r; i <= M; i++) {
        read(l), read(r);
        int j = log2(r - l + 1);
        write(max(st[l][j], st[r-(1<<j)+1][j]));
        pc('\n');
    }
    fwrite(obuf, p3 - obuf, 1, stdout);
    return 0;
}