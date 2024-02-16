#include <iostream>
#include <cstring>
using namespace std;

/*
 * Author | Sophia You
 * Date | 02/22/2024
 * Description | This program creates a max heap where the root element is the 
 * largest, and its children get progressively smaller. 
 * Sources | 
 * https://www.geeksforgeeks.org/heap-data-structure/
 */

// function prototypes
void add(int* tree, int data);

int main()
{
  int max = 50;
  char input[50];
  bool editing = true; // determines if you still want the program to continue

  // tree
  int treeSize = 101;
  int* tree = new int[101];
  
  while (editing)
    {
      // instructions
      cout << "Please only use lowercase letters." << endl;
      cout << "This is a max heap program that takes in 100 integers." << endl;
      cout << "If you would like to enter your numbers manually, type 'manual.'" << endl;
      cout << "If you would like to generate numbers from a file, type 'file.'" << endl;
      cout << "If you would like to quit the program, type 'quit.'" << endl;

      // receiving input
      cin.getline(input, max);
      if (strcmp(input, "file") == 0)
	{
	  // read in from a file
	}
      else if (strcmp(input, "manual") == 0)
	{
	  // manual read-in
	  int count = 0;
	  bool wantToQuit = false;
	  while ((count < treeSize - 1) && !wantToQuit)
	    {
	      int newnum = 0;
	      cout << "If you want to stop adding numbers, enter '-1', otherwise, please enter number " << count << ": " << endl;
	      cin >> newnum;
	      cin.ignore(max, '\n');
	      if (newnum == -1)
		{
		  wantToQuit = true;
		}
	      else
		{
		  add(tree, newnum);
		}

	      count++;
	    }
	}
      else if (strcmp(input, "quit") == 0)
	{
	  editing = false;
	}
    }
return 0;
}

/*
 * This function adds the value into your max heap
 */
void add(int* table, int data)
{
  cout << "hi" << endl;
}

