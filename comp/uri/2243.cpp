#include <bits/stdc++.h>
#define _                        \
   ios_base::sync_with_stdio(0); \
   cin.tie(0);
#define endl '\n'
#define MAX 132456

using namespace std;

int n, an[MAX], esq[MAX], dir[MAX];

int main() {
    _;

    memset(an, 0, sizeof(an));
    memset(esq, 0, sizeof(esq));
    memset(dir, 0, sizeof(dir));

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> an[i];
    }

    esq[0] = min(1, an[0]);
    for (int i=1; i<n; i++) {
        esq[i] = min(an[i], esq[i-1]+1);
    }

    dir[n-1] = min(1, an[n-1]);
    for (int i=n-2; i>=0; i--) {
        dir[i] = min(an[i], dir[i+1]+1);
    }

    int res = 0;

    for (int i=0; i<n; i++) {
        res = max(res, min(esq[i], dir[i]));
    }

    cout << res << endl;
    

    return 0;
}