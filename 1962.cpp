import java.util.PriorityQueue;

public class Solution {
    public int minStoneSum(int[] piles, int k) {
    
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>((a, b) -> b - a);
        
    
        for (int pile : piles) {
            maxHeap.offer(pile);
        }
        
       
        for (int i = 0; i < k; i++) {
      
            int largestPile = maxHeap.poll();
            
          
            int reducedPile = largestPile - largestPile / 2;
            
           
            maxHeap.offer(reducedPile);
        }
        
    
        int totalStones = 0;
        while (!maxHeap.isEmpty()) {
            totalStones += maxHeap.poll();
        }
        
        return totalStones;
    }
}

Output-
Input
piles =
[5,4,9]
k =
2
Output
12
Expected
12
