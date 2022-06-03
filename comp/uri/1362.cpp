#include <bits/stdc++.h>
#define _                        \
   ios_base::sync_with_stdio(0); \
   cin.tie(0);
#define endl '\n'
#define MAX 99
#define INF 0x3f3f3f

using namespace std;


// XXL, XL, L, M, S ou XS
// 1, 2, 3, 4, 5 ou 6

int t, n, m;
int cam1[MAX];
int cam2[MAX];
int cc[MAX];
int possible;

int verify(string x) {
    if (x == "XXL")
        return 1;
    else if(x == "XL")
        return 2;
    else if(x == "L")
        return 3;
    else if(x == "M")
        return 4;
    else if(x == "S")
        return 5;
    return 6;
}


void solve(int p) {
    if (p == m || possible){
        possible = true;
        return;
    }

    if (cc[cam1[p]] > 0) {
        cc[cam1[p]]--;
        solve(p+1);
        cc[cam1[p]]++;
    }
    if (cc[cam2[p]] > 0) {
        cc[cam2[p]]--;
        solve(p+1);
        cc[cam2[p]]++;
    }

    
}



int main() {
    _;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        possible = false;
        memset(cam1, 0, sizeof(cam1));
        memset(cam2, 0, sizeof(cam2));
        for (int i=1; i<7; i++)
            cc[i] = n/6;

        for (int i=0; i<m; i++) {
            string a, b;
            cin >> a >> b;

            cam1[i] = verify(a);
            cam2[i] = verify(b);
        }


        solve(0);

        if (possible)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    
    
    return 0;
}

