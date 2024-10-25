// 洛谷 P1177 【模板】排序
// Submission: https://www.luogu.com.cn/record/182859466
// Time: 2024-10-18 11:19:16
#include <bits/stdc++.h>
using namespace std;
int n, a[100000], t[100000];
void merge_sort(int l, int r) {
    if (l == r) return;
    int mid = (l + r) >> 1;
    merge_sort(l, mid);
    merge_sort(mid + 1, r);
    for (int i = l; i <= r; i++) t[i-l] = a[i];
    for (int i = 0, j = mid - l + 1, k = l; k <= r; k++) {
        if (i == mid - l + 1) a[k] = t[j++];
        else if (j == r - l + 1) a[k] = t[i++];
        else if (t[i] < t[j]) a[k] = t[i++];
        else a[k] = t[j++];
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
    read(n);
    for (int i = 0; i < n; i++) read(a[i]);
    merge_sort(0, n - 1);
    for (int i = 0; i < n; i++) {
        write(a[i]);
        pc(' ');
    }
    fwrite(obuf, p3 - obuf, 1, stdout);
    return 0;
}