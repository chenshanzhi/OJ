# Exercises in *Programming Contest Challenge Book, 2e* 

> 挑战程序设计竞赛（第2版）练习题

--8<-- "includes/links-of-problems.txt"
--8<-- "includes/links-of-codes.txt"

## 2.1
### POJ 1979
[:octicons-link-24: Problem][problem-poj-1979]
[:octicons-file-code-24: Code][code-poj-1979]

  - Naive DFS.

### AOJ 0118
[:octicons-link-24: Problem][problem-aoj-0118]
[:octicons-file-code-24: Code][code-aoj-0118]

  - Naive DFS from every unvisited vertex of the graph.

### AOJ 0033
[:octicons-link-24: Problem][problem-aoj-0033]
[:octicons-file-code-24: Code][code-aoj-0033]

  - Naive DFS works since $`n = 10`$. There are at most $`2^n = 1024`$ possiblities.
  - Greedy algorithm also works. Keep the two uppermost values in both cylinders: $`l`$ and $`r`$, where $`(l < r)`$. For a newly-dropped ball of value $`e`$:
    - If $`e < l < r`$, it can be placed on neither side.
    - If $`l < e < r`$, it can only be placed on $`l`$.
    - If $`l < r < e`$, it can be placed on either $`l`$ or $`r`$. But it should be placed on $`r`$ since placing $`e`$ on $`l`$ is never better than placing $`e`$ on $`r`$. 

### POJ 3009
[:octicons-link-24: Problem][problem-poj-3009]
[:octicons-file-code-24: Code][code-poj-3009]

  - DFS and pruning.

### AOJ 0558
[:octicons-link-24: Problem][problem-aoj-0558]
[:octicons-file-code-24: Code][code-aoj-0558]

  - BFS: The mouse must eat cheeses in the order of $`1, 2, \dots, N`$.

### POJ 3669
[:octicons-link-24: Problem][problem-poj-3669]
[:octicons-file-code-24: Code][code-poj-3669]

  - BFS:
    - The target of search is to find a safe location which is not destroyed by the meteors. Use BFS and keep all reachable points in the queue until the target is reached.
    - Consider a point $`(x_i, y_i)`$ that is destoryed by a meteor at $`t_i`$ at the first time. The accessible time of $`(x_i, y_i)`$ is $`[0, t_i)`$. Use `G[x][y]` to represent the upper bound of accessible time for point $`(x_i, y_i)`$, which is $`t_{\text{min}}`$ for all meteors that destory $`(x_i, y_i)`$. `G[x][y]` should be considered when we traverse through the neighbor points.
    - $`0 \le x_i, y_i \le 300`$ implies `G[302][302]` is enough. All points $`(301, *)`$ or $`(*, 301)`$ must be safe.
    - The solution, if possible, should be in the range $`[0, 1000]`$ since $`0 \le t_i \le 1000`$.

### AOJ 0121
[:octicons-link-24: Problem][problem-aoj-0121]
[:octicons-file-code-24: Code][code-aoj-0121]

  - BFS, bit manipulation, and precomputation: 
    - The result can be precomputed since $`8! = 40320`$ is small.

### POJ 2718
[:octicons-link-24: Problem][problem-poj-2718]
[:octicons-file-code-24: Code][code-poj-2718]

  - Exhausive search: `std::next_permutation`

### POJ 3187
[:octicons-link-24: Problem][problem-poj-3187]
[:octicons-file-code-24: Code][code-poj-3187]

  - Binomial expansion, Pascal's triangle, and Pascal's rule $`{n \choose k} = {n - 1 \choose k} + { n - 1 \choose k - 1} `$

### POJ 3050
[:octicons-link-24: Problem][problem-poj-3050]
[:octicons-file-code-24: Code][code-poj-3050]

  - We use DFS directly because $`5 \times 5 \times 4^5 = 25600 < 10^{5}`$

### AOJ 0525
[:octicons-link-24: Problem][problem-aoj-0525]
[:octicons-file-code-24: Code][code-aoj-0525]

  - State compression: $`2^{R + C} \to  2^R \cdot C \quad (1 \le R \le 10, 1 \le C \le 10^4)`$.
  - Bit manipulation: `__built_in_popcount` in GCC or `std::popcount` since C++20.

## 2.2
### POJ 2376
[:octicons-link-24: Problem][problem-poj-2376]
[:octicons-file-code-24: Code][code-poj-2376]

  - The unassigned shift $`[L, T]`$ can be assigned to the cow $`i`$ that is available on the interval $`[L_i, R_i]`$ as long as $`L_i \le L`$. And among all feasible choices, we choose the one with maximum $`R_i`$, which makes the remaining unassigned shift becomes $`[R_i + 1, T]`$.

### POJ 1328
[:octicons-link-24: Problem][problem-poj-1328]
[:octicons-file-code-24: Code][code-poj-1328]

  - Each island corresponds to an interval $`[a_i, b_i]`$ on the $`x`$-axis, on which we could install a radar to cover the island.
  - Sort the intervals $`[a_i, b_i]`$ in nondescreasing order: $`[a_i, b_i] < [a_j, b_j] \iff ((a_i < b_j) \lor (a_i = a_j \land b_i < b_j))`$. 
  - For $`i = 1, 2, \dots, N`$, make the current radar cover islands as many as possible.

