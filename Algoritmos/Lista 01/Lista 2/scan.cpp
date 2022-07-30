#include <string>
#include <iostream>
 
using namespace std;
 
int main(int argc, char *argv[])
{
    
  string str("Osmar J. Silva");
  string::iterator it;
   
  for(it = str.begin(); it < str.end(); it++){
    cout << *it;
  } 
      
  system("PAUSE"); // pausa o programa
  return EXIT_SUCCESS;
}