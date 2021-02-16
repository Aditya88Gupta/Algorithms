 // Merge Sort 
//  Not an inplace sorting algorithm

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


vector<int> Merge(vector<int> Left, vector<int> Right){
    vector<int> Res;
    int Lindex(0),Rindex(0);
    while(Lindex<Left.size() && Rindex<Right.size()){
        if (Left[Lindex]<=Right[Rindex]){
            Res.push_back(Left[Lindex]);
            Lindex++;
        } 
        else{
            Res.push_back(Right[Rindex]);
            Rindex++;
        }
    }
    while(Lindex<Left.size()){
        Res.push_back(Left[Lindex]);
        Lindex++;
    }
    while(Rindex<Right.size()){
        Res.push_back(Right[Rindex]);
        Rindex++;
    }
    return Res;
}

vector<int> MergeSort(vector<int> Input,int start,int end){
    if (start==end){
        vector<int> tmp;
        tmp.push_back(Input[start]);
        return tmp;
    }
    vector<int> LeftHalf; vector<int> RightHalf;
    LeftHalf= MergeSort(Input,start,(start+end)/2); 
    RightHalf= MergeSort(Input,((start+end)/2)+1,end);
    return Merge(LeftHalf,RightHalf);
}


int main(){
    string input;
    getline(cin,input);
    vector<int> List; vector<int> Res;
    List = split(input);
    int Size = List.size();
    Res= MergeSort(List,0,Size-1);
    //Res = Merge(List,List);
    for(int i=0;i<Size;i++)
        cout<<Res[i]<<" ";
    return 0;
}