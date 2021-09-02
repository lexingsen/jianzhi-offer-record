


struct ListNode
{
    ListNode* next;
    int val;

    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    void deleteNode(ListNode* node) {
      if (!node || !node->next) {
        return;
      }
      ListNode* p = node->next;
      node->val = p->val;
      node->next = p->next;
      delete p;
    }
};