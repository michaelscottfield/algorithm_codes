#include <iostream>
#include <set>
#include <time.h>
#include <math.h>
#include <ctime>
#include <limits.h>
using namespace std;
#define pai 3.1415926
set<int> set1;

int Count(int n){
    int k = 0;
    int t = (rand() << 16) + (rand() << 1) + (rand() > RAND_MAX / 2);
    int a = int(((double)t / (INT_MAX)) * (n - 1)) + 1;
    while(set1.find(a) == set1.end()){
        k += 1;
        set1.insert(a);
        t = (rand() << 16) + (rand() << 1) + (rand() > RAND_MAX / 2);
        a = int(((double)t / (INT_MAX)) * (n - 1)) + 1;
        //cout << a << endl;
    }
    return k;
}

double SetCount(int m, int n){
    int i = 0;
    long long cnt = 0;
    while(i++ < m){
        set1.clear();
        cnt += Count(n);
    }
    double sum = cnt / double(m);
    return (sum * sum * 2.0 / pai);
}

int main(){
    srand(time(0));
    for(int i = 100; i <= 100000000; i *= 10){
        cout << "n is " << i << ", calc n is " << int(SetCount(1000, i)) << endl;
    }
    return 0;
}