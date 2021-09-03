

struct ListNode {
    ListNode* next;
    int val;
    ListNode(int x) : val(x) {

    }
};

class Solution {
public:
    // 可能会删除头节点，增加虚拟节点，将头节点和其他节点统一处理
    ListNode* deleteDuplication(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* p = dummy;
        while (p->next) {
            ListNode* q = p->next;
            while (q && p->next->val == q->val) {
                q = q->next;
            }
            if (p->next == q) {
                p = p->next;
            } else {
                p->next = q;
            }
        }

        return dummy->next;
    }
};