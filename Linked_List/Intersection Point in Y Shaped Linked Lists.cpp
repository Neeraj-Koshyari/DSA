// Problem Link: https://www.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1

/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

class Solution {
  public:
    // Function to find intersection point in Y shaped Linked Lists.
    int intersectPoint(Node* head1, Node* head2) {
        // Your Code Here
        int n = 0, m = 0;
        
        Node* temp = head1;
        while(temp){
            temp = temp->next;
            n++;
        }
        
        temp = head2;
        while(temp){
            temp = temp->next;
            m++;
        }
        
        if(m > n){
            swap(n,m);
            swap(head1,head2);
        }
        
        int extra = n-m;
        while(extra--)  head1 = head1->next;
        
        while(head1){
            if(head1 == head2)  return head1->data;
            
            head1 = head1->next;
            head2 = head2->next;
        }
        return -1;
    }
};
