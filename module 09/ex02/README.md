# Ford-Johnson (Merge-Insertion) Sort Algorithm

PmergeMe is an implementation of the Ford-Johnson merge-insert sort algorithm, a sorting technique that aims to minimize the number of comparisons.


## **Exercise Requirements**

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

## **The Ford-Johnson Algorithm**

The Ford-Johnson algorithm, also known as merge-insertion sort, is a comparison-based sorting algorithm designed to minimize the number of comparisons needed to sort a sequence, approaching the theoretical minimum possible.

**Key Idea**: Instead of comparing elements sequentially (like in Bubble Sort or Selection Sort), Merge-Insertion Sort first groups elements into pairs, sorts each pair, then merges them using a smart insertion technique.

1. **Pairing Elements**:
    - The elements are divided into pairs (if there's an odd number, one element is left alone).
    - Each pair is compared, and the larger element is selected.
2. **Sort the Larger Elements**:
    - The larger elements from each pair are sorted recursively, forming a sorted list.
3. **Insert the Remaining Elements**:
    - The smaller elements from the pairs (and the leftover element, if any) are inserted into the sorted list one by one.
    - To minimize comparisons, the insertions follow a special order and use the Jacobsthal sequence.


**Time Complexity**:

- Best-case: O(n log n)
- Worst-case: O(n log n) (fewer comparisons than Merge Sort)
- Space Complexity: O(n) (additional space for storing pairs)



## **The Algorithm in Simple Terms**

Imagine you have 8 people of different heights, and you want to sort them from shortest to tallest:

1. Pair them up and compare their heights.
2. Winners go into a "Champion's List" (Main Chain), losers go into a "Second Chance List" (Pend Chain).
3. Recursively sort the Champion's List until you have a single element.
4. Insert the elements from the Pend Chain into the Champion's List in a strategic order to minimize comparisons.
5. You now have a sorted list!

The "magic" happens in step 4, where we dont just insert cards randomly - we use a special sequence to minimize comparisons. (Jacobsthal numbers)


## **Understanding Jacobsthal Numbers**

Jacobsthal numbers follow the recurrence relation:

$$
J_n = J_{n-1} + 2J_{n-2}
$$

With the first few values:

$$
J_0 = 0, \quad J_1 = 1, \quad J_2 = 1, \quad J_3 = 3, \quad J_4 = 5, \quad J_5 = 11, \quad J_6 = 21, \dots
$$

These numbers help determine insertion positions in an optimized way.




## Example: Sorting the list `[9, 3, 7, 1, 8, 4, 6, 2, 5]`

### Step 1: Pairing the Elements

First, we identify if we have a straggler (an odd element out). Since our list has 9 elements (odd), we set aside the last element as a straggler:
- Straggler: `5`
- Remaining list: `[9, 3, 7, 1, 8, 4, 6, 2]`

Now we group the elements into pairs:
- `(9, 3)`
- `(7, 1)`
- `(8, 4)`
- `(6, 2)`

### Step 2: Compare Each Pair

For each pair, we identify the larger and smaller element:
- `(9, 3)` → `9` is larger, `3` is smaller
- `(7, 1)` → `7` is larger, `1` is smaller
- `(8, 4)` → `8` is larger, `4` is smaller
- `(6, 2)` → `6` is larger, `2` is smaller

This gives us:
- Larger elements (Main Chain candidates): `[9, 7, 8, 6]`
- Smaller elements (Pend Chain): `[3, 1, 4, 2]`

### Step 3: Sort the Main Chain Recursively

We now need to sort the Main Chain `[9, 7, 8, 6]` using the same algorithm. Here's exactly how the recursion works according to the merge-insertion sort implementation:

**Recursion Level 1:**
1. We take the Main Chain `[9, 7, 8, 6]` and apply the entire algorithm to it recursively

**Recursion Level 2:**
1. With input `[9, 7, 8, 6]`, we check for a straggler (no straggler as 4 is even)
2. Form pairs: `(9, 7)` and `(8, 6)`
3. Ensure larger element is first in each pair (already correct)
4. Extract larger elements to form a new Main Chain: `[9, 8]`
5. Apply the algorithm recursively to this new Main Chain

**Recursion Level 3:**
1. With input `[9, 8]`, we check for a straggler (no straggler as 2 is even)
2. Form the single pair: `(9, 8)`
3. Ensure larger element is first (already correct)
4. Extract the larger element to form a new Main Chain: `[9]`
5. Since the Main Chain now has only one element, we've reached our base case and stop recursion

**Unwinding the Recursion:**

**At Recursion Level 3:**
- Our sorted Main Chain is simply `[9]`
- We need to insert the smaller element from the pair `(9, 8)`
- We start our result with the Main Chain element: `[9]`
- Insert the smaller element `8` in the correct position: `[8, 9]`
- This becomes our sorted result for this level: `[8, 9]`

**At Recursion Level 2:**
- We now have the sorted Main Chain `[8, 9]` from the deeper recursion
- We need to merge in the smaller elements from our original pairs
- Initialize our result with the first Main Chain element: `[8]`
- Insert the smaller element from the first pair `(9, 7)` using binary search: `[7, 8]`
- Since the second element of the Main Chain (`9`) isn't in our result yet, insert it: `[7, 8, 9]`
- Insert the smaller element from the second pair `(8, 6)` using binary search: `[6, 7, 8, 9]`
- Our sorted result for this level is: `[6, 7, 8, 9]`

**At Recursion Level 1:**
- We now have the fully sorted Main Chain: `[6, 7, 8, 9]`

### Step 4: Insert Pend Chain Elements

Now we need to insert the original Pend Chain elements `[3, 1, 4, 2]` into our sorted Main Chain `[6, 7, 8, 9]`.

Remember the original pairs:
- `(9, 3)` - Main Chain: `9`, Pend Chain: `3`
- `(7, 1)` - Main Chain: `7`, Pend Chain: `1`
- `(8, 4)` - Main Chain: `8`, Pend Chain: `4`
- `(6, 2)` - Main Chain: `6`, Pend Chain: `2`

We start by inserting the Pend Chain element from the first pair:
- Insert `3` (from pair with `9`): `[3, 6, 7, 8, 9]`

### Step 4: Insert Pend Chain Elements

Now we need to insert the original Pend Chain elements `[3, 1, 4, 2]` into our sorted Main Chain `[6, 7, 8, 9]`.

Remember the original pairs:
- `(9, 3)` - Main Chain element: `9`, Pend Chain element: `3`
- `(7, 1)` - Main Chain element: `7`, Pend Chain element: `1`
- `(8, 4)` - Main Chain element: `8`, Pend Chain element: `4`
- `(6, 2)` - Main Chain element: `6`, Pend Chain element: `2`

First, we initialize our result with the first element from the sorted Main Chain:
- Result: `[6]`

Then we insert the smaller element from the first pair:
- Since `(9, 3)` corresponds to Main Chain element `9`, we insert `3` using binary search: `[3, 6]`

For the remaining insertions, we determine the order using the Jacobsthal sequence:

1. Generate the Jacobsthal sequence: `0, 1, 1, 3, 5, 11, ...`
2. Create an insertion order based on these numbers:
   - Mark index 0 as already processed
   - For the first Jacobsthal number after 0 (which is 1), add index 1 to our insertion order: `[1]`
   - For the next Jacobsthal number (which is also 1), it's already processed
   - For the next Jacobsthal number (which is 3), add index 3 to our insertion order: `[1, 3]`
   - Then check indices between 3 and the previous processed Jacobsthal number (1) in reverse order:
     - Add index 2 to our insertion order: `[1, 3, 2]`

Following this insertion order:
1. Process pair at index 1 `(7, 1)`:
   - Insert Main Chain element `7` (if not already in result): `[3, 6, 7]`
   - Insert Pend Chain element `1` using binary search: `[1, 3, 6, 7]`

2. Process pair at index 3 `(6, 2)`:
   - Main Chain element `6` is already in result
   - Insert Pend Chain element `2` using binary search: `[1, 2, 3, 6, 7]`

3. Process pair at index 2 `(8, 4)`:
   - Insert Main Chain element `8` (if not already in result): `[1, 2, 3, 6, 7, 8]`
   - Insert Pend Chain element `4` using binary search: `[1, 2, 3, 4, 6, 7, 8]`

4. Insert the Main Chain element `9` (if not already in result): `[1, 2, 3, 4, 6, 7, 8, 9]`

### Step 5: Insert the Straggler

Finally, we insert our straggler `5` using binary search:
- Find the correct position for `5` in our sorted array `[1, 2, 3, 4, 6, 7, 8, 9]`
- Insert `5` at the correct position: `[1, 2, 3, 4, 5, 6, 7, 8, 9]`

The fully sorted array is: `[1, 2, 3, 4, 5, 6, 7, 8, 9]`



## The Main Sorting Function - sortVector

The `sortVector()` function implements the Ford-Johnson algorithm with the following steps:

### Step 1: Handle Base Cases and Straggler

First, the function checks if sorting is needed at all:
```cpp
if (_vec.size() <= 1)
    return;
```

If there's only 0 or 1 element, the vector is already sorted, so we return immediately.

Next, we handle an odd-sized array by removing the last element temporarily:
```cpp
bool hasStraggler = false;
int straggler = 0;

if (_vec.size() % 2 != 0) {
    hasStraggler = true;
    straggler = _vec.back();
    _vec.pop_back();
}
```

This "straggler" element will be reinserted later. Removing it makes the rest of the algorithm easier since we'll be working with pairs.

### Step 2: Form and Sort Pairs

We create pairs from consecutive elements:
```cpp
std::vector<std::pair<int, int>> pairs;
for (size_t i = 0; i < _vec.size(); i += 2) {
    int first = _vec[i];
    int second = _vec[i + 1];
    pairs.push_back(std::make_pair(first, second));
}
```

Then we ensure the larger element is first in each pair:
```cpp
for (size_t i = 0; i < pairs.size(); i++) {
    if (pairs[i].first < pairs[i].second)
        std::swap(pairs[i].first, pairs[i].second);
}
```

For example, if our array is `[3, 1, 4, 2]`, we form pairs: `(3,1)` and `(4,2)`. After ensuring the larger element is first, we have: `(3,1)` and `(4,2)`, which in this case didn't need to change.

### Step 3: Extract and Sort the Main Chain

The "main chain" consists of all the larger elements from each pair:
```cpp
std::vector<int> mainChain;
for (size_t i = 0; i < pairs.size(); i++) {
    mainChain.push_back(pairs[i].first);
}
```

Using our example, the main chain would be `[3, 4]`.

Now we recursively sort this main chain:
```cpp
if (mainChain.size() > 1) {
    _vec = mainChain;
    sortVector();
    mainChain = _vec;
    _vec.clear();
}
```

This is where the recursive magic happens. We:
1. Replace the current vector with the main chain
2. Call `sortVector()` recursively to sort it
3. Get the sorted main chain back
4. Clear the current vector so we can build our result

### Step 4: Begin Rebuilding the Sorted Array

We initialize our result with the main chain's first element and insert the smaller element from the first pair:
```cpp
std::vector<int> result;
if (!mainChain.empty())
    result.push_back(mainChain[0]);

if (!pairs.empty())
    result.insert(result.begin(), pairs[0].second);
```

If our main chain is `[3, 4]` (already sorted by recursion), we:
1. Start result with `[3]`
2. Insert the smaller element from the first pair (1) at the beginning: `[1, 3]`

### Step 5: Generate Jacobsthal Sequence and Insertion Order

For more than one pair, we use the Jacobsthal sequence to determine an optimal insertion order:

```cpp
if (pairs.size() > 1) {
    int jacobsthalSize = 3;
    while (getJacobsthalSequence(jacobsthalSize).back() < (int)pairs.size())
        jacobsthalSize++;

    std::vector<int> jacobSeq = getJacobsthalSequence(jacobsthalSize);
    std::vector<int> insertionOrder = generateInsertionOrder(jacobSeq, pairs.size());
```

Let's break this down in extreme detail:

#### 5.1 Finding the Right Jacobsthal Sequence Size

```cpp
int jacobsthalSize = 3;
while (getJacobsthalSequence(jacobsthalSize).back() < (int)pairs.size())
    jacobsthalSize++;
```

We need enough Jacobsthal numbers to cover all our pairs. For example, with 10 pairs:

1. Start with `jacobsthalSize = 3`
2. Generate sequence: `[0, 1, 1, 3]` (up to J(3))
3. The last number is 3, which is < 10 (our pairs size)
4. Increment to `jacobsthalSize = 4`
5. Generate sequence: `[0, 1, 1, 3, 5]` (up to J(4))
6. The last number is 5, which is < 10
7. Increment to `jacobsthalSize = 5`
8. Generate sequence: `[0, 1, 1, 3, 5, 11]` (up to J(5))
9. The last number is 11, which is > 10
10. Stop at `jacobsthalSize = 5`

#### 5.2 Generating the Jacobsthal Sequence

The `getJacobsthalSequence(n)` function generates the Jacobsthal sequence up to the nth term:

```cpp
std::vector<int> PmergeMe::getJacobsthalSequence(int n)
{
    std::vector<int> jacobsthal;

    jacobsthal.push_back(0);
    if (n > 0)
        jacobsthal.push_back(1);

    for (int i = 2; i <= n; i++)
    {
        int next = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];
        jacobsthal.push_back(next);
    }

    return jacobsthal;
}
```

This precisely follows the mathematical recurrence relation:
- J(0) = 0
- J(1) = 1
- J(n) = J(n-1) + 2*J(n-2) for n ≥ 2

The generated sequence begins: 0, 1, 1, 3, 5, 11, 21, 43, 85, 171...

#### 5.3 Creating the Insertion Order

The most complex part is generating the insertion order using the Jacobsthal sequence:

```cpp
std::vector<int> PmergeMe::generateInsertionOrder(std::vector<int> &jacobSeq, size_t pairsSize)
{
    std::vector<int> insertionOrder;
    std::vector<bool> inserted(pairsSize, false);
    inserted[0] = true; // Mark first pair as already processed

    for (size_t i = 1; i < jacobSeq.size(); i++)
    {
        int idx = jacobSeq[i];
        if (idx < (int)pairsSize && !inserted[idx])
        {
            insertionOrder.push_back(idx);
            inserted[idx] = true;
        }

        for (int j = idx - 1; j > jacobSeq[i - 1]; j--)
        {
            if (j >= 0 && j < (int)pairsSize && !inserted[j])
            {
                insertionOrder.push_back(j);
                inserted[j] = true;
            }
        }
    }

    for (size_t i = 1; i < pairsSize; i++)
    {
        if (!inserted[i])
            insertionOrder.push_back(i);
    }

    return insertionOrder;
}
```

Let's trace through this function step by step with an example of 8 pairs:

1. Initialize `insertionOrder` as an empty vector
2. Create `inserted` as a vector of 8 booleans, all initialized to `false`
3. Mark the first element as already processed: `inserted[0] = true`
4. With 8 pairs, we need a Jacobsthal sequence like `[0, 1, 1, 3, 5, 11]`

Now we loop through the Jacobsthal sequence starting from index 1:

**For i=1 (Jacobsthal value 1):**
- `idx = jacobSeq[1] = 1`
- This index is valid and not inserted yet, so add 1 to `insertionOrder`: `[1]`
- Mark `inserted[1] = true`
- Check integers between 1 and previous Jacobsthal (0) - none exist

**For i=2 (Jacobsthal value 1 again):**
- `idx = jacobSeq[2] = 1`
- This is already inserted, so skip it
- Check integers between 1 and previous Jacobsthal (1) - none exist

**For i=3 (Jacobsthal value 3):**
- `idx = jacobSeq[3] = 3`
- This index is valid and not inserted yet, so add 3 to `insertionOrder`: `[1, 3]`
- Mark `inserted[3] = true`
- Check integers between 3 and previous Jacobsthal (1) in reverse order:
  - j=2: Not inserted yet, add to `insertionOrder`: `[1, 3, 2]`
  - Mark `inserted[2] = true`

**For i=4 (Jacobsthal value 5):**
- `idx = jacobSeq[4] = 5`
- This index is valid and not inserted yet, so add 5 to `insertionOrder`: `[1, 3, 2, 5]`
- Mark `inserted[5] = true`
- Check integers between 5 and previous Jacobsthal (3) in reverse order:
  - j=4: Not inserted yet, add to `insertionOrder`: `[1, 3, 2, 5, 4]`
  - Mark `inserted[4] = true`

**For i=5 (Jacobsthal value 11):**
- `idx = jacobSeq[5] = 11`
- This is beyond our pairs size (8), so we skip it
- No integers to check between

**Final check for any remaining unprocessed indices:**
- Indices 0,1,2,3,4,5 are marked as inserted
- Indices 6,7 are not marked yet, so add them to `insertionOrder`: `[1, 3, 2, 5, 4, 6, 7]`

The final insertion order is `[1, 3, 2, 5, 4, 6, 7]`.

This complex ordering is what makes the Ford-Johnson algorithm special. By inserting elements in this specific order, we minimize the number of comparisons needed during binary insertion.

### Step 6: Insert Remaining Elements According to the Insertion Order

Once we have our insertion order, we systematically insert the remaining elements:

```cpp
for (size_t i = 0; i < insertionOrder.size(); i++) {
    int idx = insertionOrder[i];
    std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(), mainChain[idx]);
    result.insert(pos, mainChain[idx]);

    pos = std::lower_bound(result.begin(), result.end(), pairs[idx].second);
    result.insert(pos, pairs[idx].second);
}
```

Let's examine this insertion process in extreme detail using our example with insertion order `[1, 3, 2, 5, 4, 6, 7]` for 8 pairs:

#### 6.1 Binary Search Insertion Process

For each index in our insertion order, we perform two key operations:
1. Insert the main chain element (if not already in the result)
2. Insert the corresponding smaller element from the pair

Let's assume our current `result` is `[1, 3]` (first main chain element and first pair's smaller element) and our main chain is `[6, 7, 8, 9, 10, 11, 12, 13]`. Our original pairs were:
- Pair 0: `(6, 1)` - already processed
- Pair 1: `(7, 2)`
- Pair 2: `(8, 3)`
- Pair 3: `(9, 4)`
- Pair 4: `(10, 5)`
- Pair 5: `(11, 6)`
- Pair 6: `(12, 7)`
- Pair 7: `(13, 8)`

