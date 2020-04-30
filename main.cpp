#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;

void funct(string temp){
    string str = temp;
    sort(str.begin(),str.end());
    bool bandera = true;

    do{
        if(str == temp){
            if(next_permutation(str.begin(),str.end())){
                cout<<str;
                bandera = false;
                break;
            }
            else
                break;
        }
    }while(next_permutation(str.begin(),str.end()));
    if(bandera)
        cout<<"no succesor";
}

void ejercico1(){
    string str;
    vector <string> words;
    while (std::cin >> str){
        if (str == "#") break;
        words.push_back(str);
    }

    //abaacb
    //cbbaa
    for(auto item: words){
        funct(item);
        cout<<endl;
    }
}

void swap(int *a,int*b){
    auto temp = a;
    a = b;
    b = temp;
}
template <typename T>
int bubble_sotr(vector<T> vec){
    int n = {};
    for(int i = 0 ; i < vec.size();i++){
        for(int j = i + 1; j < vec.size() ;j++){
            if(vec[i]>vec[j]){
                swap(vec[i],vec[j]);
                n++;
            }
        }
    }

    return n;
}

void ej2(){
    int n;
    char str;
    vector<char> v;

    cin>>n;
    while(n--){
        cin>>str;
        v.push_back(str);
    }
    cout<<bubble_sotr(v);
}

int main() {
   int n;
    string s;
    cin>> n ;

    while(n--){
        getchar();
        int int_arry[100], n = 1;
        float f[100];
        getline(cin,s);
        stringstream ss;
        ss << s;
        while(ss >> int_arry[n])n++;
        getline(cin,s);
        ss.clear();
        ss << s;
        n = 1;
        while(ss >> f[int_arry[n]])n++;
        for(int i= 1; i < n; i++)
            cout <<f[i] << endl;
    }


    return 0;
}