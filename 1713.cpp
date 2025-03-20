public class Solution {
    public int minOperations(int[] target, int[] arr) {
       
        Map<Integer, Integer> targetIndexMap = new HashMap<>();
        for (int i = 0; i < target.length; i++) {
            targetIndexMap.put(target[i], i);
        }

       
        List<Integer> arrMapped = new ArrayList<>();
        for (int num : arr) {
            if (targetIndexMap.containsKey(num)) {
                arrMapped.add(targetIndexMap.get(num));
            }
        }

     
        return target.length - lengthOfLIS(arrMapped);
    }

    private int lengthOfLIS(List<Integer> arrMapped) {
        if (arrMapped.isEmpty()) return 0;

       
        List<Integer> lis = new ArrayList<>();
        for (int num : arrMapped) {
            int pos = binarySearch(lis, num);
            if (pos == lis.size()) {
                lis.add(num);
            } else {
                lis.set(pos, num);
            }
        }
        return lis.size();
    }

   
    private int binarySearch(List<Integer> lis, int target) {
        int left = 0, right = lis.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (lis.get(mid) < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
}


Output-
Input
target =
[5,1,3]
arr =
[9,4,2,3,4]
Output
2
