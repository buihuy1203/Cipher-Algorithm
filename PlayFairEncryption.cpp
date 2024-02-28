#include <iostream>
#include <string>
using namespace std;
char playfair[5][5];
string removeduplicate(string keyword){
    string res = "";
    for (char c : keyword) {
        if (res.find(c) == std::string::npos) {
            res += c;
        }
    }
    return res;
}

string MakePlayFairString(string keyword){
    string makestring = keyword;
    string temp = keyword;
    for(char i = 'a'; i <= 'z'; i++){
        if(temp.find(i) == std::string::npos){
            makestring += i;
        }
    }
    makestring.erase(makestring.begin() + makestring.find('J'));
    return makestring;
}

void MakeAn5x5ArrayPlayFair(string temp){
    int j = 0;
    int k = 0;
    for(int i = 0; i < temp.size(); i++){
        playfair[j][k] = temp[i];
        k++;
        if(k == 5){
        j++;
        k=0;
        }
    }
}
void search(char a, char b, int arr[]){
    int i, j;
    if(a=='J')
    a = 'I';
    else if(b == 'J')
    b = 'I';
    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            if(playfair[i][j]==a){
                arr[0]= i;
                arr[1]= j;
            }else if(playfair[i][j]==b){
                arr[2]= i;
                arr[3]= j;
            }
        }
    }
}
string EnCrypt(string msg, string keyword){
    MakeAn5x5ArrayPlayFair(MakePlayFairString(removeduplicate(keyword)));
    string result = "";
    int a[4];
    for(int i = 0; i < msg.size(); i+=2){
            if(msg[i]==msg[i+1]){
                msg.insert(msg.begin()+i+1,'X');
                i = i-1;
            }
    }
    if(msg.size()%2 != 0){
        msg.push_back('Z');
    }
    for(int i = 0; i < msg.size(); i+=2){
        search(msg[i],msg[i+1], a);
            if(a[0]==a[2]){
                result = result + playfair[a[0]][(a[1]+1)%5];
                result = result + playfair[a[0]][(a[3]+1)%5];
            }
            else if(a[1]==a[3]){
                result = result +playfair[(a[0]+1)%5][a[1]];
                result = result +playfair[(a[2]+1)%5][a[1]];
            }else{
                result = result +playfair[a[0]][a[3]];
                result = result +playfair[a[2]][a[1]];
            }
    }
    return result;
}

int main(){
    string key = "sohoa";
    cout <<"Key text: "<<key<<endl;
    string text = "chaomungbandenvoikinguyenvotan";
    cout <<"Plain text: "<<text<<endl;
    cout <<"Cipher text: "<<EnCrypt(text, key);
    return 0;
}