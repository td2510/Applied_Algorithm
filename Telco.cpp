#include <bits/stdc++.h>
#include <string>
#include <string.h>
#include <map>  
#include <stdlib.h>
#include <iostream> 
using namespace std;

bool checkPhone(string s){
    if(s.length() != 10) return 0;
    for (int i=0; i<s.length(); i++){
        if (s[i] >= '0' && s[i] <= '9') return 1;
        else return 0;
    }
}
int countTime(string ftime, string etime){
    int startTime = 3600*((ftime[0]-'0')*10 + ftime[1]-'0') + 60*((ftime[3]-'0')*10 + ftime[4]-'0') + ((ftime[6]-'0')*10 + ftime[7]-'0');
    int endTime = 3600*((etime[0]-'0')*10 + etime[1]-'0') + 60*((etime[3]-'0')*10 + etime[4]-'0') + ((etime[6]-'0')*10 + etime[7]-'0');
    return (endTime - startTime);
}
int main(){
    std::map<string, int> numberCalls, timeCall;  
    int totalCall = 0;
    int incorrectPhone = 0;
    std::string type;
    do
    {
        cin >> type;
        if (type == "#") continue;
        ++totalCall;
        string fnum, tnum, date, ftime, etime;
        cin >> fnum >> tnum >> date >> ftime >> etime;
        if ( !checkPhone(fnum) || !checkPhone(tnum)) incorrectPhone++;
        numberCalls[fnum]++;
        timeCall[fnum] += countTime(ftime, etime);
    } while (type != "#");
    std::string text;
    do
    {
        cin >> text;
        if (text == "#") continue;
        // if (strncmp(text,"?check_phone_number",19)){
        //     if(incorrectPhone == 0) cout<<1<<endl;
        //     else cout<<incorrectPhone<<endl;
        // }
        // if (text.substr(0, 19)=="?check_phone_number"){
        //     if(incorrectPhone == 0) cout<<1<<endl;
        //     else cout<<incorrectPhone<<endl;
        // }
        string phone;
        cin >> phone;
        if (text=="?check_phone_number"){
            if(incorrectPhone == 0) cout<<1<<endl;
            else cout<<incorrectPhone<<endl;
        }
        // if (strncmp(text,"?number_total_calls",19)){
        //     cout<<totalCall<<endl;
        // }
        // if (text.substr(0, 19) =="?number_total_calls"){
        //     cout<<totalCall<<endl;
        // }
        if (text=="?number_total_calls"){
            cout<<totalCall<<endl;
        }
        // if (strncmp(text,"?number_calls_from",18)){
        //     cout<<numberCalls[text.substr(19, 10)]<<endl;
        // }
        if (text=="?number_calls_from"){
            cout<<numberCalls[phone]<<endl;
        }
        // if (strncmp(text,"?count_time_calls_from",22)){
        //     cout<<timeCall[text.substr(22, 10)]<<endl;
        // }
        if (text=="?count_time_calls_from"){
            cout<<timeCall[phone]<<endl;
        }
    } while (text != "#");
    
}