### POJ 3190
[:octicons-link-24: Problem][problem-poj-3190]
[:octicons-file-code-24: Code][code-poj-3190]

  - Sort the intervals $`[a_i, b_i]`$ in nondescreasing order: $`[a_i, b_i] < [a_j, b_j] \iff a_i < b_j`$. 
  - For the cow with interval $`[a_i, b_i]`$:
    - If none of the stall is available for it, add a new stall.
    - Else, for all available stalls, choose any one of them. We choose the one that is available as early as possible.

### POJ 2393
[:octicons-link-24: Problem][problem-poj-2393]
[:octicons-file-code-24: Code][code-poj-2393]

  - The cost chosen in the $`n`$-th week should be the minimum cost from week $`1`$ to week $`n`$, which is:
  ```math
  \min_{1 \le i \le n}{ \lbrace c_i + s \cdot (n - i) \rbrace } = \min_{1 \le i \le n}{\lbrace c_i - s \cdot i \rbrace}  + s \cdot n
  ```
  - CAUTION: Since $`N \cdot C \cdot Y = 10^{4} \cdot 5000 \cdot 10^4 = 5 \cdot 10^{12} < 2^{40}`$,`long long` should be used.

### POJ 1017
[:octicons-link-24: Problem][problem-poj-1017]
[:octicons-file-code-24: Code][code-poj-1017]

  - Greedy algorithm: Deliver packets in decreasing order.
    - Deliver the packet of $`6 \times 6`$, $`5 \times 5`$, $`4 \times 4`$, $`3 \times 3`$ and remember the space left for $`2 \times 2`$ and $`1 \times 1`$.
    - Deliver $`2 \times 2`$: use the space left previously for $`2 \times 2`$ as much as possible and then transform the unused space for $`2 \times 2`$ into $`1 \times 1`$.
    - Deliver $`1 \times 1`$: use space left previously for $`1 \times 1`$ as much as possible.

### POJ 3040
[:octicons-link-24: Problem][problem-poj-3040]
[:octicons-file-code-24: Code][code-poj-3040]

  - To pay at least $`C`$ cents, choose coins in two steps:
    - Choose coins from large to small to pay some cents that is close to but not exceeding $`C`$.
    - Choose coins from small to large to pay the remaining cents.

### POJ 1862
[:octicons-link-24: Problem][problem-poj-1862]
[:octicons-file-code-24: Code][code-poj-1862]

  - The result is
    ```math
    2^{N-1} \cdot m_{1}^{0.5^{N-1}} \cdot m_{2}^{0.5^{N-1}} \cdot m_{3}^{0.5^{N-2}} \cdots  m_{k}^{0.5^{N+1-k}} \cdots m_{N-1}^{0.5^2} \cdot m_{N}^{0.5}
    ```
    which is minimized when
    ```math
    m_1 \ge m_2 \ge m_3 \ge \cdots \ge m_{N-1} \ge m_N
    ```

  - Proof: Assume $`1 < i < j`$ and $`m_i \ge m_j > 0`$, exchange the $`i`$-th and $`j`$-th element make the result smaller since
    ```math
     \frac{m_i^{0.5^{N+1-i}} \cdot m_j^{0.5^{N+1-j}}}{m_j^{0.5^{N+1-i}} \cdot m_i^{0.5^{N+1-j}}} = (\frac{m_i}{m_j})^{0.5^{j - i}} \ge 1
    ```

### POJ 3262
[:octicons-link-24: Problem][problem-poj-3262]
[:octicons-file-code-24: Code][code-poj-3262]

  - Intuition: Transport the cows with larger $`\frac{D}{T}`$ as soon as possible, since they eat faster and the time to transport them is shorter.
  - Proof: The difference of the flower losses introduced by exchanging the $`i`$-th and the $`(i+1)`$-th is $`T_{i + 1} \cdot D_{i} \to T_i \cdot D_{i + 1}`$. That's to say, exchanging any consecutive pair that satisfies $`T_{i + 1} \cdot D_{i} > T_i \cdot D_{i + 1}`$  can generate less flower losses.

## 2.3
### POJ 3176
[:octicons-link-24: Problem][problem-poj-3176]
[:octicons-file-code-24: Code][code-poj-3176]

  - 
    ```math
    dp[i][j] =
    \begin{cases}
    \max \lbrace dp[i - 1][j - 1], dp[i - 1][j] \rbrace   + \text{a}[i][j] & (1 \le j \le i \le N) \\
    0 & (\text{otherwise})
    \end{cases}
    ```

### POJ 2229
[:octicons-link-24: Problem][problem-poj-2229]
[:octicons-file-code-24: Code][code-poj-2229]

  - Hint: Is $`1`$ in the sum or not?
  - 
    ```math
    dp[n] =
    \begin{cases}
        0                                           & (n = 0) \\
        dp[n - 1]                            & (n > 0, n \bmod 2 = 1) \\
        dp[\frac{n}{2}] + dp[n - 1]   & (n > 0, n \bmod 2 = 0) \\
    \end{cases}
    ```

