
# Exercises in *Programming Contest Challenge Book, 2e* 

> 挑战程序设计竞赛（第2版）练习题

## 2.1
### [POJ 1979](http://poj.org/problem?id=1979)
  - Naive DFS.

### [AOJ 0118](https://onlinejudge.u-aizu.ac.jp/problems/0118)
  - Naive DFS from every unvisited vertex of the graph.

### [AOJ 0033](https://onlinejudge.u-aizu.ac.jp/problems/0033)
  - Naive DFS works since $`n = 10`$. There are at most $`2^n = 1024`$ possiblities.
  - Greedy algorithm also works. Keep the two uppermost values in both cylinders: $`l`$ and $`r`$, where $`(l < r)`$. For a newly-dropped ball of value $`e`$:
    - If $`e < l < r`$, it can be placed on neither side.
    - If $`l < e < r`$, it can only be placed on $`l`$.
    - If $`l < r < e`$, it can be placed on either $`l`$ or $`r`$. But it should be placed on $`r`$ since placing $`e`$ on $`l`$ is never better than placing $`e`$ on $`r`$. 

### [POJ 3009](http://poj.org/problem?id=3009)
  - DFS and pruning.

### [AOJ 0558](https://onlinejudge.u-aizu.ac.jp/problems/0558)
  - BFS: The mouse must eat cheeses in the order of $`1, 2, \dots, N`$.

### [POJ 3669](http://poj.org/problem?id=3669)
  - BFS:
    - The target of search is to find a safe location which is not destroyed by the meteors. Use BFS and keep all reachable points in the queue until the target is reached.
    - Consider a point $`(x_i, y_i)`$ that is destoryed by a meteor at $`t_i`$ at the first time. The accessible time of $`(x_i, y_i)`$ is $`[0, t_i)`$. Use `G[x][y]` to represent the upper bound of accessible time for point $`(x_i, y_i)`$, which is $`t_{\text{min}}`$ for all meteors that destory $`(x_i, y_i)`$. `G[x][y]` should be considered when we traverse through the neighbor points.
    - $`0 \le x_i, y_i \le 300`$ implies `G[302][302]` is enough. All points $`(301, *)`$ or $`(*, 301)`$ must be safe.
    - The solution, if possible, should be in the range $`[0, 1000]`$ since $`0 \le t_i \le 1000`$.

### [AOJ 0121](https://onlinejudge.u-aizu.ac.jp/problems/0121)
  - BFS, bit manipulation, and precomputation: 
    - The result can be precomputed since $`8! = 40320`$ is small.

### [POJ 2718](http://poj.org/problem?id=2718)
  - Exhausive search: `std::next_permutation`

### [POJ 3187](http://poj.org/problem?id=3187)
  - Binomial expansion, Pascal's triangle, and Pascal's rule $`{n \choose k} = {n - 1 \choose k} + { n - 1 \choose k - 1} `$

### [POJ 3050](http://poj.org/problem?id=3050)
  - We use DFS directly because $`5 \times 5 \times 4^5 = 25600 < 10^{5}`$

### [AOJ 0525](https://onlinejudge.u-aizu.ac.jp/problems/0525)
  - State compression: $`2^{R + C} \to  2^R \cdot C \quad (1 \le R \le 10, 1 \le C \le 10^4)`$.
  - Bit manipulation: `__built_in_popcount` in GCC or `std::popcount` since C++20.

## 2.2
### [POJ 2376](http://poj.org/problem?id=2376)
  - The unassigned shift $`[L, T]`$ can be assigned to the cow $`i`$ that is available on the interval $`[L_i, R_i]`$ as long as $`L_i \le L`$. And among all feasible choices, we choose the one with maximum $`R_i`$, which makes the remaining unassigned shift becomes $`[R_i + 1, T]`$.

### [**POJ 1328**](http://poj.org/problem?id=1328)
  - Each island corresponds to an interval $`[a_i, b_i]`$ on the $`x`$-axis, on which we could install a radar to cover the island.
  - Sort the intervals $`[a_i, b_i]`$ in nondescreasing order: $`[a_i, b_i] < [a_j, b_j] \iff ((a_i < b_j) \lor (a_i = a_j \land b_i < b_j))`$. 
  - For $`i = 1, 2, \dots, N`$, make the current radar cover islands as many as possible.

