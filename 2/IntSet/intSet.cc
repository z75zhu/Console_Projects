#include "intSet.h"
#include <iostream>
#include <string>
using namespace std;

//constructor
intSet::intSet(){
    data = nullptr;
    size = 0;
    capacity = 0;
}

//destructor
intSet::~intSet() {
    delete [] data;
}

//copy constructor
//x = new intSet(is);
intSet::intSet(const intSet& is) : size{is.size},capacity{is.capacity}{
    //this->size = is.size;
    //this->capacity = is.capacity;
    if (is.data==nullptr){
        this->data = nullptr;
    }else{
        this->data = new int [is.capacity];
    }
       for (int i = 0; i<size ; i++){
        this->data[i]= is.data[i];
    }
}
//move constructor
intSet::intSet(intSet &&is):size{is.size},capacity{is.capacity}{
    //data is an array;
    data = is.data;
    is.data = nullptr;
}

//copy assignment operator
intSet& intSet::operator=(const intSet& is){
    if (*this == is){
        return *this;
    }else{
        delete [] data;
        size = is.size;
        capacity = is.capacity;
        if(is.data==nullptr){
            return *this;
        }else{
            data = new int [is.capacity];
            for (int i = 0; i<size ; i++){
                data[i]= is.data[i];
            }
            return *this;
        }
    }
    //intSet x
    //intSet y
    //x=y
}
//move assignment operator using swap implemented
intSet& intSet::operator=(intSet &&is){
    swap(is);
    return *this;
}

//swap two intSet
void intSet::swap(intSet &is){
    int *tempdata = data;
    int tempsize = size;
    int tempcapacity = capacity;
    data = is.data;
    size = is.size;
    capacity=is.capacity;
    is.data = tempdata;
    is.size = tempsize;
    is.capacity=tempcapacity;
    tempdata=nullptr;
    //delete [] tempdata;
    
}
//set union
intSet intSet::operator|(const intSet &other){
    
    intSet temp;
    temp.data = new int[this->size+other.size];
    temp.size = 0;
    temp.capacity = (this -> capacity + other.size);

    for (int i = 0; i < this->size;i++){
        temp.data[temp.size] = this->data[i];
        temp.size++;
        
    }
    for (int i = 0; i <other.size; i++){
        temp.add(other.data[i]);
    }
    return temp;

}

//set intersection
intSet intSet::operator&(const intSet &other){
    
    intSet temp;
    temp.data = new int[this->size];
    temp.size = 0;
    temp.capacity = this -> capacity;
    for (int i = 0; i < this->size;i++){
        for (int j = 0; j < other.size;j++){
            if (other.data[j] == this->data[i]){
                temp.data[temp.size] = this->data[i];
                temp.size++;
            }
        }
        
    }
    temp.Sort();
    return temp;
}

//check equality print 1 if equal
bool intSet::operator==(const intSet &other){
    if (this->size != other.size){
        return 0;
    }else{
        for (int i = 0; i<other.size;i++){
            if(this->data[i]!=other.data[i]){
                return 0;
            }
        }
        return 1;
    }

}
// Print 1 if s is subset of this, 0 otherwise.
bool intSet::isSubset(const intSet s){

    if  (this->size<s.size){
        return 0;

    }else if(s.size == 0){
        return 1;

    }
    else{
        int howmanysame = 0;
        for (int m= 0; m < s.size ; m++)
        {
            for (int n= 0; n<this->size; n++)
            {
                if (s.data[m]==this->data[n]){
                    howmanysame++;
                }
            }
        }
        if (howmanysame == s.size){
            return 1;
        }else{
            return 0;
        }
    }
}
//check if contains e
//print 1 if it does
bool intSet::contains(int e){
    
    for (int i = 0 ; i <size; i++){
        if(this->data[i] == e)
            return 1;
    }

    return 0;
}
//add to the data, with a sort and array expansion
void intSet::add(int e){
    if (data == nullptr){
        data = new int[5];
        capacity = 5;
    }else if(size == capacity){
        int *temp = new int [capacity*2];
        for (int i = 0 ; i <size; i++){
            temp[i] = data[i];
        }
        capacity = capacity*2;
        delete [] data;
        data = temp;

    }
    for (int k = 0; k<size; k++){
        if (data[k]==e){
            return;
        }
    }
    data[size] = e;
    size++;
    this->Sort();
}
//remove the e
void intSet::remove(int e){
    if (!this->contains(e)){
        return;
    }
    int *x = new int[this->capacity];
    int newsize = 0;
    for (int i = 0; i< size; i++){
        if(data[i]!=e){
            x[newsize]=data[i];
            newsize++;
        }
    }
    size --;
    delete [] data;
    data = x;
}
//selection sort
void intSet::Sort(){

        for (int m= 0; m < size -1 ; m++)
        {
            int smallest = m;
            for (int n=m+1; n<size; n++)
            {
                if (data[n] < data[smallest])
                    smallest = n;
            }
            int temp = data[smallest];
            data[smallest] = data[m];
            data[m] = temp;
        }

}
//print the thing to out
std::ostream& operator<<(std::ostream& out, const intSet& is){
    
    for (int i =0; i<is.size ; i++){
        if (i == 0){
            out<<"(";
        }
        out<<is.data[i];
        if(i+1 < is.size){
            out<<",";
        }
        else{
            out<<")";
        }
    }
    if (is.size==0){
        out<<"()";
    }
    return out;
}


