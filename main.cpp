#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

/*
 * Author | Sophia You
 * Date | 02/22/2024
 * Description | This program creates a max heap where the root element is the 
 * largest, and its children get progressively smaller. 
 * Sources | 
 * https://www.geeksforgeeks.org/heap-data-structure/
 * https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/
 * https://www.geeksforgeeks.org/return-statement-in-cpp-with-examples/
 */

// function prototypes
void insert(int* &tree, int treeSize, int i);
void print(int* tree, int i, int numTabs);
void remove(int* &tree, int i);

int main()
{
  int max = 50;
  char input[50];
  bool editing = true; // determines if you still want the program to continue

  // tree
  int treeSize = 101;
  int* tree = new int[treeSize];
  tree[0] = 0; // we will not be using the 0 index

  // manual addition
  int insertIndex = 1; // records where to insert a new value
  int count = 0; // makes sure only 100 numbers are added
  
  while (editing)
    {
      // instructions
      cout << "Please only use lowercase letters." << endl;
      cout << "This is a max heap program that takes in 100 integers." << endl;
      cout << "If you would like to add to your tree, type 'add.'" << endl;
      cout << "If you would like to remove the root, type 'remove.'" << endl;
      cout << "If you would like to remove all values, type 'remove all.'" << endl;
      cout << "if you would like to print your tree, type 'print.'" << endl;
      cout << "If you would like to quit the program, type 'quit.'" << endl;

      // receiving input
      cin.getline(input, max);
      if (strcmp(input, "add") == 0)
	{
	  cout << "If you would like to enter numbers manual, type 'manual.'" << endl;
	  cout << "If you would like to enter numbers through a file, type 'file.'" << endl;
	  cin.getline(input, max);
	  if (strcmp(input, "file") == 0)
	    {
	      
	      // read in from a file
	      int fileValues[treeSize];
	      for (int i = 0; i < treeSize; i++)
		{
		  // initialize everything to zero
		  tree[i] = 0;
		}

	      int newnum = 0;

	      // read in the file
	      cout << "Enter the name of the file you want to read in" << endl;
	      cin.getline(input, max);
	      ifstream inFile;
	      inFile.open(input);

	      int i = 1;
	      while (inFile >> newnum && i < treeSize)
		{
		  tree[i] = newnum;
		  insert(tree, treeSize, i);
		  i++;
		}
	      
	      for (int i = 0; i < treeSize; i++)
	      {
	        cout << tree[i] << endl;
	      }
	    }
	  else if (strcmp(input, "manual") == 0)
	    {
	      // manual read-in
	      //	  int count = 0;
	      bool wantToQuit = false;      
	      
	      while ((count < treeSize - 1) && !wantToQuit)
		{
		  int newnum = 0;
		  cout << "If you want to stop adding numbers, enter '-1', otherwise, please enter a positive integer greater than 0"  << endl;
		  cin >> newnum;
		  cin.ignore(max, '\n');
		  if (newnum == -1)
		    {
		      wantToQuit = true;
		    }
		  else if (newnum <= 0)
		    {
		      cout << "Please enter a positive integer greater than 0." << endl;
		    }
		  else if (newnum >= 0)
		    {
		      tree[insertIndex] = newnum;
		      insert(tree, treeSize, insertIndex);
		      cout << "You've added " << insertIndex << " numbers" << endl;
		      insertIndex++;

		      cout << "New tree: " << endl;
		      print(tree, 1, 0); // visualize the current tree
		      cout << "" << endl;

		      count++;
		    }

		}
	    }
	}
      else if (strcmp(input, "remove") == 0)
	{
	  cout << "Removing root..." << endl;

	  // temporary variable that stores our position moving thru the tree
	  int rootIndex = 1;

	  insertIndex--;

	  // remove the current root, put the rightmost leaf as the root
	  tree[rootIndex] = tree[insertIndex];
	  tree[insertIndex] = 0;

	  // reorganize the tree back to a max heap
	  remove(tree, rootIndex);
	  cout << "New tree: " << endl;
	  print(tree, 1, 0);
	  cout << "" << endl;
	}
      else if (strcmp(input, "remove all") == 0)
	{
	  cout << "Removing all values..." << endl;

	  // basically call remove repeatedly until insertIndex = 1
	  while (insertIndex != 1)
	    {
	      // temporary variable   
	      int rootIndex = 1;

	      insertIndex--;

	      // remove the current root, put the rightmost leaf as the root        
	      tree[rootIndex] = tree[insertIndex];
	      tree[insertIndex] = 0;

	      // reorganize the tree back to a max heap                             
	      remove(tree, rootIndex);

	      cout << "Root removed. New tree: " << endl;
	      print(tree, 1, 0);
	      cout << "" << endl;
	    }

	  cout << "Removal process complete. Your max heap is now clear." << endl;
	  cout << "" << endl;
	}
      else if (strcmp(input, "print") == 0)
	{
	  // print the table, starting from index 1, # of indents starts at 0
	  print(tree, 1, 0);
	  cout << "" << endl;
	}
      else if (strcmp(input, "quit") == 0)
	{
	  editing = false;
	}
    }
return 0;
}

