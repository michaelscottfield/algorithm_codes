#include <stdio.h>
#include <iostream>
#include <time.h>
#include <math.h> 
using namespace std;
int bigRand(int min, int max)  
{    
    if (min > max)  
    {  
        min = max;  
    }  
  
    int rand1 = rand() % 10000;  
    int rand2 = rand() % 10000;  
    int randV = (rand1 * 10000 + rand2) % (max - min + 1);//改成这样  
  
    int randResult = min + randV;   
    return randResult;  
}  

double HitorMiss(int n){
    int k = 0;
    for (int i = 0; i < n; i ++){
        double x = bigRand(0 , 5000) / 5000.0;
        double y = bigRand(0 , 5000) / 5000.0;
        if(y <= sqrt(1.0 - x * x)){
            k ++;
        }
    }
    return 4.0 * double(k) / double(n);
}

int main(){
    srand(time(0));
    for(int n = 10; n <= 100000000; n = n * 10){
        cout << "n is " << n << ", pai is " << HitorMiss(n) << endl;
    }
    return 0;
}
