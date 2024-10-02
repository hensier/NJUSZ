// Submission: https://codeforces.com/group/fVoe9GOJPd/contest/523987/submission/284048831
// Verdict: Accepted
#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
    scanf("%d", &n);
    printf("%d", n % 2 ? 0 : 1 << (n / 2));
    return 0;
}