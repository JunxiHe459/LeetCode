# Integer Break

做题前：

1. 假设我们有一个数 n，且 n is big enough。

   如果将 n break down 为 $$ k_0 + k_1 + k_2 + k_3 + ... + k_i$$

   设 $$ k_0 * k_1 * k_2 * k_3 * ... * k_(i-1) = x$$

   则 Integer Break(n) = x * $$k_i$$

   Proof by contradiction 证明 $$k_i$$ = 2 或 3

   为了使 Integer Break(n) 取到最大，$$k_i$$必须取到最大。

   如果 $$k_i > 4$$, 则 Integer Break(n) =  x * $$k_i$$

   但 $$(k_i - 3) * 3 = 3(k_i) - 9 > k_i$$，因此，为了使 Integer Break(n)的值取到最大，$$k_i <= 4$$。

   如果$$k_i == 4$$，则分解为 2 * 2。

   因此，$$k_i$$ = 2 或 3。

2.  并且，3 是优先于 2 的。因为 6 = 3 + 3 = 2 + 2 + 2，但是 3 * 3 > 2 * 2 * 2。

   

   

做题中：

1. 注意按照题目要求，n == 2 时结果为 1 * 1，n == 3 时结果为 1 * 2



做题后：

1. 一道有点儿意思的数学题。 $$(k_i - 3) * 3 = 3(k_i) - 9 > k_i$$是关键。

