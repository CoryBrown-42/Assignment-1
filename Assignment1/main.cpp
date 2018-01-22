/*During the course of the assignment I used the internet to
find references to things I had forgot how to do, like
https://en.wikipedia.org/wiki/Sort_(C%2B%2B)
I tried to alter the examples and used mostly things we have done in class.
Studied and bounced ideas off of Ryann Dyer.

Cory Brown
*/

#include <iostream>
#include <random>
#include <time.h>
#include <vector>
#include <algorithm>

using namespace std;

void DisplayArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << ", ";
	}
	cout << endl;
}

int SearchVector(vector<int> vec, int value)
{
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] == value)
		{
			return i;
		}
	}
	return -1;
}

void FindTheFirstAndThird(int arr[], int size)
{
	for (int i = 0; i< size; i++)
	{
		int picked;
		for (picked = 0; picked < i; picked++)
		{
			if (arr[i] == arr[picked])
			{
				break;
			}
		}
	}
	//finding the first largest value
	int firstHigh = arr[0];
	for (int i = 1; i < size; i++)
	{
		if (arr[i] > firstHigh)
		{
			firstHigh = arr[i];
		}
	}
	//count backwards two, so
	int secondHigh = INT_MIN;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > secondHigh && arr[i] < firstHigh)
		{
			secondHigh = arr[i];
		}
	}
	// Find third largest
	int thirdHigh = INT_MIN; //macro
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > thirdHigh && arr[i] < secondHigh)
		{
			thirdHigh = arr[i];
		}
	}
	cout << endl;
	cout << "The first largest value in the Array: " << firstHigh << endl;
	cout << endl;
	cout << "The third largest value in the Array: " << thirdHigh << endl;
	cout << endl;

}

//original find highest value function
/*
int GetHigh(int arr[], int size)
{
int z = 1;
int high = arr[0];
while (z < size)
{
if (arr[z] > high)
{
high = arr[z];
}
z += 1;
}
return high;
}
*/


//started going through old course videos
//Functor
/*
class SearchByIntFunctor
{
public:
int intToSearchFor;
SearchByIntFunctor(int i) : intToSearchFor(i) {}
bool operator()(int &i)
{
return i == intToSearchFor;
}

};
*/


int main()
{
	/********* Vector ***********/

	vector<int> myVector(1000);
	myVector[0] = 1;
	for (int i = 0; i < 1000; i++) //loop through values 0 - 1000
	{
		myVector[i] = rand() % 2018;
	}
	DisplayArray(myVector.data(), 1000);
	cout << endl;
	cout << "This is an example of a vector containing 1000 random numbers" << endl;
	cout << endl;

	/********** 1. Array ************/

	srand(time(0));      //seed time to 0
	int myArray[1000];  //how large is the array
	myArray[0] = 0;    //set index to 1
	for (int i = 0; i < 1000; i++) //loop through values 0 - 1000
	{
		myArray[i] = rand() % 2018;
	}
	DisplayArray(myArray, 1000);
	cout << endl;
	cout << "This is an example of an array containing 1000 random numbers" << endl;
	cout << endl;


	/********* 2. Search the Array ***********/

	int largest = myArray[1000];
	SearchVector(myVector, 1000);

	//Atempt 1
	/*for (i = 1; i < size; i++)
	{
	if (largest < myArray[i])
	largest = myArray[i];
	}
	auto it = find_if(myVector.begin(), myVector.end(), SearchByIntFunctor(largest));
	if(it != myVector.end())
	{
	cout << "Found" << *it << endl;
	}
	cout << endl;*/

	//Attemp2 w/ functions
	/*
	int largestTrue = 0;
	largestTrue = GetHigh(myArray, 1000);
	cout << endl << "The largest value in the unsorted Array: " << largestTrue << endl;
	cout << endl;
	*/

	//Attempt 3
	/********* 3. Find the 3rd largest unique ***********/

	int g = sizeof(myArray) / sizeof(myArray[0]);
	FindTheFirstAndThird(myArray, g);

	/********* 4. Sort the original Array ***********/

	size_t size = sizeof(myArray) / sizeof(myArray[0]);
	sort(myArray, myArray + size);
	for (size_t i = 0; i < size; ++i)
	{
		//display the sorted array
		cout << myArray[i] << ", ";
	}
	cout << endl << endl << "This is the same Array sorted" << endl;

	/********* 4. Third Largest of the sorted ***********/

	FindTheFirstAndThird(myArray, g);
	cout << endl;

	return 0;

	/********* 5. Which  ***********/
	/*

	I don't think sorting it really matters in this case because when looking at the individual values
	the third largest is always going to be the third largest no matter which order they are in.
	I think the function that finds the third value could also be used to describe the highest value.

	*/
}
