//YouTube: https://www.youtube.com/watch?v=-dUiRtJ8ot0

// T.C. for building segment and for single query is log (n)
// T.C. for q queries is  q * log(n) where ' q ' is number of queries and ' n ' is size of array.


// Code for finding Sum in given Segment

void build(int idx,int l, int r,vector<int>& v, vector<int>& seg){
	if(l == r){
		seg[idx] = v[l];
		return;
	}

	int mid = (l+r)/2;
	build(2*idx+1, l, mid, v, seg);
	build(2*idx+2, mid+1, r, v, seg);

	seg[idx] = seg[2*idx+1] + seg[2*idx+2];
}

int query(vector<int>& v, int idx, int l, int r, int qL, int qR, vector<int>& seg){

	if(l >= qL && r <= qR)	return seg[idx];	//if current segment completly lies in finding segment

	if(r<qL || qR<l)	return 0;		// if current segment dosent lies

	// partial overlapping, Then check in left and right
	int mid = (l+r)/2;
	int left = query(v,2*idx+1,l,mid,qL,qR,seg);
	int right = query(v,2*idx+2,mid+1,r,qL,qR,seg);

	return left + right;
}
//size of seg vector will be ' 4*n ' 
// First call build(0,0,n-1,v,seg)
// Then for each query call query(v,0,0,n-1,l,r,seg)), Where l and r are asked range. If they are 1 based index then subtract 1 to l and r both.



//Code for finding min element in given Segment

void build(int idx,int l, int r,vector<int>& v, vector<int>& seg){
	if(l == r){
		seg[idx] = v[l];
		return;
	}

	int mid = (l+r)/2;
	build(2*idx+1, l,mid, v, seg);
	build(2*idx+2, mid+1,r, v, seg);

	seg[idx] = min(seg[2*idx+1],seg[2*idx+2]);
}

int query(vector<int>& v, int idx, int l, int r, int qL, int qR, vector<int>& seg){

	if(l >= qL && r <= qR)	return seg[idx];	//if current segment completly lies in finding segment

	if(r<qL || qR<l)	return INT_MAX;		// if current segment dosent lies

	// Partial overlapping check in left and right
	int mid = (l+r)/2;
	int left = query(v,2*idx+1,l,mid,qL,qR,seg);
	int right = query(v,2*idx+2,mid+1,r,qL,qR,seg);

	return min(left,right);
}

//size of seg vector will be ' 4*n ' 
// First call build(0,0,n-1,v,seg)
// Then for each query call query(v,0,0,n-1,l,r,seg)), Where l and r are asked range. If they are 1 based index then subtract 1 to l and r both.
