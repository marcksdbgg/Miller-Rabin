#include <iostream>

using namespace std;

long int module(long int a, long int n) {
    long int r = a - n * (a / n);
    r = r + (r < 0) * n;
    return r;
}

long int exp_mod_Binary(long int b, long int e, long int m)
{
    long int result = (e & 1)==1 ? b : 1;
    while (e != 0) {
        e >>= 1;
        b = module((b * b), m);
        if ((e & 1)==1)
            result = module((result * b), m);
    }
    return result;
}

int main() {
    int p;
    cout<<"Ingresa el numero:";
    cin >> p;
    int x, g;
    for (g = 2; g < p; ++g) {
        for (x = 1; x < p-1; ++x) {
            if (exp_mod_Binary(g, x, p) == 1){
                break;
            }
        }
        if (x == p-1){
            break;
        }
    }
    long int gmin = g;
    cout<<"Minima raiz primitiva: "<<gmin<<endl;
    for (x = 1; x < p; ++x) {
        if (exp_mod_Binary(g, x, p) == 2021){
            cout<<"("<<g<<"^"<<x<<")mod "<<p<<" = "<<exp_mod_Binary(g, x, p)<<endl;
            break;
        }
    }
}