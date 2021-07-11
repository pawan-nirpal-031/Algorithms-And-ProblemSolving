    
## Two Pointers Method
    The Two Pointers Method is an important technique that is often used in competetive programming.
    What is this method? The easiest way to explain it is with the example of the task "Merging two sorted arrays".

    What is this task? We are given two arrays, sorted in ascending order, a and b. We want to combine the elements of these arrays into one big array c, also sorted in ascending order.


    The easiest way to do this is with the following algorithm:

    collect all the elements into one big array;
    sort it with any sorting built into your language.
    Such an algorithm will take time O(n⋅log(n)).

    In this step, we will learn how to do it simply, without sorting, and in time faster than O(n⋅log(n)) (in linear time).

    Let's see an example. We are given two arrays:

    a=[1,3,5,8,10]
    b=[2,6,7,9,13]
    How do we merge them into one sorted array? To answer this question, let's understand which element will be in the first position in this array. Of course, this is the smallest element among all in a and b. In array a, the minimum element is the first (since the array is sorted). The situation is similar in array b.

    Let's look at these two elements (the first in a and b), select the minimum one and move it to the first position in array c .

    a=[/1,3,5,8,10]
    b=[2,6,7,9,13]
    c=[1]
    Now let's look again at the first non-deleted element of array a and the first non-deleted element of array b. They are the smallest ones remaining in their arrays. Let's choose the smaller of these two elements and transfer it to c.

    a=[/1,3,5,8,10]
    b=[/2,6,7,9,13]
    c=[1,2]
    We will continue this algorithm until all the elements in a and b are removed.

    How to implement this? You need to create two pointers (this where the name of the method is from).

    The first pointer will point to the first non-deleted element in a, and the second pointer to the first non-deleted element in b.

    a=[/1,3i↓,5,8,10]
    b=[/2,6j↑,7,9,13]
    c=[1,2]
    Each time we look, which of the elements under the pointers is smaller. If it is from the array a, then you need to transfer it. Otherwise, you need to transfer an element from array b. The index of the transfered element in array c will always be i+j. After we have moved the element, the corresponding pointer needs to be shifted to the right.

    while i < a.size() || j < b.size():
        if a[i] < b[j]:
        c[i + j] = a[i]
        i++
        else:
        c[i + j] = b[j]
        j++
    In the implementation of the algorithm, you need to be careful, at some point the elements of one of the arrays will run out completely, but in the other array the elements will still remain. For example, at the end of the algorithm with our example, we come to the following situation:

    a=[/1,/3,/5,/8,/10]i↓
    b=[/2,/6,/7,/9,13j↑]
    c=[1,2,3,5,6,7,8,9,10]
    If you do not implement the algorithm carefully, then at the next check which of the pointers is on the smallest element, you will go beyond the boundaries of the array.

    There are two ways to solve this problem.

    The first is to add +∞ to the end of each of the arrays (in your programming language, this is the maximum number that fits into the data type).

    Second solutions is to write the condition more accurately. When do you need to transfer an element from the first array? In case the second array has ended completely or if the first array has not ended yet and the element in it is less than the element in array b . The second case is dealt with in a similar way.

    while i < a.size() || j < b.size():
        if j == b.size() || i < a.size() && a[i] < b[j]:
        c[i + j] = a[i]
        i++
        else:
        c[i + j] = b[j]
        j++
    Why does this work in linear time? Each time we move one of the two pointers forward. The first pointer will be shifted no more times than the size of array a, and the second no more than the size of array b. In total, the algorithm will make O(a.size()+b.size()) operations.
    Number of smaller
    Let's apply the same technique to solve a different problem.
    We have two arrays a and b. We want to calculate for each element bj how many such i exist that ai<bj.

    This is a fairly common task, often encountered on a variety of occasions.

    How to solve it? First, let's sort both arrays (if initially they were given unsorted). Now you can use binary search to answer the problem (we covered it in another chapter). For each element of b, you need to find the prefix of array a that is less than this element.

    But you can do without binary search by using the two pointer method. Suppose we are doing the same merge sort as in the previous task. We will get a large sorted array c containing all the elements from a and b.

    How to solve the problem using the resulting array c? Let's see to which position of c element bj moved. Where are the elements of array a that are less than bj? They are in c to the left of bj. Therefore, you need to find out how many elements came from array a on the prefix of array c before the element bj.


    For implementation, you can use the same algorithm as in the previous task. Array c itself is not useful to us. Let's take a look at the moment when we move an element from array b. How many elements from a were moved before it? These are all elements with indices from 0 to i−1 (i is a pointer to the first non-deleted element in a). That is, there are exactly i such elements.

    We no longer need to move elements into array c. We simply move the pointers forward and respond to requests during the "former" moving of elements from b.

    while ...:
        if ...:
        i++
        else:
        res[j] = i
        j++
    Also, in this task, you can write simpler and more intuitive code. Instead of a single while loop with conditions inside, you can loop over the elements of array b (loop over the position of the j pointer). And with the second for loop move the first pointer i forward while ai<bj.

    i = 0
    for j = 0..b.size()-1:
        while i < a.size() && a[i] < b[j]:
        i++
        res[j] = i




