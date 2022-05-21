#include<stack>
// Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k) {
    // add code here.
    
    stack<int> s;
    //push first k element in stack
    for(int i=0;i<k;i++){
        int val=q.front();
        q.pop();
        s.push(val);
    }

    //pop from stack and add in back of queue in reverse order
    while(!s.empty()){
        int val=s.top();
        s.pop();
        q.push(val);
    }

    //take the left out element from front and place in back of queue
    int leftOut=q.size()-k;
    while(leftOut--){
        int val=q.front();
        q.pop();
        q.push(val);
    }
    
    return q;
}