  // Generalized Version Of Selection Sort
 //  Inplace but not stable

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

int Parent(int i){
    return i-1/2;
}

int Right(int i){
    return 2*i+2;
}

int Left(int i){
    return 2*i+1;
}

/*void ShiftUp(vector<int> &List, int index){
    while (index!=0 && List[Parent(index)]<List[index]){
        int tmp = List[Parent(index)];
        List[Parent(index)] = List[index];
        List[index] = tmp;
        index = Parent(index);
    }
}*/

//O(logn)
void ShiftDown(vector<int> &List, int index, int Size){
    int maxIndex = index;
    // Check if Left Child Exists, then whether it violates heap property
    if (Left(index)<Size && List[Left(index)]>List[index]){
        maxIndex=Left(index);
    }
    // Check if Right Child Exists, then if it is greater than index and it's left 
    if (Right(index)<Size && List[Right(index)]>List[maxIndex]){
        maxIndex=Right(index);
    }
    if (index!=maxIndex){
        // Swap
        int tmp = List[maxIndex];
        List[maxIndex] = List[index];
        List[index] = tmp;
        ShiftDown(List,maxIndex,Size);
    }
}

// O(n)
void BuildHeap(vector<int> &List,int Size){
    // Last Size/2 are leaf
    for (int i=Size/2;i>=0;i--)
        ShiftDown(List,i,Size);
}

void HeapSort(vector<int> &List, int Size){
    BuildHeap(List,Size);
    for(int i=0;i<List.size()-1;i++){
        // For every iteration max is at 0th index
        int tmp = List[Size-1];
        List[Size-1] = List[0];
        List[0] = tmp;
        Size--;
        ShiftDown(List,0,Size);
    }
}

int main(){

    string input;
    getline(cin,input);
    vector<int> List;
    List = split(input);
    int Size = List.size();
    HeapSort(List,Size);
    for(int i=0;i<Size;i++)
        cout<<List[i]<<" ";
    return 0;
}
