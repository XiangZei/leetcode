#include<bits/stdc++.h>
using namespace std;
int main(){
    double d = 1000.0;
    cout<<(d==1000)<<endl;
    
} 

int binarySearch(vector<int>& nums, int target) {
    if(nums.size() == 0) {
        return -1;
    }
    int left = 0, right = nums.size();
    while(left<right) {
        int mid = left+(right-left)/2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] < target) left = mid+1;
        else right = mid;
    }
    // left == right
    if(left != nums.size() && nums[left]== target) return left;
    return -1;
}