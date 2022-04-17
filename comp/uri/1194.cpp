#include <bits/stdc++.h>
#define _                        \
   ios_base::sync_with_stdio(0); \
   cin.tie(0);
#define endl '\n'
#define MAX 123456
#define INF 0x3f3f3f
using namespace std;


typedef struct node {
    char value;
    struct node* l;
    struct node* r;
} node;




map <char, int> m;
int nn;
string prefix, infix;
node* nodeo;

void add(node* nodeo, char value) {
    if (!nodeo) {
        nodeo = new node();
        nodeo->l = NULL;
        nodeo->r = NULL;
        nodeo->value = value;
    } else {
        if (m[nodeo->value] < m[value]) {
            add(nodeo->r, value);
        } else {
            add(nodeo->l, value);
        }
    }
}

void printPos(node* nodeo) {
    if(!nodeo) return;

    printPos(nodeo->l);
    printPos(nodeo->r);
    cout << nodeo->value;
}

int main() {
    _;
    int t = 0;
    cin >> t;

    for (int i=0; i<t; i++){
        cin >> nn;
        cin >> prefix;
        cin >> infix;
        
        for (int i=0; i<nn; i++) {
            m[infix[i]] = i;
        }
        for (int i=0; i<nn; i++) {
            add(nodeo, prefix[i]);
        }

        printPos(nodeo);
    }


    return 0;
}