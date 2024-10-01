#include<bits/stdc++.h>
using namespace std;


void reverseString(string &s,int start,int end){
    if(start>end) return;
    //swap
    char temp = s[start];
    s[start] = s[end];
    s[end] = temp;
    start++;
    end--;
    reverseString(s,start,end);

}
int main(){
    string s = "aravind";
    reverseString(s,0,s.length()-1);
    cout<<"reversed string: "<<s;
    return 0;
}