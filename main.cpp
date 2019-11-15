//stiveckamash

// C++ program for implementation of Heap Sort
//max sort and min sort implimentation
#include <iostream>

using namespace std;
int arrayHeap[10];//declare the size of array
int searchX;//the value to be searched
//void get data  a function to accept data
void getData()
{
    for(int i=0; i<10; i++)
    {
        cout<<"Enter an element  "<<i+1<<endl;
        cin>>arrayHeap[i];
    }
}

// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapMaxi(int arrayHeap[], int n, int i)
{
	int largest = i; // Initialize largest as root
	int left = 2*i + 1; // left node = 2*i + 1
	int right = 2*i + 2; // right  node = 2*i + 2

	// If left child is larger than root
	// n stores size
	if (left < n && arrayHeap[left] < arrayHeap[largest])
		largest = left;

	// If right child is larger than largest so far
	if (right < n && arrayHeap[right] < arrayHeap[largest])
		largest = right;

	// If largest is not root
	if (largest != i)
	{
		swap(arrayHeap[i], arrayHeap[largest]);

		// call heapify  by recursive  to the the affected sub-tree
		heapMaxi(arrayHeap, n, largest);
	}
}

// main function to do heap sort
//this makes the looping until everything is max heap sorted
void heapSort(int arrayHeap[], int n)
{
	// Build heap (rearrange array)
	for (int i = n / 2 - 1; i >= 0; i--)//starts at i = root
		heapMaxi(arrayHeap, n, i);

	// One by one extract an element from heap
	for (int i=n-1; i>=0; i--)
	{
		// Move current root to end
		swap(arrayHeap[0], arrayHeap[i]);

		// call max heapify on the reduced heap
		heapMaxi(arrayHeap, i, 0);
	}
}

/* A utility function to print array of size n */
void display(int arrayHeap[], int n)
{
	for (int i=0; i<n; ++i)
		cout << arrayHeap[i] << " ";
	cout << "\n";
}
void searchValue()
{
    cout<<"Please enter the value to search\n";
    cin>>searchX;
}
BinarySearch( int searchX)
{
    int low = 0;
    int high= 9;//array size
    int flag= 0;

    while(low <= high)
        {
        int index = low+(high-low)/2;
        if(arrayHeap[index] == searchX)
        {
            flag = 1;
            cout<<"\nFounded at index: "<<index;
            break;
        }
        else if(arrayHeap[index] < searchX){
            low   = index+1;
        }
        else{
            high = index-1;
        }
    }
    if(flag == 0){
        cout<<"Not Found!!!\n";
    }
}
// main function to do heap sort
//this makes the looping until everything is max heap sorted
void heapSortMaxi(int arrayHeap[], int n)
{
	// Build heap (rearrange array)
	for (int i = n / 2 - 1; i >= 0; i--)//starts at i = root
		heapMaxi(arrayHeap, n, i);

	// One by one extract an element from heap
	for (int i=n-1; i>=0; i--)
	{
		// Move current root to end
		swap(arrayHeap[0], arrayHeap[i]);

		// call max heapify on the reduced heap
		heapMaxi(arrayHeap, i, 0);
	}
}


//mini-heap code functioons
void heapMini(int arrayHeap[], int n, int i)
{
	int smallest = i; // Initialize smallest as root which is at current index
	int left = 2*i + 1; // left node = 2*i + 1
	int right = 2*i + 2; // right  node = 2*i + 2

	// If left child is smaller than root
	// n stores size
	if (left < n && arrayHeap[left] > arrayHeap[smallest])
		smallest = left;

	// If right child is larger than largest so far
	if (right < n && arrayHeap[right] > arrayHeap[smallest])
		smallest = right;

	// If smallest is not root
	if (smallest != i)
	{
		swap(arrayHeap[i], arrayHeap[smallest]);

		// call heapify  by recursive  to the the affected sub-tree
		heapMini(arrayHeap, n, smallest);
	}
}

// main function to do heap sort
//this makes the looping until everything is mini heap sorted
void heapSortMini(int arrayHeap[], int n)
{
	// Build heap (rearrange array)
	for (int i = n / 2 - 1; i >= 0; i--)//starts at i = root
		heapMini(arrayHeap, n, i);

	// One by one extract an element from heap
	for (int i=n-1; i>=0; i--)
	{
		// Move current root to end
		swap(arrayHeap[0], arrayHeap[i]);

		// call max heapify on the reduced heap
		heapMini(arrayHeap, i, 0);
	}
}

//Asking user if he wants to search an element
void askUser()
{
    char x;
    cout<<"Enter y or Y to search an element or any to exit :";
    cin>>x;
    if (x == 'y' || x == 'Y')
    {
    searchValue();
	BinarySearch(searchX);
    }
    else
    {
        cout<<"Exiting..................";
    }
}
// main  program
int main()
{
   //get the size of the node
   int choice;
	int n = sizeof(arrayHeap)/sizeof(arrayHeap[0]);
   getData();
   cout<<"\n\n";
	cout<<"Array before sort is \n"<<endl;
	for(int i=0; i<10; i++)
	{
		cout<<arrayHeap[i]<<" ";
	}
	cout<<"\n";
	//ask the user which sort he wants
	cout<<"+++++++++Please chose a Value for Your sort You need++++++++++\n\n";
	cout<<"1. Do Mini Sort:\n";
	cout<<"2. Do Maxi Sort:\n";
	cout<<" Any Numerical to exit\n";
	cin>>choice;
	if (choice == 1)
    {
        cout<<"\n";
        cout<<"\nMini Heap Array Is \n";
        heapSortMini(arrayHeap, n);
        display(arrayHeap, n);
        askUser();
    }
    else if(choice == 2)
    {
       cout << "\nMaxi Heap Array Is \n";
	   heapSortMaxi(arrayHeap, n);
	   display(arrayHeap, n);
	   askUser();
    }
    else
    {
        cout<<"Exiting............\n";
    }
}

