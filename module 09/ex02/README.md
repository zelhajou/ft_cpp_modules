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
    - Form main   chain: [9]
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


**Step 5**: Strategic Insertion

This is where the Ford-Johnson algorithm truly shines. Instead of inserting pend elements in a simple order, we use sequence based on [Jacobsthal numbers](https://en.wikipedia.org/wiki/Jacobsthal_number).

The Jacobsthal sequence is a sequence of numbers that can be used to minimize the number of comparisons needed to sort a sequence. The sequence is defined as follows:

- J(0) = 0
- J(1) = 1
- J(n) = J(n-1) + 2 * J(n-2)

```cpp
The first few Jacobsthal numbers are: 0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525, 699051, 1398101, 2796203, 5592405, 11184811, 22369621, 44739243, 89478485,

// Each number (beyond the first two) is formed by taking the previous number and adding twice the number before that.
```
- J(0) = 0
- J(1) = 1
- J(2) = 1
- J(3) = 3
- J(4) = 5
- J(5) = 11
- J(6) = 21
- J(7) = 43

**How the sequence is used for insertion**

Until now, we have a sorted main chain and a pend chain.

- A main chain for sorted elements: [a₁, a₂, a₃, a₄, ...] => [3, 5, 9, 8] 
- A set of remaining elements to insert: [b₁, b₂, b₃, b₄, ...] => [1, 4, 2, 6]

The key insight is that we need to determine the optimal order to insert these elements into the main chain. The Jacobsthal sequence provides this order.

**Generating the Jacobsthal Sequence**

For n elements to insert, we:

1. Look at the relevant Jacobsthal numbers (up to the first J(k) ≥ n)
2. Use these to create the insertion sequence
3. Between cosecutive Jacobsthal numbers, we insert in descending order

**Example 1: Inserting 5 Elements**

With 5 elements to insert, we need Jacobsthal numbers up to 5:
J(0)=0, J(1)=1, J(2)=1, J(3)=3, J(4)=5
Now let's construct the insertion sequence:

Take the Jacobsthal numbers that aren't 0: [1, 1, 3, 5]
Remove duplicates: [1, 3, 5]
Now fill in the gaps in descending order:

Between 1 and 3: [2]
Between 3 and 5: [4]

Final insertion sequence: [1, 3, 2, 5, 4]
This means we insert element b₁ first, then b₃, then b₂, then b₅, and finally b₄.

**Example 2: Inserting 7 Elements**

With 7 elements, we need Jacobsthal numbers up to at least 7:
J(0)=0, J(1)=1, J(2)=1, J(3)=3, J(4)=5, J(5)=11
Taking the relevant numbers (up to 7): [1, 3, 5]
Filling in the gaps in descending order:

Between 1 and 3: [2]
Between 3 and 5: [4]
After 5 (up to 7): [7, 6]

Final insertion sequence: [1, 3, 2, 5, 4, 7, 6]