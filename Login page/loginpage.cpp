
// That of the project is to create a login page using C++ lanaguage . Then its tell about User account is  have  or not in our databases

#include<iostream>
#include<fstream>
using namespace std;
class temp{
string userName,Email,password;
string searchName,searchpass,searchEmail;
fstream file;
public:
void login();
void signUP();
void forget();

}obj;
int main(){
    char choice;
    cout<<"\n1- Login";
    cout<<"\n2- Sign-Up";
    cout<<"\n3- Forget ";
    cout<<"\n4- Exit";
    cout<<"\nEnter the Choice :";
    cin>>choice;
    cin.ignore();
    switch(choice){
        case '1':
        obj.login();
        break;
        case '2':
        obj.signUP();
        break;
        case '3':
        obj.forget();
        break;
        case '4':
        return 0;
        break;
        default:
        cout<<"Please chhhhh Valid choice!!!!";
    
      }
}

void temp :: signUP(){
    cout<<"\nEnter Your User Name :";
    getline(cin,userName);
    cout<<"Enter your Email Address :";
    getline(cin,Email);
    cout<<"Enter Your Password :";
    getline(cin,password);
    file.open("loginData.txt",ios :: out | ios::app);
    file<<userName<<"*"<<Email<<"*"<<password<<endl;
    file.close();
    cout<<"Account SignUP Successfully....";

}

void temp::login(){
    string searchName,searchpass;
    cout<<"------LOGIN-------"<<endl;
    cout<<"Enter Your Username:"<<endl;
    getline(cin,searchName);
    cout<<"Enter Your Password:"<<endl;
    getline(cin,searchpass);
    file.open("loginData.txt",ios::in);
    getline(file,userName,'*');
    getline(file, Email,'*');
    getline(file,password,'\n');
    while(!file.eof()){
        if(userName==searchName){
            if(password==searchpass){
                cout<<"\n Account Login Successfully...";
                cout<<"\nUsername :"<<userName<<endl;
                cout<<"\nEmail :"<<Email<<endl;
           }
           else{
            cout<<"Please Enter Valid Password....";
           }
        }
        getline(file,userName,'*');
        getline(file, Email,'*');
        getline(file,password,'\n');

    }
    file.close();

}

void temp :: forget(){
    cout<<"\n Enter Your Username:";
    getline(cin,searchName);
    cout<<"\nEnter Your Email Address :";
    getline(cin,searchEmail);
    file.open("loginData.txt",ios::in);
    getline(file,userName,'*');
    getline(file,Email,'*');
    getline(file,password,'\n');
    while(!file.eof()){
        if(userName==searchName){
            if(Email==searchEmail){
                cout<<"\nAccount found Successfully"<<endl;
                cout<<"Your Password :"<<password<<endl; 

            }else{
                cout<<"Not Found Your Account....";
            }
        

        }else{
            cout<<"\n Not Found Your Account...";
        }
    }
}