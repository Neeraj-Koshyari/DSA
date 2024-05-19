//Algorith to find prime number till n

//insted of 2*i we use i*i because till i index they are already marked as non prime;

vector<int> sieve(int n){
	vector<int> v(n+1,1),prime;
	v[0] = v[1] = 0;

	for(int i=2;i<=n;i++){
		if(v[i]){
			prime.push_back(i);
			for(int j = i*i; j<=n; j+=i)	v[j] = 0;
		}
	}
	return prime;
}
