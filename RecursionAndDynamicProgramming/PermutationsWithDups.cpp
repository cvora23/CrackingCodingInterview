/*
 * PermutationsWithDups.cpp
 *
 *  Created on: Sep 12, 2017
 *      Author: chivora
 */
#include <iostream>
#include <list>
#include <vector>
#include <map>

using namespace std;

/*
 * This is very similar to the previous problem, except that now we could potentially have duplicate characters in the word.
 * One simple way of handling this problem is to do the same work to check if a permutation has been created before and then,
 * if not, add it to the list. A simple hash table will do the trick here.
 * This solution will take o(n !) time in the worst case (and, in fact, in all cases).
 * While it's true that we can't beat this worst case time, we should be able to design an algorithm to beat this in many cases.
 * Consider a string with all duplicate characters, like aaaaaaaaaaaaaaa.
 * This will take an extremely long time (since there are over 6 billion permutations of a 13-character string),
 * even though there is only one unique permutation.
 * Ideally, we would like to only create the unique permutations, rather than creating every permutation and then ruling out the duplicates.
 * We can start with computing the count of each letter (easy enough to get this-just use a hash table).
 * For a string such as aabbbbc, this would be:
 * a->2 , b->4 , c->1
 * Let's imagine generating a permutation of this string (now represented as a hash table).
 * The first choice we make is whether to use an a, b, or c as the first character.
 * After that, we have a subproblem to solve:find all permutations of the remaining characters, and append those to the already picked "prefix:'
 * P(a->2 | b->4 | c->1) = {a + P(a->1 | b->4 | C->1)} + {b + P(a->2 | b->3 | C->1)} + {c + P(a->2 | b->4 | c->0)}
 * P(a->1 | b->4 | C->1) = {a + P(a->0 | b->4 | c->1)} + {b + P(a->1 | b->3 | c->1)} + {c + P(a->1 | b->4 | c->0)}
 * P(a->2 | b->3 | c->1) = {a + P(a->1 | b->3 | c->1)} + {b + P(a->2 | b->2 | c->1)} + {c + P(a->2 | b->3 | c->0)}
 * P(a->2 | b->4 | c->0) = {a + P(a->1 | b->4 | c->0)} + {b + P(a->2 | b->3 | c->0)}
 * Eventually, we'll get down to no more characters remaining.
 */

namespace Sol1{

	map<char,int> buildFreqTable(string s){

		map<char,int> map;

		for(int i=0;i<s.length();i++){
			if(map.find(s[i]) == map.end()){
				map[s[i]] = 0;
			}
			map[s[i]]++;
		}
		return map;
	}

	void printPerms(map<char,int>map,string prefix,int remaining,vector<string> &result){

		/*
		 * Base case. Permutation has been completed
		 */
		if(remaining == 0){
			result.push_back(prefix);
			return;
		}

		/*
		 * Try remaining letters for next char, and generate permutations
		 */
		  for (std::map<char,int>::iterator it=map.begin(); it!=map.end(); ++it){

			  int count = it->second;

			  if(count > 0){
				  map[it->first] = count-1;
				  printPerms(map,prefix+it->first,remaining-1,result);
				  map[it->first] = count;
			  }
		  }
	}

	vector<string> printPerms(string s){

		vector<string> result;
		map<char,int> map = buildFreqTable(s);

		printPerms(map,"",s.length(),result);
		return result;
	}

}

int main()
{
	vector<string>permutations = Sol1::printPerms("aaa");
	for(int i=0;i<permutations.size();i++){
		cout<<permutations[i]<<endl;
	}
	return 0;

}