### POJ 2385
[:octicons-link-24: Problem][problem-poj-2385]
[:octicons-file-code-24: Code][code-poj-2385]

  - Define state as $`(t, w, r)`$:
    - $`t \coloneqq`$  current minute: $`0, 1, 2, 3, \dots, T`$.
    - $`w \coloneqq`$ number of chances left to walk to another tree: $`W, W-1, \dots, 1, 0`$.
    - $`r \coloneqq`$ tree number: $`1`$ or $`2`$.
    - $`a_t \coloneqq`$ the tree that will drop an apple at minute $`t`$.
    - $`f(t, w, r) \coloneqq`$ maximum number of apples that can be caught from time $`t`$ on condition that the cow is currently under tree $`r`$ and has last $`w`$ chances to walk to another tree.
    - 
      ```math
      \left\{
      \begin{align*}
        & f(T, *, *) = 0  \\
        & f(t, 0, r) = f(t + 1, 0, r) + [a_t = r] \\
        & f(t, w, r) = \max{\{ f(t + 1, w, r) + [a_t = r],  f(t + 1, w - 1, 3 - r) + [a_t \ne r]\}} \\
      \end{align*}
      \right.
      ```

### POJ 3616
[:octicons-link-24: Problem][problem-poj-3616]
[:octicons-file-code-24: Code][code-poj-3616]

  - Sort the intervals by the ending hour.
  - $`dp[i + 1] \coloneqq `$ maximum amount of milk that can be produced in the first $`i`$ intervals.
  - $`A_i \coloneqq `$ starting hour of the $`i`$-th interval.
  - $`B_i \coloneqq `$ ending hour of the $`i`$-th interval.
  - $`W_i \coloneqq `$ efficiency of the $`i`$-th interval.
  - 
    ```math
    dp[i] =
    \begin{cases}
      0 & (i = 0) \\
      dp[k] + W_i & (i > 0, k \text{ is the max ending hour that satisfies } B_k + R \le A_i) \\
    \end{cases}
    ```

### POJ 3280
[:octicons-link-24: Problem][problem-poj-3280]
[:octicons-file-code-24: Code][code-poj-3280]

  - In this problem, adding a character or deleting a character would make the same contribution to generate a palindrome. So we always choose the way with less cost.
  - $`c[s_i] \coloneqq`$ the less cost between adding and deleting the character $`s_i`$.
  - $`dp[i][j] \coloneqq`$ the cost to change the substring $` s_i, s_{i + 1}, \cdots, s_{j-1}, s_j `$ into palindrome.
  - 
    ```math
    dp[i][j] =
    \begin{cases}
      0 & (i \ge j) \\
      dp[i + 1][j - 1] & (i < j \land s_i = s_j) \\
      \min{\{ dp[i + 1][j] + c[s_i], dp[i][j - 1] + c[s_j] \}} & (i < j \land s_i = s_j) \\
    \end{cases}
    ```

### POJ 1742
[:octicons-link-24: Problem][problem-poj-1742]
[:octicons-file-code-24: Code][code-poj-1742]

  - $`dp[i + 1][j] \coloneqq `$ maximum number of coins of value $`A_i`$ left when the exact price paid is $`j`$.
    $`-1`$ if there's no feasible solution.
  - 
    ```math
    dp[i + 1][j] =
    \begin{cases}
      C_i                           & (dp[i][j] \ge 0) \\
      -1                            & (j < A_i \lor dp[i + 1][j - A_i] \le 0) \\
      dp[i + 1][j - A_i] - 1 & (\text{otherwise}) \\
    \end{cases}
    ```

### POJ 3046
[:octicons-link-24: Problem][problem-poj-3046]
[:octicons-file-code-24: Code][code-poj-3046]

  - $`dp[i][j] \coloneqq `$ number of $`j`$-nary sets that can be formed by the first $`i`$ ant families.
  - 
    ```math
    dp[i][j] = \sum_{t = \max{\{0, j - N_i\}}}^{j} {dp[i - 1][t]}
    ```
  - Optimization: Prefix Sum.

### POJ 3181
[:octicons-link-24: Problem][problem-poj-3181]
[:octicons-file-code-24: Code][code-poj-3181]

  - $`dp[i][j] \coloneqq `$ the number of ways to spend $`j`$ dollars to buy from the first $`i`$ tools.
  - 
    ```math
    \begin{align*}
    dp[i][j] =
    & dp[i - 1][j] + dp[i - 1][j - i] + dp[i - 1][j - 2\cdot i] + \dots + \\
    &dp[i - 1][j - \lfloor \frac{j}{i} \rfloor \cdot i]
    \end{align*}
    ```
  - Optimization: Since each item in the sum above is $`i`$ distance apart, a vector is used to record the sums whose elements are $`i`$ distance part.
  - Arbitrary-precision arithmetic.

### POJ 1065
[:octicons-link-24: Problem][problem-poj-1065]
[:octicons-file-code-24: Code][code-poj-1065]

  - Essentially, the result is the minimum number of nondecreasing subsequences. 
  - Use `std::set` to keep the last element of the nondecreasing subsequences.
  - Greedily append new elements $`e`$ to the nondecreasing subsequence whose last element is closest to but not exceeding $`e`$.

### POJ 1631
[:octicons-link-24: Problem][problem-poj-1631]
[:octicons-file-code-24: Code][code-poj-1631]

  - Longest Increasing Subsequence.
  - $` dp[i] \coloneqq `$ the minimum value of the last elements in an increasing subsequence of length $`i + 1`$.

