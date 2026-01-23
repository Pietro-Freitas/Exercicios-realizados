#include<bits/stdc++.h>
using namespace std;

int maximumScore(int a, int b, int c) {
    int ans = 0, mi, ma;
    while(true){
        if((a == 0 && b == 0) || (a == 0 && c == 0) || (b == 0 && c == 0)) return ans;
        
        if((a == min(a, b) && a == min(a,c))) mi = a;
        else if((b == min(a, b) && b == min(b,c))) mi = b;
        else if((c == min(a, c) && c == min(b,c))) mi = c;
        
        if(a == max(a, b) && a == max(a, c)) ma = a;
        else if(b == max(a, b) && b == max(b, c)) ma = b;
        else ma = c;
        
        if(mi > 0){
            if(mi == a)mi = a;
            else if(mi == b)mi = b;
            else mi = c;
        }
        else{
            if(mi == a){
            if(b  == min(b, c))mi = b;
            else mi = c;
            }
            else if(mi == b){
                if(a  == min(a, c)){mi = a;}
                else{mi = c;}
            }
            else{
                if(a  == min(a, b)){mi = a;}
                else{mi = b;}
            }
        }
        if(mi == ma){
            if(a == b){a--;b--;}
            else if(a == c){a--;c--;}
            else if(c == b){b--;c--;}
        }else{
            if(mi == a && ma == b){a--; b--;}
            else if(mi == a && ma == c){a--; c--;}
            else if(mi == b && ma == a){a--; b--;}
            else if(mi == b && ma == c){b--; c--;}
            else if(mi == c && ma == a){a--; c--;}
            else if(mi == c && ma == b){b--; c--;}
        }

        ans++;
    }
}

/*
Solução mais elegante que percebi depois:

#include<bits/stdc++.h>
using namespace std;

int maximumScore(int a, int b, int c) {
    if(a > (b+c)) return b+c;
    if(b > (a+c)) return a+c;
    if(c > (a+b)) return a+b;

    return ((a+b+c) / 2);
}

*/