#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;

int studentLogin();
int adminLogin();
int studentView();
int adminView();
int markMyAttendance(string username);
int checkCredentials(string userName, string password);
int delay();

void delay()
{
for(int i=0; i<3; i++)
{
	cout<<"\n SAVING";
    for(int j=0; j<20000; j++)
    {
    	for(int k=0; k<20000; k++)
       	{ }
    }
}  
cout<<"\n QUITTING";
for(int i=0; i<3; i++){
   for(int j= 0; j<20000; j++) { 
     for(int k=0; k<20000; k++){
	 }
    } 
}
}

int studentLogin()
{
system("cls");
cout<<"\n STUDENT LOGIN --";	
studentView();
delay();
return 0; 
}


int adminLogin()
{
system("cls");
cout<<"\n ADMIN LOGIN --";	

string username;
string password;

cout<<"\n Enter username -";
cin>>username;
cout<<"\n Enter password -";
cin>>password;

if(username=="admin" && password=="admin@2") 
{
    adminView();
    getchar();	
    delay();
}   
else
{
cout<<"\n Error! Invalid Credentials!";	
cout<<"\n Press any key for Main Menu";
getchar();
getchar();
}
return 0;
}

int studentView()
{
cout<<"\n STUDENT LOGIN --\n";		
string username, password;
cout<<"\n Enter username -";
cin>>username;

cout<<"\n Enter password -";
cin>>password;

int res = checkCredentials(username, password);

if(res  == 0)
{
   cout<<"\n Error! Invalid Credentials!";
   cout<<"\n Press any key for Main Menu";
   getchar(); getchar();	
   return 0;
} 

int goBack = 0;
while(1)
{
system("cls");

cout<<"\n ENTER 1 - Mark Attendance for today \n 2 - Count my Attendance till date \n 3 - Return";
cout<<"ENTER YOUR CHOICE";
int choice;
cin>>choice;

switch(choice)
{
	case 1: markMyAttendance(username);
	break;
	case 2: countMyAttendance(username);
	break;
	case 0: goBack = 1;
	break;
    default: cout<<"\n Invalid choice entered. Try again.";
    getchar();           	
}   

if(goBack == 1)
{
break;
}     	
} 
}

int adminView()
{	
int goBack = 0;
while(1)
{
system("cls");
cout<<"\n ENTER 0 - Return back \n 1 - Register a Student \n 2 - Delete all students name that are registered \n 3 - Delete a student through rollno \n 4 - Check list of students registered by userame \n 5 - Check present attendance of any student through rollno \n 6 - Get complete list of students with their attendance";
int choice;

cout<<"ENTER YOUR CHOICE";
cin>>choice;

switch(choice)
{
	case 1: registerStudent();
	break;  
	case 2: deleteAllStudents();
	break;
	case 3: deleteStudentbyRollno();
	break;
	case 4: checkListOfStudentsRegistered();
	break;
	case 5: checkPresenseCountbyRollno();
	break;
	case 6: getListOfStudentsWithTheirPresenseCount();
	break;
	case 0: goBack = 1;
	break;
    default: cout<<"\n Invalid choice entered. Try again.";
    getchar();           	
}   
if(goBack == 1)
{
break;
}     
}
return 0;
}

int checkCredentials(string username, string password)
{
ifstream read;
read.open("db.dat");

if (read) {
int recordFound = 0;
string line;
string temp = username + password + ".dat";
cout<<"\n file name is : "<<temp;
while(getline(read, line)) {
	if(line == temp)
	{
		recordFound = 1;
		break;
	}
}
if(recordFound == 0)
    return 0;
else
   return 1;
}
else
{
   return 0;
}    		
}

int markMyAttendance(string username)
{
cout<<"\n Marked Attendance for today";	
cout<<"\n Press any key to continue.";

getchar();getchar();

return 0;	
} 


int main() {
	
while(1)
{
	system("cls");
	cout<<"\n ATTENDANCE MANAGEMENT SYSTEM \n";
	
	cout<<"ENTER 1 - STUDENT LOGIN \n 2 - ADMIN LOGIN \n 3 - EXIT \n";
	int choice;
	cout<<"ENTER YOUR CHOICE";
	cin>>choice;
	switch(choice)
	{
	case 1: studentLogin();
	break;
	case 2: adminLogin();
	break;
	case 3: 
	        while(1)
	        {
		    system("cls");
        	cout<<"\n Are you sure, you want to exit? Press y for yes or n for no \n";
        	char ex;
        	cin>>ex;
        	if(ex == 'y' || ex == 'Y')
        	   exit(0);
        	else if(ex == 'n' || ex == 'N')
             {
             	break;
             }
             else{
             	cout<<"\n Invalid choice entered.";
             	getchar();
             }

     	   }
            break;
             	 
    default: cout<<"\n Invalid choice entered. Try again.";
    getchar();
	}   		        

}	
return 0;
} 