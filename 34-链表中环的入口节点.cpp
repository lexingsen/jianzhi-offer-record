#include <iostream>
#include <cstdio>
using namespace std;

struct ListNode {
    ListNode* next;
    int val;
    ListNode(int x) : val(x) {

    }
};


class Solution {
public:
    ListNode *entryNodeOfLoop(ListNode *head) {
        if (!head || !head->next) {
            return nullptr;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while (slow && fast) {
            // 满指针每次走一步  快指针每次走两步
            slow = slow->next;
            fast = fast->next;
            if (fast) {
                fast = fast->next;
            } else {
                return nullptr;
            }

            // 第一次相遇
            if (slow == fast) {
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};
