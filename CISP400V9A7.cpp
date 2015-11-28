// NAME  : Yevgeniy Lankin
// CLASS : CISP 400, Online
// Assignment #: A7
// PURPOSE :
// To show my understanding of vectors, random number generators, quicksort, and suffix functions.
// Software Change (Modifications) Record
// date         what               who
// 11/25/2015   created program    Yev

#include <iostream> // allows program to output data to the screen
#include <iomanip> // parameterized stream manipulators
#include <vector>
#include <ctime>

#define LARGEST_NUM 200 // the largest number to be generated
#define MAX_ELEMENTS 20 // the max of elements per vertex
#define MAX_VECTOR_SIZE 10 // how many vectors we are working with

using namespace std;
void suffix(int i, char suff[]); // function to return a suffix bases on the number passed
void quickSort(vector<int>&, int, int); // function to sort numbers from smallest to largest
int partition(vector<int>&, int, int); // function to  find the first value of the sorted vector

int main()
{
	char suff[4];
	vector<int> randomNums; // vector holding a random num of nums
	srand((int)time(NULL));

	// main for loop, loops "MAX_VECTOR_SIZE" times
	for (int i = 0; i < MAX_VECTOR_SIZE; i++)
	{

		int a = rand() % MAX_ELEMENTS + 1; // create a random number  not geater than MAX_ELEMENTS
		// assign random numbers to a random amount of elemets in a vector
		for (int i = 0; i < a; i++)
		{
			int b = rand() % LARGEST_NUM + 1; // random number not greater than LARGEST_NUM
			randomNums.push_back(b);
		}
		suffix(i + 1, suff); // call suffix function
		cout << "The " << i + 1 << suff << " set of data(" << a << "):" << endl;
		// output original data
		cout << "  Initial vector values are: " << endl;
		cout << "  ";
		for (auto e : randomNums)
		{
			cout << setw(3) << e << "  ";
		}
		cout << endl;
		int p = 0;
		quickSort(randomNums, p, a); // call quickSort function
		// output modified data
		cout << "  The sorted vector values are: " << endl;
		cout << "  ";
		for (auto e : randomNums)
		{
			cout << setw(3) << e << "  ";
		}
		randomNums = {}; // create empty vector
		cout << endl << endl;
	}
	return 0;
} // end main

// function to return a suffix bases on the number passed
void suffix(int i, char suff[])
{
	char suffixes[4][5] = { "th", "st", "nd", "rd" };
	int ord = i % 100;
	if (ord > 3) ord = 0;
	strcpy(suff, suffixes[ord]);
} // end function suffix

// function to sort numbers from smallest to largest
void quickSort(vector<int>& randomNums, int p, int a)
{
	int r;
	if (p < a)
	{
		r = partition(randomNums, p, a);
		quickSort(randomNums, p, r);
		quickSort(randomNums, r + 1, a);
	}
} // end function quicksort

// Partitioning Step : Take the first element of the unsorted vector and 
// determine its final location in the sorted vector(i.e., all values to 
// the left of the element in the vector are less than the element’s value, 
// and all values to the right of the element in the vector are greater than 
// the element’s value—we show how to do this below).We now have one value 
// in its proper location and two unsorted subvectors.
int partition(vector<int>& randomNums, int p, int a)
{
	int x = randomNums[p];
	int i = p;
	int j;

	for (j = p + 1; j < a; j++)
	{
		if (randomNums[j] <= x)
		{
			i = i + 1;
			swap(randomNums[i], randomNums[j]);
		}
	}
	swap(randomNums[i], randomNums[p]);
	return i;
} //end function partion
