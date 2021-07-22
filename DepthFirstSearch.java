
/**
 *
 * @author vkondrasu
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
