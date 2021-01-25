
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
using namespace std;

int FindMin(vector<int> Input, int start, int end,int &comp){
    // The minimum element will be smaller than its previous element
    while(start<=end){
         
        if (start == end){                          // If only one element 
            comp++;
            return Input[start]; 
        }
        int mid = (start+end)/2;
        if (mid < end && Input[mid+1] < Input[mid]){       
            comp++;
            return Input[mid+1]; 
        }
        else if (mid > start && Input[mid] < Input[mid - 1]) {
            comp++;
            return Input[mid]; 
        }
        else if (Input[end] > Input[mid]){          // Normal increasing order, min will be in the opposite region
            comp++;
            end= mid-1;
        }
        else{
            comp++;
            start = mid+1;
        }
    }
    return Input[0];       // In case of no rotation 
} 

int main(){
    int N,temp;
    cin >> N;
    vector<int> List;
    for(int i=0;i<N;i++){
        cin>>temp;
        List.push_back(temp);
    }
    int num,comp=0;
    num = FindMin(List,0,List.size()-1,comp);
    cout<<"The Minimum element is:"<<num<<endl;
    //cout<<"Number of comparisons:"<<comp;
    
}