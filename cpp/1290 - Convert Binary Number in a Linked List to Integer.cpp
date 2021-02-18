class Solution {
public:
    int getDecimalValue(ListNode* head) {
        auto num{0};
        
        while(head)
        {
            num <<= 1;
            num += head->val;
            head = head->next;
        }
        return num;
    }
};