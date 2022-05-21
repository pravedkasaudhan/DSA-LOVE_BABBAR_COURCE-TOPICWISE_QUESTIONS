void addInLL(Node* &tail,Node* addNode){
	tail->next=addNode;
	tail=addNode;
}
Node* sortList(Node *head)
{
    // Write your code here.
	Node* zerohead=new Node(-1);
	Node* zerotail=zerohead;
	Node* onehead=new Node(-1);
	Node* onetail=onehead;
	Node* twohead=new Node(-1);
	Node* twotail=twohead;
	
	Node*temp=head;
	while(temp!=NULL){
		if(temp->data==0){
			addInLL(zerotail,temp);
		}
		else if(temp->data==1){
			addInLL(onetail,temp);
		}
		else if(temp->data==2){
			addInLL(twotail,temp);
		}
		temp=temp->next;
	}
	
	if(onehead->next==NULL){
		zerotail->next=twohead->next;
	}
	else{
		zerotail->next=onehead->next;
		onetail->next=twohead->next;
	}
	twotail->next=NULL;
	head=zerohead->next;

}
