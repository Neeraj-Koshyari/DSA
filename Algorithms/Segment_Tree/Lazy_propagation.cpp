/*  Video explanation (Striver): https://www.youtube.com/watch?v=rwXVCELcrqU&list=PLgUwDviBIf0rf5CQf_HFt35_cF04d8dHN&index=4
    Problem ling: https://codeforces.com/contest/52/problem/C

  Q: In one Operation:
    1. Increase the values of array in given range [l - r]
    2. Find sum or min or max in given range [l - r]
   
  
  Below is the code for finding min value in given range [l - r]
  Refer this code for finding sum or max value in given range.
  
  Size of seg vector and lazy vector will be '4*n' where 'n' is the size of v (given array)

  function call will be:
    build (current idx, start idx, last idx, arr,seg);
    
  If its query number is:
    1. update(current idx, start idx, last idx, query start idx, query last idx, query value, seg,laxy);
    2. query(current idx, start idx, last idx, query start idx, query last idx, seg,laxy);

  Initially for all the 'current idx' and 'start idx' will be 'zero' and 'last idx' will be 'n-1'

*/

void build(int idx, int l, int r, vector<long long>& v, vector<long long>& seg){
	if(l == r){
		seg[idx] = v[l];
		return ;
	}

	int mid = (l+r)/2;
	build(2*idx+1, l, mid, v, seg);
	build(2*idx+2, mid+1, r, v, seg);

	seg[idx] = min(seg[2*idx+1], seg[2*idx+2]);
}

// for some questions in line 40,99 the code will be 'seg[idx] += (r-l+1) * lazy[idx] ' which means line 51 will also change to (r-l+1)*val
// for above question-link  The code remain same

void update (int idx, int l, int r, int ql, int qr,int val, vector<long long>& seg, vector<long long>& lazy){
	if(lazy[idx] != 0){	//if their any remaining value which we have to add
		seg[idx] += lazy[idx];
		if(l!=r){		//if it is not a terminal node pass the lazy value to its children
			lazy[2*idx+1] += lazy[idx];		//left child
			lazy[2*idx+2] += lazy[idx];		//right child
		}
		lazy[idx] = 0;	//this value is computed
	}

	if(l>=ql && r<=qr){
		seg[idx] += val;
		if(l != r){
			lazy[2*idx+1] += val;
			lazy[2*idx+2] += val;
		}
		return;
	}
	if(r<ql || l>qr)	return;

	int mid = (l+r)/2;
	update(2*idx+1, l, mid, ql, qr, val, seg, lazy);
	update(2*idx+2, mid+1, r, ql, qr, val, seg, lazy);

	seg[idx] = min(seg[2*idx+1], seg[2*idx+2]);
}

int query(int idx, int l, int r, int ql, int qr, vector<long long>& seg, vector<long long>& lazy){
	if(lazy[idx] != 0){
		seg[idx] += lazy[idx];
		if(l!=r){
			lazy[2*idx+1] += lazy[idx];
			lazy[2*idx+2] += lazy[idx];
		}
		lazy[idx] = 0;
	}

	if(l>=ql && r<=qr)	return seg[idx];
	if(r<ql || l>qr)	return 1e9;

	int mid = (l+r)/2;
	long long left = query(2*idx+1, l, mid, ql, qr, seg, lazy);
	long long right = query(2*idx+2, mid+1, r, ql, qr, seg, lazy);

	return min(left,right);
}
