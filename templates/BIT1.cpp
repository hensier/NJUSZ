// 洛谷 P3374 【模板】树状数组 1
// Submission: https://www.luogu.com.cn/record/180308870
// Verdict: Accepted
#include <bits/stdc++.h>
using namespace std;
int n, m, t[500001];
int lowbit(int x) {
    return x & (-x);
}
void add(int x, int c) {
    for (int i = x; i <= n; i += lowbit(i)) t[i] += c;
}
int query(int x) {
    int s = 0;
    for (int i = x; i; i -= lowbit(i)) s += t[i];
    return s;
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
    read(n), read(m);
    for (int i = 1, a; i <= n; i++) {
        read(a);
        add(i, a);
    }
    for (int i = 1, op, x, y; i <= m; i++) {
        read(op), read(x), read(y);
        if (op == 1) add(x, y);
        else {
            write(query(y) - query(x - 1));
            pc('\n');
        }
    }
    fwrite(obuf, p3 - obuf, 1, stdout);
    return 0;
}