#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;
class customer{
	protected:
		string c_name;
		string c_num;
		
	public:
		customer(){}
		
		customer(string na,string nu)
		{
			c_name=na;
			c_num=nu;
		}
	virtual void set_data()=0;	
};

class book{
	public:
		
		string b_name[10];
		int b_prize[10];	
		book(){}

};

class online:public customer,public book {
	private:
		string cnic;
		string city_name;
		string debit_card;
		
	public:
		string date;
		int quantity;
		online(){}	//null constructor
	void check_profit()
	{
		string check_date;
		int sum=0,var=0;
		cout<<"Enter the particular date to find the profit of that day: ";
		cin>>date;
		fstream pro;
		pro.open("profit_online_record.txt,ios::app");
		while(pro>>check_date)
		{
			if(check_date==date)
			{
				;
			}
		}
	}				
	void set_data()
	{
		int count=0,c=0;
		int i=0;
		int i_j=0;	
		fstream input;
		input.open("online_record.txt",ios::app);
		fstream profit;
		profit.open("profit_online_record.txt",ios::app);
		cout<<"Enter the Date: ";
		getline(cin,date);
		fflush(stdin);
		cout<<"Enter customer name: ";
		getline(cin, c_name);
   		fflush(stdin);
		cout<<"Enter customer number: ";
		getline(cin, c_num);
		cout<<"Enter number of books: ";
		cin>>quantity;
			
		while(quantity!=0)
		{
			fflush(stdin);
			ifstream r;
			r.open("books names.txt",ios::app);	
			string check;
			cout<<"Enter book  name "<<i+1<< ": ";
			cin>>b_name[i];
			while(r>>check)
			{
				
			if(b_name[i]==check)
			{
				if(i_j==0)		//it will save customer  infomation only for once
				{
						input<<date<<"  "<<c_name<<"  "<<c_num<<"  ";						
						profit<<date<<"  ";
				}
				i_j++;
				c++;
				count++;
				fflush(stdin);
				cout<<"Enter prize of the book " <<i+1<< ":  ";
				cin>>b_prize[i];
				profit<<b_prize[i]<<"  ";
				fflush(stdin);
				i++;
				break;			
			}
			
			}
			quantity--;
			if(check=="*"){
				cout<<"Book Not Available..\n";
				if (c>=1 && quantity==0)
				{
					goto n;
				}
				else if (count==0 && quantity==0)
				{
					r.close();
					goto x;
				}
			}
			
			count=0;
			
			r.close();
			
			
		}
		n:
			input<<i_j;
			for(i=0;i<i_j;i++)
			{	
			input<<"  "<<b_name[i]<<"  "<<b_prize[i];
		}
		cout<<"Enter Cnic:  ";
		cin>>cnic;
		cout<<"Enter City Name:  ";
		cin>>city_name;
		cout<<"Enter Debit Card Number:  ";
		cin>>debit_card;
		input<<"  "<<cnic<<"  "<<city_name<<"  "<<debit_card<<"  "<<endl;
		cout<<"Record is successfully added..!\n";
		x:
		input.close();
		fflush(stdin);
string x;
cout<<"Press Enter to continue..!\n";
getline(cin,x);
if(x!="0")
{
	system("cls");
}

	}
	};
class by_hand:public customer,public book {		
	public:
		string date;
		int quantity;
		by_hand(){}		
		
	void set_data()
	{
		ofstream input;
		input.open("by_hand_record.txt",ios::app);
		int i=0,sum=0;
		cout<<"Enter the Date: ";
		getline(cin,date);
		fflush(stdin);
		cout<<"Enter customer name: ";
		getline(cin, c_name);
		cout<<"Enter customer number: ";
		getline(cin, c_num);	
		cout<<"Enter number of books: ";
		cin>>quantity;
			string check;
			int j=1;
		while(quantity!=0)
		{
			cout<<"Enter book  name "<<j<< ": ";
			
			ifstream r;
			r.open("books names.txt");
			cin>>b_name[i];
			while(r>>check)
			{
			
			if(b_name[i]==check)
			{
				if (i==0)
				{
					input<<date<<"  "<<c_name<<"  "<<c_num<<"  ";
				}
				cout<<"Enter prize of the book " <<j<< ":  ";
				cin>>b_prize[i];
				i++;
				break;
			}
			}
			j++;
			if(check=="*"){
				cout<<"Not Available..\n";
			}
			quantity--;
			r.close();
			}
		if(i>0)
		input<<i;
		for(j=0;j<i;j++)
		{
			input<<"  "<<b_name[j]<<"  "<<b_prize[j];
			sum=sum+b_prize[j];
		}
		if(i>0)
		{
			cout<<"\nYour total bill is:  "<<sum<<endl;
			cout<<"Record is successfully added..!\n";
		}
		input<<endl;
		input.close();
		fflush(stdin);	
		string x;
cout<<"Press Enter to continue..!\n";
getline(cin,x);
if(x!="0")
{
	system("cls");
}

	}
};

