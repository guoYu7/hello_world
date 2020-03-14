//
// Created by Zhangjun on 2020/3/14.
//
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};

ListNode* insertionSortList(ListNode* head) {
    ListNode *dummy = new ListNode(-1),*cur;
    cur = dummy;
    while(head){
        cur = dummy;
        ListNode* t = head->next;
        while(cur->next&&cur->next->val <= head->val){
            cur=cur->next;
        }
        head->next = cur->next;
        cur->next = head;
        head = t;
    }
    return dummy->next;
}



//反转链表
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
//删除链表最大节点（不含重复最大节点）（首末位置均可安全删除）
ListNode* deleteMaxNode(ListNode* head){//注意不能删除头指针，需要加额外条件
    ListNode *pre = head,*cur = head->next;
    ListNode *maxpre = pre,*maxp = head->next;
    while(cur){
        if(maxp->val < cur->val){
            maxp = cur;
            maxpre = pre;
        }
        pre = cur;
        cur = cur->next;
    }
    //看看头指针是不是最大的值
    if(head->val > maxp->val){
        maxpre = head;//maxpre有可能在head位置上，也有可能不在，maxp肯定不在head上
        head = head->next;
        delete maxpre;
        maxpre = nullptr;
        return head;
    }
    maxpre->next = maxp->next;//执行删除操作，前序指针直接指向maxp的下一个
    //free(maxp);//释放掉maxp指针
    delete maxp;
    return head;
}


//删除链表最小的节点（不含重复最小节点）（首末位置均可安全删除）
ListNode* deleteMinNode(ListNode* head){//注意不能删除头指针，需要加额外条件
    ListNode *pre = head,*cur = head->next;
    ListNode *minpre = pre,*minp = head->next;
    while(cur){
        if(minp->val > cur->val){
            minp = cur;
            minpre = pre;
        }
        pre = cur;
        cur = cur->next;
    }
    //看看头指针是不是最大的值
    if(head->val < minp->val){
        minpre = head;//maxpre有可能在head位置上，也有可能不在，maxp肯定不在head上
        head = head->next;
        delete minpre;
        minpre = nullptr;
        return head;
    }
    minpre->next = minp->next;//执行删除操作，前序指针直接指向maxp的下一个
    //free(maxp);//释放掉maxp指针
    delete minp;
    return head;
}

// 删除所有val==num 的节点
ListNode* removeNode(ListNode *head,int num)
{
    ListNode *cur = NULL;
    while(NULL != head){ //看看头指针是不是等于num
        if(num != head->val)
            break;
        cur = head;
        head = head->next;
        delete cur;
    }
    //找后面，看还有没有等于num的节点
    cur = head;
    ListNode *pre = head;
    while(NULL != cur){
        if(num == cur->val){
            pre->next = cur->next;
            delete cur;
        }
        else{
            pre = cur;
        }
        cur = pre->next;
    }
    return head;
}


int main(){
    ListNode* head = new ListNode(-1),*cur;
    cur = head;
    srand((unsigned int)time(NULL));//产生随机数的种子

    for(int i=0;i<10;i++){
        ListNode* l = new ListNode((rand()%100));
        cur->next = l;
        cur = l;
    }
    cur = head;
    cout<<"raw:"<<endl;
    while(cur){
        cout<<cur->val<<" ";
        cur = cur->next;
    }
    cout<<endl;
    cout<<"reverse:"<<endl;
    head = reverse(head);
    cur = head;
    while (cur){
        cout<<cur->val<<" ";
        cur = cur->next;
    }
    cout<<endl;
    cout<<"insertionSort:"<<endl;
    head = insertionSortList(head);
    cur = head;
    while(cur){
        cout<<cur->val<<" ";
        cur = cur->next;
    }
    cout<<endl;


    //head = deleteMinNode(head);
    head = deleteMaxNode(head);
    //head = removeNode(head,1);
    cout<<"delete max or min or val == num:"<<endl;
    cur = head;
    while(cur){
        cout<<cur->val<<" ";
        cur = cur->next;
    }
    cout<<endl;

    return 0;
}







