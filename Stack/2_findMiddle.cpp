void findMiddle(stack<int> &stack,int N,int c){
	if(c==N/2){
		stack.pop();
		return;
	}
	//get the top element before removing it and keeping aside to send the remaining stack for recursion call
	int num=stack.top();
	stack.pop();
	findMiddle(stack,N,c+1);
	
	//add the top element removed from stack after getting the stack from recursive call; 
	stack.push(num);
}

void deleteMiddle(stack<int>&inputStack, int N){
	
   // Write your code here
   int count=0;
	findMiddle(inputStack,N,count);
}