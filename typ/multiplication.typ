= Multiplication

== Method

Denote $a$ by $overline(a_1a_2 ... a_32)$, where $a_i$ is the $i$-th bit of $a$ from right to left. Then 
$ 
    a b = sum^32_(i=0) 2^(i-1) a_i b
$
We traversal through bits of $a$. If $a_i = 1$, left_shift $b$ by $i$ bits then add it to the result. After traversal is done, the sum will be the product.

== Time Complexity
For each bit, an additional shift may occur; for each shift, an addition with complexity $O(log n)$ is done to sum the result. Hence the complexity is $O(n log n)$. 

== Difficulties

None

== Credit 

None
