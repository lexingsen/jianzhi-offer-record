
struct ListNode {
    int val;
    ListNode* next, *random;
    ListNode(int x):val(x), next(nullptr), random(nullptr) {}
};


// https://www.acwing.com/solution/content/38525/
class Solution {
public:
    ListNode *copyRandomList(ListNode *head) {
        if (!head) {
            return head;
        }
        ListNode* p = head;
        while (p != nullptr) {
            ListNode* np = new ListNode(p->val);
            np->next = p->next;
            p->next = np;
            p = p->next->next;
        }

        p = head;
        while (p != nullptr) {
            if (p->random != nullptr) {
                p->next->random = p->random->next;
            }
            p = p->next->next;
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        p = head;
        while (p != nullptr) {
            cur->next = p->next;
            cur = cur->next;
            p->next = p->next->next;
            p = p->next;
        }

        return dummy->next;
    }
};