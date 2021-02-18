class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
        {
            return head;
        }
        int length = 1;
        ListNode* last = head;
        while(last->next)
        {
            ++length;
            last = last->next;
        }
        k %= length;
        if(k == 0)
        {
            return head;
        }
        ListNode* next = head;
        ListNode* prev;
        for(int i = 0; i < length - k; ++i)
        {
            prev = next;
            next = next->next;
        }
        last->next = head;
        prev->next = NULL;
        return next;
    }
};