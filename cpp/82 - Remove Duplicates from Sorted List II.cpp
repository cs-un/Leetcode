class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        auto it{head};
        ListNode* prev{NULL};
        while(it)
        {
            if(it->next && it->next->val == it->val)
            {
                auto next{it->next->next};
                while(next && it->val == next->val)
                {
                    next = next->next;
                }
                it = next;
            }
            else
            {
                if(prev)
                {
                    prev->next = it;
                }
                else
                {
                    head = it;
                }
                prev = it;
                it = it->next;
            }
        }
        
        if(!prev)
        {
            return NULL;
        }
        prev->next = it;
        
        return head;
    }
};