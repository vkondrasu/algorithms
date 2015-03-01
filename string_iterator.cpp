#include<string>
#include<iostream>
#include<stack>
using namespace std;
int main(){
   string str ;
   stack<char> s;
cout<<"Enter the string: ";
   cin >> str ;
   for(string::iterator itr = str.begin();itr!=str.end();itr++){
             cout << *itr << "\n";
             s.push(*itr);
             cout << "Top of the stack " << s.top() << endl;}
 cout << "\n" << endl;
 return 0;}
