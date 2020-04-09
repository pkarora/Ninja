#include <iostream>
using namespace std;
int main()
   //Write a program to print first x terms of the series 3N + 2 which are not multiples of 4.
{
  int n;
  cin>>n;
  int i=1;
  int k=1;
while (i<=n) {
  int j=3*k+2;
  if(j%4!=0){
    cout<<j<<" ";
    i=i+1;
  }
  k=k+1;
}
}
