#include<iostream>
#include<vector>
using namespace std;


// if you want to return ans in array

vector<string> subseq(string p, string up){  // p = processed string : initially empty,,,,,,, up = unprocessed string : string from which you want all subsets;
    if(up.empty()){
        vector<string> ans = {p};
        return ans;
    }
    char ch = up.front();
    
    vector<string>left = subseq(p+ch,up.substr(1));
    vector<string>right = subseq(p,up.substr(1));
    left.insert(left.end(),right.begin(),right.end());
    return left;
}

// if you only print all subsets of a string 

void subseq(string p, string up){
    if (up.empty()){
        cout<<p;
        return;
    }
    char ch = up.front();

    subseq(p+ch,up.substr(1));
    subseq(p,up.substr(1));
}

// subset using backtracking 

void subseq(int idx, string s,string temp){  //initially idx will be zero  , s = main string from which we have to find all subsets
    
    cout<<temp<<" ";
    for(int i = idx;i<s.size();i++){  
        temp.push_back(s[i]);
        subseq(i+1,s,temp);
        temp.pop_back();    
    }
}
