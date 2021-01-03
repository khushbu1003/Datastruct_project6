

//************************************  PROGRAM IDENTIFICATION  ***************************************
//*                                                                                                   *
//*   PROGRAM FILE NAME:  Source1.cpp          ASSIGNMENT #:  6             Grade: _________          *
//*                                                                                                   *
//*   PROGRAM AUTHOR:                                                                                 *
//*                   ___________________________________________________                             *
//*                                   Khushbu Shah                                                    *
//*                                                                                                   *
//*   COURSE #:  CSC 24400 11                              DUE DATE: December 6, 2019                 *
//*                                                                                                   *
//*****************************************************************************************************

//***********************************  PROGRAM DESCRIPTION  *******************************************
//*                                                                                                   *
//*   PROCESS: This program is designed to show five divisions and headquarters, it uses one class    * 
//*		         and about 10 functions to getdata and print it in a correct form, there are          * 
//*              about five objects with division one to five and headquarters too.each division      *
//*              has its account Id number, credit, debit and total balance.Task is to print          *
//*              details and update the statments whenever needed and add it up at the end to         *
//*              print the entire summary with using printdata function.                              *
//*   USER DEFINED                                                                                    *
//*    MODULES    : class Employeeclass- it has private data types and pointers pointing              *
 //                  to the object.It has contrutor by default as well as with parameter              * 
//*                  it has all other inline and fascilator functions with the same class.            *
//*                  these all will be called in main function as well with declaration.              *
//*		             dataFunctioning- It gets the data from Inputfile-Data6.txt and set it in loop    *
//*		             setdata - Sets data for variables declared from private in class	              *
//*		             getID- it gets the credit amount into this function.     		                  *
//*		             getfirstname - It gets the debit amount into the function.                       *
//*                  getlastname - It gets the corresponding balance to the function to use           *  
//*                  getdepartment- It gets the name of the department to read in                     *
//*                  getTitile-  It gets the name of Title to read in                                 *
//*                  updateId-       It reset new ID with the old one                                 *
//*                  updatefirstName- this function will reset the firstname for each objects         * 
//*                  updateLastname- this function will reset the Lastname for each objects           *
//*                  updatePayment- It will update the payment information                            *
//*                  addcomma - It will addcoma in appropriate place as needed                        *
//*                  sorting-  Keep objects sorted from high to low ID number                         *
//*                  and deduct the debit amount from the balance.                                    *
//*                  Printdata- this will output the values under each catagory according to          *
//*                              the conditions while reading the type character                      *
//*					 PrintfullData- this will be used to print final output after adding or           *
//*                                 subtracting the credit/debit balance                  		      *
//*****************************************************************************************************


//preprocessor directives
#include <iostream>                    //for output and Input streams
#include<string>                       // to Insert thie string
#include<iomanip>                      //to formate the output
#include<fstream>                      //for inserting a file and outputting it

using namespace std;                   //namespace to use in program

//prototypes

void Header(ofstream& outfile1);       //calling of function header
void Footer(ofstream& outfile1);       //calling of function footer
struct EmployeeInfo                    //this holds Data types
{
	int ID;                      //to read in the IDs
	char FirstName[15];           //holds firstname
	char LastName[15];            //holds Last name
	char Department[17];          //department type
	char Title[17];               //holds position title
	float pay;                     //floating amount for payment


};

class EmployeeClass
{
private:
	EmployeeInfo Employee;      //calling from definition of struct

public:
	
	
	
	//constructor function param type
	EmployeeClass(int ID, char[], char[], char[], char[], float pay);     //param function    
	EmployeeClass(void);                                                 //Default function
	void setdata(int, char[], char[], char[], char[], float);            //sets data with param
	int getID() { return Employee.ID; }                                 //return ID of the obj
	char* getFirstname() { return Employee.FirstName; }                  //return firstname of the obj
	char* getLastname() { return Employee.LastName; }                   //return lastname of the obj
	char* getDepartment() { return Employee.Department; }               //returns the name of depart
	char* getTitle() { return Employee.Title; }                         //returns the title of obj

	void updateFirstName(char[]);        //replaces the first name with new name
	void updateLastname(char[]);         //replaces the lastname with new name
	void updateDepartment(char[]);       //replace the department with new one
	void updateTitle(char[]);            // replace the title with new title
	void updatePayment(float);           //replace the payment information 
	void addcomma(ofstream&);           // for high number add commas in output
	void sorting(EmployeeClass[]);            //sorts the object

