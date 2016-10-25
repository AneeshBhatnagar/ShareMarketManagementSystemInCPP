/*
	Share Market Management System
	Made By : Aneesh Bhatnagar
	Enrollment Number : A2305211097
	Guided By : Ms. Sugandha Agarwal
*/

#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<dos.h>
#include<process.h>
#include<graphics.h>
#define max 10 //The maximum number of shares that a person can buy.
#define path "BGI" //The path for the BGI Drivers.

char Aname[]="admin",Adpass[]="password"; //The administrator's username and password.
char loggedin[10]; // To store the username of the user currently logged in.

void administrator(); //A funtion which handles all administrator functions.
void customer(); // A function which handles all customer functions.
void showallsh(); // A function to show all the exiting shares in the database.
void showsh(); // A function used to show a particular share.
void colourit(); // A function which sets the background colour and the text colour.
void getpass(); // A function which reads the password from the keyboard and hides it behind *
void blink(); // A function to show "Share Market Management System" blinking style on screen
void newuser(); // A function to allow new users to register!
class shares
{
	protected:
	char cname[20]; //The Company Name
	int cno; // The unique Company Number
	float unitp; // The unit Price per share of the company.
	public:
	int retno() //Funtion to return the Company number
	{
		return cno;
	}
	float retprice() // Function to return the Unit price per share
	{
		return unitp;
	}
	void dispshare(); // A function which displays a share.
	void updateprice(int x)
	{
		unitp=x;
	}
};

class customers: public shares
{
	protected:
	int nos[max],bought,utype,uinfo; // Array to store the shares bought and utype defines the type of the user.
	float bal; // The current balance in the customer's account.
	char uname[10],upass[10],uemail[30],uaddress[50],ucontact[10],ufname[20]; // The deatils of the user.
	public:
	char* retuser()
	{
		return uname;
	}
	char* retpass()
	{
		return upass;
	}
	int retshare()
	{
		return bought;
	}
	float retbal()
	{
		return bal;
	}
	int rettype()
	{
		return utype;
	}
	int retinfo()
	{
		return uinfo;
	}
	void updatepass(char x[])
	{
		strcpy(upass,x);
	}
	void purch(int x,float p)
	{
		nos[bought++]=x;
		bal-=p;
	}
	void updatetype()
	{
		utype=1;
	}
	void setbal(float x)
	{
		utype=0;
		bought=0;
		bal=x;
	}
	void getudata(); // A function that is used to get the data of a new user.
	void userauth(); // A function to authorise the login of a user.
	void dispuserinfo(); // A function which displays the user information for the logged in user.
	void buyshare(); // A function to purchase shares.
	void viewshares(); // A function to show all shares of a user
	void view();
	void changepass(); // A function to change the password of a user.
	void sellshare(); // A function to sell a user share.
	int sell(int);
	int buy(int,float);
	void updateinfo(); // A function which allows the user to update their information in the database.
	void update();
	void showinfo();
	void show();
	void newudata();
};

class admin: public customers
{
	public:
	void adduser(); // A function to add a new customer.
	void edituser(); // A function to edit an existing customer.
	void deluser(); // A function to delete any particular customer.
	void showallu(); // A function to display all the existing users in the database.
	void getdata(); // A function to get the data of a share.
	void addshare(); // A function to add a new share.
	void delshare(); // A function to delete a share.
	void editshare(); // A function to update the unit price of a share.
	void activate(); // A function to approve the user info.
	void approve(); // A function to activate the new users.
};

void main()
{
	int run=1;	// Run is used to check if the loop still needs to run or not!
	char op;
	int gd=DETECT,gm; // Graphics mode and Graphics Driver
	initgraph(&gd,&gm,path); // Initializing the Graphics Mode
	blink();
	op=getch();
	while(run)
	{
		clrscr();
		cleardevice();
		colourit();
		cout<<"\nWelcome to the Share Market Management System"
			<<"\n\nChoose your user type : "
			<<"\n1. Administrator"
			<<"\n2. Customer"
			<<"\n3. Register as a new user"
			<<"\nEnter your user type : ";
		op=getch();
		switch(op)
		{
			case '1': administrator();
					run=0;
					break;
			case '2': customer();
					run=0;
					break;
			case '3': newuser();
						run=0;
						break;
			default: cout<<"\nInvalid Choice entered! Please choose again!";
				getch();

		}
	}
	getch();
	closegraph();// Closing the Graphics Mode.
}

