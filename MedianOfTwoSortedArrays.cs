public class Solution {
	public double FindMedianSortedArrays(int[] nums1, int[] nums2) {
      int length = nums1.Length + nums2.Length;
      int medIndex = (nums1.Length + nums2.Length)/2;
      int prev = 0, last = 0;
      for(int i = 0, j = 0; i+j != medIndex + 1;)
      {
         prev = last;
         if(j == nums2.Length || i < nums1.Length && nums1[i] < nums2[j])
         {
            last = nums1[i];
            ++i;
         }
         else
         {
            last = nums2[j];
            ++j;
         }
      }

      return length %2 == 0 ? (double)(prev+last)/2 : last;
	}
}