class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* res = head;
        ListNode* p = head;
        ListNode* begin=NULL, *end;
        ListNode* rbegin, *rend;
        
        int count = 1;
        while (count<m-1) {
            count++;
            p = p->next;
        }
        if(m!=1) {
            begin = p;
            count++;
            p = p->next;
        }
        rbegin = p;
        
        ListNode* prev=begin;
        ListNode* tmp=p->next;
        while (count<n) {
            tmp = p->next;
            p->next = prev;
            prev = p;
            p = tmp;
            count++;
        }
        rend = p;
        end = p->next;
        p->next = prev;
        
        if(!begin) res = rend;
        else begin->next = rend;
        
        rbegin->next = end;
        
        return res;
    }
};
