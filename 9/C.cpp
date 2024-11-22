// Submission: https://codeforces.com/group/fVoe9GOJPd/contest/567353/submission/292464057
// Verdict: Accepted
#include <bits/stdc++.h>
using namespace std;
int n, m, sum;
int exgcd(int a, int b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int g = exgcd(b, a % b, x, y), t = x;
    x = y;
    y = t - a / b * y;
    return g;
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
    read(n), read(m);
    for (int i = 1, a; i <= n; i++) {
        read(a);
        sum = (sum + a) % m;
    }
    int N = 1LL * n * (n + 1) / 2 % m;
    long long s, d, x, y;
    int g = exgcd(n, N, s, d), G = exgcd(g, m, x, y);
    x *= sum / G;
    y *= sum / G;
    s = (m - s % m * (x % m) % m) % m;
    d = (m - d % m * (x % m) % m) % m;
    printf("%d\n%lld %lld", sum % G, s, d);
    return 0;
}