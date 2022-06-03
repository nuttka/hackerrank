#include <bits/stdc++.h>
#define _                        \
   ios_base::sync_with_stdio(0); \
   cin.tie(0);
#define endl '\n'
#define MAX 999
#define INF 0x3f3f3f

using namespace std;


long long n, k;
long long seq[MAX];
long long dp[MAX][MAX];
// map<string, bool> cc;


long long solve() {
    long long int res = 0;

    for (long long int i=2; i<=k; i++) {
        for (long long int j=1; j<=n; j++) {
            for (long long int l=1; l<j; l++) {
                if (seq[l] < seq[j])
                    dp[i][j] += dp[i-1][l];
            }
        }
    }
    
    for (long long int i=1; i<=n; i++) {
        res += dp[k][i];
    }
    
    return res;
}



int main() {
    _;
    
    while (cin >> n >> k) {
        if (n==0 & k==0)
            return 0;

        memset(seq, 0, sizeof(seq));
        memset(dp, 0, sizeof(dp));

        for (int i=1; i<=n; i++) {
            cin >> seq[i];
            dp[1][i] = 1;
        }

        long long res = solve();
        cout << res << endl;
    }
    
    return 0;
}