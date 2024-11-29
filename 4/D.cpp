// Submission: https://codeforces.com/group/fVoe9GOJPd/contest/533703/submission/292773839
// Verdict: Accepted
#include <bits/stdc++.h>
using namespace std;
int T, W, N, D, X[1001];
int gcd(int x, int y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}
void exgcd(int a, int b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return;
    }
    exgcd(b, a % b, x, y);
    int t = x;
    x = y;
    y = t - a / b * y;
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
    read(T);
    for (int id = 1; id <= T; id++) {
        read(W), read(N), read(D);
        for (int i = 1; i <= W; i++) read(X[i]);
        printf("Case #%d: ", id);
        int g = gcd(N, D), n = N / g;
        long long ans = 0;
        for (int i = 1; i <= W / 2; i++) {
            if ((X[i] - X[W-i+1]) % g != 0) {
                ans = -1;
                break;
            }
            long long x, y;
            int k = (X[i] - X[W-i+1]) / g;
            exgcd(D, N, x, y);
            x *= k;
            y *= k;
            x = (x % n + n) % n;
            ans += min(x, n - x);
        }
        if (ans == -1) puts("IMPOSSIBLE");
        else printf("%lld\n", ans);
    }
    return 0;
}