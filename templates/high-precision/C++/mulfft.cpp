// 洛谷 P1919 【模板】高精度乘法 | A*B Problem 升级版
// Submission: https://www.luogu.com.cn/record/182782723
// Time: 2024-10-17 20:47:06
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1 << 25;
const double pi = acos(-1);
char ch, a[1000001], b[1000001];
int n, m, N, l, len, r[maxn | 1], ans[2000001];
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
} f[maxn | 1];
void FFT(comp *f, int N, int type) {
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
    void pc(char c) {
        if (p3 - obuf < (1 << 21)) *p3++ = c;
        else {
            fwrite(obuf, p3 - obuf, 1, stdout);
            p3 = obuf;
            *p3++ = c;
        }
    }
} using namespace IO;
int main() {
    while (ch = gc()) {
        if (!isdigit(ch)) break;
        a[n++] = ch;
    }
    while (!isdigit(ch)) ch = gc();
    while (isdigit(ch)) {
        b[m++] = ch;
        ch = gc();
    }
    for (int i = 0; i < n; i++) f[i].real = a[n - i - 1] ^ 48;
    for (int i = 0; i < m; i++) f[i].imag = b[m - i - 1] ^ 48;
    for (N = 1; N <= (max(n, m) << 1); N <<= 1) l++;
    for (int i = 0; i < N; i++) r[i] = (r[i >> 1] >> 1) | ((i & 1) << (l - 1));
    FFT(f, N, 1);
    for (int i = 0; i < N; i++) f[i] = f[i] * f[i];
    FFT(f, N, -1);
    len = n + m;
    for (int i = 0; i <= n + m; i++) {
        ans[i] += int(f[i].imag / N / 2 + 0.5);
        if (ans[i] > 9) {
            ans[i+1] += ans[i] / 10;
            ans[i] %= 10;
            if (i == n + m) len++;
        }
    }
    bool flag = false;
    for (int i = len; i >= 0; i--) {
        if (ans[i] != 0) flag = true;
        if (flag) pc(ans[i] + 48);
    }
    fwrite(obuf, p3 - obuf, 1, stdout);
    return 0;
}