//
// Created by Zhangjun on 2020/3/13.
//
#include <iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};

ListNode* reverse(ListNode *head){
    ListNode *pre=NULL,*cur=head,*next=head->next;
    while(cur){
        cur->next = pre;
        pre = cur;
        cur = next;
        if(next)
            next = next->next;
    }
    return pre;
}

int main(){
    ListNode* head = new ListNode(-1),*cur;
    cur = head;
    for(int i=0;i<10;i++){
        ListNode* l = new ListNode(i*i);
        cur->next = l;
        cur = l;
    }
    cur = head;
    while(cur){
        cout<<cur->val<<" ";
        cur = cur->next;
    }

    cur = reverse(head);
    cout<<endl;

    while (cur){
        cout<<cur->val<<" ";
        cur = cur->next;
    }
    cout<<endl;
}

