class Solution {
public:
    Node* helper(Node* head)
    {
        if(!head)
        {
            return NULL;
        }

        auto next = helper(head->child);
        if(next)
        {
            auto temp = head->next;
            next->next = temp;
            head->next = head->child;
            if(temp)
            {
                temp->prev = next;
            }
            head->child->prev = head;
            head->child = NULL;
        }
        if(!head->next)
        {
            return head;
        }
        return helper(head->next);
    }
    
    Node* flatten(Node* head) {
        helper(head);
        return head;
    }
};