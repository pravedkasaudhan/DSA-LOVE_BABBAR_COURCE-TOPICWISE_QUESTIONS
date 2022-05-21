class Solution
{   public:

      struct Node* reverse(struct Node* head){
            struct Node* prev=NULL;
            struct Node* curr=head;
            struct Node* next=curr->next;
            while(curr!=NULL){
                next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
            }
            return prev;
        }
        public:
        struct Node* addToAns(struct Node* &head,struct Node* &tail,int d){
            struct Node* newNode=new Node(d);
            if(head==NULL){
                head=newNode;
                tail=newNode;
                return head;
            }
            else{
                tail->next=newNode;
                tail=newNode;
            
            }
            
        }
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        struct Node* firstNew=reverse(first);
        struct Node* secondNew=reverse(second);
        
        struct Node* resHead=NULL;
        struct Node* resTail=NULL;
        
        int digit ,carry=0,val1,val2,sum;
        while(firstNew!=NULL || secondNew!=NULL ||carry!=0){
            val1=0;
            sum=0;
            if(firstNew){
               val1=firstNew->data; 
            }
              val2=0;
            if(secondNew){
               val2=secondNew->data; 
            }
            sum=val1+val2+carry;
            digit=sum%10;
            carry=sum/10;
            addToAns(resHead,resTail,digit);
            
            if(firstNew){
                firstNew=firstNew->next;
            }
             if(secondNew){
                secondNew=secondNew->next;
            }
        }
        return reverse(resHead);
    }
};