// Global Functions.

void administrator()
{
	clrscr();
	cleardevice();
	char aname[10],apass[10];
	cout<<"\nUsername: ";
	gets(aname);
	cout<<"Password: ";
	gets(apass);
	if((strcmp(aname,Aname)==0) && strcmp(apass,Adpass)==0)
	{
		cout<<"\nWelcome Administrator!"
			<<"\nPress any key to continue!";
		getch();
	}
	else
	{
		cout<<"\nInvalid Details entered!";
		return;
	}
	int op=0;
	admin ob;
	while(1)
	{
		clrscr();
		cleardevice();
		cout<<"\t\t Administrator Menu "
			<<"\nSelect the task to perform : "
			<<"\n 0. Exit"
			<<"\n 1. Add Users "
			<<"\n 2. Change Password for a user "
			<<"\n 3. Delete Users "
			<<"\n 4. Add Shares "
			<<"\n 5. Modify Shares "
			<<"\n 6. Delete Shares "
			<<"\n 7. Display All Shares "
			<<"\n 8. Display A Particular Share"
			<<"\n 9. Display All Users "
			<<"\n10. Approve user data "
			<<"\n11. Activate new users "
			<<"\nEnter Option: ";
		cin>>op;
		switch(op)
		{
			case 0: exit(0);
			case 1 : ob.adduser();
					  break;
			case 2 : ob.edituser();
					  break;
			case 3 : ob.deluser();
					  break;
			case 4 : ob.addshare();
					  break;
			case 5 : ob.editshare();
					  break;
			case 6 : ob.delshare();
					  break;
			case 7 : showallsh();
					  break;
			case 8 : showsh();
					  break;
			case 9 : ob.showallu();
					  break;
			case 10 : ob.activate();
						break;
			case 11 : ob.approve();
						break;
			default:cout<<"\nInvalid Option entered!";
		}
		cout<<"\nPress any key to continue!";
		getch();
	}
}

void customer()
{
	clrscr();
	cleardevice();
	customers x;
	x.userauth();
	getch();
	char op;
	while(1)
	{
		clrscr();
		cleardevice();
		x.dispuserinfo();
		cout<<"\t\t Customer Menu "
			<<"\nSelect the task to perform : "
			<<"\n0. Exit"
			<<"\n1. Buy Shares "
			<<"\n2. Sell Shares "
			<<"\n3. View your Shares "
			<<"\n4. Display all Shares "
			<<"\n5. Display a Particular Share "
			<<"\n6. Change your Password "
			<<"\n7. Update your Information "
			<<"\n8. Display your Information "
			<<"\nEnter Option: ";
		op=getche();
		cout<<op;
		switch(op)
		{
			case '0': exit(0);
			case '1' : x.buyshare();
					  break;
			case '2' : x.sellshare();
					  break; 
			case '3' : x.viewshares();
					  break;
			case '4' : showallsh();
					  break;
			case '5' : showsh();
					  break;
			case '6' : x.changepass();
					  break;
			case '7' : x.updateinfo();
						break;
			case '8' : x.showinfo();
						break;
			default:cout<<"\nInvalid Option entered!";
		}
		cout<<"\nPress any key to continue!";
		getch();
	}
}

void showallsh()
{
	fstream f;
	admin ob;
	f.open("shares.dat",ios::in | ios::binary);
	if(!f)
	{		
		cout<<"\nError connecting to database!";
		getch();
		return;
	}
	while(f.read((char*)&ob,sizeof(ob)))
		ob.dispshare();
	f.close();
}

void showsh()
{
	fstream f;
	admin ob;
	int x,flag=0;
	f.open("shares.dat",ios::in | ios::binary);
	if(!f)
	{		
		cout<<"\nError connecting to database!";
		getch();
		return;
	}
	cout<<"\nEnter the share number : ";
	cin>>x;
	while(f.read((char*)&ob,sizeof(ob)))
	{
		if(x==ob.retno())
		{
			ob.dispshare();
			flag=1;
			break;
		}
	}
	if(flag==0)
		cout<<"\nNo such share found in the database!";
	f.close();
}

