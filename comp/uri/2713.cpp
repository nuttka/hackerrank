#include <bits/stdc++.h>
#define _                        \
   ios_base::sync_with_stdio(0); \
   cin.tie(0);
#define endl '\n'
#define MAX 1234

using namespace std;


int n, k, v;
int life[MAX], damage[MAX];
double dp[MAX][MAX];
int aux[MAX][MAX];

int val = 1;


double solve(int stage, int mana) {
    if (stage == n) return 0;

    if (aux[stage][mana] == val)
        return dp[stage][mana];

    aux[stage][mana] = val;

    double s1 = solve(stage+1, mana) + double(life[stage])/v;
    if (mana>0) {
        double s2 = solve(stage+1, mana-1) + double(life[stage])/(damage[stage]+v);
        dp[stage][mana] = min(s1, s2);
    } else {
        dp[stage][mana] = s1;
    }

    return dp[stage][mana];
}


int main() {
    _;

    while (cin >> n) {
        val++;
        cin >> k >> v;

        memset(life, 0, sizeof(life));
        memset(damage, 0, sizeof(damage));
        memset(aux, -1, sizeof(aux));

        for (int i=0; i<n; i++) {
            cin >> life[i] >> damage[i];
        }

        double d = solve(0, k);
        
        cout << fixed;
        cout << setprecision(4);
        cout << d << endl;

    }

    

    return 0;
}