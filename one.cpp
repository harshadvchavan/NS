// exp - 1 updated code 

#include<iostream>
#include<string>
using namespace std;

int main(){
    string password="Admin";
    cout<<"Press \n 1:default password\n 2:changing password\n 3:print the password \n";
    int c;
   while(1){
       cout<<"Enter the choice: ";
    cin>> c;
        if(c==1){
            string pass;
            cout<<"Enter the Password: ";
            cin>>pass;
            if(pass==password){
                 cout<<"It is a Default Password "<<endl;
                 
            }
            else{
                cout<<"You have Entered Wrong Password "<<endl;
            }
        }
        else if(c==2){
            string pass;
            cout<<"Enter the New Password: ";
            cin>>pass;
            password= pass;
            cout<<"Your Password is Reseted"<<endl;
        }
        else if(c==3){
            int len=password.length();
            for(int i=0;i<len;i++){
                cout<<'*';
            }
            cout<<endl;
        }
        else{
            cout<<"You have choosen invalid choice"<<endl;
        }
            
    }
}