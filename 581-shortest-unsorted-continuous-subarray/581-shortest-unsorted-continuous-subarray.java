class Solution {
    public int findUnsortedSubarray(int[] nums) {
        ArrayList<Pair<Integer,Integer>> arr = new ArrayList();
        
        for(int i = 0; i < nums.length; i++){
            arr.add(new Pair(nums[i], i));
        }
        Collections.sort(arr, (a, b) -> {
            return a.getKey().compareTo(b.getKey());
        });
        
        
        int i = 0, j = nums.length-1;
        while(i < nums.length-1){
            if(arr.get(i).getValue() > arr.get(i+1).getValue()){
                break;
            }
            i++;
        }
        if(i == nums.length-1) return 0;
        while(j > 1){
            if(arr.get(j).getValue() < arr.get(j-1).getValue()){
                break;
            }
            j--;
        }
        
        int min = nums.length, max = -1;
        
        while(i <= j){
            min = Math.min(arr.get(i).getValue(), min);
            max = Math.max(arr.get(i).getValue(), max);
            i++;
        }
        
        return max-min+1;
    }
}