### POJ 3666
[:octicons-link-24: Problem][problem-poj-3666]
[:octicons-file-code-24: Code][code-poj-3666]

  - $`B_i \in \{ A_1, A_2, \dots, A_N \}`$.
  - Assuming that there are $`K`$ distinct numbers $`U_1, U_2, U_3, \dots, U_K`$ in  $` \{ A_1, A_2, \dots, A_N \} `$ where $` U_1 < U_2 < U_3 < \dots < U_K `$, a nondecreasing sequence $` B_1, B_2, B_3, \dots, B_N `$ can be represented as $` U_{t_1}, U_{t_2}, U_{t_3}, \dots, U_{t_N} `$  where $` 1 \le t_1 \le t_2 \le \dots \le t_N \le K `$.
  - $` dp[i][j] \coloneqq `$ the minimum cost to adjust $` A_1, \dots A_i `$ to a new sequence ended in $`U_{j}`$.
  - 
    ```math
    dp[i][j] =
    \begin{cases}
    0                                                                & (i = 0) \\
    \min_{1 \le k \le j}{\{ dp[i - 1][k] + |A_i - U_k | \} }  & (i > 0) \\
    \end{cases}
    ```

### POJ 2392
[:octicons-link-24: Problem][problem-poj-2392]
[:octicons-file-code-24: Code][code-poj-2392]

  - $`dp[i + 1][j] \coloneqq `$ the maximum number of blocks $`i`$ left when building a space elevator of height $`j`$ using blocks from $`0`$ to $`i`$, $`-1`$ if there's no feasible solution.
  - 
    ```math
    dp[i + 1][j] =
    \begin{cases}
      -1                            & (j > a_i) \\
      c_i                           & (dp[i][j] \ge 0) \\
      -1                            & (j < h_i \lor dp[i + 1][j - h_i] \le 0) \\
      dp[i + 1][j - h_i] - 1 & (\text{otherwise}) \\
    \end{cases}
    ```

### POJ 2184
[:octicons-link-24: Problem][problem-poj-2184]
[:octicons-file-code-24: Code][code-poj-2184]

  - 0-1 Knapsack Problem and Hashing: In hash table, the key is sum of "Smartness" and the value is the maximum sum of "Funness".

## 2.4
### POJ 3614
[:octicons-link-24: Problem][problem-poj-3614]
[:octicons-file-code-24: Code][code-poj-3614]

  - Use lotions from small `SPF` to large `SPF`. If there are multiple cows that can be protected by a lotion, we first protect the cows with smaller `maxSPF`.

### POJ 2010
[:octicons-link-24: Problem][problem-poj-2010]
[:octicons-file-code-24: Code][code-poj-2010]

  - Sort the cows by score.
  - For each candidate of the median score, the min sum of financial aids should be $`L + C + R`$:
    - $`L`$ is the min sum of any $`\frac{N}{2}`$ cows's finanial aid before the candidate.
    - $`R`$ is the min sum of any $`\frac{N}{2}`$ cows's finanial aid after the candidate.
    - $`C`$ is the candidate's financial aid.
  - During calculate $`L`$ (or $`R`$) for each candidate of the median score, keep the $`\frac{N}{2}`$ cows of $`L`$ (or $`R`$) in a `std::priority_queue`.

### POJ 2236
[:octicons-link-24: Problem][problem-poj-2236]
[:octicons-file-code-24: Code][code-poj-2236]

  - Naive union-find.

### POJ 1703
[:octicons-link-24: Problem][problem-poj-1703]
[:octicons-file-code-24: Code][code-poj-1703]

  - Union-find and equivalence classes.

### AOJ 2170
[:octicons-link-24: Problem][problem-aoj-2170]
[:octicons-file-code-24: Code][code-aoj-2170]

  - Union-find and path compression.
  - In this problem, after a node is marked, current disjoint sets would be further splitted into a larger number of disjoint sets. So the query/mark operations are kept in a sequence and handled in reverse order, which would convert splitting operations into union operations.

## 2.5
### AOJ 0189
[:octicons-link-24: Problem][problem-aoj-0189]
[:octicons-file-code-24: Code][code-aoj-0189]

  - All-pairs shortest path: the Floyd-Warshall algorithm.
  - CAUTION: The numbers of vertices might not be consecutive numbers.

### POJ 2139
[:octicons-link-24: Problem][problem-poj-2139]
[:octicons-file-code-24: Code][code-poj-2139]

  - All-pairs shortest path: the Floyd-Warshall algorithm.

### POJ 3259
[:octicons-link-24: Problem][problem-poj-3259]
[:octicons-file-code-24: Code][code-poj-3259]

  - Single-source shortest path: the Bellman-Ford algorithm.
  - Negative cycle detection using the Bellman-Ford algorithm.
    - A global source vertex numbered $`0`$ is added to the vertex set.
    - $`N`$ edges, from vertex $`0`$ to vertex $`1, 2, \dots, N`$ are added to the edge set.
    - Vertex $`0`$ is used as the single-source in the Bellman-Ford algorithm.
  - Time complexity analysis:
    - In this problem, the graph contains at most $`V = N = 500`$ vertices and $`E = M * 2 + W = 5200`$ edges.
    - If the Floyd-Warshall algorithm is used to detect negative cycle, the time complexity would be $`\mathcal{O}(V^3)`$. Since $`V^3 \approx 10^8 `$, it is unacceptable.
    - The time complexity of the Bellman-Ford algorithm is $` \mathcal{O}(V \cdot E) `$. Since $` V \cdot E \approx 10^6 `$, it is acceptable.
  - CAUTION: Pay attention to the statement: "Two fields might be connected by more than one path". That's to say, if there are more than one path between two fields, the path with minimum time cost should be taken as the edge.

