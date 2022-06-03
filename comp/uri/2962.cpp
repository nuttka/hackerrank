#include <bits/stdc++.h>
#define _                        \
   ios_base::sync_with_stdio(0); \
   cin.tie(0);
#define endl '\n'
#define MAX 12345

using namespace std;


struct point {
    int x;
    int y;
    int range;
    point(int x, int y, int range) {
        this->x = x;
        this->y = y;
        this->range = range;
    }
};


int n, m, k, visited[MAX][MAX];
vector<point> points;

string possible = "N";


bool insideRange(int row, int col, int range, int x, int y) {
    float distance = sqrt(pow((row-x),2) + pow((col-y),2));

    if (distance>range) return false;

    // cout << "range: " << distance << endl;
    return true;
}


bool isPossible(int x, int y) {
    if (x>n || x<0 || y>m || y<0 || visited[x][y] == 1) {
        return false;
        // cout << "nao possivel a  " << x << ", " << y << endl;
    }

    for (int i=0; i<k; i++) {
        if (insideRange(points[i].x, points[i].y, points[i].range, x, y)) {
            // cout << "nao possivel b  " << x << ", " << y << endl;
            return false;
        }
    }
    
    // cout << "possivel " << x << ", " << y << endl;
    return true;
}




void ssea(int x, int y) {
    if (possible == "S" || visited[x][y] == 1) return;
    if (x == n && y == m) {
        possible = "S";
        return;
    }

    visited[x][y] = 1;

    // cout << "visitando " << x << ", " << y << endl;

    if (isPossible(x+1, y)) {
        ssea(x+1, y);
    }
    // if (isPossible(x+1, y+1)) {
    //     ssea(x+1, y+1);
    // }
    if (isPossible(x, y+1)) {
        ssea(x, y+1);
    }
    // if (isPossible(x-1, y+1)) {
    //     ssea(x-1, y+1);
    // }
    if (isPossible(x-1, y)) {
        ssea(x-1, y);
    }
    // if (isPossible(x-1, y-1)) {
    //     ssea(x-1, y-1);
    // }
    if (isPossible(x, y-1)) {
        ssea(x, y-1);
    }
    // if (isPossible(x+1, y-1)) {
    //     ssea(x+1, y-1);
    // }
}




int main() {
    _;

    memset(visited, 0, sizeof(visited));

    cin >> n >> m >> k;

    for (int i=0; i<k; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        points.push_back(point(a, b, c));
    }

    ssea(0, 0);


    cout << possible << endl;
    

    return 0;
}