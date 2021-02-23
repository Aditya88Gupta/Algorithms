#include<iostream>
#include<string> 
#include<vector>
#include<limits>
#include<algorithm>
using namespace std;

struct ListNode {
   int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* Merge(ListNode* Left, ListNode* Right);
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *Res;
        if(lists.size()==0)
            return NULL;
        Res=lists[0];
        for(int i=1;i<lists.size();i++)
            Res=Merge(Res,lists[i]);
        return Res;
    }
};

ListNode* Solution::Merge(ListNode* Left, ListNode* Right){
    ListNode *Res, *Tail;
    if (Left!=NULL){
        if (Right!=NULL && Left->val>=Right->val){
            Res=Right;
            Right=Right->next;
        }else{
            Res=Left;
            Left=Left->next;
        }
    } else if(Right!=NULL){
        Res=Right;
        Right=Right->next;
    } 
    Tail=Res;
    while(Left!=NULL && Right!=NULL){
        if (Left->val<=Right->val){
            Tail->next=Left;
            Tail=Left;
            Left=Left->next;
        } 
        else{
            Tail->next=Right;Tail=Right;
            Right=Right->next;
        }
    }
    while(Left!=NULL){
        Tail->next=Left;Tail=Left;
        Left=Left->next;
    }
    while(Right!=NULL){
        Tail->next=Right;Tail=Right;
        Right=Right->next;
    }
    return Res;
}