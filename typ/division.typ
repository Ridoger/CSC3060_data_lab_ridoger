= Division

== Method

Naturally come up with the idea of long division, which is the method we use in daily life. 

First, take the absolute value $|a|, |b|$ for convenience. The value of `add(~INT32_MIN, 1)` is `INT32_MIN` itself. However, if we use `static_cast<uint32_t>` cast `INT32_MIN` to unsigned int, then we get $2^31$ which is exactly what we desire. Also, we need to avoid arithmetic shifts since it will cause some unexpected problems when right shifting `INT32_MIN` in the following steps. So cast `a, b` to unsigned int is necessary.

Then we try to find the maximal $i$ that $(b "<<" i) <= a$. We do this by checking the sign of the difference between $a$ and the multiplier. Since left-shifting $b$ may lead to overflow and cause unexpected effect (e.g. $(2^31-1) = -2 < 0$), we right-shift $a$ and check the sign of $(a ">>" i) - b$ instead.

Since arithmetic right shift 

Every time we find the multiplier $(b "<<" i)$ that smaller than $a$, we let `a = a - b << i` and plus 1 << i to the quotient. At last we get $a < b$ and the long division terminates. After restoring the sign of quotient, we return the result.

== Time Complexity

$n$ subtraction with complexity $O(log n)$ is applied to check whether the multiplier is greater than the remainder, thus the complexity is $O(n log n)$.

== Difficultis

I had forgotten that signed integer uses arithmetic shift. That caused some chaos when checking the sign of differences. #link(<gpt>)[gpt pointed it out] for me. After all, I didn't met any big problems.

#parbreak()
#set page(
    height: auto
)

== Credit <gpt>

#image("/images/gpt1.png", height: 500pt)
#image("/images/gpt2.png", height: 517pt)