**First iteration (i=0, idx=1):**
- We need to process pair 1: `(7, 2)`
- Find position for `mainChain[1]` which is `7`:
  - `std::lower_bound(result.begin(), result.end(), 7)` performs a binary search:
    - Mid element is `3`, `7 > 3`, so search in right half
    - No more elements, so return position after `3`
  - Insert `7` at this position: `result = [1, 3, 7]`
- Find position for `pairs[1].second` which is `2`:
  - `std::lower_bound(result.begin(), result.end(), 2)` performs a binary search:
    - Mid element is `3`, `2 < 3`, so search in left half
    - Mid element is `1`, `2 > 1`, so position is after `1`
  - Insert `2` at this position: `result = [1, 2, 3, 7]`

**Second iteration (i=1, idx=3):**
- We need to process pair 3: `(9, 4)`
- Find position for `mainChain[3]` which is `9`:
  - Binary search finds position after `7`
  - Insert `9` at this position: `result = [1, 2, 3, 7, 9]`
- Find position for `pairs[3].second` which is `4`:
  - Binary search finds position after `3` and before `7`
  - Insert `4` at this position: `result = [1, 2, 3, 4, 7, 9]`

**Third iteration (i=2, idx=2):**
- We need to process pair 2: `(8, 3)`
- Find position for `mainChain[2]` which is `8`:
  - Binary search finds position after `7` and before `9`
  - Insert `8` at this position: `result = [1, 2, 3, 4, 7, 8, 9]`
