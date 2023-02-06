1. [fibonacci series](#fib)
2. bionomial
3. 0/1 Knapsack
4. making change
5. matrix chain order
6. largest common subsequence
7. string edit problem
8. assembly line schedule (multi stage graph)
9. maximum continuous sub array
10. bellman ford
11. floyed warshell algorithm
12. tarjans algo
13. kosaraju algo
14. dfs and bfs

## fibonacci series

- algorithm
```algorithm
    dp[n+1]
    dp[0]=0
    dp[1]=1
    for i=2 to n
        dp[i] = dp[i-1]+dp[i-2]
    
    return dp[n]
```

## binomial coefficient

<sup>n</sup>C<sub>k</sub> = <sup>n-1</sup>C<sub>k-1</sub> + <sup>n-1</sup>C<sub>k</sub> 

- algorithm

```cpp
int dp[n + 1][k + 1] = {0};
int i, j;
for (i = 0; i <= n; i++){
    for (j = 0; j <= min(i, k); j++){
        if (j == 0 || j == i)
            dp[i][j] = 1;
        else
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
    }
}
```

## 0/1 KnapSack

- algorithm

```

```