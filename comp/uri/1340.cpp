#include <bits/stdc++.h>
#define _                        \
   ios_base::sync_with_stdio(0); \
   cin.tie(0);
#define endl '\n'
#define MAX 1234

using namespace std;



int n;

int main() {
    _;

    while (cin >> n) {
        stack<int> s;
        queue<int> q;
        priority_queue<int> pq;
        bool isS=true, isQ=true, isPQ=true;
        for (int i=0; i<n; i++) {
            int com, val;
            cin >> com;
            cin >> val;
            if (com == 1) {
                s.push(val);
                q.push(val);
                pq.push(val);
            } else {
                if (s.top() == val) {
                    s.pop();
                } else {
                    isS = false;
                }

                if (q.front() == val) {
                    q.pop();
                } else {
                    isQ = false;
                }

                if (pq.top() == val) {
                    pq.pop();
                } else {
                    isPQ = false;
                }
            }
        }

        if (isS && !isQ && !isPQ) cout << "stack" << endl;
        else if (!isS && isQ && !isPQ) cout << "queue" << endl;
        else if (!isS && !isQ && isPQ) cout << "priority queue" << endl;
		else if (isS || isQ || isPQ) cout << "not sure" << endl;
		else if (!isS && !isQ && !isPQ) cout << "impossible" << endl;
    }



    return 0;
}