#include <bits/stdc++.h>
using namespace std;
int t, m, x, c[51], h[51];
long long f[51][50001];
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
        read(m), read(x);
        long long sumh = 0;
        for (int i = 1; i <= m; i++) {
            read(c[i]), read(h[i]);
            sumh += h[i];
        }
        memset(f, -1, sizeof(f));
        f[1][0] = 0;
        for (int i = 2; i <= m; i++) {
            for (int j = 0; j <= sumh; j++) {
                if (f[i-1][j] >= 0) {
                    f[i][j] = f[i-1][j] + x;
                }
            }
            for (int j = h[i]; j <= sumh; j++) {
                if (f[i-1][j-h[i]] >= 0) {
                    f[i][j] = max(f[i][j], f[i-1][j-h[i]] + x - c[i]);
                }
            }
        }
        for (int i = sumh; i >= 0; i--) {
            if (f[m][i] >= 0) {
                printf("%d\n", i + (c[1] == 0 ? h[1] : 0));
                break;
            }
        }
    }
    return 0;
}