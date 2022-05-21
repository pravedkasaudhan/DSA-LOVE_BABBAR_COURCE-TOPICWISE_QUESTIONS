class Solution {
public:
    vector<int> nextSmallestSection(vector<int>& arr,int n){
        vector<int> ans(n);
	
        stack<int> s;
        s.push(-1);
        for(int i=n-1;i>=0;i--){
            int ele=arr[i];
             while(s.top()!=-1 && arr[s.top()]>=ele){
                 s.pop();
             }
            ans[i]=s.top();
            
            s.push(i);
        }
        return ans;
    }
     vector<int> prevSmallestSection(vector<int>& arr,int n){
              vector<int> ans(n);
	
        stack<int> s;
        s.push(-1);
        for(int i=0;i<n;i++){
            int ele=arr[i];
             while(s.top()!=-1 && arr[s.top()]>=ele){
                 s.pop();
             }
           ans[i]=s.top();
            s.push(i);
        }
             return ans;
     }
         
    int largestRectangleArea(vector<int>& heights) {
        int maxRect=INT_MIN;
        int size=heights.size();
        stack<int> s;
        vector<int> next(size);
        vector<int> prev(size);
        //get the array for index of next smallest element on right side
        next=nextSmallestSection(heights,size);
     
        //get the array for index of prev smallest element on left side
        prev=prevSmallestSection(heights,size);
        
        for(int i=0;i<heights.size();i++){
            //this condition if for array [-1,-1,-1] i.e all are at same level thus it expand its the size of array
            if(next[i]==-1){
                next[i]=size;
            }
            //get the ma width a specific height block can expand its head
            int width=next[i]-prev[i]-1;

            //finding the area by max width it can expand with its height
            int area=width*heights[i];

            maxRect=max(maxRect,area);
            
        }
        return maxRect;
    }
};