	void print(ofstream&);                             //printing to outfile only
	float getPay() { return Employee.pay; }             //inline func return payment
	void dataFunctioning(ifstream&, ofstream&, EmployeeClass[]);        // take input in and output the result
	

};

//*********************************************************************************************************

//*******************************************FUNCTION UPDATEFIRSTNAME**************************************

void EmployeeClass::updateFirstName(char temp[])
{
	//Receives - first name from file
	// task - swap it with new one
	// Returns - New firstname
	strcpy_s(Employee.FirstName, temp);       //update the first name

}
//*********************************************************************************************************

//*******************************************FUNCTION UPDATELASTNAME***************************************

void EmployeeClass::updateLastname(char temp[])
{
	//Receives - first name from file
	// task - swap it with new one
	// Returns - New lastname
	strcpy_s(Employee.LastName, temp);      //swap it with new name

}
//*********************************************************************************************************

//*******************************************FUNCTION UPDATEDEPARTMENT**************************************

void EmployeeClass::updateDepartment(char temp[])
{
	//Receives - first name from file
	// task - swap it with new one
	// Returns - New department
	strcpy_s(Employee.Department, temp);     //swap it with new depart

}
//*********************************************************************************************************

//*******************************************FUNCTION UPDATETITLE**************************************
void EmployeeClass::updateTitle(char temp[])
{
	//Receives - first name from file
	// task - swap it with new one
	// Returns - New Title
	strcpy_s(Employee.Title, temp);        //swap with new Title

}
//*********************************************************************************************************

//*******************************************FUNCTION UPDATEPAYMENT****************************************
void EmployeeClass::updatePayment(float a)
{
	//Receives - first name from file
	// task - swap it with new one
	// Returns - New Title
	Employee.pay = a;
}

//*********************************************************************************************************

//*******************************************CONSTRUCTOR EMPLOYEECLASS**************************************

//constructor function
void EmployeeClass ::setdata(int ID, char FirstName[14],char LastName[14],char Department[16],char Title[16],float pay )            
{
	//Receives - all input info
	// task - assining all data var to class data types
	// Returns -obj with information

	//put data into these objects' variables


	Employee.ID= ID;
	strcpy_s(Employee.FirstName, FirstName);
	strcpy_s(Employee.LastName, LastName);
	strcpy_s(Employee.Department, Department);
	strcpy_s(Employee.Title, Title);
	Employee.pay = pay;

}
//*********************************************************************************************************

//*******************************************CONSTRUCTOR EMPLOYEECLASS**************************************

EmployeeClass::EmployeeClass(void)
{
	//Receives - receive an object
	// task - assign or create a new one
	// Returns - new object
	//Initialization
	Employee.ID = 0;
	Employee.FirstName[15] = { NULL };
	Employee.LastName[15] = { NULL };
	Employee.Department[17] = { NULL };
	Employee.Title[15] = { NULL };
	Employee.pay = 0;

}
//*********************************************************************************************************

//*************************************************FUNCTION PRINT******************************************
void EmployeeClass::print(ofstream& outfile1)
{
	//Receives - receive objects to printout
	// task - create a formatting look for output
	// Returns - the output with objects

	//prints the obj while formatting it
	outfile1 << setw(5) << getID();
	outfile1 << setw(18) << getFirstname() << setw(5) << getLastname() << setw(5) << getDepartment();
	outfile1 << setw(20) << getTitle() << setw(16) << setprecision(2) << fixed << "$";

	//printing number with comma
	if (getPay() > 9999)           //set condition do it if greater than 9999
		addcomma(outfile1);           //put commas for large numbers
	else
		outfile1 << right << setw(2) << getPay() << endl;     //payment printing

}
//*********************************************************************************************************

