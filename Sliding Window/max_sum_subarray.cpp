#include <bits/stdc++.h>
using namespace std;
using ll = long long;

		#define loop(i,n) for(int i=0;i<(n);++i)
		#define dloop(i,a,n) for(int i=a;i>=(n);--i)

int maxSum(int arr[],int k,int n){
	int size__of__arr = n;

	int i=1, j=0;
	int maxSum = 0;
	while(j != k){
		maxSum += arr[j]; j++;
	}
	int tracker = maxSum;
	while(i <= size__of__arr - k){
		tracker = tracker - arr[i-1] + arr[j];
		maxSum = max(tracker,maxSum);
		i++;
		j++;
	}

	return maxSum;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int arr[] = {2,9,4,3,6,2,24};
    int k = 3, n = 7;
    cout << maxSum(arr,k,n) << endl;

    return 0;
}