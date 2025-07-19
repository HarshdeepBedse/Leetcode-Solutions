class Solution {
public:
    bool binarysearch(vector<int>&nums,int start,int end,int target){
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]==target){
                return true;
            }
            else if(nums[mid]<target){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
            
        }
        return false;
    }
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int count =0;
        for(int i=0;i<nums.size();i++){
            if(i==0 && binarysearch(nums,i+1,nums.size()-1,nums[i]+k)){
                count ++;
            }
            else if(binarysearch(nums,i+1,nums.size()-1,nums[i]+k)&& nums[i]!=nums[i-1]){
                    count++;

            }
        }

        return count;
    }
};