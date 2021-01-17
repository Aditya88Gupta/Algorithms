#include <iostream>
#include <string> 
#include <vector>
#include "Quick Sort.h"
using namespace std;


vector<float> split(string str){
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
    vector<float> input;
    for(vector<string>::iterator i=temp.begin();i!=temp.end();i++){
        input.push_back(stof(*i));
    }
    
    return input;
}

int GroupChildren(vector<float>Input){
    int i=0;
    float lower,upper;
    int num=0;
    while (i<Input.size()){
        lower = Input[i];
        upper = Input[i]+1;
        cout<<lower;
        i++;
        while (i<Input.size() & (Input[i]<=upper)){
            cout<<", "<<Input[i];
            i++;
        } 
        cout<<endl;
        num++;
    }

    return num;
}

int main(){

    string input;
    getline(cin,input);
    vector<float> List; 
    List = split(input);
    int size = List.size();
    QuickSort(List,0,size-1);
    int num = GroupChildren(List);
    cout<<"Minimum number of such groups: "<<num;
    return 0;
}