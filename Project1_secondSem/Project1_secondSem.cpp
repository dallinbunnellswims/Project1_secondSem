// Project1_secondSem.cpp : Defines the entry point for the console application.
//Author Dallin Bunnell
/*Prompt the user to enter in their taxable income.
Get the input. If a non-numeric character is entered, display an error message and ask the user to input the value again. Once you have a numeric value, validate the input to insure that it is a positive value. If it is not a positive value go back to step 1.
Prompt the user to enter in "s" or "m" for filing single or jointly.
Get the input and validate that it is either "s" or "m". Re-do this step if the input is not one of these two characters.
Based on the user's input, calculate the user's tax using the appropriate tax table and display the amount of money that person owes. Present this data nicely formatted as a currency value.
Ask the user if they want to do another tax calculation.
Accept either "y" or "n" as input. Validate the input and re-do this step if it is not correct.
If the user selects "y" start back at step one. If the user selects "n" quit. For all other choices, tell that user that an invalid choice was made and ask them to input again.
*/

#include "stdafx.h"
#include <iostream>
#include <ios>


int main()
{
	double tax;
	int income=0;
	double temp;
	char MorS;
	char YorN;
	bool validInput = false;
	bool repeat = true;
	
	while (repeat)
	{
		validInput = false;
		std::cout << "This program calculates your income tax." << std::endl;
		std::cout << "Please enter your taxable income. ";
		std::cin >> income;
		std::cout << "Are you married and filing jointly (enter an m)\nor single and filing singly (enter an s) ";
		std::cin >> MorS;
		while (!validInput)
		{
			if (MorS == 'm' || MorS == 's')
			{
				validInput = true;
			}
			else
			{
				std::cout << "Invalid input, please enter an m or s ";
				std::cin >> MorS;
				validInput = false;
			}

		}
		if (MorS == 'm')
		{
			if (income <= 1726 && income >= 0)
				tax = ((income - 0.0)*.022) + 0.0;
			else if (income <= 5176 && income >= 1727)
				tax = ((income - 1726.0)*.033) + 40.0;
			else if (income <= 8626 && income >= 5177)
				tax = ((income - 5176.0)*.062) + 175.0;
			else if (income > 8626)
				tax = ((income - 8626.0)*.075) + 390.0;
		}
		if (MorS == 's')
		{
			if (income <= 863 && income >= 0)
				tax = ((income - 0.0)*.022) + 0.0;
			else if (income <= 2588 && income >= 864)
				tax = ((income - 863.0)*.033) + 25.0;
			else if (income <= 4313 && income >= 2589)
				tax = ((income - 2588.0)*.062) + 85.0;
			else if (income > 4313)
				tax = ((income - 4313.0)*.075) + 181.0;
		}

		std::cout.precision(2);
		std::cout << std::fixed << "Your income tax is " << tax << std::endl;
		std::cout << "Do you wish to make another calculation? enter y or n ";
		std::cin >> YorN;
		validInput = false;
		while (!validInput)
		{
			if (YorN == 'y')
			{
				validInput = true;
				repeat = true;
			}
			else if (YorN == 'n')
			{
				repeat = false;
				return 0;
			}
			else
			{
				std::cout << "Invalid input, please enter an y or n ";
				std::cin >> MorS;
				validInput = false;
			}

		}
	}
	


	

    return 0;
}

