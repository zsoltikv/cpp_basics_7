#include <iostream> // include the input-output stream library for cin and cout
#include <string>   // include string library for string data type and operations like getline
#include <iomanip>  // include iomanip library for formatted console output like setw and setf

using namespace std; // use the standard namespace to avoid writing std constantly

// define a structure named Worker to group together related data fields for a worker
struct Worker
{
	string name;   // store the full name of the worker as a string
	int salary;    // store the monthly salary of the worker as an integer
	int birthYear; // store the birth year of the worker as an integer
};

int main()
{
	// set the locale to support Hungarian characters in the console output
	setlocale(LC_ALL, "hu_HU.UTF-8");

	// -------------------------------------------------------------------------------
	// --- 1. WORKER DATA COLLECTION AND RANDOM GENERATION ---
	// -------------------------------------------------------------------------------

	// declare an array of 5 Worker structures to store information for 5 employees
	Worker workers[5];

	// seed the pseudo-random number generator using current system time to get different results on each run
	srand(time(NULL));

	// loop 5 times to gather and generate details for each worker
	for (int i = 0; i < 5; i++)
	{
		// prompt the user to enter the worker name with 1-based indexing for display
		cout << "Enter the " << i + 1 << ". worker's name: ";

		// read the complete line of text including spaces into the worker name variable
		getline(cin, workers[i].name);

		// use a do-while loop for input validation to ensure salary falls within the valid range of 200000 to 700000
		do
		{
			// prompt the user to enter the salary
			cout << "Salary: ";

			// read the integer salary value from the input stream
			cin >> workers[i].salary;

			// clear the leftover newline character from the input stream buffer so getline works correctly in the next iteration
			cin.ignore();

		} while (workers[i].salary < 200000 || workers[i].salary > 700000); // repeat if salary is outside the specified limits

		// generate a random birth year between 1980 and 2000 (rand() % 21 produces 0-20, adding 1980 shifts range to 1980-2000)
		workers[i].birthYear = rand() % 21 + 1980;

	}

	// -------------------------------------------------------------------------------
	// --- 2. FORMATTED DISPLAY OF WORKER INFORMATION ---
	// -------------------------------------------------------------------------------

	// set left-alignment flag on cout so formatted fields align to the left side
	cout.setf(ios::left);

	// print header message for the worker information table
	cout << "\n\nWorker Information:\n\n";

	// iterate through the workers array to print each worker details in formatted columns
	for (int i = 0; i < 5; i++)
	{
		// print a tab space followed by left-aligned fields with widths 25 for name, 8 for salary, and 6 for birth year
		cout << "\t" << setw(25) << workers[i].name << setw(8) << workers[i].salary << setw(6) << workers[i].birthYear << endl;
	}

	// -------------------------------------------------------------------------------
	// --- 3. CALCULATING AVERAGE SALARY ---
	// -------------------------------------------------------------------------------

	// declare and initialize an accumulator variable to calculate total salaries
	int salaryAverage = 0;

	// iterate through the workers array to sum up all salaries
	for (int i = 0; i < 5; i++)
	{
		// add current worker salary to the total sum accumulator
		salaryAverage += workers[i].salary;
	}

	// perform integer division by total number of workers to calculate average salary
	salaryAverage /= 5;

	// display the calculated average salary value
	cout << "\nAverage salary: " << salaryAverage << endl;

	// -------------------------------------------------------------------------------
	// --- 4. LINEAR SEARCH FOR SALARY OF EXACTLY 500,000 ---
	// -------------------------------------------------------------------------------

	// declare and initialize an index variable to start linear search from index 0
	int i = 0;

	// search through the array while staying within bounds and while salary is not equal to 500000
	while (i < 5 && workers[i].salary != 500000)
	{
		// increment index to inspect the next worker
		i++;
	}

	// check if the loop stopped before reaching the end of the array, meaning a salary of 500000 was found
	if (i < 5)
	{
		// print message confirming a worker with exactly 500000 salary was found
		cout << "There is salary bigger then 500.000" << endl;
	}
	else
	{
		// print message confirming no worker has a salary of exactly 500000
		cout << "There is no salary bigger then 500.000" << endl;
	}

	// -------------------------------------------------------------------------------
	// --- 5. FINDING YOUNGEST WORKER AND LEAST SALARY WORKER ---
	// -------------------------------------------------------------------------------

	// declare and initialize index tracking variables to 0 (assume first element is initial candidate)
	int youngestWorkerIndex = 0;
	int LeastSalaryIndex = 0;

	// iterate through the array to find extreme values for salary comparison
	for (int i = 0; i < 5; i++)
	{
		// Note: The logic compares salaries, updating youngestWorkerIndex if a higher salary is found
		if (workers[i].salary > workers[youngestWorkerIndex].salary)
		{
			// update index of the worker with the highest salary
			youngestWorkerIndex = i;
		}

		// check if the current worker salary is less than the current minimum salary
		if (workers[i].salary < workers[LeastSalaryIndex].salary)
		{
			// update index of the worker with the lowest salary
			LeastSalaryIndex = i;
		}
	}

	// display the name and salary of the worker tracked by youngestWorkerIndex
	cout << "\nThe youngest worker is: " << workers[youngestWorkerIndex].name << " with salary: " << workers[youngestWorkerIndex].salary << endl;

	// compare whether the same worker holds both index positions
	if (youngestWorkerIndex == LeastSalaryIndex)
	{
		// print message if the worker index matches both conditions
		cout << "The youngest worker also has the least salary." << endl;
	}
	else
	{
		// print message if different workers hold these conditions
		cout << "The youngest worker does not have the least salary." << endl;
	}

	// return 0 to indicate that the program executed successfully
	return 0;

}