import java.nio.charset.StandardCharsets;
import java.util.HashMap;
import java.util.Map;

/**
 * Created by ENG.AHMED HANI on 8/23/2015.
 */

public class MajorityElement1 {
    public static int majorityElement(int[] nums) {
        if (nums.length == 1) return nums[0];
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        int target = (int)nums.length / (int)2;
        boolean found = false;
        int element;

        for (int i = 0; i < nums.length; i++) {
            if (map.containsKey(nums[i])) {
                int counter = map.get(nums[i]);
                map.put(nums[i], ++counter);
            }
            else {
                map.put(nums[i], 1);
            }
        }

        for (Map.Entry<Integer, Integer> item : map.entrySet()) {
            if (item.getValue() > target) {
                return item.getKey();
            }
        }

        return 0;
    }

}
