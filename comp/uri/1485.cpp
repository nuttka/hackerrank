#include <bits/stdc++.h>
#define _                        \
   ios_base::sync_with_stdio(0); \
   cin.tie(0);
#define endl '\n'
#define MAX 545
#define INF 0x3f3f3f

using namespace std;


int s, b;
int rol[MAX], balls[MAX];
int dp[MAX][MAX];



int solve() {
    int val = -INF;

    for (int i=0; i<s; i++) {
        dp[0][i] = balls[0]*(rol[i] + rol[(i+1)%s]);
        for (int j=1; j<s; j++) {
            dp[0][((i+j)%s)] = max(balls[0]*(rol[((i+j)%s)] + rol[(((i+j)%s)+1)%s]), dp[0][(((i+j)%s)+s-1)%s]);
        }

        for (int j=1; j<b; j++) {
            for (int k=0; k<s; k++)
                dp[j][k] = -INF;

            for (int k=2*j; k<s-1; k++) {
                dp[j][((i+k)%s)] = max(balls[j]*(rol[((i+k)%s)] + rol[(((i+k)%s)+1)%s]) + dp[j-1][(((i+k)%s)+s-2)%s], dp[j][(((i+k)%s)+s-1)%s]);
            }
        }

        val = max(val, dp[b-1][(i+s-2)%s]);
    }

    return val;

}




int main() {
    _;

    while (cin >> s) {
        cin >> b;

        if (s==0 && b==0) return 0;

        memset(dp, -1, sizeof(dp));
        memset(rol, 0, sizeof(rol));
        memset(balls, -1, sizeof(balls));

        for (int i=0; i<s; i++) {
            cin >> rol[i];
        }

        for (int i=0; i<b; i++) {
            int a;
            cin >> a;
            balls[i] *= a;
        }

        int val = solve();

        cout << val << endl;
    }
    

    return 0;
} 