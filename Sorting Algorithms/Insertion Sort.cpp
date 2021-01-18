// Insertion Sort, useful for almost sorted inputs 

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


void InsertionSort(vector<int> &Input){

    for(int i=1;i<Input.size();i++){
        int val = Input[i];
        int j = i-1;
        // Shifting Elements
        while(j>=0 && val<Input[j]){  
            Input[j+1] = Input[j];
            j--;
        }
        Input[j+1]= val;
    }

}

int main(){

    string input;
    getline(cin,input);
    vector<int> List; 
    List = split(input);
    int size = List.size();
    InsertionSort(List);
    for(int i=0;i<size;i++){
        cout<<List[i]<<" ";
    }
    return 0;
}