#include<bits/stdc++.h>
#define distance(d1,d2) sqrt(d1*d1+d2*d2)
#define F(i,a,b) for(int(i)=a;i<=b;i++)
#define FT(i,a,b) for(int(i)=a;i<b;i++)
#define FF(i,a,b) for(int(i)=a;i>=b;i--)
#define FN(i,a,b) for(int(i)=a;i>b;i--)
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define revful(ehe) reverse(ehe.begin(),ehe.end())
#define pll pair<ll,ll>
#define fast() (ios_base:: sync_with_stdio(false),cin.tie(NULL));
#define sortfull(x) sort(x.begin(),x.end())
const ll mod=1e9+7;
#define testcase cin>>tc;while(tc--)
#define xd cout<<endl;
using namespace std;

int tc;
void read() {
    freopen("DATA.in","r",stdin);
    // freopen("DATA.out","w",stdout);
}
//int row,col;
//int a[125][125];
//int dx[8]= {1,0,1,-1,1,-1,0,-1};
//int dy[8]= {1,1,0,1,-1,0,-1,-1};
class poly {
  private:
    int deg;
    vector<double> coef;
  public:
    void input();
    void print();
    double calculate(double x);
    poly operator+(poly);
    poly operator-(poly);
    poly operator*(poly);
};

void poly::input() {
    cin>>deg;
    F(i,0,deg) {
        double x;
        cin>>x;
        coef.pb(x);
    }
}

void poly::print() {
    int n = coef.size();
    cout<<coef[0]<<"x^"<<n-1;
    FT(i,1,n) {
        if(i<n-1) {
            if(coef[i]>0) cout<<"+"<<coef[i]<<"x^"<<n-i-1;
            if(coef[i]<0) cout<<coef[i]<<"x^"<<n-i-1;
        } else {
            if(coef[n-1]<0) cout<<coef[n-1];
            else cout<<"+"<<coef[n-1];
        }
    }
    xd
}

double poly::calculate(double x)
{
    int n=this->coef.size();
    double res=0;
    FT(i,0,n-1)
    {
        res=res+this->coef[i]*pow(x,n-1-i);
    }
    res+=this->coef[n-1];
    return res;
}
poly poly::operator+(poly another) {
    vector<double> a=this->coef,b=another.coef;
    revful(a);
    revful(b);
    int n1=a.size(),n2=b.size();
    int n=max(n1,n2);
    poly sum;
    sum.coef.resize(n);
    FT(i,0,n) {
        double x=(i<n1)?a[i]:0;
        double y=(i<n2)?b[i]:0;
        sum.coef[i]=x+y;
    }
    revful(sum.coef);
    return sum;
}

poly poly::operator-(poly another) {
    vector<double> a=this->coef,b=another.coef;
    revful(a);
    revful(b);
    int n1=a.size(),n2=b.size();
    int n=max(n1,n2);
    poly diff;
    diff.coef.resize(n);
    FT(i,0,n) {
        double x=(i<n1)?a[i]:0;
        double y=(i<n2)?b[i]:0;
        diff.coef[i]=x-y;
    }
    revful(diff.coef);
    return diff;
}

poly poly::operator*(poly another) {
    int n1=this->coef.size(),n2=another.coef.size();
    int n=n1+n2-1;
    vector<double> a=this->coef,b=another.coef;
    poly prod;
    prod.coef.resize(n,0);
    FT(i,0,n1) {
        FT(j,0,n2) {
            prod.coef[i+j]+=a[i]*b[j];
        }
    }
    return prod;
}

int main() {
    //read();
    poly a,b,c;
    cout<<"input a:"<<endl;
    a.input();
    cout<<"input b:"<<endl;
    b.input();
    c=a+b;
    cout<<"C = a + b = ";
    c.print();
    cout<<"C = a - b = ";
    c = a-b;
    c.print();
    c=a*b;
    cout<<"C = a * b = ";
    c.print();
    cout<<"Calculating polynomial C with x = 2"<<endl;
    double f2=c.calculate(2);
    cout<<"C(2) = "<<f2;
}
