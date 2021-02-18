class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head)
        {
            return NULL;
        }
        auto next{head->next};
        if(next)
        {
            auto cc{head->next->next};
            head->next->next = head;
            head->next = swapPairs(cc);
            return next;
        }
        return head;
    }
};