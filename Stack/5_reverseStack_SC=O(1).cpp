void pushAtBottom(stack<int>& myStack, int x) 
{
   
    //when stack in recursion call becomes empty then we add the element in stack at last
	if(myStack.empty()){
		myStack.push(x);
		return ;
	}
	int top=myStack.top();
	myStack.pop();
	pushAtBottom(myStack,x);
	myStack.push(top);
}
void reverseStack(stack<int> &stack) {
    
	if(stack.empty()){
		return;
	}
    //get the top element and then update the stack by removing top elemt for recursion call
	int top=stack.top();
	stack.pop();
	reverseStack(stack);

    // after recursion back add the top element at bottom of the stack
	pushAtBottom(stack,top);
}