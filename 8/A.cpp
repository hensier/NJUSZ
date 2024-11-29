// Submission: https://codeforces.com/group/fVoe9GOJPd/contest/556471/submission/285109503
// Verdict: Accepted
#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(20241010);
int main() {
    printf("100000 %d\n", rnd() % 100001 + 1);
    for (int i = 0; i < 100000; i++) putchar(rnd() % 26 + 'a');
    return 0;
}