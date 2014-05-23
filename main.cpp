//
//  main.cpp
//
//  Created by Matthew Michnal on 9/24/13.
//  Copyright (c) 2013 Matthew Michnal. All rights reserved.
//  THIS PROGRAM WAS CREATED AS A FINANCIAL CALCULATOR SUBSTITUTE. THIS WAS CREATED AS A SIDE PROJECT
//  The program allows the user to compute a multitude of different
//  Financial calculations based on information that users input into the program.
//  This program uses validation loops, do while loops, void functions, integer functions, etc.


#include <iostream>
#include <cmath> //Allows the calculation of powers in this program
#include <iomanip> //Allows the program to set precision for integer, float, and double values
using namespace std;
int choices, y_n;// This is the constant integer that controls the loop on functions below
double return_compound, return_irate;
int intro(); // Intro function that displays the options that user has
void time_money(); // placeholder for time value of money function
void debt_equity(); // placeholder for debt to equity function
void compound(); // placeholder for compound interest function
void annual_percent(); // placeholder for annual percentage yield function
void invest_2(); // placeholder for current ratio function
void leverage();
void amortization();
double compound_interest(float);
double compoundtype(int); //placehold for compound converter function
int main() // main integer that performs all of the lower functions by calling to them.
{
    
do // do loop that repeats the entire calculator until choice 6 is choosen which then ends the loop
{
    choices = intro();
    
    if (choices == 1)
        time_money();
    else if (choices == 2)
        annual_percent();
    else if (choices == 3)
        debt_equity();
    else if (choices == 4)
        compound();
    else if (choices == 5)
        invest_2();
     // else if (choices == 6)
       // leverage();
     else if (choices == 7)
        amortization();
    

}while (choices != 8);
    
    if (choices == 8)
    cout << endl;
    cout << endl;
    cout << "You have exited the program.\n";
    cout << "Thank you for using our services, we hope you found our program useful.\n";
    cout << "This program will now terminate, GOOD-BYE!!!\n" << endl;
    
return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////  THIS IS THE INDEPENDENT FUNCTION SECTION!! /////////////////////////
// IN HERE YOU WILL FIND ALL THE FUNCTIONS THAT ARE BEING CALLED BY THE MAIN FUNCTION ABOVE  //
//// IT IS ORGANIZED TO FLOW THE SAME WAY AS THE MAIN FUNCTION CALLS THEM, AND EACH ONE IS ////
/////// STORED BASED ON THE OPTIONS LIST FOUND IN THE OPTIONS FUNCTION BELOW VVVVVVVV /////////
///////////////////////////////////////////////////////////////////////////////////////////////

//*************************************************************************************************
// Independent function that is called by the main function in order to introduce program
// This is the independent function that calls the introduction of the time value of money function
///////////////////////////////////////////////////////////////////////////////////////////////////

int intro()
{
    int input; // Integer that stores the users input within this function
    cout << "Hello, this program was created as a substitute to financial calculators.\n";
    cout << "Here we offer a variety of options that allow you to solve a multitude of problems.\n";
    cout << "Below is the following options, by entering the number next to each option you will be\n";
    cout << "transfered to that part of the calculator. We hope you to enjoy our calculator!!!\n";
    cout << "1. Time value of money option.\n";
    cout << "2. Annual percentage yield.\n";
    cout << "3. Debt to equity.\n";
    cout << "4. Compoud interest.\n";
    cout << "5. Double your investment.\n";
    cout << "6. Leverage ratio.\n";
    cout << "7. Amortization.\n";
    cout << "8. Quit the program.\n";
    cin >> input; // User puts input in and this function then returns that value back to main function
    while (input >= 9) // Validation loop that doesn't allow user to enter data outside of 7
    {
        cout << endl;
        cout << "If you enter an invalid option, you will not proceed.\n";
        cin >> input;
        
    }
      return input; // returns input to main function for interpretation
}

//****************************************************************************************************
// This is the time value of money function. Inside it contains every element and formula involved with
// the time value of money formula. This function then sends the output to the main function above ^^^^
//////////////////////////////////////////////////////////////////////////////////////////////////////

void time_money()
{
do // do loop that repeats entire time value process as long as y_n doesn't equal 2.
{
    cout << "Hello Welcome to the Time value of money part of this calculator.\n"
         << "Please enter the following information and will do the rest.\n"
         << "For the piece of information that your missing please enter 0, thank you!\n" << endl;
    
    //Holds variables that will be input by user
    float years;
    float irate;
    float fRate;
    long double fvalue, pvalue;
    
    //Asks user for first input
    cout << "Number of years: ";
    cin >> years;
    
    //Asks user for second input
    cout << "Interest rate: ";
    cin >> irate;
    
    //Validation loop that wont allow more then 100% interest
    while (irate > 1)
    {
        cout << "That is not possible please try again.";
        irate++;
        cin >> irate;
    }
    
    //Asks for the final two pieces of information needed by the calculator
    cout << "Present value of investment: ";
    cin >> pvalue;
    cout << "Future value of investment: ";
    cin >> fvalue;
    
    //If statement that solves the formula based on information given to it
    if (pvalue == 0) // solves if present value number is missing
    {
        fRate = 1/ (1 + irate);
        cout << "The present value of this investment is "
        << fvalue * pow(fRate,years) << endl;
    }
    else if (irate == 0) // solves if interest rate value is missing
    {
        double f_pvalue;
        float n_value;
        f_pvalue = fvalue/pvalue;
        n_value = 1 / years;
        cout << "The interest rate needed to make this possible is " << setprecision(3)
        << pow(f_pvalue,n_value) - 1 << endl;
    }
    else if (years == 0) //  solves if number of years is missing
    {
        cout << "The number of years it will take is "
        << setprecision(3) << (log(fvalue/pvalue)/log(1 + irate)) << endl;
    }
    else if (fvalue == 0) // solves if futurve value is missing
    {
        cout << "The future value of this investment is "
        << setprecision(2) << pvalue * pow((1 + irate),years) << endl;
    }
    else
        cout << "You have entered a value in each space, there is nothing for me "
             << "to solve.\n";
    
    // This is the statement that asks user if they wish to repeat the process
    cout << endl;
    cout << "Would you like to repeat the time value of money function?\n";
    cout << "1. Yes\n";
    cout << "2. No\n";
    cin >> y_n; // takes the users input
    while (y_n > 2)
    {
        cout << "You have entered an invalid option please try again.\n";
        cin >> y_n;
    }
    
}while (y_n != 2); // while statement that closes the loop if 2 or "no" is selected
    
    cout << endl;

}

//********************************************************************************************************
// This function was created to hold the annual percentage yield formulas. It is designed much like
// the time value function, in which users input data and based on the information, the function calculates
// the annual percentage yield
///////////////////////////////////////////////////////////////////////////////////////////////////////////

void annual_percent()
{
do // do loop that controls the entire function. While function is the same as time value
{
    float irate; // variable asigned for interest rate
    int c_number; // variable assigned for the compound number
    int compute; // variable assigned for user to choose whether they want to change the value
    double annual_percent; // variable assigned for annual percent yield
    

    cout << "Hello welcome to the annual percentage yield section of this program.\n";
    cout << "Please enter the following information when prompted to by the calculator.\n";
    cout << "For the piece of information that you want us to solve, please enter a 0.\n";
    cout << endl;
    cout << "Please enter the interest rate you wish to find the yield of: ";
    cin >> irate; // User enters their input into this line.
    while (irate > 1) // Validation loop that limits the irate to 100% or less
    {
        cout << "This is not possible, please try again.\n";
        irate++;
        cin >> irate;
    }
    
    do // do while loop that finds the compounded number necessary for calculation
    {
    cout << "Now we need the number of times you would like the interest rate to \n";
    cout << "be compounded?\n";
    cin >> c_number; // User enters their input into this line
    cout << "This value is assumed in years would you like us to convert it for you?\n";
    cout << "1. Yes\n";
    cout << "2. No\n";
    cin >> compute; // User indicates if they want the calculator to convert the compound number
    
    switch (compute) // switch option that performs action based on selection
    {
        case 1:
            return_compound = compoundtype(c_number); // calls to compound function to convert number
            break;
        case 2:
            return_compound = (c_number * 1); // calculates user input as a yearly compound
            break;
    }
    
    switch (compute) // switch option that performs the irate conversion
    {
            case 1:
                return_irate = compound_interest(irate); // calls to interest rate function to convert irate
                break;
            case 2:
                return_irate = (irate); // calculates irate as is
                break;
    }
        
    cout << "The Return compound is " << return_compound << endl; // Displays the return compound
    cout << "The Interest rate has also adjusted to " << return_irate << endl; // Displays the irate
    cout << "Are these number correct??\n";
    cout << "1. Yes\n";
    cout << "2. No\n";
    cin >> y_n;
    }while (y_n == 2); // end of do while loop for compounding interest
    
    cout << "Ok then lets move on.\n";
    cout << endl;
    cout << "Now I will calculate your annual percentage yield. One moment....\n";
    
    annual_percent = pow((1 + return_irate), return_compound) - 1; //formula for annual percentage yield
    cout << "Your annual percentage yield will be " << annual_percent << endl; // displays the results
    
    cout << endl;
    cout << "Would you like to repeat the annual percentage yield function?\n";
    cout << "1. Yes\n";
    cout << "2. No\n";
    cin >> y_n;
    
}while (y_n != 2); // end of do while loop that controls entire function
    
    cout << endl;
}

//********************************************************************************************************
// This function was designed to hold the debt to equity portion of the financial calculator. In here it
// performs all necessary computations, and displays the results to the user. This function will be made
// with same "do" loop that allows user to repeat process as many times as they want, until the user
// chooses to exit this function
///////////////////////////////////////////////////////////////////////////////////////////////////////////

void debt_equity()
{
    double liabilities; // variable assigned to liabilities in this function
    double equity; // variable assigned to equity in this function
    double d_e; // variable assigned to the final debt/equity ratio
    
do
{
    double l_total = 0; // totals that will continue to add liabilities as long as user wants
    double e_total = 0; // totals that will continue to add equities as long as user wants
    cout << endl;
    cout << "Hello welcome to the Debt to Equity portion of this program.\n";
    do
    {
        
    cout << "Please enter the following information when prompted to by the calculator.\n";
    cout << endl;
    cout << "First we need all the instances of liabilities in the problem.\n";
    cout << "Don't worry we'll sum this all up once you're done.\n";
            do // Do while loop that continues to add liabilities together as long as user wants.
            {
                
                cin >> liabilities; // user enters liabilities
                l_total = l_total + liabilities; // the liability is added to the total liability
                cout << "The total is " << l_total;
                cout << " Do you have any more liability that you would like to add to this total??\n";
                cout << "1. Yes\n";
                cout << "2. No\n";
                cin >> y_n;
                while (y_n > 2 || y_n < 1)
                {
                    cout << "This is an invalid option please try again.\n";
                    cin >> y_n;
                }
                
                cout << " Please enter another integer and ill continue to add it to the total.\n";
        
            } while (y_n != 2);
    
    cout << "The final liability total is " << l_total << endl; // displays the final liability to user
    cout << endl;
    cout << "Now we need to find all the instances of equity in the problem.\n";
    cout << "Don't worry, once again we'll sum this all up for you once you're done.\n";
            do // Do while loop that continues to add equity together as long as user wants.
            {
        
                cin >> equity; // user enters equity
                e_total += equity; // the equity is added to the total equity
                cout << "The total is " << e_total << endl;
                cout << "Do you have any more equity numbers that you would like to add to this total.\n";
                cout << "1. Yes\n";
                cout << "2. No\n";
                cin >> y_n;
                while (y_n > 2 || y_n < 1)
                {
                    cout << "This is an invalid option please try again.\n";
                    cin >> y_n;
                }
            
            } while (y_n != 2);
    
    cout << "The final equity total is " << e_total << endl; // displays the final equity to user
    
    cout << "The two numbers that our calculator has computed:\n";
    cout << "Total liability = " << l_total << endl; // Allows user to see the liability total
    cout << "Total equity = " << e_total << endl; // Allows user to see the equity total
    cout << "Are these the numbers you wish to proceed with.\n";
    cout << "1. Yes\n";
    cout << "2. No\n";
    cin >> y_n;
        
        while (y_n > 2 || y_n < 1)
        {
            cout << "This is an invalid option please try again.\n";
            cin >> y_n;
        }
    
    } while (y_n != 1); // end of do while loop that will repeat entire process if user is not satisfied
    
    cout << endl;
    d_e = l_total/e_total; // formula for debt to equity ratio
    
    cout << "The debt to equity ratio was compiled by " << l_total << " liability and " << e_total
    << " equity." << endl;
    cout << "Debt to Equity is: " << d_e << endl; // Displays the debt to equity ratio to the user
    cout << endl;
    cout << "Would you like to repeat the debt to equity part of the calculator??\n";
    cout << "1. Yes\n";
    cout << "2. No\n";
    cin >> y_n;

}while (y_n != 2);
    
    cout << endl;
    
}

//********************************************************************************************************
// This function was designed to hold the compound interest portion of the financial calculator. In here it
// performs all necessary computations, and displays the results to the user. This function will be made
// with same "do" loop that allows user to repeat process as many times as they want, until the user
// chooses to exit this function
//////////////////////////////////////////////////////////////////////////////////////////////////////////

void compound()
{
    float irate; // variable asigned for interest rate
    int c_number; // variable assigned for the compound number
    int compute; // variable assigned for user to choose whether they want to change the value
    double o_value; // variable assigned for original value
    double final_compound; // variable assigned for the final compound number returned
    
do
{
    cout << "Hello welcome to the compound interest section of this program.\n";
    cout << "Please enter the following information when prompted to by the calculator and we'll solve the rest for you.\n";
    cout << endl;
    cout << "The first thing that we need to know is the original value that you want compounded.\n";
    cout << "Please enter this value below.\n";
    cin >> o_value; // user is asked for original value of investment
    cout << endl;
    cout << "Good job, now we need the next piece of the equation.\n";
    cout << "Please enter the interest rate you wish to find the yield of: ";
    cin >> irate; // User enters their input into this line.
    
    while (irate > 1) // Validation loop that limits the irate to 100% or less
    {
        cout << "This is not possible, please try again.\n";
        irate++;
        cin >> irate;
    }
    
    do // do while loop that finds the compounded number necessary for calculation
    {
        cout << "Now we need the number of times you would like the value to be compounded\n";
        cin >> c_number; // User enters their input into this line
        cout << "This value is assumed in years would you like us to convert it for you?\n";
        cout << "1. Yes\n";
        cout << "2. No\n";
        cin >> compute; // User indicates if they want the calculator to convert the compound number
        
        
        switch (compute) // switch option that performs action based on selection
        {
            case 1:
                return_compound = compoundtype(c_number); // calls to compound function to convert number
                break;
            case 2:
                return_compound = (c_number * 1); // calculates user input as a yearly compound
                break;
        }
        
        switch (compute) // switch option that performs action based on selection
        {
            case 1:
                return_irate = compound_interest(irate); // calls to compound interest function to convert
                break;
            case 2:
                return_irate = (irate); // calculates user input as is
                break;
        }
        
        cout << "The Return compound is " << return_compound << endl; // Displays the return compound
        cout << "The Interest rate has also adjusted to " << return_irate << endl;
        cout << "Are these number correct??\n";
        cout << "1. Yes\n";
        cout << "2. No\n";
        cin >> y_n;
        while(y_n < 1 || y_n >2)
        {
            cout << "You have entered an invalid option please try again.\n";
            cin >> y_n;
        }
    
    }while (y_n == 2); // end of do while loop that will repeat entire process if user isn't happy
    
    cout << endl;
    cout << "Ok then, lets move on to the next part of the calculator.\n";
    final_compound = o_value * (pow((1+return_irate),return_compound) - 1); // formula for compound interest
    cout << endl;
    cout << "Please give me a minute and I'll perform the calculations.....\n";
    cout << "The compounding interest value is " << final_compound << endl; // displays final compound
    cout << endl;
    cout << "Your total value in " << return_compound << " cycles is " << final_compound << endl;
    cout << endl;
    cout << endl;
    cout << "Would you like to repeat the compound interest section of this calculator??\n";
    cout << "1. Yes\n";
    cout << "2. No\n";
    cin >> y_n;
    while (y_n < 1 || y_n > 2)
    {
        cout << "You have entered an invalid option please try again.\n";
        cin >> y_n;
    }
    
    
}while (y_n != 2); // end of do while loop that controls whether user wants to repeat entire function
    
}

//***************************************************************************************************




void amortization()
{
    double principal;
    int p_time;
    float irate;
    double m_p;
    
do
{
    cout << "Hello welcome to the amortization section of this program.\n";
    cout << "Please enter the following information when prompted to by the calculator and will solve the rest for you.\n";
    cout << endl;
    cout << "The first thing we to know is what information you want us to solve for.\n";
    cout << "Do you want us to find the principal that you will owe on the loan?\n";
    cout << "or do you want us to find the payments that are needed in order to make the loan possible?\n";
    cout << "1. Principal owed\n";
    cout << "2. Payments owed\n";
    cin >> choices;
    while(choices < 1 || choices > 2)
    {
        cout << "You have entered an invalid option, please try again.\n";
        cin >> choices;
    }
    
    
    switch(choices)
    {
        case 1:
        cout << "You have entered the principal owed section of the calculator.\n";
        cout << "The first thing that we're going to need is the monthly payment that is required by this loan.\n";
        cin >> m_p;
        cout << "Thank you, the next thing that we need is the interest rate.\n";
        cin >> irate;
         while(irate > 1)
         {
             cout << "This is an invalid option, please try again.\n";
             cin >> irate;
         }
   
            do // do while loop that finds the compounded number necessary for calculation
            {
                cout << "Thank you, the last thing that we need is "
                     << "the time period that you have to pay this off.\n";
                cin >> p_time;
                cout << "This value is assumed in years would you like us to convert it for you?\n";
                cout << "1. Yes\n";
                cout << "2. No\n";
                cin >> y_n; // User indicates if they want the calculator to convert the compound number
                while (y_n < 1 || choices > 2)
                {
                    cout << "You have entered an invalid option, please try again.\n";
                    cin >> y_n;
                }
                
                switch (y_n) // switch option that performs action based on selection
                {
                    case 1:
                        return_compound = compoundtype(p_time); // calls to compound function to convert number
                        break;
                    case 2:
                        return_compound = (p_time * 1); // calculates user input as a yearly compound
                        break;
                }
                
                switch (y_n) // switch option that performs action based on selection
                {
                    case 1:
                        return_irate = compound_interest(irate); // calls to compound interest function to convert
                        break;
                    case 2:
                        return_irate = (irate); // calculates user input as is
                        break;
                }
                
                cout << "The Return compound is " << return_compound << endl; // Displays the return compound
                cout << "The Interest rate has also adjusted to " << return_irate << endl;
                cout << "Are these number correct??\n";
                cout << "1. Yes\n";
                cout << "2. No\n";
                cin >> y_n;
                while(y_n < 1 || y_n >2)
                {
                    cout << "You have entered an invalid option please try again.\n";
                    cin >> y_n;
                }
                
            }while (y_n == 2); // end of do while loop that will repeat entire process if user isn't happy
            
        cout << "Thank you for all of the information, I will now calculate the principal owed.\n";
        cout << "Please give me a minute............\n";
            
        principal = m_p * ((1 - pow((1 / 1 + return_irate),-return_compound)) / return_irate);
        
        cout << "The principal that you will owe on this loan is: " << principal << endl;
        break;
        
        case 2:
        cout << "You have entered the payments owed section of the calculator.\n";
        cout << "The first thing we're going to need is the principal of the loan.\n";
        cin >> principal;
        cout << "Thank you, now the next piece of information we need is the interest rate.\n";
        cin >> irate;
            while(irate > 1)
            {
                cout << "This is an invalid option, please try again.\n";
                cin >> irate;
            }
            
            do // do while loop that finds the compounded number necessary for calculation
            {
                cout << "Thank you, the last thing that we need is "
                << "the time period that you have to pay this off.\n";
                cin >> p_time;
                cout << "This value is assumed in years would you like us to convert it for you?\n";
                cout << "1. Yes\n";
                cout << "2. No\n";
                cin >> y_n; // User indicates if they want the calculator to convert the compound number
                while (y_n < 1 || choices > 2)
                {
                    cout << "You have entered an invalid option, please try again.\n";
                    cin >> y_n;
                }
                
                switch (y_n) // switch option that performs action based on selection
                {
                    case 1:
                        return_compound = compoundtype(p_time); // calls to compound function to convert number
                        break;
                    case 2:
                        return_compound = (p_time * 1); // calculates user input as a yearly compound
                        break;
                }
                
                switch (y_n) // switch option that performs action based on selection
                {
                    case 1:
                        return_irate = compound_interest(irate); // calls to compound interest function to convert
                        break;
                    case 2:
                        return_irate = (irate); // calculates user input as is
                        break;
                }
                
                cout << "The Return compound is " << return_compound << endl; // Displays the return compound
                cout << "The Interest rate has also adjusted to " << return_irate << endl;
                cout << "Are these number correct??\n";
                cout << "1. Yes\n";
                cout << "2. No\n";
                cin >> y_n;
                while(y_n < 1 || y_n >2)
                {
                    cout << "You have entered an invalid option please try again.\n";
                    cin >> y_n;
                }
                
            }while (y_n == 2); // end of do while loop that will repeat entire process if user isn't happy
            
            m_p = principal * ((return_irate * pow((1 + return_irate),return_compound))/(pow((1 + return_irate), return_compound)-1));
            
            cout << "The payments that you will have to pay in order to achieve this is " << m_p << endl;
            break;
    
    }
    
    cout << endl;
    cout << "Would you like to repeat the amortization section of this calculator??\n";
    cout << "1. Yes\n";
    cout << "2. No\n";
    cin >> y_n;
    while (y_n < 1 || y_n > 2)
    {
        cout << "You have entered an invalid option please try again.\n";
        cin >> y_n;
    }
    

}while(y_n != 2);

}

//*******************************************************************************************************

void invest_2()
{
    float irate;
    double rule_72;
do
{
 cout << "Hello welcome to the double your investment section of the calculator.\n";
 cout << "This part uses the rule of Seventy-Two in order to calculate how long it takes "
      << " for your investment to double.\n";
 cout << "Please enter the interest rate that you wish to double your investment with.\n";
 cin >> irate;
    while (irate > 1)
    {
        cout << "This is an invalid option, please try again.\n";
        cin >> irate;
    }
    
    cout << "Thank you, now I will tell you how long it will take to double your investment.\n";
    cout << "One moment please..........................\n";
    rule_72 = 72 / irate;
    cout << "The amount of time it will take to double your investment is " << rule_72;
    cout << endl;
    cout << "Would you like to repeat the double your investment section of the calculator?\n";
    cout << "1. Yes\n";
    cout << "2. No\n";
    cin >> y_n;

} while(y_n != 2);
    
}

//*********************************************************************************************************






















//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
// This function was designed to convert the choice into monthly, daily, semiannually,
// quarterly, and more. It then returns the output back to the function that calls to it
// FOR RIGHT NOW THE FUNCTIONS THAT CALL THIS CONVERTER ARE: COMPOUND INTEREST FUNCTION, ANNUAL PERCENT
////////////////////////////////////////////////////////////////////////////////////////////

double compoundtype(int c_number)// takes the c_number from the annual percentage yield
{
    int decision; // int for the decisions within this function
    int f_compound; // int for the f_compound that will be returned
    
    cout << "How would you like us to compound this interest rate?: \n";
    cout << "1. Monthly\n";
    cout << "2. Daily\n";
    cout << "3. Semiannually.\n";
    cout << "4. Quarterly.\n";
    cout << "Please indicate which one you would like by entering the number of "
    << "your selection.\n";
    cin >> decision; // int decision that is entered by user, tells program what switch to perform
    
    
    while (decision > 4 || decision <= 0)// Validation loop that makes sure you cant enter an invalid option
    {
        cout << "You have entered an invalid option please try again.\n";
        cin >> decision;
    }
    
    switch (decision) // Switch option that calculates the c_compound based on users choice
    {
        case 1:
            f_compound = (c_number * 12); // formula for monthly choice
            break;
        case 2:
            f_compound = (c_number * 365); // formula for daily choice
            break;
        case 3:
            f_compound = (c_number * 2); // formula for semiannual choice
            break;
        case 4:
            f_compound = (c_number * 4); // formula for quarterly choice
            break;
    }
    
    return f_compound; // returns the value back to the function that calls for it
}

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
// This function was designed to convert the interest rate into monthly, daily, semiannually,
// quarterly, and more. It then returns the output back to the function that calls to it
// FOR RIGHT NOW THE FUNCTIONS THAT CALL THIS CONVERTER ARE: COMPOUND INTEREST FUNCTION, ANNUAL PERCENT
////////////////////////////////////////////////////////////////////////////////////////////

double compound_interest(float irate)
{
    int decision; // int for the decisions within this function
    float f_irate; // int for the f_compound that will be returned
    
    cout << "Before we proceed, we still need to do one more thing.\n";
    cout << "We need to convert the interest rate to match the compound number.\n";
    cout << "So, once again we must ask you what type of compound do you want?\n";
    cout << "PLEASE REMEMBER TO SELECT THE SAME CHOICE TO MATCH YOUR COMPOUND INFORMATION.\n";
    cout << "How would you like us to compound this interest rate?: \n";
    cout << "1. Monthly\n";
    cout << "2. Daily\n";
    cout << "3. Semiannually.\n";
    cout << "4. Quarterly.\n";
    cout << "Please indicate which one you would like by entering the number of "
    << "your selection.\n";
    cin >> decision; // int decision that is entered by user, tells program what switch to perform
    
    
    while (decision > 4 || decision <= 0)// Validation loop that makes sure you cant enter an invalid option
    {
        cout << "You have entered an invalid option please try again.\n";
        cin >> decision;
    }
    
    switch (decision) // Switch option that calculates the c_compound based on users choice
    {
        case 1:
            f_irate = (irate / 12); // formula for monthly choice
            break;
        case 2:
            f_irate = (irate / 365); // formula for daily choice
            break;
        case 3:
            f_irate = (irate / 2); // formula for semiannual choice
            break;
        case 4:
            f_irate = (irate / 4); // formula for quarterly choice
            break;
    }
    
    return f_irate; // returns the value back to the function that calls for it
}