#include<bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long int
#define mod 1000000007
using namespace std;


bool check[1000005]={false};
int func(int a)
{
    int ans=(a*(a+1))%mod;
    ans*=(2*a + 1);
    ans%=mod;
    ans*=166666668;
    ans%=mod;
    return ans;
}
void solve()
{
  int n;
  cin>>n;

  int ans=n%mod;
  int s = sqrt(n);
  if(s>1000000)
  {
    //   cout<<"true";
         s = 1000000;

        vector<int> divisors;
        int div=1;
        while(n/div>1000000000000)
        {
            divisors.push_back(n/div);
            div++;
        }
        divisors.push_back(1000000000000);



        for(int &i : divisors)
        {
            i = (int)sqrt(i);
        }


        for(int i=0;i<divisors.size()-1;i++)
        {
            ans+=(((func(divisors[i])-func(divisors[i+1])+mod)%mod)*(i+1))%mod;
            ans%=mod;
        }

  }
//   cout<<s<<endl;

    for(int i=2;i<=s;i++)
    {

      if(check[i]==false)
      {

        for(int j=i*i;j<=n;j*=i)
              {
                if(j<1000005)
                check[j]=true;

                ans+=((((n/j)%mod)*(j%mod))%mod);
                ans%=mod;

                if(j>1000000 and j<=1000000000)
                {
                    int t = j*j;
                    ans-=((((n/t)%mod)*(t%mod))%mod);
                    ans+=mod;
                    ans%=mod;
                }
                if((long double)j * (long double)i > (long double)n)
                  break;
              }

      }

    }


  cout<<ans<<endl;






}
signed main()

{
  FAST_IO;
  int t = 1;

  cin>>t;

  while(t--)
  {
    solve();
  }

  return 0;
}
