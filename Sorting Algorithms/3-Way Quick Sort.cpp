
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

void Partition(vector<int> &Input,int start,int end,int* m1,int* m2){

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
    int x = start;int p =j-1;
    while (x<p){
        if(Input[x]==pivot){
            if(Input[p]==pivot){
                p-=1;
                continue;
            }
            Input[x] = Input[p];
            Input[p] = pivot;
            p--;
        }
        x+=1;
    }
    for(int i=start;i<=end;i++){
        if(Input[i]==pivot){
            p = i;
            break;
        }
    }
    *m2 = j;
    *m1 = p;
}

void QuickSort(vector<int> &Input,int start,int end){

    if (start>=end)
       return;     
    int pivot = rand()%(end-start)+start;
    int temp = Input[start];
    Input[start] = Input[pivot];
    Input[pivot] = temp;
    int m1,m2;
    Partition(Input,start,end,&m1,&m2);
    QuickSort(Input,start,m1-1);
    QuickSort(Input,m2+1,end);

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