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
    getline(cin, user_input);
    user_input = normalizer(user_input);
    vector<string>tokens = tokenize(user_input);
    cout << user_input << endl;
    for (int i = 0; i < tokens.size(); i++) cout << tokens[i] << " ";
    cout << endl;
    int idx = 0;
    TreeNode* root = build_tree(tokens, idx);
    printTree(root);

    double ans = calculate_tree(root);
    cout << ans << endl;
    delete root;
}
