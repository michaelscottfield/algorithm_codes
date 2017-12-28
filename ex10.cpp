#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

int ModularExponent(int a, int j, int p){//a^j mod p
    int s = 1;
    while(j > 0){
        if(j % 2 == 1){
            s = (s * a) % p;
        }
        a = (a * a) % p;
        j = j >> 1;
    }
    return s;
}

bool Btest(int a, int n){
    int s = 0, t = n - 1;
    int x;
    while(t % 2 == 0){
        s ++;
        t /= 2;
    }
    x = ModularExponent(a, t, n);
    if(x == 1 || x == (n - 1)) return true;
    for(int i = 1; i <= s - 1; i ++){
        x = (x * x) % n;
        if(x == (n - 1)) return true;
    }
    return false;
}

bool MillRab(int n){
    int a;
    srand(unsigned(time(NULL)));
    a = int(2 + (n - 4) * rand() / (double)RAND_MAX);
    return Btest(a, n);
}

bool RepeatMillRab(int n, int k){
    int i;
    for(i = 1; i <= k; i ++){
        if(MillRab(n) == false) return false;
    }
    return true;
}

void PrintPrimes(){
    int n = 101, k, i = 0;
    k = (int)(log(double(n)) / log(2.0));
    while(n < 10000){
        if(RepeatMillRab(n, k)){
            printf("%d\t", n);
            i ++;
        }
        n += 2;
    }
    printf("\n共有 %d 个素数! %.4lf\n", i, (i - 1204) / 1204.0);
}

int main(){
    PrintPrimes();
    system("pause");
    return 0;
}