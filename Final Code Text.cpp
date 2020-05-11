#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<fstream.h>
#include<ctype.h>
#include<dos.h>
#include<math.h>
//LOGOUT
void logout()
{	gotoxy(10,10);
	for(int j=0;j<5;j++)
	{
		cout<<"* ";
        delay(500);
	}
	for(int i=100;i<500;i+=100)
	{
        sound(i);
        delay(500);
	}
        nosound();
        exit(0);
}
//CALCULATOR
void core()
{
    clrscr();
    int ch=1;
	float num1, num2;
	char op;
	while(ch!=0)
    {
        cout<<"Enter number1"<<endl;
        cin>>num1;
        cout<<"Enter operator"<<endl;
        cin>>op;
        cout<<"Enter number2"<<endl;
        cin>>num2;
        switch(op)
        {
            case '+':   cout<<"ANS: "<<num1+num2<<endl;
                        break;
            case '-':   cout<<"ANS: "<<num1-num2<<endl;
                        break;
            case '*':   cout<<"ANS: "<<num1*num2<<endl;
                        break;
            case '/':   cout<<"ANS: "<<num1/num2<<endl;
                        break;
            case '^':
            case '$':   cout<<"ANS: "<<pow(num1, num2)<<endl;
                        break;
            default:    cout<<"Error"<<endl;
        }
        cout<<"Enter 0 to go back"<<endl;
        cin>>ch;
	}
getch();
}
//CORE FEATURES CLASS
class core_features
{
	public: void todolist();
            void calculator();
            void digital_clock();
			void input();
			void deposit();
			void withdraw();
			void display();

			char name[50];
			int accno;
			char acctype[50];
			float balance;

            void menu_screen();
            //For RPS Game
            char username[35];
            int pt1;
            int i, j, pt2, huser, hcomp[3];
            char ch, ch2, ch3; int len; int temp;

