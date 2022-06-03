#include <bits/stdc++.h>
#define _                        \
   ios_base::sync_with_stdio(0); \
   cin.tie(0);
#define endl '\n'
#define MAX 1234567


using namespace std;


string s;
int n, arcc[1234];




void solve() {
    int start = 0, end = 0;
    set<char> w;
    int size = s.length();

    for (int en=0, st=0; en<size; en++) {
        w.insert(s[en]);
        arcc[s[en]]++;

        // cout << s.substr(st, en - st + 1) << endl;
        while(w.size() > n) {
            arcc[s[st]]--;
            if (arcc[s[st]] == 0) {
                w.erase(s[st]);
            }
            st++;
        }

        if (end-start < en-st) {
            end = en;
            start = st;
        }
    }
    // cout << s.substr(start, end - start + 1) << endl;
    cout << end-start+1 << endl;

}


int main() {
    _;
    
    while (true) {
        cin >> n;
        if (n==0) break;
        cin.ignore();
        getline(cin, s);

        // cout << s << endl;

        memset(arcc, 0, sizeof(arcc));

        solve();
    }
    
    return 0;
}