- Find position for `pairs[2].second` which is `3`:
  - Binary search finds position where `3` would go, but it's already there!
  - If we were strictly implementing the algorithm, we'd insert it again, but in practice our code might handle this differently

We would continue this process for the remaining indices in our insertion order (5, 4, 6, 7).

#### 6.2 The `std::lower_bound` Magic

The `std::lower_bound` function is crucial to this algorithm's efficiency. It implements a binary search algorithm to find the first position where a value could be inserted while maintaining the sorted order.

For an array of size n, binary search has a time complexity of O(log n), which is vastly more efficient than a linear search (O(n)) for large arrays.

For example, when finding the position to insert `4` in `[1, 2, 3, 7, 9]`:

1. Compare with middle element (position 2): `3`
   - `4 > 3`, so search in right half `[7, 9]`
2. Compare with middle element (position 3): `7`
   - `4 < 7`, so search in left half - but there's nothing between `3` and `7`
3. Return position after `3`, which is position 3 (before `7`)

This entire search took just 2 comparisons, whereas a linear search might have taken up to 5.

#### 6.3 Performance Advantage of Ford-Johnson

This insertion strategy, guided by the Jacobsthal sequence, is what gives the Ford-Johnson algorithm its performance advantage. By carefully controlling the order of insertions, we maximize the efficiency of each binary search.