void colourit()
{
	setbkcolor(1);//Setting the background colour.
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
	setcolor(YELLOW);//Setting the text colour for dispuserinfo function.
}

void getpass(char A[])
{
	for(int i=0;i<10;i++)
	{
		A[i]=getch();
		if((int)A[i]==13)
			break;
		else
			cout<<"*";
	}
	A[i]='\0';
	cout<<endl;
}

void blink()
{
	char *str,ch;
	int i,j,location,n,c=10;
	strcpy(str,"             Welcome to Share Market Management System             ");
	colourit();
	for(i=0;!kbhit();i++)
	{
		cleardevice();
		if(c==14)
			c=10;
		else
			c++;
		setcolor(c);
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
		outtextxy(5,50,str);
		outtextxy(80,150,"Project Title : Share Market Management System");
		outtextxy(80,170,"Made By : Aneesh Bhatnagar");
		outtextxy(80,190,"Enrollment Number : A2305211097");
		outtextxy(80,210,"Class : 5CSE2-Y");
		delay(350);
        ch = str[0];
		 n=strlen(str);
       location=0;
       for(j=location;j<n;j++)
         str[j] = str[j+1];
       str[n-1]=ch;
       str[n]=NULL;
	}

}

void newuser()
{
	customers ob,x;
	fstream f;
	f.open("users.dat",ios::in | ios::binary);
	if(!f)
	{
		cout<<"\nError connecting to database!";
		return;	
	}
	ob.newudata();
	while(f.read((char*)&x,sizeof(x)))
	{
		if(strcmp(ob.retuser(),x.retuser())==0)
		{
			cout<<"\nA user with this name already exists in the system! Press any key to exit.";
			f.close();
			return;
		}
	}
	f.close();
	f.open("users.dat",ios::app | ios::binary);
	if(!f)
	{
		cout<<"\nError Connecting to database!";
		getch();
		return;
	}
	f.write((char*)&ob,sizeof(ob));
	cout<<"\nUser Succesfully Saved! Waiting for Administrator approval.";
	f.close();
}
//Functions of Shares Class

void shares::dispshare()
{
	cout<<"\nCompany Identification number: "<<cno
		<<"\nCompany Name : ";
	puts(cname);
	cout<<"Unit Price(in Rs.):"<<unitp<<endl;
}

//Functions of Customers Class

void customers::getudata()
{
	cout<<"\nEnter the login ID:";
	gets(uname);
	cout<<"Enter the password : ";
	gets(upass);
	cout<<"Enter the Account Balance : ";
	cin>>bal;
	utype=0;
	uinfo=0;
	bought=0;
	cout<<"The no. of shares bought have been set to 0 by default!";
}

void customers::userauth()
{
	int flag=0;
	customers x;
	fstream f;
	f.open("users.dat", ios::in | ios::binary);
	if(!f)
	{
		cout<<"\nError Connecting to Database! Press Any key to exit.";
		getch();
		exit(0);
	}
	cout<<"\nUsername: ";
	gets(uname);
	cout<<"Password: ";
	getpass(upass);
	while(f.read((char*)&x,sizeof(x)))
		if((strcmp(uname,x.retuser())==0) && (strcmp(upass,x.retpass())==0))
		{
			if(x.rettype()==-1)
				flag=-1;
			else
				flag=1;
			break;
		}
	f.close();
	if(flag==1)
	{
		cout<<"Logged in Successfully! Press any key to continue.";
		strcpy(loggedin,uname);
	}
	else if(flag==0)
	{
		cout<<"Invalid Credentials entered. Press any key to exit.";
		getch();
		exit(1);
	}
	else if(flag==-1)
	{
		cout<<"Your account has not been approved by an administrator! Please wait until it is activated.";
		getch();
		exit(1);
	}
}

