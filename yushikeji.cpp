
//编写代码，以给定值x为基准将链表分割成两部分，所有小于x的结点排在大于或等于x的结点之前

//给定一个链表的头指针 ListNode* pHead，请返回重新排列后的链表的头指针。注意：分割以后保持原来的数据顺序不变。





struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/

class Partition {
public:
    ListNode* partition(ListNode*pHead,int x)
    {
        if(pHead == NULL)
            return NULL;
        ListNode *pcur = pHead;
        ListNode *bstart = NULL;
        ListNode *bend = NULL;
        ListNode *sstart = NULL;
        ListNode *send = NULL;
        while(pcur)
        {
            if (pcur->val < x){
                if (send == NULL){
                    sstart = send = pcur;
                }
                else{
                    send->next = pcur;
                    send = pcur;
                }
            }
            else
            {
                if(bend == NULL){
                    bstart = bend = pcur;
                }
                else{
                    bend->next = pcur;
                    bend = pcur;
                }
            }
            pcur = pcur->next;
        }

        if(send != NULL)
        {
            send->next = bstart;
        }
        if(bend != NULL)
        {
            bend->next = NULL;
        }
        return sstart == NULL ? bstart: sstart;
    }
};







/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/

class Partition {
public:


    ListNode* partition(ListNode*pHead,int x)
    {
        if(pHead == NULL)
            return NULL;
        ListNode *smallstart = NULL;
        ListNode *smallend = NULL;

        ListNode *bigstart = NULL;
        ListNode *bigend = NULL;

        ListNode *pCur = pHead;

        while(pCur)
        {
            if (pCur->val < x)
            {
                if (smallend == NULL) //表示这是小的部分的头结点
                {
                    smallstart = smallend = pCur;
                }
                else
                {
                    smallend->next = pCur;
                    smallend = pCur;
                }
            }
            else
            {
                if(bigend == NULL) //表示这是大于或等于x的头结点
                {
                    bigstart = bigend = pCur;
                }
                else
                {
                    bigend->next = pCur;
                    bigend = pCur;
                }
            }
            pCur = pCur->next;
        }


        if(smallend != NULL)
        {
            smallend->next = bigstart;
        }
        if(bigend != NULL)
        {
            bigend->next = NULL;
        }

        return smallstart == NULL ? bigstart: smallstart;

    }
};



