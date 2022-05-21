include<stack>
bool findRedundantBrackets(string &s)
{
    // Write your code here.
	stack<char> st;
		char ch;
		for(int i=0;i<s.length();i++){
			ch=s[i];
            // if its any opening bracket or any operator then we push in stack
			if(ch=='(' || ch=='+' || ch=='*' || ch=='/' || ch=='-'){
				st.push(ch);
			}
			else{
                // when we get closing bracket in iteration
				if(ch==')'){
                    // we keep a flag variable for tracking any rudandant,we assume that there is redundant bracket
					bool isRedundant=true;
                    // we iterate till we reach the opening bracket for this closing one
					while(st.top()!='('){
						char top=st.top();
                        // if we get any operator then we make our assumption false
						if(top=='+' || top=='-' || top== '/' || top=='*'){
							isRedundant=false;
						}
						st.pop();
					}
                    // if our assumption was right then we return false;
					if(isRedundant==true){
						return true;
					}
                    //else we pop out the opening bracket also for the closing one after removing operators between them
					st.pop();
				}
			}
		}
	return false;
}
