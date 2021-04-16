#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

struct Node{
    Node *Left,*Right;
    char ch;
    long fq;
    Node(char ch,long fq){
        Left=Right=NULL;
        this->ch= ch;
        this->fq= fq;
    }
};

struct Compare{
    bool operator()(Node *L, Node *R){
        return (L->fq > R->fq);
    }
};

void assignCode(struct Node *Root, string code){
    if(Root==NULL)
        return;
    if(Root->ch!='+'){
        cout<<Root->ch<<": "<<code<<endl;
    }
    assignCode(Root->Left,code+'0');
    assignCode(Root->Right,code+'1');    
}

void HuffmanTree(vector<char> letters, vector<long> count){    
    priority_queue<Node*,vector<Node*>,Compare> minHeap;
    for(size_t i=0;i<letters.size();i++){
        minHeap.push(new Node(letters[i],count[i]));
    }
    struct Node *Root;
    while(minHeap.size()!=1){
        struct Node *First,*Second;
        First = minHeap.top();
        minHeap.pop();
        Second = minHeap.top();
        minHeap.pop();
        Root = new Node('+',First->fq + Second->fq);
        Root->Left = First;
        Root->Right = Second;
        minHeap.push(Root);
    }
    assignCode(Root,"");
}

int main(){
    size_t n;
    cin>>n;
    vector<char> letters(n,'-');
    vector<long> count(n,0);
    for(size_t i=0;i<n;i++){
        char ch;cin>>ch;
        letters[i]=ch;
    }
    for(size_t i=0;i<n;i++){
        long tmp;cin>>tmp;
        count[i]=tmp;
    }
    HuffmanTree(letters,count);
    
    return 0;
}