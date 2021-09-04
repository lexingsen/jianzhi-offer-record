struct ListNode {
    ListNode* next;
    int val;
    ListNode(int x) : val(x) {

    }
};


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            // cur = cur->next; cur->next已经被覆盖掉了，所以被覆盖之前需要保存一下
            cur = next;
        }
        return pre;
    }
};


