
# Exercises in *Programming Contest Challenge Book, 2e* 

> 挑战程序设计竞赛（第2版）练习题

## 2.1
- [POJ 1979](http://poj.org/problem?id=1979)
  - Naive DFS.
- [AOJ 0118](https://onlinejudge.u-aizu.ac.jp/problems/0118)
  - Naive DFS from every unvisited vertex of the graph.
- [AOJ 0033](https://onlinejudge.u-aizu.ac.jp/problems/0033)
  - Naive DFS works since $n = 10$. There are at most $2^n = 1024$ possiblities.
  - Greedy algorithm also works. Keep the two uppermost values in both cylinders: $l$ and $r$, where $(l < r)$. For a newly-dropped ball of value $e$:
    - If $e < l < r$, it can be placed on neither side.
    - If $l < e < r$, it can only be placed on $l$.
    - If $l < r < e$, it can be placed on either $l$ or $r$. But it should be placed on $r$ since placing $e$ on $l$ is never better than placing $e$ on $r$. 
- [POJ 3009](http://poj.org/problem?id=3009)
  - DFS and pruning.
- [AOJ 0558](https://onlinejudge.u-aizu.ac.jp/problems/0558)
  - BFS: The mouse must eat cheeses in the order of $1, 2, \dots, N$.
- [POJ 3669](http://poj.org/problem?id=3669)
  - BFS:
    - The target of search is to find a safe location which is not destroyed by the meteors. Use BFS and keep all reachable points in the queue until the target is reached.
    - Consider a point $(x_i, y_i)$ that is destoryed by a meteor at $t_i$ at the first time. The accessible time of $(x_i, y_i)$ is $[0, t_i)$. Use `G[x][y]` to represent the upper bound of accessible time for point $(x_i, y_i)$, which is $t_{\text{min}}$ for all meteors that destory $(x_i, y_i)$. `G[x][y]` should be considered when we traverse through the neighbor points.
    - $0 \le x_i, y_i \le 300$ implies `G[302][302]` is enough. All points $(301, *)$ or $(*, 301)$ must be safe.
    - The solution, if possible, should be in the range $[0, 1000]$ since $0 \le t_i \le 1000$.
- [AOJ 0121](https://onlinejudge.u-aizu.ac.jp/problems/0121)
  - BFS, bit manipulation, and precomputation: 
    - The result can be precomputed since $8! = 40320$ is small.
- [POJ 2718](http://poj.org/problem?id=2718)
  - Exhausive search: `std::next_permutation`
- [POJ 3187](http://poj.org/problem?id=3187)
  - Binomial expansion, Pascal's triangle, and Pascal's rule ${n \choose k} = {n - 1 \choose k} + { n - 1 \choose k - 1} $
- [POJ 3050](http://poj.org/problem?id=3050)
  - We use DFS directly because $5 \times 5 \times 4^5 = 25600 < 10^{5}$
- [AOJ 0525](https://onlinejudge.u-aizu.ac.jp/problems/0525)
  - State compression: $2^{R + C} \to  2^R \cdot C \quad (1 \le R \le 10, 1 \le C \le 10^4)$.
  - Bit manipulation: `__built_in_popcount` in GCC or `std::popcount` since C++20.

## 2.2
- [POJ 2376](http://poj.org/problem?id=2376)
  - The unassigned shift $[L, T]$ can be assigned to the cow $i$ that is available on the interval $[L_i, R_i]$ as long as $L_i \le L$. And among all feasible choices, we choose the one with maximum $R_i$, which makes the remaining unassigned shift becomes $[R_i + 1, T]$.
- [**POJ 1328**](http://poj.org/problem?id=1328)
  - Each island corresponds to an interval $[a_i, b_i]$ on the $x$-axis, on which we could install a radar to cover the island.
  - Sort the intervals $[a_i, b_i]$ in nondescreasing order: $[a_i, b_i] < [a_j, b_j] \iff ((a_i < b_j) \lor (a_i = a_j \land b_i < b_j))$. 
  - For $i = 1, 2, \dots, N$, make the current radar cover islands as many as possible.
- [POJ 3190](http://poj.org/problem?id=3190)
  - Sort the intervals $[a_i, b_i]$ in nondescreasing order: $[a_i, b_i] < [a_j, b_j] \iff a_i < b_j$. 
  - For the cow with interval $[a_i, b_i]$:
    - If none of the stall is available for it, add a new stall.
    - Else, for all available stalls, choose any one of them. We choose the one that is available as early as possible.
- [POJ 2393](http://poj.org/problem?id=2393)
  - The cost chosen in the $n$-th week should be the minimum cost from week $1$ to week $n$, which is:
  $$\min_{1 \le i \le n}{\{ c_i + s \cdot (n - i)\}} = \min_{1 \le i \le n}{\{ c_i - s \cdot i\}} + s \cdot n$$
  - CAUTION: Since $N \cdot C \cdot Y = 10^{4} \cdot 5000 \cdot 10^4 = 5 \cdot 10^{12} < 2^{40}$,`long long` should be used.
- [POJ 1017](http://poj.org/problem?id=1017)
  - Greedy algorithm: Deliver packets in decreasing order.
    - Deliver the packet of $6 \times 6$, $5 \times 5$, $4 \times 4$, $3 \times 3$ and remember the space left for $2 \times 2$ and $1 \times 1$.
    - Deliver $2 \times 2$: use the space left previously for $2 \times 2$ as much as possible and then transform the unused space for $2 \times 2$ into $1 \times 1$.
    - Deliver $1 \times 1$: use space left previously for $1 \times 1$ as much as possible.
- [**POJ 3040**](http://poj.org/problem?id=3040)
  - To pay at least $C$ cents, choose coins in two steps:
    - Choose coins from large to small to pay some cents that is close to but not exceeding $C$.
    - Choose coins from small to large to pay the remaining cents.
- [POJ 1862](http://poj.org/problem?id=1862)
  - The result is $ 2^{N-1} \cdot m_1^{0.5^{N-1}} \cdot m_2^{0.5^{N-1}} \cdot m_3^{0.5^{N-2}} \cdots  m_k^{0.5^{N+1-k}} \cdots m_{N-1}^{0.5^2} \cdot m_N^{0.5} $,
  which is minimized when $m_1 \ge m_2 \ge m_3 \ge \cdots \ge m_{N-1} \ge m_N$.
  - Proof: Assume $1 < i < j$ and $m_i \ge m_j > 0$, exchange the $i$-th and $j$-th element make the result smaller since
    $$ \frac{m_i^{0.5^{N+1-i}} \cdot m_j^{0.5^{N+1-j}}}{m_j^{0.5^{N+1-i}} \cdot m_i^{0.5^{N+1-j}}} = 
    (\frac{m_i}{m_j})^{0.5^{j - i}} \ge 1
    $$
- [POJ 3262](http://poj.org/problem?id=3262)
  - Intuition: Transport the cows with larger $\frac{D}{T}$ as soon as possible, since they eat faster and the time to transport them is shorter.
  - Proof: The difference of the flower losses introduced by exchanging the $i$-th and the $(i+1)$-th is $T_{i + 1} \cdot D_{i} \to T_i \cdot D_{i + 1}$. That's to say, exchanging any consecutive pair that satisfies $T_{i + 1} \cdot D_{i} > T_i \cdot D_{i + 1}$  can generate less flower losses.

## 2.3
- POJ 3176
- POJ 2229
- POJ 2385
- POJ 3616
- POJ 3280

- POJ 1742
- POJ 3046
- POJ 3181

- POJ 1065
- POJ 1631
- POJ 3666
- POJ 2392
- POJ 2184

## 2.4
- POJ 3614
- POJ 2010

- POJ 2236
- POJ 1703
- POJ 2170

## 2.5
- AOJ 0189
- POJ 2139
- POJ 3259
- POJ 3268
- AOJ 2249
- AOJ 2200

- POJ 1258
- POJ 2377
- AOJ 2224
- POJ 2395

## 2.6
- AOJ 0005
- POJ 2429
- POJ 1930

- AOJ 0009
- POJ 3126
- POJ 3421
- POJ 3292

- POJ 3641
- POJ 1995

## 3.1
- POJ 3258
- POJ 3273
- POJ 3104
- POJ 3045

- POJ 2976
- POJ 3111

- POJ 3579
- POJ 3685

- POJ 2010
- POJ 3662

- POJ 1759
- POJ 3484

## 3.2
- POJ 2566
- POJ 2739
- POJ 2100

- POJ 3185
- POJ 1222

- POJ 2674

- POJ 3977
- POJ 2549

- AOJ 0531

## 3.3
- POJ 1990
- POJ 3109
- POJ 2155
- POJ 2886

- POJ 3264
- POJ 3368
- POJ 3470
- POJ 1201
- UVa 11990

## 3.4
- POJ 2441
- POJ 3254
- POJ 2836
- POJ 1795
- POJ 3411

- POJ 3420
- POJ 3735

- POJ 3171

## 3.5
- POJ 3713
- POJ 2987
- POJ 2914
- POJ 3155

- POJ 1274
- POJ 2112
- POJ 1486
- POJ 1466
- POJ 3692
- POJ 2724
- POJ 2226
- AOJ 2251

- POJ 3068
- POJ 2195
- POJ 3422
- AOJ 2266
- AOJ 2230

## 3.6
- POJ 1981
- POJ 1418
- AOJ 2201

- POJ 3168
- POJ 3293
- POJ 2482

- POJ 1113
- POJ 1912
- POJ 3608
- POJ 2079
- POJ 3246
- POJ 3689

- AOJ 2256
- AOJ 2215

## 4.1
- POJ 1150
- POJ 1284
- POJ 2115
- POJ 3708
- POJ 2720
- GCJ Japan 2011 Finals B

- POJ 2345
- POJ 3532
- POJ 3526

- POJ 2407
- POJ 1286
- POJ 2409
- AOJ 2164
- AOJ 2214

## 4.2
- POJ 1082
- POJ 2068
- POJ 3688
- POJ 1740

- POJ 2975
- POJ 3537
- Codeforces 138D
- POJ 2315

## 4.3
- POJ 3180
- POJ 1236

- POJ 3678
- POJ 2723
- POJ 2749

- POJ 1986
- POJ 3728

## 4.4
- POJ 3250
- POJ 2082
- POJ 3494

- POJ 2823
- POJ 3260
- POJ 1180
- AOJ 1070

## 4.5
- POJ 1011
- POJ 2046
- POJ 3134

- POJ 3523
- POJ 2032
- UVa 10181

## 4.6
- POJ 1854

- GCJ 2009 World Finals B
- Codeforces 97B

- POJ 2114
- UVa 12161
- SPOJ QTREE5

## 4.7
- AOJ 2212
- Codeforces 86C

- Codeforces 25E
- AOJ 1312

- POJ 1509
- POJ 3415
- POJ 3729
- AOJ 2292
- Codeforces 123D