//*******************************************FUNCTION ADDCOMMA*********************************************
void EmployeeClass::addcomma(ofstream& outfile1)
{
	//Receives - receive the objects payment amount
	// task - determine the large numbers from objects
	// Returns - add comma to the large number when necessary

	int i = 0;                 //temp variable
	int BalArray[10] = { 0 };     //assign an empty array
	int Bal = getPay();       //assign balance with getpay func
	double Bal2 = getPay();       //assign bal2 with getpay func

	//calculation for where to add commas
	BalArray[0] = Bal / 10000;
	Bal -= BalArray[0] * 10000;
	Bal2 -= BalArray[0] * 10000;
	BalArray[1] = Bal / 1000;
	Bal -= BalArray[1] * 1000;
	Bal2 -= BalArray[1] * 1000;

	//output format
	outfile1 << right << setw(2) << BalArray[0] << BalArray[1] << ",";
	if (Bal2 < 10)
		outfile1 << "00" << Bal2 << endl;
	else
		outfile1 << Bal2 << endl;


}
//*********************************************************************************************************

//*******************************************FUNCTION SORTING**********************************************
void EmployeeClass::sorting(EmployeeClass employeeinfo[])
{
	//Receives - objects in the array form
	// task -sorts the object according to Id num
	// Returns - the sorted objects

	EmployeeClass temp;          //temperary variable
	float temp1;                 //temp placeholder

	for (int i = 0; i <  50; i++)
	{
		for (int j = (i + 1); j < 50; j++)
		{
			//swap up the objects from high to low Id num
			if (employeeinfo[i].getID() < employeeinfo[j].getID())
			{
				temp = employeeinfo[i];
				employeeinfo[i] = employeeinfo[j];
				employeeinfo[j] = temp;

			}
		}
	}
	return;

}
//*********************************************************************************************************

//******************************************FUNCTION DATAFUNCTIONING****************************************

void EmployeeClass::dataFunctioning(ifstream& infile1, ofstream& outfile1, EmployeeClass employeeinfo[])
{
	//Receives - the input from the the infile
	// task - process all of the received data in a right format
	// Returns - formatted data to the outfile

	//variables
	char t = 0;
	int i = 0;

	infile1 >> t;
	


	while (t != 'Q')        //keep it going till there is no more type left
	{
		cout << "i = " << i <<  " t = " << t << endl;
		if (t == 'I')
		{
			//reads in data for a object
			infile1 >> Employee.ID;
			infile1 >> ws;
			infile1.getline(Employee.FirstName, 15);
			infile1.getline(Employee.LastName, 15);
			infile1.getline(Employee.Department, 17);
			infile1.getline(Employee.Title, 17);
			infile1 >> Employee.pay;

			//put the information into the object
			employeeinfo[i].setdata(Employee.ID, Employee.FirstName, Employee.LastName, Employee.Department, Employee.Title, Employee.pay);
			i++;

			
		}
	
		else if (t == 'D')
		{
		//decalre varables
		int tempID;
		infile1 >> tempID;     //reads in temperory Id
		//assigning variables of the objects to the 0
		for (int k = 0; k < 50; k++)
		{
		if (employeeinfo[i].Employee.ID == tempID)
		{
		employeeinfo[i].Employee.ID = 0;
		}
		}

		}

		else if (t == 'C')
		{
		//declaring var
		int newvar;
		int tempId;
		float newpay;

		//receive the id number and generate the new code
		infile1 >> tempId >> newvar;

		float id = tempId;      //temperory variable

		if (newvar == 1)
		{
		infile1 >> ws;     //sets the white space

		infile1.getline(Employee.FirstName, 17);    //read in the first name

		for (int k = 0; k < 50; k++)
		{
		if (employeeinfo[k].Employee.ID == id)    //if ids are same
		{
		employeeinfo[k].updateFirstName(Employee.FirstName);     //must update the firstname 
		}

		}
		}

	    else if (newvar == 2)
		{
		infile1 >> ws;     //sets the white space

		infile1.getline(Employee.LastName, 17);    //read in the last name


		for (int i = 0; i < 50; i++)
		{
		if (employeeinfo[i].Employee.ID == id)    //if ids are same
		{
		employeeinfo[i].updateLastname(Employee.LastName);   //updates the lastname
		}
		}
		}

		else if (newvar == 3)
		{
		infile1 >> ws;

		infile1.getline(Employee.Department, 17);          //will get departments name

		for (int i = 0; i < 50; i++)
		{
		if (employeeinfo[i].Employee.ID == id)    //if ids are same
		{
		employeeinfo[i].updateDepartment(Employee.Department);   //updates the lastname
		}
		}
		}
		else if (newvar == 4)
		{
		infile1 >> ws;                    //read in white space

		infile1.getline(Employee.Title, 17);          //will get departments name

		for (int i = 0; i < 50; i++)
		{
		if (employeeinfo[i].Employee.ID == id)    //if ids are same
		{
		employeeinfo[i].updateTitle(Employee.Title);   //updates the lastname
		}
		}
		}
		else if (newvar == 5)
		{
		infile1 >> newpay;                    //temperory payment


		for (int i = 0; i < 50; i++)
		{
		if (employeeinfo[i].Employee.ID == id)    //if ids are same
		{
		employeeinfo[i].updatePayment(Employee.pay);   //updates the lastname
		}
		}
		}

		}
		else if (t == 'P')        //for printing
		{
			infile1 >> t;            //will get the type of printing opt

			if (t == 'E')
			{
				//variables
				static float TotalPay = 0;
				//Print heading
				outfile1 << "=================================================================================================================" << endl;
				outfile1 << "ID #          Name                  Department               Position                     Pay" << endl;
				outfile1 << "================================================================================================================" << endl;
				sorting(employeeinfo);                                //sets the data after ID num

				for (int i = 0; i < 50; i++)
				{
					if (employeeinfo[i].getID() != 0)                  //prints all obj with data
					{
						employeeinfo[i].print(outfile1);
						TotalPay += employeeinfo[i].Employee.pay;           //calculates the total amount


					}
				}

				//Footer of printing format
				outfile1 << "=================================================================================================================" << endl;
				outfile1 << "                                                            Total Amount of Payroll:" << setw(7) << setprecision(2);
				outfile1 << fixed << "$";

				//Add commas to the printing
				if (getPay() > 999)
					addcomma(outfile1);
				else
					outfile1 << TotalPay;
				outfile1 << endl;

			}
			else if (t == 'S')                         //should print only one obj
			{
				int tempId;
				infile1 >> tempId;                    //read in temp id

				//formatting heading
				outfile1 << "=================================================================================================================" << endl;
				outfile1 << "ID #              Name                      Department               Position               Pay" << endl;
				outfile1 << "================================================================================================================" << endl;
				for (int y = 0; y < 50; y++)
				{
					if (employeeinfo[y].getID() == tempId)               //set it equal to check
						if (employeeinfo[y].getID() != 0)              //print it while obj have values in it
							employeeinfo[y].print(outfile1);             //printing the obj

				}
				outfile1 << endl;
				
			}
		}
		infile1 >> t;
			}
		}
	

