
#include <iostream>
#include <string> 
#include <vector>
using namespace std;

int **Min(NULL),**Max(NULL);

int MaxValue(vector<int> numbers,vector<char> operations);

int main(){
    string Str;
    getline(cin,Str);
    vector<int> numbers;
    vector<char> operations;
    for(int i=0;i<Str.size();i++){
        if(i%2==0)
           numbers.push_back((Str[i]-'0'));
        else
           operations.push_back(Str[i]);   
    }
    int n=numbers.size();
    Min=new int*[n];
    Max=new int*[n];
    for(int i=0;i<Str.size();i++){
        Min[i]=new int[n];   
        Max[i]=new int[n];
    } 
    cout<<MaxValue(numbers,operations); 
}

void Min_Max(int i,int j,vector<char> operations){

}

int MaxValue(vector<int> numbers,vector<char> operations){
    for(int i=0;i<numbers.size();i++){
        Min[i][i]=Max[i][i]=numbers[i];
    }
    int n=numbers.size(),j;
    for(int s=1;s<n;s++){
        for(int i=1;i<n-s;s++){
            j=i+s;
            Min_Max(i,j,operations);
        }
    }
}