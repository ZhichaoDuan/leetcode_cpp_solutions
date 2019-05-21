class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> stk;
        unordered_set<string> op;
        op.insert("+");
        op.insert("-");
        op.insert("*");
        op.insert("/");
        for (string s : tokens) {
            unordered_set<string>::const_iterator got = op.find(s);
            if (got != op.end()) {
                int num2 = stoi(stk.top());
                stk.pop();
                int num1 = stoi(stk.top());
                stk.pop();
                int res = process(s, num1, num2);
                stk.push(to_string(res));
            } else {
                stk.push(s);
            }
        }
        return stoi(stk.top());
    }
private:
    int process(string op, int lhs, int rhs) {
        if (op=="+") return lhs+rhs;
        else if(op=="-") return lhs-rhs;
        else if(op=="*") return lhs*rhs;
        else return lhs/rhs;
    }
};
