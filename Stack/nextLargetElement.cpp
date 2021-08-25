#include <bits/stdc++.h>
using namespace std;
using ll = long long;

		#define loop(i,n) for(int i=0;i<(n);++i)
		#define dloop(i,a,n) for(int i=a;i>=(n);--i)

stack<int> s;
vector<int> ans;

vector<int> nextSmallerElement(int arr[],int n){
	int i = n-1;
	while(i >= 0){
		if(s.empty()){
			ans.push_back(-1);
			s.push(arr[i]);
			i--;
		}else{
			if(s.top() < arr[i]){
				ans.push_back(s.top());
				s.push(arr[i]);
				i--;
			}else{
				s.pop();
			}
		}
	}

	reverse(ans.begin(), ans.end());
	return ans;
}

vector<int> previousSmallerElement(int arr[], int n){

	int i =0;
	while(i <= n-1){
		if(s.empty()){
			ans.push_back(-1);
			s.push(arr[i]);
			i++;
		}else{
			if(s.top() < arr[i]){
				ans.push_back(s.top());
				s.push(arr[i]);
				i++;
			}else{
				s.pop();
			}
		}
	}

	return ans;
}

vector<int> previousLargestElement(int arr[], int n){

	int i =0;
	while(i <= n-1){
		if(s.empty()){
			ans.push_back(-1);
			s.push(arr[i]);
			i++;
		}else{
			if(s.top() > arr[i]){
				ans.push_back(s.top());
				s.push(arr[i]);
				i++;
			}else{
				s.pop();
			}
		}
	}

	return ans;
}

vector<int> nextLargestElement(int arr[],int n){

	int i =n-1;
	while(i>= 0){
		if(s.empty()){
			ans.push_back(-1);
			s.push(arr[i]);
			i--;
		}else{
			if(s.top() > arr[i]){
				ans.push_back(s.top());
				s.push(arr[i]);
				i--;
			}else{
				s.pop();
			}
		}
	}

	reverse(ans.begin(), ans.end());
	return ans;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int arr[] = {1,3,0,0,1,2,4};
    vector<int> v;
    v = previousSmallerElement(arr,7);
    loop(i,v.size()) cout << v[i] << " ";

    return 0;
}