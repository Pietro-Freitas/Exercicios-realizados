#include<bits/stdc++.h>
using namespace std;

int firstUniqChar(string s) {
    int v;
	bool ans = false;
    for(int i = 0; i < (int)s.size(); i++){
    	char a = s[i];
        if(count(s.begin(), s.end(), a) == 1){
            v = i;
            ans = true;
            break;
        }
    }
    if(ans == true) return v;
    else return -1;
}