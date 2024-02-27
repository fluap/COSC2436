

#COSC 2436 Programming Fundamentals III
#Kathryn Rehfield
#Lab 1 – Arrays and Recursion
#Due: 02/25/24
 
 ✔️❌
 
 You will use the array bag code that we reviewed in the text book. This code is provided with this assignment. In this code I have added one new method to the class for you to use as a guide. You should remove all traces of the “doSomething” method in all the files before you submit your assignment.
You will write 3 new methods in the ArrayBag class:

- ✔️ **bubbleSort** - a method to sort the array in ascending order using the bubble sort. 
- ✔️ **binarySearchIterative** – a repetitive version of the binary search.
- ✔️ **binarySearchRecursive** - a recursive version of the binary search. 

✔️(**You should use a helper method that calls the recursive method so the client code does not have to provide the extra parameters**. Client calls to both of the search methods should be identical other than the method name.)

Load your bag with some initial values, but do not fill it completely.
# You are here You are here You are here You are here You are here You are here
**Your client code should give the user the option to:**

- ✔️ **Display the contents** of the bag using the class method “toVector”.
- ✔️ **Add values** to the bag.
- ✔️ **Remove values** from the bag.
- ✔️ **Sort** the bag.
- ✔️ **Search** for a value using their choice of either the iterative search or the recursive search - both need to be tested.

**Other rules:**
- ✔️ Allow the user to keep doing these things until they are done.
- ✔️ Do not automatically sort the bag if the user chooses to search. * Your program should give the user a message telling them they must first sort the bag before they can search. You must think of a way to detect programatically that the array has not been sorted. *
- ✔️ You decide what the user interface will be.  Make it clear and easy to use.  *It can be very basic; nothing fancy. A menu driven program works well.*
- Each value in your array should be unique - no value will appear in the array multiple times.
- ✔️ Your array elements can be any data type the client code wants to use – use a template class put in place in the code provided. You can write your client code to process a bag holding any data type you want.
- ✔️ Write your client code in a modular, structured fashion.  
- ✔️ Make sure you perform input validation where appropriate. 
- *This program should be bullet-proof and well documented. I am expecting code from a programmer who is in their third semester of writing software.*

**You will submit the following:**
- All of program source and header files compressed into a zip file (.zip).  
- Name your zip file “lab1_Firstname_Lastname”. 
- You decide what to name the other files. 
- **Do not include .exe files.**

## Lab Grade Points     
**Labs will be graded on the following:**                    

Comments (Including):
- Program description (comment block at top of program).
- Function descriptions for every function other than main().*including purpose, input and output.*
- Comments at major algorithm steps (at a minimum).

Followed directions
- Correct output
- Structured program design
- Meaningful identifier names

**NOTE** – The following is considered unstructured progamming and you will not do any of this in your programs:*

- You will NEVER use break, exit, return, pass, continue or anything to leave a loop (or iteration), function, or other construct prematurely, unless it is part of the structure as in a switch statement.
- You will NEVER have a function call itself, unless it is intentional recursion.
- You will NEVER use global variables.  However, you may use global constants if it is appropriate and they are used properly.
- You will have only one return statement in a function. (Exception – Multiple return statements may be necessary in a recursive function.)
- You will NEVER intentionally write an infinite loop and then break out of it.