### Segment with good sum Now we use the same technique to solve a different problem. You are given an array a consisting of non-negative integers. It is necessary to find in this array a segment of numbers [l;r], the sum of elements on which does not exceed s and the length of the segment is maximum.Let's solve this problem with the two-pointer method. We will maintain some segment of the array (its left and right boundaries will be the same two pointers), as well as the sum on this segment. We will slowly move both boundaries of this segment to the right. If we move the right border one element forward, and the sum on the new segment is no more than s, then we can leave the left border in place. It makes no sense to move it forward, since the current segment is already coming up. If we added a right element and the sum has become more than s, then we need to move the left border forward. You need to move it forward until the sum on the segment again becomes less than or equal to s. This is done using any of the implementations shown in the previous step. But in this particular task, it is more convenient to move the right border with the for cycle, and tighten the left border with the while cycle. The complexity of the algorithm is also linear. 
    x = 0, L = 0  for R = 0..n-1
     x += a[R]
    while x > s:
        x -= a[L]
        L++
    res = max(res, R - L + 1) If we want to find a segment with a sum greater than or equal to s (in this case, the length of the segment, on the contrary, needs to be minimized), then a similar algorithm can be used. We will again move the right border with the for cycle, and move the left one forward until the sum remains greater than or equal to s. However, in this version, a case appears in which for a fixed right boundary of the segments with the required sum does not exist at all. Therefore, when updating the answer, you need to add a check. x = 0, L = 0 
    
    for R = 0..n-1
    x += a[R]
    while x - a[L] >= s:
        x -= a[L]
        L++
    if x >= s:
       res = min(res, R - L + 1) These are two options for a fairly general task. In such problems, you need to look for the longest (shortest) segment with some property. Both options are solved using the two pointer method. One more modification is to find the number of segments, the sum of elements on which does not exceed s. You need to make minimal changes to the code of the first task. Since the for loop iterates over the right border, let's count how many segments fit for each right border. In the previous problem, we moved the left border until we found the first segment with the sum not exceeding s. This segment has the maximum length among all segments of interest to us with such a right boundary. This means that if we marked the left border as l, and the right border as r, then all segments starting to the left of l do not suit us, and all segments whose left border is in the interval [l,r] suit us. If we have fixed r and found the minimum l such that the sum on the segment [l;r] does not exceed s, then there are exactly r−l+1 possible segments with such a right boundary.
    x = 0, L = 0
    for R = 0..n-1
     x += a[R]
     while x > s:
        x -= a[L]
        L++
     res += R - L + 1 The same algorithm works for the modification of the second problem. Other problemsSuppose you received a problem at the contest in which you need to do something similar: find the longest (shortest) good segment or count the number of good segments. How do you know if you can apply the two-pointer method to it? First, one of the following two properties must be met: if the segment [L,R] is good, then any segment nested in it is also good (in this case, you can apply the code from the first problem);
    if the segment [L,R] is good, then any segment that contains it is also good (in this case, you can apply the code from the second problem).
    Secondly, you should be able to recalculate your function (check if current segment is good or bad), while moving the left or right border by one to the right.

    In such tasks, the code almost always looks like this:

    L = 0
    for R = 0..n-1
        add(a[R])
        while not good():
            remove(a[L])
            L++
    To solve such problems, you need to implement three functions: add, remove, and good.
    Segment with a small set
    Let's solve a classical problem.
    Given an array a, you need to find a segment [L,R] of maximum length, on which there are no more than k different numbers. For simplicity, all numbers in the array will be from 0 to m−1.

    Let's check that this problem can be solved with the two pointers method. If there are no more than k distinct numbers on the segment [L,R], then on any nested segment there will also be no more than k distinct numbers. The second question is how to recalculate the functions from the code above (how to check that the segment remains good after moving the borders)?

    It is possible to maintain a structure that counts the number of distinct numbers in the current segment. If the numbers are large, then you can use map from C++ its analogues in other languages. In this version, for each number, you can store how many times it occurs on the segment.

    But if the numbers are small, then this can be done using a regular array. Let's create an array of counters, which for each number stores the number of its occurrences on the segment. And we will also get a counter that stores the number of different elements on a segment.

    When adding a new element, you just need to increase the corresponding counter by one. If the counter has become equal to one, then a new element has appeared.

    When deleting an element, you just need to decrease the corresponding counter by one. If the counter has become zero, then this number is no longer present on the segment.

    cnt[x] - how many positions exist L <= i <= R, such that a[i] = x

    num - how many distinct numbers on the segment L..R exists

    good():
        return num <= k

    add():
        cnt[x]++
        if cnt[x] == 1:
            num++

    remove():
        cnt[x]--
        if cnt[x] == 0:
            num--
    Segment with small spread
    One more example:
    Given an array a, a segment [L;R] is considered good if
    max(a[L..R])−min(a[L..R])≤k
    If [L;R] is good, then nested segment [Math Processing Error] is also good. Because:

    [Math Processing Error]
    [Math Processing Error]
    This means: [Math Processing Error] ≤ max(a[L..R])−min(a[L..R]) ≤ k.

    To recalculate functions, we need to be able to quickly recalculate the maximum and minimum on the current segment. You can, for example, use set, priority queue, or any other similar data structure that can find the minimum and maximum. But in this case, the running time of the algorithm will be O(n⋅log(n)).

    But this problem can be solved in linear time. If we only move the right border forward, then we could easily recalculate the minimum (as the smaller number from the added and past minimum). However, when we move the left border, the minimum is more difficult to recalculate.

    To solve the problem, you can use a queue on two stacks. We always add elements only when the right border moves (adding an element to the queue) and delete from the other end of the segment when the left border moves (removing from the queue).

    That is, any segment [L;R] can be thought of as a queue. A queue can be thought of as two stacks.


    In the picture, the current segment is split into two stacks (green s1, red s2). When we want to add an element, we add it to the red stack, when we want to remove it, we remove it from the green stack.

    But what happens when the left stack ends, that is, all the elements end up on the right stack? You can pop all the elements from the second stack and put them in the first.


    Now we need to find the minimum and maximum not in the queue, but in the stack. To do this, let's create a second stack in which for each element the minimum is stored from it to the beginning of the stack and another stack for the maximums.

    s=[3,5,2,6]
    minS=[3,3,2,2]
    maxS=[3,5,5,6]
    The current maximum and minimum always lie on top of the respective stacks. If we want to push an item to the stack, then we simply push it in s, push in minS the minimum from it and the previous one, and push in maxS the maximum from it and the previous one. When we pop an item from the stack, we simply pop it from all three stacks.