### POJ 3268
[:octicons-link-24: Problem][problem-poj-3268]
[:octicons-file-code-24: Code][code-poj-3268]

  - Single-source shortest path: the Bellman-Ford algorithm.

### AOJ 2249
[:octicons-link-24: Problem][problem-aoj-2249]
[:octicons-file-code-24: Code][code-aoj-2249]

  - Single-source shortest path: the Bellman-Ford algorithm.
  - Since the final plan must corresponds to a tree rooted by the capital, we just need to keep the cost of the incoming edge to a city. And if two incoming edges both result in the minimum distance, we should choose the one with less cost.

### AOJ 2200
[:octicons-link-24: Problem][problem-aoj-2200]
[:octicons-file-code-24: Code][code-aoj-2200]

  - The Floyd-Warshall algorithm and dynamic programming.
  - $` L[a][b] \coloneqq `$ the shortest travel time from $`a`$ to $`b`$ without using a boat.
  - $` S[a][b] \coloneqq `$ the shortest travel time from $`a`$ to $`b`$ by boat.
  - $` z_0 \to z_1 \to \cdots \to z_{R-1} \coloneqq `$  the order of collection / delivery.
  - $` (x, y) \coloneqq `$ the state that the postal carrier is in the town $`x`$ and the boat is in the town $`y`$.
  - $` dp[i][j] \coloneqq `$ the shortest travel time from $` (z_0, z_0) `$ to $` (z_i, j) `$.
  - 
    ```math
    dp[i][j] =
    \begin{cases}
      0 & (i = 0 \land j = z_0) \\
      \infty & (i = 0 \land j \ne z_0) \\
      dp[i - 1][k] + L[z_{i}][z_{i + 1}] & (i > 0 \land k = j)\\
      \min{ \lbrace dp[i - 1][k] + L[z_{i}][k] + S[k][j] + L[j][z_{i + 1}] \rbrace } & (i > 0 \land k \ne j) \\
    \end{cases}
    ```

### POJ 1258
[:octicons-link-24: Problem][problem-poj-1258]
[:octicons-file-code-24: Code][code-poj-1258]

  - Minimum Spanning Tree.

### POJ 2377
[:octicons-link-24: Problem][problem-poj-2377]
[:octicons-file-code-24: Code][code-poj-2377]

  - A variant of Minimum Spanning Tree: Maximum Spanning Tree.
  - CAUTION: The original graph may not be a connected graph and the result may be a minimum spanning forest.

### AOJ 2224
[:octicons-link-24: Problem][problem-aoj-2224]
[:octicons-file-code-24: Code][code-aoj-2224]

  - The minimum length of edge removed to obtain a maximum spanning tree.

### POJ 2395
[:octicons-link-24: Problem][problem-poj-2395]
[:octicons-file-code-24: Code][code-poj-2395]

  - The maximum edge length in the minimum spanning tree.

## 2.6
### AOJ 0005
[:octicons-link-24: Problem][problem-aoj-0005]
[:octicons-file-code-24: Code][code-aoj-0005]

  - GCD and LCM.

### POJ 2429
[:octicons-link-24: Problem][problem-poj-2429]
[:octicons-file-code-24: Code][code-poj-2429]

  - Miller-Rabin primality test.
  - Integer factorization with Pollard's rho algorithm.
  - DFS. The depth of DFS in this problem is at most 16 since we have the experiential knowledge:
    ```
    2*3*5*7*11*13*17*19*23*29*31*37*41*43*47    = 0x0888 86FF DB34 4692
    2*3*5*7*11*13*17*19*23*29*31*37*41*43*47*53 = 0xC443 F2F8 61D2 9C3A
    ```
  - Some test cases for debugging.
    ```
    21 614889782588491410
    // --> 3577359786 3609557385
    // 614889782588491410 = 2*3*5*7*11*13*17*19*23*29*31*37*41*43*47

    13 6121863882679589928
    // --> 7190755416 11067575779
    // 6121863882679589928 = 2*2*2*3*3*13*71*7682431*11990873

    17 3423517729149215872
    // --> 2806947503 20734196608
    // 3423517729149215872 = 2*2*2*2*2*2*2*17*1433*115223*9528583
    ```

### POJ 1930
[:octicons-link-24: Problem][problem-poj-1930]
[:octicons-file-code-24: Code][code-poj-1930]

  - Converting a repeating decimal to a fraction.
    ```math
    \begin{align*}
    x &= 0.\overline{a_1 a_2 a_3 \cdots a_n} \\
    10^n \cdot x &= a_1 a_2 a_3 \cdots a_n.\overline{a_1 a_2 a_3 \cdots a_n} \\
    (10^n - 1) \cdot x &= a_1 a_2 a_3 \cdots a_n \\
    x &= \frac{a_1 a_2 a_3 \cdots a_n}{10^n - 1} \\
    \end{align*}
    ```
  - In this problem, the input $` 0.d_1 d_2 d_3 \cdots d_n\dots `$ might be interpreted as a repeating decimal whose repetend has $`k`$ digits $`(1 \le k \le n)`$. We need to convert the $`n`$ repeating decimals to fractions and use GCD to get the simplest forms.

