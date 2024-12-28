// Problem Link: https://leetcode.com/problems/sliding-window-median/description/

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        int n = nums.size();
        
        multiset<long long> left, right;

        auto balance = [&](){
            if(right.size() > left.size()){
                left.insert(*right.begin());
                right.erase(right.begin());
            }

            if(left.size() - 1 > right.size()){
                right.insert(*left.rbegin());
                left.erase(prev(left.end()));
            }
        };

        for(int i=0;i<n;i++){
            if(left.size() == 0 || nums[i] <= *left.rbegin())   left.insert(nums[i]);
            else right.insert(nums[i]);
            balance();

            if(i >= k){
                if(nums[i-k] <= *left.rbegin()) left.erase(left.find(nums[i-k]));
                else right.erase(right.find(nums[i-k]));
                balance();
            }

            if(i >= k-1){
                if(k&1) ans.push_back(*left.rbegin());
                else ans.push_back((*left.rbegin() + *right.begin()) / 2.0);
            }
        }
        return ans;
    }
};
