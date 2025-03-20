import java.util.Arrays;

public class Solution {
    public int maximumUnits(int[][] boxTypes, int truckSize) {
        // Sort the boxTypes array in descending order of units per box.
        Arrays.sort(boxTypes, (a, b) -> b[1] - a[1]);

        int totalUnits = 0;
        
        // Iterate through the sorted boxTypes array
        for (int[] box : boxTypes) {
            // Determine how many boxes we can load from the current type
            int boxesToLoad = Math.min(box[0], truckSize);
            
            // Add the corresponding number of units to the total
            totalUnits += boxesToLoad * box[1];
            
            // Decrease the truck size by the number of boxes loaded
            truckSize -= boxesToLoad;
            
            // If the truck is full, no need to load more boxes
            if (truckSize == 0) break;
        }
        
        return totalUnits;
    }
}

Output 
boxTypes =
[[1,3],[2,2],[3,1]]
truckSize =
4
