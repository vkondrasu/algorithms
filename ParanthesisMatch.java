class Solution {
    public boolean isOpenExpression(char c){
        return c=='('|| c=='{' || c=='[';
        
    }
    
    public boolean isTopMatched(char c, Stack<Character> sc){
        return (!sc.empty()) && ( (c==')' && sc.peek()=='(') || (c==']' && sc.peek()=='[') || (c=='}' && sc.peek()=='{') );
    }
    public boolean isValid(String s) {
        
        char ca[] = s.toCharArray();
        
        Stack<Character> opStack = new Stack<Character>();
        
        for(char c: ca){
            if(isOpenExpression(c)){
                opStack.push(c);
                continue;
            }

            if(isTopMatched(c, opStack)){
                opStack.pop();
            }else{
                return false;
            }
            
        }
        
        if(opStack.empty())
            return true;
        
        return false;
        
    }
}
