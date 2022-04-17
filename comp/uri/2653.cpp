#include <bits/stdc++.h>
#define _                        \
   ios_base::sync_with_stdio(0); \
   cin.tie(0);
#define endl '\n'
#define MAX 10000

using namespace std;

string current;
set<string> jj;

int main() {
    _;

    while (cin >> current) {
        jj.insert(current);
    }

    cout << jj.size() << endl;
    return 0;
}