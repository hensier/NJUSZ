// 洛谷 P5656 【模板】二元一次不定方程 (exgcd)
// Submission: https://www.luogu.com.cn/record/189923082
// Time: 2024-11-20 11:57:37
#include <bits/stdc++.h>
using namespace std;
int T, a, b, c;
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
        if (x < 0) {
            pc('-');
            x = -x;
        }
        if (x > 9) write(x / 10);
        pc(x % 10 + 48);
    }
    template<typename T, typename... Ts> void write(T x, Ts... xs) {
        write(x);
        pc(' ');
        write(xs...);
    }
} using namespace IO;
int main() {
    read(T);
    while (T--) {
        read(a), read(b), read(c);
        int g = gcd(a, b);
        if (c % g != 0) write(-1);
        else {
            long long x, y;
            int k = c / g, A = a / g, B = b / g;
            exgcd(a, b, x, y);
            x *= k;
            y *= k;
            if (x % B == 0) x = B;
            else x = ((x % B) + B) % B;
            if (a * x > c - b) {
                if (y % A == 0) y = A;
                else y = ((y % A) + A) % A;
                write(x, y);
            }
            else {
                long long n = ((c - b) / a - x) / B + 1, t = (c - a * x) / b;
                write(n, x);
                x += (n - 1) * B;
                pc(' ');
                write((c - a * x) / b, x, t);
            }
        }
        pc('\n');
    }
    fwrite(obuf, p3 - obuf, 1, stdout);
    return 0;
}