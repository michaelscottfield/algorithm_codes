#include <stdio.h>
#include <time.h>
#include <iostream>
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

double Darts (int n) {
		
		int k = 0;
		for (int i = 0; i < n; i ++) {
			double x = bigRand(0 , 10000) / 10000.0;
			double y = x; // 随机产生点(x,y)
			if (x * x + y * y <= 1.0) k++; //圆内
		}
		return double(4.0)*double(k)/double(n);
    }
int main(){
	srand(time(0));
	for(int i = 10; i <= 1000000; i = i * 10){
		cout << "n is " << i << ", pai is " << Darts(i) << endl;
	}
	return 0;
}
