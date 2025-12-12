#include<bits/stdc++.h>
#include "helper.h"
using namespace std;

void printTree(TreeNode* root, int depth = 0) {
    if (!root) return;

    printTree(root->right, depth + 1);

    for (int i = 0; i < depth; i++) cout << "    ";

    cout << root->value << "\n";

    printTree(root->left, depth + 1);
}



int main(){
    string user_input;
    string vars;    
    getline(cin, vars);
    getline(cin, user_input);
    // cout << "variable manager: " << VariableManager(user_input, vars) << endl;
    user_input = normalizer(normalizer(VariableManager(user_input, vars)));
    vector<string>tokens = tokenize(user_input);
    cout << endl << "Expression: ";
    for (int i = 0; i < tokens.size(); i++) cout << tokens[i] << " ";
    cout << endl << endl;;
    int idx = 0;
    TreeNode* root = build_tree(tokens, idx);
    printTree(root);

    double ans = calculate_tree(root);
    cout << endl << "Answer: " << ans << endl;
    delete root;
}
