//Jay Rosen
//COP2551.0M1
//This program reads rainfall.txt and sorts the data into descending order based on monthly rainfall.
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// SortRainfall class declaration
class SortRainfall
{
private:
	string name;	//Store the array for the named months
	double rain;	//Store the array for the rainfall double data
	ifstream txt;	//Store rainfall.txt file

public:
	void getTxt();									//To open rainfall.txt file		
	void selectionSort(double[], int, string[]);	//To sort the parallel arrays in descending order
	void showArray(const double[], int, string[]);	//To display the sorted parallel arrays

}; // End SortRainfall class declaration


   // Program that uses the SortRainfall class

   /**************************************************************
   *               SortRainfall::getTxt                          *
   * This function reads the data of rainfall.txt                *
   * and initalizes the parallel arrays for both the name of the *
   * month and the corresponding rainfall for that month.        *
   * The parallel arrays are then passed to the functions        *
   * selectionSort and showArray.								  *
   **************************************************************/
void SortRainfall::getTxt()
{
	// The number of months of the year
	const int MONTHS = 12;

	// name is an array of 12 strings, initalized to the named months of the year
	string name[MONTHS] =
	{ "January", "February", "March", "April",
		"May", "June", "July", "August",
		"September", "October", "November", "December" };

	//rain is an array of 12 doubles, not yet initalized
	double rain[MONTHS];
	int count = 0;

	//open and check if the rainfall.txt file is accessible to program
	ifstream txt;
	txt.open("rainfall.txt");
	if (!txt)
		cout << "Error opening data file\n";

	//initalize the rain array with the 12 line items of the rainfall.txt
	else
	{
		while (count < MONTHS && txt >> rain[count])
			count++;
		txt.close();

		//Display the parallel arrays for name of month and monthly raindall after reading the file
		for (count = 0; count < MONTHS; count++)
		{
			cout << "\t\t\t" << name[count] << setw(6) << "\t" << setprecision(3) << rain[count] << endl;
		}

		cout << "\n\n\t\t";
	}

	cout << "The months with the most rainfall were : \n\n";

	//Pass the arrays and number of elements to selectionSort function
	selectionSort(rain, MONTHS, name);

	//Pass the arrays and number of elements to showArray function
	showArray(rain, MONTHS, name);
}



/**************************************************************
*               SortRainfall::selectionSort                       *
* This function performs a descending-order selection sort        *
* on the array. The parameter size holds the number of elements   *
* in the array.Tthe parameter name holds array of months.         *
**************************************************************/
void SortRainfall::selectionSort(double array[], int size, string name[])
{
	//Two counters to be used in nested loops
	int i;
	int j;

	//Temporary variable to hold the lowest rainfall data for each pass
	int lowest;

	for (i = 0; i < size; i++)
	{
		lowest = i;

		for (j = i; j < size; j++)
		{
			// determine if the element is greater than the lowest, it is the new lowest for this pass
			if (array[j] > array[lowest])

			{
				lowest = j;

				// swap the variables for the rainfall array with the temporary double variable
				double tempDouble = array[i];
				array[i] = array[j];
				array[j] = tempDouble;

				// swap the variables for the named months array with temporary string variable
				string tempString = name[i];
				name[i] = name[j];
				name[j] = tempString;
			}
		}
	}
}


/*************************************************************
*                        SortRainfall::showArray                *
* This function displays the contents of the now sorted array.  *
* Parameter size holds the number of elements in the array.     *
* Parameter name holds the array for months						*
*************************************************************/
void SortRainfall::showArray(const double array[], int size, string name[])
{
	//Loop 12 times, displaying the new values for the parallel arrays
	for (int count = 0; count < size; count++)
		cout << "\t\t\t" << name[count] << setw(6) << "\t" << setprecision(3) << array[count] << endl;

	cout << endl;
}


//Main Program


int main()
{
	SortRainfall RainMeter;

	cout << "\n\n\t\tThe average monthly rainfall for year 20XX :\n\n";

	RainMeter.getTxt();

	cout << "\n\n\t\t";

	system("pause");

	return 0;
}



