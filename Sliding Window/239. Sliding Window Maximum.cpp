//Problem Link: https://leetcode.com/problems/sliding-window-maximum/
// Youtube: https://www.youtube.com/watch?v=pAvGyVfxHmk

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& v, int k) {
        int n = v.size();

        deque<int> dq;
        for(int i=0;i<k;i++){
            while(dq.size() && v[i] > v[dq.back()])   dq.pop_back();
            dq.push_back(i);
        }

        vector<int> ans;
        ans.push_back(v[dq.front()]);
        if(dq.front() == 0) dq.pop_front();

        for(int i=k;i<n;i++){
            while(dq.size() && v[i] > v[dq.back()])   dq.pop_back();
            dq.push_back(i);

            ans.push_back(v[dq.front()]);
            if(i-k+1 == dq.front())   dq.pop_front();
        }

        return ans;
    }
};
