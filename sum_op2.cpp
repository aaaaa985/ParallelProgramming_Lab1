#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>
using namespace std;
// 优化算法-递归函数
void recursion(int n,vector<int> a){
    if(n==1){
        return;
    }
    else{
        for(int i=0;i<n/2;i++){
            a[i]+=a[n-1-i];
        }
        recursion(n/2,a);
    }
}
int main(int argc,char* argv[]){
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <matrix_dimension_n>" << endl;
        return 1;
    }
    int n=atoi(argv[1]);
    vector<int> a(n);
    const int NUM=1000;
    auto start=chrono::high_resolution_clock::now();
    for(int r=0;r<NUM;r++){
        // 初始化
        for(int i=0;i<n;i++){
            a[i]=2;
        }
        recursion(n,a);
    }
    auto end=chrono::high_resolution_clock::now();
    chrono::duration<double,milli> elapsed=end-start;
    cout<<"Sum = "<<a[0]<<endl;
    cout<<"Time elapsed = "<<elapsed.count()/NUM<<"ms"<<endl;
    return 0;
}