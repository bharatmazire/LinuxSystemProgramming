#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#define N 10

using namespace std;

int my_main(int argc,char ** argv , char ** envp)
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
 cout <<N<<endl;
  return 0;
}
