/*
 * UniqueChars.cpp
 *
 *  Created on: Jul 10, 2017
 *      Author: chivora
 */
#include <iostream>
#include <map>
#include <bitset>
#include <string>         // std::string
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
#define NUM_CHARS 255
/*
 * Hint:
 * 1: Hash Table
 * 2: Bit Vector
 * 3: O(N log N) time solution - Without using external Data Structures
 */

bool checkIfUniqueChars(string str){
	bool result = true;
	std::map<char,int> mymap;
    std::map<char,int>::iterator it;

	for(unsigned int i=0;i<str.length();i++){
		it = mymap.find(str[i]);
		if(it != mymap.end()){
			result = false;
			break;
		}else{
			mymap[str[i]] = 1;
		}
	}
	return result;
}

bool checkIfUniqueChars2(string str){
	bool result = true;
	bitset<NUM_CHARS> myBitSet;
	for(unsigned int i=0;i<str.length();i++){
		if(myBitSet[str[i]] > 0){
			result = false;
			break;
		}else{
			myBitSet[str[i]] = 1;
		}
	}
	return result;
}

bool checkIfUniqueChars3(string str){
	bool result = true;
	std::sort(str.begin(),str.end());
	for(unsigned int i=0;i<str.length();i++){
		if( (i != str.length()-1) && str[i] != str[i+1]){
//          continue
//			cout<<"i = "<<i<<endl;
//			cout<<"str[i] = "<<str[i]<<endl;
//			cout<<"str[i+1] = "<<str[i+1]<<endl;
		}else if ((i != str.length()-1)){
//			cout<<"i = "<<i<<endl;
//			cout<<"str[i] = "<<str[i]<<endl;
//			cout<<"str[i+1] = "<<str[i+1]<<endl;
			result = false;
			break;
		}
	}
	return result;
}

bool checkIfUniqueChars4(string str){
	int checker = 0;
	for(unsigned int i=0;i<str.length();i++){
		int val = str[i] - 'a';
		if ((checker & (1 << val)) > 0){
			return false;
		}
		checker |= (1 << val);
	}
	return true;
}

int main(){
	cout<<checkIfUniqueChars("Hello")<<endl;
	cout<<checkIfUniqueChars("Hi")<<endl;
	cout<<checkIfUniqueChars("Chintan")<<endl;
	cout<<checkIfUniqueChars2("Hello")<<endl;
	cout<<checkIfUniqueChars2("Hi")<<endl;
	cout<<checkIfUniqueChars2("Chintan")<<endl;
	cout<<checkIfUniqueChars3("Hello")<<endl;
	cout<<checkIfUniqueChars3("Hi")<<endl;
	cout<<checkIfUniqueChars3("Chintan")<<endl;
	cout<<checkIfUniqueChars4("Hello")<<endl;
	cout<<checkIfUniqueChars4("Hi")<<endl;
	cout<<checkIfUniqueChars4("Chintan")<<endl;
}



