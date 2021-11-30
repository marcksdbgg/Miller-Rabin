#include <iostream>
#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;

ZZ modulo(ZZ a, ZZ n){
    ZZ r = a-n*(a/n);
    r = r+(r<0)*n;
    return r;
}

ZZ modPow(ZZ a ,ZZ n,ZZ m){

    ZZ exp (1);
    ZZ x = modulo(a,m);

    while(n>0){
        if(modulo(n, ZZ(2)) == 1)
            exp = modulo(exp*x,m);
        x = modulo(x*x,m);
        n>>=1;
    }
    return exp;
}

ZZ RandomNumber(ZZ a,ZZ b) {
    ZZ k = b - a + 1;
    ZZ num = RandomBnd(k)+a;
    return num;
}

bool millerRabinTest(ZZ number, ZZ iter)
{

    if(modulo(number,ZZ(2))== 0) return false;
    if (number <= 1 || number == 4)  return false;
    if (number <= 3) return true;


    ZZ d = number - 1;


    while (modulo(d,ZZ(2)) == 0)
        d >>= 1;



    for (ZZ i (0); i < iter; i++){


        ZZ a = RandomNumber(ZZ(2),number-2);


        ZZ x = modPow(a, d, number);

        if (x == 1  || x == number-1)
            return true;

        while (d != number-1)
        {
            x= modulo(x*x,number);

            d <<=1;

            if (x == 1)   return false;
            if (x == number-1)  return true;
        }
        return false;
    }

    return true;
}

int main() {

    cout<<"Primos de 10 BITS: "<<endl;
    for(ZZ num = ZZ(512); num < ZZ(1024); num += ZZ(1)){
        if (millerRabinTest(num,ZZ(571))){
            cout<<num<< " , "<<endl;
    }
}
