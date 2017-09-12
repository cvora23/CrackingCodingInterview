/*
 * MagicIndex.cpp
 *
 *  Created on: Sep 11, 2017
 *      Author: chivora
 */

#include <iostream>
#include <vector>

using namespace std;

namespace Sol1{

	int magicSlow(vector<int>vec){

		for(int i=0;i<vec.size();i++){
			if(vec[i] == i){
				return i;
			}
		}
		return -1;
	}

}


/*
 * Given that the array is sorted, though, it's very likely that we're supposed to use this condition.
 * We may recognize that this problem sounds a lot like the classic binary search problem.
 * Leveraging the Pattern Matching approach for generating algorithms, how might we apply binary search here?
 * In binary search, we find an element k by comparing it to the middle element, x,
 * and determining if k would land on the left or the right side of x.
 * Building off this approach, is there a way that we can look at the middle element to
 * determine where a magic index might be? Let's look at a sample array:
 * Why couldn't the magic index be on the left side? Observe that when we move from i to i -1,
 * the value at this index must decrease by at least 1,
 * if not more (since the array is sorted and all the elements are distinct).
 * So, if the middle element is already too small to be a magic index, then when we move to the left,
 * subtracting k indexes and (at least) k values, all subsequent elements will also be too small.
 * We continue to apply this recursive algorithm, developing code that looks very much like binary search.
 */

namespace Sol2{

	int magicFast(vector<int>vec,int start,int end){

		if(end < start){
			return -1;
		}

		int middle = (end+start)/2;

		if(vec[middle] == middle){
			return middle;
		}else if(vec[middle] > middle){
			return magicFast(vec,start,middle-1);
		}else{
			return magicFast(vec,middle+1,end);
		}

	}

	int magicFast(vector<int>vec){

		return magicFast(vec,0,vec.size()-1);

	}

}

/*
 * Follow Up: What if the elements are not distinct?
 * If the elements are not distinct, then this algorithm fails. Consider the following array:
 * When we see that A[mid] < mid, we cannot conclude which side the magic index is on.
 * It could be on the right side, as before. Or, it could be on the left side (as it, in fact, is).
 * Could it be anywhere on the left side? Not exactly. Since A[5] = 3, we know that A[ 4] couldn't be a magic index.
 * A[4] would need to be 4 to be the magic index, but A[4] must be less than or equal to A[5].
 * In fact, when we see that A[5] = 3, we'll need to recursively search the right side as before.
 * But, to search the left side, we can skip a bunch of elements and only recursively search elements A[e] through A[3].
 * A[ 3] is the first element that could be a magic index.
 * The general pattern is that we compare midIndex and midValue for equality first.
 * Then, if they are not equal, we recursively search the left and right sides as follows:
 * Left side: search indices start through Math. min (midIndex - 1, midValue).
 * • Right side:search indices Math. max(midIndex + 1, midValue) through end.
 *
 */

namespace Sol3{

int magicFast(vector<int>vec,int start,int end){

	if(end < start){
		return -1;
	}

	int middleIndex = (end+start)/2;
	int middleValue = vec[middleIndex];

	if(middleIndex == middleValue){
		return middleIndex;
	}

	/*
	 * Search left
	 */
	int leftIndex = min(middleIndex-1,middleValue);
	int left = magicFast(vec,start,leftIndex);

	if(left >= 0){
		return left;
	}

	/*
	 * Search right
	 */
	int rightIndex = max(middleIndex+1,middleValue);
	int right = magicFast(vec,rightIndex,end);
	return right;
}

int magicFast(vector<int>vec){
	return magicFast(vec,0,vec.size()-1);
}


}

int main(){

	int array[11] = {-40,-20,-1,1,2,3,5,7,9,12,13};
	std::vector<int> vec1;
	for(int i=0;i<11;i++){
		vec1.push_back(array[i]);
	}


	cout<<Sol1::magicSlow(vec1)<<endl;
	cout<<Sol2::magicFast(vec1)<<endl;

	int array2[11] = {-10,-5,2,2,2,3,4,7,9,12,13};
	std::vector<int> vec2;
	for(int i=0;i<11;i++){
		vec2.push_back(array2[i]);
	}

	cout<<Sol3::magicFast(vec2)<<endl;

	return 0;
}
