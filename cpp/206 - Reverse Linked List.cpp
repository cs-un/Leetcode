class Solution {
public:
    ListNode* reverseList(ListNode* head, ListNode* prev = NULL) {
        if(!head)
        {
            return prev;
        }

        auto res = reverseList(head->next, head);
        head->next = prev;
        
        return res;
    }
};