stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    // Write your code here.
    //when stack in recursion call becomes empty then we add the element in stack at last
	if(myStack.empty()){
		myStack.push(x);
		return myStack;
	}
	int top=myStack.top();
	myStack.pop();
	pushAtBottom(myStack,x);
	myStack.push(top);
	
	return myStack;
}
