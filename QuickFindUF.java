/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author vk185107
 */
public class QuickFindUF {
    
    private int[] id;
    private int count;
    
    public QuickFindUF(int N){
        count = N;
        id = new int[N];
        
        for(int i =0; i<N; i++){
            id[i] = i;
        }
    }
    
    public int count(){
        return count;
    }
    
    public int find(int p){
        return id[p];
    }
    
    public void union(int p, int q){
        if(!connected(p,q)){
            int c = id[p];
            int N = id.length;
            
            for(int i = 0; i<N; i++){
                if(id[i] == c){
                    id[i] = id[q];
                    count --;
                }
            }
        }
    }
    
    public boolean connected(int p, int q){
        return find(p) == find(q);
    }
    
    public static void main(String[] args){
        int N= StdIn.readInt();
        
        QuickFindUF uf = new QuickFindUF(N);
        
        while(!StdIn.isEmpty()){
            
            int p = StdIn.readInt();
            int q = StdIn.readInt();
            
            if(!uf.connected(p,q)){
                uf.union(p, q);
                
                StdOut.println(p + " " + q);
            }
        }
        
        StdOut.println(uf.count() + "Components");
    }
}
