#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include "ArrayBag.h"

// GUI functionality
// ANSI escape sequences for cursor movements
#define CURSOR_UP(n) std::cout << "\033[" << n << "A"        //Moves the cursor up one line.
#define CURSOR_DOWN(n) std::cout << "\033[" << n << "B"      //Moves the cursor down one line.
#define CURSOR_FORWARD(n) std::cout << "\033[" << n << "C"   //Moves the cursor one space forward.
#define CURSOR_BACKWARD(n) std::cout << "\033[" << n << "D"  //Moves the cursor one space back.

void clientMenu(bool isSorted, bool isFull, bool isEmpty, std::string theBagContents, std::string lastOperation);   //Menu display
void clearCurrentLine(); //Clears out the current line in the CLI.                  //Majority of case uses replaced with system("cls")
void clearStatusLine();  //Clears out the status line in the CLI (Last operation).  //Majority of case uses replaced with system("cls")

int main()
{
	//ADT Setup
	ArrayBag<int> bag; //Initialize array of type int.

	//Left this here in case youd like to have more starting values.
	//Make sure to increase the DEFAULT CAPACITY accordingly.
	//int initialValues[] = {1, 33, 6, 9, 2, 65, 4, 29, 5, 8, 39, 88, 7, 25, 51, 3, 99, 14, 11, 10};
	int initialValues[] = {1, 33, 5};
	// Add the initial values to the bag
	for (int i = 0; i < 3; i++)
	{
		bag.add(initialValues[i]);
	} 

	

	//Runtime setup - Information trackers.
	bool sorted = false;     //Hard-Coded because of the order of the initial values.
	bool full = false;       //Hard-Coded because we didn't fill the array with initial values.
	bool bagempty = false;   //Hard-Coded because we have initial values.
	std::string bagContents; //holds last fetched bag contents
	std::string lastOperation = "Awaiting Selection . . . \n"; //Starts off awaiting selection.
	bool run = true;
	char menuSelection[2];
	//Runtime
	while(run)
	{
		clientMenu(sorted, full, bagempty, bagContents, lastOperation); //Draw menu 
	
		char menuSelection;			//Determinant for user input.								  

		std::cin >> menuSelection; 
		std::cin.clear();          //Ensure the stream object is clear.
		std::cin.ignore();         //Ensure the stream object is clear.
		switch(menuSelection) 
		{
			case '1': // Diaplay what is currently in the bag.
			{
				clearStatusLine();
				
				bagContents = "";
				std::vector<int> vectorContents = bag.toVector();
				for (int i = 0; i < vectorContents.size(); i++) {
					bagContents += std::to_string(vectorContents[i]) + " ";
				}
				if (bagContents.empty()) {
					bagempty = true;
				}
				else
				{
					bagempty = false;
				}

				lastOperation = "Displayed Bag Contents. \n";
				break;
			};
			case '2': //Add values to the bag.
			{
				if (!full)
				{
					bool functionSuccess;
					bool inputValidation = true;
					std::string inputMesage = "Awaiting value. . .";

					do 
					{
						int inputValid;

						system("cls");
						std::cout << "ADDING VALUE \n";
						std::cout << inputMesage << '\n';

						std::string targetValue;
						std::cout << "Enter value: ";
						std::getline(std::cin, targetValue);
						std::stringstream iss(targetValue);
						if (iss >> inputValid)  //The input is valid ?
						{
							functionSuccess = bag.add(inputValid); // Can the value be added? (Is is full)
							if (!functionSuccess){ //The bag is full
								full = true; //
								lastOperation = "Bag is Full, value was not added! \n";
							}
							else
							{
								lastOperation = "Value was added! Be sure to Re-Display! \n";
								sorted = false;  //Flag for menu information
							}
							inputValidation = true; //flag for successful function call.
						}
						else
						{
							inputMesage = "Invalid value.";
							inputValidation = false;
						}
					}
					while (!inputValidation);
				}
				else
				{
					lastOperation = "Bag is full, cannot add more values! \n";
				}
				break;
			};
			case '3':
			{
				bagempty = bag.isEmpty();
				if (!bagempty)
				{
					bool functionSuccess;
					bool inputValidation = true;
					std::string inputMesage = "Awaiting value. . .";

					do 
					{
						int inputValid;

						system("cls");
						std::cout << "REMOVING VALUE \n";
						std::cout << inputMesage << '\n';
						
						std::string targetValue;
						std::cout << "Enter value: ";
						std::getline(std::cin, targetValue);
						
						std::istringstream iss(targetValue);
						if (iss >> inputValid)  //The input is valid ?
						{
							functionSuccess = bag.remove(inputValid); // Was the value removed?
							if (!functionSuccess){ //The bag is empty
								lastOperation = "Value not found \n";
							}
							else
							{
								lastOperation = "Value was removed! Be sure to re-display! \n";
								sorted = false;
							}
							inputValidation = true;
						}
						else
						{
							inputMesage = "Invalid value.";
							inputValidation = false;
						}
					}
					while (!inputValidation);
					full = false;
				}
				else
				{
					lastOperation = "Bag is empty, cannot remove values! \n";
					bagempty = true;
				}
				break;
			};
			case '4':
			{
				clearStatusLine();
				bag.bubbleSort();
				system("cls");
				sorted = true;
				lastOperation = "Bag sorted. Be sure to Re-display! \n";
				break;
			};
			case '5':
			{
				if (sorted != true)
				{
					lastOperation = "Please sort the bag prior to searching \n";
				}
				else if (sorted == true)
				{
					int x; //breakpoint helper
					bool inputValidation = false; 

					std::string searchValueInput; // Pre validation
					int searchValue;              // Post validation
					
					std::string searchTypeInput;  // Pre validation
					int searchType;               // Post validation
				
					std::string errorMessage = "";
					int inputValid;
					
					do 
					{
						system("cls");
						std::string inputMessage = (searchValueInput.empty() ? "Awaiting search value..." : searchValueInput);
						std::string typeAndValue = (searchValueInput.empty() ? "Enter value: " : "Enter search type: ");
						std::string displaySearchOptions (searchValueInput.empty() ? "" : "1) Binary Search ITERATIVE \n2) Binary Search RECURSIVE\n");
						std::cout << "BINARY SEARCH \n";
						std::cout << displaySearchOptions;
						std::cout << errorMessage; //no endl to not include whitespace if no error.
						std::cout << "Value: " << inputMessage << '\n';
						std::cout << typeAndValue;

						//input validation should be in a separate client helper function to avoid 
						//rewriting the same code but I simply ran out of time.
						//Will document the first input validation. The rest works the same way.
						if (searchValueInput.empty())
						{
							std::getline(std::cin, searchValueInput); //Copy the stream information into a variable.
							std::stringstream iss(searchValueInput);  //Create a stream object
							if (iss >> x && iss.eof()) //attempt to insert the entire stream object into a variable
							{
								iss.seekg(0);      //resets the cursor to the beginning of the stream. //~Thank you internet. This was a headache and a half.
								iss >> searchValue; //Place the stream data into a variable knowing it will work.
								iss.clear();   //Clear the stream
								iss.str("");   //Set the stream to empty string.
								errorMessage = ""; //Reset error Message
							}
							else
							{
								iss.clear();  //Clear the stream
								iss.str("");  //Set the stream to an empty string
								searchValueInput = ""; //Clear the searchValue input.
								errorMessage = "Invalid Search value. \n"; //Display the type of error in the CLI.
							}
						}
						else if (searchTypeInput.empty())
						{
							std::getline(std::cin, searchTypeInput);
							std::stringstream isa(searchTypeInput);
							if (isa >> x && isa.eof())                //changed iss to isa just for easy searchability for debug.
							{
								isa.seekg(0);
								isa >> searchType;
								isa.clear();
								isa.str("");
								if (searchType != 1 && searchType != 2)
								{
									searchTypeInput = "";
									errorMessage = "Search value must be 1 or 2. \n";
								}
								else
								{
									if(bag.binarySearchHelper(searchType, searchValue))
									{
										lastOperation = "Value was found! \n";
										
									}
									else
									{
										lastOperation = "Value was not found. \n";
									}
									inputValidation = true;
								}
							}
							else
							{
								isa.clear();
								isa.str("");
								searchTypeInput = "";
								errorMessage = "Invalid search type. \n";
							}
						}
						 //both inputs are valid because neither are cleared.
					}	
					while(!inputValidation);
				
				}
				break;
			}
			case '0':
			{
				system("cls");
				std::cout << "Goodbye! \n";
				run = false;
				break;
			}
			default:
			{
				clearStatusLine();
				lastOperation = "Invalid Input \n";
				break;
			}
		}
		system("cls");
	}
	return 0;
   
}  // end main