### AOJ 0009
[:octicons-link-24: Problem][problem-aoj-0009]
[:octicons-file-code-24: Code][code-aoj-0009]

  - Sieve of Eratosthenes and Prefix Sum.

### POJ 3126
[:octicons-link-24: Problem][problem-poj-3126]
[:octicons-file-code-24: Code][code-poj-3126]

  - Sieve of Eratosthenes and BFS.

### POJ 3421
[:octicons-link-24: Problem][problem-poj-3421]
[:octicons-file-code-24: Code][code-poj-3421]

  - Naive factorization: $` X = p_{1}^{e_1} \cdot p_{2}^{e_2}  \cdots p_{k-1}^{e_{k-1}} \cdot p_{k}^{e_k} `$
  - Maximum length: $` n = e_1 + e_2 + \cdots + e_k `$
  - Number of such X-factors chains:
    $` x = \binom{n}{e_1} \cdot \binom{n - e_1}{e_2} \cdot \binom{n - e_1 - e_2}{e_3} \cdots \binom{n - e_1 - \cdots - e_{k - 1}}{e_k} = \frac{n!}{e_1! e_2! \cdots e_k!} `$
  - Experiential knowledge:
    - $`20! < 2^{63} < 2^{64} < 21!`$

### POJ 3292
[:octicons-link-24: Problem][problem-poj-3292]
[:octicons-file-code-24: Code][code-poj-3292]

  - Sieve of Eratosthenes, Precomputation, Prefix Sum.
  - In this problem, an H-semi-prime number is an H-number which is the product of exact two H-primes. It's worth noting that while enumerating the product of two H-primes, the same H-semi-prime might be enumerated twice, e.g. $` 441 = 9 \times 49 = 21 \times 21 `$.

### POJ 3641
[:octicons-link-24: Problem][problem-poj-3641]
[:octicons-file-code-24: Code][code-poj-3641]

  - Binary exponentiation and primality test.

### POJ 1995
[:octicons-link-24: Problem][problem-poj-1995]
[:octicons-file-code-24: Code][code-poj-1995]

  - Binary exponentiation.

## 3.1
### POJ 3258
[:octicons-link-24: Problem][problem-poj-3258]
[:octicons-file-code-24: Code][code-poj-3258]

  - Binary search: maximizing the minimum value / minimizing the maximum value.
  - The shortest distance between two adjacent rocks
    $` d_{\text{min}} \in [1, L] `$.
    And $` 1 \le L \le 10^9 `$ implies that we should
    apply binary search algorithm to the shortest distance.
  - Hint: In order to make the shortest distance between two adjacent rocks
    $` \ge x `$, how many rocks must be removed at least?
    - $`S \coloneqq`$ a set of rocks that the distances between adjacent rocks
      are all $` \ge x `$.
      Initally, the set $`S`$ only contains the rock at the start.
    - Scan from left to right, add the rock to the set $`S`$
      if the distance from the rock to the rightmost rock in the set $`S`$
      is greater than or equal to $`x`$, otherwise drop the rock.

### POJ 3273
[:octicons-link-24: Problem][problem-poj-3273]
[:octicons-file-code-24: Code][code-poj-3273]

  - Binary search: maximizing the minimum value / minimizing the maximum value.
  - Hint: In order to make the expenses of each "fajomonths"
    smaller than or equal to $`x`$,
    how many "fajomonths" should be arranged at least?

### POJ 3104
[:octicons-link-24: Problem][problem-poj-3104]
[:octicons-file-code-24: Code][code-poj-3104]

  - Binary search: maximizing the minimum value / minimizing the maximum value.
  - Hint: Could the clothes be dried in $`t`$ minutes?
  - CAUTION: On the radiator, the amount of water decreases by $`k`$
    in each minute, not $`k + 1`$.
  - In order to dry all clothes in $`t`$ minutes, the radiator must be used
    for the clothes that contains $`a_i`$ amounts of water, where $`a_i > t`$.
    For such clothes, the minimum time on the radiator should be
    $` \lceil \frac{a_i - t}{k - 1} \rceil `$ minutes.
  - CAUTION: $`\sum_{i} \lceil \frac{a_i - t}{k - 1} \rceil `$
    could be larger than `INT_MAX`.

