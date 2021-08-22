class TopKByFrequency {
    public int[] topKFrequent(int[] nums, int k) {
        HashMap<Integer,Integer> map = new HashMap<Integer,Integer>();
        //Construct frequency map
        for(int num : nums){
            if(map.containsKey(num)){
                map.replace(num, map.get(num)+1);
            }else{
                map.put(num,1);
            }
        }
        
        //Create min heap
        Queue<Integer> heap = new PriorityQueue<>( (n1,n2) -> map.get(n1) - map.get(n2) );
        
        
        for(Map.Entry<Integer,Integer> entry : map.entrySet()){
            //add elements to heap
            heap.add(entry.getKey());
            //if size is more than 'k' -> kick out smallest frequency
            if(heap.size() > k)
                heap.poll();
        }
        
        int[] top = new int[k];
        for(int i = k-1; i>=0; --i){
            top[i] = heap.poll();
        }
        
        return top;
    }
}
