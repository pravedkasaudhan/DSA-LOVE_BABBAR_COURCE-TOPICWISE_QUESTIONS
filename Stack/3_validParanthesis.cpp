class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
	for(int i=0;i<s.length();i++){
		int ch=s[i];
        //check if its opening bracket then simple [push it]
		if(ch=='(' || ch=='{' ||ch=='['){
			st.push(ch);
		}
        //if the current character is closing bracket
		else{
            // if the stack is not empty then only we can get the top and compare it with current character
			if(!st.empty()){
				
				int lastChar=st.top();
                //if current and last one are corresponding then pop the last one (if pair found) else return as invalid string
				if((lastChar=='(' && ch==')')||
				   (lastChar=='{' && ch=='}')||
				   (lastChar=='[' && ch==']')){
					st.pop();
				}
				else{
					return false;
				}
			}
            //if we get the closing bracket and current stack is empty then straight its invalid without opening bracket how a closing bracket can occur.
			else{
				return false;
			}
		}
	}
    // it is there to check if all brackets are valid pair and removed; leaving stack empty
	if(st.empty()){
		return true;
	}
	else{
		return false;
	}
	
    }
};