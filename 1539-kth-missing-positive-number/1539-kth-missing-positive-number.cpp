class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // no of missed element before each index is a[i]-(i+1)
        int start=0,end=arr.size()-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if((arr[mid]-(mid+1))<k){
                start=mid+1;
            }
            else {
                end=mid-1;
            }
        }
        return start+k;
    }
};