#include<bits/stdc++.h>
#include<windows.h>
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

class Matrix {
  private:
    int row,col;
    vector<vector<double>> arr;
  public:
    Matrix(int x,int y) {
        arr.resize(x,vector<double>(y,0));
        row=x,col=y;
    }
    Matrix()
    {

    }
    void input();
    friend istream& operator >>(istream& in,Matrix &a);
    friend ostream& operator <<(ostream& out,Matrix a);
    void print();
    Matrix operator+(Matrix);
    Matrix operator*(Matrix);
    Matrix Transposition();
    Matrix Inverse();
    Matrix Ladder();
    double determinant();
};

istream& operator >>(istream& in,Matrix &a) {
    cout<<"Enter the elements of the matrix:"<<endl;
    FT(i,0,a.row) {
        FT(j,0,a.col) in>>a.arr[i][j];
    }
}

ostream& operator <<(ostream& out,Matrix a)
{
    FT(i,0,a.row) {
        FT(j,0,a.col) {
            out<<setw(10)<<fixed<<setprecision(2)<<a.arr[i][j];
            Sleep(150);
        }
        xd
    }
}

void Matrix::input() {
    cout<<"Enter the matrix size: ";
    cin>>row>>col;
    cout<<"Enter the elements of the matrix:"<<endl;
    this-> arr.resize(row,vector<double>(col));
    FT(i,0,row) {
        FT(j,0,col) cin>>this->arr[i][j];
    }
}

void Matrix::print() {
    this-> row=this->arr.size();
    this-> col=this->arr[0].size();
    FT(i,0,row) {
        FT(j,0,col) {
            cout<<setw(10)<<fixed<<setprecision(2)<<arr[i][j];
            Sleep(150);
        }
        xd
    }
}

Matrix Matrix::operator+(Matrix other) {
    if(this->col!=other.col||this->row!=other.row) {
        cout<<"Dimension ERROR!"<<endl;
        exit(1);
    }

    Matrix result(row,col);
    FT(i,0,row) {
        FT(j,0,col) {
            result.arr[i][j]=this->arr[i][j]+other.arr[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator*(Matrix other) {
    if(this->col!=other.row) {
        cout<<"Dimension ERROR!"<<endl;
        exit(1);
    }

    Matrix result;
    result.arr.resize(row,vector<double>(other.col,0));
    FT(i,0,row) {
        FT(j,0,other.col) {
            FT(k,0,this->col) {
                result.arr[i][j]+=arr[i][k]*other.arr[k][j];
            }
        }
    }
    return result;
}

Matrix Matrix::Transposition() {
    Matrix result;
    int rr=this->col,cr=this->row;
    result.arr.resize(rr,vector<double>(cr,0));
    FT(i,0,rr) {
        FT(j,0,cr) {
            result.arr[i][j]=arr[j][i];
        }
    }
    return result;
}

Matrix Matrix::Ladder() {
    Matrix lad;
    lad.row=this->row,lad.col=this->col;
    lad.arr=this->arr;
    int i=0,j=0,k,t,n=this->row,m=this->col,hang;
    double temp,luu;
    while(i<n&&j<m) {
        if(lad.arr[i][j]==0) {
            for(t=i+1; t<n; t++)
                if(lad.arr[t][j]!=0) {
                    for(k=i; k<m; k++) {
                        swap(lad.arr[t][k],lad.arr[i][k]);
                    }
                    break;
                }
            if(t==n) j++;
        }
        if(lad.arr[i][j]!=0) {
            for(t=i+1; t<n; t++)
                if(lad.arr[t][j]!=0) {
                    luu=lad.arr[t][j];
                    for(k=j; k<m; k++)
                        lad.arr[t][k]=lad.arr[t][k]-lad.arr[i][k]*luu/lad.arr[i][j];
                }
            i++;
            j++;
        }
    }
    return lad;
}


double Matrix::determinant() {
    Matrix tmp = this->Ladder();
    int n=tmp.row,m=tmp.col;
    if(n!=m||m==1||n==1) exit(0);
    double det=1;
    FT(i,0,n) det*=tmp.arr[i][i];
    return det;

}

Matrix Matrix::Inverse() {
    int n=this->row;
    Matrix res;
    vector<vector<double>> ehe=this->arr;
    if(this->determinant()==0) exit(1);
    res.arr.resize(n,vector<double>(n));
    FT(i,0,n) res.arr[i][i]=1;

}

int main() {
    //read();
    Matrix a(2,3),b,c;
    cin>>a;
    b.input();
    c=a+b;
    cout<<c;
   // a.input();
    //a.print();
    /* b.input();
     b.print();
     cout<<"C = a * b ="<<endl;
     c=a*b;
     c.print();*/
   /* cout<<"Ladder matrix of A:"<<endl;
    Matrix d=a.Ladder();
    d.print();
    cout<<"Determinant of A = ";
    cout<<fixed<<setprecision(15)<<a.determinant()<<endl;
    d=a.Inverse();
    cout<<"Inverse matrix of A:\n";
    d.print();*/
}
