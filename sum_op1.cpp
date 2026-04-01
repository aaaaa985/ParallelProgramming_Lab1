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
    int sum1,sum2;
    vector<int> a(n);
    // 添加重复循环以获取更有效的时间
    const int NUM=100;
    auto start=chrono::high_resolution_clock::now();
    for(int r=0;r<NUM;r++){
        // 初始化
        sum1=0;
        sum2=0;
        for(int i=0;i<n;i++){
            a[i]=2;
        }
        // 优化算法-多链路式
        for(int i=0;i<n;i+=2){
            sum1+=a[i];
            sum2+=a[i+1];
        }
    }
    auto end=chrono::high_resolution_clock::now();
    chrono::duration<double,milli> elapsed=end-start;
    cout<<"Sum = "<<sum1+sum2<<endl;
    cout<<"Time elapsed = "<<elapsed.count()/NUM<<"ms"<<endl;
    return 0;
}