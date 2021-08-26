#include <bits/stdc++.h>
using namespace std;
using ll = long long;


		#define db1(x) cout<<#x<<"="<<x<<'\n'
		#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
		#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
		#define rep(i,n) for(int i=0;i<(n);++i)
		#define loop(i,a,n) for(int i=a;i<=(n);++i)
		#define dloop(i,a,n) for(int i=a;i>=(n);--i)

vector<int> ngl(int arr[],int n){
	vector<int> left;
	left.push_back(arr[0]);

	for(int i= 1;i<n;i++){
		if(arr[i] >= left[i-1]) left.push_back(arr[i]);
		else left.push_back(left[i-1]);
	}

	return left;
}

vector<int> ngr(int arr[],int n){
	vector<int> right;
	right.push_back(arr[n-1]);

	int j=0;
	for(int i=n-2;i>= 0;i--){
		if(arr[i] >= right[j]) right.push_back(arr[i]);
		else right.push_back(right[i-1]);
		j++;
	}

	reverse(right.begin(), right.end());

	return right;
}

int rain_water(int arr[],int n){

	vector<int> left = ngl(arr,n);
	vector<int> right = ngr(arr,n);

	int water_init = 0;
	for(int i=0;i<n;i++){
		water_init += (min(left[i],right[i]) - arr[i]);
	}

	return water_init;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int arr[] = {3,0,0,2,0,4};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << rain_water(arr,n) << endl;
    return 0;
}