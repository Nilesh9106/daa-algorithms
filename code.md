1. [fibonacci series](#fibonacci-series)
2. [bionomial](#binomial-coefficient)
3. [0/1 Knapsack](#0-1-KnapSack)
4. [making change](#making-change)
5. [matrix chain order](#matrix-chain-problem)
6. [largest common subsequence](#lcs)
7. [string edit problem](#string-edit-distance)
8. [assembly line schedule (multi stage graph)](#assembly-line-schedule-multi-stage-graph)
9. [maximum continuous sub array](#max-sub-array)
10. [bellman ford](#bellman-ford)
11. [floyed warshell algorithm](#floyed-warshell)
12. [tarjans algo](#tarjans-algorithm)
13. [kosaraju algo](#kosaraju-algorithm)


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

## 0-1 KnapSack

- algorithm

```
n = number of items
c = capacity
w = weight of items
p = price of items

dp[n+1][c+1]

for(i=0 to n)
    dp[i][0]=0
for(i=0 to c)
    d[0][j]=0
for(i=1 to n)
    for(j=1 to c)
        if(j<w[i])
            dp[i][j]=dp[i-1][j]
        else
            dp[i][j]=max(dp[i-1][j],p[i] + dp[i-1][j-w[i]] )
```

## making change

- algorithm

```
n = number of coin
c = amount
coins[i] = value of coin i

dp[n+1][c+1]

for(i=0 to n)
    dp[i][0]=0

for(i=1 to n)
    for(j=1 to c)
        if(j<coins[i])
            if(i==1)
                dp[i][j]=-1
            else
                dp[i][j]=sp[i-1][j]
        else
            if(i==1)
                dp[i][j] = 1+dp[i][j-coins[i]]
            else
                dp[i][j] = min(dp[i-1][j] , 1 + dp[i][j-coins[i]])


```

## matrix chain Problem

- algorithm

```
n = number of matrix
p = dimension of all matrix

dp[n+1][n+1]
cut[n+1][n+1]


for(i=0 to n-1)
    dp[i][i]=0

for(l=2 to n)
    for(i=1 to n-l+1)
        j = i+l-1
        dp[i][j] = infinite
        for(k=i to j-1)
            q = dp[i][k]+dp[k+1][j] + p[i-1]*p[k]*p[j]
            if(q<dp[i][j])
                dp[i][j]=q
                cut[i][j]=k
```

- for getting final matrix
```
get_pair(k,i,j)
    if(i==j)
        print(Ai)
    else
        print("(")
        get_pair(k, i , k[i][j])
        get_pair(k, k[i][j] + 1 ,j)
        print(")")
```

## lcs
- algorithm

```
x = string of length m
y = string of length n

dp[m+1][n+1]
dir[m+1][n+1]

for(i=0 to m)
    dp[i][0]=0
for(j=0 to n)
    dp[0][j]=0

for(i=1 to m)
    for(j=1 to n)
        if(x[i-1] == y[j-1])
            dp[i][j] = dp[i-1][j-1] + 1
            dir[i][j] = 'D'
        else if(dp[i-1][j] >= dp[i][j-1])
            dp[i][j] = dp[i-1][j]
            dir[i][j] = 'U'
        else
            dp[i][j] = dp[i][j-1]
            dir[i][j] = 'L'
```
- for getting common string

```
i=m,j=n

while(i>0 and j>0)
    if(dir[i][j]=='D')
        print(x[i])
        i--
        j--
    else if(dir[i][j]=='U')
        i--
    else
        j--
```

## String edit distance

- algorithm
```
x = string of length m
y = string of length n

dp[m+1][n+1]

for(i=0 to m)
    dp[i][0]=i
for(i=0 to n)
    dp[0][i]=i

for(i=1 to m)
    for(j=1 to n)
        dp[i][j] = min(dp[i-1][j]+1 , dp[i][j-1]+1 , dp[i-1][j-1] + x[i]==y[i]?0:2)
```

## assembly line schedule (multi stage graph)

- algorithm
```
e1 = starting cost of line 1
e2 = staring cost of line 2
x1 = ending cost of line 1
x2 = ending cost of line 2
T = cost for transfer
A = cost of station
L = Directions
dp[i][j] = cost for going to ith line jth stage
n = number of stages

dp[1][1] = e1 +A[1][1]
d[2][1] = e2 + A[2][1]

for(i=2 to n)
    if(dp[1][i-1] + A[1][i] < dp[2][i-1] + A[1][i] + T[2][i-1])
        dp[1][i] = dp[1][i-1] + A[1][i]
        L[1][i] = 1
    else
        dp[1][i] = dp[2][i-1] + A[1][i] +T[2][i-1]
        L[1][i] = 2
    
    if(dp[2][i-1] + A[2][i] < dp[1][i-1] + A[2][i] + T[1][i-1])
        dp[2][i] = dp[2][i-1] + A[2][i]
        L[2][i] = 2
    else
        dp[2][i] = dp[1][i-1] + A[2][i] +T[1][i-1]
        L[2][i] = 1

if(dp[1][n] + x1 < d[2][n]+x2)
    final = dp[1][n]+x1
    final_l = 1
else
    final = dp[2][n]+x2
    final_l = 2
```

- for getting path of stations
```
i=final_l
j=n

while(j>0)
    print(L[i][j])
    i = L[i][j]
    j--
```

## max sub array

- algorithm
```
a = array of length n
maxi = maximum sum of sub array

dp[n]

dp[0] = a[0]
maxi = a[0]

for(i=1 to n-1)
    dp[i] = max(a[i],dp[i-1]+a[i])
    maxi = max(maxi,dp[i])

return maxi
```

## bellman ford

- algorithm
```
p = store parent of all nodes
d = store distance of source to all nodes
s = source
v =number of vertices

for every node i in graph
    i.d = infinite
    i.p = -1

s.d = 0

for(i=1 to v - 1)
    for every edge (u,v) of graph
        if(v.d > u.d + w[u][v])
            v.d = u.d + w[i][j]
            v.p = u

for every edge (u,v) of graph
    if(v.d > u.d + w[u][v])
        print(negative edge found)
        return
```

## floyed warshell

-algorithm
```
cost[i][j] = cost of edge i to j (if no edge then value will be infinite)
v = number of vertices


for(i=1 to v)
    for(j=1 to v)
        a[i][j]=cost[i][j]
    a[i][i]=0

for(k=1 to v)
    for(i=1 to v)
        for(j=1 to v)
            a[i][j] = min(a[i][j],a[i][k] + a[k][j])
```

## tarjans algorithm

- algorithm
```
art(u,v)
    d[u]=num
    low[u]=num
    num++

    for every adj w of u
        if(d[w] == 0)
            art(w,u)
            low[u] = min(low[u],low[w])
        else if(w != v)
            low[u]=min(low[u],d[w])

art(1,-1)
for every edge (u,v)
    if(d[v] <= low[u])
        u is A.P
```

## kosaraju algorithm

```
function Kosaraju(G)
    stack S // empty stack
    visited = [false, ..., false] // array of booleans, initially false for each vertex
    for each vertex v in G do
        if not visited[v] then
            DFS1(G, v, visited, S) // populate the stack with the order of finishing times
        end if
    end for

    transposeG = Transpose(G) // generate the transpose of the graph

    visited = [false, ..., false] // reset visited array

    components = [] // empty array of components

    while not S.isEmpty() do
        v = S.pop() // get the next vertex in the order of finishing times
        if not visited[v] then
            component = [] // empty array for the new strongly connected component
            DFS2(transposeG, v, visited, component) // traverse the transpose from v to get the component
            components.append(component) // add the component to the list of components
        end if
    end while

    return components
end 

function DFS1(G, v, visited, S)
    visited[v] = true
    for each vertex u adjacent to v do
        if not visited[u] then
            DFS1(G, u, visited, S)
        end if
    end for
    S.push(v) // add v to the stack after visiting all of its neighbors
end 

function DFS2(G, v, visited, component)
    visited[v] = true
    component.append(v) // add v to the current component
    for each vertex u adjacent to v in G do
        if not visited[u] then
            DFS2(G, u, visited, component)
        end if
    end for
end 

function Transpose(G)
    transposeG = [] // empty graph
    for each vertex v in G do
        transposeG.addVertex(v) // add v to the transpose graph
    end for
    for each edge (u, v) in G do
        transposeG.addEdge(v, u) // reverse the direction of the edge in the transpose graph
    end for
    return transposeG
end 
```