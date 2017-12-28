#include <iostream>
#include <set>
#include <ctime>
using namespace std;

void backtrace(int k, int *tryy, set<int> col, set<int> diag45, set<int> diag135, int &success, int QueenNum, int &NodesSearched){
    int base = k;
    int i = k;
    int j = 0;
    int index = 0;
    while(i < QueenNum){
        for(j = index; j < QueenNum; j ++){
            if((col.find(j) == col.end()) &&(diag45.find(j - i) == diag45.end()) &&(diag135.find(j + i) == diag135.end())){
                tryy[i] = j;
                col.insert(j);
                diag45.insert(j - i);
                diag135.insert(j + i);
                i ++;
                index = 0;
                j = 0;
                NodesSearched ++;//place a queen
                break;
            }
        }
        if(j == QueenNum){
            i --;
            if(i < base){
                success = 0;
            }
            index = tryy[i] + 1;
            col.erase(tryy[i]);
            diag45.erase(tryy[i] - i);
            diag135.erase(tryy[i] + i);
        }
    }
    success = 1;
}

void Queenslv(int &success, int *tryy, int QueenNum, int StepVegas, int &NodesSearched){
    set<int> col, diag45, diag135;
    tryy = new int[QueenNum];
    int k = 0;
    int nb = 1, j;
    while(nb != 0 &&  k != StepVegas){
        nb = 0;
        for(int i = 0; i < QueenNum; i ++){
            if((col.find(i) == col.end()) &&(diag45.find(i - k) == diag45.end()) &&(diag135.find(i + k) == diag135.end())){
                nb = nb + 1;
                if(rand() % nb + 1 == 1){
                    j = i;
                }
            }
        }
        if(nb > 0){
            k = k + 1;
            tryy[k - 1] = j;
            col.insert(j);
            diag45.insert(j - k + 1);
            diag135.insert(j + k - 1);
            NodesSearched ++;
        }
    }
    if(nb > 0){
        backtrace(k, tryy, col, diag45, diag135, success, QueenNum, NodesSearched);
    }
    else{
        success = 0;
    }
}

double StaticNodesSearched(int QueenNum, int StepVegas){
    int *tryy;
    tryy = new int[QueenNum];
    int success = 0;
    int NumberOfNodes = 0;
    int sumSuccess = 0;
    int sumFailed = 0;
    int NumberOfSuccess = 0;
    int NumberOfFailed = 0;
    int i;
    for(i = 0; i < 100; i ++){
        NumberOfNodes = 0;
        //tryy = new int[QueenNum];
        Queenslv(success, tryy, QueenNum, StepVegas, NumberOfNodes);
        if(success == 1){
            NumberOfSuccess ++;
            sumSuccess += NumberOfNodes;
        }
        else{
            NumberOfFailed ++;
            sumFailed += NumberOfNodes;
        }
    }
    //if(i == 100) cout << "dog" << endl;
    double successRate = double(NumberOfSuccess) / 100.0;
    double answer;
    if(successRate == 0.0){
        answer = sumFailed / NumberOfFailed;
    }
    else if(successRate == 1.0){
        answer = sumSuccess / NumberOfSuccess;
    }
    else{
        answer = double(sumSuccess) / double(NumberOfSuccess) + (1.0 - successRate) * (double(sumFailed) / double(NumberOfFailed)) / successRate;
    }
    return answer;
}

void SearchMin(double *answer, int i, int &key, double &ANSWER){
    ANSWER = answer[0];
    for(int j = 1; j <= i; j ++){
        if(answer[j] < ANSWER){
            key = j;
            ANSWER = answer[j];
        }
    }
}

void StepVegasCalculate(int key, double ANSWER){
    double *answer;
    answer = new double[21];
    answer[0] = 1000000;
    for(int i = 12; i<= 20; i ++){
        for(int j = 1; j <= i; j ++){
            answer[j] = StaticNodesSearched(i, j);
        }
        key = 0;
        ANSWER = 0;
        SearchMin(answer, i, key, ANSWER);
        cout << i <<"Queens, Best StepVegas = " << key << ", Average Nodes Searched: " << ANSWER << endl;
    }
}

int main(){
    time_t t;
    srand((unsigned)time(&t));
    int key;
    double ANSWER;
    StepVegasCalculate(key, ANSWER);
    return 0;
}