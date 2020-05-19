#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

string getParameterizedWord(const string &word);
bool isThere(const string &orderedWord, unordered_map<string, string> &map);
void print(unordered_map<string, string> &map);

int main() {

    string word, orderedWord;
    unordered_map<string, string> ananagrams;

    while (true)
    {
        cin>>word;
        if (word == "#") break;
        orderedWord = getParameterizedWord(word);
        if (!isThere(orderedWord, ananagrams))
            ananagrams[orderedWord] = word;
        else
            ananagrams[orderedWord] = "NOT";
    }

    print(ananagrams);

    return 0;
}

string getParameterizedWord(const string &word){
    string returnWord = word;
    for (int i = 0; i<word.size(); i++)
    {
        if (isupper(returnWord[i]))
            returnWord[i] = tolower(returnWord[i]);
    }
    sort(returnWord.begin(), returnWord.end());
    return returnWord;
}

bool isThere(const string &orderedWord, unordered_map<string, string> &map){
    for (auto element: map)
        if (element.first == orderedWord)
            return true;
    return false;
}

void print(unordered_map<string, string> &map){
    vector <string> vec;
    for (auto element: map)
        if (element.second != "NOT")
            vec.push_back(element.second);
    sort(vec.begin(), vec.end());
    for (auto element: vec)
        cout<<element<<endl;
}

