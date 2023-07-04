#include<bits/stdc++.h>
#include<windows.h>
#include<cstdlib>
using namespace std;
const float R = 5.75;
int randID()
{
    return  (rand()%(99999));
}
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
class Banking_Service
{
    public:
    string acc_holder_name;
    int age;
    long long contact_no;
    long long acc_no;
    long PIN;
    public:
    float Bal, amount, min_Bal = 2000;
    void new_AC();
    void chq_bal();
    void deposit();
    void withdraw();
    void new_FD();
    
};

int main()
{
    system("cls");
    char ch;
    Banking_Service s;
    while(1)
    {
        gotoxy(35,15);
        cout<<"Welcome to E-Banking services";
        gotoxy(32,17);
        cout<<"1- Open New Bank A/c";
        gotoxy(32,18);
        cout<<"2- Cheque Balance";
        gotoxy(32,19);
        cout<<"3- Cash Deposit";
        gotoxy(32,20);
        cout<<"4- Cash Withdraw";
        gotoxy(32,21);
        cout<<"5- Create FD";
        gotoxy(32,22);
        cout<<"6- Apply for Home Loan";
        gotoxy(32,23);
        cout<<"7- Apply for Gold Loan";
        gotoxy(32,24);
        cout<<"8- Locker services";
        gotoxy(32,25);
        cout<<"9- Exit";
        gotoxy(32,27);
        cin>>ch;
        switch(ch)
        {
            case '1':
            {
                s.new_AC();
                break;
            }
            case '2':
            {
                s.chq_bal();
                break;
            }
            case '3':
            {
                s.deposit();
                break;
            }
            case '4':
            {
                s.withdraw();
                break;
            }
            case '5':
            {
                s.new_FD();
            }
            case '9':
            {
                system("cls");
                exit(0);
                break;
            }
            default:
            {
                cout<<"Invalid Choice code";
                break;
            }
        }

    }
    return 0;
}
void Banking_Service::new_AC()
{
    system("cls");
    cout<<"\n Name of account holder : ";
    getline(cin,acc_holder_name);

    cin.ignore();
    cout<<"\n Age : ";
    cin>>age;
    cin.ignore();
    if(age<18)
    {
        cout<<"\nNot eligible !";
        
        getchar();
        exit(0);
    }
    cout<<"\n Contact No : ";
    cin>>contact_no;
    // cout<<"\n Your Account Number is : ";
    // acc_no = randID();
    //cout<<setfill('0')<<setw(6)<<acc_no<<endl;
    // cout<<"\n Set PIN : ";
    // cin>>PIN;
    //const long pinc = PIN;
    Bal=min_Bal;
    getchar();
    cout<<"\n You have successfully opened new bank account !";
    getchar();
    system("cls");
    fstream f;
    f.open("acc_details.txt",ios::out);
    if(!f)
    {
        cout<<"\n Error 404 : File not found";
    }
    else
    {
        // //f<<acc_holder_name<<endl;
        // f<<acc_no<<endl;
        // f<<PIN<<endl;
        // f.close();
    }
}
void Banking_Service::chq_bal()
{
    system("cls");
    //long pin;
    // cout<<"\n Enter PIN :";
    // cin>>pin;
    // ifstream fi;
    // fi.open("acc_ddetails.txt",ios::in);
    // fi>>PIN;
    // if(pin == PIN)
    // {
    //     cout<<"\n Balance = Rs."<<Bal<<endl;
    // }
    cout<<"\n Balance = Rs."<<Bal<<endl;
    getchar();
    cin.ignore();
    system("cls");
}
void Banking_Service::deposit()
{
    system("cls");
    cout<<"\n Balance = Rs."<<Bal<<endl;
    cout<<"\n Amount to be deposited ";
    cin>>amount;
    Bal = Bal + amount;
    cout<<"\n Balance = Rs."<<Bal<<endl;
    cin.ignore();
    getchar();
    system("cls");
}
void Banking_Service::withdraw()
{
    system("cls");
    cout<<"\n Balance = Rs."<<Bal<<endl;
    cout<<"\n Amount to be withdrawn ";
    cin>>amount; 
    if((Bal-amount)<min_Bal)
    {
        cout<<"\n Insufficient Balance !";
    }
    else
    {
        Bal = Bal - amount;
        cout<<"\n Balance = Rs."<<Bal<<endl;
    }
    cin.ignore();
    getchar();
    system("cls");
}
void Banking_Service::new_FD()
{
    system("cls");
    char m;
    float cap;
    int T;
    cout<<"Enter Capital : "<<endl;
    cin>>cap;
    getchar();
    cout<<"Enter term of maturity : ";
    cin>>T;
    cout<<"From Savings account (enter s) OR From new Capital (enter c) ?";
    cin>>m;
    float M_am;

    if(m=='s')
    {
        Bal = Bal - cap;
        cout<<"\n Updated balance = "<<Bal;
        M_am = cap*pow ((1+(R/100)),T);
        cout<<"\n Maturity amount = "<<M_am;
    }
    if(m=='c')
    {
        M_am = cap*pow ((1+(R/100)),T);
        cout<<"\n Maturity amount = "<<M_am;
    }
    else
    {
        cout<<"\n Invalid Input";
    }
    cin.ignore();
    system("cls");
}

