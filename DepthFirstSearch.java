/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author vk185107
 */
public class DepthFirstSearch {
    
    public boolean[] marked;
    private int count;
    
    public DepthFirstSearch(Graph G, int s){
        marked = new boolean[G.V()];
        dfs(G, s);
    }
    
    public void dfs(Graph G, int v){
        marked[v] = true;
        count++;
        for(int w: G.adj(v)){
            if(!marked[v]){
                dfs(G,w);
            }
        }
    }
    
    public boolean marked(int v){ return marked[v]; }
    
    public int count(){ return count; }
    
}
