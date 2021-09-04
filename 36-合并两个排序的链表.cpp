struct ListNode {
    ListNode* next;
    int val;
    ListNode(int x) : val(x) {

    }
};




class Solution {
public:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if (!l1 && l2) {
            return l2;
        } else if (!l2 && l1) {
            return l1;
        } else if (!l2 && !l1) {
            return nullptr;
        } 
        ListNode* dummy = new ListNode(-1);
        ListNode* p = dummy;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                p->next = l1;
                l1 = l1->next;
                p = p->next;
            } else {
                p->next = l2;
                l2 = l2->next;
                p = p->next;
            }
        }
        
        if (l1) {
            p->next = l1;
        } else {
            p->next = l2;
        }
        
        return dummy->next;
    }
};