// Problem Link: https://www.geeksforgeeks.org/problems/insert-interval-1666733333/1


//Noob code from Line 5.     Less Calculation code start from line 58
class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals,
                                       vector<int> &newInterval) {
        // code here
        vector<vector<int>> ans;
        int n = intervals.size();
        int start = intervals[0][0];
        int end = intervals[0][1];
        
        if(newInterval[1] < start)  ans.push_back(newInterval);
        else if(newInterval[0] <= start){
            start = min(start, newInterval[0]);
            end = max(end, newInterval[1]);
        }
        
        for(int i=0;i<n;i++){
            if(end < intervals[i][0]){
                ans.push_back({start,end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
            else end = max(end, intervals[i][1]);
            
            if(newInterval[0] >= start && newInterval[0] <= end)    end = max(end, newInterval[1]);
            else if(i+1 < n && newInterval[0] > intervals[i][1] && newInterval[0] < intervals[i+1][0]){
                ans.push_back({start,end});
                
                if(newInterval[1] < intervals[i+1][0]){  
                    ans.push_back(newInterval);
                    start = intervals[i+1][0];
                    end = intervals[i+1][1];
                }
                else{
                    start = newInterval[0];
                    end = max(newInterval[1],intervals[i+1][1]);
                }
            }
        }
        
        if(end < newInterval[0]){
            ans.push_back({start,end});
            start = newInterval[0];
            end = newInterval[1];
        }
        ans.push_back({start,end});
        
        return ans;
    }
};


// Less calculation Code
class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals,
                                       vector<int> &newInterval) {
        // code here
        int n = intervals.size(),i=0;
        
        vector<vector<int>> ans;
        
        while(i<n && newInterval[0] > intervals[i][1]){
            ans.push_back(intervals[i]);
            i++;
        }
        
        while(i<n && newInterval[1] >= intervals[i][0]){
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        
        ans.push_back(newInterval);
        
        while(i<n){
            ans.push_back(intervals[i]);
            i++;
        }
        
        return ans;
    }
};
