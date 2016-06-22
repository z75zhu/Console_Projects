#include <iostream>
using namespace std;

// this function sort the array to the descending order
void Sort(int array[], const int size)
{
     for (int m= size - 1; m > 0; m--)
     {
         int smallest = 0;                 
         for (int n=1; n<=m; n++)   
         {
            if (array[n] < array[smallest])
            smallest = n;
         }
         int temp = array[smallest];   
         array[smallest] = array[m];
         array[m] = temp;
     }
     return;
}

int main() {	
	int sizeOfTypes;
	int total;

	cin >> sizeOfTypes;
    //check if cin is a int
    if (!cin) {
    	cout<<"Impossible"<<endl;
    	return 0;
    }
    //if size is zero, any other given total will result Impossible, 
    //except for total=0 which will just return
    if (sizeOfTypes == 0){
    	cin >> total;
	    if (!cin) {
    		cout<<"Impossible"<<endl;
    		return 0;
    	}
    	if (total == 0){
    		return 0;
    	}else{
    		cout<<"Impossible"<<endl;
    		return 0;
    	}	
    }
    //this is the array for the multiples which has the same size as denominations
    int multiples[sizeOfTypes] = {0};
    //this is the array for different denominations
	int denominations [sizeOfTypes];
	for (int i = 0; i<sizeOfTypes;i++){
		cin >> denominations[i];
 		if (!cin) {
    	cout<<"Impossible"<<endl;
    	return 0;
    	}
	}
	cin >> total;
    if (!cin) {
    	cout<<"Impossible"<<endl;
    	return 0;
    }
    //sort the array
	Sort(denominations,sizeOfTypes);
    //go through the sorted array, if integer division total/denomination is greater than 0
    //assign that result to corresponding multiples[], and change the value of total
    //by using modulus
	for (int i = 0; i<sizeOfTypes;i++){
		if (total/denominations[i]>0)
		{
			multiples[i] = total/denominations[i];
            total = total%denominations[i];
        }
	}
    //if in the end, total is not zero,
    //meaning it is impossible
	if (total != 0){
		cout<<"Impossible"<<endl;
    	return 0;
	}
    //otherwise print the result and skip the zero multiples
	for (int i = 0; i<sizeOfTypes;i++){
		if (multiples[i]!=0){
			cout<<multiples[i]<<" x "<<denominations[i]<<endl;
		}
	}

    return 0;

}

