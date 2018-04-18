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
    ListNode* merge2Lists(ListNode* l1, ListNode* l2){
        if(l1==NULL && l2==NULL) return NULL;
        else if(l1==NULL) return l2;
        else if(l2==NULL) return l1;
        else if(l1->val<l2->val) {
            l1->next = merge2Lists(l1->next, l2);
            return l1;
        }
        else {
            l2->next = merge2Lists(l1, l2->next);
            return l2;
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        if(lists.size()==1) return lists[0];
        
        vector<ListNode*> newLists;
        
        for(int i=0; i<lists.size()/2; i++){
            newLists.push_back(merge2Lists(lists[i*2], lists[i*2+1]));
        }
        if(lists.size()%2>0){
            newLists.push_back(lists.back());
        }
        return mergeKLists(newLists);
    }
};
