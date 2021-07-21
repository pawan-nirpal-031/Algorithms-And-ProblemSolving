# BinarySearch
    Today we will learn one of the most popular techniques in competitive programming — binary search.
    Searching an item in an array

    Suppose we have an array a=[a1,a2,…,an], sorted in non-decreasing order. That is, the inequality ai≤ai+1 is satisfied for the neighboring elements of the array. We need to quickly search for the position of the element x in the array, that is, we need to find such i, then ai=x.

    How would we search for the position of x? If you go from left to right through the array a, then this will work in O(n) time, which is inefficient for a large array.

    How to make it faster? Let's take advantage of the fact that the a array is sorted. If we found out that for some j it is true that aj>x, then the inequality will hold for all k>j. Until the array consists of one element, we will proceed as follows:

    let's look at the element that is in the middle of the array,
    if it is greater than x, then we cut off all elements to the right of it, otherwise, we cut off all elements to the left of it.
    At the end of this procedure, we will have exactly one element in the array, which will either be equal to x or not equal to x.

    For example, for the array a=[3,5,8,13,18,19,21,27,32] and x=13, the algorithm will be executed as follows:


    We consider the segment [l,r]=[1,9], the middle element is at the position l+r2=5.



    We consider the segment [l,r]=[1,4], the middle element is at the position l+r2=3.



    We consider the segment [l,r]=[3,4], the middle element is at the position l+r2=4.

    Why do we find the position of the element x using this method (if it occurs in the array)? This follows from the sorted array. At each step, we remove from consideration the part of the array containing elements greater or less than x.

    Why is it faster than a linear search? At each step of the algorithm, we reduce the length of the segment under consideration by 2 times, therefore, the steps of the algorithm will be done no more than log2n. Thus, we got an algorithm that runs in O(logn) time.

    Find closest in array

    Let's learn how to solve the following problem — in a sorted array, you need to quickly find the element closest to the number x (x changes from query to query).

    If we needed to find an element exactly equal to x, then we could use a hash table. But if there is no x element in the array, then the hash table will simply indicate this. In this case, we need to solve the following two tasks:

    Find the maximum element not greater than x (closest to x on the left)
    Find the minimum element not less than x (closest to x on the right)
    Choosing from these two options the one that is closer to the number x, we will solve the problem (since all the elements to the left and to the right will only be further from x).

    Consider a binary search algorithm for solving the first problem (maximum element not greater than x).

    We are given an array a=[a0,a1,…,an−1]. Let's create two pointers l and r. They will be responsible for the boundaries of the segment under consideration. We will maintain the invariant that al≤x and ar>x. We put l and r so that the invariant holds. To do this, add −∞ to the beginning of the array (the index of this infinity will be −1), and to the end of the array +∞ (the index of this infinity will be n). Then set l to −1 and r to n. Obviously, the invariant is satisfied.

    We will execute the following algorithm until l+1<r (until the pointers converge):

    Let m — be the index of the midpoint of the segment [l,r];
    If am≤x then put l=m. All elements to the left of m are less than am;
    If am>x then put r=m. All elements to the right of m are greater than am.
    Let's take an example a=[3,5,10,11,13,18,25,27,31], x=20.

    Since x=20 is greater than am=13, then l=m
    Since x=20 is less than am=25, then r=m
    Since x=20 is greater than am=18, then l=m
    Pointers converged
    Since the invariant is satisfied, then al≤x, and ar>x, in this case, l is the maximum of such indices, and r is the minimum.

    It remains only to choose from the elements al and ar the one that is closer to x. In this example, it is 18.

    What happens in special cases?

    If all items are greater than x, then l=−1.
    If all items are less than x, then r=n.
    But since we set these elements equal to ±∞, the correctness the algorithm will not be violated.