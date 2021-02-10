#include<iostream>
#include<vector>
#include<cmath>
using namespace std;


vector<vector<int> > MatMul(vector<vector<int> > A,vector<vector<int> > B,int Am,int An,int Bm,int Bn);

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

int Wrapper(int val){
    // To ensure rows & columns are power of 2
    if(ceil(log2(val)) != floor(log2(val)))
        return (int)pow(2,ceil(log2(val)));
    return val;
}

void SetMat(int i,int m, int n,vector<vector<int> > A,vector<vector<int> > &Res){
    for(int x=0;x<m;x++){
        for(int y=0;y<n;y++)
            Res[i].push_back(A[x][y]);
        i++;
    }
}

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

int main(){
    int m1,n1,m2,n2;
    cin>>m1>>n1>>m2>>n2;
    int Copy_m1,Copy_m2,Copy_n1,Copy_n2;
    if (m1>m2){
        Copy_m1 = Wrapper(m1);
        Copy_m2 = Wrapper(m1);
    }else{
        Copy_m1 = Wrapper(m2);
        Copy_m2 = Wrapper(m2);
    }
    Copy_n1 = Copy_m1;        // Ensuring that MatMul receives square matrices
    Copy_n2 = Copy_m2;
    vector<vector<int> > Mat_1(Copy_m1, vector<int>());
    TakeInput(Copy_m1, Copy_n1, m1, n1, Mat_1);
    vector<vector<int> > Mat_2(Copy_m2, vector<int>());
    TakeInput(Copy_m2, Copy_n2, m2, n2, Mat_2);
    vector<vector<int> > Mat_3(Copy_m1, vector<int>());
    //SetZero(Copy_m1, Copy_n2, Mat_3);
    Mat_3 = MatMul(Mat_1,Mat_2,Copy_m1,Copy_n1,Copy_m2,Copy_n2);
    printMat(m1, n2, Mat_3);
    //printMat(Copy_m1, Copy_n1, Mat_1);
}


vector<vector<int> > Extract(int size,int x,int y,int m, int n,vector<vector<int> > A){
    // Function used for extracting sub-matrices from the main matrix
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

void Add(vector<vector<int> > &Res,vector<vector<int> > A,vector<vector<int> > B,int m,int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            Res[i][j]=(A[i][j]+B[i][j]);
    }
}

void Subtract(vector<vector<int> > &Res,vector<vector<int> > A,vector<vector<int> > B,int m,int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            Res[i][j]=(A[i][j]-B[i][j]);
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
    vector<vector<int> > P((int)(Am/2), vector<int>());
    vector<vector<int> > Q((int)(Am/2), vector<int>());
    vector<vector<int> > R((int)(Am/2), vector<int>());
    vector<vector<int> > S((int)(Am/2), vector<int>());
    vector<vector<int> > T((int)(Am/2), vector<int>());
    vector<vector<int> > U((int)(Am/2), vector<int>());
    vector<vector<int> > V((int)(Am/2), vector<int>());
    vector<vector<int> > A1((int)(Am/2), vector<int>());
    vector<vector<int> > A2((int)(Bm/2), vector<int>());
    vector<vector<int> > A3((int)(Am/2), vector<int>());
    vector<vector<int> > A4((int)(Am/2), vector<int>());
    vector<vector<int> > B1((int)(Bm/2), vector<int>());
    vector<vector<int> > B2((int)(Bm/2), vector<int>());
    vector<vector<int> > B3((int)(Bm/2), vector<int>());
    vector<vector<int> > B4((int)(Bm/2), vector<int>());
    vector<vector<int> > Comp1((int)(Am/2), vector<int>());
    vector<vector<int> > Comp2((int)(Bm/2), vector<int>());
    SetZero(Am/2,An/2,Comp1);         // For Reuseability
    SetZero(Bm/2,Bn/2,Comp2);
    A1 = Extract(Am/2,0,0,Am/2,An/2,A);
    B1 = Extract(Bm/2,0,0,Bm/2,Bn/2,B);
    A2 = Extract(Am/2,0,An/2,Am/2,An,A);
    B2 = Extract(Bm/2,Bm/2,0,Bm,Bn/2,B);
    B3 = Extract(Bm/2,0,Bn/2,Bm/2,Bn,B);
    B4 = Extract(Bm/2,Bm/2,Bn/2,Bm,Bn,B);
    A3 = Extract(Am/2,Am/2,0,Am,An/2,A);
    A4 = Extract(Am/2,Am/2,An/2,Am,An,A);
    Add(Comp1,A1,A4,Am/2,An/2);
    Add(Comp2,B1,B4,Bm/2,Bn/2);
    P = MatMul(Comp1,Comp2,Am/2,An/2,Bm/2,Bn/2);
    Add(Comp1,A3,A4,Am/2,An/2);
    Q = MatMul(Comp1,B1,Am/2,An/2,Bm/2,Bn/2);
    Subtract(Comp2,B3,B4,Bm/2,Bn/2);
    R = MatMul(A1,Comp2,Am/2,An/2,Bm/2,Bn/2);
    Subtract(Comp2,B2,B1,Bm/2,Bn/2);
    S = MatMul(A4,Comp2,Am/2,An/2,Bm/2,Bn/2);
    Add(Comp1,A1,A2,Am/2,An/2);
    T = MatMul(Comp1,B4,Am/2,An/2,Bm/2,Bn/2);
    Subtract(Comp1,A3,A1,Am/2,An/2);
    Add(Comp2,B1,B3,Bm/2,Bn/2);
    U = MatMul(Comp1,Comp2,Am/2,An/2,Bm/2,Bn/2);
    Subtract(Comp1,A2,A4,Am/2,An/2);
    Add(Comp2,B2,B4,Bm/2,Bn/2);
    V = MatMul(Comp1,Comp2,Am/2,An/2,Bm/2,Bn/2);
    vector<vector<int> > tmp((int)(Am/2), vector<int>());
    vector<vector<int> > tmp2((int)(Am/2), vector<int>());
    SetZero(Am/2,Bn/2,tmp);     // For Reuseability
    SetZero(Am/2,Bn/2,tmp2);
    Add(tmp,P,V,Am/2,Bn/2);
    Subtract(tmp2,S,T,Am/2,Bn/2);
    Add(Comp1,tmp,tmp2,Am/2,Bn/2);
    SetMat(0,Am/2,Bn/2,Comp1,Res);
    Add(Comp1,R,T,Am/2,Bn/2);
    SetMat(0,Am/2,Bn/2,Comp1,Res);
    Add(Comp1,Q,S,Am/2,Bn/2);
    SetMat(Am/2,Am/2,Bn/2,Comp1,Res);
    Add(tmp,P,U,Am/2,Bn/2);
    Subtract(tmp2,R,Q,Am/2,Bn/2);
    Add(Comp1,tmp,tmp2,Am/2,Bn/2);
    SetMat(Am/2,Am/2,Bn/2,Comp1,Res);
    
    return Res;
}