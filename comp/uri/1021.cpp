#include <bits/stdc++.h>
#define _                        \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define endl '\n'

// #define MAX 10000

using namespace std;



long double NOTAS[] = {100.00, 50.00, 20.00, 10.00, 5.00, 2.00};
long double MOEDAS[] = {1.00, 0.50, 0.25, 0.10, 0.05, 0.01};



int main() {
    _;

    double v;
    cin >> v;
    double aux = v;
    int f;

    cout << "NOTAS:" << endl;

    f = floor(aux/100);
    aux -= f*100;
    cout << f << " nota(s) de R$ 100.00" << endl;
    f = floor(aux/50);
    aux -= f*50;
    cout << f << " nota(s) de R$ 50.00" << endl;
    f = floor(aux/20);
    aux -= f*20;
    cout << f << " nota(s) de R$ 20.00" << endl;
    f = floor(aux/10);
    aux -= f*10;
    cout << f << " nota(s) de R$ 10.00" << endl;
    f = floor(aux/5);
    aux -= f*5;
    cout << f << " nota(s) de R$ 5.00" << endl;
    f = floor(aux/2);
    aux -= f*2;
    cout << f << " nota(s) de R$ 2.00" << endl;




    cout << "MOEDAS:" << endl;

    f = floor(aux/1);
    aux -= f*1;
    cout << f << " moeda(s) de R$ 1.00" << endl;
    
    aux *= 100;
    f = floor(aux/50);
    aux -= f*50;
    cout << f << " moeda(s) de R$ 0.50" << endl;
    f = floor(aux/25);
    aux -= f*25;
    cout << f << " moeda(s) de R$ 0.25" << endl;
    f = floor(aux/10);
    aux -= f*10;
    cout << f << " moeda(s) de R$ 0.10" << endl;
    f = floor(aux/5);
    aux -= f*5;
    cout << f << " moeda(s) de R$ 0.05" << endl;
    f = floor(aux/1);
    aux -= f*1;
    cout << f << " moeda(s) de R$ 0.01" << endl;


    // for (int i=0; i<6; i++) {
    //     f = floor(aux/NOTAS[i]);
    //     aux -= f*NOTAS[i];
    //     cout << f << " nota(s) de R$ " << NOTAS[i] << ".00" << endl;
    // }



    // cout << "MOEDAS:" << endl;

    // for (int i=0; i<6; i++) {
    //     f = floor(aux/MOEDAS[i]);
    //     aux -= f*MOEDAS[i];

    //     if (i==0){
    //         cout << f << " moeda(s) de R$ " << MOEDAS[i] << ".00" << endl;
    //     }else if (i==1 || i==3){
    //         cout << f << " moeda(s) de R$ " << MOEDAS[i] << "0" << endl;
    //     }else {
    //         cout << f << " moeda(s) de R$ " << MOEDAS[i] << endl;
    //     }

    // }
    
   
    return 0;
}