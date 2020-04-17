#include<bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;
// int i=0;
long long int mod = 998244353;

class node
{
    
    public:
        long long int a,b,c,d;

        node()
        {
            a=b=c=d=748683265;
        }

};


node* solve(node* x, node* y, int op)
{
    long long int p=0,q=0,r=0,s=0;
    // cout<<"im being called"<<endl;


    if(op==2)
    {
        p+=((x->a)*(y->a + y->b + y->c + y->d))%mod;
        p+=((x->b)*(y->a))%mod;
        p+=((x->c)*(y->a + y->d))%mod;
        p+=((x->d)*(y->a + y->c))%mod;

        q+=((x->b)*(y->b))%mod;

        r+=((x->b)*(y->c))%mod;
        r+=((x->c)*(y->b))%mod;
        r+=((x->c)*(y->c))%mod;

        s+=((x->b)*(y->d))%mod;
        s+=((x->d)*(y->b))%mod;
        s+=((x->d)*(y->d))%mod;

    }
    else if(op==3)
    {
        p+=((x->a)*(y->a))%mod;

        q+=((x->b)*(y->a + y->b + y->c + y->d))%mod;
        q+=((x->a)*(y->b))%mod;
        q+=((x->c)*(y->b + y->d))%mod;
        q+=((x->d)*(y->b + y->c))%mod;

        r+=((x->a)*(y->c))%mod;
        r+=((x->c)*(y->a))%mod;
        r+=((x->c)*(y->c))%mod;

        s+=((x->a)*(y->d))%mod;
        s+=((x->d)*(y->a))%mod;
        s+=((x->d)*(y->d))%mod;

    }
    else
    {
        p+=((x->a)*(y->a))%mod;
        p+=((x->b)*(y->b))%mod;
        p+=((x->c)*(y->c))%mod;
        p+=((x->d)*(y->d))%mod;

        q+=((x->a)*(y->b))%mod;
        q+=((x->b)*(y->a))%mod;
        q+=((x->c)*(y->d))%mod;
        q+=((x->d)*(y->c))%mod;

        r+=((x->a)*(y->c))%mod;
        r+=((x->b)*(y->d))%mod;
        r+=((x->c)*(y->a))%mod;
        r+=((x->d)*(y->b))%mod;

        s+=((x->a)*(y->d))%mod;
        s+=((x->b)*(y->c))%mod;
        s+=((x->c)*(y->b))%mod;
        s+=((x->d)*(y->a))%mod;

    }

    p%=mod;
    q%=mod;
    r%=mod;
    s%=mod;
    node* answer = new node();
    answer->a = p;
    answer->b = q;
    answer->c = r;
    answer->d = s;
    // cout<<x->a<<" "<<x->b<<" "<<x->c<<" "<<x->d<<" "<<endl;
    // cout<<y->a<<" "<<y->b<<" "<<y->c<<" "<<y->d<<" "<<endl;
    // cout<<answer->a<<" "<<answer->b<<" "<<answer->c<<" "<<answer->d<<" "<<endl;
    // cout<<mod<<endl;

    return answer;


}
void solve()
{
    string s;
    cin>>s;
    // string extra = "" ;
    map<char,int> mp;
    mp['('] = 0;
    mp[')'] = 1;
    mp['&'] = 2;
    mp['|'] = 3;
    mp['^'] = 4;
    mp['#'] = 5;
    stack<int> st;
    node* ans = new node();
    map<int, node*> mpp;
    int curr=6;
    for(int i=0;i<s.size();i++)
    {
        int p = mp[s[i]];
        if(p==1)
        {
            node* a = NULL;
            node* b = NULL;
            if(st.top()>5)
                b=mpp[st.top()];
            else
                b= new node();
            st.pop();

            int operand = st.top();
            st.pop();

            if(st.top()>5)
                a=mpp[st.top()];
            else
                a = new node();
            st.pop();

            st.pop();
            ans = solve(a,b,operand);
            mpp[curr]=ans;
            st.push(curr++);
            delete a;
            delete b;

        }
        else
        st.push(p);
    }

    // cout<<endl<<extra<<endl;

    // long long int a=748683265,b=748683265,c=748683265,d=748683265;
    // long long int var = 748683265;

    // for(int i=0;i<extra.size();i++)
    // {
    //     long long int p=0,q=0,r=0,s=0;
    //     if(extra[i]=='&')
    //     {
    //         p+=((var%m)*((4*a+b+2*c+2*d)%m))%m;
    //         q+=((b%m)*(var%m))%m;
    //         r+=((var%m)*((b+2*c)%m))%m;
    //         s+=((var%m)*((b+2*d)%m))%m;

    //     }
    //     else if(extra[i]=='|')
    //     {
    //         p+=((a%m)*(var%m))%m;
    //         q+=((var%m)*((a+4*b+2*c+2*d)%m))%m;
    //         r+=((var%m)*((a+2*c)%m))%m;
    //         s+=((var%m)*((a+2*d)%m))%m;


    //     }
    //     else
    //     {
    //         p+=((var%m)*((a+b+c+d)%m))%m;
    //         q+=((var%m)*((a+b+c+d)%m))%m;
    //         r+=((var%m)*((a+b+c+d)%m))%m;
    //         s+=((var%m)*((a+b+c+d)%m))%m;
    //     }

    //     a=p;
    //     b=q;
    //     c=r;
    //     d=s;
    // }


    cout<<ans->a<<" "<<ans->b<<" "<<ans->c<<" "<<ans->d<<" "<<endl;




}
int main()

{
    FAST_IO;
    long int t = 1;

    cin>>t;

    while(t--)
    {
        solve();
    }

    return 0;
}
