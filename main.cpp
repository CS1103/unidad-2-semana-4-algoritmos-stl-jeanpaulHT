#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <fstream>
#include <map>

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

void ej3(){
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
    vector <int> temp_order;
    for(int i = 0 ; i < container.size();i++) {
        temp_order = order;
        bubble_sotr_especial(&container[i], temp_order);
    }

    for(auto vec: container){
        for(auto item: vec){
            cout<<item<<endl;
        }
    }

}

void ej4(){
    int n;
    int row;
    int col;
    string str;
    vector<string> vec;
    cin>>n;
    getchar();
    cin>>col;
    cin>>row;

    for(int i = 0; i<row + 1;i++){
        getline(cin,str);
        vec.push_back(str);
    }
    for(int i = 0; i< row; i++){
        for(int j = i + 1 ; j < row; j++){
            if(vec[i].compare(vec[j]) > 0 && j < row){
                if(vec[j].compare(vec[j + 1]) == 0)
                    std::swap(vec[j], vec[j + 1]);
                std::swap(vec[i],vec[j]);
            }
        }
    }

    for(auto item:vec)
        cout<<item<<endl;
}

template <typename t>
t sum_vector(vector<t> vec){
    t temp = {};
    for(auto item :vec){
        temp += item;
    }
    return temp;
}

void ej5(){
    int days;
    bool bandera  = true;
    stringstream ss;
    string str;
    int num;
    vector<vector<int>*> urn;
    cin>>days;
    getchar();
    while(days--){
        getline(cin,str);
        if(str == "0"){
            bandera = false;
            days++;
        }
        ss<<str;
        if(bandera){
            urn.push_back(new vector<int>);
            while(ss >> num){
                urn.back()->push_back(num);
            }
            urn.back()->erase(urn.back()->begin());
        }
        ss.clear();
    }


    int max = 0;
    int min = sum_vector(*urn[0]);
    int sum = 0;

    for(auto item: urn){
        sum = sum_vector(*item);
        if(max < sum){
            max = sum;
        }
        if(min > sum){
            min = sum;
        }
    }
    cout<< max - min;
}

float cost(map <char, int>mapa){
    char c;
    float costo = {};
    fstream in("../ej6.txt");
    while(in>>c){
        if(mapa.count(c) > 0){
            costo += mapa[c];
        }
    }
    return costo/100;
}

void ej6(){

    int test;
    int keys;
    int num;
    char c;
    float total_cost = {};
    map<char, int> map;

    cin>>test;
    while(test--){
        cin>>keys;
        while(keys--){
            cin>>c;
            cin>>num;
            map[c] = num;
        }
        getchar();
        total_cost += cost(map);
    }
    cout<<total_cost;
}

int main() {
    return 0;
}