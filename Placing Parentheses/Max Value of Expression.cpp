
#include<iostream>
#include<string> 
#include<vector>
#include<limits>
#include<algorithm>
using namespace std;

long long **Min(NULL),**Max(NULL);  // Value of expression can be very large

long long MaxValue(vector<int> numbers,vector<char> operations);
void Min_Max(int i,int j,vector<char> operations);

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
    Min=new long long*[n];
    Max=new long long*[n];
    for(int i=0;i<Str.size();i++){
        Min[i]=new long long[n];   
        Max[i]=new long long[n];
    } 
    cout<<MaxValue(numbers,operations); 
}

long long MaxValue(vector<int> numbers,vector<char> operations){
    for(int i=0;i<numbers.size();i++){
        Min[i][i]=Max[i][i]=numbers[i];
    }
    int n=numbers.size(),j;
    for(int s=1;s<n;s++){          // Increasing Order of j-i
        for(int i=0;i<n-s;i++){
            j=i+s;
            Min_Max(i,j,operations);
            //cout<<Max[i][j]<<" ";
        }
        //cout<<endl;
    }
    return Max[0][n-1];
}

bool Smaller(int a, int b){ 
    return (a < b); 
}

bool Larger(int a, int b){ 
    return (a > b); 
}

void Min_Max(int i,int j,vector<char> operations){

    char opk;
    long long sub1,sub2,sub3,sub4;
    Min[i][j]=numeric_limits<int>::max();
    Max[i][j]=numeric_limits<int>::min();
    for(int k=i;k<j;k++){
        opk=operations[k];
        switch (opk){
        case '-':
            sub1=Max[i][k]-Max[k+1][j];  
            sub2=Max[i][k]-Min[k+1][j];
            sub3=Min[i][k]-Max[k+1][j];
            sub4=Min[i][k]-Min[k+1][j];
            break;     
        case '+':
            sub1=Max[i][k]+Max[k+1][j];  
            sub2=Max[i][k]+Min[k+1][j];
            sub3=Min[i][k]+Max[k+1][j];
            sub4=Min[i][k]+Min[k+1][j];
            break;
        case '*':
            sub1=Max[i][k]*Max[k+1][j];  
            sub2=Max[i][k]*Min[k+1][j];
            sub3=Min[i][k]*Max[k+1][j];
            sub4=Min[i][k]*Min[k+1][j];
            break;        
        default:
            break;
        }

        Min[i][j]=min({sub1,sub2,sub3,sub4,Min[i][j]},Smaller);  // Smallest Among all Subexpression
        Max[i][j]=min({sub1,sub2,sub3,sub4,Max[i][j]},Larger);  // Largest Among all Subexpression
    }

}