void customers::dispuserinfo()
{
	fstream f;
	int maxx=getmaxx();
	char out1[20],out2[20];
	customers x;
	f.open("users.dat", ios::in | ios::binary);
	if(!f)
	{
		cout<<"\nError connecting to Database!";
		return;
	}
	while(f.read((char*)&x,sizeof(x)))
		if(strcmp(loggedin,x.retuser())==0)
			break;
	float a=x.retbal();
	sprintf(out1,"Rs.%.2f",a);
	sprintf(out2,"%d",x.retshare());
	outtextxy(maxx-200,10,"Username:");
	outtextxy(maxx-120,10,x.retuser());
	outtextxy(maxx-200,20,"Balance:");
	outtextxy(maxx-130,20,out1);
	outtextxy(maxx-200,30,"Shares Purchased:");
	outtextxy(maxx-60,30,out2);
	f.close();
}

void customers::buyshare()
{
	int buyno,flag=0;
	float price;
	admin ob;
	customers x;
	fstream f;
	if(bought==max)
	{
		cout<<"\nSorry, you have purchased the maximum number of shares that a user can.";
		return;
	}
	cout<<"\nThe shares currently available are as follows.";
	showallsh();
	cout<<"\nEnter the Company Identification number to buy a share : ";
	cin>>buyno;
	f.open("shares.dat",ios::in | ios::binary);
	if(!f)
	{
		cout<<"\nError Connecting to Database!";
		return;
	}
	while(f.read((char*)&ob,sizeof(ob)))
		if(buyno==ob.retno())
		{
			price=ob.retprice();
			flag=1;
		}
	if(flag==0)
	{
		cout<<"\nNo such company found!";
		f.close();
		return;
	}
	f.close();
	int ans=buy(buyno,price);
	if(ans==1)
		cout<<"\nShare Purchased Successfully!";
	else if(ans==-1)
		cout<<"\nInsufficient Balance!";
	else
		cout<<"\nError Connecting to Database!";
}

void customers::viewshares()
{
	fstream f;
	f.open("users.dat",ios::in | ios::binary);
	if(!f)
	{
		cout<<"\nError connecting to database!";
		return;
	}
	customers x;
	while(f.read((char*)&x,sizeof(x)))
	{
		if(strcmp(loggedin,x.retuser())==0)
		{
			x.view();
			break;
		}
	}
	f.close();
}

void customers::view()
{
	if(bought==0)
	{
		cout<<"\nNo Shares purchased!";
		return;
	}
	int i=0;
	admin ob;
	fstream f;
	f.open("shares.dat",ios::in | ios::binary);
	if(!f)
	{
		cout<<"\nError connecting to database!";
		return;
	}
	while(f.read((char*)&ob,sizeof(ob)))
	{
		for(int i=0;i<bought;i++)
			if(nos[i]==ob.retno())
				ob.dispshare();
	}
	f.close();
}

void customers::changepass()
{
	char cpass[10],npass1[10],npass2[10];
	fstream f;
	customers ob;
	int flag=0;
	f.open("users.dat",ios::in | ios::out | ios::binary);
	if(!f)
	{
		cout<<"\nError connecting to database!";
		return;
	}
	cout<<"\nEnter your current password for verification : ";
	getpass(cpass);
	long pos=f.tellg();
	while(f.read((char*)&ob,sizeof(ob)))
	{
		if((strcmp(loggedin,ob.retuser())==0) && (strcmp(cpass,ob.retpass())==0))
		{
			cout<<"Enter new password :";
			getpass(npass1);
			cout<<"Enter new password again: ";
			getpass(npass2);
			if(strcmp(npass1,npass2)==0)
			{
				ob.updatepass(npass1);
				f.seekg(pos,ios::beg);
				f.write((char*)&ob,sizeof(ob));
				flag=1;
			}
			else
				flag=-1;
			break;
		}
		pos=f.tellg();
	}
	if(flag==0)
		cout<<"Invalid password entered!";
	else if(flag==1)
		cout<<"Password Changed Successfully!";
	else
		cout<<"\nBoth the passwords do not match!";
	f.close();
}

