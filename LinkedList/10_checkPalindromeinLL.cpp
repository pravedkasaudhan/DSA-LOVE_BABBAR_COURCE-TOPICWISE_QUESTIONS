class Solution{
     public:
    
        Node* middle(Node* head){
        Node* slow=head;
        Node* fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    public:
    Node* reverse(Node* head){
            Node* prev=NULL;
            Node* curr=head;
            Node* next=curr->next;
            while(curr!=NULL){
                next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
            }
            return prev;
        }
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
         if(head->next==NULL){
            return true;
        }
        Node* mid=middle(head);
        
        Node* temp=mid->next;
        mid->next=reverse(temp);
        
        Node* first=head;
        Node* second=mid->next;
        while(second!=NULL){
            if(first->data!=second->data){
                return false;
            }
            first=first->next;
            second=second->next;
        }
        
        temp=mid->next;
        mid->next=reverse(temp);
        
        return true;
    }
};