/**
 * This function adds the data value into your max heap
 * @param tree | this is the heap
 * @param data | the value being entered
 * @param i | current index we are walking through
 */
void insert(int* &tree, int treeSize,  int i)
{
  bool fullTree = true;
  for (int i = 1; i < treeSize - 1; i++)
    {
      if (tree[i] == 0)
	{
	  fullTree = false;
	}
    }
  
  cout << "added value: " << tree[i] << endl;

  if ((i * 2) < treeSize && (i * 2 + 1) < treeSize && i < treeSize)
    {
  // check if your parent (floor(i/2), with i as the current index) < current
  int parent = tree[(int)(i/2)];
  if (parent !=0 && parent < tree[i])
    {
      // swap parent with child
      int temp = parent;
      tree[(int)(i/2)] = tree[i];
      tree[i] = temp;

      // move up one generation
      i /= 2;
      insert(tree, treeSize, i);

    }
  else
    {
      cout << "we are here." << endl;
    }
    }

}

void remove(int* &tree, int i)
{

  int treeSize = 101;
  if (tree[i] != 0 && (2 * i) < treeSize)
    {
      cout << "entered" << endl;
      // check the children and swap with the larger one
      if (tree[2 * i] != 0 &&
	  tree[i] < tree[2 * i] &&
	  tree[2 * i] >= tree[2 * i + 1])
      {
	// the left child is larger than the parent and the right child
	// swap the parent and the left child
	int temp = tree[2 * i];
	tree[2 * i] = tree[i];
	tree[i] = temp;

	// move down the tree
	remove(tree, (i * 2));
      }
      else if (tree[2 * i + 1] != 0 &&
	  tree[i] < tree[2 * i + 1] &&
	  tree[2 * i + 1] >= tree[2 * i])
      {
	// the right child is larger than the left child             
	// swap the parent and the left child                                       
	int temp = tree[2 * i + 1];
	tree[2 * i + 1] = tree[i];
	tree[i] = temp;

	remove(tree, (i * 2 + 1));
      }
    }
}

/**
 * This function creates a visual representation of the max heap. 
 * @param tree | this is the max heap structure
 * @param i | this is the current index we are working with
 * @param numTabs | this will keep track of how many indents to make
 */
void print(int* tree, int i, int numTabs)
{
  if (tree[i] == 0)
    {
      return; // there is nothing in the table, or we've reached a leaf
    }

  // else if the tree is not empty
  numTabs += 1; // indent one more in

  // recursively move down by moving to the right child each time
  print(tree, (2 * i + 1), numTabs);

  // IMPORTANT NOTE!
  // once we reach the last child (the leaf), we can no longer move down
  // to another child. This means that when we call the print function
  // from above, the parameter (2 * i + 1) = 0. Thus, we jump into the
  // if statement several lines above and return, exiting the print function.
  // however, since we had called print recursively, when we
  // jump out of print(tree, (2 * i + 1), numTabs), we end up on the line below

  cout << endl;
  for (int i = 1; i < numTabs; i++)
    {
      // indent the number of times as stated by numTabs
      cout << "\t";
    }
  cout << tree[i] << "\n"; // print value here

  print(tree, (2 * i), numTabs); // same idea for the left child
  

  
}
