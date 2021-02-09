#include<iostream>
#include<vector>
#include<cmath>
using namespace std;


void TakeInput(int Copy_m, int Copy_n, int m, int n, vector<vector<int> > &Matrix){
    for(int i=0;i<Copy_m;i++){
        for(int j=0;j<Copy_n;j++){
            if (i<m && j<n){
                int num;
                cin>>num;
                Matrix[i].push_back(num);
            }else 
                Matrix[i].push_back(0);
        }
    }
}

void SetZero(int m, int n,vector<vector<int> > &Matrix){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            Matrix[i].push_back(0);
    }
}


void printMat(int m, int n, vector<vector<int> > Matrix){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<Matrix[i][j]<<" ";
        }
        cout<<"\n";
    }
}

vector<vector<int> > Extract(int size,int x,int y,int m, int n,vector<vector<int> > A){
    vector<vector<int> > Matrix(size,vector<int>());
    int tmp=0;
    for(int i=x;i<m;i++){
        for(int j=y;j<n;j++)
            Matrix[tmp].push_back(A[i][j]);
        tmp++;
    }
    //printMat(size,n,Matrix);
    return Matrix;
}

int Wrapper_1(int m){
    if(ceil(log2(m)) != floor(log2(m)))
        return (int)pow(2,ceil(log2(m)));
    return m;
}

void SetMat(int i,int m, int n,vector<vector<int> > A,vector<vector<int> > &Res){
    for(int x=0;x<m;x++){
        for(int y=0;y<n;y++)
            Res[i].push_back(A[x][y]);
        i++;
    }
}

void Add(vector<vector<int> > &Res,vector<vector<int> > A,vector<vector<int> > B,int m,int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            Res[i].push_back(A[i][j]+B[i][j]);
    }
}

vector<vector<int> > MatMul(vector<vector<int> > A,vector<vector<int> > B,int Am,int An,int Bm,int Bn){
    
    if ((Am<=2 && An<=2) && (Bm<=2 && Bn<=2)){
        vector<vector<int> > Temp(Am, vector<int>());
        Temp[0].push_back(A[0][0]*B[0][0]+A[0][1]*B[1][0]);
        Temp[0].push_back(A[0][0]*B[0][1]+A[0][1]*B[1][1]);
        Temp[1].push_back(A[1][0]*B[0][0]+A[1][1]*B[1][0]);
        Temp[1].push_back(A[1][0]*B[0][1]+A[1][1]*B[1][1]);
        return Temp;
    }
    vector<vector<int> > Res(Am, vector<int>());
    //SetZero(Am,Bn,Res);
    vector<vector<int> > P1((int)(Am/2), vector<int>());
    vector<vector<int> > P2((int)(Am/2), vector<int>());
    vector<vector<int> > P3((int)(Am/2), vector<int>());
    vector<vector<int> > P4((int)(Am/2), vector<int>());
    vector<vector<int> > P5((int)(Am/2), vector<int>());
    vector<vector<int> > P6((int)(Am/2), vector<int>());
    vector<vector<int> > P7((int)(Am/2), vector<int>());
    vector<vector<int> > P8((int)(Am/2), vector<int>());
    vector<vector<int> > tmp1((int)(Am/2), vector<int>());
    vector<vector<int> > tmp2((int)(Bm/2), vector<int>());
    vector<vector<int> > Comp1((int)(Am/2), vector<int>());
    vector<vector<int> > Comp2((int)(Am/2), vector<int>());
    vector<vector<int> > Comp3((int)(Am/2), vector<int>());
    vector<vector<int> > Comp4((int)(Am/2), vector<int>());
    
    tmp1 = Extract(Am/2,0,0,(int)(Am/2),(int)(An/2),A);
    tmp2 = Extract(Bm/2,0,0,(int)(Bm/2),(int)(Bn/2),B);
    P1 = MatMul(tmp1,tmp2,Am/2,An/2,Bm/2,Bn/2);
    tmp1 = Extract(Am/2,0,(An/2),(Am/2),An,A);
    tmp2 = Extract(Bm/2,Bm/2,0,Bm,Bn/2,B);
    //printMat(Bm/2,Bn/2,tmp2);
    P2 = MatMul(tmp1,tmp2,(Am/2),(An/2),(Bm/2),(Bn/2));
    Add(Comp1,P1,P2,Am/2,Bn/2);
    SetMat(0,Am/2,Bn/2,Comp1,Res);
    tmp1 = Extract(Am/2,0,0,Am/2,An/2,A);
    tmp2 = Extract(Bm/2,0,Bn/2,Bm/2,Bn,B);
    P3 = MatMul(tmp1,tmp2,Am/2,An/2,Bm/2,Bn/2);
    tmp1 = Extract(Am/2,0,An/2,Am/2,An,A);
    tmp2 = Extract(Bm/2,Bm/2,Bn/2,Bm,Bn,B);
    P4 = MatMul(tmp1,tmp2,Am/2,An/2,Bm/2,Bn/2);
    Add(Comp2,P3,P4,Am/2,Bn/2);
    SetMat(0,Am/2,Bn/2,Comp2,Res);
    tmp1 = Extract(Am/2,Am/2,0,Am,An/2,A);
    tmp2 = Extract(Bm/2,0,0,Bm/2,Bn/2,B);
    P5 = MatMul(tmp1,tmp2,Am/2,An/2,Bm/2,Bn/2);
    tmp1 = Extract(Am/2,Am/2,An/2,Am,An,A);
    tmp2 = Extract(Bm/2,Bm/2,0,Bm,Bn/2,B);
    P6 = MatMul(tmp1,tmp2,Am/2,An/2,Bm/2,Bn/2);
    Add(Comp3,P5,P6,Am/2,Bn/2);
    SetMat(Am/2,Am/2,Bn/2,Comp3,Res);
    tmp1 = Extract(Am/2,Am/2,0,Am,An/2,A);
    tmp2 = Extract(Bm/2,0,Bn/2,Bm/2,Bn,B);
    P7 = MatMul(tmp1,tmp2,Am/2,An/2,Bm/2,Bn/2);
    tmp1 = Extract(Am/2,Am/2,An/2,Am,An,A);
    tmp2 = Extract(Bm/2,Bm/2,Bn/2,Bm,Bn,B);
    P8 = MatMul(tmp1,tmp2,Am/2,An/2,Bm/2,Bn/2);
    Add(Comp4,P7,P8,Am/2,Bn/2);
    SetMat(Am/2,Am/2,Bn/2,Comp4,Res);
    return Res;
}

int main(){
    int m1,n1,m2,n2;
    cin>>m1>>n1>>m2>>n2;
    int Copy_m1,Copy_m2,Copy_n1,Copy_n2;
    Copy_m1 = Wrapper_1(m1);
    Copy_n1 = Wrapper_1(n1);
    Copy_m2 = Wrapper_1(m2);
    Copy_n2 = Wrapper_1(n2);
    vector<vector<int> > Mat_1(Copy_m1, vector<int>());
    TakeInput(Copy_m1, Copy_n1, m1, n1, Mat_1);
    vector<vector<int> > Mat_2(Copy_m2, vector<int>());
    TakeInput(Copy_m2, Copy_n2, m2, n2, Mat_2);
    vector<vector<int> > Mat_3(Copy_m1, vector<int>());
    //SetZero(Copy_m1, Copy_n2, Mat_3);
    Mat_3 = MatMul(Mat_1,Mat_2,Copy_m1,Copy_n1,Copy_m2,Copy_n2);
    printMat(m1, n2, Mat_3);
    //printMat(Copy_m2, Copy_n2, Mat_2);
}