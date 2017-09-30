#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int main(int argc,char ** argv , char ** envp)
{
  char ** ptr = envp;
  int i = 0;

  while(*ptr)
  {
   cout<<i++<<" "<< "env : "<< *ptr << endl;
   *ptr++;
  }

  char *user = getenv("USER"); //  passing key to getenv function
  if(user)
  {
   cout << "user name : "<<user << endl;
  }
  char *home = getenv("HOME");
  if(home)
  {
   cout << "home address : "<<home << endl;
  }
  return 0;
}
