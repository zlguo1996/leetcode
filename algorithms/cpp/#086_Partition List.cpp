class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *f=NULL, *l=NULL, *res=NULL, *p=head, *lf=NULL;
        while (p) {
            if(p->val<x){
                if(f) f->next = p;
                else res = p;
                f = p;
                p = p->next;
                f->next = lf;
            }else{
                if(l) l->next = p;
                else{
                    if(f) f->next = p;
                    else res = p;
                    lf = p;
                }
                l = p;
                p = p->next;
                l->next = NULL;
            }
        }
        
        return res;
    }
};
