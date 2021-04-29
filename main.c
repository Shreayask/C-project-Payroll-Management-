#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#include <ctype.h>
#define EMP_FILE "d:\\emp.txt"
#define TMP_FILE "d:\\raw.txt"
#define login "admin"
#define pw "12345"
#define ENTER 13
#define TAB 9
#define BKSP 8
#define SPACE 32

void box(int a,int b,int c,int d);
void welcome_message(void);
void get_password();
void emp_menu();
void add_employee();
void display();
void edit_employee();
void delete_employee();
int scan();

int main()
{

    FILE *fptr;

    fptr=fopen("d:\\emp.txt","r" );
if(fptr==NULL)
{
    fptr=fopen("d:\\emp.txt","w");
    if(fptr==NULL)
    {
        printf("file cannot be created!!!\n");
        exit(1);
    }

}


   welcome_message();//for welcome page

	get_password();
    emp_menu();
}

COORD co={0,0};
void gotoxy(int x,int y)
{
    co.X=x;
    co.Y=y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),co);
}

void box(int a,int b,int c,int d)
{
	int i,j;
	for(i=a;i<c;i++)
	{
 		gotoxy(i,b);printf("\xcd");
		gotoxy(i,d);printf("\xcd");
	}
	for(j=b;j<d;j++)
	{
		gotoxy(a,j);printf("\xba");
		gotoxy(c,j);printf("\xba");
	}
		gotoxy(a,b);printf("\xc9");
		gotoxy(c,b);printf("\xbb");
		gotoxy(a,d);printf("\xc8");
		gotoxy(c,d);printf("\xbc");
}

void welcome_message(void)
{
gotoxy(40,20);
    box(33,20,118,39);//outer box
    box(42,25,110,35);//inner box
    gotoxy(63,30);
    printf("WELCOME TO PAYROLL MANAGEMENT SYSTEM");

    gotoxy(90,38);
	printf("Press Enter to continue\n\n\n");
	gotoxy(115,38);
	getchar();


}
void get_password()
//admin login

{
char log_n[50],password[50],ch;
int i=0;
login_info:
   {

system("cls");
box(33,15,118,39);
gotoxy(48,20);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Welcome to the Admin Login Page  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n\n");

       gotoxy(38,25);
       printf(" Admin login");

   gotoxy(39,28);
    printf("User name: ");
    fflush(stdin);
    box(50,27,75,29);
    gotoxy(52,28);
	gets(log_n);
	gotoxy(39,31);
	printf("Password: ");
	fflush(stdin);
	box(50,30,75,32);
	gotoxy(52,31);
	//gets(password);

     while(1)
     {
      ch = getchar();
      if(ch== ENTER)
      {
        password[i]='\0';
        break;
      }
      else if(ch==BKSP)
      {
        if(i>0)
        {
          i--;
          printf("\b \b");
        }
      }
      else if(ch==TAB||ch==SPACE)
      {
        continue;
      }
      else{
        password[i]=ch;
        i++;
        printf("*");

   }
     }}

if ((strcmp(log_n,login)==0)&&(strcmp(password,pw)==0))
    {
        gotoxy(39,35);
        printf("LOGIN IS SUCCESSFULL...");
    }
    else
    {
        gotoxy(39,34);
       printf("Incorrect login information!!Please try again.");
       gotoxy(39,36);
       printf("Press Enter key ");
       getchar();
        goto login_info;//to re-enter valid login info.
    }
 gotoxy(37,37);
printf("Enter any key to continue");
	getchar();

}


