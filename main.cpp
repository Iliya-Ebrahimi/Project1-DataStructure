#include<bits/stdc++.h>
#include "helper.h"
using namespace std;

void printTree(TreeNode* root, int depth = 0) {
    if (!root) return;

    // اول راست را چاپ کن تا بالاتر دیده شود
    printTree(root->right, depth + 1);

    // فاصله‌ها بر اساس عمق درخت
    for (int i = 0; i < depth; i++) cout << "    ";

    // چاپ مقدار نود
    cout << root->value << "\n";

    // چپ
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
    TreeNode* root = parser_add_sub(tokens, idx);
    printTree(root);
    delete root;
}
