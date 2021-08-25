#include <bits/stdc++.h>
using namespace std;
using ll = long long;

		#define loop(i,n) for(int i=0;i<(n);++i)
		#define dloop(i,a,n) for(int i=a;i>=(n);--i)

vector<int> nsl(int arr[],int n){
	stack<pair<int,int>> s;
	vector<int> ans;

	int i=0;
	while(i<n){
		if(s.empty()){
			ans.push_back(-1);
			s.push(make_pair(arr[i],i));
			i++;
		}else{
			pair<int,int> temp = s.top();
 			if(temp.first < arr[i]){
 				ans.push_back(temp.second);
 				s.push(make_pair(arr[i],i));
 				i++;
 			}else{
 				s.pop();
 			}
		}
	}

	return ans;
}

vector<int> nsr(int arr[],int n){
	
	stack<pair<int,int>> s;
	vector<int> ans;

	int i=n-1;
	while(i >= 0){
		if(s.empty()){
			ans.push_back(n);
			s.push(make_pair(arr[i],i));
			i--;
		}else{
			pair<int,int> temp = s.top();
 			if(temp.first < arr[i]){
 				ans.push_back(temp.second);
 				s.push(make_pair(arr[i],i));
 				i--;
 			}else{
 				s.pop();
 			}
		}
	}

	reverse(ans.begin(), ans.end());
	return ans;
}

int maxArea(int arr[],int n){
	vector<int> left = nsl(arr,n);
	vector<int> right = nsr(arr,n);

	int max_area = 0;
	for(int i=0;i<n;i++) max_area = max(max_area,(arr[i]*(right[i]-left[i]-1)));

	return max_area;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int arr[] = {2,3,3,2};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << maxArea(arr,n) << endl;

    return 0;
}