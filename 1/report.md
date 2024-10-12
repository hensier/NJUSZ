# [NJUSZ-Week1](https://codeforces.com/group/fVoe9GOJPd/contest/523987) Report $_\text{by hensier}$

|题号|题名|难度|原题|记录|首 A|
|:-:|:-:|:-:|:-:|:-:|:-:|
|A|Filling Shapes|$\color{fe4c61}{入门}$|[CF1182A](https://codeforces.com/problemset/problem/1182/A)|[AC](https://codeforces.com/group/fVoe9GOJPd/contest/523987/submission/284048831)|2024-10-01 23:43|
|B|Find the Car|$\color{f39c11}{普及-}$|[CF1971E](https://codeforces.com/problemset/problem/1971/E)|[AC](https://codeforces.com/group/fVoe9GOJPd/contest/523987/submission/283930821)|2024-10-02 00:21|
|C|Download Speed Monitor|$\color{f39c11}{普及-}$$^*$|[JCPC 2024 F](https://codeforces.com/gym/105161/problem/F)|[AC](https://codeforces.com/group/fVoe9GOJPd/contest/523987/submission/283928670)|2024-10-02 00:29|
|D|XOUR|$\color{ffc116}{普及/提高-}$|[CF1971G](https://codeforces.com/problemset/problem/1971/G)|[AC](https://codeforces.com/group/fVoe9GOJPd/contest/523987/submission/285300153)|2024-10-02 00:51|
|E|Number Deletion Game|$\color{52c41a}{普及+/提高}$$^*$|[JCPC 2024 K](https://codeforces.com/gym/105161/problem/K)|[AC](https://codeforces.com/group/fVoe9GOJPd/contest/523987/submission/285395231)|2024-10-02 10:20|
|F|DIDA's Secret Room|$\color{ffc116}{普及/提高-}$$^*$|N/A|[MLE](https://codeforces.com/group/fVoe9GOJPd/contest/523987/submission/283966839) $\to$ [AC](https://codeforces.com/group/fVoe9GOJPd/contest/523987/submission/284048198)|2024-10-02 22:20|

---

### A. Filling Shapes

一个小单元无论如何摆放，都一定会填充 $3$ 格，其中一列 $2$ 格，一列 $1$ 格。

因此，为了恰好铺满同列中的 $3$ 格，就需要用到两个小单元，一个在此列填充 $2$ 格，另一个填充 $1$ 格。于此同时，相邻的一列也会恰好被填满。

于是，可先考虑 $3 \times 2$ 的区域，共有 $2$ 种填充方案。

1. 当 $n$ 为偶数时，$3 \times n$ 由 $\frac{n}{2}$ 个 $3 \times 2$ 区域构成，故总方案数为 $2^\frac{n}{2}$。

2. 当 $n$ 为奇数时，由于对每列填充完后，一定会影响到相邻的一列，因此无法填充。

时空复杂度： $\mathcal O(1)$。

```cpp
#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
    scanf("%d", &n);
    printf("%d", n % 2 ? 0 : 1 << (n / 2));
    return 0;
}
```

---

### B. Find the Car

对于每次询问，先二分找到被询问的距离位于哪个区间内，再进一步计算。

- 时间复杂度：$\mathcal O(\sum k + (\sum q) \log k) \approx \mathcal O(k \log k)$。
- 空间复杂度：$\mathcal O(k)$。

```cpp
#include <bits/stdc++.h>
using namespace std;
int t, n, k, q, d, a[100001], b[100001];
int main() {
    read(t);
    while (t--) {
        read(n), read(k), read(q);
        for (int i = 1; i <= k; i++) read(a[i]);
        for (int i = 1; i <= k; i++) read(b[i]);
        while (q--) {
            read(d);
            if (d == 0) pc('0'), pc(' ');
            else {
                int pos = lower_bound(a + 1, a + k + 1, d) - a;
                write(b[pos-1] + 1LL * (d - a[pos-1]) * (b[pos] - b[pos-1]) / (a[pos] - a[pos-1]));
                pc(' ');
            }
        }
        pc('\n');
    }
    fwrite(obuf, p3 - obuf, 1, stdout);
    return 0;
}
```

---

### C. Download Speed Monitor

利用前缀和单次询问 $\mathcal O(1)$ 求固定值的区间和。

时空复杂度：$\mathcal O(n)$。

```cpp
#include <bits/stdc++.h>
using namespace std;
int n, k;
long long s[100001];
int main() {
    read(n), read(k);
    for (int i = 1, a; i <= n; i++) {
        read(a);
        s[i] = s[i-1] + a;
    }
    for (int i = k; i <= n; i++) {
        double ans = 1.0 * (s[i] - s[i - k]) / k;
        if (ans >= 1024) printf("%.6lf MiBps\n", ans / 1024);
        else printf("%.6lf KiBps\n", ans);
    }
    return 0;
}
```

---

### D. XOUR

考虑 $x~\mathsf{XOR}~y$ 的含义：分别对二进制下 $x,y$ 的每一位都进行运算，相同为 $0$，不同为 $1$。

$a_i~\mathsf{XOR}~a_j \lt 4 = (100)_2$ 等价于 $a_i~\mathsf{XOR}~a_j \le 3 = (011)_2$。因而，如果该式成立，那么只允许二进制下的 $a_i,a_j$ 在末两位不同。即 $a_i~\mathsf{rsh}~2 = a_j~\mathsf{rsh}~2$。

我们可以以 $a_i~\mathsf{rsh}~2$ 为依据进行分组，同组内部按照从小到大的顺序输出即可。

- 时间复杂度：$\mathcal O(\sum (n \log n)) \approx \mathcal O(n \log n)$。
- 空间复杂度：$\mathcal O(n)$。

```cpp
#include <bits/stdc++.h>
using namespace std;
int t, n, cnt, a[200001];
map<int, int> mp;
vector<int> v[200001];
int main() {
    read(t);
    while (t--) {
        read(n);
        cnt = 0;
        mp.clear();
        for (int i = 1; i <= n; i++) v[i].clear();
        for (int i = 1; i <= n; i++) {
            read(a[i]);
            if (mp.find(a[i] >> 2) == mp.end()) mp[a[i] >> 2] = ++cnt;
            v[mp[a[i] >> 2]].push_back(a[i]);
        }
        for (int i = 1; i <= cnt; i++) {
            v[i].push_back(0);
            sort(v[i].begin(), v[i].end());
        }
        for (int i = 1; i <= n; i++) {
            int id = mp[a[i] >> 2];
            write(v[id][++v[id][0]]);
            pc(' ');
        }
        pc('\n');
    }
    fwrite(obuf, p3 - obuf, 1, stdout);
    return 0;
}
```

---

### E. Number Deletion Game

考虑特殊情形：若只有一个数，则先手玩家获胜。

- 当**最大数**的数量为**奇数**时：经过**奇数**次操作后，新的最大数出现。Alice 作为先手，可以控制**次大数**的数量始终为**偶数**：

    - 若初始次大数的数量为奇数，则在删去一个最大数后添加次大数。
    - 若初始次大数的数量为偶数，则在删去一个最大数后不添加次大数。

在 Alice 的第一回合结束后，无论 Bob 对次大数数量的奇偶性的影响如何，Alice 都能在下一回合使次大数的数量为偶数。

当所有的最大数被取完后，应轮到 Bob。此时，**新的最大数**（即**原次大数**）的数量为偶数。则 Bob 无论如何操作，在他的回合结束后，**最大数**的数量必为**奇数**。此时恰轮到 Alice，这与初始情况等价，因此 Alice 在轮到自己时，可以一直维持**最大数**的数量为**奇数**，**次大数**的数量为**偶数**。

因此，最终 Alice 可以保证只剩下一个数（此时**最大数**的数量为 $1$，是**奇数**）的时候轮到自己，从而获胜。

- 当**最大数**的数量为**偶数**时：Alice 无论如何操作，在她的回合结束后，**最大数**的数量必为**奇数**。即等价于 Bob 先手时**最大数**的数量为**奇数**。此时 Bob 有必胜策略。

时空复杂度：$\mathcal O(n)$。

```cpp
#include <bits/stdc++.h>
using namespace std;
int n, maxa, cnt, a[1001];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        maxa = max(maxa, a[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] == maxa) {
            cnt++;
        }
    }
    printf(cnt & 1 ? "Alice" : "Bob");
    return 0;
}
```

---

### F. DIDA's Secret Room

每一个状态有两个自由度：当前所处的房间号和拥有的钥匙，因此总状态数为 $N \cdot 2^K$。又考虑到要求通过传送门数量的最小值，故使用 bfs。

时空复杂度：$\mathcal O(N \cdot 2^K)$。

```cpp
#include <bits/stdc++.h>
using namespace std;
int N, M, K, room[5001];
bool vis[5001][1024];
vector<pair<int, int>> portal[5001];
struct node {
    int x, val, cnt;
}; queue<node> q;
int main() {
    read(N), read(M), read(K);
    for (int i = 1; i <= N; i++) {
        for (int j = 1, x; j <= K; j++) {
            read(x);
            room[i] = (room[i] << 1) | x;
        }
    }
    for (int i = 1, x, y; i <= M; i++) {
        read(x), read(y);
        int val = 0;
        for (int j = 1, z; j <= K; j++) {
            read(z);
            val = (val << 1) | z;
        }
        portal[x].push_back({y, val});
    }
    q.push((node){1, 0, 0});
    while (q.size()) {
        node f = q.front();
        q.pop();
        f.val |= room[f.x];
        if (vis[f.x][f.val]) continue;
        vis[f.x][f.val] = true;
        if (f.x == N) {
            printf("%d", f.cnt);
            return 0;
        }
        for (pair<int, int> p: portal[f.x]) {
            if ((f.val & p.second) == p.second) {
                q.push((node){p.first, f.val, f.cnt + 1});
            }
        }
    }
    printf("No Solution");
    return 0;
}
```
---