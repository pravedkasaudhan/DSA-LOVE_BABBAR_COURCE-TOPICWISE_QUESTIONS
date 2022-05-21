class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
     // your code goes here
     map<int,bool> visited;
	if(head==NULL){
		return NULL;
	}
	Node* prev=head;
	Node* curr=head->next;
	visited[prev->data]=true;
	while(curr!=NULL){
		if(visited[curr->data]==true){
			Node*temp=curr;
			curr=curr->next;
			prev->next=curr;
			temp->next=NULL;
			delete temp;
		}
		else{
			visited[curr->data]=true;
			prev=curr;
			curr=curr->next;
		}		
	}
	return head;
    }
};