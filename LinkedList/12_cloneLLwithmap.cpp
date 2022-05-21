class Solution
{   public:
    void addToTail(Node* &head,Node* &tail,int data){
        Node* newNode=new Node(data);
        if(head==NULL){
            head=newNode;
            tail=newNode;
            return;
        }
        tail->next=newNode;
        tail=newNode;
    }
    public:
    Node *copyList(Node *head)
    {
        //Write your code here
        
        //create the copy node with next pointer
        Node* temp=head;
        
        Node* clonehead=NULL;
        Node* clonetail=NULL;
        while(temp!=NULL){
            addToTail(clonehead,clonetail,temp->data);
            temp=temp->next;
        }
        
        	// create the map for of corresponding node in original LL and copy LL
        unordered_map<Node*,Node*> mapping;
        
        Node* originalHead=head;
        Node* copyHead=clonehead;
        while(originalHead!=NULL){
            mapping[originalHead]=copyHead;
            originalHead=originalHead->next;
            copyHead=copyHead->next;
        }
        
        // add the corresponding node in random pointer of copy LL as per the node getting from map data.
        originalHead=head;
        copyHead=clonehead;
        while(copyHead!=NULL){
            copyHead->arb=mapping[originalHead->arb];
            copyHead=copyHead->next;
            originalHead=originalHead->next;
        }
        
        return clonehead;
    }

};