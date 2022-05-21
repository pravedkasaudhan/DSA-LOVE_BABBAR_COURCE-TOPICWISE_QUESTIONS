class Solution {
    public:
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
    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return NULL;
        }
        //create the copy node with next pointer
         Node* temp=head;
        
        Node* clonehead=NULL;
        Node* clonetail=NULL;
        while(temp!=NULL){
            addToTail(clonehead,clonetail,temp->val);
            temp=temp->next;
        }
                
        
        //inserting copy LL in original LL with corresponding nodes.
        Node* originalHead=head;
        Node* copyHead=clonehead;
        Node* next=NULL;
        while(originalHead!=NULL && copyHead!=NULL){
            //diverting the original LL node to copy LL node
            next=originalHead->next;
            originalHead->next=copyHead;
            originalHead=next;
            
            //diverting the copy LL to original LL
            next=copyHead->next;
            copyHead->next=originalHead;
            copyHead=next;
        }
        
        //add the respective random pointer to copy LL nodes.Here now original and copy LL came in originl LL as single LL
        temp=head;
        while(temp!=NULL){
            if(temp->next!=NULL){
                temp->next->random=temp->random?temp->random->next:temp->random;
            }
            temp=temp->next->next;
        }
        
        //removing nodes of copy LL from original LL after pointing thier random pointers to respective nodes.
         originalHead=head;
         copyHead=clonehead;
         
        while(originalHead!=NULL && copyHead!=NULL){
            //diverting the next of node of original LL from copy LL to original LL node
           originalHead->next=copyHead->next;
            originalHead=originalHead->next;
            
            //same is done for node of copy LL
            if(originalHead!=NULL){
             copyHead->next=originalHead->next;
            }
            copyHead=copyHead->next;
        }
       
        
        return clonehead;
    }
    
};