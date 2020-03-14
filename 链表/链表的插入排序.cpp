//   https://leetcode-cn.com/problems/insertion-sort-list/


/**链表的插入排序
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        
        ListNode *dummy = new ListNode(-1),*cur;
        cur = dummy;
        while(head)
        {
            cur = dummy;
            ListNode* t = head->next;
            
            while(cur->next&&cur->next->val <= head->val)
            {
                cur=cur->next;               
            }
            head->next = cur->next;
            cur->next = head;
            head = t;
             
        }
        return dummy->next;
    }
};



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


//归并排序
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        
        if(!head || !head->next)
            return head;
        
        ListNode *slow,*fast,*pre;
        slow = fast = head;
        
        while(fast && fast->next)
        {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        pre->next = NULL;
        
        return merge(sortList(head),sortList(slow));
    }
    
    
    ListNode* merge(ListNode* l1, ListNode* l2)
    {
        if(!l1) return l2;
        if(!l2) return l1;
        
        if(l1->val < l2->val)
        {
            l1->next = merge(l1->next,l2);
            return l1;
        }
        else
        {
            l2->next = merge(l1,l2->next);
            return l2;
        }
    }
};



//快速排序
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        
        if(!head || !head->next)
            return head;
        
        ListNode* small = new ListNode(-1);
        ListNode* large = new ListNode(-1);
        
        ListNode *s,*l,*cur;
        s = small;
        l = large;
        cur = head->next;
        
        while(cur)
        {
            if(cur->val < head->val)
            {
                s->next = cur;
                s = cur;
            }
            else
            {
                l->next = cur;
                l = cur;
            }
            cur = cur->next;
        }      
        s->next = NULL;
        l->next = NULL;
        
        small = sortList(small->next);
        large = sortList(large->next);
        
        cur = small;
        
        if(cur)
        {
            while(cur->next)
                cur = cur->next;
            cur->next = head;
            head->next = large;
            return small;
        }
        else
        {
            head->next = large;
            return head;
        }
    }
};


