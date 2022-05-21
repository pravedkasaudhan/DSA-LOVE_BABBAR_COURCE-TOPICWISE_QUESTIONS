class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    
		    map<char,int> count;
		    string ans="";
		    queue<char> q;

            // iterate through each character
		    for(int i=0;i<A.length();i++){
		        char ch=A[i];

                // increase the frequency of characater
		        count[ch]++;
                //push the character in queue
		        q.push(ch);
                // pop the lement till we have repeating element
		        while(!q.empty()){
		            if(count[q.front()]>1){
		                q.pop();
		            }
                    //on getting non repeating one store it in ans and break the while loop as there is no need to remove it from queue
		            else{
		                ans.push_back(q.front());
		                break;
		            }
		        }
                // when on queue becomes empty on removing the repeating element or no NR element found then queue wil be empty so we add # in answer
		        if(q.empty()){
		        ans.push_back('#');
		    }
		    }
		    
		    return ans;
		}

};
