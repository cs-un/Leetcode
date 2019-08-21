/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode MergeTwoLists(ListNode l1, ListNode l2) {
        if (l1 == null)
        {
            return l2;
        }
        else if (l2 == null)
        {
            return l1;
        }
        
        ListNode node;
        if(l1.val < l2.val)
        {
            node = l1;
            node.next = MergeTwoLists(l1.next, l2);
        }
        else
        {
            node = l2;
            node.next = MergeTwoLists(l1, l2.next);
        }
        
        return node;
    }
}
