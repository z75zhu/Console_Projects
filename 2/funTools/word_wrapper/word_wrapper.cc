#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(int argc, char *argv[]) {
	int lineLength;
	if (argc == 1){ 
		lineLength = 25;
	}else{
		stringstream convert(argv[1]);
		convert>>lineLength;
	}
	string inputword;
	int usedLength=0;
	string extrachars = "";

    //cout << argc << endl;
    while(cin>>inputword){

    	if (( inputword.length() == lineLength ) && ( usedLength == 0 )){
    		cout<<inputword<<endl;
    	}
    	else if (( inputword.length() < lineLength ) && ( usedLength == 0 )){
    		cout<<inputword;
    		usedLength = usedLength + inputword.length();
    	}
    	else if (( usedLength != 0 ) && ((inputword.length()+1+usedLength) < lineLength )){
    		cout<<" "<<inputword;
    		usedLength = usedLength + inputword.length() + 1;
    	}
    	else if (( usedLength != 0 ) && ((inputword.length()+1+usedLength) == lineLength )){
    		cout<<" "<<inputword<<endl;
    		usedLength = 0;
    	}
    	else if (( usedLength != 0 ) && ((inputword.length()+1+usedLength) > lineLength ) && (inputword.length() <= lineLength)){
    		cout<<endl;
    		cout<<inputword;
    		usedLength = inputword.length();
    	}
    	else if (( usedLength != 0 ) && ((inputword.length()+1+usedLength) > lineLength ) && (inputword.length() > lineLength)){
    		cout<<endl;
    		usedLength = 0;
    		int printedlength = 0;
    		while(printedlength<inputword.length()){
    			for (int i =0; i<lineLength; i++){
    				if (printedlength<inputword.length()){
    					cout<<inputword[printedlength];
    					printedlength++;
    					usedLength++;
    				}
    			}
    			if(usedLength == lineLength){
    				cout<<endl;
    				usedLength = 0;
    			}
    		}
    	}
    	else if (( usedLength == 0 ) && ( inputword.length() > lineLength )){
    		int printedlength = 0;
    		while(printedlength<inputword.length()){
    			for (int i =0; i<lineLength; i++){
    				if (printedlength<inputword.length()){
    					cout<<inputword[printedlength];
    					printedlength++;
    					usedLength++;
    				}
    			}
    			if(usedLength == lineLength){
    				cout<<endl;
    				usedLength = 0;
    			}
    		}
    	}

	}
	//getline(cin, inputword)


}