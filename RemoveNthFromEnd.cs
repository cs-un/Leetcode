/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode RemoveNthFromEnd(ListNode head, int n) {
        int count = 0;
        var i = head;
        while(i != null)
        {
            ++count;
            i = i.next;
        }
        if(n == count)
        {
            return head.next;
        }
        i = head;
        for(int j = 0; j < count - n - 1; ++j)
        {
            i = i.next;
        }
        i.next = i.next.next;
        return head;
    }
}
