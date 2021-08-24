#include<iostream>
#include<vector>
using namespace std;

int fpoint(vector<int>& S, int& a, int left, int right){
	if (left <= right){
		int mid = (left + right)/2;
		if (S[mid]+a < mid+1) return fpoint(S, a, mid+1, right);
		else if (S[mid]+a > mid+1) return fpoint (S, a, left, mid-1); 
		else {
			int point = fpoint(S, a, left, mid-1);
			if (point == -1) return mid+1;
			else return point;
		}
	}
	return -1;
}


int main(){
	int n, x, m, counter=1;
	while (cin>>n){
		vector<int> S(n);
		for (int i = 0; i<n; ++i) cin>>S[i];
		
		cin>>m;
		cout << "Sequence #" << counter << endl;
		for (int i = 0; i<m; ++i) {
			cin>>x;
			int ret = fpoint(S, x, 0, n-1);
			if (ret!=-1) cout << "fixed point for " << x << ": " << ret << endl;
			else cout << "no fixed point for " << x << endl;
		}
		cout << endl;
		++counter;
	}

}
