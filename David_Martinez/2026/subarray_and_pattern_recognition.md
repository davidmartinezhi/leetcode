# Subarray & DP Pattern Recognition Cheatsheet

## 1. Contiguous Sum (Kadane's Algorithm)

**When to use:** You need the maximum (or minimum) sum of a contiguous subarray.

**Key indicators:**
- The operation is addition
- Elements are contiguous (subarray, not subsequence)
- You want max or min sum

**Core intuition:** If the accumulated sum drops below 0, it can only hurt you. Start fresh.

**Template:**
```cpp
int max_sum = nums[0];
int curr_sum = 0;

for (int i = 0; i < n; i++) {
    curr_sum += nums[i];
    max_sum = max(max_sum, curr_sum);
    if (curr_sum < 0) curr_sum = 0;
}
```

**Why it works:** 0 is the neutral element of addition. Anything below 0 means the accumulated prefix is actively dragging down any future subarray.

**Examples:**
- Maximum subarray sum (classic)
- Minimum subarray sum (flip signs or invert comparison)
- Maximum sum circular subarray (combine max and min Kadane)

**Does NOT apply when:**
- Elements don't need to be contiguous (that's a different DP or greedy problem)
- The array is circular (needs a modified version)
- The operation is multiplication

---

## 2. Contiguous Product (Min/Max Tracking)

**When to use:** You need the maximum (or minimum) product of a contiguous subarray.

**Key indicators:**
- The operation is multiplication
- A negative times a negative can become the new max
- Zeros kill the entire product

**Core intuition:** You can't just reset at a threshold like Kadane. A single negative can flip min to max. Track both min and max at every step.

**Template:**
```cpp
int max_product = nums[0];
int max_end = nums[0];
int min_end = nums[0];

for (int i = 1; i < n; i++) {
    int old_max = max_end;
    int old_min = min_end;
    max_end = max({nums[i], old_max * nums[i], old_min * nums[i]});
    min_end = min({nums[i], old_max * nums[i], old_min * nums[i]});
    max_product = max(max_product, max_end);
}
```

**Why it works:** Multiplication has sign-flipping behavior. The minimum product (a large negative) can instantly become the maximum when multiplied by another negative. Tracking both covers all cases.

**Three candidates at each step:**
1. Start fresh with `nums[i]` alone
2. Extend the current max: `max_end * nums[i]`
3. Extend the current min: `min_end * nums[i]` (negative * negative = positive)

**Examples:**
- Maximum product subarray (classic)
- Problems involving contiguous multiplication with negatives and zeros

**Does NOT apply when:**
- The operation is addition (use Kadane)
- You're selecting non-contiguous elements (use knapsack or greedy)

---

## 3. Knapsack (Selection with Constraint)

**When to use:** You choose items from a set to optimize a value without exceeding a capacity.

**Key indicators:**
- Each item has a cost and a value (or weight and benefit)
- There is a capacity/budget/limit you cannot exceed
- You make include/exclude decisions per item
- Items do NOT need to be contiguous

**Core intuition:** For each item, you decide: take it or skip it. Build up optimal solutions for smaller capacities first.

### 3a. 0/1 Knapsack

Each item can be taken at most once.

**Template:**
```cpp
// dp[j] = max value achievable with capacity j
vector<int> dp(capacity + 1, 0);

for (int i = 0; i < n; i++) {
    for (int j = capacity; j >= weight[i]; j--) {  // reverse to avoid reuse
        dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
    }
}
// answer: dp[capacity]
```

**Examples:**
- Classic knapsack (items with weight and value, limited bag capacity)
- Partition equal subset sum (can you split array into two equal halves?)
- Target sum (assign + or - to each number to reach a target)

### 3b. Unbounded Knapsack

Each item can be taken unlimited times.

**Template:**
```cpp
vector<int> dp(capacity + 1, 0);

for (int i = 0; i < n; i++) {
    for (int j = weight[i]; j <= capacity; j++) {  // forward allows reuse
        dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
    }
}
```

**Examples:**
- Coin change (minimum coins to make amount)
- Coin change II (number of ways to make amount)
- Rod cutting (maximize profit by cutting rod into pieces)

### 3c. Subset Sum

Special case where value = weight. You want to know if you can reach an exact sum.

**Template:**
```cpp
vector<bool> dp(target + 1, false);
dp[0] = true;

for (int i = 0; i < n; i++) {
    for (int j = target; j >= nums[i]; j--) {
        dp[j] = dp[j] || dp[j - nums[i]];
    }
}
// answer: dp[target]
```

**Examples:**
- Can you partition the array into two subsets with equal sum?
- Does any subset sum to exactly K?

---

## Quick Decision Guide

```
Is the operation addition or multiplication?
|
+-- Addition
|   |
|   +-- Contiguous subarray? --> Kadane
|   +-- Select items with constraint? --> Knapsack
|   +-- Select items, no constraint? --> Greedy or sort
|
+-- Multiplication
    |
    +-- Contiguous subarray? --> Min/Max tracking
    +-- Non-contiguous? --> Likely a different DP or math problem
```

## Key Differences Summary

| Aspect             | Kadane (Sum)       | Min/Max Product     | Knapsack            |
|--------------------|--------------------|---------------------|---------------------|
| Operation          | Addition           | Multiplication      | Addition (usually)  |
| Contiguous?        | Yes                | Yes                 | No                  |
| Reset condition    | Sum < 0            | Never (track both)  | N/A                 |
| Why it works       | Negative sum only  | Negatives flip sign | Build optimal       |
|                    | drags you down     |                     | from subproblems    |
| Runtime            | O(n)               | O(n)                | O(n * capacity)     |
| Space              | O(1)               | O(1)                | O(capacity)         |

# two pointers variants

- la variante de tener un pointer static que solo se usa para colocar un tipo de valor como en el de move zerows o remove duplicates. mientras tienes el otro pointer que explora el array. uno recorre hasta el final y el otro solo es la estaca que va colocando los valores no duplicados o que no son 0s. esta tecnica es un clasico
- two pointers
    - -><-
    - <-->
    - ->->
        - static y dinamic
        - uno recorre y el otro recorre hasta el status actual
