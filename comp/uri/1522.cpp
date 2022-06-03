#include <bits/stdc++.h>
#define _                        \
   ios_base::sync_with_stdio(0); \
   cin.tie(0);
#define endl '\n'
#define MAX 999
#define INF 0x3f3f3f

using namespace std;


int n;
int p1[MAX], p2[MAX], p3[MAX];
int possible;

map<string, bool> verified;


void solve(int c1, int c2, int c3) {
    if (c1 == n && c2 == n && c3 == n || possible == 1) {
        possible = 1;
        return;
    }

    string tri = to_string(c1) + to_string(c2) + to_string(c3);
    if (verified[tri] == true) 
        return;
        
    verified[tri] = true;
    
    
    if (c1 != n && c2 != n && c3 != n && (p1[c1]+p2[c2]+p3[c3])%3 == 0) {
        solve(c1+1, c2+1, c3+1);
    }
    if (c1 != n && c2 != n && (p1[c1]+p2[c2])%3 == 0) {
        solve(c1+1, c2+1, c3);
    }
    if (c1 != n && c3 != n && (p1[c1]+p3[c3])%3 == 0) {
        solve(c1+1, c2, c3+1);
    }
    if (c2 != n && c3 != n && (p2[c2]+p3[c3])%3 == 0) {
        solve(c1, c2+1, c3+1);
    }
    if (c1 != n && p1[c1]%3 == 0) {
        solve(c1+1, c2, c3);
    }
    if (c2 != n && p2[c2]%3 == 0) {
        solve(c1, c2+1, c3);
    }
    if (c3 != n && p3[c3]%3 == 0) {
        solve(c1, c2, c3+1);
    }
    
}



int main() {
    _;

    while (cin >> n) {
        if (n == 0) return 0;
        verified.clear();
        possible = 0;
        memset(p1, 0, sizeof(p1));
        memset(p2, 0, sizeof(p2));
        memset(p3, 0, sizeof(p3));

        for (int i=0; i<n; i++) {
            cin >> p1[i] >> p2[i] >> p3[i];
        }

        solve(0, 0, 0);

        cout << possible << endl;
    }
    
    

    return 0;
} 