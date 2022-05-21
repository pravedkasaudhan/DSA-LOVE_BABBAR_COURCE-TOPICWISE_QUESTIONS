#include<stack>
int findMinimumCost(string str) {

  //check the invalid condition when no of character are odd ,then its sure invalid to reverse the braket to make it valid paranthesis
	if(str.length()%2!=0){
		return -1;
	}

    //remove the valid pair of brackets leaving back unvalid pair left
	stack<int> st;
	for(int i=0;i<str.length();i++){
		char ch=str[i];
		if(ch=='{'){
			st.push(ch);
		}
		else{
			if(!st.empty() && st.top()=='{'){
				st.pop();
			}
			else{
				st.push(ch);
			}
		}
	}
    // count the no of opening and cosing bracket and with help of formula get the no of steps required
	int a=0,b=0;
	while(!st.empty()){
		if(st.top()=='{'){
			a++;
		}
		else if(st.top()=='}'){
			b++;
		}
		st.pop();
	}
	int res=(a+1)/2+(b+1)/2;
	return res;
}