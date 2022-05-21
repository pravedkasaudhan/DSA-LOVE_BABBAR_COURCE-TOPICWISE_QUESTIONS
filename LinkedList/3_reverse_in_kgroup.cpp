Node* kReverse(Node* head, int k) {
    // Write your code here.
	   if(head==NULL){
            return NULL;
        }
        Node* forward=NULL;
        Node* curr=head;
        Node* prev=NULL;
        int ct=0;
        while(curr!=NULL && ct<k){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
            ct++;
        }
        if(forward!=NULL){
            head->next=kReverse(forward,k); 
        }
        return prev;
}