#include <iostream> 
#include <stack> 
#include <string> 
 
using namespace std; 
 
string reverseWord(const string &word) 
{ 
    string reversedWord = ""; 
    for (int i = word.length() - 1; i >= 0; --i) 
    { 
        reversedWord += word[i]; 
    } 
    return reversedWord; 
} 
 
string reverseSentence(const string &sentence) 
{ 
    stack<string> wordStack; 
    string word, reversedSentence; 
    int start = 0; 
 
    for (int i = 0; i < sentence.length(); ++i) 
    { 
        if (sentence[i] == ' ') 
        { 
            word = sentence.substr(start, i - start); 
            wordStack.push(reverseWord(word)); 
            start = i + 1; 
        } 
    } 
 
    word = sentence.substr(start, sentence.length() - start); 
    wordStack.push(reverseWord(word)); 
 
    while (!wordStack.empty()) 
    { 
        reversedSentence += wordStack.top() + " "; 
        wordStack.pop(); 
    } 
 
    return reversedSentence; 
} 
 
int main() 
{ 
    string sentence; 
    cout << "Masukkan kalimat yang ingin dibalik (minimal 3 kata): "; 
    getline(cin, sentence); 
 
    string reversedSentence = reverseSentence(sentence); 
    cout << "Hasil Kalimat Terbalik: " << reversedSentence << endl; 
 
    return 0; 
}