#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

int Search(int x, int i, int *var, int *ptr, int n){
    int count = 0;
    while(ptr[i] !=  -1 && x > var[i]){
        count ++;
        i = ptr[i];
    }
    return count;
}

int A(int x, int *var, int *ptr, int n, int head){
    return Search(x, head, var, ptr, n);
}

int D(int x, int *var, int *ptr, int n, int head){
    int i = rand() % n;
    if(x < var[i])
        return (1 + Search(x, head, var, ptr, n));
    else if(x > var[i])
        return (1 + Search(x, ptr[i], var, ptr, n));
    else return 1;
}

int B(int x, int *var, int *ptr, int n, int head){
    int i = head;
    int len = int(sqrt(double(n)));
    int max = var[i];
    for(int j = 0; j < len; j ++){
        if(max < var[j] && var[j] <= x){
            i = j;
            max = var[j];
        }
    }
    return (len + Search(x, i , var, ptr, n));
}

int C(int x, int *var, int *ptr, int n, int head){
    int i = head;
    int max = var[i];
    int len = int(sqrt(double(n)));
    int s = rand() % (n - len) + 1;
    for(int k = s; k < len + s; k ++){
        if(max < var[k] && var[k] <= x){
            i = k;
            max = var[k];
        }
    }
    return (len + Search(x, i, var, ptr, n));
}

void Shuffle(int n, int *var, int *ptr, int &head){
    int i = 1, pre, next;
    head = rand() % n;
    var[head] = i;
    pre = head;
    while(++i <= n){
        next = rand() % n;
        if(var[next] != -1){
            int temp = next;
            while(var[next] != -1 && next < n) next ++;
            if(next == n){
                next = --temp;
                while(var[next] != -1 && next > -1) next--;
            }
        }
        ptr[pre] = next;
        var[next] = i;
        pre = next;
    }
}

void Init(int *var, int m, int n){//为动态数组赋值
    for(int i = 0; i < n; i ++){
        var[i] = m;
    }
}

int main(){
    int head, n, *var, *ptr;
    time_t t;

    for(int i = 0; i < 3; i ++){
        cout << "输入待处理数据集合的大小: ";
        cin >> n;
        srand((unsigned)time(&t));
        int x = rand() % n;
        var = new int[n];
        ptr = new int[n];
        cout << "执行A、B、C、D算法时的查找次数: \n";
        for(int j = 0; j < 3; j ++){
            Init(var, -1, n);
            Init(ptr, -1, n);
            Shuffle(n, var, ptr, head);
            cout << "A: " << A(x, var, ptr, n, head) << "   "
                 << "B: " << B(x, var, ptr, n, head) << "   "
                 << "C: " << C(x, var, ptr, n, head) << "   "
                 << "D: " << D(x, var, ptr, n, head) << endl;
        }
        delete []var;
        delete []ptr;
    }
    system("pause");
    return 0;
}