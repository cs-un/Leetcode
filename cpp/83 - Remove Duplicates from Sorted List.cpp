class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        auto it{head};
        while(it && it->next)
        {
            if(it->next->val == it->val)
            {
                auto temp = it->next;
                it->next = it->next->next;
                delete temp;
            }
            else
            {
                it = it->next;
            }
        }
        return head;
    }
};