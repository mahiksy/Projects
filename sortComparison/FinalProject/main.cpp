//Mohammed Khoshkhoiyazdi
//Final project
//CIS 350
// Due Date: 12/7/2021

#include<iostream>
#include<fstream>
#include<time.h>
#include<stdlib.h>
#include<math.h>
#include <iomanip>
#include<ctime>

int compare1 = 0,compare2 = 0,compare3 = 0;
long double CPU1 = 0, CPU2 = 0, CPU3 = 0;
using namespace std;

//desc: creating a rand sequence
//pre: n and p should have been asigned a value
//post: the random sequence with size n and ramdomazied based on p value has been created and the pointer of this sewuence has been returned
int* rand_seq(int n, double p)
{
	srand(time(0));
	int* s = new int[n];
	for (int i = 0; i < n; i++)
	{
		s[i] = i;
	}
	double g = n * p;
	int m = ceil(g);
	for (int k = 0; k < m ; k++)
	{
		int i = rand() % (n - 1);
		int j = rand() % (n - 1);
		int x = s[i];
		s[i] = s[j];
		s[j] = x;
	}
	return s;
}

//desc: combine the solutions of two subsets into a solution for the actual sequence
//post: the pointer arr and left, mid and right must have values.
//pre: the elements have been put back in the arr and they have been sorted.
void merge( int* arr, int left, int mid, int right)
{
	int sub_one = (mid - left)+1;
	int sub_second = right - mid;
	int* sub1 = new int[sub_one];
	int* sub2 = new int[sub_second];

	for (int i = 0; i < sub_one; i++)
	{
		sub1[i] = arr[i+left];
	}
	for (int j = 0; j < sub_second; j++)
	{
		sub2[j] = arr[j + 1 + mid];
	}
	int a = 0, b = 0, c = left;
	while (a < sub_one && b < sub_second)
	{
		if (sub1[a] <= sub2[b])
		{
			compare3++;
			arr[c] = sub1[a];
			a++;
		}
		else
		{
			compare3++;
			arr[c] = sub2[b];
			b++;
		}
		c++;
	}
	while (a < sub_one)
	{
		arr[c] = sub1[a];
		a++;
		c++;
	}
	while (b < sub_second)
	{
		arr[c] = sub2[b];
		b++;
		c++;
	}

}
//desc: sorting sequence with merge sorting
//pre: poitner a and beign and end must have values.
//post: the sequence in 'a' has been sorted.
void mergeSort(int* a,int begin,int end)
{
	if (begin>=end)
	{
		return;
	}
	int mid = (begin +end)/ 2;
	// int* sub1= int new [mid]
	//int* sub2=int new[mid]
	//if it was odd then sub2=int new[mid+1];
	mergeSort(a, begin,mid);
	mergeSort(a, mid+1,end);
	merge(a, begin, mid, end);
}

//desc: swapping two values.
//pre: the element1 and element 2 must have values
//post: the values that element2 and element 2 are pointing have been swapped with eachother.
void swap(int* element1, int* element2)
{
	int* obj = element1;
	element1 = element2;
	element2 = element1;
}

//desc: partition step of quick sort determinestic
//pre: arr, first and last must have vlaues
//post: the value of i+1 has been returned
int partition(int* arr, int first, int last)
{
	//defining my piviot
	int pivot = arr[last];
	int i = (first - 1);
	for (int j = first; j < last; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap(arr[i], arr[j]);
		}
		compare1++;
	}
	swap(arr[i + 1], arr[last]);
	return (i + 1);
}

//desc: sorting a sequence with quick sort determinestic
//pre: arr first and last must have values.
//post: the sequence pointed by arr has been sorted.
void QuickSort_deter(int* arr, int first, int last)
{
	if (first < last)
	{
		int pi = partition(arr, first, last);
		QuickSort_deter(arr, first, pi - 1);
		QuickSort_deter(arr, pi + 1, last);
	}
}

//desc: partition step of quick sort random
//pre: arr, first and last must have vlaues
//post: the value of i+1 has been returned
int partition_rand(int* arr, int first, int last)
{
	//finding a random pivot
	srand(time(0));
	int piv_ran = first + rand() % (last - first);
	swap(arr[piv_ran], arr[last]);// chera inja swap mikonim?
	//chon ma barae inke bedunim random indexemun kojast va betunim track konimesh
	//ba last ya first swap mikonim ta pivotemon yek jae moshakhasi bashe.
	int pivot = arr[last];
	int i = (first - 1);
	for (int j = first; j < last; j++)
	{
		if (arr[j] <= pivot)
		{
			
			i++;
			swap(arr[i], arr[j]);
		}
		compare2++; 
	}
	swap(arr[i + 1], arr[last]);
	return (i + 1);
}

//desc: sorting a sequence with quick sort random
//pre: arr first and last must have values.
//post: the sequence pointed by arr has been sorted.
void QuickSort_rand(int* arr, int first, int last)
{
	if (first < last)
	{
		int pi = partition_rand(arr, first, last);
		QuickSort_rand(arr, first, pi - 1);
		QuickSort_rand(arr,pi+1,last);
	}
}


