#include <bits/stdc++.h>
using namespace std;
int n, cnt, a[1001];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1, greater<int>());
    for (int i = 1; i <= n && a[i] == a[1]; i++, cnt++);
    printf(cnt & 1 ? "Alice" : "Bob");
    return 0;
}