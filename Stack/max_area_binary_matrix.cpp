#include <bits/stdc++.h>
using namespace std;
using ll = long long;

		#define loop(i,n) for(int i=0;i<(n);++i)
		#define dloop(i,a,n) for(int i=a;i>=(n);--i)

const int n=4;

vector<int> nsl(int mah_arr[]){
	vector<int> ans;
	stack<pair<int,int>> s;

	int i=0;
	while(i < n){
		if(s.empty()){
			ans.push_back(-1);
			s.push(make_pair(mah_arr[i],i));
			i++;
		}
		else{
			pair<int,int> temp = s.top();
			if(temp.first < mah_arr[i]){
				ans.push_back(temp.second);
				s.push(make_pair(mah_arr[i],i));
				i++;
			}else{
				s.pop();
			}
		}
	}

	return ans;
}

vector<int> nsr(int mah_arr[]){
	vector<int> ans;
	stack<pair<int,int>> s;

	int i= n-1;
	while(i >= 0){
		if(s.empty()){
			ans.push_back(n);
			s.push(make_pair(mah_arr[i],i));
			i--;
		}
		else{
			pair<int,int> temp = s.top();
			if(temp.first < mah_arr[i]){
				ans.push_back(temp.second);
				s.push(make_pair(mah_arr[i],i));
				i--;
			}else{
				s.pop();
			}
		}
	}
	reverse(ans.begin(), ans.end());

	return ans;
}

int mah(int mah_arr[]){
	vector<int> left = nsl(mah_arr);
	vector<int> right = nsr(mah_arr);

	int max_area = INT_MIN;
	loop(i,n) max_area = max(max_area,((right[i]-left[i]-1)*mah_arr[i]));

	return max_area;
}

int maxArea_binary_matrix(int arr[n][n]){
	int mah_arr[n];
	loop(i,n) mah_arr[i] = 0;

	int max_area = INT_MIN;

	loop(i,n){
		loop(j,n){
			if(arr[i][j] == 0) mah_arr[j] = 0;
			else mah_arr[j] += 1;
		}
		int i_area = mah(mah_arr);
		loop(i,n) cout << mah_arr[i] << " ";
		cout << " -> " << i_area << endl;

		max_area = max(i_area,max_area);
	}
	

	return max_area;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int arr[n][n];

    loop(i,n){
    	loop(j,n){
    		cin >> arr[i][j];
    	}
    }

    cout << maxArea_binary_matrix(arr) << endl;

    //int barry[] = {2,3,3,2};
    //cout << endl << mah(barry);

    return 0;
}