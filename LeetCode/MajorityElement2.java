public class MajorityElement2 {
    public static List<Integer> majorityElement(int[] nums) {
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        List<Integer> res = new ArrayList<Integer>();
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
                res.add(item.getKey());
            }
        }

        return res;
    }
}