void emp_menu()
//main menu code
{
menu:{
    int option;
do
    {
system("cls");
     fflush(stdin);
     box(33,15,118,39);
     gotoxy(57,18);
     printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

	gotoxy(40,25);
	printf("\xDB\xDB\xDB\xDB\xB2  1 : Add Employee");
	gotoxy(40,27);
	printf("\xDB\xDB\xDB\xDB\xB2  2 : Display Employee");
	gotoxy(40,29);
	printf("\xDB\xDB\xDB\xDB\xB2  3 : Edit Employee");
	gotoxy(40,31);
	printf("\xDB\xDB\xDB\xDB\xB2  4 : Delete Employee");
	gotoxy(40,33);
	printf("\xDB\xDB\xDB\xDB\xB2  5 : Exit Employee");
	gotoxy(40,36);
    printf("Choose the option:\n");
    gotoxy(60,36);
    scanf("%d",&option);
fflush(stdin);

    switch(option)
		{
			case 1:
			{
				add_employee();
				break;
			}

			case 2:
                {
                    display();

                    break;
                }


            case 3:{ edit_employee();
               break;
               }
               case 4:
                {
                    delete_employee();
                    break;
                }
                case 5:
                {
                    system("cls");
                   printf("You have chosen to exit.\n\n");
                  printf("Exiting the system...\n\n");
                  exit(0);
                       }


			default:
			    gotoxy(40,37);
			    printf("Invalid choice! Press enter to go back to menu.");
			    getchar();
			    goto menu;

			    //exit(0);

            }

} while(option!=60);
}

}
void add_employee()
{
    system("cls");
    char name[50];
	char address[100],designation[100],sex[50];
	char phone[11];
	char id1[5],id[5];
    float age;
	float salary;
	float  h1,h2,h3,h4,h5,h6,h7;
	FILE *fp,*fp1;
	fp = fopen("d:\\emp.txt", "a");
	printf("\n\n\nYou haven chosen option to add Employee:\n\n");
	printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	printf("\n-----------------------------------------------------------------------------------------------------------\n");

fp1 = fopen("d:\\emp.txt","r");
	enter_id:
	{

	printf("\nEmployee's ID: ");
	fflush(stdin);
	gets(id1);


// validation of id

do  {
 // opening file in read mode for checking and restricting id duplication
check:
 {
      if (strlen(id1)==0  )
    {
      printf("Invalid format. Enter again.\n ");
  			goto enter_id;
    }

int i =0;
    while (id1[i] != '\0')
  	{
  		if( (id1[i] >= 'a' && id1[i] <= 'z') || (id1[i] >= 'A' && id1[i] <= 'Z') ) // restricting for alphabet
  		{
  			printf("Invalid\n ");
  			goto enter_id;
 		}
  		else if (id1[i] >= '0' && id1[i] <= '9') //must only contain numeric value

  		{
  			i++;
  		}

        else

        {
            printf("Invalid.\n");// restricting special character
            goto enter_id;
        }


  	}
fscanf(fp1, "%[^/]%*c%[^/]%*c%[^/]%*c%[^/]%*c%[^/]%*c%[^/]%*c %f %f %f %f %f %f %f %f %f%*c",name, address, phone, id,designation,sex,&age, &salary,&h1,&h2,&h3,&h4,&h5,&h6,&h7);
 if(feof(fp1))
		{

			break;
		}
if(strcmp(id,id1)==0)
//restricting dupliction of id
{
printf("\nID already exists. Enter unique ID: ");
fflush(stdin);
gets(id1);
rewind(fp1);
goto check;
}

}

}while(!(feof(fp1)));
	}
fclose(fp1);
strcpy(id,id1);


enter_name:
    // name validation
{
    printf("\n Name: ");
	fflush(stdin);
	gets(name);


      if (strlen(name)==0  )
    {
      printf("Invalid format. Enter again.\n ");
  			goto enter_name;
    }
	int i =0;
    while (name[i] != '\0')
  	{
  	    //int sp = isspace( name[i]);
  		if( (name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'A' && name[i] <= 'Z') )
  		{
  			i++;
 		}
  		else if (name[i] >= '0' && name[i] <= '9')

  		{

  			printf("Invalid\n ");
  			goto enter_name;
  		}

        else if (name[i] == ' ')
        {
            i++;
        }
       else

        {
            printf("Invalid.\n");
            goto enter_name;
        }


  	}
}
 enter_des:
{
    printf("Designation: ");
	fflush(stdin);
	gets(designation);
	if (strlen(designation)==0  )
    {
      printf("Invalid format. Enter again.\n ");
  			goto enter_des;
    }
int i =0;
    while (designation[i] != '\0')
  	{
  	    int sp_des = isspace( designation[i]); // returns non zero integer if  white space is present
  		if( (designation[i] >= 'a' && designation[i] <= 'z') || (designation[i] >= 'A' && designation[i] <= 'Z') )
  		{
  			i++;
 		}
  		else if ((designation[i] >= '0' && designation[i] <= '9') || (sp_des!=0))

  		{

  			printf("Invalid\n ");
  			goto enter_des;
  		}

        else if (designation[i] == ' ')
        {
            i++;
        }
       else

        {
            printf("Invalid.\n");
            goto enter_des;
        }


  	}
}

    enter_address:
        {
    printf("Address: ");
	fflush(stdin);
	gets(address);
	if (strlen(address)==0  )
    {
        //address validation
      printf("Invalid format. Enter again.\n ");
  			goto enter_address;
    }
        }
enter_sex:
    {
	    printf("Sex (f/m) :  ");
	fflush(stdin);
	//strcpy(sex, sex_ver( ));
	gets(sex);
	if (strlen(sex)==0  )
    {
        // validation of sex
      printf("Invalid format. Enter again.\n ");
  			goto enter_sex;
    }
int i =0;

    while (sex[i] != '\0')
  	{
  	     int sp_s = isspace( sex[i]);
  		if( (sex[i] >= 'a' && sex[i] <= 'z') || (sex[i] >= 'A' && sex[i] <= 'Z') )
  		{
  			if((sex[i] == 'm' || sex[i] == 'f') && (strlen(sex)==1))
            {
        i++;
            }
            else
  			{
  			     printf("Invalid. Enter f( for female) and m( for male).\n");
                goto enter_sex;
 		}
  		}
  		else if ((sex[i] >= '0' && sex[i] <= '9') || (sp_s!=0))

  		{

  			printf("Invalid. Enter m (male) or f (female)\n ");
  			goto enter_sex;
  		}


       else

        {
            printf("Invalid. Enter m (male) or f (female)\n");
            goto enter_sex;
        }
      }
    }

re:
	{
	    printf("Age: ");
	fflush(stdin);
	 age=scan();// for validation of age

	if (age<18 || age>60)
    {
        printf("Invalid age. Enter again.\n");
        goto re;
    }

	}

	enter_ph:
	    //phone number validation
	{
	    printf("Phone: ");
	fflush(stdin);
	gets(phone);
	int i =0;
    while (phone[i] != '\0')
  	{
  		if( (phone[i] >= 'a' && phone[i] <= 'z') || (phone[i] >= 'A' && phone[i] <= 'Z') )
  		{
  			printf("Invalid\n ");
  			goto enter_ph;
 		}
  		else if (phone[i] >= '0' && phone[i] <= '9' )

  		{
  			i++;
  		}

        else

        {
            printf("Invalid.\n");
            goto enter_ph;
        }
  	}
  	if(strlen(phone)!=10)
    {
       printf("Invalid format. Enter 10 numbers (eg.9841402565)\n") ;
       goto enter_ph;
    }

	}

	printf("Salary (weekly): ");
	fflush(stdin);
	salary = scan(); // salary validation
	printf(" Worked Hours:\n ");

ent_sun:
    {
        printf("Sun: ");
	fflush(stdin);
	h1=scan();// validation
if(h1>24)
{
    printf("Invalid hours.\n");
    goto ent_sun;
}
    }

    ent_mon:
    {

printf("Mon: ");
	fflush(stdin);
	h2=scan();
	if(h2>24)
{
    printf("Invalid hours.\n");
    goto ent_mon;
}
}
ent_tue:
{
printf("Tue: ");
	fflush(stdin);
	h3=scan();
	if(h3>24 )
{
    printf("Invalid hours.\n");
    goto ent_tue;
}}

  ent_wed:
  {
    printf("Wed:");
	fflush(stdin);
	h4=scan();
	if(h4>24)
{
    printf("Invalid hours.\n");
    goto ent_wed;
}
  }
ent_thu:
{printf("Thu: ");
	fflush(stdin);
    h5=scan();
    if(h5>24)
{
    printf("Invalid hours.\n");
    goto ent_thu;
}
}
ent_fri:
{printf("Fri: ");
	fflush(stdin);
	h6=scan();
	if(h6>24)
{
    printf("Invalid hours.\n");
    goto ent_fri;
}}
ent_sat:
    {printf("Sat: ");
	fflush(stdin);
	h7=scan();
	if(h7>24)
{
    printf("Invalid hours.\n");
    goto ent_sat;
}}
fprintf(fp, "%s/%s/%s/%s/%s/%s/%.1f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f\n", name,address,phone,id,designation,sex,age,salary,h1,h2,h3,h4,h5,h6,h7);
	fflush(fp);
	fclose(fp);
	printf("\n-------------------------------------------------------------------------------------------\n");
	printf("Done Entering New Record >>>\n ");
		printf("\nPress any key.......");
	getchar();

}