### [POJ 3190](http://poj.org/problem?id=3190)
  - Sort the intervals $`[a_i, b_i]`$ in nondescreasing order: $`[a_i, b_i] < [a_j, b_j] \iff a_i < b_j`$. 
  - For the cow with interval $`[a_i, b_i]`$:
    - If none of the stall is available for it, add a new stall.
    - Else, for all available stalls, choose any one of them. We choose the one that is available as early as possible.

### [POJ 2393](http://poj.org/problem?id=2393)
  - The cost chosen in the $`n`$-th week should be the minimum cost from week $`1`$ to week $`n`$, which is:
  ```math
  \min_{1 \le i \le n}{ \lbrace c_i + s \cdot (n - i) \rbrace } = \min_{1 \le i \le n}{\lbrace c_i - s \cdot i \rbrace}  + s \cdot n
  ```
  - CAUTION: Since $`N \cdot C \cdot Y = 10^{4} \cdot 5000 \cdot 10^4 = 5 \cdot 10^{12} < 2^{40}`$,`long long` should be used.

### [POJ 1017](http://poj.org/problem?id=1017)
  - Greedy algorithm: Deliver packets in decreasing order.
    - Deliver the packet of $`6 \times 6`$, $`5 \times 5`$, $`4 \times 4`$, $`3 \times 3`$ and remember the space left for $`2 \times 2`$ and $`1 \times 1`$.
    - Deliver $`2 \times 2`$: use the space left previously for $`2 \times 2`$ as much as possible and then transform the unused space for $`2 \times 2`$ into $`1 \times 1`$.
    - Deliver $`1 \times 1`$: use space left previously for $`1 \times 1`$ as much as possible.

### [**POJ 3040**](http://poj.org/problem?id=3040)
  - To pay at least $`C`$ cents, choose coins in two steps:
    - Choose coins from large to small to pay some cents that is close to but not exceeding $`C`$.
    - Choose coins from small to large to pay the remaining cents.

### [POJ 1862](http://poj.org/problem?id=1862)
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


### [POJ 3262](http://poj.org/problem?id=3262)
  - Intuition: Transport the cows with larger $`\frac{D}{T}`$ as soon as possible, since they eat faster and the time to transport them is shorter.
  - Proof: The difference of the flower losses introduced by exchanging the $`i`$-th and the $`(i+1)`$-th is $`T_{i + 1} \cdot D_{i} \to T_i \cdot D_{i + 1}`$. That's to say, exchanging any consecutive pair that satisfies $`T_{i + 1} \cdot D_{i} > T_i \cdot D_{i + 1}`$  can generate less flower losses.

## 2.3
### [POJ 3176](http://poj.org/problem?id=3176)
  - 
    ```math
    dp[i][j] =
    \begin{cases}
    \max \lbrace dp[i - 1][j - 1], dp[i - 1][j] \rbrace   + \text{a}[i][j] & (1 \le j \le i \le N) \\
    0 & (\text{otherwise})
    \end{cases}
    ```

### [POJ 2229](http://poj.org/problem?id=2229)
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

### [POJ 2385](http://poj.org/problem?id=2385)
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

### [POJ 3616](http://poj.org/problem?id=3616)
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

### [POJ 3280](http://poj.org/problem?id=3280)
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

### [POJ 1742](http://poj.org/problem?id=1742)
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

### [POJ 3046](http://poj.org/problem?id=3046)
  - $`dp[i][j] \coloneqq `$ number of $`j`$-nary sets that can be formed by the first $`i`$ ant families.
  - 
    ```math
    dp[i][j] = \sum_{t = \max{\{0, j - N_i\}}}^{j} {dp[i - 1][t]}
    ```
  - Optimization: Prefix Sum.

### [POJ 3181](http://poj.org/problem?id=3181)
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

### [POJ 1065](http://poj.org/problem?id=1065)
  - Essentially, the result is the minimum number of nondecreasing subsequences. 
  - Use `std::set` to keep the last element of the nondecreasing subsequences.
  - Greedily append new elements $`e`$ to the nondecreasing subsequence whose last element is closest to but not exceeding $`e`$.

