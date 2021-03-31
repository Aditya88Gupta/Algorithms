#include<iostream> 
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int **SumTable(NULL);
int PossibleSum(int m, vector<int> Input);
    
int main(){
    int Sum(0),n;
    vector<int> numbers;
    cin>>n;
    for(int i=0;i<n;i++){
        int num;cin>>num;
        numbers.push_back(num);
        Sum+=num;
    }
    SumTable = new int*[n];
    int m = Sum/2;        // Min diff can be 0
    for(int i=0;i<n;i++){
        SumTable[i]=new int[m+1];
        for(int j=0;j<=m;j++){
            if(j==0)
                SumTable[i][j]=1;
            else
                SumTable[i][j]=0;
        }
    }
    sort(numbers.begin(),numbers.end());
    int Sum_1=PossibleSum(m,numbers);  // We check if a subset can have sum equal to half of total
    int Sum_2=Sum-Sum_1;
    cout<<abs(Sum_1-Sum_2);
}

void printMat(int n, int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<=m;j++)
            cout<<SumTable[i][j]<<" ";
    cout<<endl;
    }
}

int PossibleSum(int m, vector<int> Input){
    SumTable[0][Input[0]]=1;
    for(int i=1;i<Input.size();i++){
        for(int j=1;j<=m;j++){
            if(SumTable[i-1][j]==1)
                SumTable[i][j]=1;
            if(j>=Input[i] && SumTable[i-1][j-Input[i]]==1)
                SumTable[i][j]=1;
        }
    }
    //printMat(Input.size(),m);
    for(int j=m;j>=0;j--){
        if(SumTable[Input.size()-1][j]==1)
            return j;                    // Return sum nearest to half of total
    }
    return 0;
}


