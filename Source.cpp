//Abdullah Suleyman Abdallah 20945456

#include <iostream>
#include <fstream>
#include<string>
using namespace std;

//declaring all my functions with the parameters that are passed for each function.
void MainMenu(double credits);
double Creditts(double credits);
double BurgerSize(double credits);
double Topping(double BurgerPrice,double credits,string size);
double Checkout(double BurgerPrice, double credits,string size);
double EnoughCredits(double BurgerPrice, double credits,string size);
double NotEnoughCredits(double BurgerPrice, double credits,string size);
void RecentOrders(string size,double BurgerPrice);
void OrderComplete();
void OrderIncomplete();
void passToppings(string b[], int len);
void ReadRecents();

//========================================================================//
void OrderComplete()
{
    string outfile = "recentorders.txt";
    ofstream myfile(outfile, ios::app); //opening the file and appending to the file and not rewriting.
    myfile << "\nOrder Successful"; //writing a gap
    myfile.close();
}
void OrderIncomplete()
{
    string outfile = "recentorders.txt";
    ofstream myfile(outfile, ios::app); //opening the file and appending to the file and not rewriting.
    myfile << "\nOrder failed"; //writing a gap
    myfile.close();
}
// function that opens and writes an array into a text file called recentorders.txt
void ReadRecents()
{
    // creates a string that holds the text file
    string stringfile;

    // reads the textfile recentorders.
    ifstream myfile("recentorders.txt");

    // loops the getline function to output the file line by line according to the file line length.
    while (getline(myfile, stringfile)) {
        
        cout << stringfile; //outputs the text from the file
        cout << "\n"; //seperating each item with a gap
    }

    // closes file
    myfile.close();
    
}
void passToppings (string tlist[],int len) //takes every item in array and writes in into the text file
{
    string outfile = "recentorders.txt"; //name of the textfile
    for (int pointer = 0; pointer < len; pointer++) //goes through each item in an array 
    {
        
        ofstream myfile(outfile, ios::app); //opening the file and appending to the file and not rewriting.
        
        myfile << tlist[pointer] << " " << endl; //writing each item in the array.
    }
}



void RecentOrders(string size, double BurgerPrice) //opens and outputs recent orders
{
    int arrayLength = 6;
    string outfile = "recentorders.txt";
    ofstream myfile(outfile, ios::app);
    if (myfile.is_open())
    {
        myfile << "\n";
        myfile << size;
        myfile << "\n";
        myfile << BurgerPrice;
        myfile.close();
    }
    else
    {
        cout << "unable to open file";
    }
}

//Main menu for program
void MainMenu(double credits)
{
    int Option;
    const int kAddCred = 1;
    const int kOrderBurg = 2;
    const int kRecentOrders = 3;
    const int kExit = 0;
    string Linebreak = "--------------------------------------------\n";
    
    cout << Linebreak;
    cout << "Welcome to UCLAN burger\n";
    cout << Linebreak;
    cout << "Main Menu \n";
    cout << "1. Add Credits (current credits == "<< credits << ")\n";
    cout << "2. Order a borgor\n";
    cout << "3. Open recent orders\n";
    cout << "0. Exit\n";
    cout << Linebreak;    
    cout << "Please enter a number: ";

    cin >> Option;
    while (cin.fail() || Option < kExit || Option > kRecentOrders)
    {
        //clear the input line
        cin.clear();
        //ignores the input and create a new line
        cin.ignore(80, '\n');

        //asks the user for a new input
        cout << "enter a number: \n";
        cin >> Option;
    }
    if (Option == kExit) //checks if option is = 0
    {
        exit(0); //end the program
    }
    else if (Option == kAddCred) //checks if the input is = 1
    {
        Creditts(credits); //sends program to the credits function passing the credits variable
    }
    else if (Option == kOrderBurg) //checks if the input is = 2
    {
        BurgerSize(credits); //sends program to the burgersize function passing the credits variable
    }
    else
    {
        ReadRecents(); //opens the recent orders  
        MainMenu(credits); //sends the program back to the main menu
    }
}

