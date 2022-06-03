#include <bits/stdc++.h>
#define _                        \
   ios_base::sync_with_stdio(0); \
   cin.tie(0);
#define endl '\n'
#define MAX 1234

using namespace std;



int p[MAX], qtd[MAX];
int n;
vector<vector<int>> uvw;

int find(int i) {
    if (p[i] == -1)
        return i;
    p[i] = find(p[i]);
    return p[i];
}

void uni(int a, int b) {
    if (a == b) return;

    int fa = find(a);
    int fb = find(b);

    if (qtd[fa] > qtd[fb]) {
        qtd[fa] += qtd[fb];
        p[fb] = fa;
    } else {
        qtd[fb] += qtd[fa];
        p[fa] = fb;
    }
}

void krskl_min() {
    sort(uvw.begin(), uvw.end());
    int vsize = uvw.size();
    int cc = 0;

    for (int i=0; i<vsize; i++) {
        if (find(uvw[i][1]) != find(uvw[i][2])) {
            uni(uvw[i][1], uvw[i][2]);
            cc += uvw[i][0];
        }
    }

    cout << cc << endl;
}

void krskl_max() {
    sort(uvw.begin(), uvw.end(), greater <>());
    int vsize = uvw.size();
    int cc = 0;

    for (int i=0; i<vsize; i++) {
        if (find(uvw[i][1]) != find(uvw[i][2])) {
            uni(uvw[i][1], uvw[i][2]);
            cc += uvw[i][0];
        }
    }

    cout << cc << endl;
}



int main() {
    _;
    cin >> n;
    for (int i=0; i<n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        uvw.push_back({w, u, v});
    }
    
    memset(p, -1, sizeof(p));
    memset(qtd, 1, sizeof(qtd));
    krskl_max();
    
    memset(p, -1, sizeof(p));
    memset(qtd, 1, sizeof(qtd));
    krskl_min();

    return 0;
}