void display()

{
system("cls");
char name[50];
	char address[100],designation[100],sex[50];
	char phone[11];
	char id[5];
	char idSearch[5];
	float salary,wk,rate,OT,NS,age,UT,DR;
	float h1,h2,h3,h4,h5,h6,h7;
	FILE *fp;
	fp = fopen("d:\\emp.txt","r");
	printf("\n\n\nYou haven chosen option to Display Employee\n\n");
	printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
printf("\n\nEnter the Employee ID to Search :");
	fflush(stdin);
	gets(idSearch);
do
	{

fscanf(fp, "%[^/]%*c%[^/]%*c%[^/]%*c%[^/]%*c%[^/]%*c%[^/]%*c %f %f %f %f %f %f %f %f %f%*c",name, address, phone, id,designation,sex,&age, &salary,&h1,&h2,&h3,&h4,&h5,&h6,&h7);
if(feof(fp))
		{
			printf("\nID is not found!\n\n");
			break;
		}
if((strcmp(id,idSearch)) == 0)
{

printf("\n\n--------------  Displaying records of Employee ID %s  -------------------------\n",id);
printf("\n\nID: %s\t\t\tName: %s\t\t\t\tAddress: %s \t\tAge:%.1f yr\n\n",id,name,address,age);

printf("Sex: %s\t\t\tPhone: %s\t\t\t\tDesignation: %s\n\n",sex,phone,designation);
printf("Salary: Rs %.2f\n\n",salary);
	printf("-----------------------------------------\n");
	printf("Working hours:\n\n");
    printf("Sun: %.2f\n",h1);
   printf("Mon: %.2f\n",h2);
    printf("Tue: %.2f\n",h3);
     printf("Wed: %.2f\n",h4);
	printf("Thu: %.2f\n",h5);
	printf("Fri: %.2f\n",h6);
printf("Sat: %.2f\n",h7);
wk=h1+h2+h3+h4+h5+h6+h7;
printf("\nTotal worked=%.2f hr",wk);
printf("\n-----------------------------------------\n");
printf("\t\tSalary calculation\n\n"),
printf("Salary: Rs %.2f\n", salary);
 if(wk>=42)
{
    OT=wk-42;
    printf("Overtime done in the week = %.2f hr\n",OT);
    rate=salary/(7*7);   //salary of one hour
    NS=salary+(rate*OT);
     printf("-----------------------------------------\n");
  printf("\nNet salary (weekly)= Rs %.2f\n",NS);
  printf("-----------------------------------------\n");


}
else
{
    UT=42-wk;
    rate=salary/(7*7);
    DR=UT*rate;
    NS=salary-(DR);
    printf("Salary of %.2f hr has been deduced due to incomplete working hours.\n",UT);
printf("-----------------------------------------\n");

    printf("Net salary(weekly)= Rs %.2f\n\n",NS);
printf("-----------------------------------------\n\n");
}
break;
}
}while(!(feof(fp)));


printf("\nPress any key ");

	getchar();
	fclose(fp);
}


