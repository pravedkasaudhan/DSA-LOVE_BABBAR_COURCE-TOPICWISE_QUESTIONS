Node *findMiddle(Node *head) {
    // Write your code here
	 Node* fast=head;
        Node* slow=head;
        while(fast->next!=NULL){
            fast=fast->next;
            if(fast->next!=NULL){
                fast=fast->next;
            }
            slow=slow->next;
        }
        return slow;
}