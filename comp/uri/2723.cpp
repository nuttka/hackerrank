#include <bits/stdc++.h>
#define _                        \
   ios_base::sync_with_stdio(0); \
   cin.tie(0);
#define endl '\n'
#define MAX 11111
#define INF 0x3f3f3f

using namespace std;


int t, n;
int prs[MAX];
int dp[MAX][99];



int solve(int p, int d) {
    if (p == n) {
        return 1;
    }

    if (dp[p][d] != -1) 
        return dp[p][d];

    int p1 = 0, p2 = 0;
    if (abs(d+prs[p]) <= 5) {
        p1 = solve(p+1, d+prs[p]);
    }
    if (abs(d-prs[p]) <= 5) {
        p2 = solve(p+1, d-prs[p]);
    }

    dp[p][d] = max(p1, p2);

    return dp[p][d];
}



int main() {
    _;
    cin >> t;
    while (t--) {
        cin >> n;
        memset(prs, 0, sizeof(prs));
        memset(dp, -1, sizeof(dp));

        for (int i=0; i<n; i++) {
            cin >> prs[i];
        }

        int res = solve(0, 0);
        if (res == 1)
            cout << "Feliz Natal!" << endl;
        else 
            cout << "Ho Ho Ho!" << endl;
    }
    
    
    return 0;
}