void edit_employee(void)
{
	system("cls");
	char name[50];
	char address[100],designation[100],sex[50];
	char phone[11];
	char id[5];
	char ch,choice;
	char idEdit[5];
	float salary,age;
	float  h1,h2,h3,h4,h5,h6,h7,wk;
	FILE *fp1;
	FILE *fp2;
	fp1 = fopen(EMP_FILE, "r");
	fp2 = fopen(TMP_FILE, "w");
    printf("\n\n\nYou haven chosen option to Edit Employee\n\n");
	printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	printf("\n\n\nEnter Employee ID to Edit : ");
	fflush(stdin);
	gets(idEdit);
	do
	{
		fscanf(fp1,"%[^/]%*c%[^/]%*c%[^/]%*c%[^/]%*c%[^/]%*c%[^/]%*c %f %f %f %f %f %f %f %f %f%*c",name, address, phone, id,designation,sex,&age, &salary,&h1,&h2,&h3,&h4,&h5,&h6,&h7);
    if(feof(fp1))
		{

			break;
		}
		if((strcmp(id, idEdit)) == 0)
		{


		    printf("\n\nDisplaying old records of the searched ID:\n");
		    printf("-----------------------------------------\n");
		    printf("Name: %s\n", name);
			printf("Address: %s\n", address);
			printf("Phone: %s\n", phone);
			printf("ID: %s\n", id);
			printf("Designation: %s\n",designation);
			printf("Sex: %s\n",sex);
			printf("Age: %.1f yr",age);
			printf("\nSalary (weekly): Rs %.2f\n", salary);
			printf("-----------------------------------------\n");
            printf("\nWorking hours:\n\n");
        printf("Sun: %.2f\n",h1);
        printf("Mon: %.2f\n",h2);
        printf("Tue: %.2f\n",h3);
        printf("Wed: %.2f\n",h4);
	    printf("Thu: %.2f\n",h5);
	    printf("Fri: %.2f\n",h6);
        printf("Sat: %.2f\n",h7);
        wk=h1+h2+h3+h4+h5+h6+h7;
        printf("\nTotal worked = %.2f hr",wk);

printf("\n-----------------------------------------\n\n");
printf("\n-->Enter y to Edit worked hours only");
printf("\n-->Enter any other key to Edit other records\n");
choice=getchar();
if(choice=='y')
{
printf("\nEnter new Worked Hours:\n ");
ent_sun:
    {
        printf("Sun: ");
	fflush(stdin);
	h1=scan();// validation
if(h1>24)
{
    printf("Invalid hours.\n");
    goto ent_sun;
}
    }

    ent_mon:
    {printf("Mon: ");
	fflush(stdin);
	h2=scan();
	if(h2>24)
{
    printf("Invalid hours.\n");
    goto ent_mon;
}
}
ent_tue:
{
printf("Tue: ");
	fflush(stdin);
	h3=scan();
	if(h3>24 )
{
    printf("Invalid hours.\n");
    goto ent_tue;
}}

  ent_wed:
  {
    printf("Wed:");
	fflush(stdin);
	h4=scan();
	if(h4>24)
{
    printf("Invalid hours.\n");
    goto ent_wed;
}
  }
ent_thu:
{printf("Thu: ");
	fflush(stdin);
    h5=scan();
    if(h5>24)
{
    printf("Invalid hours.\n");
    goto ent_thu;
}
}
ent_fri:
{printf("Fri: ");
	fflush(stdin);
	h6=scan();
	if(h6>24)
{
    printf("Invalid hours.\n");
    goto ent_fri;
}}
ent_sat:
    {printf("Sat: ");
	fflush(stdin);
	h7=scan();
	if(h7>24)
{
    printf("Invalid hours.\n");
    goto ent_sat;
}}
}
else
{
printf("\nEmployee's Id :%s\n",id);
enter_name:
    // name validation
{
    printf("\n Name: ");
	fflush(stdin);
	gets(name);


      if (strlen(name)==0  )
    {
      printf("Invalid format. Enter again.\n ");
  			goto enter_name;
    }
	int i =0;
    while (name[i] != '\0')
  	{
  	    //int sp = isspace( name[i]);
  		if( (name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'A' && name[i] <= 'Z') )
  		{
  			i++;
 		}
  		else if (name[i] >= '0' && name[i] <= '9')

  		{

  			printf("Invalid\n ");
  			goto enter_name;
  		}

        else if (name[i] == ' ')
        {
            i++;
        }
       else

        {
            printf("Invalid.\n");
            goto enter_name;
        }


  	}
}
 enter_des:
{
    printf("Designation: ");
	fflush(stdin);
	gets(designation);
	if (strlen(designation)==0  )
    {
      printf("Invalid format. Enter again.\n ");
  			goto enter_des;
    }
int i =0;
    while (designation[i] != '\0')
  	{
  	    int sp_des = isspace( designation[i]); // returns non zero integer if  white space is present
  		if( (designation[i] >= 'a' && designation[i] <= 'z') || (designation[i] >= 'A' && designation[i] <= 'Z') )
  		{
  			i++;
 		}
  		else if ((designation[i] >= '0' && designation[i] <= '9') || (sp_des!=0))

  		{

  			printf("Invalid\n ");
  			goto enter_des;
  		}

        else if (designation[i] == ' ')
        {
            i++;
        }
       else
{
            printf("Invalid.\n");
            goto enter_des;
        }
}
}
   enter_address:
        {
    printf("Address: ");
	fflush(stdin);
	gets(address);
	if (strlen(address)==0  )
    {
        //address validation
      printf("Invalid format. Enter again.\n ");
  			goto enter_address;
    }
        }
enter__sex:
    {
	    printf("Sex (f/m) :  ");
	fflush(stdin);
	gets(sex);
	//strcpy(sex, sex_ver( ));
	if (strlen(sex)==0  )
    {
        // validation of sex
      printf("Invalid format. Enter again.\n ");
  			goto enter__sex;
    }

int i =0;
    while (sex[i] != '\0')
  	{
  		if( (sex[i] >= 'a' && sex[i] <= 'z') || (sex[i] >= 'A' && sex[i] <= 'Z') )
  		{
  			if((sex[i] == 'm' || sex[i] == 'f') && (strlen(sex)==1))
            {
        i++;
            }
            else
  			{
  			     printf("Invalid. Enter f( for female) and m( for male).\n");
                goto enter__sex;
 		}
  		}
  		else if (sex[i] >= '0' && sex[i] <= '9')

  		{
  		    printf("Invalid. Enter m (male) or f (female)\n ");
  			goto enter__sex;
  		}
      else
         {
            printf("Invalid. Enter m (male) or f (female)\n");
            goto enter__sex;
        }
      }
    }

re:
	{
	    printf("Age: ");
	fflush(stdin);
	 age=scan();// for validation of age

	if (age<18 || age>60)
    {
        printf("Invalid age. Enter again.\n");
        goto re;
    }

	}

	enter_ph:
	    //phone number validation
	{
	    printf("Phone: ");
	fflush(stdin);
	gets(phone);
	int i =0;
    while (phone[i] != '\0')
  	{
  		if( (phone[i] >= 'a' && phone[i] <= 'z') || (phone[i] >= 'A' && phone[i] <= 'Z') )
  		{
  			printf("Invalid\n ");
  			goto enter_ph;
 		}
  		else if (phone[i] >= '0' && phone[i] <= '9' )

  		{
  			i++;
  		}

        else

        {
            printf("Invalid.\n");
            goto enter_ph;
        }
  	}
  	if(strlen(phone)!=10)
    {
       printf("Invalid format. Enter 10 numbers (eg.9841402565)\n") ;
       goto enter_ph;
    }

	}
    printf("Salary (weekly): ");
	fflush(stdin);
	salary = scan(); // salary validation
	printf(" Worked Hours:\n ");

ent_sund:
    {
        printf("Sun: ");
	fflush(stdin);
	h1=scan();// validation
if(h1>24)
{
    printf("Invalid hours.\n");
    goto ent_sund;
}
    }
ent_mond:
    {
printf("Mon: ");
	fflush(stdin);
	h2=scan();
	if(h2>24)
{
    printf("Invalid hours.\n");
    goto ent_mond;
}
}
ent_tued:
{
printf("Tue: ");
	fflush(stdin);
	h3=scan();
	if(h3>24 )
{ printf("Invalid hours.\n");
    goto ent_tued;
}}

  ent_weda:
  {
    printf("Wed:");
	fflush(stdin);
	h4=scan();
	if(h4>24)
{
    printf("Invalid hours.\n");
    goto ent_weda;
}
  }
ent_thud:
{printf("Thu: ");
	fflush(stdin);
    h5=scan();
    if(h5>24)
{
    printf("Invalid hours.\n");
    goto ent_thud;
}
}
ent_frid:
{printf("Fri: ");
	fflush(stdin);
	h6=scan();
	if(h6>24)
{
    printf("Invalid hours.\n");
    goto ent_frid;
}}
ent_satd:
    {printf("Sat: ");
	fflush(stdin);
	h7=scan();
	if(h7>24)
{
    printf("Invalid hours.\n");
    goto ent_satd;
}}
}
		}
fprintf(fp2,"%s/%s/%s/%s/%s/%s/%.1f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f\n", name,address,phone,id,designation,sex,age,salary,h1,h2,h3,h4,h5,h6,h7);
}while(!(feof(fp1)));
fclose(fp1);
fclose(fp2);
fp1=fopen(EMP_FILE,"w");
fp2=fopen(TMP_FILE,"r");
	while((ch=fgetc(fp2))!=EOF)
    {
                fputc(ch,fp1);
    }
fflush(fp2);
fclose(fp2);
fclose(fp1);
printf("\n<<<<Editing is completed.>>>>\n\n");
printf("Enter any key ");
getchar();

}

