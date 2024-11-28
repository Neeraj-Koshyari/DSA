// Problem Link: https://www.geeksforgeeks.org/problems/implement-atoi/1


class Solution {
  public:
    int myAtoi(char *s) {
        // Your code here
        long long int ans = 0, MAX = INT_MAX, MIN = INT_MIN;
        int flag = 0, i = 0;
        
        while(s[i] != '\0' && s[i] == ' ')  i++;
        
        if(s[i] == '-'){ 
            flag = 1;
            i++;
        }
        else if(s[i] == '+'){    
            flag = 0;
            i++;
        }
        
        while(s[i] != '\0' && s[i] >= '0' && s[i] <= '9'){
            ans = ans*10 + (s[i] - '0');
            i++;
        }
        
        if(flag == 1){
            ans *= -1;
            ans = max(ans,MIN);
        }
        else    ans = min(ans, MAX);
        
        return ans;
    }
};
