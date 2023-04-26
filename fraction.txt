#include<bits/stdc++.h>
//#include<windows.h>
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

class fraction {
  private:
    ll x,y;
    double D;
  public:
    friend istream& operator >> (istream& in,fraction &a);
    fraction operator + (fraction );
    fraction operator - (fraction );
    fraction operator * (fraction );
    friend bool compare(fraction A,fraction B);
    friend ostream& operator << (ostream& out,fraction a);
    double toDecimal();
};

double fraction::toDecimal() {
    return this->x/this->y;
}

bool compare(fraction A,fraction B) {
    fraction c=A-B;
    double ehe=c.toDecimal();
    return ehe>0;
}
fraction fraction::operator+(fraction other) {
    fraction result;
    result.x=this->x*other.y+other.x*this->y;
    result.y=this->y*other.y;
    ll ehe=__gcd(result.x,result.y);
    result.x/=ehe,result.y/=ehe;
    result.D=result.toDecimal();
    return result;
}

fraction fraction::operator - (fraction other) {
    fraction result;
    result.x=this->x*other.y-this->y*other.x;
    result.y=this->y*other.y;
    ll ehe=__gcd(result.y,result.x);
    result.x/=ehe,result.y/=ehe;
    result.D=result.toDecimal();
    return result;
}

fraction fraction::operator*(fraction other) {
    fraction res;
    res.x=this->x*other.x;
    res.y=this->y*other.y;
    ll ehe=__gcd(result.y,result.x);
    result.x/=ehe,result.y/=ehe;
    return res;
}
istream& operator >> (istream& in,fraction& a) {
    cout<<"tu =";
    in>>a.x;
    xd
    do {
        cout<<"mau =";
        in>>a.y;
    } while(a.y==0);
    return in;
}

ostream& operator <<(ostream& out,fraction a) {
    out<<a.x<<"/"<<a.y;
    xd
    return out;
}

int main() {
    fraction c,a,b;
    cin>>a;
    cin>>b;
    c=a+b;
    cout<<"c = a + b:"<<endl;
    cout<<c;
    cout<<"c = a - b:"<<endl;
    c=a-b;
    cout<<c;  
    c=a*b;
    cout<<"c = a*b:"<<endl;
    cout<<c;
    if(compare(a,b)) cout<<"a > b";
    else cout<<"a < b";
}
