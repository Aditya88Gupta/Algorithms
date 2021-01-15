
#include <iostream>
#include <string> 
#include <vector>
using namespace std;


vector<int> split(string str){
    size_t pos = 0;
    string token;
    vector<string>temp;
    while ((pos = str.find(" ")) != string::npos){
        token = str.substr(0, pos);
        //cout << token << std::endl;
        temp.push_back(token);
        str.erase(0, pos + 1);
        //cout << str << std::endl;
    }
    token = str.substr(0, pos);
    temp.push_back(token);
    vector<int> input;
    for(vector<string>::iterator i=temp.begin();i!=temp.end();i++){
        input.push_back(stoi(*i));
    }
    
    return input;
}

int Partition(vector<int> &Input,int start,int end){

    int j= start;
    int pivot = Input[start];
    for (int i = start+1;i<=end;i++){
        if (pivot>= Input[i]){
            j += 1;
            int temp = Input[j];
            Input[j] = Input[i];
            Input[i] = temp; 
        }
    }
    int temp = Input[j];
    Input[j] = Input[start];
    Input[start] = temp;
    return j;
}

void QuickSort(vector<int> &Input,int start,int end){
        
    while (start<end){
        int pivot = rand()%(end-start)+start;
        int temp = Input[start];
        Input[start] = Input[pivot];
        Input[pivot] = temp;
        int m = Partition(Input, start, end);
        if ((m-start)<(end-m)){
            QuickSort(Input,start,m-1);
            start = m+1;
        }else{
            QuickSort(Input,m+1,end);
            end = m-1;
        }
    }
}


int main(){

    string input;
    getline(cin,input);
    vector<int> List; 
    List = split(input);
    int size = List.size();
    QuickSort(List,0,size-1);
    for(int i=0;i<size;i++){
        cout<<List[i]<<" ";
    }
    return 0;
}