/*
 * TripleStep.cpp
 *
 *  Created on: Sep 11, 2017
 *      Author: chivora
 */

#include <iostream>
#include <vector>
#include <algorithm>    // std::fill

using namespace std;

/*
 * Triple Step: A child is running up a staircase with n steps and can hop either 1 step, 2 steps, or 3 steps at a time.
 * Implement a method to count how many possible ways the child can run up the stairs.
 */


/*
 * Let's think about this with the following question: What is the very last step that is done?
 * The very last hop the child makes- the one that lands her on the nth step-was either a 3-step hop, a 2-step hop, or a 1-step hop.
 * How many ways then are there to get up to the nth step? We don't know yet. but we can relate it to some subproblems.
 * If we thought about all of the paths to the nth step, we could just build them off the paths to the three previous steps.
 * We can get up to the nth step by any of the following:
 * • Going to the (n -l)st step and hopping 1 step.
 * Going to the (n - 2)nd step and hopping 2 steps.
 * Going to the (n - 3)rd step and hopping 3 steps.
 * Therefore, we just need to add the number of these paths together.
 * Be very careful here. A lot of people want to multiply them.
 * Multiplying one path with another would signify taking one path and then taking the other.
 * That's not what's happening here.
 */

/*
 * Recursive Solution
 * Brute Force Solution
 * This is a fairly straightforward algorithm to implement recursively.
 * We just need to follow logic like this: countways(n-l) + countways(n-2) + countWays(n-3)
 * The one tricky bit is defining the base case. If we have 0 steps to go (we're currently standing on the step),
 * are there zero paths to that step or one path?
 * That is, what is countWays (e)? Is it 1 or O?
 * You could define it either way.There is no "right" answer here.
 * However, it's a lot easier to define it as 1. If you defined it as 0,
 * then you would need some additional base cases (or else you'd just wind up with a series of Os getting added).
 */
int countWays(int n){

	if(n < 0){
		return 0;
	}else if(n == 0){
		return 1;
	}else{
		return countWays(n-1)+countWays(n-2)+countWays(n-3);
	}

}

/*
 * Memoization Solution
 * The previous solution for countWays is called many times for the same values, which is unnecessary.
 * We can fix this through memoization.
 * Essentially, if we've seen this value of n before, return the cached value. Each time we compute a fresh value, add it to the cache.
 * Typically we use a HashMap<Integer, Integer> for a cache.
 * In this case, the keys will be exactly 1 through n.
 * lt's more compact to use an integer array.
 */

int countWays2(int n,std::vector<int> &memo){
	if(n<0){
		return 0;
	}else if(n == 0){
		return 1;
	}else if(memo[n] > -1){
		return memo[n];
	}else{
		memo[n] = countWays2(n-1,memo) + countWays2(n-2,memo) + countWays2(n-3,memo);
		return memo[n];
	}
}

int countWays2(int n){
	std::vector<int> memo;
	memo.reserve(n+1);
	for(int i=0;i<n+1;i++){
		memo.push_back(-1);
	}
	return countWays2(n,memo);
}

int main(){
	cout<<countWays(3)<<endl;
	cout<<countWays(4)<<endl;
	cout<<countWays2(3)<<endl;
	cout<<countWays2(4)<<endl;


	return 0;
}



