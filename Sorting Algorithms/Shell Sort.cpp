 // Generalized Version Of Insertion Sort
//  Inplace but not stable

#include <iostream>
#include <string> 
#include <vector>
using namespace std;


/*vector<int> split(string str){
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
}*/


void ShellSort(vector< pair <int,int> > &List){
    
    int gap=List.size()/3;
    while (gap>1){
        for(int i=0;i<List.size()-gap;i++){
            pair<int,int> tmp;
            if(i+gap<List.size() && List[i].first>List[i+gap].first){
                tmp=List[i];
                List[i]=List[i+gap];
                List[i+gap]=tmp;
            }
        }
        gap=gap/2;
    }
    
    for(int i=1;i<List.size();i++){
        int key = List[i].first;
        int val = List[i].second;
        int j = i-1;
        // Shifting Elements
        while(j>=0 && key<List[j].first){ 
            List[j+1].first = List[j].first;
            List[j+1].second = List[j].second;
            j--;
        }
        List[j+1].first=key;
        List[j+1].second=val;
    }

}

int main(){

    //string input;
    //getline(cin,input);
    int n,tmp; cin>>n;
    vector< pair <int,int> > List;
    for(int i=0;i<n;i++){
        pair<int,int> tmp;
        cin>>tmp.first;
        tmp.second=0;
        List.push_back(tmp);
    }
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        List[i].second=tmp;
    } 
    //List = split(input);
    //Res = Merge(List,List);
    ShellSort(List);
    for(int i=0;i<n;i++)
        cout<<List[i].first<<" ";
    cout<<endl;
    for(int i=0;i<n;i++)
        cout<<List[i].second<<" ";
    return 0;
}
