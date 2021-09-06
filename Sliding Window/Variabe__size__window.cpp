#include <bits/stdc++.h>
using namespace std;
using ll = long long;

		#define loop(i,n) for(int i=0;i<(n);++i)
		#define dloop(i,a,n) for(int i=a;i>=(n);--i)

int maximum__subarray__of_sum_k(vector<int> arr, int k){

	int i=0, j=0, sum = 0;

	int maximum__length = INT_MIN;
	while(j < arr.size()){
		sum += arr[j];
		if(sum == k) maximum__length = max(maximum__length,(j-i+1)); 			
		else if(sum > k){
			while(sum > k){
				++i;
				sum -= arr[i-1];
			}
		} 
		j++;
	}

	return maximum__length;
}

int longest__substring_with_k__unique_characters(string str,int k){

	map<char,int> alphabets;

	int i=0, j=0, maximum__length = INT_MIN;

	while(j < str.size()){
		auto iterator = alphabets.find(str[j]);
		if(iterator == alphabets.end()) alphabets.insert({str[j],1});
		else iterator->second = iterator->second + 1;


		if(alphabets.size() == k) maximum__length = max(maximum__length,(j-i+1));		 			
		else if(alphabets.size() > k){
			while(alphabets.size() > k){
				--alphabets[str[i]];
				if(alphabets[str[i]] == 0) alphabets.erase(str[i]);
				i++;
			}
		} 
		j++;
	}

	return maximum__length;
}

int longest__substring_with__all_unique_characters(string str){
	map<char,int> alphabets;

	int i=0, j=0, maximum__length = INT_MIN;

	while(j < str.size()){
		auto iterator = alphabets.find(str[j]);
		if(iterator == alphabets.end()) alphabets.insert({str[j],1});
		else{
			++i;
			cout << (j-i+1) << " ";
			maximum__length = max(maximum__length,(j-i+1));
		} 
		j++;
	}

	return maximum__length;
}

int maximum__toys(string str){
	map<char,int> alphabets;

	int i=0, j=0, maximum__length = INT_MIN;

	while(j < str.size()){
		auto iterator = alphabets.find(str[j]);
		if(iterator == alphabets.end()) alphabets.insert({str[j],1});
		else iterator->second = iterator->second + 1;

		if(alphabets.size() == 2){
			cout << (j-i+1) << " ";
			maximum__length = max(maximum__length,(j-i+1));
		}
		else if(alphabets.size() > 2){
			while(alphabets.size() > 2){
				--alphabets[str[i]];
				if(alphabets[str[i]] == 0) alphabets.erase(str[i]);
				i++;
			}
		} 
		j++;
	}

	return maximum__length;
}

/*--------Most Important---------*/
int minimum__window__substring(string str, string to__find){
	map<char,int> letters;
	for(int k=0;k<to__find.size();k++){
		auto iterator = letters.find(to__find[k]);
		if(iterator == letters.end()) letters.insert({to__find[k],1});
		else{
			letters[to__find[k]]++;
		}
	}

	int count = letters.size();
	int i=0, j=0;
	int min__length = INT_MAX;

	while(j < str.size()){
		auto iterator = letters.find(to__find[j]);
		if(iterator != letters.end()){
			letters[to__find[j]]--;
			if(letters[to__find[j]] == 0) count--;
		}

		while(count == 0){
			min__length = min(min__length,(j-i+1));
			auto iterator__second = letters.find(to__find[i]);
			if(iterator__second == letters.end()) i++;
			else{
				if(iterator__second->second <= 0){
					i++;
					iterator__second->second = iterator__second->second + 1;
				}
				else if(iterator__second->second > 0){
					count++;
				}
			}
		}

		j++;
	}

	return min__length;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

   /* vector<int> arr = {4,1,0,0,1,2,6};
    cout << maximum__subarray__of_sum_k(arr,5) << endl;*/

    string str = "totmtaptat";
    string tsr = "tat";
    cout << endl << minimum__window__substring(str,tsr);

    return 0;
}