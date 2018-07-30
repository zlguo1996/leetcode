class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||head->next==NULL) return head;
        
        int size=1;
        ListNode* last=head;
        while(last->next!=NULL){
            last = last->next;
            size++;
        }
        last->next = head;
        
        k = k%size;
        int offset = size-k;
        last = head;
        while(offset>1){
            last = last->next;
            offset--;
        }
        head = last->next;
        last->next = NULL;
        
        return head;
    }
};
