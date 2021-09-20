struct ListNode {
    ListNode* next;
    int val;
    ListNode(int x) : val(x) {

    }
};


/*
交叉走
1.走到了公共节点
2.走到了null
*/

class Solution {
public:
    ListNode *findFirstCommonNode(ListNode *headA, ListNode *headB) {
        auto p = headA;
        auto q = headB;
        while (p != q) {
            if (p) {
                p = p->next;
            } else {
                p = headB;
            }

            if (q) {
                q = q->next;
            } else {
                q = headA;
            }
        }
        return p;
    }
};