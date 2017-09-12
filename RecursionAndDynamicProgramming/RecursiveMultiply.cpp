/*
 * RecursiveMultiply.cpp
 *
 *  Created on: Sep 12, 2017
 *      Author: chivora
 */

#include <iostream>
#include <algorithm>    // std::fill
#include <map>

using namespace std;

/*
 * Recursive Multiply: Write a recursive function to multiply two positive integers without using the
 * * operator (or / operator). You can use addition, subtraction, and bit shifting,
 * but you should minimize the number of those operations.
 */

/*
 * Let's pause for a moment and think about what it means to do multiplication.
 * We can think about mUltiplying 8x7 as doing 8+8+8+8+8+8+8 (or adding? eight times).
 * We can also think about it as the number of squares in an 8x? grid.
 */


/*
 * How would we count the number of squares in this grid? We could just count each cell. That's pretty slow, though.
 * Alternatively, we could count half the squares and then double it (by adding this count to itself).To count half the squares,
 * we repeat the same process.Of course, this "doubling" only works if the number is in fact even.
 * When it's not even, we need to do the counting/summing from scratch.
 */

namespace Sol1{

	int minProductHelper(int smaller,int bigger){

		if(smaller == 0){
			return 0;
		}else if(smaller == 1){
			return bigger;
		}

		/*
		 * compute half. If uneven, compute other half. If even, double it.
		 */
		int s = smaller >> 1; // Divide by 2
		int side1 = minProductHelper(s,bigger);
		int side2 = side1;
		if(smaller % 2 == 1){
			side2 = minProductHelper(smaller -s,bigger);
		}

		return side1 + side2;
	}

	int minProduct(int a,int b){
		int bigger = a < b ? b : a;
		int smaller = a < b ? a : b;
		return minProductHelper(smaller,bigger);
	}

}

/*
 * If we observe how the recursion operates, we'll notice that we have duplicated work.
 * Consider this example:
 * minProduct(17,23) minProduct(8,23)
 * minProduct(4 , 23) * 2 + minProduct(9 , 23)
 * minProduct(4 , 23) + minProduct(5 , 23)
 * The second call to minProduet(4) 23) is unaware of the prior call, and so it repeats the same work. We should cache these results.
 */
namespace Sol2{

	int minProductHelper(int smaller,int bigger,std::map<int,int>&memo){

		if(smaller == 0){
			return 0;
		}else if(smaller == 1){
			return bigger;
		}else if(memo[smaller] > 0){
			return memo[smaller];
		}

		/*
		 * compute half. If uneven, compute other half. If even, double it.
		 */
		int s = smaller >> 1; // Divide by 2
		int side1 = minProductHelper(s,bigger,memo);
		int side2 = side1;
		if(smaller % 2 == 1){
			side2 = minProductHelper(smaller -s,bigger,memo);
		}
		/*
		 * Sum and Cache
		 */
		memo[smaller] = (side1 + side2);
		return memo[smaller];
	}

	int minProduct(int a,int b){
		int bigger = a < b ? b : a;
		int smaller = a < b ? a : b;

		std::map<int,int> memo;

		return minProductHelper(smaller,bigger,memo);
	}
}

/*
 * One thing we might notice when we look at this code is that a call to minProduct on an even number
 * is much faster than one on an odd number. For example, if we call minProduct (30, 35),
 * then we'll just dominProduct(15, 35)anddoubletheresult.However,if we do minProduct(31, 35),
 * then we'll need to call minProduct (15, 35) and minProduct (16, 35).
 * This is unnecessary. Instead, we can do:
 * minProduct(31, 35) = 2 * minProduct(15, 35) + 35
 * After all, since 31 = 2*15+1, then 31x35 = 2*15*35+35.
 * The logic in this final solution is that, on even numbers, we just divide smaller by 2 and
 * double the result of the recursive call. On odd numbers, we do the same, but then we also add bigger to this result.
 * In doing so, we have an unexpected "win:' Our minProduct function just recurses straight downwards,
 * with increasingly small numbers each time. It will never repeat the same call, so there's no need to cache any information.
 */

namespace Sol3{

	int minProductHelper(int smaller,int bigger){

		if(smaller == 0){
			return 0;
		}else if(smaller == 1){
			return bigger;
		}

		/*
		 * compute half. If uneven, compute other half. If even, double it.
		 */
		int s = smaller >> 1; // Divide by 2
		int halfProd = minProductHelper(s,bigger);
		if(smaller % 2 == 0){
			return halfProd + halfProd;
		}else{
			return halfProd + halfProd + bigger;
		}
	}

	int minProduct(int a,int b){
		int bigger = a < b ? b : a;
		int smaller = a < b ? a : b;
		return minProductHelper(smaller,bigger);
	}

}

int main(){

	cout<<Sol1::minProduct(8,2)<<endl;
	cout<<Sol2::minProduct(8,2)<<endl;
	cout<<Sol3::minProduct(8,2)<<endl;

	cout<<Sol1::minProduct(8,3)<<endl;
	cout<<Sol2::minProduct(8,3)<<endl;
	cout<<Sol3::minProduct(8,3)<<endl;

	cout<<Sol1::minProduct(3,3)<<endl;
	cout<<Sol2::minProduct(3,3)<<endl;
	cout<<Sol3::minProduct(3,3)<<endl;

	return 0;

}