Without this strategic ordering, we might end up with worst-case scenarios for binary search. The Jacobsthal sequence ensures we build the sorted result in a way that minimizes total comparisons.

### Step 7: Handle the Straggler Element

Finally, if we had a straggler (odd element), we insert it back into our sorted array:
```
if (hasStraggler) {
    std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(), straggler);
    result.insert(pos, straggler);
}
```

We use binary search again to find the correct position for the straggler element.

### Step 8: Update the Original Vector

The last step is to update our original vector with the sorted result:
```
_vec = result;
```

### Complete Flow Using an Example

Let's trace through the algorithm with a simple example: `[3, 1, 4, 2, 5]`.

1. We identify element `5` as a straggler and set it aside: `[3, 1, 4, 2]`
2. We form pairs: `(3,1)` and `(4,2)`
3. We ensure larger element is first (already done): `(3,1)` and `(4,2)`
4. We extract the main chain: `[3, 4]`
5. We recursively sort the main chain:
   - With only 2 elements, we form a single pair: `(3,4)`
   - Swap to ensure larger is first: `(4,3)`
   - The main chain is now just `[4]`
   - Since it's only one element, it's already sorted
   - Working back up, we insert `3` using binary search: `[3, 4]`
6. We initialize our result with first main chain element and first pair's smaller element: `[1, 3]`
7. For the second pair, we use our insertion order:
   - Insert `4` using binary search: `[1, 3, 4]`
   - Insert `2` using binary search: `[1, 2, 3, 4]`
8. Finally, insert the straggler `5`: `[1, 2, 3, 4, 5]`

The Ford-Johnson algorithm thus efficiently sorts the array while minimizing the number of comparisons required.