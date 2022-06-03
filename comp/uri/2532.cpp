#include <bits/stdc++.h>
#define _                        \
   ios_base::sync_with_stdio(0); \
   cin.tie(0);
#define endl '\n'
#define MAX 2222
#define INF 0x3f3f3f

using namespace std;

int dp[MAX][MAX];
int damage[MAX];
int mana[MAX];

int solve(int mag, int dam, int n, int p) {
    if (mag == n) {
        if (dam >= p) return 0;
        else return INF;
    }

    if (dp[mag][dam] != -1) return dp[mag][dam];

    int pos1 = solve(mag+1, dam, n, p);
    int pos2 = solve(mag+1, dam + damage[mag], n, p) + mana[mag];

    int ans = min(pos1, pos2);
    dp[mag][dam] = ans;
    return dp[mag][dam];
}

int main() {
    int n;

    while(cin >> n) {
        int p;
        cin >> p;

        memset(dp, -1, sizeof(dp));
        memset(damage, 0, sizeof(damage));
        memset(mana, 0, sizeof(mana));

        for (int i=0; i<n; i++) {
            cin >> damage[i];
            cin >> mana[i];
        }

        int ans = solve(0, 0, n, p);
        
        if (ans != INF) cout << ans << endl;
        else cout << -1 << endl;
    }

    return 0;
}