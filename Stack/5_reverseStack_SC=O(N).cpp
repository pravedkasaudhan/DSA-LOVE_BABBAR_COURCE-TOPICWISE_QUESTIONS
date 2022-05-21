class Solution{
public:
    void rev(stack<int> &s,vector<int> &ans){
        if(s.empty()){
            return;
        }
        int top=s.top();
        s.pop();
        ans.push_back(top);
        rev(s,ans);
    }
    vector<int> Reverse(stack<int> St){
    vector<int> ans;
    rev(St,ans);
    return ans;
    }
};