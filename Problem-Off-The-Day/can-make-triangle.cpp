/**
 *    author:   abhijayrajvansh
 *    created:  04.03.2022 06:48:24
**/
#include <bits/stdc++.h>
using namespace std;

vector<int> canMakeTriangle(vector<int> arr, int n){
    int limit = n - 2;
    vector<int> ans;

    for(int i = 2; i < n; i++){
        if(arr[i-2] + arr[i] > arr[i - 1]){
            ans.push_back(1);
        }
        else{
            ans.push_back(0);
        }
    }
    return ans;

}

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N = 4;
    vector<int> arr = {1, 2, 2, 4};
    vector<int> ans =  canMakeTriangle(arr, N);
    for(auto & i : ans){
        cout << i << " ";
    }
    return 0;
}