//UI HELPER FUNCTIONS
//This may have been a mistake spending so much time on this part.
//I did learn a lot in general using online resources
//at the cost of being able to better understand the material we're learning in class.

//Im just realizing now ive basically made this into a CRT monitor lol.
//Theres gotta be a better way ~

//Used to overwrite terminal menu instad of reprinting.
void clearCurrentLine() 
{
    std::cout << "\033[2K"; // Clear current line
    std::cout << "\r";      // Move cursor to beginning of line
} //end clearCurrentLine

void clearStatusLine()
{
	CURSOR_UP(1);       //
	clearCurrentLine(); //Helper function for a specific terminal update that occurs often.
	CURSOR_DOWN(1);     //Majority of this use was replaced with system("cli");
} //end clearStatusLine

//Terminal main menu template.
void clientMenu(bool isSorted, bool isFull, bool isEmpty, std::string theBagContents, std::string lastOperation) 
{
	std::cout << "\n== Info Panel ==\n";
	std::cout << "Bag items: " << (theBagContents.empty() ? "Null" : theBagContents) << '\n';
	std::cout << "Sorted: " << (isSorted ? "YES" : "NO") << '\n';
	std::cout << "Full: " << (isFull ? "YES" : "NO") << '\n';
	std::cout << "Empty: " << (isEmpty ? "YES" : "NO") << '\n';
	std::cout << "\n== Main Menu ==\n";
	std::cout << "1) Display Bag Contents. \n";
	std::cout << "2) Add values to the bag. \n";
	std::cout << "3) Remove values from the bag. \n";
	std::cout << "4) Sort the bag. \n";
	std::cout << "5) Search the bag for a value. \n";
	std::cout << "0) Exit. \n";
	std::cout << "STATUS: " << lastOperation;
	std::cout << "Enter selection: ";
} //end clientMainMenu