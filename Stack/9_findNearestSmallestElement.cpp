#include<stack>;
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
	vector<int> ans(n);
	
	stack<int> s;
	s.push(-1);
    //iterate from back and keep on updating the lowest elment in stack and check for each element that whether stack contain any smallest element than it
	for(int i=n-1;i>=0;i--){
		int ele=arr[i];
        // pop until we find the smallest element 
		 while(s.top()>=ele){
			 s.pop();
		 }
        //  take the smallest element got and add it in answer array and push it in stack 
		ans[i]=s.top();
		s.push(ele);
	}
	return ans;
}