// Problem Link : https://www.naukri.com/code360/problems/letter-combinations-of-a-phone-number_983623

vector<string> dp = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void find(string& x, vector<string>& ans, string& s, int idx){
	if(idx == s.length()){
		ans.push_back(x);
		return;
	}

	string temp = dp[s[idx]-'2'];
	for(auto& ch : temp){
		x.push_back(ch);
		find(x,ans,s,idx+1);
		x.pop_back();
	}
}

vector<string> combinations(string s){
	
	// Write your code here
	vector<string> ans;
	string x = "";
	find(x,ans,s,0);
	return ans;
	
}
