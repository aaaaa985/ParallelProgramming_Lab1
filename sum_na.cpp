#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>
using namespace std;
int main(int argc,char* argv[]){
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <matrix_dimension_n>" << endl;
        return 1;
    }
    int n=atoi(argv[1]);
    int sum;
    vector<int> a(n);
    
    // 添加重复循环以获取更有效的时间
    const int NUM=100;
    auto start=chrono::high_resolution_clock::now();
    for(int r=0;r<NUM;r++){
        // 初始化
        sum=0;
        for(int i=0;i<n;i++){
            a[i]=2;
        }
        // 平凡算法
        for(int i=0;i<n;i++){
            sum+=a[i];
        }
    }
    auto end=chrono::high_resolution_clock::now();
    chrono::duration<double,milli> elapsed=end-start;
    cout<<"Sum = "<<sum<<endl;
    cout<<"Time elapsed = "<<elapsed.count()/NUM<<"ms"<<endl;
    return 0;
}