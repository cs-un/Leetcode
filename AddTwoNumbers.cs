/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode AddTwoNumbers(ListNode l1, ListNode l2) {
        return AddTwoNumbers(l1, l2, 0);
    }
    
    
    private ListNode AddTwoNumbers(ListNode l1, ListNode l2, int overflow)
    {
        if(l1 == null && l2 == null && overflow == 0)
        {
            return null;
        }
        
        overflow += (l1?.val ?? 0) + (l2?.val ?? 0);
        
        var result = new ListNode(overflow % 10);
        result.next = AddTwoNumbers(l1?.next, l2?.next, overflow/10);
        return result;
    }
}
