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

void CountingSort(vector<int> Input,int limit){
    
    int size = limit;
    int Count[size+1] = {0};
    int Pos[size+1] = {0};
    for(vector<int>::iterator item=Input.begin();item!=Input.end();item++){
        Count[*item]+=1;
    }
    Pos[1]=1;
    for (int index = 2;index<size;index++){
        Pos[index] = Pos[index-1] + Count[index-1];
    }
    int res[Input.size()+1] = {0};
    for(vector<int>::iterator item=Input.begin();item!=Input.end();item++){
        res[Pos[*item]] = *item;
        Pos[*item]+=1;
    }
    for(int i=1;i<Input.size()+1;i++){
        cout<<res[i]<<" ";
    }
    //return res;
}


int main(){

    int num;
    string input;
    getline(cin,input);
    cout<<"Enter the Upper Bound: ";
    cin>>num;
    vector<int> List; 
    List = split(input);
    int size = List.size();
    CountingSort(List,num+1);
    /*for(int i=0;i<size;i++){
        cout<<*(ptr+i)<<" ";
    }*/
    return 0;
}