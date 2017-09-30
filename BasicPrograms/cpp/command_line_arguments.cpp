#include<iostream>
#include<stdio.h>

using namespace std;

int main(int argc,char ** argv , char ** envp)
{
  cout <<"Command line arguments count : "<<argc << endl;

  cout <<"Command line arguments are :"<<endl;

  for(int i = 0 ; i < argc ;i++)
  {
    cout <<"\t\t Arg : "<<i+1 <<": "<<(unsigned int)argv[i] << "," << argv[i] << endl;
   // cout << " address are : "<<(unsigned int)argv[i]<<endl;
   printf("arg %d address %u arg %s \n",i+1 ,argv[i],argv[i],argv[i]);
  }

  return 0;
}
