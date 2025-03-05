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

1. Pair Up Elements:
    - The elements are divided into pairs (if there's an odd number, one element is left alone).
    - Each pair is compared, and the larger element is selected.
2. Sort the Larger Elements:
    - The larger elements from each pair are sorted recursively, forming a sorted list.

3. Insert the Remaining Elements:
    - The smaller elements from the pairs (and the leftover element, if any) are inserted into the sorted list one by one.
    - To minimize comparisons, the insertions follow a special order and use the Jacobsthal sequence.

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


##  **Example: Sorting the list [9, 3, 7, 1, 8, 4, 6, 2, 5]**

### **Step 1: Pairing the Elements**

- First, we group the elements into pairs:
  - (9, 3)
  - (7, 1)
  - (8, 4)
  - (6, 2)
  - (5) – This element remains unpaired since the list has an odd number of elements.

### **Step 2: Compare Each Pair**

- Next, we compare each pair and determine the smaller and larger elements:
  - (9, 3) → **9** is larger, **3** is smaller.
  - (7, 1) → **7** is larger, **1** is smaller.
  - (8, 4) → **8** is larger, **4** is smaller.
  - (6, 2) → **6** is larger, **2** is smaller.
  - (5) → This element remains as it is because it’s unpaired.

- This results in:
  - **Larger elements**: [9, 7, 8, 6]
  - **Smaller elements + unpaired**: [3, 1, 4, 2, 5]

### **Step 3: Form and Sort the Main Chain**

- Now, we form the main chain by sorting the **larger elements**:
  - Main Chain: [9, 7, 8, 6]
  
- We recursively apply the same sorting process to the **main chain** (i.e., [9, 7, 8, 6]) until we have a single element:
  - **Pair up** the elements:
    - [9, 7]
    - [8, 6]
  
  - **Sort** each pair:
    - (9, 7) → **9** is larger than **7**, so it stays as [9, 7].
    - (8, 6) → **8** is larger than **6**, so it stays as [8, 6].

  - **Form new main chain** after sorting the pairs: [9, 7], [8, 6] → Merge them into: [9, 8, 7, 6]
  
- Now, recursively apply sorting until only one element remains:
  - **Pair up**: [9, 8]
  - **Sort**: [8, 9]
  - **Form main chain**: [8, 9]
  
- Now we merge the remaining element from the previous step (6):
  - Inserting 6 into [8, 9] → Result: [6, 8, 9]

- After sorting and merging, we get the fully sorted **Main Chain**: [6, 7, 8, 9]

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

This is where the Ford-Johnson algorithm truly shines. Instead of inserting pend elements in a simple order, we use sequence based on [Jacobsthal numbers](https://en.wikipedia.org/wiki/Jacobsthal_number).

**Why Jacobsthal?**

The Ford-Johnson algorithm (merge-insert sort) uses the Jacobsthal sequence because it provides an optimal or near-optimal insertion order when inserting elements into a sorted sequence. The key insight is that by inserting elements according to this sequence, we can minimize the total number of comparisons needed.

