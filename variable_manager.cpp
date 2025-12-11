#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

string VariableManager(string expr, string vars){
    vector<string> result;
    string temp = "";

    // ----------- Parse vars string into {"x","10","y","5",...} -----------
    for (int i = 0; i < vars.size(); i++) {
        if (vars[i] == ' ') continue;

        if (isalnum(vars[i])) {
            temp.clear();
            while (i < vars.size() && isalnum(vars[i])) {
                temp.push_back(vars[i]);
                i++;
            }
            result.push_back(temp);
            i--; 
        }
        else if (vars[i] == '=' || vars[i] == ',') {
            continue;
        }
    }

    // ----------- Build map: variable -> value -----------
    unordered_map<string,string> mp;

    for (int i = 0; i + 1 < result.size(); i += 2) {
        mp[result[i]] = result[i + 1];
    }

    // ----------- Replace variables in expr -----------
    string out = "";
    for (int i = 0; i < expr.size(); i++) {
        
        if (isalpha(expr[i])) {
            string var = "";
            while (i < expr.size() && isalnum(expr[i])) {
                var.push_back(expr[i]);
                i++;
            }
            i--; 

            if (mp.count(var)) out += mp[var];
            else out += var;                 
        }

        else {
            out.push_back(expr[i]); 
        }
    }

    return out;
}