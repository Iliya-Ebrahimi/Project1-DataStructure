#include<bits/stdc++.h>
using namespace std;

bool isOperator (const string& s) {
    return (s == "+" || s == "-" || s == "*" || s == "/" || s == "^" || s == "√");
}


// throw an error if the number under a sqrt is negatave !( does not work if the answer under it is negative --> √5-6 )!
void NegativeSqrt(string s) {
    for (int i = 0; i < s.size() - 1;i++){
        if (s[i] == '√' and s[i + 1] == '-'){
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

TreeNode* parser_add_sub (const vector<string>& tokens, int& index);
TreeNode* parser_mult_div (const vector<string>& tokens, int& index);
TreeNode* parser_power (const vector<string>& tokens, int& index);
TreeNode* parser_radical (const vector<string>& tokens, int& index);
TreeNode* parser_max_min (const vector<string>& tokens, int& index);
TreeNode* parser_sin_cos_tan_cot (const vector<string>& tokens, int& index);
TreeNode* var_OR_bracket (const vector<string>& tokens, int& index);
TreeNode* build_tree (const vector<string>& tokens, int& index);



TreeNode* parser_add_sub (const vector<string>& tokens, int& index) {
    // parser add Or sub and numbers of tokens
    TreeNode* left = parser_mult_div(tokens, index);
    if (index < tokens.size() && (tokens[index] == "+" || tokens[index] == "-")) {
        string opt = tokens[index];
        index++;
        TreeNode* right = parser_add_sub(tokens, index);
        TreeNode* node = new TreeNode(opt);
        node -> left = left;
        node -> right = right;
        return node;
    }
    return left;
}

TreeNode* parser_mult_div (const vector<string>& tokens, int& index) {
    // parser mult Or div and numbers of tokens
    TreeNode* left = parser_power(tokens, index);
    if (index < tokens.size() && (tokens[index] == "*" || tokens[index] == "/")) {
        string opt = tokens[index];
        index++;
        TreeNode* right = parser_mult_div(tokens, index);
        TreeNode* node = new TreeNode(opt);
        node -> left = left;
        node -> right = right;
        return node;
    }
    return left;

}

TreeNode* parser_power (const vector<string>& tokens, int& index) { 
    // parser power and numbers of tokens
    TreeNode* left = parser_radical(tokens, index);
    if (index < tokens.size() && tokens[index] == "^") {
        index++;
        TreeNode* right = parser_power(tokens, index);
        TreeNode* node = new TreeNode("^");
        node -> left = left;
        node -> right = right;
        return node;
    }
    return left;
}

TreeNode* parser_radical (const vector<string>& tokens, int& index) {
    // parser radikal and number of tokens
    if (index < tokens.size() && tokens[index] == "√") {
        index++;
        TreeNode* left = parser_radical(tokens, index); // example: √√5
        TreeNode* node = new TreeNode("√");
        node -> left = left;
        return node;
    }
    return var_OR_bracket(tokens, index);
}

TreeNode* parser_max_min (const vector<string>& tokens, int& index) {
    // two child
}

TreeNode* parser_sin_cos_tan_cot (const vector<string>& tokens, int& index) {
    // one child
}

TreeNode* var_OR_bracket (const vector<string>& tokens, int& index) {
    string tok = tokens[index];
    if (isdigit(tok[0]) || isalpha(tok[0])) {
        index++;
        return new TreeNode(tok);
    }
    else if (tok == "(") {
        index++;
        TreeNode* node = parser_add_sub(tokens, index);
        if (index >= tokens.size() || tokens[index] != ")") {
            throw runtime_error("Missing closing parenthesis");
        }
        index++;
        return node;
    }
    else if (tok == "+" || tok == "-") {
        index++;
        auto operand = var_OR_bracket(tokens, index);
        if (tok == "-") {
            auto node = new TreeNode("-");
            node->left = new TreeNode("0");
            node->right = operand;
            return node;
        } 
        else {
            return operand;
        }
    }

    throw runtime_error("Unexpected token in primary: " + tok);
}

TreeNode* build_tree (const vector<string>& tokens, int& index) {
    index = 0;
    TreeNode* root = parser_add_sub(tokens, index);
    //must start with the lowest operation to recursively calculate the expression and make the tree
    //expression = parser_add_sub
    if (index != tokens.size()) {
        throw runtime_error("Unexpected token after parsing expression");
    }
    return root;
}

