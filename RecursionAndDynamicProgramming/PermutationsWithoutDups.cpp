/*
 * PermutationsWithoutDups.cpp
 *
 *  Created on: Sep 12, 2017
 *      Author: chivora
 */

#include <iostream>
#include <list>
#include <vector>
#include <map>


using namespace std;

namespace Sol1{

	/*
	 * insert character c at index i in word
	 */
	string insertCharAt(string word,char c,int i){
		string start = word.substr(0,i);
		string end = word.substr(i);
		return start + c + end;
	}

	vector<string> getPerms(string str){
		vector<string> permutations;
		/*
		 * base case
		 */
		if(str.length() == 0){
			permutations.push_back("");
			return permutations;
		}

		char first = str.at(0); // get the first character
		string remainder = str.substr(1); // remove the first character

		vector<string> words = getPerms(remainder);
		for(int i=0;i<words.size();i++){
			for(int j=0;j<=words[i].length();j++){
				string s = insertCharAt(words[i],first,j);
				permutations.push_back(s);
			}
		}
		return permutations;
	}
}


namespace Sol2{

}

int main(){

	vector<string>permutations = Sol1::getPerms("abcd");
	for(int i=0;i<permutations.size();i++){
		cout<<permutations[i]<<endl;
	}

	return 0;

}