//desc: reseting 6 vlaues
//pre: tot1,tot2,tot3,tota1,tota2,tota3 must have values.
//pre: all the veriables have been set to 0
void reset(double tot1, double tot2, double tot3,long double tota1, long double tota2, long double tota3)
{
	tot1 = 0;tot2 = 0;tot3 = 0;
	tota1 = 0;tota2 = 0;tota3 = 0;
}
int main()
{
	ofstream myfile;
	myfile.open("code.txt");
	int n[7] = { 10,20,50,100,200,500,1000 };
	double p[5] = { 0.0,0.1,0.2,0.5,1.0 };
	double CI1 = 0, CI2 = 0, CI3 = 0;
	double CI11 = 0, CI22 = 0, CI33 = 0;
	double total1_comp = 0;
	double total2_comp = 0;
	double total3_comp = 0;
	double standard_comp1 = 0;
	double standard_comp2 = 0;
	double standard_comp3 = 0;
	long double CI4 = 0, CI5 = 0, CI6 = 0;
	long double CI44 = 0, CI55 = 0, CI66 = 0;
	long double total1_CPU = 0;
	long double total2_CPU = 0;
	long double total3_CPU = 0;
	long double standard_CPU1 = 0;
	long double standard_CPU2 = 0;
	long double standard_CPU3 = 0;
	double array1[25];
	double array2[25];
	double array3[25];
	long double array4[25];
	long double array5[25];
	long double array6[25];
	

	cout << "Q1= QuickSort Deterministic" << "  " << "Q2= QucikSort Randomized" << endl;
	cout << "M= MergeSort" << endl;
	myfile << "Q1= QuickSort Deterministic" << "  " << "Q2= QucikSort Randomized" << endl;
	myfile << "M= MergeSort" << endl;
	cout << "size" << setw(15) << "P_value" << setw(25) << "Q1_comp" << setw(25) << "CI1" << setw(25) << "CI11" << setw(25) << "standard1" << setw(25)
		<< "Q2_comp" << setw(25) << "CI2" << setw(25) << "CI22" << setw(25) << "standard2" << setw(25) <<
		"M_comp" << setw(25) << "CI3" << setw(25) << "CI33" << setw(25) << "standard3" << setw(25)
		<< "Q1_CPU" << setw(25) << "CI4" << setw(25) << "CI44" << setw(25) << "standard4" <<
		setw(25) << "Q2_CPU" << setw(25) << "CI5" << setw(25) << "CI55" << setw(25) << "standard5" <<
		setw(25) << "M_CPU" <<setw(25) <<"CI6" << setw(25) << "CI66" << setw(25) << "standard6" << endl;
	myfile << "size" << setw(15) << "P_value" << setw(25) << "Q1_comp" << setw(25) << "CI1" << setw(25) << "CI11" << setw(25) << "standard1" << setw(25)
		<< "Q2_comp" << setw(25) << "CI2" << setw(25) << "CI22" << setw(25) << "standard2" << setw(25) <<
		"M_comp" << setw(25) << "CI3" << setw(25) << "CI33" << setw(25) << "standard3" << setw(25)
		<< "Q1_CPU" << setw(25) << "CI4" << setw(25) << "CI44" << setw(25) << "standard4" <<
		setw(25) << "Q2_CPU" << setw(25) << "CI5" << setw(25) << "CI55" << setw(25) << "standard5" <<
		setw(25) << "M_CPU" << setw(25) << "CI6" << setw(25) << "CI66"<< setw(25) << "standard6" << endl;

	for (int i = 0; i < 5; i++)//is p
	{
		for (int j = 0; j < 7; j++)//is n
		{
			for (int k = 0; k < 25; k++)
			{
				int* s = rand_seq(n[j], p[i]);
				int* list1 = new int[n[j]];
				int* list2 = new int[n[j]];
				int* list3 = new int[n[j]];
				for (int z = 0; z< n[j]; z++)
				{
					list1[z] = s[z];
					list2[z] = s[z];
					list3[z] = s[z];
				}

				clock_t  start1 = clock();
				QuickSort_deter(list1, 0, n[j] - 1);
				clock_t end1 = clock();
				clock_t start2 = clock();
				QuickSort_rand(list2, 0, n[j] - 1);
				clock_t end2 = clock();
				clock_t start3 = clock();
				mergeSort(list3, 0, n[j] - 1);
				clock_t end3 = clock();
				CPU1 = (1000.0 * (end1 - start1)) / CLOCKS_PER_SEC;
				CPU2 = (1000.0 * (end2 - start2)) / CLOCKS_PER_SEC;
				CPU3 = (1000.0 * (end3 - start3)) / CLOCKS_PER_SEC;

				//calculating total comp number
				total1_comp = total1_comp + compare1;//quick deter
				array1[k] = compare1;
				total2_comp = total2_comp + compare2;//quick rand
				array2[k] = compare2;
				total3_comp = total3_comp + compare3;//merge
				array3[k] = compare3;
				compare1 = 0; compare2 = 0; compare3 = 0;

				//calculating total cpu
				total1_CPU = total1_CPU + CPU1;// qucik deter
				array4[k] = CPU1;
				total2_CPU = total2_CPU + CPU2;// quick rand
				array5[k] = CPU2;
				total3_CPU = total3_CPU + CPU3;// merge
				array6[k] = CPU3;
				CPU1 = 0; CPU2 = 0; CPU3 = 0;
			}
			
			//calculating mean
			total1_comp = total1_comp / 25;
			total2_comp = total2_comp / 25;
			total3_comp = total3_comp / 25;
			total1_CPU = total1_CPU / 25;
			total2_CPU = total2_CPU / 25;
			total3_CPU = total3_CPU / 25;

			//calculating standard deviatsion
			for (int g = 0; g < 25; g++)
			{
				standard_comp1 += pow(array1[g] - total1_comp, 2);
				standard_comp2 += pow(array2[g] - total2_comp, 2);
				standard_comp3 += pow(array3[g] - total3_comp, 2);
				standard_CPU1 += pow(array4[g] - total1_CPU, 2);
				standard_CPU2 += pow(array5[g] - total2_CPU, 2);
				standard_CPU3 += pow(array6[g] - total3_CPU, 2);
			}
			standard_comp1 = sqrt(standard_comp1 / 25);
			standard_comp2 = sqrt(standard_comp2 / 25);
			standard_comp3 = sqrt(standard_comp3 / 25);
			standard_CPU1 = sqrt(standard_CPU1 / 25);
			standard_CPU2 = sqrt(standard_CPU2 / 25);
			standard_CPU3 = sqrt(standard_CPU3 / 25);

			//calcualting CI 95%
			CI1 = total1_comp - ((1.96 * standard_comp1) / sqrt(25));
			CI11 = total1_comp + ((1.96 * standard_comp1) / sqrt(25));
			CI2 = total2_comp - ((1.96 * standard_comp2) / sqrt(25));
			CI22 = total2_comp + ((1.96 * standard_comp2) / sqrt(25));
			CI3= total3_comp - ((1.96 * standard_comp3) / sqrt(25));
			CI33 = total3_comp + ((1.96 * standard_comp3) / sqrt(25));
			CI4= total1_CPU - ((1.96 * standard_CPU1) / sqrt(25));
			CI44 = total1_CPU + ((1.96 * standard_CPU1) / sqrt(25));
			CI5= total2_CPU - ((1.96 * standard_CPU2) / sqrt(25));
			CI55 = total2_CPU + ((1.96 * standard_CPU2) / sqrt(25));
			CI6= total3_CPU - ((1.96 * standard_CPU3) / sqrt(25));
			CI66 = total3_CPU + ((1.96 * standard_CPU3) / sqrt(25));

			//printing out the result
			cout << n[j] << setw(15) << p[i] << setw(25) << total1_comp << setw(25) <<CI1<< setw(25) <<CI11<< setw(25)<< standard_comp1<<setw(25)<<total2_comp << setw(25)
			 << CI2 << setw(25) << CI22<< setw(25) << standard_comp2 << setw(25) << total3_comp << setw(25) <<CI3<< setw(25) <<CI33 << setw(25) << standard_comp3 << setw(25) << total1_CPU << setw(25) <<
				CI4<< setw(25) <<CI44 << setw(25) << standard_CPU1<<setw(25)<< total2_CPU << setw(25) <<CI5<< setw(25) <<CI55 << setw(25) << standard_CPU2 << setw(25)
				<< total3_CPU << setw(25) <<CI6<< setw(25) <<CI66 << setw(25)<< standard_CPU1 << endl;
			myfile<< n[j] << setw(15) << p[i] << setw(25) << total1_comp << setw(25) << CI1 << setw(25) << CI11 << setw(25) << standard_comp1 << setw(25) << total2_comp << setw(25)
				<< CI2 << setw(25) << CI22 << setw(25) << standard_comp2 << setw(25) << total3_comp << setw(25) << CI3 << setw(25) << CI33 << setw(25) << standard_comp3 << setw(25) << total1_CPU << setw(25) <<
				CI4 << setw(25) << CI44 << setw(25) << standard_CPU1 << setw(25) << total2_CPU << setw(25) << CI5 << setw(25) << CI55 << setw(25) << standard_CPU2 << setw(25)
				<< total3_CPU << setw(25) << CI6 << setw(25) << CI66 << setw(25) << standard_CPU1 << endl;
			
			//reseting
			reset(total1_comp, total2_comp, total3_comp, total1_CPU, total2_CPU, total3_CPU);
			reset(standard_comp1, standard_comp2, standard_comp3, standard_CPU1, standard_CPU2, standard_comp3);
			reset(CI1, CI2, CI3, CI4, CI5, CI6);
			reset(CI11, CI22, CI33, CI44, CI55, CI66);
		}

	}

	myfile.close();
}