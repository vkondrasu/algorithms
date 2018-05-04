/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author vk185107
 */

import java.util.*;

public class Graph {
    
    private final int V;
    private int E;
    
    
    
    private int[] vertices;
    private Bag<Integer>[] adj;
    
    public Graph(int V){
        this.V = V;
        this.E = 0;
        
        vertices = new int[V];
        adj = (Bag<Integer>[]) new Bag[V];        
        
        for(int i = 0; i<V; i++){
            adj[i] = new Bag<Integer>();
        }
    }
    
    public Graph(In in){
        this(in.readInt());
        int E = in.readInt();
        
        for(int i = 0; i <E; i++){
            int v = in.readInt();
            int w = in.readInt();
            
            addEdge(v,w);
        }
    }
    
    public int V(){  return V;   }
    
    public int E(){  return E;    }
    
    public void addEdge(int v, int w){
        adj[v].add(w);
        adj[w].add(v);
        
        E++;
    }
    
    public Iterable<Integer> adj(int V){
        return adj[V];
    }
    
    public static int degree(Graph G, int v){
        int degree = 0;
        for(int w: G.adj[v]){   degree++;    }        
        return degree;
    }
    
    public static int maxDegree(Graph G){
        int max_degree = 0;
        int degree;
        for(int v=0; v < G.V(); v++){
            degree = Graph.degree(G, v);
            
            if(degree>max_degree) max_degree = degree;
        }
        
        return max_degree;
    }
    
    public static int avgDegree(Graph G){
        /*int degreeSum = 0;
        
        for(int v = 0; v < G.V(); v++){
            degreeSum += Graph.degree(G, v);
        }
        
        return degreeSum/G.V();*/
        
        return 2 * G.E() / G.V();
    }
    
    public static int numberOfSelfLoops(Graph G){
        int loops = 0;
        
        for(int v=0; v < G.V(); v++){
            for(int w: G.adj(v)){
                if( v == w) loops++;
            }
        }
        
        return loops;
    }
    
    public String toString(){
        String s = V + " vertices " + E + " edges.\n";
        
        for(int i = 0; i < V; i++){
            s += i+": ";
            for(int w: this.adj[i]){
                s += w + " ";
            }
            
            s += "\n";
        }
        
        return s;
    }
    
}