void customers::sellshare()
{
	if(bought==0)
	{
		cout<<"\nYou have not purchased any shares yet! Please Purchase before selling.";
		return;
	}
	int ans,sno;
	customers ob;
	fstream f;
	cout<<"\nTo view all your shares, press any key.";
	getch();
	viewshares();
	cout<<"\nEnter the share number you wish to sell: ";
	cin>>sno;
	f.open("users.dat",ios::in | ios::out | ios::binary);
	if(!f)
	{
		cout<<"\nError Connecting to Database!";
		return;
	}
	long pos=f.tellg();
	while(f.read((char*)&ob,sizeof(ob)))
	{
		if(strcmp(loggedin,ob.retuser())==0)
		{
			f.seekg(pos,ios::beg);
			ans=ob.sell(sno);
			f.write((char*)&ob,sizeof(ob));
			break;		
		}
		pos=f.tellg();
	}
	if(ans==1)
		cout<<"\nShare has been sold successfully!";
}	

int customers::sell(int no)
{
	admin x;
	fstream f;
	float p=0;
	int flag=0;
	f.open("shares.dat",ios::in | ios::binary);
	if(!f)
	{
		cout<<"\nError Connecting to Database!";
		return 0;
	}
	for(int i=0;i<bought;i++)
		if(nos[i]==no)
		{
			flag=1;
			break;
		}
	if(flag==0)
	{
		cout<<"\nYou do not have any such share!";
		f.close();
		return 0;
	}
	while(f.read((char*)&x,sizeof(x)))
	{
		if(no==x.retno())
		{
			p=x.retprice();
			break;
		}
	}
	f.close();
	bal+=p;
	for(i=0;i<bought;i++)
	{
		if(no==nos[i])
		{
			for(int j=i;j<bought-1;j++)
				nos[j]=nos[j+1];
			bought--;
			break;
		}
	}
	return 1;
}

int customers::buy(int no,float p)
{
	fstream f;
	float rem;
	customers x;
	f.open("users.dat",ios::in | ios::out | ios::binary);
	if(!f)
		return 0;
	long pos=f.tellg();
	while(f.read((char*)&x,sizeof(x)))
	{
		if(strcmp(loggedin,x.retuser())==0)
		{
			f.seekg(pos,ios::beg);
			rem=x.retbal();
			if(rem<p)
			{
				f.close();
				return -1;		
			}
			x.purch(no,p);
			f.write((char*)&x,sizeof(x));
		}
		pos=f.tellg();
	}
	f.close();
	return 1;

}

void customers::updateinfo()
{
	char pass[10];
	int flag=0;
	fstream f;
	customers ob;
	f.open("users.dat",ios::in | ios::out | ios::binary);
	if(!f)
	{
		cout<<"\nError Connecting to Database!";
		return;
	}
	cout<<"\nEnter your password before updating information : ";
	getpass(pass);
	long pos=f.tellg();
	while(f.read((char*)&ob,sizeof(ob)))
	{
		if(strcmp(loggedin,ob.retuser())==0 && strcmp(ob.retpass(),pass)==0)
		{
			ob.update();
			f.seekg(pos,ios::beg);
			f.write((char*)&ob,sizeof(ob));
			cout<<"\nInformation successfully updated!";
			flag=1;
			break;
		}
		pos=f.tellg();
	}
	if(flag==0)
		cout<<"\nIncorrect password entered!";
	f.close();
}

void customers::update()
{
	cout<<"\nEnter your First Name: ";
	gets(ufname);
	cout<<"Enter your address: ";
	gets(uaddress);
	cout<<"Enter your Mobile Number: ";
	gets(ucontact);
	cout<<"Enter your email address: ";
	gets(uemail);
	utype=0;
	uinfo=1;
}

void customers::showinfo()
{
	fstream f;
	customers ob;
	f.open("users.dat",ios::in | ios::binary);
	if(!f)
	{
		cout<<"\nError connecting to Database!";
		return;
	}
	while(f.read((char*)&ob,sizeof(ob)))
		if(strcmp(loggedin,ob.retuser())==0)
		{
			if(ob.retinfo()==0)
				cout<<"\nYou have not entered any information yet!";
			else 
			{
				if(ob.rettype()==0)
					cout<<"\nThe information that you have entered is not approved by an administrator!";
				else
					cout<<"\nThe information that you have entered has been approved!";
				ob.show();			
			}
		}
	f.close();	
}
void customers::show()
{
		cout<<"\nUsername: ";
		puts(uname);
		cout<<"Address: ";
		puts(uaddress);
		cout<<"Mobile Number: ";
		puts(ucontact);
		cout<<"Email Address: ";
		puts(uemail);
}

