// 洛谷 P3803 【模板】多项式乘法（FFT）
// Submission: https://www.luogu.com.cn/record/182749913
// Time: 2024-10-17 19:37:21
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1 << 25;
const double pi = acos(-1);
int n, m, N, l, a[1000001], b[1000001], r[maxn | 1];
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
}; vector<comp> f;
vector<comp> FFT(vector<comp> f, int N, int type) {
    for (int i = 0; i < N; i++) {
        if (i < r[i]) {
            swap(f[i], f[r[i]]);
        }
    }
    for (int i = 1; i < N; i <<= 1) {
        for (int j = 0; j < N; j += (i << 1)) {
            comp tmp = (comp){1, 0};
            for (int k = 0; k < i; k++) {
                comp p = f[j+k], q = tmp * f[j+k+i];
                f[j+k] = p + q;
                f[j+k+i] = p - q;
                tmp = tmp * (comp){cos(pi / i), type * sin(pi / i)};
            }
        }
    }
    return f;
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
    for (int i = 0; i <= n; i++) read(a[i]);
    for (int i = 0; i <= m; i++) read(b[i]);
    for (int i = 0; i <= max(n, m); i++) f.push_back((comp){double(a[i]), double(b[i])});
    for (N = 1; N <= (max(n, m) << 1); N <<= 1) l++;
    for (int i = 0; i < N; i++) r[i] = (r[i >> 1] >> 1) | ((i & 1) << (l - 1));
    for (int i = max(n, m) + 1; i < N; i++) f.push_back((comp){0, 0});
    f = FFT(f, N, 1);
    for (int i = 0; i < N; i++) f[i] = f[i] * f[i];
    f = FFT(f, N, -1);
    for (int i = 0; i <= n + m; i++) {
        write(int(f[i].imag / N / 2 + 0.5));
        pc(' ');
    }
    fwrite(obuf, p3 - obuf, 1, stdout);
    return 0;
}