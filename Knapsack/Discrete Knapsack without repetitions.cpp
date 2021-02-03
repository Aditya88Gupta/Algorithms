
#include<iostream>
#include<string> 
#include<vector>
using namespace std;

long **Matrix(NULL);
int MaxValue(long capacity,vector<long> gold_bars);

int main(){

   long Cap,num,weight;
   vector<long> gold_bars;
   cin>>Cap>>num;
   Matrix=new long*[num+1];
   for(long i=0;i<num;i++){
       cin>>weight;
       gold_bars.push_back(weight);
       Matrix[i]=new long[Cap+1];
       Matrix[i][0]=0;                          // If knapsack of weight 0
    }
    Matrix[num]=new long[Cap+1];
    Matrix[num][0]=0;
   cout<<MaxValue(Cap,gold_bars);
   return 0;
}

int MaxValue(long capacity,vector<long> gold_bars){
    for(long j=0;j<=capacity;j++)
        Matrix[0][j]=0;                       // gold_bar of weight 0
    for(long i=1;i<=gold_bars.size();i++){   //  Filling the table rowise
        for(long j=1;j<=capacity;j++){
            if(j<gold_bars[i-1])             // If knapsack's weight < weight of gold_bar 
                Matrix[i][j]=Matrix[i-1][j];
            else if(j==gold_bars[i-1])      //  If knapsack's weight = weight of gold_bar
                Matrix[i][j]=gold_bars[i-1];
            else{
                Matrix[i][j]=gold_bars[i-1]+Matrix[i-1][j-gold_bars[i-1]]; // If Selected
                if(Matrix[i-1][j]>Matrix[i][j])
                   Matrix[i][j]=Matrix[i-1][j]; // If Rejected
            }            
        }
    }
    /*for(long i=0;i<=gold_bars.size();i++){
        for(long j=0;j<=capacity;j++){
            cout<<Matrix[i][j]<<" ";
        }
        cout<<endl;
    }*/
    return Matrix[gold_bars.size()][capacity];
}