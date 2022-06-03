#include <bits/stdc++.h>
#define _                        \
   ios_base::sync_with_stdio(0); \
   cin.tie(0);
#define endl '\n'
#define MAX 1234

using namespace std;


int n, m, lamp[MAX], inte[MAX][MAX], initial[MAX][MAX];


bool verify() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (inte[i][j] != initial[i][j]) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    _;
    int l;
    cin >> n >> m;
    memset(lamp, -1, sizeof(lamp));
    memset(inte, 0, sizeof(inte));
    memset(initial, 0, sizeof(initial));
    cin >> l;
    for (int i=0; i<l; i++) {
        int a;
        cin >> a;
        lamp[a] = 1;
    }

    for (int i=1; i<=n; i++) {
        int k;
        cin >> k;

        for (int j=0; j<k; j++) {
            int y;
            cin >> y;
            inte[i][y] = 1;
            initial[i][y] = 1;
        }
    }

    // a

    // for (int i=0; i<n; i++) {
    //     for (int j=0; j<m; j++) {
    //         cout << inte[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // for (int i=0; i<n; i++) {
    //     for (int j=0; j<m; j++) {
    //         cout << initial[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // a

    int qtd = 0;
    
    do {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                if (inte[i][j] != 0) {
                    inte[i][j] *= -1;
                    lamp[j] *= -1;
                }
            }
            qtd++;
            
            bool all = true;
            for (int j=1; j<=m; j++) {
                if (lamp[j] == 1) {
                    all = false;
                }
            }

            if (all) {
                cout << qtd << endl;
                return 0;
            }
        }

    } while (verify());
    
    cout << "-1" << endl;

    return 0;
}