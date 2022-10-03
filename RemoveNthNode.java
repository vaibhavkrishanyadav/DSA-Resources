//This program deletes the nth node from the end of the linked list

class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if(head==null || head.next==null){
            return null;
            
        }
        int size=0;
        ListNode curr=head;
        while(curr!=null){
            curr=curr.next;
            size++;
            
        }
        if(n==size){
            return head.next;
        }
        int indextosearch=size-n;
        ListNode prev=head;
        int i=1;
        while(i<indextosearch){
            prev=prev.next;
            i++;
        }
        prev.next=prev.next.next;
        return head;
        
    }
}
