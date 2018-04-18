/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* t1 = head;
        if(t1==NULL) return head;
        ListNode* t2 = head->next;
        if(t2==NULL) return head;
        
        t1->next = t2->next;
        t2->next = t1;
        t1->next = swapPairs(t1->next);
        
        return t2;
    }
};
