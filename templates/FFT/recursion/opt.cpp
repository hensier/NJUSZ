// 洛谷 P3803 【模板】多项式乘法（FFT）
// Submission: https://www.luogu.com.cn/record/182744309
// Time: 2024-10-17 19:23:55
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1 << 25;
const double pi = acos(-1);
int n, m, N;
struct comp {
    double real, imag;
    comp operator+(const comp &x) const {
        return (comp){real + x.real, imag + x.imag};
    }
    comp operator-(const comp &x) const {
        return (comp){real - x.real, imag - x.imag};
    }
    comp operator*(const comp &x) const {
        return (comp){real * x.real - imag * x.imag, real * x.imag + imag * x.real};
    }
} f[maxn | 1], t[maxn | 1];
void FFT(comp *f, int len, int type) {
    if (len == 1) return;
    comp *fl = f, *fr = f + (len >> 1);
    for (int k = 0; k < len; k++) t[k] = f[k];
    for (int k = 0; k < (len >> 1); k++) {
        fl[k] = t[k << 1];
        fr[k] = t[k << 1 | 1];
    }
    FFT(fl, len >> 1, type);
    FFT(fr, len >> 1, type);
    comp tmp = (comp){1, 0};
    for (int k = 0; k < (len >> 1); k++) {
        t[k] = fl[k] + tmp * fr[k];
        t[k + (len >> 1)] = fl[k] - tmp * fr[k];
        tmp = tmp * (comp){cos(2 * pi / len), type * sin(2 * pi / len)};
    }
    for (int k = 0; k < len; k++) f[k] = t[k];
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
    for (int i = 0, x; i <= n; i++) {
        read(x);
        f[i].real = x;
    }
    for (int i = 0, x; i <= m; i++) {
        read(x);
        f[i].imag = x;
    }
    for (N = 1; N <= (max(n, m) << 1); N <<= 1);
    FFT(f, N, 1);
    for (int i = 0; i < N; i++) f[i] = f[i] * f[i];
    FFT(f, N, -1);
    for (int i = 0; i <= n + m; i++) {
        write(int(f[i].imag / N / 2 + 0.5));
        pc(' ');
    }
    fwrite(obuf, p3 - obuf, 1, stdout);
    return 0;
}