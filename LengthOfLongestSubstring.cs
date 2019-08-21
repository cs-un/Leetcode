public class Solution {
    public int LengthOfLongestSubstring(string s) {
        var chars = new Dictionary<char, int>();
        var max = 0;
        var start = 0;
        var end = 0;
        foreach(char c in s)
        {
            if(chars.ContainsKey(c))
            {
                start = chars[c] < start ? start : chars[c] + 1;
            }

            max = Math.Max(max, end - start + 1);
            chars[c] = end++;
        }
        return max;   
    }
}
