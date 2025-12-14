#include<bits/stdc++.h>
#include "normalizer.cpp"
#include "tokenizer.cpp"
#include "CalculateTree.cpp"
#include "variable_manager.cpp"
#include <fstream>
#include <string>
using namespace std;


// ----------------------------Graphviz-----------------------------------
string create_name_node(int& counter) { return "node_" + to_string(counter++); }

void make_node_in_dot_file(TreeNode* node, ofstream& myfile, int& counter, string name_papa = "") {
    if (!node) return; // not papa :)

    string name_node = create_name_node(counter);
    myfile << " " << name_node << "[label=\"" << node -> value << "\"];\n";
    
    if (name_papa != "") { myfile << " " << name_papa << " -> " << name_node << ";\n"; }
    if (node->left) { make_node_in_dot_file(node->left, myfile, counter, name_node); }
    if (node->right) { make_node_in_dot_file(node->right, myfile, counter, name_node); }
}

void make_dot_file(TreeNode* root, string name_myfile = "myTree.dot") {
    ofstream myfile(name_myfile);
    int counter = 0;

    myfile << "digraph ExpressionTree {\n  node [shape=circle, fontsize=14];\n";
    make_node_in_dot_file(root, myfile, counter); myfile << "}\n";
    myfile.close();
}

// ------------------------------------------Main-------------------------------------------

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

    make_dot_file(root); // command: dot -Tpng myTree.dot -o tree.png
    double ans = calculate_tree(root);
    cout << endl << "Answer: " << ans << endl;
    delete root;
}
