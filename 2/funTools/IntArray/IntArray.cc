#include <iostream>
using namespace std;

struct IntArray {
  int size;
  int capacity;
  int *contents;
  //this is the default constructor for IntArray
  IntArray(){
    this->size = 0;
    this->capacity = 0;
    this->contents = nullptr;
  }
};

//this will double the capacity of the array
//by creating an new array and copies all the contents
//reset the pointer and destroy the old one
void doubleCapacity(IntArray& ia){
  int *x = new int [ia.capacity*2];
  for (int i = 0 ; i <ia.size; i++){
    x[i] = ia.contents[i];
  }
  ia.capacity = ia.capacity*2;
  delete [] ia.contents;
  ia.contents = x;

}

IntArray readIntArray(){
  int x;

  IntArray array;
  while ((cin>>x)&&(!cin.eof()))
  {

    if (array.capacity==0){
      array.capacity = 5;
      array.contents = new int[5];
    }
    //if the size == capacity, since I use size as index first then increment the size
    //this is already out of scope, so I need to double the capacity
    if (array.size == array.capacity)
       doubleCapacity(array);
    
    array.contents[array.size] = x;
    array.size++;

  }
  //clear the cin, then ignore
  cin.clear();
  cin.ignore();
  return array;

}


void addToIntArray(IntArray& ia){
  int x;
    while ((cin>>x)&&(!cin.eof()))
  {

    if (ia.capacity==0){
      ia.capacity = 5;
      ia.contents = new int[5];
    }
    if ((ia.size) >= ia.capacity)
      doubleCapacity(ia);

    ia.contents[ia.size] = x;
    ia.size++;
    
  }
  cin.clear();
  cin.ignore();
}
//print the array
void printIntArray(const IntArray& ia){
  for (int i = 0 ; i < ia.size; i++){
    cout<<ia.contents[i]<<" ";
  }
  cout<<endl;
}

// Do not change this function!

int main() {  // Test harness for IntArray functions.
  bool done = false;
  IntArray a[4];
  a[0].contents = a[1].contents = a[2].contents = a[3].contents = nullptr;

  while(!done) {
    char c;
    char which;

    // Note:  prompt prints to stderr, so it should not occur in .out files
    cerr << "Command?" << endl;  // Valid commands:  ra, rb, rc, rd,
                                 //                  +a, +b, +c, +d,
                                 //                  pa, pb, pc, pd, q
    cin >> c;  // Reads r, +, p, or q
    if (cin.eof()) break;
    switch(c) {
      case 'r':
        cin >> which;  // Reads a, b, c, or d
        delete [] a[which-'a'].contents;
        a[which-'a'].contents = nullptr;
        a[which-'a'] = readIntArray();
        break;
      case '+':
        cin >> which;  // Reads a, b, c, or d
        addToIntArray(a[which-'a']);
        break;
      case 'p':
        cin >> which;  // Reads a, b, c, or d
        printIntArray(a[which-'a']);
        cout << "Capacity: " << a[which-'a'].capacity << endl;
        break;
      case 'q':
        done = true;
    }
  }

  for (int i = 0; i < 4; ++i) delete [] a[i].contents;
}