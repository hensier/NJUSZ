// 洛谷 P3803 【模板】多项式乘法（FFT）
// Submission: https://www.luogu.com.cn/record/182850545
// Time: 2024-10-18 10:16:53
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1 << 25;
const double pi = acos(-1);
int n, m, r[maxn | 1];
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
}; vector<comp> f[2], g;
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
vector<comp> mul(vector<comp> f, vector<comp> g) {
    int len = f.size() + g.size() - 2, N, l = 0;
    for (N = 1; N <= len; N <<= 1) l++;
    for (int i = 0; i < N; i++) r[i] = (r[i >> 1] >> 1) | ((i & 1) << (l - 1));
    for (int i = f.size(); i < N; i++) f.push_back((comp){0, 0});
    for (int i = g.size(); i < N; i++) g.push_back((comp){0, 0});
    f = FFT(f, N, 1);
    g = FFT(g, N, 1);
    for (int i = 0; i < N; i++) f[i] = f[i] * g[i];
    f = FFT(f, N, -1);
    for (int i = 0; i <= len; i++) {
        f[i].real = floor(f[i].real / N + 0.5);
        f[i].imag = 0;
    }
    for (int i = len + 1; i < N; i++) f[i] = (comp){0, 0};
    return f;
}
vector<comp> solve(int l, int r) {
    if (l == r) return mul(f[l], g);
    int mid = (l + r) >> 1;
    return mul(solve(l, mid), solve(mid + 1, r));
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
        f[0].push_back((comp){double(x), 0});
    }
    for (int i = 0, x; i <= m; i++) {
        read(x);
        f[1].push_back((comp){double(x), 0});
    }
    g.push_back((comp){1, 0});
    f[0] = solve(0, 1);
    for (int i = 0; i <= n + m; i++) {
        write(int(f[0][i].real));
        pc(' ');
    }
    fwrite(obuf, p3 - obuf, 1, stdout);
    return 0;
}