# [NJUSZ-Week2](https://codeforces.com/group/fVoe9GOJPd/contest/525673) Report $_\text{by hensier}$

|题号|题名|难度|原题|记录|首 A|
|:-:|:-:|:-:|:-:|:-:|:-:|
|A|Fetch Stone By Terms|$\color{f39c11}{普及-}$$^*$|N/A|[AC](https://codeforces.com/group/fVoe9GOJPd/contest/525673/submission/284055949)|2024-10-02 23:21|
|B|Fliptile|$\color{3498db}{提高+/省选-}$|[洛谷 P1985](https://www.luogu.com.cn/problem/P1985)|N/A $\to$ [AC](https://codeforces.com/group/fVoe9GOJPd/contest/525673/submission/284308898)|2024-10-04 20:38|
|C|McDonald|$\color{f39c11}{普及-}$$^*$|N/A|[AC](https://codeforces.com/group/fVoe9GOJPd/contest/525673/submission/286059539)|2024-10-02 22:12|
|D|Jumpy Dumpy!|$\color{f39c11}{普及-}$$^*$|N/A|[AC](https://codeforces.com/group/fVoe9GOJPd/contest/525673/submission/284050136)|2024-10-02 22:35|
|E|Buy Tickets|$\color{52c41a}{普及+/提高}$$^*$|[POJ 2828](http://poj.org/problem?id=2828)|N/A $\to$ [AC](https://codeforces.com/group/fVoe9GOJPd/contest/525673/submission/287848583)|2024-10-06 18:48|
|F|Meeting|$\color{f39c11}{普及-}$$^*$|N/A|[AC](https://codeforces.com/group/fVoe9GOJPd/contest/525673/submission/284053870)|2024-10-02 23:05|

---

### A. Fetch Stone By Terms

考虑石子数量不超过 $4$ 的特殊情形：当前剩余石子为 $1,2$ 或 $3$ 时，先手获胜；反之后手获胜。可以发现：

- 当 $k=0$ 时 $p^k=1$，模 $4$ 余 $1$。
- 当 $k=1$ 时 $p^k$ 为质数，模 $4$ 后的余数可以为 $1,2,3$，但不能为 $0$。

不妨将问题转化为：给定初始石子数量，每次可以取 $1 \sim 3$ 枚石子，求先手必胜还是后手必胜。则：

- 当石子数量为 $4$ 的倍数时，后手必胜：当先手取 $x$ （$x \bmod 4 \in \{1,2,3\}$）枚石子时，后手只要取 $4-x \bmod 4$ 枚，从而保证了当轮到先手时，石子的数量为 $4$ 的倍数，最终一定会依次仅剩下 $4$ 枚、$0$ 枚。因此后手必胜。
- 当石子数量不为 $4$ 的倍数时，先手必胜：先手可以先取 $x \bmod 4$ 枚石子，则转化为轮到后手时，石子的数量为 $4$ 的倍数，故先手必胜。

可见，答案仅与初始石子数量是否为 $4$ 的倍数有关。

- 时间复杂度：$\mathcal O(T)$。
- 空间复杂度：$\mathcal O(1)$。

```cpp
#include <bits/stdc++.h>
using namespace std;
int T, n;
int main() {
    read(T);
    while (T--) {
        read(n);
        puts(n % 4 ? "xly wins!" : "cyh wins!");
    }
    return 0;
}
```

---

### B. Fliptile

考虑枚举所有情形：每个格子最多被操作一次，总情况数为 $2^{MN} \le 2^{225}$，不可行。

不妨先枚举第一行的操作方式。第一行操作后，前两行的格子将受到影响。而为了让整个 $N \times M$ 矩阵均为 $0$，就必然要让第一行均为 $0$。

在对第一行进行操作后，对于第一行的格子，只有对其正下方的格子进行操作才能让自身格子被翻转。因此，为了确保第一行均为 $0$，在第一行的操作方式固定后，第二行的操作方式也随之确定。以此类推，第 $3 \sim M-1$ 行的操作方式也将被确定。而第 $M$ 行的操作必须同时让第 $M-1$ 行和第 $M$ 行均为 $0$，需进行判断。

最后记录最小翻转次数即可。

- 时间复杂度：$\mathcal O(MN \cdot 2^N) \approx \mathcal O( N^2 \cdot 2^N)$。
- 空间复杂度：$\mathcal O(MN)$。

```cpp
#include <bits/stdc++.h>
using namespace std;
int M, N, minf = 226, a[15][15], A[15][15], b[15][15], B[15][15];
int main() {
    scanf("%d%d", &M, &N);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < (1 << N); i++) {
        memcpy(A, a, sizeof(a));
        for (int j = 0; j < N; j++) b[0][j] = i >> (N - j - 1) & 1;
        for (int j = 0; j < M; j++) {
            if (j > 0) {
                for (int k = 0; k < N; k++) {
                    A[j][k] ^= b[j-1][k];
                }
            }
            for (int k = 0; k < N; k++) {
                if (k > 0) A[j][k-1] ^= b[j][k];
                A[j][k] ^= b[j][k];
                if (k < N - 1) A[j][k+1] ^= b[j][k];
            }
            if (j < M - 1) memcpy(b[j+1], A[j], sizeof(A[j]));
        }
        bool flag = true;
        for (int j = 0; j < N; j++) {
            if (A[M-1][j]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            int cur = 0;
            for (int j = 0; j < M; j++) {
                for (int k = 0; k < N; k++) {
                    cur += b[j][k];
                }
            }
            if (cur < minf) {
                minf = cur;
                memcpy(B, b, sizeof(b));
            }
        }
    }
    if (minf == 226) printf("IMPOSSIBLE");
    else {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) printf("%d ", B[i][j]);
            putchar('\n');
        }
    }
    return 0;
}
```

---

### C. McDonald

$$\sum_{i = 1} ^ n {i ^ 2}$$

$$=\sum_{i = 1} ^ n {i(i + 1)} - \sum_{i = 1} ^ n  i$$

$$=\sum_{i = 1} ^ n {\frac{3i(i + 1)}{3}} - \frac{n(n + 1)}{2}$$

$$=\sum_{i = 1} ^ n {i \cdot \frac{(i + 2)(i + 1) - (i - 1)(i + 1)}{3}} - \frac{n(n + 1)}{2}$$

$$=\sum_{i = 1} ^ n [{\frac{i(i + 1)(i + 2)}{3}} - \frac{(i - 1)i(i + 1)}{3}] - \frac{n(n + 1)}{2}$$

$$=\frac{1 \cdot 2 \cdot 3}{3} - \frac{0 \cdot 1 \cdot 2}{3} + \frac{2 \cdot 3 \cdot 4}{3} - \frac{1 \cdot 2 \cdot 3}{3} + \cdots + \frac{n(n + 1)(n + 2)}{3} - \frac{(n - 1)n(n + 1)}{3} - \frac{n(n + 1)}{2}$$

$$=\frac{(n - 1)n(n + 1)}{3} - 0 - \frac{n(n + 1)}{2}$$

$$=\frac{n(n + 1)(2n - 2) - 3n(n + 1)}{6}$$

$$=\frac{n(n + 1)(2n + 1)}{6}$$

由于 $n \le 10^{1000}$，需用高精度。

时空复杂度：$\mathcal O(\log N)$。

```cpp
#include <bits/stdc++.h>
using namespace std;
string n;
string add(string a, string b) {
    if (a.size() < b.size()) swap(a, b);
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for (int i = 0; b[i]; i++) {
        a[i] += b[i] - '0';
        if (!isdigit(a[i])) {
            a[i] -= 10;
            if (a.size() == b.size() && i == b.size() - 1) a += '1';
            else a[i+1]++;
        }
    }
    for (int i = b.size(); a[i] && !isdigit(a[i]); i++) {
        a[i] -= 10;
        if (i == a.size() - 1) a += '1';
        else a[i+1]++;
    }
    reverse(a.begin(), a.end());
    return a;
}
string easy_mul(string a, char b) {
    reverse(a.begin(), a.end());
    int tmp = 0;
    for (int i = 0; a[i]; i++) {
        int x = (a[i] - '0') * (b - '0') + tmp;
        a[i] = x % 10 + '0';
        tmp = x / 10;
    }
    if (tmp) a += (tmp + '0');
    reverse(a.begin(), a.end());
    return a;
}
string mul(string a, string b) {
    string ans = "0";
    for (int i = b.size() - 1; i >= 0; i--) {
        ans = add(ans, easy_mul(a, b[i]));
        a += "0";
    }
    int pos = 0;
    while (ans[pos+1] && ans[pos] == '0') pos++;
    return ans.substr(pos);
}
string easy_div(string a, char b) {
    string ans;
    bool flag = false;
    for (int i = 0; a[i]; ) {
        int A = a[i] - '0', B = b - '0';
        if (A == 0) {
            ans += '0';
            i++;
        }
        else if (A >= B) {
            flag = false;
            ans += A / B + '0';
            if (A % B == 0) {
                flag = true;
                i++;
            }
            else a[i] = A % B + '0';
        }
        else {
            if (flag) ans += '0';
            flag = false;
            A = A * 10 + (a[i+1] - '0');
            ans += A / B + '0';
            if (A % B == 0) {
                flag = true;
                i += 2;
            }
            else a[++i] = A % B + '0';
        }
    }
    return ans;
}
int main() {
    cin >> n;
    cout << easy_div(mul(mul(n, add(n, "1")), add(mul(n, "2"), "1")), '6');
    return 0;
}
```

---

### D. Jumpy Dumpy!

最优解为位于同一个长为 $K$ 的区间内的炸弹数量的最大值。

排序后，我们只需枚举以每个炸弹为区间左 / 右端点。得到对应的右 / 左端点后，通过二分可以获取位于区间内最大 / 小的炸弹。最后按照序号差统计答案即可。

- 时间复杂度：$\mathcal O(N \log N)$。
- 空间复杂度：$\mathcal O(N)$。

```cpp
#include <bits/stdc++.h>
using namespace std;
int N, K, ans, jd[1001];
int main() {
    scanf("%d%d", &N, &K);
    for (int i = 1; i <= N; i++) scanf("%d", &jd[i]);
    sort(jd + 1, jd + N + 1);
    for (int i = 1; i <= N; i++) {
        int pos = upper_bound(jd + i + 1, jd + N + 1, jd[i] + K) - jd - 1;
        ans = max(ans, pos - i + 1);
    }
    printf("%d", ans);
    return 0;
}
```

---

### E. Buy Tickets

每次入队后所在的位置为 $P_i = Pos_i + 1$。当后续有人的 $Pos_j$ 小于 $P_i$ 后，仍有 $P_j = Pos_j + 1$，但 $P_i$ 将 $+1$。

如果正向模拟，我们将难以考虑到 $P_i$ 需要 $+1$ 的情形，因为后面的总会影响到前面的。

因此，考虑倒着跑。我们先构造一个全 $1$ 的数组 $a$。当第 $n$ 个人入队时，其位置即为 $Pos_n + 1$。虽然自身不受影响，但这将影响第 $1 \sim n - 1$ 个人的位置。不妨将 $a_{Pos_n + 1}$ 减 $1$。

接着，当第 $i$ 个人入队时，为了判断其位置是否在 $Pos_{i+1} + 1$ 之后，我们可以二分求出第一个 $\sum_{i = 1} ^ k a_i \le Pos_i + 1$ 的 $k$。$k$ 即为 $P_i$。随后将 $a_{P_i}$ 减 $1$，重复直至第 $1$ 个人入队。

对 $a_i$ 求和的过程可用树状数组、线段树等维护。

- 时间复杂度：$\mathcal O(\sum (N \log^2 N))$。
- 空间复杂度：$\mathcal O(N)$。

```cpp
#include <bits/stdc++.h>
using namespace std;
int N, t[200001];
int lowbit(int x) {
    return x & (-x);
}
void add(int x, int c) {
    for (int i = x; i <= N; i += lowbit(i)) t[i] += c;
}
int query(int x) {
    int s = 0;
    for (int i = x; i; i -= lowbit(i)) s += t[i];
    return s;
}
int find(int x) {
    int l = 1, r = N;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (query(mid) >= x) r = mid - 1;
        else l = mid + 1;
    }
    return l;
}
struct person {
    int pos, val, id;
    bool operator<(const person &x) const {
        return id < x.id;
    }
} p[200001];
int main() {
    while (read(N)) {
        for (int i = 1; i <= N; i++) {
            read(p[i].pos), read(p[i].val);
            p[i].pos++;
        }
        memset(t, 0, sizeof(t));
        for (int i = 1; i <= N; i++) add(i, 1);
        for (int i = N; i; i--) {
            p[i].id = find(p[i].pos);
            add(p[i].id, -1);
        }
        sort(p + 1, p + N + 1);
        for (int i = 1; i <= N; i++) write(p[i].val), pc(' ');
        pc('\n');
    }
    fwrite(obuf, p3 - obuf, 1, stdout);
    return 0;
}
```

---

### F. Meeting

我们只需对两种边权分别进行 dfs，就能求出各自所需时间的所有可能值。最后进行比对即可。

- 时间复杂度：$\mathcal O(M) \approx \mathcal O(N^2)$。
- 空间复杂度：$\mathcal O(N + M) \approx \mathcal O(N^2)$。

```cpp
#include <bits/stdc++.h>
using namespace std;
int N, M, cnt, head[17];
vector<int> v[2];
struct node {
    int nxt, to, w[2];
} e[121];
void add_edge(int A, int B, int C, int D) {
    e[++cnt] = (node){head[A], B, {C, D}};
    head[A] = cnt;
}
void dfs(int u, int tot, int type) {
    if (u == N) {
        v[type].push_back(tot);
        return;
    }
    for (int i = head[u]; i; i = e[i].nxt) dfs(e[i].to, tot + e[i].w[type], type);
}
int main() {
    scanf("%d%d", &N, &M);
    for (int i = 1, A, B, C, D; i <= M; i++) {
        scanf("%d%d%d%d", &A, &B, &C, &D);
        add_edge(A, B, C, D);
    }
    for (int i = 0; i < 2; i++) dfs(1, 0, i);
    if (v[0].empty()) {
        printf("IMPOSSIBLE");
        return 0;
    }
    for (int i = 0; i < 2; i++) sort(v[i].begin(), v[i].end());
    for (int i = 0; i < v[0].size(); i++) {
        int pos = lower_bound(v[1].begin(), v[1].end(), v[0][i]) - v[1].begin();
        if (v[1][pos] == v[0][i]) {
            printf("%d", v[0][i]);
            return 0;
        }
    }
    printf("IMPOSSIBLE");
    return 0;
}
```

---