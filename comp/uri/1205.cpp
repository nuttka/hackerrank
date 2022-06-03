#include <bits/stdc++.h>
#define _                        \
   ios_base::sync_with_stdio(0); \
   cin.tie(0);
#define endl '\n'
#define MAX 1234
#define INF 0x3f3f3f
using namespace std;




int main() {
    _;
    int n;
    
    while (cin >> n) {
        int m, k, na;
        double prob;
        
        cin >> m >> k >> prob;

        vector<int> p[n+1];
        vector<int> at(n+1, 0);
        vector<int> val(n+1, INF);
        vector<int> visited(n+1, 0);

        for (int i=0; i<m; i++) {
            int aaa, bbb;
            cin >> aaa >> bbb;
            p[aaa].push_back(bbb);
            p[bbb].push_back(aaa);
        }
        cin >> na;

        for (int i=0; i<na; i++) {
            int aaa;
            cin >> aaa;
            at[aaa]++;
        }

        int start, end;
        cin >> start >> end;

        val[start] = at[start];

        for (int i=0; i<n; i++){
            int next = -1;
            for (int j=1; j<=n; j++) {
                if (visited[j] == 0 && (next == -1 || val[j] < val[next])) 
                    next = j;
            }

            visited[next] = 1;

            for (int u : p[next]) {
                if (val[u] > val[next] + at[u]) 
                    val[u] = val[next] + at[u];
            }
        }

        int minn = val[end];

        double pf;

        if (k<minn) pf = 0.0;
        else pf = pow(prob, minn);

        cout << fixed << setprecision(3) << pf << endl;

    }

    return 0;
}