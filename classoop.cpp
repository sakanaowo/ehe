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
const string UD = "Unidentified";
const int cnt = 100;

int tc;
void read() {
    freopen("DATA.in","r",stdin);
    // freopen("DATA.out","w",stdout);
}
//int row,col;
//int a[125][125];
//int dx[8]= {1,0,1,-1,1,-1,0,-1};
//int dy[8]= {1,1,0,1,-1,0,-1,-1};
string standardized_date(string s) {
    string tmp=s;
    if(tmp[1]=='/')tmp="0"+tmp;
    if(tmp[4]=='/')tmp.insert(3,"0");
    return tmp;
}
class Person {
  private:
    string name,ID;
    string birth,address;
    string gender;
  public:
    void input();
    void display();
};

void Person::input() {
    string s;
    cout<<"Please enter your"<<endl;
    cout<<"Name: ",getline(cin,this->name);
    xd
    cout<<"Date of birth: ",cin>>s;
    this->birth=standardized_date(s);
    cin.ignore();
    xd
    cout<<"Address: ",getline(cin,this->address);
    xd
    cout<<"Male/Female (M/F): ";
    cin>>this->gender;
}
void Person::display() {
    cout<<"----"<<this->name<<"----";
    cout<<"Birth: "<<this->birth<<endl;
    cout<<"Address: "<<this->address<<endl;
    cout<<"Gender: ";
    if(this->gender=="F") cout<<"Female";
    else if(this->gender=="M") cout<<"Male";
    else cout<<UD;
    xd
    xd
}

class Alumnus: Person {
  private:
    double GPA,fee;
    string major;
  public:
    void inputA();
    void displayA();
};

void Alumnus::inputA() {
    Person::input();
    // cout<<"GPA: ",cin>>this->GPA;
    // xd
    cout<<"Major: ",cin>>this->major;
}

void Alumnus::displayA() {
    Person::display();
    cout<<"Major: "<<this->major<<endl;
}




