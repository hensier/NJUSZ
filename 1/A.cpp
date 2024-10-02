// Submission: https://codeforces.com/group/fVoe9GOJPd/contest/523987/submission/283964982
// Verdict: Accepted
#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
    scanf("%d", &n);
    printf("%lld", n & 1 ? 0 : 1LL << (n / 2));
    return 0;
}