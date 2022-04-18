#include <bits/stdc++.h>
#define _                        \
   ios_base::sync_with_stdio(0); \
   cin.tie(0);
#define endl '\n'
#define MAX 123456
#define INF 0x3f3f3f
using namespace std;



int nn;
string prefix, infix;

void printPos(string pre, string in) {
    char root = pre[0];
    pre.erase(0, 1;

    string e = in.find(root) == 0 ? "" : in.substr(0, in.find(root));
    string d = (in.find(root) == in.length() - 1) ? "" : in.substr(in.find(root) + 1);


    if (e != "") {
        string ppre = pre.substr(0, e.length());
        printPos(ppre, e);
    }

    if (d != "") {
        string ppre = pre.substr(e.length());
        printPos(ppre, d);
    }
    
    cout << root;
}

int main() {
    _;
    int t = 0;
    cin >> t;

    for (int i=0; i<t; i++){
        cin >> nn;
        cin >> prefix;
        cin >> infix;

        printPos(prefix, infix);
        
        cout << endl;
    }



    return 0;
}