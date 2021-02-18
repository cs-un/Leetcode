class Solution {
public:
    void deleteNode(ListNode* node) {
        auto next = node->next;
        *node = *node->next;
        delete next;
    }
};