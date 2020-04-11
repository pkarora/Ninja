#include <iostream>
using namespace std;
int main()
 // Write a program to generate the reverse of a given number N.
{
int n;
cin>>n;
int reverse = 0;
int i=n;
while (i>0)
 {
  /* code */
  int k=i%10;
  reverse = reverse*10 + k;
  i = i/10;
 }
 cout<<reverse;
}
