
#include <iostream>
#include <string> 
#include <vector>
using namespace std;


// start-j contains all elements <= pivot
// j-end contains all elements > pivot
int Partition(vector<float> &Input,int start,int end){

    int j= start;  
    float pivot = Input[start];
    for (int i = start+1;i<=end;i++){
        if (pivot>= Input[i]){
            j += 1;
            float temp = Input[j];
            Input[j] = Input[i];
            Input[i] = temp; 
        }
    }
    float temp = Input[j];
    Input[j] = Input[start];
    Input[start] = temp;
    return j;
}

void QuickSort(vector<float> &Input,int start,int end){
        
    while (start<end){
        int pivot = rand()%(end-start)+start;  // Randomly selecting pivot 
        float temp = Input[start];
        Input[start] = Input[pivot];
        Input[pivot] = temp;
        int m = Partition(Input, start, end);
        // Eliminating tail recursion to minimize recursion depth and memory usage to logarithmic
        if ((m-start)<(end-m)){
            QuickSort(Input,start,m-1);
            start = m+1;
        }else{
            QuickSort(Input,m+1,end);
            end = m-1;
        }
    }
}