void customers::newudata()
{
	cout<<"\nEnter the following details in order to register: "<<endl;
	cout<<"Username: ";
	gets(uname);
	cout<<"Password: ";
	gets(upass);
	cout<<"\nEnter your First Name: ";
	gets(ufname);
	cout<<"Enter your address: ";
	gets(uaddress);
	cout<<"Enter your Mobile Number: ";
	gets(ucontact);
	cout<<"Enter your email address: ";
	gets(uemail);
	uinfo=1;
	utype=-1;
}
//Functions of Administrator Class

void admin::adduser()
{
	customers ob,x;
	fstream f;
	f.open("users.dat", ios::in | ios::binary);
	if(!f)
	{
		cout<<"\nError Connecting to Database!";
		return;
	}
	ob.getudata();
	while(f.read((char*)&x,sizeof(x)))
	{
		if(strcmp(ob.retuser(),x.retuser())==0)
		{
			cout<<"\nA user with this name already exists in the system!";
			f.close();
			return;
		}
	}
	f.close();
	f.open("users.dat",ios::app | ios::binary);
	if(!f)
	{
		cout<<"\nError Connecting to database!";
		getch();
		return;
	}
	f.write((char*)&ob,sizeof(ob));
	cout<<"\nUser Succesfully Saved!";
	f.close();
}

void admin::deluser()
{
	char x[10];
	int flag=0;
	cout<<"\nEnter the username to delete : ";
	gets(x);
	customers ob;
	fstream f,n;
	f.open("users.dat", ios::in | ios::binary);
	n.open("temp.dat", ios::out | ios::binary);
	if(!f || !n)
	{
		cout<<"\nError connecting to the database!";
		getch();
		return;
	}
	while(f.read((char*)&ob,sizeof(ob)))
	{
		if((strcmp(x,ob.retuser()))==0)
		{	
			cout<<"\nThe user has been deleted!";
			flag=1;
		}
		else
			n.write((char*)&ob,sizeof(ob));
	}
	f.close();
	n.close();
	remove("users.dat");
	rename("temp.dat","users.dat");
	if(flag==0)
		cout<<"\nUser not found!";
}

void admin::showallu()
{
	customers ob;
	fstream f;
	int i=1;
	f.open("users.dat" , ios::in | ios::binary);
	if(!f)
	{
		cout<<"\nError connecting to the database!";
		getch();
		return;
	}
	cout<<"\nThe list of all the users currently in the databse is as follows : \n\n";
	while(f.read((char*)&ob,sizeof(ob)))
	{
		cout<<i<<". ";
		puts(ob.retuser());
		i++;
	}
	f.close();
}

void admin::edituser()
{
	customers ob;
	char x[10];
	cout<<"\nEnter the username to edit : ";
	gets(x);
	int flag=0;
	fstream f;
	f.open("users.dat",ios::in | ios::out | ios::binary);
	if(!f)
	{
		cout<<"\nError connecting to databse!";
		getch();
		return;
	}	
	char newpass[10];
	long pos=f.tellg();
	while((f.read((char*)&ob,sizeof(ob))) && flag==0)
	{
		if(strcmp(x,ob.retuser())==0)
		{
			flag=1;
			f.seekg(pos, ios::beg);
			cout<<"Enter the new password : ";
			gets(newpass);
			ob.updatepass(newpass);
			f.write((char*)&ob,sizeof(ob));
		}
		pos=f.tellg();
	}
	if(flag==0)
		cout<<"No such user found in the database!";
	else 
		cout<<"Password Changed Successfully!";
	f.close();
}

void admin::getdata()
{
	cout<<"\nEnter the serial number of the share : ";
	cin>>cno;
	cout<<"Enter the company name : ";
	gets(cname);
	cout<<"Enter the unit price of the Share in Rs. : ";
	cin>>unitp;
}

