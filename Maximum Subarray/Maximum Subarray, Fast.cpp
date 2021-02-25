#include<iostream>
#include <limits.h>
#include<vector>
using namespace std;

int maxSum(vector<int> List){
    int Sum=0,Max=0;
    for(int i=0;i<List.size();i++){
        Sum+=List[i];
        if (Sum<0)
            Sum=0;
        if (Max<Sum)
            Max=Sum;
    }
    return Max;
}

int max(vector<int> List){
    int Max=List[0];
    for(int i=1;i<List.size();i++){
        if (Max<List[i])
            Max=List[i];
    }
    return Max;
}

int main(){
    size_t N;
    cin>>N;
    vector<int> List;
    for(size_t i=0;i<N;i++){
        int num;cin>>num;
        List.push_back(num);
    }
    int Max= maxSum(List);
    if (Max==0)
        cout<< max(List);
    else
        cout<<Max;
}