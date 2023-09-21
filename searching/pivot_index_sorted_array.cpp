
//algorithm to find pivot index in sorted array in O(log(n)) time complexity
//For example, [0,1,2,4,5,6,7] rotated at pivot index 3 and become [4,5,6,7,0,1,2].

int findPivot(vector<int>&nums){
        int s =0;
        int e = nums.size()-1;
        while(s<=e){
            int m = s+(e-s)/2;
            if(m<e && nums[m]>nums[m+1]){
                return m;
            }
            else if (m>s && nums[m]<nums[m-1]){
                return m-1;
            }
            else if(nums[m]<=nums[s]){
                e=m-1;
            }
            else{
                s=m+1;
            }
        }
        return -1 ;

    }


// or

 int findPivot(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;

        while (s < e){
            const int mid = (s + e) / 2;
            if ( nums[mid] > nums[e]) {
                s = mid + 1;
            } else {
                e = mid;
            }
        }
        return s;
 }