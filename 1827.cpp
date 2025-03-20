public class Solution {
    public int minOperations(int[] nums) {
        int operations = 0;

        // Iterate through the array starting from the second element
        for (int i = 1; i < nums.length; i++) {
            // If current element is not greater than the previous element
            if (nums[i] <= nums[i - 1]) {
                // We need to perform an operation to make nums[i] greater than nums[i-1]
                operations += nums[i - 1] - nums[i] + 1;
                // Update nums[i] to the new value which is nums[i-1] + 1
                nums[i] = nums[i - 1] + 1;
            }
        }
        
        return operations;
    }
}

Output
Input
nums =
[1,1,1]
Output
3
Expected
3
