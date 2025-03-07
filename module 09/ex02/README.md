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


##  **Example: Sorting the list `[9, 3, 7, 1, 8, 4, 6, 2, 5]`**

### **Step 1: Pairing the Elements**

- First, we group the elements into pairs:
  - `(9, 3)`
  - `(7, 1)`
  - `(8, 4)`
  - `(6, 2)`
  - `(5)` – This element remains unpaired since the list has an odd number of elements.

### **Step 2: Compare Each Pair**

- Next, we compare each pair and determine the smaller and larger elements:
  - `(9, 3)` → **`9`** is larger, **`3`** is smaller.
  - `(7, 1)` → **`7`** is larger, **`1`** is smaller.
  - `(8, 4)` → **`8`** is larger, **`4`** is smaller.
  - `(6, 2)` → **`6`** is larger, **`2`** is smaller.
  - `(5)` → This element remains as it is because it’s unpaired.

- This results in:
  - **Larger elements**: `[9, 7, 8, 6]`
  - **Smaller elements + unpaired**: `[3, 1, 4, 2, 5]`

### **Step 3: Form and Sort the Main Chain**

- Now, we form the main chain by sorting the **larger elements**:
  - **Main Chain**: `[9, 7, 8, 6]`
  
- We recursively apply the same sorting process to the **main chain** (i.e., `[9, 7, 8, 6]`) until we have a single element:
  - **Pair up** the elements:
    - `[9, 7]`
    - `[8, 6]`
  
  - **Sort** each pair:
    - `(9, 7)` → **`9`** is larger than **`7`**, so it stays as `[9, 7]`.
    - `(8, 6)` → **`8`** is larger than **`6`**, so it stays as `[8, 6]`.

  - **Form new main chain** after sorting the pairs: `[9, 7]`, `[8, 6]` → Merge them into: `[9, 8, 7, 6]`
  
- Now, recursively apply sorting until only one element remains:
  - **Pair up**: `[9, 8]`
  - **Sort**: `[8, 9]`
  - **Form main chain**: `[8, 9]`
  
- Now we merge the remaining element from the previous step (`6`):
  - Inserting `6` into `[8, 9]` → Result: `[6, 8, 9]`

- After sorting and merging, we get the fully sorted **Main Chain**: `[6, 7, 8, 9]`

### **Step 4: Created Pend Chain**

- The "pend" chain consists of the smaller elements from each original pair, with each element being associated with a specific element from the main chain:
  - **1** is associated with **3**
  - **4** is associated with **5**
  - **2** is associated with **6**
  - **6** is associated with **8**

- Now, we have:
  - **Main Chain**: [6, 7, 8, 9]
  - **Pend Chain**: [1, 4, 2, 6]

### **Step 5: Merging the Main Chain and Pend Chain**

