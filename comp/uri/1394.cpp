#include <bits/stdc++.h>
#define _                        \
   ios_base::sync_with_stdio(0); \
   cin.tie(0);
#define endl '\n'
#define MAX 123

using namespace std;


int n, m, g;
int points[MAX];

int graph[MAX][MAX];



void ourTeam() {
    for(int i=1; i<n; i++) {
        int nm = m - graph[0][i];
        points[0] += 2*nm;
        graph[0][i] += nm;
        graph[i][0] += nm;
        // cout << "Jogo contra " << i << ": " << 2*nm << " / " << points[0] << endl;
    }
}

char verifyPoints() {
    int t0 = points[0];

    // cout << 0 << ": " << t0 << endl;

    for (int i=1; i<n; i++) {
        // cout << i << ": " << points[i] << endl;
        if (points[i]>=t0)
            return 'N';
    }
    return 'Y';
}

char solve () {
    ourTeam();
    for (int i=1; i<n; i++) {
        for (int j=1; j<n; j++) {
            if (i==j)
                continue;

            int nm = m - graph[j][i];
            graph[j][i] += nm;
            graph[i][j] += nm;

            for (int k=0; k<nm; k++) {
                if (points[i]>points[j]) {
                    points[j] += 2;
                } else if (points[i]<points[j]) {
                    points[i] += 2;
                } else {
                    points[i] += 1;
                    points[j] += 1;
                }
            }
        }
    }

    return verifyPoints();
}



int main() {
    _;
    
    while (cin >> n) {
        cin >> m >> g;
        if (n == 0 && m == 0 && g == 0) 
            return 0;

        memset(points, 0, sizeof(points));
        // memset(matches, 0, sizeof(matches));
        memset(graph, 0, sizeof(graph));

        for (int i=0; i<g; i++) {
            int a, b;
            char c;
            cin >> a >> c >> b;
            graph[a][b] += 1;
            graph[b][a] += 1;
            
            if (c == '<')
                points[b] += 2;
            else {
                points[b] += 1;
                points[a] += 1;
            }
        }

        char res = solve();

        cout << res << endl;

    }


    return 0;
}