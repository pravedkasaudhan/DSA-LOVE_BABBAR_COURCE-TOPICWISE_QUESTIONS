#include<vector>
class Solution {
public:

    void solve(string digit,string output,int index,vector<string> &ans,string mapping[]){
	//base case when the index reaches the last digit for digit so that it get possible combination and we put it in answer array
        if(index>=digit.length()){
            ans.push_back(output);
            return ;
        }
		// for getting the digit in integer format from string
        int currentIndex=digit[index]-'0';
		
		// map the integer with its corresponding array of characters
        string str=mapping[currentIndex];
		
		// iterate each character of string for correspinding possible combination
        for(int i=0;i<str.length();i++){
		// push the corresponding alphabet and do recursive call for next index to get furthur combination
            output.push_back(str[i]);
            solve(digit,output,index+1,ans,mapping);
			// remove the current alphabet befor going for next iteration
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()==0){
            return ans;
        }
		// to maintain the answer for each call depth for each answer
        string output="";
		
		// to maintain the depth of the recursive call as per the no of digits
        int index=0;
		
		//for doing mapping of each digit to its corresponding array of characters
        string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,output,index,ans,mapping);
        return ans;
    }
};