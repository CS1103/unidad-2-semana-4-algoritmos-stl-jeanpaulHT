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

template <typename t>
void swap(t* a,t* b){
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


void bubble_sotr_especial(vector<float> *vec, vector<int> order){
    for(int i = 0 ; i < order.size();i++){
        for(int j = i + 1; j < order.size() ;j++){
            if(order[i]>order[j]){
                swap(order[i],order[j]);
                swap(vec->at(i),vec->at(j));
            }
        }
    }

}
int main() {
    int n;
    string str;
    int num;
    stringstream ss;
    cin>> n ;
    vector<int> order;

    getchar();
    getchar();
    getline(cin,str);
    ss<<str;
    while(ss >> num){
        order.push_back(num);
    }


    vector<vector<float>> container;
    vector<float> temp;
    float num_2;
    while(n--){
        ss.clear();
        getline(cin,str);
        ss<<str;
        while(ss >> num_2){
            temp.push_back(num_2);
        }
        container.push_back(temp);
        temp.clear();

    }
    //bubble_sotr_especial(&container[0],order);
    for(int i = 0 ; i < container.size();i++)
        bubble_sotr_especial(&container[i],order);


    for(auto vec: container){
        for(auto item: vec){
            cout<<item<<endl;
        }
    }


    return 0;
}