This is where the Ford-Johnson algorithm truly shines. Instead of inserting pend elements in a simple order, we use sequence based on [Jacobsthal numbers](https://en.wikipedia.org/wiki/Jacobsthal_number). Think of it as a mathematical pattern, similar to the Fibonacci sequence but with different rules:

- The Jacobsthal sequence is a specific integer sequence defined as:
  - `J(0)` = `0`
  - `J(1)` = `1`
  - `J(n)` = `J(n-1) + 2*J(n-2) for n ≥ 2`

So the sequence begins: `0, 1, 1, 3, 5, 11, 21, 43, 85, 171, ...`

This sequence is important for determining the order in which we'll insert elements later in the algorithm.

```cpp
std::vector<int> PmergeMe::getJacobsthalSequence(int n) {
    std::vector<int> jacobsthal;
    
    jacobsthal.push_back(0);
    if (n > 0)
        jacobsthal.push_back(1);
    
    for (int i = 2; i <= n; i++) {
        int next = jacobsthal[i-1] + 2 * jacobsthal[i-2];
        jacobsthal.push_back(next);
    }
    
    return jacobsthal;
}
```

**Why Jacobsthal?**

The key insight of the Ford-Johnson algorithm is that the Jacobsthal sequence provides an efficient order for binary insertion. When inserting elements into a sorted sequence, we typically need to perform binary searches to find the right position. The Jacobsthal sequence minimizes the number of comparisons needed across all these insertions.
To understand why:

1. The Jacobsthal numbers grow roughly at a rate between linear and exponential
2. By inserting elements in this specific order, we're optimizing the "divide" part of the binary search
3. It ensures that we're making progress in sorting the array while minimizing comparisons

## The Main Sorting Function - sortVector

### Step 1: Handle odd-sized array

```cpp
bool hasStraggler = false;
int straggler = 0;

if (_vec.size() % 2 != 0) {
    hasStraggler = true;
    straggler = _vec.back();
    _vec.pop_back();
}
```

If we have an odd number of elements, we temporarily remove the last element (called the "straggler") and set it aside to deal with later. This makes the rest of the algorithm easier since we'll be working with pairs.

### Step 2: Form pairs from consecutive elements

```cpp
std::vector<std::pair<int, int> > pairs;
for (size_t i = 0; i < _vec.size(); i += 2) {
    int first = _vec[i];
    int second = _vec[i + 1];
    pairs.push_back(std::make_pair(first, second));
}
```
Here we're taking elements two at a time and creating pairs. For example, if our array is `[3, 1, 4, 2]`, we form pairs: `(3,1)` and `(4,2)`.

### Step 3: Sort elements within pairs

```cpp
for (size_t i = 0; i < pairs.size(); i++) {
    if (pairs[i].first < pairs[i].second)
        std::swap(pairs[i].first, pairs[i].second);
}
```

We sort each pair so the larger element is first. Our pairs would now be: `(3,1)` → `(3,1)` and `(4,2)` → `(4,2)`.


### Step 4: Extract main chain (larger elements)

```cpp
std::vector<int> mainChain;
for (size_t i = 0; i < pairs.size(); i++) {
    mainChain.push_back(pairs[i].first);
}
```
We take all the larger elements (the first element in each pair) to form what's called the "main chain". In our example, that's `[3, 4]`.

### Step 5: Recursively sort main chain

```cpp
if (mainChain.size() > 1) {
    _vec = mainChain;
    sortVector();
    mainChain = _vec;
}
```

### Step 6 & 7: Initialize result with first elements

```cpp
std::vector<int> result;
if (!mainChain.empty())
    result.push_back(mainChain[0]);

if (!pairs.empty())
    result.insert(result.begin(), pairs[0].second);
```

We start building our final sorted list:

- Add the first element from the sorted main chain `(3)`
- Insert the smaller element from the first pair `(1)` at the beginning
So our result is now `[1, 3]`.

### Step 8: Using the Jacobsthal Sequence for Remaining Elements

At this point in our example, we have:

- Original array: `[3, 1, 4, 2]`
- Pairs: `(3,1)` and `(4,2)` (with larger elements first)
- Main chain (sorted): `[3, 4]`
- Current result: `[1, 3]` (first smaller element and first main chain element)

Now we need to efficiently insert the remaining elements.

#### 8.1: Generate the Jacobsthal Sequence

```cpp
int jacobsthalSize = 3;
while (getJacobsthalSequence(jacobsthalSize).back() < (int)pairs.size())
    jacobsthalSize++;

std::vector<int> jacobSeq = getJacobsthalSequence(jacobsthalSize);
```

First, we need to determine how many Jacobsthal numbers we need. We need enough numbers to cover all our pairs (in this case, 2 pairs).

1. Start with `jacobsthalSize = 3`
2. The Jacobsthal sequence for `3` is `[0, 1, 1]`
3. The last number is `1`, which is less than our pairs size `(2)`
4. So we increment to `jacobsthalSize = 4`
5. The Jacobsthal sequence for `4` is `[0, 1, 1, 3]`
6. The last number is `3`, which is greater than our pairs size `(2)`
7. We stop and use this sequence: `[0, 1, 1, 3]`


#### 8.2: Calculate Insertion Order

```cpp
std::vector<int> insertionOrder;
std::vector<bool> inserted(pairs.size(), false);
inserted[0] = true; // Mark first pair as already processed
```

We're creating a list to track the order in which we'll insert the remaining pairs. We start by marking pair 0 as already processed (since we've already added it to our result in steps 6 and 7).

```cpp
for (size_t i = 1; i < jacobSeq.size() && jacobSeq[i] < (int)pairs.size(); i++) {
    int idx = jacobSeq[i];
    if (!inserted[idx]) {
        insertionOrder.push_back(idx);
        inserted[idx] = true;
    }
    
    // Fill in between Jacobsthal numbers in descending order
    for (int j = idx - 1; j > jacobSeq[i-1]; j--) {
        if (j >= 0 && j < (int)pairs.size() && !inserted[j]) {
            insertionOrder.push_back(j);
            inserted[j] = true;
        }
    }
}
```

Now we use the Jacobsthal sequence to determine the insertion order. The algorithm is:

1. Start with the Jacobsthal numbers after `0`: `[1, 1, 3]`
2. For each Jacobsthal number:
  - Add that index to the insertion order (if it exists and hasn't been processed)
  - Then, check all indices between this Jacobsthal number and the previous one, in reverse order

Let's trace through this logic:

- First, we look at Jacobsthal number at index `1`, which is `1`
- We add `1` to our insertion order: [1]
- There are no indices between `1` and the previous Jacobsthal number (`0`)
- Next, we look at Jacobsthal number at index `2`, which is also `1`
- It's already been processed, so we skip it
- No new indices to check
- Next, we look at Jacobsthal number at index `3`, which is `3`
- This is greater than our pairs size (`2`), so we don't use it

So our insertion order becomes just [1].

```cpp
// Add any remaining indices
for (size_t i = 1; i < pairs.size(); i++) {
    if (!inserted[i])
        insertionOrder.push_back(i);
}
```

This code makes sure any indices that weren't covered by the Jacobsthal sequence get added to the end of our insertion order. In our example, since `pairs.size()` is `2` and we've only processed index `1`, there are no additional indices to add.

So our final insertion order is `[1]`, meaning we'll insert pair at index `1` next.

#### 8.3: Insert Elements According to the Determined Order

At this point in our example:

- Our result array is: `[1, 3]` (containing the first small element and first main chain element)
- Our insertion order is: `[1]` (meaning we need to process the pair at index 1)
- The pair at index 1 is: `(4, 2)` (larger element 4, smaller element 2)

Let's examine the code with extremely detailed attention:

```cpp
for (size_t i = 0; i < insertionOrder.size(); i++) {
    int idx = insertionOrder[i];
    
    // Insert main chain element if not already in result
    if (std::find(result.begin(), result.end(), mainChain[idx]) == result.end()) {
        std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(), mainChain[idx]);
        result.insert(pos, mainChain[idx]);
    }
    
    // Insert smaller element
    std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(), pairs[idx].second);
    result.insert(pos, pairs[idx].second);
}
```

**Step-by-Step Execution**

1. We begin the loop with `i = 0`
2. We set `idx = insertionOrder[0]`, which is `1`

**Inserting the Main Chain Element**

First, we check if the main chain element at index `1` is already in our result:

```cpp
if (std::find(result.begin(), result.end(), mainChain[idx]) == result.end())
```

- `mainChain[1]` is `4`
- `std::find` searches through `result` (`[1, 3]`) looking for the value `4`
- Since `4` is not in `result`, `std::find` returns `result.end()`
- The condition evaluates to `true`, so we enter the if-block

Now we need to find the correct position to insert `4`:

```cpp
std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(), mainChain[idx]);
```

- `std::lower_bound` is a binary search algorithm that finds the position where we should insert a value to maintain the sorted order
- It searches through `result` (`[1, 3]`) to find the first position where `4` could be inserted
- The function returns an iterator pointing to the position after `3` (the end of the array)
- So `pos` points to the position after `3`

Then we insert `4` at this position:

```cpp
result.insert(pos, mainChain[idx]);
```

- This inserts `4` at the position pointed to by `pos` (after `3`)
- Our `result` is now `[1, 3, 4]`

**Inserting the Smaller Element**

```cpp
std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(), pairs[idx].second);
```

- `pairs[1].second` is `2` (the smaller element in the second pair)
- `std::lower_bound` searches through `result` (`[1, 3, 4]`) to find where `2` should go
- Since `2` is greater than `1` but less than `3`, it returns an iterator pointing to the position of `3` (index 1)
- So `pos` points to the position of `3`

