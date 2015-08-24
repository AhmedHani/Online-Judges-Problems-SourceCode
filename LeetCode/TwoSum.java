
/**
 * Created by ENG.AHMED HANI on 8/23/2015.
 */
public class TwoSum {
    public static int[] twoSum(int[] nums, int target) {
        int sum = 0;
        int[] res = new int[2];

        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[i] + nums[j] == target) {
                    res[0] = i + 1;
                    res[1] = j + 1;
                    break;
                }
            }
        }

        return res;
    }
}
