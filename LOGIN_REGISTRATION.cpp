

#include <iostream>
#include<fstream> // fstream is a library which is used in oder to create files/write info. in files /read info. from files i.e file handling
#include<string.h>
using namespace std;
void login();
void registration();
void forgotPassword();

int main()
{int option;

    cout<<"\t\t\t Welcome to the Page \n\n\n";
    cout<<"\t\t\t Please select from the following options\n\n\n";
    cout<<"\t Press 1 for Login"<<endl;
    cout<<"\t Press 2 for Registration"<<endl;
    cout<<"\t Press 3 for Password Retrieval"<<endl;
    cout<<"\t Press 4 to exit "<<endl;
    cout<<"\t Please Select The Option:";
    cin>>option;
    cout<<endl;
    switch (option){
        case 1: login();
                break;
        case 2: registration();
                break;
        case 3: forgotPassword();
                break;
        case 4: cout<<"THANK YOU FOR VISITING...EXIT!!!"<<endl;
        default:system("cls");
                cout<<"Please Enter a Valid Option"<<endl;
                main();
    }
    

    return 0;
}
void login(){ int count;
    
    string userID,password,id,pass;
    cout<<"\t\t\tPlease Enter the UserID and Password\n";
    cout<<"\t\t\tUserID:";
    cin>>userID;
    cout<<"\t\t\tPassword:";
    cin>>password;
    ifstream input("records.text");
    while(input>>id>>pass){
        if(id==userID && pass==password){
            count=1;
            
        }
    }input.close();
    if (count==1){
        cout<<"userID"<<endl<<"LOGGED IN SUCCESSFULLY"<<endl;
        main();
    }else {
        cout<<"LOGIN ERROR!!! TRY AGAIN!!!"<<endl;
        main();
    }
}
 void registration(){
    string ruserID,rpassword,rid,rpass;
    cout<<"Please Enter the userID:";
    cin>>ruserID;
    cout<<"Please Enter the password:";
    cin>>rpassword;
    ofstream file1("records.txt",ios::app) ;
    file1<<ruserID<<' '<<rpassword<<endl;
    cout<<"YOUR REGISTRATION IS DONE SUCCESSFULLY!!!"<<endl;
    main();
}
void forgotPassword(){
    int choice;
    cout<<"FORGOT PASSWORD? DON'T WORRY\n";
    cout<<"Press 1 to search your id by userID"<<endl;
    cout<<"Press 2 to return to main menu"<<endl;
    cout<<"PLEASE ENTER THE CHOICE:";
    cin>>choice;
    switch(choice){
        case 1:{
            int count=0;
            string suserID,sid,spass;
            cout<<"\n Enter The Username That Your Remember:";
            cin>>suserID;
            ifstream file2("records.txt");
            while(file2>>sid>>spass){
                if(sid==suserID){
                    count=1;
                }
            }file2.close();
            if (count==1){
                cout<<"Match Found!!!"<<endl;
                cout<<"Matching Password is:"<<spass;
                main();
            }else{
                cout<<"NOT FOUND!!! REGRETS!!!"<<endl;
                main();
            }break;
        }case 2:{
            main();
        }default:
                 cout<<"Wrong Choice...TRY AGAIN!!!"<<endl;
                 forgotPassword();
    }
}