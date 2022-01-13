#include <iostream>
#include <vector>
#include <algorithm>
#include "make_random_vector.hpp"
#include <math.h>
using namespace std;

int fun(const int& a, const int& b)
{
    return a > b;
}

class A
{
public:
    int operator()(const int& a, const int& b) { return a > b; }
    int operator()(const int& a) { return a > aa; }

    int aa;
};

int fun1(const int& a)
{
    return a > 7;
}

class student
{
public:
    int idx;
};

int main()
{
    auto vec = make_random_vector< int >(10, 0, 10);
    //for (int i = 0; i < vec.size(); ++i)
        //cout << vec[i] << endl;
    cout << "[";
    for (auto& a : vec)
        cout << a << ", ";
    cout << "]" << endl;
    sort(vec.begin(), vec.end());
    cout << "[";
    for (auto& a : vec)
        cout << a << ", ";
    cout << "]" << endl;
    cout << count(vec.begin(), vec.end(), 4) << endl;
    sort(vec.begin(), vec.end(), A()); // albo fun zamiast A()
    cout << "[";
    for (auto& a : vec)
        cout << a << ", ";
    cout << "]" << endl;
    cout << "== == == == == == == =="  << endl;
    A b;
    cin >> b.aa;
    cout << count_if(vec.begin(), vec.end(), b) << endl; // instancja A z operatorem () zamiast fun1
    /*
    vector<int> w(10);
    for (int i = 0; i < 10; ++i)
        cin >> w[i];
    cout << "[";
    for (auto& a : w)
        cout << a << ", ";
    cout << "]" << endl;
    adjacent_find(w.begin(), w.end());
    */

    //labda
    // [ /* capture */ ] ( /* argumenty */ ) { /* cia³o */ }
    //auto lambda_sin = [](double x) { return sin(x); };
    //cout << lambda_sin(3.1415) << endl;

    int  f;
    cin >> f;
    //auto comp = [&](const int& e) { return e > f; }; // & oznacza ze przechwytuje wszystkie zmienne co jest powyzej czyli tez b , mozna wpisac po prostu b
    //cout << count_if(vec.begin(), vec.end(), comp) << endl;
    cout << count_if(vec.begin(), vec.end(), [f](const int& e) { return e > f; }) << endl;

    
    auto studenci= make_random_vector< int >(10, 100000, 999999);
    // for (int i = 0; i < vec.size(); ++i)
    // cout << vec[i] << endl;
    unique(studenci.begin(), studenci.end());
    sort(studenci.begin(), studenci.end());
    studenci.resize(unique(studenci.begin(), studenci.end()) - studenci.begin());
    vector< student > w2(studenci.size());
    for (int i = 0; i < w2.size(); ++i) {
        w2[i].idx = studenci[i];
        cout << w2[i].idx << endl;
    }
    for (auto& a : studenci)
        cout << a << ", ";
    cout << endl;
    cout << count_if(w2.begin(), w2.end(), [](student v) { return v.idx > 555555; }) << endl;
}