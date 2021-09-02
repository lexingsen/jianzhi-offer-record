#include <iostream>
using namespace std;


struct ListNode
{
    ListNode* next;
    int val;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* findKthToTail(ListNode* pListHead, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = pListHead;
        int cnt = 0;
        ListNode* p = dummy;
        while (p->next) {
            cnt++;
            p = p->next;
        }
        if (k > cnt) {
            return NULL;
        }
        p = dummy;
        int loop = cnt - k + 1;
        while (loop--) {
            p = p->next;
        }
        return p;
    }
};

