#include <bits/stdc++.h>
#define _                        \
   ios_base::sync_with_stdio(0); \
   cin.tie(0);
#define endl '\n'
#define MAX 1234
#define INF 0x3f3f3f

using namespace std;




int n, m, serv, visited[MAX], vs[MAX][MAX], val[MAX];


void d() {

    for (int i=1; i<n; i++) {
        int next, minn = INF;
        for (int k=1; k<=n; k++) {
            if (visited[k] == 0 && val[k] <= minn) {
                next = k;
                minn = val[k];
            }
        }
        visited[next] = 1;

        for (int j=1; j<=n; j++) {
            if (visited[j] == 0 && vs[next][j] != 0 && val[next] != INF && (val[next] + vs[next][j] < val[j])) {
                val[j] = val[next] + vs[next][j];
            }
        }
    }

}



int main() {
    _;
    cin >> n >> m;
    memset(visited, 0, sizeof(visited));
    memset(vs, 0, sizeof(vs));
    memset(val, INF, sizeof(val));

    for (int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        vs[a][b] = c;
        vs[b][a] = c;
    }
    cin >> serv;

    val[serv] = 0;
    d();
    
    int bigg = 0, minn = INF;
    for (int i=1; i<=n; i++) {
        if (i != serv) {
            bigg = max(bigg, val[i]);
            minn = min(minn, val[i]);
        }
    }
    
    // for (int i=1; i<=n; i++) {
    //     for (int j=1; j<=n; j++) {
    //         cout << vs[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // for (int i=1; i<=n; i++) {
    //     cout << val[i] << endl;
    // }

    // for (int i=1; i<=n; i++) {
    //     cout << visited[i] << endl;
    // }

    cout << bigg-minn << endl;
    
    

    return 0;
}