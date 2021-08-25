#include <bits/stdc++.h>
using namespace std;
using ll = long long;

		#define loop(i,n) for(int i=0;i<(n);++i)
		#define dloop(i,a,n) for(int i=a;i>=(n);--i)

vector<int> previousSmaller(int arr[],int n){
	vector<int> ans;
	stack<pair<int,int>> s;

	int i=0;
	while(i<n){
		if(s.empty()){
			ans.push_back(-1);
			s.push(make_pair(arr[i],i));
			i++;
		}
		else{
			pair<int,int> temp = s.top();

			if(temp.first > arr[i]){
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

vector<int> stockSpan(int arr[],int n){
	vector<int> ans;
	stack<int> s;

	vector<int> ngl = previousSmaller(arr,n);

	for(int i=0;i<n;i++){
		if(ngl[i] == -1) ans.push_back(1);
		else ans.push_back(i - ngl[i]);
	}

	return ans;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int arr[] = {100,80,60,70,60,75,85};
    vector<int> v = stockSpan(arr,7);
    for(int i=0;i<v.size();i++) cout << v[i] << " ";

    return 0;
}