#include "mastermind.h"
#include <cstdlib>
#include <iostream>
using namespace std;
//constructor for my Mastermind Object and use srand() for seed
Mastermind::Mastermind(int seed , int codeLength , int guessCount ): seed(seed),codeLength(codeLength),guessLimit(guessCount),code(nullptr),usercode(nullptr){
    srand(seed);
}

//this will get a passcode using rand()
void getPassCode (char passCode[],int size){
    for (int i = 0; i < size; i++){
        int random = rand() % 6; //arrange from 0-5
        switch(random%6)
        {
            case 0 :
                passCode[i]='A';
                break;
            case 1 :
                passCode[i]='B';
                break;
            case 2 :
                passCode[i]='C';
                break;
            case 3 :
                passCode[i]='D';
                break;
            case 4 :
                passCode[i]='E';
                break;
            case 5 :
                passCode[i]='F';
                break;
        }
    }
}
//this function reads the use's input
//with case insensitive 
//and clear cin in the end
void readInput(char userCode[],int size){
    int guessedSize=0;
    
    while (guessedSize<size){
        char x;
        cin>>x;
        switch(x)
        {
            case 'A' :
            case 'a' :
                userCode[guessedSize]='A';
                guessedSize++;
                break;
            case 'B' :
            case 'b' :
                userCode[guessedSize]='B';
                guessedSize++;
                break;
            case 'C' :
            case 'c' :
                userCode[guessedSize]='C';
                guessedSize++;
                break;
            case 'D' :
            case 'd' :
                userCode[guessedSize]='D';
                guessedSize++;
                break;
            case 'E' :
            case 'e' :
                userCode[guessedSize]='E';
                guessedSize++;
                break;
            case 'F' :
            case 'f' :
                userCode[guessedSize]='F';
                guessedSize++;
                break;
        }
    }
    cin.clear();
    cin.ignore();
}
//destructor to delete two arrays I allocated on heap when program finished
Mastermind::~Mastermind(){
    delete [] usercode;
    delete [] code;
}
//this get number of blacks and white
//using two boolean array, one for code one for user
void getBW(const char passCode[],const char userCode[],const int size,int &black,int &white){
    bool forcode [size];
    bool forguess [size];
    
    for (int i = 0 ; i < size ; i++){
        forcode[i] = forguess[i] = false;
    }
    //for black
    // set both array to true if same position and they are equal
    for (int i = 0 ; i < size ; i++ ){
        if (passCode[i]==userCode[i]){
            forcode[i] = forguess[i]= true;
            black ++;
        }
    }
    //for white
   //set the postion to be true if at some position i in code and j in forguess, they are equal
    for (int i = 0 ; i < size ; i++ ){
        for (int j = 0 ; j < size ; j++ ){
            if((forguess[j]==true) || (forcode [i]==true) ){
                
            }else if (userCode[j]==passCode[i]){
                forcode[i] = forguess[j]=true;
                white++;
            }
            
        }
    }
    
    
}

//this function plays the game and has a recursion in the end
void Mastermind::playGame() {
    int size = this->codeLength;
    int count = this->guessLimit;
    this->code = new char [size];
    this->usercode = new char [size];
    getPassCode(this->code,size);
    cout<<"Welcome to Mastermind! Please enter your first guess."<<endl;
    //this loop for number of chances the user get to play
    while(count>0){
        int black = 0;
        int white = 0;
        
        bool match = true;
        readInput(this->usercode,size);
        
        getBW(code,usercode,size,black,white);
        count-- ;
        
        
        for (int i = 0; i<size ;i++){
            if(code[i]!=usercode[i]){
                match = false;
            }
        }
        if (match==true){
            cout << "You won in guessCount guesses!"<<endl;
            break;
        }
        else if ((!match)&&(count>0)){
            cout<<black<<"b, "<<white<<"w"<<endl;
            cout<<(count)<<" guesses left. Enter guess:"<<endl;
        }else if ((!match)&&(count==0)){
            cout<<black<<"b, "<<white<<"w"<<endl;
            cout<<"You lost! The password was: "<< endl;
            for (int ii = 0; ii<size ; ii++ ){
                cout<<code[ii];
            }
            cout<<endl;
        }
    }
    cout<<"Would you like to play again? (Y/N):"<<endl;
    char s;
    cin>>s;
    //if  Y or y delele the array allocated on heap, since next time call playgame will allocate a new one
    //otherwise, exit
    if ((s=='Y') ||(s=='y')){
        delete [] usercode;
        delete [] code;
        playGame();
    }
    
    
}