### POJ 3045
[:octicons-link-24: Problem][problem-poj-3045]
[:octicons-file-code-24: Code][code-poj-3045]

  - Greedy algorithm.
  - Proof:
    - Assume that swapping the $`i`$-th cow and the $`(i+1)`$-th cow
      from the bottom to the top could make the largest risk smaller.
      Then the largest risk must be either the risk of the $`i`$-th cow
      or the risk of the $`(i+1)`$-th cow.
    - Denote the sum of weight on the $`(i+1)`$-th cow by
      $`X`$, i.e. $`X \coloneqq \sum_{k = i + 2}^{N} W_{k}`$.
    - Before swapping, the largest risk is
      ```math
      \max\{ W_{i+1} + X - S_{i}, X - S_{i+1} \}
      ```
    - After swapping, the largest risk is
      ```math
      \max\{ X - S_{i}, W_{i} + X - S_{i+1} \}
      ```
    - Swapping could make the largest risk smaller implies
      ```math
      \max\{ W_{i+1} + X - S_{i}, X - S_{i+1} \} >
      \max\{ X - S_{i}, W_{i} + X - S_{i+1} \}
      ```
    - Add $`S_{i} + S_{i+1} - X`$ to both sides, we have
      ```math
      \max\{ W_{i+1} + S_{i+1}, S_{i} \} > \max\{ S_{i+1}, W_{i} +S_{i} \}
      ```
    - This holds as long as $`W_{i+1} + S_{i+1} > W_{i} +S_{i}`$ holds,
      since $`W_{i+1} + S_{i+1} > S_{i+1}`$ holds
      and $`S_{i} < W_{i} + S_{i}`$ holds.

### POJ 2976
[:octicons-link-24: Problem][problem-poj-2976]
[:octicons-file-code-24: Code][code-poj-2976]

  - Binary search: maximizing / minimizing the average value.
  - Denote the cumulative average by $`x`$ and
    denote the indices of the $`n-k`$ tests by $`S`$:
    ```math
    \begin{align*}
    & \exists S = \{ i_1, i_2, \cdots, i_{n-k}\} \subset \{ 1, 2, \cdots, n \}:
    100 \cdot \frac{\sum_{i \in S}{a_{i}}}{\sum_{i \in S}{b_{i}}} \ge x \\
    & \implies \\
    & \exists S = \{ i_1, i_2, \cdots, i_{n-k}\} \subset \{ 1, 2, \cdots, n \}:
    \sum_{i \in S}{(a_{i} \cdot 100 - b_{i} \cdot x)} \ge 0
    \end{align*}
    ```
  - Such $`S`$ exists as long as the sum of the maximum $`(n - k)`$ values
    of $`(a_{i} \cdot 100 - b_{i} \cdot x)`$ is $` \ge 0 `$.
  - CAUTION: Greedy algorithm does not work for this problem.
    That's to say, the cumulative average of the maximum $`(n-k)`$ values
    of $`\frac{a_i}{b_i}`$ is not the highest cumulative average.
    The sample input gives the indication.
    Drop `1` test in `3` tests: `5/5`, `0/1`, `2/6`.
    The highest cumulative average should be `(5+0)/(5+1)`.

### POJ 3111
[:octicons-link-24: Problem][problem-poj-3111]
[:octicons-file-code-24: Code][code-poj-3111]

  - Binary search: maximizing / minimizing the average value.
  - Use `maxSpecific` and `res[MAX_K + 1]` to keep the result
    since the predicate function might return false in the last iteration.
  - Binary search on real values in the the 1EEE 754 standard:
    ```cpp
    double l_real = 0, r_real = 1E7;
    int64_t l, r;
    memcpy(&l, &l_real, sizeof(double)); // std::bit_cast since C++20.
    memcpy(&r, &r_real, sizeof(double));
    while (l < r) {
      int64_t x = l + (r - l) / 2;
      double x_real;
      memcpy(&x_real, &x, sizeof(double));
      if (pred(x_real)) {
        l = x + 1;
      } else {
        r = x;
      }
    }
    ```

### POJ 3579
[:octicons-link-24: Problem][problem-poj-3579]
[:octicons-file-code-24: Code][code-poj-3579]

  - Binary search: find the $`k`$-th smallest / largest value.
  - $`N \le 10^5`$ and $`\binom{n}{2} \sim 10^{10}`$
    implies `priority_queue` does not work for this problem.
  - Use `scanf` and `printf` instead of `cin` and `cout`.

### POJ 3685
[:octicons-link-24: Problem][problem-poj-3685]
[:octicons-file-code-24: Code][code-poj-3685]

  - Binary search: find the $`k`$-th smallest / largest value.
  - $`N \le 50000`$ and $`M \le N^2`$
    implies `priority_queue` does not work for this problem.
  - For simplicity, the lower bound is initialized to $`-10^5 \cdot N`$
    and the upper bound is initialized to $`3 \cdot N^2 + 10^5 \cdot N`$.
    ```math
    \begin{align*}
    & f(i, j) = i^2 + 10^5 \cdot i + j^2 - 10^5 \cdot j + i \cdot j  \qquad
      (1 \le i \le N, 1 \le j \le N) \\
    & \implies -10^5 \cdot N < f(i, j) < 3 \cdot N^2 + 10^5 \cdot N
    \end{align*}
    ```

