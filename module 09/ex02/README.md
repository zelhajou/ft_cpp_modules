# Ford-Johnson (Merge-Insertion) Sort Algorithm

PmergeMe is an implementation of the Ford-Johnson merge-insert sort algorithm, a sorting technique that aims to minimize the number of comparisons.


**Exercise Requirements**

1. Creating a program named PmergeMe
2. Taking a positive integer sequence as input
3. Implementing the Ford-Johnson (merge-insert) sorting algorithm
4. Using at least two differnet STL conatiners
5. Displaying:
    - The unsorted sequence
    - The sorted sequence
    - Time taken using the first container
    - Time taken using the second container
6. Handling at least 3000 differnet integers

**The Ford-Johnson Algorithm**

The Ford-Johnson algorithm, also known as merge-insertion sort, is a comparison-based sorting algorithm designed to minimize the number of comparisons needed to sort a sequence, approaching the theoretical minimum possible.

**The Algorithm in Simple Terms**

Imagine you have a deck of cards that you want to sort. The Ford-Johnson algorithm works as follows:

1. Group the cards into pairs.
2. For each pair, put the larger card on top
3. Take all the top cards and repeat the process until you have a single card left. (Recursively useing the same process)
4. Strategically insert the botton cars into the sorted top carsds to create a sorted deck.

The "magic" happens in step 4, where we dont just insert cards randomly - we use a special sequence to minimize comparisons.

**Step-by-Step Breakdown**

[3, 1 , 4, 5, 9, 2, 6, 8]

**Step 1**: Pair Formation

Group elements into pairs:
    
- Pair 1: [3, 1]
- Pair 2: [4, 5]
- Pair 3: [9, 2]
- Pair 4: [6, 8]

If we have an odd numbers of elements, the last one be set aside as a "straggler."

**Step 2**: Sort Each Pair
The larger element is placed on top:

- Pair 1: [3, 1] -> no change needed since 3 > 1
- Pair 2: [4, 5] -> swap to [5, 4] since 5 > 4
- Pair 3: [9, 2] -> no change needed since 9 > 2
- Pair 4: [6, 8] -> Swap to [8, 6] since 8 > 6

Now our pairs are ([3, 1], [5, 4], [9, 2], [8, 6])

**Step 3**: Form and Sort Main Chain
Extract the top elements and form a new chain:

- Main Chain: [3, 5, 9, 8]

We recursively sort this main chain using the same algorithm until we have a single element left.

1. Pair up: [3, 5], [9, 8]
2. Sort: [5, 3], [9, 8]
3. Form main chain: [5, 9]
4. Sort recursively:
    - Pair up: [5, 9]
    - Sort: [9, 5]
    - Form main chain: [9]
    - Base case reached - we have a single element sorted
    - Inset the smaller element into the main chain: [5, 9] -> [5, 9]
5. Insert the last element into the main chain: [3, 5, 9 ,8] -> [3, 5, 9, 8]

**Step 4**: Created Pend Chain
The, "pend" chain consists of the smaller elements from each original pair, keeping track of which main chain element they're associated with:

- 1 (associated with 3)
- 4 (associated with 5)
- 2 (associated with 9)
- 6 (associated with 8)

- Main Chain: [3, 5, 9, 8]
- Pend Chain: [1, 4, 2, 6]



