#include<bits/stdc++.h>
using namespace std;

void Sort0s1s2s( vector<int> &vec){
    int zero=0, one=0, two= vec.size()-1;
    while(one<=two){
        switch(vec[one]){
            case 0:
                swap(vec[zero], vec[one]);
                zero++,one++;
                break;
            case 1:
                one++;
                break;
            case 2:
                swap(vec[one], vec[two]);
                two--;
                break;
            default:
                cout<<"Wrong input";
                return;
        }
    }
}

int main()
{
    vector<int> vec ={ 2,0,1,0,2,2,0,1,1};
    Sort0s1s2s(vec);
    for (int i = 0; i < vec.size(); i++) {
            cout << vec[i] << " ";
        }
}