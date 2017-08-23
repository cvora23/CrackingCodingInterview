/*
 * UrilifyString.cpp
 *
 *  Created on: Aug 21, 2017
 *      Author: chivora
 */
#include <iostream>
#include <string.h>         // std::string
#include <stdlib.h>

using namespace std;

void UrilifyString(char* str,int length){
	int actual_length = 0;
	char* temp = str;
	while(*temp != NULL){
		cout<<"actual_length = "<<actual_length++<<endl;
		temp++;
	}
	length--;
	actual_length--;
	for(int i=length;i>=0;i--)
	{
		// If we found a space
		if(*(str+i) == ' '){
			*(str+actual_length) = '0';
			actual_length--;
			*(str+actual_length) = '2';
			actual_length--;
			*(str+actual_length) = '%';
			actual_length--;
		}else{
			cout<<"*(str+actual_length) = "<<*(str+actual_length)<<endl;
			cout<<"*(str+i) = "<<*(str+i)<<endl;

			*(str+actual_length) = *(str+i);
			actual_length--;
		}
	}

}


int main(){

	char* str = (char*)malloc(100);
	strcpy(str,"Mr John Smith    ");
	cout<<"Before urilifystring, str = "<<str<<endl;
	UrilifyString(str,13);
	cout<<"After urilifystring, str = "<<str<<endl;
}