//====================================================================a=====//
// Creates a function to add credits.
double Creditts(double credits)
{
    
    double NewCred=0.00; //validating and initialising local variable NewCred
    string Linebreak = "--------------------------------------------\n";
    
    
    cout << Linebreak;
    cout << "Enter how much credits you want to add: ";
    cin >> NewCred; //taking input to add credits
    while (cin.fail() || NewCred < 0 ) //validation check so that the user can't input a string or number less than 0
    {
        //clear the input
        cin.clear();
        //ignores the max limit of the stream and prepares a new line
        cin.ignore(80, '\n');

        //asks the user for another input
        cout << "Enter a number: \n";
        cin >> NewCred;
    }
    credits = NewCred + credits; //updates the credits variable according to user input
    cout << "\n Your new balanace is: " << credits <<endl; //outputs the user's credit 
    cout << Linebreak;
    MainMenu(credits); //Opens the main menu function passing the updated credit.
    return credits;
}



// Function to select the size of the burger and then returns the price
double BurgerSize(double credits)
{
    //declaring and initialising the local variables.
    const int smallBurger = 1;
    const int mediumBurger = 2;
    const int largeBurger = 3;
    
    const double smallPrice = 3.00;
    const double medPrice = 5.50;
    const double largePrice = 7.25;
    
    int select;
    string size;
    double BurgerPrice;
    string Linebreak = "---------------------------------------------\n";
    
    //declaring and initiialising the size of the menu array.
    const int MenuLen = 4;
    //declaring an array for the menu
    string Menu[] = 
    {
        "Choose your burger size;\n","1. Small[3.0 credits]\n","2. Medium [5.50 credits]\n", "3. Large[7.25 credits]\n"
    };
    
    //outputting the menu onto the console with all the options for the user to choose from.
    
    cout << Linebreak;
    
    for (int index = 0; index < MenuLen;index++) //using a for loop to loop the whole menu array
    {
        cout << Menu[index]; //outputting the Menu array according to the pointer
    }

    
    cin >> select; //taking input for the user to select an option
    
    //a while loop to validate the selection
    while (cin.fail()  || select < 1 ||  select > 3)
    {
        //make cin ready
        cin.clear();
        //ignores the max size of stream - clears everything 
        cin.ignore(80, '\n');

        //asks the user for another input 
        cout << "Enter a number: \n";
        cin >> select;
    }
    //checks the input and sets the size and burgerprice variables according to their choice
    if (select == smallBurger)
    { 
        size = "Small Burger";
        BurgerPrice = smallPrice;
    }
    
    else if (select == mediumBurger)
    {
        size = "Medium Burger";
        BurgerPrice = medPrice;
    }
    
    else
    {
        size = "Large Burger";
        BurgerPrice = largePrice;
    }
    //outputs their choices for the user
    cout << "You have selected a " << size << " burger. \n";
    cout << "it costs " << BurgerPrice <<endl;
    cout << Linebreak;
    //passes the burgerprice, credit and the size of the burger to the next function.
    Topping(BurgerPrice,credits,size);
    //return burgerprice to the prev function.
    return BurgerPrice;   
}



