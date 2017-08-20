//朴素的模式匹配算法
#include<iostream>
#include<string>
using namespace std;
/*返回子串T在主串S中第pos个字符之后的位置。若不纯在，则函数返回值0.*/
/*T非空，1<=pos<=strlength(s)*/
//假设主串S和要匹配的子串T的长度存在S[0]和T[0]。

int index(string  S, string  T, int pos){
    int i = pos; //i用于主串S中当前位置下标，若pos不为1
    int j = 0;   //j用于子串中当前位置下标
    while(i <S.size() && j <T.size()){//若i小于S长度且j小于T的长度时循环。
        if(S[i] == T[j]){//两字母相等则继续
            ++i;
            ++j;
        }
        else{
            i = i - j + 1; //i退回到上次匹配首位的下一位
            j = 0;
        }
	}
    if(j >= T.size())
        return i-T.size();//恰好是能匹配上时的第一个字符所在的位置。
    else
        return 0;
}

int main(){
    string str = "12b3google123";
    string substr = "google";
    int pos = index(str, substr,1);
    cout<<pos<<endl;
}

