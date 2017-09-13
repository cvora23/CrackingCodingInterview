/*
 * GenerateParenthesis.cpp
 *
 *  Created on: Sep 12, 2017
 *      Author: chivora
 */

#include <iostream>
#include <vector>
#include <map>
#include <vector>
#include <list>
#include <set>

using namespace std;

/*
 * Our first thought here might be to apply a recursive approach where we build the solution for f (n)
 * by adding pairs of parentheses to f (n -1) .That's certainly a good instinct.
 * Let's consider the solution for n =3:
 * (()()), ((())) ,  ()(()),  (())(), ()()()
 * How might we build this from n = 2?
 * (()) ()()
 * We can do this by inserting a pair of parentheses inside every existing pair of parentheses,
 * as well as one at the beginning of the string. Any other places that we could insert parentheses,
 * such as at the end of the string, would reduce to the earlier cases.
 * So, we have the following:
 *
 * (()) --------->   (()())    ----- Insert pair after 1st left parenthesis
 *      --------->   ((()))    ----- Insert pair after 2nd left parenthesis
 *      --------->   ()(())    ----- Insert pair at beginning of the string
 *
 * ()() --------->   (())()    ----- Insert pair after 1st left parenthesis
 *      --------->   ()(())    ----- Insert pair after 2nd left parenthesis
 *      --------->   ()()()    ----- Insert pair at beginning of the string
 *
 * But wait- we have some duplicate pairs listed.The string ()(()) is listed twice.
 * But If we're going to apply this approach, we'll need to check for duplicate values before adding a string to our list.
 */

namespace Sol1{

	string insertInside(string str,int leftIndex){

		string left = str.substr(0,leftIndex+1);
		string right = str.substr(leftIndex+1,str.length());
		return left + "()" + right;
	}

	std::set<string> generateParens(int remaining){

		std::set<string> mySet;

		if(remaining == 0){
			mySet.insert("");
		}else{
			set<string>prev = generateParens(remaining - 1);
			for (std::set<string>::iterator it=prev.begin(); it!=prev.end(); ++it){
			  string str = *it;
			  for(int i=0;i<str.length();i++){
				  if(str[i] == '('){
					  string s = insertInside(str,i);
					  /*
					   * Add s to set if its not already in there. Note:
					   * set automatically checks for duplicates before adding, so an explicit
					   * check is not necessary
					   */
					  mySet.insert(s);
				  }
			  }
			  mySet.insert("()"+str);
			}
		}
		return mySet;
	}
}

int main(){

	{
		std::set<string>mySet  = Sol1::generateParens(1);
		for (std::set<string>::iterator it=mySet.begin(); it!=mySet.end(); ++it){
			cout<<*it<<endl;
		}
	}
	{
		std::set<string>mySet  = Sol1::generateParens(2);
		for (std::set<string>::iterator it=mySet.begin(); it!=mySet.end(); ++it){
			cout<<*it<<endl;
		}
	}
	{
		std::set<string>mySet  = Sol1::generateParens(3);
		for (std::set<string>::iterator it=mySet.begin(); it!=mySet.end(); ++it){
			cout<<*it<<endl;
		}
	}




	return 0;

}


