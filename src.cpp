#include<iostream>
#include<conio.h>
#include<fstream>

using namespace std;

//declaring file object
ifstream ofile;


string mi,mp,ui,up;
int f=1;
bool validate(string id,string pass){
	cout<<"\nvalidating...\n";
	string userid,password,p;
	string line;
	bool a=true;
	bool b=false;
	ofile.open("login.txt");
if (!ofile)
cout << "Unable to open file"<<endl;
else
{
while (!ofile.eof())
{
    ofile >> userid >> password;
if (ofile.fail())
    break;
else if (userid == id)
        {
        if(password == pass){
			system("cls");
			return b;
            break;
		}
        }
    }
}

		return a;  
}

	
string convert(string *password,int size ){
	int i;
	string s="";
	for(i=0;i<size;i++){
		s= s+ password[i];
	}
	return s;
}

int pass_enc(string mi){
	string password[20];
	int i;
	int val;
	string id;
	id=mi;
	cout<<"enter password";
	for(i=0;i<11;i++){
		password[i] = getch();
		cout<<"*";
	}
	int size = sizeof(password)/sizeof(string);
	string pass = convert(password,size);
	val = validate(id,pass);
	cout<<"\nreturned value\n"+val;
	return val;
}

class login{
public:
void m_login(){
	cout<<"\nmaster login\n";
	cout<"############################################";
	cout<<"\nenter master id\n";
	cin>>mi;
	string password;
	bool v;
	v = pass_enc(mi);
	if(v==0){
		//next_page
		cout<<"access granted";
	}
	else{
		cout<<"\naccess denied\n";
	}
	
}
/*void u_login(){
	cout<<"\nuser login\n";
	cout<<"############################################";
	cout<<"\nEnter user id\n";
	cin>>ui;
	int v;
	if(v==1){
		//next page
	}
	else{
		cout<<"\naccess denied\n";
	}
}*/


void login_page(){
		int ch;
		cout<<"\n1- Master login\n";
		cout<<"\n2- User login(not in use)\n";
		cin>>ch;
		switch(ch){
			case 1:{
				m_login();
				break;
			}
			case 2:{
				u_login();
				break;
			}
			case 3:{
				//main_page();
				break;
			}
		}
}
};


login logobj;
void signup_page(){
}
void main_page(){
	int ch;
	cout<<"				Welcome";
	cout<<"\n\n";
	cout<<"############################################";
	cout<<"\n";
	cout<<"\n1-login\n";
	cout<<"\n2-sign up\n";
	cin>>ch;
	switch(ch){
		case 1:{
			logobj.login_page();
			break;
		}
		case 2:{
			signup_page();
			break;
		}
	}
}
main(){
	main_page();
}
/* void imain(){
string s;
cout<<"enter id";
cin>>s;
cout<<"\npasswordforid"+s+":";
}*/