void admin::addshare()
{
	admin ob,x;
	fstream f;
	f.open("shares.dat", ios::in | ios::binary);
	if(!f)
	{
		cout<<"\nError connecting to the database!";
		getch();
		return;
	}
	ob.getdata();
	while(f.read((char*)&x,sizeof(x)))
	{
		if(ob.retno()==x.retno())
		{
			cout<<"\nCompany with this Identification Number already Exists!";
			f.close();
			return;
		}
	}
	f.close();
	f.open("shares.dat", ios::app | ios::binary);
	if(!f)
	{
		cout<<"\nError Connecting to the Database!";
		getch();
		return;
	}
	f.write((char*)&ob,sizeof(ob));
	cout<<"\nShare added to the database successfully!"<<endl;
	f.close();
}

void admin::editshare()
{
	admin x;
	int no;
	cout<<"\nEnter the Company number to edit : ";
	cin>>no;
	int flag=0;
	fstream f;
	f.open("shares.dat", ios::binary|ios::in|ios::out);
	if(!f)
	{
		cout<<"\nError Connecting to the Database!";
		return;
	}
	int nprice;
	long pos=f.tellg();
	while(f.read((char*)&x,sizeof(x)))
	{
		if(no==x.retno())
		{
			flag=1;
			cout<<"\nEnter new price : ";
			cin>>nprice;
			x.updateprice(nprice);
			f.seekg(pos,ios::beg);
			f.write((char*)&x,sizeof(x));
			break;
		}
		pos=f.tellg();
	}
	if(flag==0)
		cout<<"No Company found with this number!";
	else
		cout<<"Price updated Successfully!";
	f.close();
}

void admin::delshare()
{
	admin x;
	int no,flag=0;
	cout<<"\nEnter the Company Number to delete share : ";
	cin>>no;
	fstream f,temp;
	f.open("shares.dat",ios::binary | ios::in);
	temp.open("temp.dat",ios::binary | ios::out);
	if(!f || !temp)
	{
		cout<<"\nError Connecting to Database!";
		return;
	}
	while(f.read((char*)&x,sizeof(x)))
	{
		if(x.retno()==no)
		{
			cout<<"\nThe Share has been deleted!";
			flag=1;
		}
		else
			temp.write((char*)&x,sizeof(x));
	}
	if(flag==0)
		cout<<"\nCompany not found!";
	f.close();
	temp.close();
	remove("shares.dat");
	rename("temp.dat","shares.dat");
}

void admin::activate()
{
	fstream f;
	customers ob;
	char ch='n';
	int flag=0;
	f.open("users.dat",ios::in | ios::out | ios::binary);
	if(!f)
	{
		cout<<"\nError connecting to Database!";
		return;
	}
	long pos=f.tellg();
	while(f.read((char*)&ob,sizeof(ob)))
	{
		if(ob.rettype()==0 && ob.retinfo()==1)
		{
			ob.show();
			flag=1;
			cout<<"\nApprove data?(y/n): ";
			cin>>ch;
			if(ch=='y' || ch=='Y')
			{
				ob.updatetype();
				f.seekg(pos,ios::beg);
				cout<<"\nUser data successfully updated!";
				f.write((char*)&ob,sizeof(ob));
			}
			else
				cout<<"\nUser data not approved!";
		}
		pos=f.tellg();
	
	}
	if(flag==0)
		cout<<"\nNo user with unapproved data!";
	f.close();
}

void admin::approve()
{
	fstream f;
	customers ob;
	char ch='n';
	float x;
	int flag=0;
	f.open("users.dat",ios::in | ios::out | ios::binary);
	if(!f)
	{
		cout<<"\nError connecting to Database!";
		return;
	}
	long pos=f.tellg();
	while(f.read((char*)&ob,sizeof(ob)))
	{
		if(ob.rettype()==-1)
		{
			flag=1;
			ob.show();
			cout<<"\nActivate this user?? (y/n): ";
			cin>>ch;
			if(ch=='y' || 'Y')
			{
				cout<<"\nEnter the account balance for this user: ";
				cin>>x;
				ob.setbal(x);
				f.seekg(pos,ios::beg);
				f.write((char*)&ob,sizeof(ob));		
				cout<<"User successfully activated!";
			}
			else
				cout<<"\nUser not activated!";			
		}
		pos=f.tellg();
	}
	if(flag==0)
		cout<<"\nNo unactivated users exist in the system!";
	f.close();
}