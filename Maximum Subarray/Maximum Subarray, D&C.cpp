#include<iostream>
#include <limits.h>
#include<vector>
#include<algorithm>
using namespace std;

int CrossSum(vector<int> List, int start, int mid , int end){
    int Sum=0;
    int LeftSum= INT_MIN;
    for(int i=mid;i>=start;i--){
        Sum+=List[i];
        if (Sum>LeftSum)
            LeftSum=Sum;
    }
    Sum=0;
    int RightSum= INT_MIN;
    for(int i=mid+1;i<=end;i++){
        Sum+=List[i];
        if (Sum>RightSum)
            RightSum=Sum;
    }
    return max(LeftSum,max(RightSum,LeftSum+RightSum));
}

int maxSum(vector<int> List, int start, int end){
    if (start>=end)
        return List[end];
    int mid= (start+end)/2;
    int LMax= maxSum(List,start,mid);
    int RMax= maxSum(List,mid+1,end);
    int Cross= CrossSum(List,start,mid,end);
    return max(max(LMax,RMax),Cross);
}

int main(){
    size_t N;
    cin>>N;
    vector<int> List;
    for(size_t i=0;i<N;i++){
        int num;cin>>num;
        List.push_back(num);
    }
    cout<<maxSum(List,0,N-1);
}