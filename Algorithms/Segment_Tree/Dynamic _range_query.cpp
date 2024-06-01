/*
  Q: In one operation:
      1. update the value at position k to u
      2. Find sum or min or max in the given range [l - r]

  This update function works in log(4*n) where n is size of array
*/


// Sum update
void update(int idx, int l, int r, int k, int u,vector<ll>& seg){
	if(l == r){	
		seg[idx] = u;
		return;
	}

	int mid = (l+r)/2;
	if(k<=mid)	update(2*idx+1, l, mid, k, u, seg);
	else update(2*idx+2,mid+1, r, k, u, seg);

	seg[idx] = seg[2*idx + 1] + seg[2*idx + 2];
}

// Min update
void update(int idx, int l, int r, int k, int u,vector<ll>& seg){
	if(l == r){	
		seg[idx] = u;
		return;
	}

	int mid = (l+r)/2;
	if(k<=mid)	update(2*idx+1, l, mid, k, u, seg);
	else update(2*idx+2,mid+1, r, k, u, seg);

	seg[idx] = minseg([2*idx + 1], seg[2*idx + 2]);
}
