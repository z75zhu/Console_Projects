#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(int argc, char *argv[]) {
	int indent=0;
    bool startingOftheLine=true;
	string inputword;
    //keep getting standard inputs	
    while(cin>>inputword){
        //if its a ; check if its at the starting of the line if yes check for indentation
        //if no print a space before it and go other line with reset for startoftheline
        if (inputword == ";"){
            if (!startingOftheLine){
                cout<<" ";
            } else {
                for (int i = 0 ; i< indent ; i++){
                    cout<<" ";
                }
            }
            cout<<inputword<<endl;
            startingOftheLine = true;
        //check if { is at the starting of the line
        //add the indent in the end
        }else if (inputword == "{"){
            if (!startingOftheLine){
                cout<<" ";
            } else {
                for (int i = 0 ; i< indent ; i++){
                    cout<<" ";
                }
            }
            cout<<inputword<<endl;
            startingOftheLine = true;
            indent++;
        //same as {, but { will be its own line, and 
        //decrease the indent in the end
        }else if (inputword =="}"){
            if (!startingOftheLine){
                cout<<endl;
            }
            indent-- ;
            for (int i = 0 ; i< indent ; i++){
                cout<<" ";
            }
            cout<<inputword<<endl;
            startingOftheLine = true;
        // if "//" gets read just get the whole line after
        }else if (inputword == "//"){
            if (startingOftheLine){
                for (int i = 0 ; i< indent ; i++){
                    cout<<" ";
                }  
            }
            string comments;
            getline(cin, comments);
            cout<<"//"<<comments<<endl;
            startingOftheLine = true;

        }else{
        //anything else check for indent first then print
            if (startingOftheLine){
                for (int i = 0 ; i< indent ; i++){
                    cout<<" ";
                }  
                cout<<inputword;
                startingOftheLine= false;
            }else{
                cout<<" "<<inputword;
            }
        }
    	

	}


}

