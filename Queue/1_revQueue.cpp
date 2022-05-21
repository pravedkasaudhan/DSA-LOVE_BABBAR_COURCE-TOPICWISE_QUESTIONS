queue<int> rev(queue<int> q)
{
    // add code here.
    stack<int> s;

    //push the lement in stack
    while(!q.empty()){
        int val=q.front();
        q.pop();
        s.push(val);
    }

    // now take the element from stack in reverse porder and push in queue
    while(!s.empty()){
        int val=s.top();
        s.pop();
        q.push(val);
    }
    return q;
}