// 洛谷 P1480 A/B Problem
// Submission: https://www.luogu.com.cn/record/184168297
// Time: 2024-10-23 10:50:26
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
char a[5001], b[10], SUB[5001], EMUL[5001], DIV[5001];
void swap(char *x, char *y) {
    char t[5001];
    strcpy(t, x);
    strcpy(x, y);
    strcpy(y, t);
}
void reverse(char *s, int len) {
    for (char *l = s, *r = s + len - 1; l < r; l++, r--) {
        char t = *l;
        *l = *r;
        *r = t;
    }
}
void append(char *s, int ls, char c) {
    s[ls] = c;
    s[ls+1] = '\0';
}
bool smaller(char *a, char *b, int la, int lb) {
    if (la != lb) return la < lb;
    return strcmp(a, b) < 0;
}
char *subtract(char *a, char *b) {
    strcpy(SUB, a);
    bool neg = false;
    if (smaller(SUB, b, strlen(SUB), strlen(b))) {
        neg = true;
        swap(SUB, b);
    }
    int la = strlen(SUB), lb = strlen(b);
    reverse(SUB, la);
    reverse(b, lb);
    for (int i = 0; b[i]; i++) {
        SUB[i] -= b[i] - '0';
        if (!isdigit(SUB[i])) {
            SUB[i] += 10;
            SUB[i+1]--;
        }
    }
    for (int i = lb; SUB[i] && !isdigit(SUB[i]); i++) {
        SUB[i] += 10;
        SUB[i+1]--;
    }
    reverse(SUB, la);
    reverse(b, lb);
    int pos = 0;
    while (SUB[pos+1] && SUB[pos] == '0') pos++;
    char t[10088] = "";
    strncpy(t, SUB + pos, la - pos);
    strcpy(SUB, t);
    for (int i = la - pos; SUB[i]; i++) SUB[i] = '\0';
    if (neg) {
        strncpy(t, SUB, strlen(SUB));
        strcpy(SUB, t);
        memset(t, 0, sizeof(t));
        t[0] = '-';
        strcat(t, SUB);
        strcpy(SUB, t);
    }
    return SUB;
}
char *easy_mul(char *a, char b) {
    strcpy(EMUL, a);
    int la = strlen(EMUL), tmp = 0;
    reverse(EMUL, la);
    for (int i = 0; EMUL[i]; i++) {
        int x = (EMUL[i] - '0') * (b - '0') + tmp;
        EMUL[i] = x % 10 + '0';
        tmp = x / 10;
    }
    if (tmp) append(EMUL, la++, tmp + '0');
    reverse(EMUL, la);
    return EMUL;
}
char *div(char *a, char *b) {
    memset(DIV, 0, sizeof(DIV));
    int pa = -1, pd = 0, la, lb = strlen(b);
    char sa[5001] = "", sb[11][5001];
    do {
        pa++;
        sa[pa] = a[pa];
        la = pa + 1;
    } while (a[pa] && smaller(sa, b, la, lb));
    for (int i = 1; i <= 10; i++) strcpy(sb[i], easy_mul(b, i + '0'));
    do {
        int coef = 0;
        while (coef <= 9 && !smaller(sa, sb[coef+1], la, strlen(sb[coef+1]))) coef++;
        append(DIV, pd++, coef + '0');
        strcpy(sa, subtract(sa, sb[coef]));
        la = strlen(sa);
        append(sa, la++, a[++pa]);
        if (sa[0] == '0') {
            char t[5001] = "";
            strncpy(t, sa + 1, --la);
            strcpy(sa, t);
            for (int i = la + 1; sa[i]; i++) sa[i] = '\0';
        }
    } while (a[pa]);
    return DIV;
}
int main() {
    scanf("%s%s", a, b);
    printf("%s", div(a, b));
    return 0;
}