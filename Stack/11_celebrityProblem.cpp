class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int> s;
        //keep all the peoples in stack
        for(int i=0;i<n;i++){
            s.push(i);
        }
        
        // iterate while stack has only 1 element left out 
        while(s.size()>1){
            //get two top elements
            int a=s.top();
            s.pop();
            int b=s.top();
            s.pop();

            // if a knows b then b must be a celebrity so push b again in stack
            if(M[a][b]==1){
                s.push(b);
            }
            //else a must be celebrity so push back a in stack
            else{
                s.push(a);
            }
        }

        // we get the possibel celberity
        int possibleCel=s.top();
        
        //now checks whether he knows anyone or not if he dows not know anyone then he may be
        int celKnowsOthers=0;
        for(int i=0;i<n;i++){
            if(M[possibleCel][i]==0){
                celKnowsOthers++;
            }
        }

    
        if(celKnowsOthers != n){
            return -1;
        }
        
        //check wheter all knows him ignore that h knows himself ,i.e. n-1 person must know him
        int othersKnowsCel=0;
        for(int i=0;i<n;i++){
            if(M[i][possibleCel]==1){
                othersKnowsCel++;
            }
        }
       
        if(othersKnowsCel!=n-1){
            return -1;
        }
        

        // he pass all the test and now he is celebrity.
        return possibleCel;
    }
};