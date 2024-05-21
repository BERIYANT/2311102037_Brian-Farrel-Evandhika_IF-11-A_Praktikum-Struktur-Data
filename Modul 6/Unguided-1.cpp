#include <iostream> 
#include <stack> 
#include <string> 
 
using namespace std; 
 
bool isPalindrome(string str) 
{ 
    stack<char> s; 
 
    for (char c : str) 
    { 
        if (isalnum(c)) 
        {                      
            s.push(tolower(c));  
        } 
    } 
    for (char c : str) 
    { 
        if (isalnum(c)) 
        {  
            if (tolower(c) != s.top()) 
            { 
                return false; 
            } 
            s.pop(); 
        } 
    } 
 
    return true; 
} 
 
int main() 
{ 
    string kalimat; 
    cout << "Masukkan kalimat: "; 
    getline(cin, kalimat); 
 
if (isPalindrome(kalimat)) 
{ 
cout << "Kalimat tersebut adalah palindrom." << endl; 
} 
else 
{ 
cout << "Kalimat tersebut bukan palindrom." << endl; 
} 
return 0; 
}