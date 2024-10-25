# [NJUSZ-Week3](https://codeforces.com/group/fVoe9GOJPd/contest/526673) Report $_\text{by hensier}$

|题号|题名|难度|原题|记录|首 A|
|:-:|:-:|:-:|:-:|:-:|:-:|
|A|YetnotherrokenKeoard|$\color{fe4c61}{入门}$|[CF1907B](https://codeforces.com/problemset/problem/1907/B)|[AC](https://codeforces.com/group/fVoe9GOJPd/contest/526673/submission/284107478)|2024-10-03 10:36|
|B|Rectangle Filling|$\color{f39c11}{普及-}$|[CF1966B](https://codeforces.com/problemset/problem/1966/B)|[AC](https://codeforces.com/group/fVoe9GOJPd/contest/526673/submission/284178353)|2024-10-03 21:35|
|C|Beautiful Triple Pairs|$\color{ffc116}{普及/提高-}$|[CF1974C](https://codeforces.com/problemset/problem/1974/C)|[AC](https://codeforces.com/group/fVoe9GOJPd/contest/526673/submission/284110718)|2024-10-03 11:24|
|D|Money Buys Happiness|$\color{ffc116}{普及/提高-}$|[CF1974E](https://codeforces.com/problemset/problem/1974/E)|[AC](https://codeforces.com/group/fVoe9GOJPd/contest/526673/submission/284188675)|2024-10-03 22:41|

---

### A. YetnotherrokenKeoard

用两个栈分别维护大小写字母即可。

时空复杂度：$\mathcal O(\sum |s|)$。

```cpp
#include <bits/stdc++.h>
using namespace std;
int t, cnt;
char s[1000001];
struct node {
    char c;
    int id;
    bool operator<(const node &x) const {
        return id < x.id;
    }
}; vector<node> upper, lower;
int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%s", s);
        cnt = 0;
        upper.clear();
        lower.clear();
        for (int i = 0; s[i]; i++) {
            switch (s[i]) {
                case 'B': {
                    if (upper.size()) upper.pop_back();
                    break;
                }
                case 'b': {
                    if (lower.size()) lower.pop_back();
                    break;
                }
                default: {
                    if (isupper(s[i])) upper.push_back((node){s[i], ++cnt});
                    else lower.push_back((node){s[i], ++cnt});
                }
            }
        }
        while (lower.size()) {
            upper.push_back(lower.back());
            lower.pop_back();
        }
        sort(upper.begin(), upper.end());
        for (int i = 0; i < upper.size(); i++) putchar(upper[i].c);
        putchar('\n');
    }
    return 0;
}
```

[官方题解](https://codeforces.com/blog/entry/123012)提供的另一种做法：倒着跑，遇到一个 $\text{B / b}$ 就跳过接下来的一个大 / 小写字母。

---

### B. Rectangle Filling

每次操作，左上顶点 $x,y$ 尽可能小的情况总优于 $x$ 或 $y$ 稍大时。则候选顶点可为 $x$ 为第一关键字最小、$y$ 为第二关键字最小；以及 $y$ 为第一关键字最小、$x$ 为第二关键字最小。

同理，右上、左下、右下的候选顶点也各有 $2$ 个，共 $8$ 个。

因此，我们只需对 $n \times m$ 矩形中的每个格点进行判断，如果存在一个格点不在任何一个由候选顶点组成的矩形中，则无解。

时空复杂度：$\mathcal O(\sum (nm))$。

```cpp
#include <bits/stdc++.h>
using namespace std;
int t, n, m;
pair<int, int> xy, xY, Xy, XY, yx, yX, Yx, YX;
char s[501];
bool b[501][501];
bool check(bool f) {
    xy = yx = {n, m};
    xY = Yx = {n, 1};
    Xy = yX = {1, m};
    XY = YX = {1, 1};
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (b[i][j] == f) {
                if (i < xy.first || (i == xy.first && j < xy.second)) xy = {i, j};
                if (i < xY.first || (i == xY.first && j > xY.second)) xY = {i, j};
                if (i > Xy.first || (i == Xy.first && j < Xy.second)) Xy = {i, j};
                if (i > XY.first || (i == XY.first && j > XY.second)) XY = {i, j};
                if (j < yx.second || (j == yx.second && i < yx.first)) yx = {i, j};
                if (j < yX.second || (j == yX.second && i > yX.first)) yX = {i, j};
                if (j > Yx.second || (j == Yx.second && i < Yx.first)) Yx = {i, j};
                if (j > YX.second || (j == YX.second && i > YX.first)) YX = {i, j};
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (b[i][j] == !f) {
                if (i >= xy.first && j >= xy.second && i <= XY.first && j <= XY.second) continue;
                if (i >= xy.first && j >= xy.second && i <= YX.first && j <= YX.second) continue;
                if (i >= yx.first && j >= yx.second && i <= XY.first && j <= XY.second) continue;
                if (i >= yx.first && j >= yx.second && i <= YX.first && j <= YX.second) continue;
                if (i <= Xy.first && j >= Xy.second && i >= xY.first && j <= xY.second) continue;
                if (i <= Xy.first && j >= Xy.second && i >= Yx.first && j <= Yx.second) continue;
                if (i <= yX.first && j >= yX.second && i >= xY.first && j <= xY.second) continue;
                if (i <= yX.first && j >= yX.second && i >= Yx.first && j <= Yx.second) continue;
                return false;
            }
        }
    }
    return true;
}
int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) {
            scanf("%s", s + 1);
            for (int j = 1; j <= m; j++) b[i][j] = (s[j] == 'W');
        }
        puts((check(false) || check(true)) ? "YES": "NO");
    }
    return 0;
}
```

[官方题解](https://codeforces.com/blog/entry/128914)的做法：先考虑整个 $n \times m$ 矩形的四角。若两个对角均分别不同色，则四角必为两黑两白，且同色共行或共列，有 $4$ 种可能。但它们经过旋转后都重合，故不妨只考虑上两白、下两黑的一种。

若第一行有黑格，那么该格与左下格和右下格可分别圈出两个矩形，从而覆盖整个 $N \times M$ 矩形。同理，若最后一行有白格，也能实现全覆盖。

否则，第一行全白、最后一行全黑。此时，第一行不可能变黑，因为第一行无黑格。同理，最后一行不可能变白。因此，在这种情况下不可能实现全覆盖。

---

### C. Beautiful Triple Pairs

用 map、vector 来维护三种优美对，最后进行计数。

- 时间复杂度：$\mathcal O(\sum (n \log n)) \approx \mathcal O(n \log n)$。
- 空间复杂度：$\mathcal O(\sum n) \approx \mathcal O(n)$。

```cpp
#include <bits/stdc++.h>
using namespace std;
int t, n, a[200001], cnt[3];
vector<int> v[3][200001];
map<pair<int,int>, int> mp[3];
int main() {
    read(t);
    while (t--) {
        read(n);
        for (int i = 1; i <= n; i++) read(a[i]);
        for (int i = 0; i < 3; i++) {
            for (int j = 1; j <= cnt[i]; j++) v[i][j].clear();
            cnt[i] = 0;
            mp[i].clear();
        }
        for (int i = 2; i < n; i++) {
            if (mp[0].find({a[i], a[i+1]}) == mp[0].end()) mp[0][{a[i], a[i+1]}] = ++cnt[0];
            v[0][mp[0][{a[i], a[i+1]}]].push_back(a[i-1]);
        }
        for (int i = 2; i < n; i++) {
            if (mp[1].find({a[i-1], a[i+1]}) == mp[1].end()) mp[1][{a[i-1], a[i+1]}] = ++cnt[1];
            v[1][mp[1][{a[i-1], a[i+1]}]].push_back(a[i]);
        }
        for (int i = 2; i < n; i++) {
            if (mp[2].find({a[i-1], a[i]}) == mp[2].end()) mp[2][{a[i-1], a[i]}] = ++cnt[2];
            v[2][mp[2][{a[i-1], a[i]}]].push_back(a[i+1]);
        }
        long long ans = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 1; j <= cnt[i]; j++) {
                sort(v[i][j].begin(), v[i][j].end());
                vector<int> u;
                int lst = 0;
                for (int k = 0; k < v[i][j].size(); k++) {
                    if (k && v[i][j][k] != v[i][j][k-1]) {
                        u.push_back(k - lst);
                        lst = k;
                    }
                }
                u.push_back(v[i][j].size() - lst);
                long long cur = 0;
                for (int k = 0; k < u.size(); k++) cur += 1LL * u[k] * (v[i][j].size() - u[k]);
                ans += cur / 2;
            }
        }
        write(ans);
        pc('\n');
    }
    fwrite(obuf, p3 - obuf, 1, stdout);
    return 0;
}
```

---

### D. Money Buys Happiness

背包递推式：

$$f_{1,0} = 0$$

$$f_{i,j} = \max\{f_{i-1,j} + x, f_{i-1,j-h_i} + x - c_i\}$$

时空复杂度：$\mathcal O(m \sum h_i)$。

```cpp
#include <bits/stdc++.h>
using namespace std;
int t, m, x, c[51], h[51];
long long f[51][50001];
int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &m, &x);
        long long sumh = 0;
        for (int i = 1; i <= m; i++) {
            scanf("%d%d", &c[i], &h[i]);
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
```

---