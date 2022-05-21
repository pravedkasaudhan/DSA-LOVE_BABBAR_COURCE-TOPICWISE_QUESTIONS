bool isCircular(Node* head){
    // Write your code here.
	if(head==NULL){
		return true;
	}
	Node* temp=head->next;
	while(temp!=NULL && temp!=head){
		temp=temp->next;
	}
	if(temp==head){
		return true;
	}
	
	return false;
}