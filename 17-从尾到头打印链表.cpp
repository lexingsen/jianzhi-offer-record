class Solution {
public:
    vector<int> printListReversingly(ListNode *head) {
        if (!head) {
            return {};
        }
        auto res = printListReversingly(head->next);
        res.emplace_back(head->val);
        return res;
    }
};