### POJ 2010
[:octicons-link-24: Problem][problem-poj-2010]
[:octicons-file-code-24: Code][code-poj-2010]

  - See `priority_queue` solution [here](#poj-2010).

### POJ 3662
[:octicons-link-24: Problem][problem-poj-3662]
[:octicons-file-code-24: Code][code-poj-3662]

  - Binary Search and Dijkstra algorithm.
  - In the given graph, for any path from vertex $`1`$ to vertex $`N`$,
    denote the $`(K+1)`$-th maximum edge length as $`x`$,
    the aim is to find the minimum $`x`$ among all paths.
  - The key to the problem is to convert the graph.
     - $`W(t) \coloneqq (e_1, e_2, \dots, e_t) `$ denotes a walk
      from $`1`$ to $`N`$ which is connected by $t$ edges
      $`e_1, e_2, \dots, e_t`$.
    - The lengths of the $`t`$ edges are sorted in nondescending order:
      $`L_1 \le L_2 \le \cdots \le L_t`$.
    - $`P(x) \coloneqq \exists W(t): t \le K \lor L_{t - K} \le x `$
    - In this problem, $`P(x)`$ indicates the amount of money
      that Farmer John has to pay is less than or equal to $`x`$.
    - Convert the original graph $`G(V, E)`$ into a new graph
      $` G'(V, \{0, 1\}, x) `$:
      $`\forall e \in E: e' = [e > x] \in \{0, 1\}`$.
    - $`P(x) \iff`$
      In $`G'(V, \{0, 1\}, x)`$, the shortest path from $`1`$ to $`N`$
      is less than or equal to $`K`$ .
  - In this problem, $`V \le 10^3`$ and $`E \le 10^4`$.
    - The Dijkstra algorithm: $`\mathcal{O}(E\log{V}) \sim 10^5`$
    - Binary search between `0` and `INT_MAX`: at most $`31`$ times.

### POJ 1759
[:octicons-link-24: Problem][problem-poj-1759]
[:octicons-file-code-24: Code][code-poj-1759]

  - Binary search on real values.
  - $`H_{N}`$ gets larger as $`H_{2}`$ gets larger:
  ```math
  \begin{align*}
    & \phantom{\implies} H_{i} = \frac{1}{2}(H_{i - 1} + H_{i + 1}) - 1 \\
    & \implies H_{i + 1} - H_{i} = H_{i} - H_{i - 1} + 2 \\
    & \implies H_{N} - H_{N - 1} = H_{2} - H_{1} + 2(N - 2) \\
    & \implies H_{N} - H_{1} = (N - 1) (H_{2} - H_{1}) + (N - 1)(N - 2) \\
    & \implies H_{N} = (N - 1) H_{2} - (N - 2) H_{1} + (N - 1)(N - 2)
  \end{align*}
  ```
  - To find the smallest $`H_{N}`$, we use binary search to
    find the smallest $`H_{2}`$ in $`[0, H_{1}]`$ that makes
    $`H_i \ge 0`$ for $`1 \le i \le N`$.

### POJ 3484
[:octicons-link-24: Problem][problem-poj-3484]
[:octicons-file-code-24: Code][code-poj-3484]

  - Binary Search.
    - If the number of elements in all sequences is even,
      there is no corruption in the data set.
    - If the number of elements in all sequences is odd,
      the only one element that occurs odd number of times should be
      the smallest element in $`[x_{\text{min}}, y_{\text{max}}]`$
      which has a even number of greater elements in all sequences.

## 3.2
### POJ 2566
### POJ 2739
### POJ 2100

### POJ 3185
### POJ 1222

### POJ 2674

### POJ 3977
### POJ 2549

### AOJ 0531

## 3.3
### POJ 1990
### POJ 3109
### POJ 2155
### POJ 2886

### POJ 3264
### POJ 3368
### POJ 3470
### POJ 1201
### UVa 11990

## 3.4
### POJ 2441
### POJ 3254
### POJ 2836
### POJ 1795
### POJ 3411

### POJ 3420
### POJ 3735

### POJ 3171

## 3.5
### POJ 3713
### POJ 2987
### POJ 2914
### POJ 3155

### POJ 1274
### POJ 2112
### POJ 1486
### POJ 1466
### POJ 3692
### POJ 2724
### POJ 2226
### AOJ 2251

### POJ 3068
### POJ 2195
### POJ 3422
### AOJ 2266
### AOJ 2230

## 3.6
### POJ 1981
### POJ 1418
### AOJ 2201

### POJ 3168
### POJ 3293
### POJ 2482

### POJ 1113
### POJ 1912
### POJ 3608
### POJ 2079
### POJ 3246
### POJ 3689

### AOJ 2256
### AOJ 2215

## 4.1
### POJ 1150
### POJ 1284
### POJ 2115
### POJ 3708
### POJ 2720
### GCJ Japan 2011 Finals B

### POJ 2345
### POJ 3532
### POJ 3526

### POJ 2407
### POJ 1286
### POJ 2409
### AOJ 2164
### AOJ 2214

## 4.2
### POJ 1082
### POJ 2068
### POJ 3688
### POJ 1740

### POJ 2975
### POJ 3537
### Codeforces 138D
### POJ 2315

## 4.3
### POJ 3180
### POJ 1236

### POJ 3678
### POJ 2723
### POJ 2749

### POJ 1986
### POJ 3728

## 4.4
### POJ 3250
### POJ 2082
### POJ 3494

### POJ 2823
### POJ 3260
### POJ 1180
### AOJ 1070

## 4.5
### POJ 1011
### POJ 2046
### POJ 3134

### POJ 3523
### POJ 2032
### UVa 10181

## 4.6
### POJ 1854

### GCJ 2009 World Finals B
### Codeforces 97B

### POJ 2114
### UVa 12161
### SPOJ QTREE5

## 4.7
### AOJ 2212
### Codeforces 86C

### Codeforces 25E
### AOJ 1312

### POJ 1509
### POJ 3415
### POJ 3729
### AOJ 2292
### Codeforces 123D
