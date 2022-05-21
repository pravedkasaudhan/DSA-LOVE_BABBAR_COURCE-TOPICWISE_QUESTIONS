LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
	LinkedListNode<int>* temp=head; 
	
	LinkedListNode<int>* curr=head; 
	LinkedListNode<int>* prev=NULL; 
	LinkedListNode<int>* forward;
	while(curr!=NULL){
		forward=curr->next;
		curr->next=prev;
		prev=curr;
		curr=forward;
	}
	head=prev;
	return head;
    // Write your code here
}