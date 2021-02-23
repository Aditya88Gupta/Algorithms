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
    ListNode* Split(ListNode *head);
    ListNode* MergeSort(ListNode *head);
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *Res, *Tail;
        if(lists.size()==0)
            return NULL;
        Res=lists[0];
        Tail=Res;
        for(int i=1;i<lists.size();i++){
            if (lists[i]==NULL)
                continue;
            while (Tail!=NULL && Tail->next!=NULL){
                Tail=Tail->next;
            }
            if (Tail==NULL){
                if (Res==NULL)
                    Res=lists[i];
                Tail=lists[i];
                continue;
            }
            Tail->next=lists[i];
            Tail=lists[i];
        }
        Res=MergeSort(Res);
        return Res;
    }
};

ListNode* Solution::Split(ListNode *head){
    ListNode *Jump2=head,*Jump1=head;
    while (Jump2->next!=NULL && Jump2->next->next!=NULL){
        Jump2 = Jump2->next->next;
        Jump1 = Jump1->next;
    }
    ListNode *Temp=Jump1->next;
    Jump1->next=NULL;
    return Temp;
}

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

ListNode* Solution::MergeSort(ListNode* head){
    if (head==NULL || head->next==NULL)
        return head;
    ListNode* mid = Split(head);
    head = MergeSort(head);
    mid = MergeSort(mid);
    return Merge(head,mid);
}
