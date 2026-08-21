class Solution {
public:
    int dfs(vector<string>& tokens){
        string tk=tokens.back();
        tokens.pop_back();
        if(tk != "+" && tk != "-" && tk != "*" && tk != "/"){
            return stoi(tk);
        }
        int r=dfs(tokens);
        int l=dfs(tokens);
        if(tk=="+")return l+r;
        else if(tk=="-")return l-r;
        else if(tk=="*")return l*r;
        else return l/r;
    }
    int evalRPN(vector<string>& tokens) {
       return dfs(tokens); 
    }
};
