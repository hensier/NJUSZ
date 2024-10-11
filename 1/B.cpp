#include <bits/stdc++.h>
using namespace std;
int t, n, k, q, d, a[100001], b[100001];
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
        read(n), read(k), read(q);
        for (int i = 1; i <= k; i++) read(a[i]);
        for (int i = 1; i <= k; i++) read(b[i]);
        while (q--) {
            read(d);
            if (d == 0) pc('0'), pc(' ');
            else {
                int pos = lower_bound(a + 1, a + k + 1, d) - a;
                write(b[pos-1] + 1LL * (d - a[pos-1]) * (b[pos] - b[pos-1]) / (a[pos] - a[pos-1]));
                pc(' ');
            }
        }
        pc('\n');
    }
    fwrite(obuf, p3 - obuf, 1, stdout);
    return 0;
}