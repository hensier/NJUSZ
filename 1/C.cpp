#include <bits/stdc++.h>
using namespace std;
int n, k;
long long s[100001];
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
    read(n), read(k);
    for (int i = 1, a; i <= n; i++) {
        read(a);
        s[i] = s[i-1] + a;
    }
    for (int i = k; i <= n; i++) {
        double ans = 1.0 * (s[i] - s[i - k]) / k;
        if (ans >= 1024) printf("%.6lf MiBps\n", ans / 1024);
        else printf("%.6lf KiBps\n", ans);
    }
    return 0;
}