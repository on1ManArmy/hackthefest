#include <iostream>
using namespace std;
void swap(int *a, int *b)
{
  int t = *a;
  *a = *b;
  *b = t;
}
void printArray(int array[], int size)
{
  int i;
  for (i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}
int partition(int array[], int low, int q)
{
  int pivot = array[q];
  int i = (low - 1);
  for (int j = low; j < q; j++)
  {
    if (array[j] <= pivot)
    {
      i++;
      swap(&array[i], &array[j]);
    }
  }
//  printArray(array, 7);
//  cout << "........\n";
  swap(&array[i + 1], &array[q]);
  return (i + 1);
}
void quickSort(int array[], int low, int q)
{
  if (low < q)
  {
    int pi = partition(array, low, q);
    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, q);
  }
}
int main()
{
    int w, data[100];
   
    int n;
    cout<<"Enter number of elements in the array\n";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>data[i];
    }
     cout<<"Please enter pivot index\n";
    cin>>w;
  //  int q=w-1;
    swap(data[w],data[n-1]);
    //this will run when input failures occurs
    if(cin.fail())
    {
    	cout<<"Invalid input is entered \n";
    	return 0;
	}
//this function will call partition as the function
  quickSort(data, 0, n - 1);
//  cout << "Sorted array in ascending order: \n";
  printArray(data, n);
}
