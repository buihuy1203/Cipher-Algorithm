#include <iostream>
#include <string>
using namespace std;

string EnCrypt(string msg, int a, int b){
    string result  = "";
    for(char c : msg){
        if(!(c == ' '))
        result = result + (char)(((a*(int)(c-'A')+b)%26)+'A');
        else
        result += c;
    }
    return result;
}

int main(){
    int a = 15,b = 24;
    string text = "HOM NAY TOI DI HOC";
    cout << "A and B value is: "<< a <<" "<<b << endl;
    cout <<"Message: "<<text<<endl;
    cout <<"Cipher Text: "<<EnCrypt(text, a, b);
}