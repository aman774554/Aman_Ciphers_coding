#include<bits/stdc++.h>
using namespace std;
vector<string> keypad ={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void generatePossibleStringHelper(string &number, int index, string &resultSoFar, vector<string>& result){
    if(index>=number.size())
    {
        result.push_back(resultSoFar);
        return;
    }
    int digit = number[index]-'0';
    string possibleMoves = keypad[digit];
    for(int i=0;i<possibleMoves.size();i++){
        resultSoFar.push_back(possibleMoves[i]);
        generatePossibleStringHelper(number, index+1, resultSoFar , result);
        resultSoFar.pop_back();
    }
}

vector<string> generatePossibleString(string &number){
    vector<string> result;
    string resultSoFar ="";
    generatePossibleStringHelper(number, 0, resultSoFar, result);
    return result;
}

int main()
{
    string str="222";
    vector<string> vec;
    vec=generatePossibleString(str);
    //cout<<vec.size();
    for(int i=0;i<vec.size();i++)
    {
        cout<<vec[i]<<" ";
    }
    return 0;
}