//Function that allows user to set toppings and calculates the burgerprice and passes the
//burgersize, burgerprice and toppings into the file.
double Topping(double BurgerPrice, double credits, string size) 
{
  //setting local variables
    double cost = 0;
    int select2;
    int maxarrayLength = 6;
    string toppings[6];
    bool pickTopping;
    int index = 0;
    //setting constants for the options
    const int MaxSelect = 5;
    const int MinSelect = 0;
    const int cheese = 1;
    const int salad = 2;
    const int bacon = 3;
    const int ketchup = 4;
    const int mayo = 5;
    const int exburger = 6;
    const int checkout = 0;
    const int ToppingLen = 7;
    //setting constants for the toppings prices
    const double cheesepr = 0.80;
    const double saladpr = 0.50;
    const double baconpr = 1.00;
    const double ketchuppr = 0.30;
    const double mayopr = 0.30;
    const double extrabgpr = 1.50;
    //declaring and itialising the menu array
    string Menu[] =
    {
        "Please choose from the following toppings:\n","1. Cheese      [0.80 credits] \n", "2. Salad      [0.50 credits] \n", "3. Bacon       [1.00 credits] \n","4. Ketchup     [0.30 credits]\n","5. Mayo     [0.30 credits]\n","6. Extra Burger      [1.50 credits] \n","0. Checkout\n"
    };
    //initialising picktopping boolean as true
    pickTopping = true;
    //a while loop that allows users to input toppings every run until the array fills.
    while (pickTopping == true)
    {
        for (int index = 0; index < ToppingLen; index++)
        {
            cout << Menu[index];
        }

        cout << "-------------------------------\n";
        cin >> select2;
        //setting a check so that if user inputs wrong data type or number outside of range it asks for another input
        while (cin.fail() || select2 < MinSelect || select2 > MaxSelect)
        {
            //clear the input line
            cin.clear();
            //ignores the max stream and adds a gap.
            cin.ignore(80, '\n');

            //asks the user for another valid input
            cout << "Enter a number: \n";
            cin >> select2;
        } 
        if (select2 == cheese) //checks input and if it matches the value.
        {
            toppings[index] = "Cheese"; //changes the value in the toppings array to the value written.
            cost = cost + cheesepr; // adds to the variable cost according to the input
            
        }
        else if (select2 == salad)
        {
            toppings[index] = "Salad";
            cost = cost + saladpr;
        }
        else if (select2 == bacon)
        {
            toppings[index] = "Bacon";
            cost = cost + baconpr;
        }
        else if (select2 == ketchup)
        {
            toppings[index] = "Ketchup";
            cost = cost + ketchuppr;
        }
        else if (select2 == mayo)
        {
            toppings[index] = "Mayo";
            cost = cost + mayopr;
        }
        else if (select2 == exburger)
        {
            toppings[index] = "Extra Burger";
            cost = cost + extrabgpr;
        }
        
        else //if 0 is pressed.
        {
            BurgerPrice = BurgerPrice + cost; //calculates the final burgerprice
            
            RecentOrders(size, BurgerPrice); //goes to the function recentorders with the variables size and burgerprice as parameters
            Checkout(BurgerPrice, credits, size); //goes to checkout function with the variables burgerprice, credits ane pd size.

            exit(0); //stops the program from rerunning after it passes through the other functions
        }

        cout << "You chose " << toppings[index] << endl; //prints out the toppings picked
        index = index + 1; //passes the index of the array up
        cout << "Do you want to choose additional toppings? 1 for yes 2 for no: ";

        const int yes = 1;
        const int no = 2;
        int additional;
       
        cin >> additional; // takes input to see if the user wants to add more items to the array
        while (cin.fail() || select2 < MinSelect || select2 > no)
        {
            //clear the input line
            cin.clear();
            //ignores the max stream and adds a gap.
            cin.ignore(80, '\n');

            //asks the user for another valid input
            cout << "Enter a number: \n";
            cin >> additional;
        }
        if (additional == yes) //checks the input and carries on the loop 
        {
            pickTopping = true; //continues the pickTopping loop

        }
        else if (additional == no) //checks input to see if it has to stop the loop
        {
            BurgerPrice = cost + BurgerPrice; //calculates the final cost of the burger
            pickTopping = false; // stops the pickTopping loop
        } 
        else if (index == maxarrayLength) //checks to see if the array pointer has hit its limit
        {
            cout << "You have added the max amount of toppings";
            BurgerPrice = cost + BurgerPrice; //calculates the final burgerprice
            pickTopping = false;//stops the loop
        }
    }

    RecentOrders(size, BurgerPrice); // runs the recentorders function sending the variables size and burgerprice as parameters
    passToppings(toppings, index); // run the passToppings function sending the variables toppings and the index as parameters
    Checkout(BurgerPrice,credits,size); // runs the checkout function sending the variables burgerprice credit and size as parameters
    
    
    return cost;
    
}


