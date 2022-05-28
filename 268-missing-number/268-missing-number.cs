public class Solution {
    public int MissingNumber(int[] nums) {
      int sum = 0;
      foreach(var num in nums) {
          sum += num;
      }
      int n = nums.Length;
      int target = n * (n + 1) / 2;
      return target - sum;
    }
}