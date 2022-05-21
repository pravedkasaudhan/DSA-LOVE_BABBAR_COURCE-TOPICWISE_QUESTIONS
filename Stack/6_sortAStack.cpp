void insertInOrder(stack<int> &s,int d){
	// insert only when either stack is empty or when top is less than element to be entered
	if(s.empty() || (!s.empty() && s.top()<d)){
		s.push(d);
		return;
	}
	int top=s.top();
	s.pop();
	insertInOrder(s,d);
	s.push(top);
}
void sortStack(stack<int> &stack)
{
	// Write your code here
	if(stack.empty()){
		return;
	}
	int top=stack.top();
	stack.pop();
	//keep recursive call for new stack after remvoing top element
	sortStack(stack);
	//after recursive call insrt the element kept in current iteration in sorted order
	insertInOrder(stack,top);
}