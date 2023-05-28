#include<iostream>
#include<vector>
#include<string>
#include<numeric>
#include<string>
#include<functional>
#include<cassert> 
#include<iterator>
using namespace std;
string text, key;
//int key[] = {4,6,1,5,3,7,2};
void exit(){
    cout <<"Usage: " << endl;
    return;
}
int main(int argc, char const *argv[])
{
    cout << "===Welcome to Vertical cipher tool====" << endl;
    //cout << "===Welcome to Vertical cipher tool====" << endl;
    //text = string(argv[1]);
    string input_key = "4615372"; 
    //add spaces
    assert(input_key.size() > 1);
    std::string key = std::accumulate(std::next(input_key.begin()), input_key.end(), std::string(1,input_key[0]), [](std::string a, char b) -> std::string {return a+ " " + b;});
    std::cout << key << endl;
    //string to int[]
    vector<int> v;
    auto ptr = key.c_str();
    char *endptr = nullptr;
    while (ptr != key.c_str() + key.size()) {
        auto value = strtol(ptr, &endptr, 10);
        if (ptr == endptr) {
            ptr++;
        } else {
            ptr = endptr;
            v.push_back(value);
        }
    }
    copy(begin(v), end(v), ostream_iterator<int>(cout, " \n"));
    text = "SOLOVEVARTEMOLEGOVICH";
    return 0;
}
