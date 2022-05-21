#include <vector>
#include <stack>
class Solution
{

public:
    vector<int> nextSmallestEle(int heights[MAX], int m)
    {
        vector<int> ans(m);
        stack<int> s;
        s.push(-1);
        for (int i = m - 1; i >= 0; i--)
        {
            int ele = heights[i];
            while (s.top() != -1 && heights[s.top()] >= ele)
            {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    vector<int> prevSmallestEle(int heights[MAX], int m)
    {
        vector<int> ans(m);
        stack<int> s;
        s.push(-1);
        for (int i = 0; i < m; i++)
        {
            int ele = heights[i];
            while (s.top() != -1 && heights[s.top()] >= ele)
            {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    int largestRect(int heights[MAX], int m)
    {

        int width, maxArea = 0;
        vector<int> next(m);
        vector<int> prev(m);
        next = nextSmallestEle(heights, m);
        prev = prevSmallestEle(heights, m);

        for (int i = 0; i < m; i++)
        {
            if (next[i] == -1)
            {
                next[i] = m;
            }
            width = next[i] - prev[i] - 1;
            int area = width * heights[i];
            maxArea = max(area, maxArea);
        }
        return maxArea;
    }
    int maxArea(int M[MAX][MAX], int n, int m)
    {
        // set the initial area as the largest rect area fpr 1st row
        int area = largestRect(M[0], m);

        // now we keep on updting the each row and find the max area we can get from that row and then compare it with previous row area to get out the max of al thw rows
        
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (M[i][j] == 0)
                {
                    M[i][j] = 0;
                }
                else
                {
                    M[i][j] += M[i - 1][j];
                }
            }
            area = max(area, largestRect(M[i], m));
        }
        return area;
    }
};
