class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode *last_dis = head, *p = head;
        
        bool flag = true, h=false;
        while (p->next) {
            if (p->val==p->next->val) flag=false;
            else if(flag) {
                if(!h) {
                    head = p;
                    last_dis = head;
                    h = true;
                }
                else{
                    last_dis->next = p;
                    last_dis = p;
                }
            }else if(!flag){
                flag = true;
            }
            p = p->next;
        }
        if(flag) {
            if(!h) return p;
            last_dis->next=p;
        }
        else {
            if(!h) return NULL;
            last_dis->next = NULL;
        }
        
        return head;
    }
};
