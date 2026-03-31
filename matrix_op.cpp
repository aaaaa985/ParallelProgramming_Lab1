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
    vector<float> a(n);
    vector<float> b(n * n);// 使用一维数组表示矩阵确保数据存在一起
    vector<float> sum(n);
    for(int i=0;i<n;i++){
        a[i]=2.0f;
        for(int j=0;j<n;j++){
            b[i*n+j]=static_cast<float>(i+j);
        }
    }
    // 添加重复循环以获取更有效的时间
    const int NUM=100;
    auto start=chrono::high_resolution_clock::now();
    for(int r=0;r<NUM;r++){
        // 初始化sum
        for(int i=0;i<n;i++){
            sum[i]=0.0f;
        }
        // 优化算法
        for(int j=0;j<n;j++){
            for(int i=0;i<n;i++){
                sum[i]+=b[j*n+i]*a[j];
            }
        }
    }
    auto end=chrono::high_resolution_clock::now();
    chrono::duration<double,milli> elapsed=end-start;
    cout<<"Result(first few elements):";
    for(int i=0;i<min(n,10);i++){// 若n>10则只打印前10个元素，避免输出过长
        cout<<sum[i]<<" ";
    }
    cout<<endl;
    cout<<"Time elapsed = "<<elapsed.count()/NUM<<"ms"<<endl;
    return 0;
}