            void init();
            void maingame();
            void startup();
            void check();
            void ending();
            void maing();
	protected:  void passbook();
                void manage_account();
};
//TO-DO LIST
void core_features::todolist()
{
	clrscr();
	int ch1;
	gotoxy(0,3);
	cout<<"1. NEW"<<endl<<"2. OPEN "<<endl<<"3. BACK"<<endl;
	cin>>ch1;

	switch(ch1)
	{
		case 1: clrscr();
				int ch2;
				cout<<"1. PRESENTATION"<<endl<<"2. CYCLING"<<endl<<"3. WORKOUT"<<endl<<"4. MEETING"<<endl<<"5. SHOPPING"<<endl;
				cin>>ch2;
				ofstream off;
				off.open("List.dat");
				switch(ch2)
				{
					case 1:	off<<"PRESENTATION"<<endl;
							break;
					case 2:	off<<"CYCLING"<<endl;
							break;
					case 3: off<<"WORKOUT"<<endl;
							break;
					case 4:	off<<"MEETING"<<endl;
							break;
					case 5:	off<<"SHOPPING"<<endl;
							break;
					default: cout<<endl<<"STICK TO THE PLAN!"<<endl;
                             break;
				}
				off.close();
				break;
		case 2: clrscr();
				char todo[20];
				ifstream iff("List.dat");
				iff>>todo;
				cout<<"CURRENT TASK: "<<todo<<endl;
				getch();
				break;
        case 3: menu_screen();
				break;
	}
	menu_screen();


}
//MENU SCREEN
 void core_features::menu_screen()
{
	clrscr();
	cout<<"1. PASSBOOK"<<endl<<"2. ENTERTAINMENT"<<endl<<"3. CALCULATOR"<<endl<<"4. TO DO LIST"<<endl<<"5. LOG OUT"<<endl;
	int ch;
	cin>>ch;
	switch(ch)
	{
		case 1: passbook();
                break;
		case 2: maing();
				menu_screen();
                break;
		case 3: calculator();
                break;
		case 4: todolist();
                break;
		case 5: logout();
                break;
	}
}
//CALCULATOR
void core_features::calculator()
{
	core();
	menu_screen();
}
//INPUTTING DETAILS
void core_features::input()
{

    cout<<"ENTER THE DETAILS\n";
    cout<<"Enter The Name Of Depositor: ";
    cin>>name;
    cout<<"Enter The Account Number: ";
    cin>>accno;
    cout<<"Enter The Account Type: ";
    cin>>acctype;
    cout<<"Enter The Amount To Be Deposited: ";
    cin>>balance;
	fstream fileout("Passbook.dat", ios::out);
	fileout<<name<<"\n"<<accno<<"\n"<<acctype;
	fileout.close();
	fstream fileout2("Balance.dat", ios::out);
	fileout2<<balance;
	fileout2.close();


}
//DEPOSITING
void core_features::deposit()
{
    float x;
    cout<<"DEPOSIT:\n";
    cout<<"Enter The Amount To Be Deposited: ";
    cin>>x;
    balance+=x;
	fstream filein("Balance.dat", ios::out);
	filein<<balance;
	filein.close();


}
//WITHDRAWING
void core_features::withdraw()
{
    float amt;
    cout<<"WITHDRAW:\n";
    cout<<"Enter The Amount To Withdraw: ";
    cin>>amt;
    balance-=amt;
	fstream filein("Balance.dat", ios::out);
	filein<<balance;
	filein.close();
}
//DISPLAY
void core_features::display()
{
	fstream filein2("Passbook.dat", ios::in);
	filein2>>name>>accno>>acctype;
	filein2.close();
	fstream filein3("Balance.dat", ios::in);
	filein3>>balance;
	filein3.close();
    cout<<" ACCOUNT DETAILS:\n";
    cout<<"Name Of The Depositor: "<<name<<endl;
    cout<<"Account Number: "<<accno<<endl;
    cout<<"Account Type: "<<acctype<<endl;
    cout<<"Balance: "<<balance<<endl;
}
//PASSBOOK
void core_features:: passbook()
{
	int choice=1;
    while(choice!=0)
    {
        cout<<"-----BANK-----\n";
        cout<<"1.CREATE ACCOUNT\n2.DEPOSIT\n3.WITHDRAW\n4.CURRENT ACCOUNT STATUS\n5.BACK\n";
        cin>>choice;
        switch(choice)
        {
            case 1: input();
                    break;
            case 2: clrscr();
					deposit();
                    break;
            case 3: clrscr();
					withdraw();
                    break;
            case 4: clrscr();
					display();
                    break;
			case 5: menu_screen();
            default: cout<<"invalid";
                     break;
        }
    }
}
//Defining the class for creating an account
class admin_account: public core_features
{
    public:
    //Declaring The Data Members Of The Class
    char user_name[100];
    char password[11];
    char profile_name[100];
};
//ROCK-PAPER SCISSOR
//Function To Initialize The Player Name
void core_features::init()
{
    clrscr();
    char username[110];
    gotoxy(10,10);
    cout<<"\nEnter your name: \n";
    cin>>username;
    for(int j=0;j<strlen(username);j++)
    toupper(username[j]);
}
//Function To Execute The Ending Of The Game
void core_features::ending()
{
     clrscr();
     gotoxy(20,19);
     cout<<"That's it!! So... who's the winner?\n";
     gotoxy(20,20);
     cout<<"********************************************";
     gotoxy(20,21);
     cout<<"*                                          *";
     gotoxy(20,22);
     cout<<"*  Your score:"<<pt1<<"|| Computer's score: "<<pt2;
     gotoxy(20,23);
     cout<<"*                                          *";
     gotoxy(20,24);
     cout<<"********************************************";
     gotoxy(20, 35);
     if(pt1>pt2)
     {
         cout<<"YOU WON! Good going..\n"; getch();
     }
     else if(pt1<pt2)
     {
         cout<<"HARD LUCK! Better luck next time!\n";
         getch();
     }
     else if(pt1==pt2)
     {
         cout<<"WOW! It's a tie! Do you want a tie breaker? (y/n)\n";
         cin>>ch3;
         if(ch3=='n')
         {
             clrscr();
             exit(0);
         }
         else if(ch3=='y')
         {
             clrscr();
             maingame();
         }
     }
	 menu_screen();
}
//Function That Takes Care Of The Main Running Of Game.
void core_features::maingame()
{
    srand(time(NULL));
    int k=0;
    int hcomp[3]={1,2,3};
    while(k<6)
    {
        sleep(1);
        gotoxy(20,20);
        cout<<"\nROUND"<<k+1;
        gotoxy(20,21);
        cout<<"------ --\n";
        gotoxy(10,15);
        cout<<username<<" enter your hand: 1 for ROCK, 2 for PAPER, 3 for SCISSORS\n\n";
        cin>>huser;
        gotoxy(10,35);
        temp=rand()%3;
        cout<<"Computer's hand: ";
        cout<<hcomp[temp];
        check();
        k++;
        gotoxy(20, 20);
        cout<<"********************************************";
        gotoxy(20,21);
        cout<<"*                                          *";
        gotoxy(20,22);
        cout<<"*  Your score:"<<pt1<<" || Computer's score:"<<pt2;
        gotoxy(20,23);
        cout<<"*                                          *";
        gotoxy(20,24);
        cout<<"********************************************";
        clrscr();
        gotoxy(20,100);
        cout<<"Entering next round.\n\n";
        getch();
    }
    ending();
}
//Function To Check For Hands And Increment Scores
void core_features::check()
{
    if((temp==0 && huser==2) || (temp==1 && huser==3) || (temp==2 && huser==1))
    pt1+=2;
    else if((temp==1 && huser==1) || (temp==2 && huser==2) || (temp==0 && huser==3))
    pt2+=2;
    else if((temp==0 && huser==1) || (temp==1 && huser==2) || (temp==2 && huser==3))
    {
        pt1+=1; pt2+=1;
    }
}
//Function To Initiate The Game's Starting Sequence
void core_features::startup()
{
    clrscr();
    gotoxy(21,10);
    cout<<"ENTER to play\n";
    getch();
    clrscr();
    gotoxy(21,10);
    cout<<"   ###########     ###########      ###########    \n";
    gotoxy(21,11);
    cout<<"   #          #    #          #    #               \n";
    gotoxy(21,12);
    cout<<"   #          #    #          #    #               \n";
    gotoxy(21,13);
    cout<<"   #          #    #          #    #               \n";
    gotoxy(21,14);
    cout<<"   ###########     ###########      ##########     \n";
    gotoxy(21,15);
    cout<<"   #         #     #                          #    \n";
    gotoxy(21,16);
    cout<<"   #          #    #                          #    \n";
    gotoxy(21,17);
    cout<<"   #          #    #                          #    \n";
    gotoxy(21,18);
    cout<<"   #          #    #               ###########     \n";
    gotoxy(21,20);
    cout<<"           ROCK  -  PAPER  -  SCISSORS             \n\n";
    cout<<"\n\n\n   INSTRUCTIONS: The game runs for 6 rounds. Enter your hand against the computer's to score 2 points every win and 1 point in case of tie.\n Total points at the end of 6 rounds will be checked for the winner. Good luck!\n\n\n";
    cout<<"          VERSION 11.10.04, 2018\n\n\n";
}
//Main Function That Invokes All Other Functions
void core_features::maing()
{
    clrscr();
    startup();
    cout<<"Enter 'y' to continue or 'n' to exit\n";
    input:
    cin>>ch;
    if(ch=='n')
    {
        cout<<"\nExiting...\n";
        exit(0);
    }
    else if(ch!='y')
    {
        cout<<"Enter valid choice\n";
        goto input;
    }
    else
        init();
        clrscr();
        maingame();
        getch();
}
//LOGIN SCREEN
int login_screen()
{
    admin_account A;
    char check_password[110], check_username[110];
    clrscr();
    gotoxy(10,10);
    cout<<"Login to your account.."<<endl;
    gotoxy(10,15);
    cout<<"USER NAME: "<<endl;
    gotoxy(10,16);
    cout<<"PASSWORD: "<<endl;
    gotoxy(22,15);
    gets(check_username);
    char ch;
    gotoxy(21,16);
    clreol();
	ch=getch();
	//While loop to print '*' instead of text for password entry
	int i=0;
	while(ch!=13)
	{
	    check_password[i]=ch;
	    cout<<'*';
	    ch=getch();
	    i++;
	}
    check_password[i]='\0';
    char password[110], user_name[110];
    strcpy(password, "qwerty");
    strcpy(user_name, "Planner");
	if(strcmp(check_username, user_name)==0)
	{
		if(strcmp(check_password, password)==0)
		{
			clrscr();
			gotoxy(10,10);
			cout<<"Login successful! Press any key..";
			getch();
			return 0;
		}
	}
	else
	{
		cout<<"\nUSER NAME/PASSWORD INCORRECT!!"<<endl;
		return 1;
	}
    return 1;
}
//MAIN FUNCTION
void main()
{

	clrscr();
	gotoxy(10,10);
	cout<<"LOADING...";
	gotoxy(10,11);
	for(int j=0;j<5;j++)
	{
		cout<<"* ";
		delay(500);
	}
	for(int i=100;i<500;i+=100)
	{
	   sound(i);
	   delay(500);
	}
	   nosound();
	mai:
	clrscr();
    int ch;
    gotoxy(10,10);
	cout<<"1. LOGIN";
	gotoxy(10,11);
	cout<<"2. EXIT"<<endl;
	gotoxy(10,12);
	cin>>ch;
	admin_account B;
	clrscr();
	switch(ch)
	{
		case 0: clrscr();
                gotoxy(10,10);
                cout<<"EXITING...";
                delay(1500);
                exit(0);

		case 1: int res;
                res=login_screen();
                if(res==1)
                goto mai;
                clrscr();
                B.menu_screen();
                break;
        case 2:
		default:cout<<"Enter valid choice"<<endl;
    }
getch();
}
