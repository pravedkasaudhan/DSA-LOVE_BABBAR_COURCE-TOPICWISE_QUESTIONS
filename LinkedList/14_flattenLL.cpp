 Node* merge(Node* head1,Node* head2){
	if(head1==NULL){
		return head2;
	}
	if(head2==NULL){
		return head1;
	}
	Node* ans=new Node(-1);
	Node* temp=ans;
	while(head1!=NULL && head2!=NULL){
		if(head1->data<head2->data){
			temp->bottom=head1;
			temp=temp->bottom;
			head1=head1->bottom;
			
		}
		else{
			temp->bottom=head2;
			temp=temp->bottom;
			head2=head2->bottom;
			
		}
	}
	if(head1!=NULL){
		temp->bottom=head1;		
	}
	else{
		temp->bottom=head2;
	}
	
	return ans->bottom;
}
Node *flatten(Node *head)
{
   // Your code here
   if(head==NULL || head->next==NULL){
	return head;
}
//get the next head by recursion call for right side merged coloumns
	head->next=flatten(head->next);
    // send the current and right side merged data to merge and make a single coloumn
	head=merge(head,head->next);
    //return the finally merged data till current head call
	return head;
}