### [POJ 1631](http://poj.org/problem?id=1631)
  - Longest Increasing Subsequence.
  - $` dp[i] \coloneqq `$ the minimum value of the last elements in an increasing subsequence of length $`i + 1`$.

### [POJ 3666](http://poj.org/problem?id=3666)
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

### [POJ 2392](http://poj.org/problem?id=2392)
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

### [POJ 2184](http://poj.org/problem?id=2184)
  - 0-1 Knapsack Problem and Hashing: In hash table, the key is sum of "Smartness" and the value is the maximum sum of "Funness".

## 2.4
### [POJ 3614](http://poj.org/problem?id=3614)
  - Use lotions from small `SPF` to large `SPF`. If there are multiple cows that can be protected by a lotion, we first protect the cows with smaller `maxSPF`.

### [POJ 2010](http://poj.org/problem?id=2010)
  - Sort the cows by score.
  - For each candidate of the median score, the min sum of financial aids should be $`L + C + R`$:
    - $`L`$ is the min sum of any $`\frac{N}{2}`$ cows's finanial aid before the candidate.
    - $`R`$ is the min sum of any $`\frac{N}{2}`$ cows's finanial aid after the candidate.
    - $`C`$ is the candidate's financial aid.
  - During calculate $`L`$ (or $`R`$) for each candidate of the median score, keep the $`\frac{N}{2}`$ cows of $`L`$ (or $`R`$) in a `std::priority_queue`.

### [POJ 2236](http://poj.org/problem?id=2236)
  - Naive union-find.
### [POJ 1703](http://poj.org/problem?id=1703)
  - Union-find and equivalence classes.
### [AOJ 2170](https://onlinejudge.u-aizu.ac.jp/problems/2170)
  - Union-find and path compression.
  - In this problem, after a node is marked, current disjoint sets would be further splitted into a larger number of disjoint sets. So the query/mark operations are kept in a sequence and handled in reverse order, which would convert splitting operations into union operations.

## 2.5
### [AOJ 0189](https://onlinejudge.u-aizu.ac.jp/problems/0189)
  - All-pairs shortest path: the Floyd-Warshall algorithm.
  - CAUTION: The numbers of vertices might not be consecutive numbers.

### [POJ 2139](http://poj.org/problem?id=2139)
  - All-pairs shortest path: the Floyd-Warshall algorithm.

### [POJ 3259](http://poj.org/problem?id=3259)
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
### [POJ 3268](http://poj.org/problem?id=3268)
  - Single-source shortest path: the Bellman-Ford algorithm.

### [AOJ 2249](https://onlinejudge.u-aizu.ac.jp/problems/2249)
  - Single-source shortest path: the Bellman-Ford algorithm.
  - Since the final plan must corresponds to a tree rooted by the capital, we just need to keep the cost of the incoming edge to a city. And if two incoming edges both result in the minimum distance, we should choose the one with less cost.

### [AOJ 2200](https://onlinejudge.u-aizu.ac.jp/problems/2200)
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

### [POJ 1258](http://poj.org/problem?id=1258)
  - Minimum Spanning Tree.

### [POJ 2377](http://poj.org/problem?id=2377)
  - A variant of Minimum Spanning Tree: Maximum Spanning Tree.
  - CAUTION: The original graph may not be a connected graph and the result may be a minimum spanning forest.

### [AOJ 2224](https://onlinejudge.u-aizu.ac.jp/problems/2224)
  - The minimum length of edge removed to obtain a maximum spanning tree.

### [POJ 2395](http://poj.org/problem?id=2395)
  - The maximum edge length in the minimum spanning tree.

## 2.6
### AOJ 0005
### POJ 2429
### POJ 1930

### AOJ 0009
### POJ 3126
### POJ 3421
### POJ 3292

### POJ 3641
### POJ 1995

## 3.1
### POJ 3258
### POJ 3273
### POJ 3104
### POJ 3045

### POJ 2976
### POJ 3111

### POJ 3579
### POJ 3685

### POJ 2010
### POJ 3662

### POJ 1759
### POJ 3484

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