//delete employee
void delete_employee()
{
    system("cls");
	char name[50];
	char address[100],designation[100],sex[50];
	char phone[11];
	char id[5];
	char idDel[5];
char ch;
	float age,salary;
	float  h1,h2,h3,h4,h5,h6,h7;
	FILE *fp1;
	FILE *fp2;
	fp1 = fopen(EMP_FILE, "r");
	fp2 = fopen(TMP_FILE, "w");
	printf("\n\n\nYou haven chosen option to Delete Employee\n\n");
	printf("\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	printf("\n\nEnter Employee ID to Delete : ");
	fflush(stdin);
	gets(idDel);

	do
	{
		fscanf(fp1,"%[^/]%*c%[^/]%*c%[^/]%*c%[^/]%*c%[^/]%*c%[^/]%*c %f %f %f %f %f %f %f %f %f%*c",name, address, phone, id,designation,sex,&age, &salary,&h1,&h2,&h3,&h4,&h5,&h6,&h7);

		if(feof(fp1))
		{

			break;
		}
		if((strcmp(id, idDel)) != 0)
		{
			fprintf(fp2,"%s/%s/%s/%s/%s/%s/%.1f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f\n", name,address,phone,id,designation,sex,age,salary,h1,h2,h3,h4,h5,h6,h7);
		}



	}while(!(feof(fp1)));

	fclose(fp2);
	fclose(fp1);

fp1=fopen(EMP_FILE,"w");
fp2=fopen(TMP_FILE,"r");
	while((ch=fgetc(fp2))!=EOF)
    {
                fputc(ch,fp1);
    }

	printf("\nID has been deleted!");
fflush(fp2);
fclose(fp2);
fclose(fp1);
	printf("\npress any key.......");
	getchar();


}

//function to validate and check for numeric values only
int scan()
 {
   float val;
   char str[20];


    enter_sc:
        {

    gets(str);
    if (strlen(str)==0)
    {
      printf("Invalid format. Enter again: ");
  			goto enter_sc;
    }

int i =0;
while (str[i] != '\0')
        {

  		if( (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') )
  		{
  			printf("Invalid format. Enter again: ");
  			goto enter_sc;
 		}
  		else if ((str[i] >= '0' && str[i] <= '9') || (str[i]=='.'))

  		{
  			i++;
  		}

        else
          {
            printf("Invalid format. Enter again:");
            goto enter_sc;
        }

   }
        }

   val = atof(str); //converting string into float
   return(val);

}











