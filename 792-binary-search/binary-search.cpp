class Solution {
public:
    int search(vector<int>& nums, int target) {
        int below = 0;
        int above = nums.size()-1;

        while(below <= above){
            int middle = below + (above - below)/2;
            if(nums[middle]==target)
              return middle;
            else if(nums[middle] < target)
               below = middle + 1;
            else
               above = middle - 1;
        }
        return -1;
    }
};