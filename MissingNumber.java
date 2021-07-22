class Solution {
    public int missingNumber(int[] nums) {
        
        int sum = 0;
        
        for(int num : nums){
            sum += num;
        }
        
        int n = nums.length;
        
        int exp_sum = ((n+1)*n)/2;
        
        return exp_sum - sum;
        
    }
}