int main()
{
	int choice,j=1;
	string date,dummy;
do{

	
		cout<<("Enter your choice:\n");
   		cout<<("press 1 to Enter the Record:\n");
 		cout<<("press 2 to Check the Previous Record:\n");
  		cout<<("press 3 to check the profit:\n");
		  cout<<("Press 0 for Exit:\n");
   		cin>>choice;
   		fflush(stdin);
   	switch(choice)
   {
		case 0:
			cout<<"Thank YOu..!!";
			exit(0);
			break;
		case 1:
   		int choice2;
	   	cout<<("Enter the Type of purchase\n");
        cout<<("Press 1 for online.\nPress 2 for through hand.\n");
 		cin>>choice2;
		 	if(choice2==1)
			 {
			 	fflush(stdin);
			 	online o;
			 	o.set_data();
							 	
				 }
			else if(choice2==2)
			{
				fflush(stdin);
				by_hand h;
				h.set_data();
			
			}	 	
		break;
	case 2:
		cout<<"Enter the Date ";
		getline(cin,date);
		ifstream search;
		search.open("online_record.txt",ios::in);
		while (search>>dummy)	
		{
				if(date==dummy)
				{	
					search>> dummy;
					cout<<"Customer name is: ";
					cout<<dummy<<endl;
					search>> dummy;
					cout<<"customer number is: ";
					cout<<dummy<<endl;
					cout<<"BOOK information\n";
					search>> dummy;
					char a=dummy[0];
					 j=1;
					for(char i='0';i<a;i++)
					{
						cout<<"Name of book "<<j<<" is: ";
						search>>dummy;
						cout<<dummy<<endl;
						cout<<"prize of book "<<j<<" is: ";
						search>>dummy;
						cout<<dummy<<endl;
						j++;
					}
					cout<<"NIC of the customer is:  ";
					search>>dummy;
					cout<<dummy<<endl;
					cout<<"City Name is:  ";
					search>>dummy;
					cout<<dummy<<endl;
					cout<<"Debit card number is:  ";
					search>>dummy;
					cout<<dummy<<endl;
					cout<<"\n\n\n";
				}
				else 
				{
					getline(search,dummy);
				}
		}
		search.close();
				
		ifstream search2;
		search2.open("by_hand_record.txt",ios::in);
		while (search2>>dummy)	
		{
				if(date==dummy)
				{	
					search2>> dummy;
					cout<<"Customer name is: ";
					cout<<dummy<<"\n";
					search2>> dummy;
					cout<<"customer number is: ";
					cout<<dummy<<endl;
					cout<<"BOOK information\n";
					search2>> dummy;
					char a,i;
					a=dummy[0];
					 j=1;
					for( i='0';i<a;i++)
					{
						cout<<"Name of book "<<j<<" is: ";
						search2>>dummy;
						cout<<dummy<<endl;
						cout<<"prize of book "<<j<<" is: ";
						search2>>dummy;
						cout<<dummy<<endl;
						j++;
					}
				}
					else 
					{
						getline(search2,dummy);
					}
	}
				search2.close();
					if(j==1)
				{
				cout<<"Record not found...!!\n";
				}
				j=1;	
				fflush(stdin);
				string x;
				cout<<"\nPress Enter to continue..!\n";
				getline(cin,x);
				if(x!="0")
				system("cls");
	    		break;
				  
		}

}while(choice!=0);
}