//*********************************************************************************************************

//*************************************************FUNCTION HEADER******************************************
void Header(ofstream& outfile1)
{
	//Receives - the output file
	// task - Prints the output premble
	// Returns - Nothing
	outfile1 << setw(30) << "Khushbu Shah";
	outfile1 << setw(17) << "CSC 24400";
	outfile1 << setw(15) << "Section 11" << endl;
	outfile1 << setw(30) << "FALL 2019";
	outfile1 << setw(20) << "Assignment 6" << endl;
	outfile1 << setw(35) << "--------------------------------------------";
	outfile1 << setw(35) << "--------------------------------------------" << endl << endl;

	return;
}
//*********************************************************************************************************

//**********************************************FUNCTION FOOTER*********************************************

void Footer(ofstream& outfile1)

{
	//receives- the output file
	//Task- Prints the output salutation
	//Returns- Nothing

	outfile1 << endl;

	outfile1 << setw(35) << "--------------------------------------------" << endl;

	outfile1 << setw(35) << "|         END OF PROGRAM OUTPUT             |" << endl;

	outfile1 << setw(35) << "--------------------------------------------" << endl;

	return;

}

//*********************************************************************************************************


//***************************************MAIN FUNCTION*****************************************************

int main()
{
   //recieves- It has output in formtting way and function calling demending on the order
	//task- declare varibales and function calling, output and input file
	//returns- it returns the result by the order of formatting and function calling and closes the file



	ifstream infile1("DATA6.TXT", ios::in);      //Tells the processor where to find the input file
	ofstream outfile1("results.txt", ios::out);  // to outstream the result file
	EmployeeClass employeeinfo[50];
	

	Header(outfile1);
	EmployeeClass company;
	company.dataFunctioning(infile1, outfile1, employeeinfo);          //taking input info and printing it out 

	Footer(outfile1);                                     //calling of function Footer
	//closes the files
	infile1.close();
	outfile1.close();
	cin.ignore();

	return 0;


}
//*********************************************************************************************************

