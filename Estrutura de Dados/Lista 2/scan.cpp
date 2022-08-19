#include <string>
#include <iostream>
 
using namespace std;


int main(int argc, char *argv[])
{
  string str;
  getline (cin,str);
  string::iterator it;
  cout << str << endl;
  for(it = str.begin(); it < str.end(); it++){
    char a = *it;
    if (a != 'O'){cout << a;}
  } 
  cout << '\n';
  int tamstring = str.size() -109;
  char tams = 'Tam';
  system("PAUSE");
  return 0;
}