double Checkout(double BurgerPrice,double credits,string size) //Checkout function that checks if the user has enough credits.
{ 
    if (BurgerPrice <= credits) //checks if burger price is less than or equal to credits 
    {
        EnoughCredits(credits, BurgerPrice,size); //runs the function enoughcredits
        OrderComplete();
    }
    else //if the user does not have enough credits
    {
        
        NotEnoughCredits(credits, BurgerPrice,size); //runs the function not enough credits
        OrderIncomplete;
    }
    return 0;
}

double EnoughCredits(double credits, double BurgerPrice,string size)
{
    //declares the local variables.
    int NewOrder;
    const int yes = 1;
    const int no = 2;
    //outputs the users balance and the price of their burger.
    cout << "your available balance is "<<credits<<endl;
    cout << "Your burger price is " << BurgerPrice << endl;
    cout << "----------------------------------------------\n";
    credits = credits - BurgerPrice; // calculates their credit after their purchase.
    cout << "Your new balance is " << credits<<endl;
    cout << "----------------------------------------------\n";
    cout << "Would you like to order a new burger?\n";
    cout << "Input 1 for Yes and 2 for No: ";
    cin >> NewOrder; //takes input to see if user wants to order a new burger
    while (cin.fail() || NewOrder < yes || NewOrder > no) //input check to see if the user picks anything other than 1 or 2
    {
        //clear the input line
        cin.clear();
        //ignores the size of stream creates a new line
        cin.ignore(80, '\n');

        //asks the user for another input
        cout << "Enter a number: \n";
        cin >> NewOrder;
    }
    if (NewOrder == yes)
    {
        MainMenu(credits); //resets the program back to main menu
    }
    else
    {
        exit(0); //exits the program
    }
    return credits;
}


double NotEnoughCredits(double BurgerPrice,double credits,string size) //function that passes the variables burgerprice, credits and size

{
    //declares + initialises the local variables
    double AddCredits;
    int Option;
    const int yes = 1;
    const int no = 2;
    //outputting to ask if they want to add more credits
    cout << "\n";
    cout << "You have insufficient credits available\n";
    cout << "Would you like to add more credits? \n";
    cout << "Input 1 for Yes or 2 for No: ";
    cin >> Option; //taking an input into the variable option
    while (cin.fail() || Option < yes || Option > no) // validation check so that the user can only input 1 or 2
    {
        //clears the inputline
        cin.clear();
        
        //ignores the max stream and creates a new line
        cin.ignore(80, '\n');
       
        //asks the user for another input
        cout << "Enter a number: \n";
        cin >> Option;
    }
    if (Option == yes) //if the user inputs 1
    {
        cout<<"Enter the credit top up: ";
        cin >> AddCredits; //takes an input for the topup
        while (cin.fail() || AddCredits < 0 ) //validation so that the user can't input a negative number or a string
        {
            //a
            cin.clear();
            //ignores the max size of stream - clears everything 
            cin.ignore(80, '\n');

            //asks the user agai
            cout << "Enter your top up amount: \n";
            cin >> AddCredits;

        }
        credits = AddCredits + credits; //updates the credit
        Checkout(credits,BurgerPrice,size); //takes the program back to the checkout menu
    }
    else //if the user inputs 2 (for no)
    {
        MainMenu(credits); //sends the user back to main (cancels order)
    }
    return credits;
}


// The main method
int main()
{
    double credits = 0.00;
    MainMenu(credits); //sends the user to the main menu

}
                
