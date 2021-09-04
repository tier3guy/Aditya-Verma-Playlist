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

vector<int> first_negative_integers(vector<int> arr, int k){
	int size__of__arr = arr.size();
	queue<int> listt;

	vector<int> ans;

	int i=0, j=0;
	while(j < k){

		if(arr[j] < 0) listt.emplace(arr[j]);
		j++;
	}
	if(listt.empty()) ans.push_back(0);
	else ans.push_back(listt.front()); 

	i++;
	while(j < size__of__arr){

		if(arr[j] < 0) listt.emplace(arr[j]);
		if(arr[i-1] == listt.front()) listt.pop();
		
		if(listt.empty()) ans.push_back(0);
		else ans.push_back(listt.front()); 

		i++; j++;
	}

	return ans;
}

int count__anagrams(string str, string sub__string){

	vector<int> alphabets(27,0);
	vector<int> helper(27,0);

	for(int i=0;i<sub__string.size();i++) alphabets[int(sub__string[i] - 'a' + 1)] += 1;

	int counter_to_anagrams = 0;

	int window__size = sub__string.size();
	int i=0, j=0;

	while(j < window__size){
		helper[int(str[j] - 'a' + 1)] += 1;
		j++;
	}

	if(alphabets == helper) counter_to_anagrams++;
	i++;
	while(j < str.size()){
		helper[int(str[i-1] - 'a' + 1)] -= 1;
		helper[int(str[j] - 'a' + 1)] += 1;

		if(alphabets == helper) counter_to_anagrams++;
		i++; j++;
	}

	return counter_to_anagrams;
}

vector<int> maximum_of__all__sub_array(vector<int> arr, int k){

	vector<int> ans;
	queue<int> q;

	int i=0;
	int j=0;

	while(j < k){
		if(q.empty()) q.emplace(arr[j]);
		else{
			if(q.front() > arr[j]) q.emplace(arr[j]);
			else{
				while(!q.empty()) q.pop();
				q.emplace(arr[j]);
			}
		}
		j++;
	}
	if(!q.empty()) ans.push_back(q.front());
	i++;

	while(j < arr.size()){
			if(arr[i-1] == q.front()) q.pop();
			
			if(q.front() > arr[j]) q.emplace(arr[j]);
			else{
				while(!q.empty()) q.pop();
				q.emplace(arr[j]);
			}

		if(!q.empty()) ans.push_back(q.front());
		i++;j++;
	}

	return ans;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> array = {2,3,5,9,5,4,6,5}; 
    int k = 3;

    vector<int> ans = maximum_of__all__sub_array(array,k);
    for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
    cout << endl;

    return 0;
}