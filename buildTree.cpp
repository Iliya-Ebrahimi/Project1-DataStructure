#include<bits/stdc++.h>
using namespace std;

bool isOperator (const string& s) {
    return (s == "+" || s == "-" || s == "*" || s == "/" || s == "^" || s == "√");
}

// Prioritizing operators
int prioritizing_operators (const string& s) {
    if (s == "+" || s == "-") return 1;
    if (s == "*" || s == "/") return 2;
    if (s == "^") return 3;
    return 0;
}

// Right-effect operator detection
bool right_operator_effect (const string& s) {
    return (s == "^" || s == "√");
}

// throw an error if the number under a sqrt is negatave !( does not work if the answer under it is negative --> √5-6 )!
void NegativeSqrt(string s){
    for (int i = 0; i< s.size()-1;i++){
        if (s[i] == '√' and s[i+1] == '-'){
            throw runtime_error("No negative sqrts");
        }
    }
}

// Tree Nodes
struct TreeNode {
    string value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(const string& v) : value(v), left(nullptr), right(nullptr) {}
    ~TreeNode() {
        delete left;
        delete right;
    }
};


TreeNode* parser_add_sub (const vector<string>& tokens, int& index){
    // parser add Or sub and numbers of tokens
}

TreeNode* parser_mult_div (const vector<string>& tokens, int& index){
    // parser mult Or div and numbers of tokens
}

TreeNode* parser_power (const vector<string>& tokens, int& index){
    // parser power and numbers of tokens
}

TreeNode* parser_radical (const vector<string>& tokens, int& index){
    // parser radikal and number of tokens
    if (index < tokens.size() && tokens[index] == "√") {
        index++;
        TreeNode* right = parser_radical(tokens, index); // example: √√5
        TreeNode* node = new TreeNode("√");
        node -> right = right;
        return node;
    }
    return var_OR_bracket(tokens, index);
}

TreeNode* var_OR_bracket (const vector<string>& tokens, int& index) {
    string tok = tokens[index];
    if (isdigit(tok[0]) || isalpha(tok[0])) {
        index++;
        return new TreeNode(tok);
    }
    else if (tok == "(") {
        // ...
    }
    else {
        // for operators...
    }
}

TreeNode* build_tree (const vector<string>& tokens, int& index) {
    int index = 0;
    TreeNode* root = var_OR_bracket(tokens, index);
    if (index != tokens.size()) {
        throw runtime_error("Unexpected token after parsing expression");
    }
    return root;
}