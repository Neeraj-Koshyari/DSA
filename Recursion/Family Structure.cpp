// Problem Link : https://www.naukri.com/code360/problems/family-structure_981243

string find(long long int k){
	if(k == 1)	return "Male";

	string s = find((k+1)/2);

	if(s == "Male"){
		if(k&1)	return "Male";
		else return "Female";
	}
	else{
		if(k&1)	return "Female";
		else return "Male";
	}
}

string kthChildNthGeneration(int n, long long int k)
{
	// Write your code here	
	return find(k);
}
