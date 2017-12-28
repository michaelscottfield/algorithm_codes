#include <stdio.h>
#include <iostream>
#include <time.h>
#include <math.h>
#include <string.h> 
using namespace std;

char str1[] = "x^2";
char str2[] = "-sqrt(x)";
char str3[] = "sin(x)";

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

double MyCalc(char f[], double minx, double maxx, double miny, double maxy, int n){
    int k = 0;
    double fx;
    for(int i = 0; i < n; i ++){
        double x = bigRand(0 , 5000) / 5000.0 * (maxx - minx) + minx;
        double y = bigRand(0 , 5000) / 5000.0 * (maxy - miny) + miny;
        if(string(f) == string(str1)){
            fx = x * x;
        }
        else if(string(f) == string(str2)){
            fx = 0.0 - sqrt(x);
        }
        else if(string(f) == string(str3)){
            fx = sin(x);
        }
        if(fx >= 0){
            if(y <= fx && y >= 0){
                k++;
            }
        }
        else if(y >= fx && y <= 0){
            k--;
        }
    }
    if(miny > 0){
        return double(k) / double(n) * (maxx - minx) * (maxy - miny) + miny * (maxx - minx);
    }
    else if(maxy < 0){
        return double(k) / double(n) * (maxx - minx) * (maxy - miny) + maxy * (maxx - minx);
    }
    else{
        return double(k) / double(n) * (maxx - minx) * (maxy - miny);
    }
}

int main(){
    double pai = 3.1415926535898;
    char strr1[] = "x^2";
    char strr2[] = "-sqrt(x)";
    char strr3[] = "sinx";
    srand(time(0));
    cout << "n is 10000000" << endl;
    cout << "calc answer of x^2 from 2 to 3 is " << MyCalc(strr1, 2.0, 3.0, 4.0, 9.0, 10000000) << ", real: 6.333333333" << endl; 
    cout << "calc answer of -sqrt(x) from 4 to 9 is " << MyCalc(strr2, 4.0, 9.0, 0.0 - 3.0, 0.0 - 2.0, 10000000) << ", real: -12.666666667" << endl;
    cout << "calc answer of sinx from 0 to pai is " << MyCalc(str3, 0.0, pai, 0.0, 1.0, 10000000) << ", real: 2.000000000" << endl;
    cout << "calc answer of sinx from -pai to pai is " << MyCalc(str3, 0.0 - pai, pai, 0.0 - 1.0, 1.0, 10000000) << ", real: 0.000000000" << endl;

    return  0;
}