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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *ptr1=head, *ptr2=head;
        
        while(n>0) {
            ptr1 = ptr1->next;
            n--;
        }
        
        if(!ptr1){
            head = head->next;
            return head;
        }
        
        while(ptr1->next){
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        
        ptr2->next = ptr2->next->next;
        
        return head;
    }
};
