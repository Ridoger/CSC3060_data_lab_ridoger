= Addition

== Method

=== An naive way <naive>

Naturally we notice that if both $a$ and $b$ have a 1 at the same bit position, then $a$ & $b$ will also have a 1 at that bit, which indicates a carry is generated at that position; if we ignore the carry, then each bit of $a + b$ is 1 if and only if exactly one of $a$ or $b$ has a 1 at that bit. Thus we obtain 
$
    a + b = a_1 + b_1, "where" a_1 = a and b "<<" 1, b_1 = a xor b.
$
Note that since left-shifting fills the vacated bits with zeros, the least significant bit $a_1$ of $a$, equals to $(a and b) "<<" 1$, is always 0. Consequently, the two lowest-order bits of $(a_1 and b_1) "<<" 1$ will both be 0. Every time we repeat this process, one more 0 will be generated at the right side. Hence after 32 repeats, we finally get $a_32 = 0$. We conclude that one of the approaches to implement `add()` just need to do the operation above for 32 times.

However this approach is slow and code looks ugly while loops are forbiddened. Inspired by the thought of Carry-Lookahead Adder[CLA], I implemented another approach (although it might be more proper to call my `add()` as Parallel Prefix Adder[PPA]).

=== My approach

Define carry propagation function $P_0(a,b) = a xor b$ and carry generation function $G_0(a,b) = a and b$. Denote the bits of $P_0$ and $G_0$ by $p^i_0, g^i_0, i=1, 2, ..., 32$ where $p^1_0, g^1_0$ are the right end of $P_0, G_0$. Note that a carry $g^i_0 = 1$ triggers another carry $<=>g^i_0 and p^(i+1)_0 = 1.$ 

We define that a sequence of 1 $S = {p_k^i=1, p_k^(i+1)=1, ..., p_k^(i+j)=1} subset.eq P_k$ is a _path_, if $forall g_k^i in S$, we have either $g_0^i = 0$ or $g_0^i$ is the right end of the sequence. We call $|S|$ the _length_ of the path. Then, all carries that don't trigger another carry will be represented by a path with length 1.

#align(center)[```cpp
    G |= (G << 1) & P;
    P &= P << 1;
    G |= (G << 2) & P;
```]

Meaning of the first line is similar to the operation in *@naive*. By using $P_1 = P_0 and (P_0 "<<" 1)$ we can find end points for all possible propagation with len = 2, then we use $G_2 = G_1 or [(G_1 "<<" 2) and P_1]$ to expand the length of paths in $G_1$ if possible. *Here comes some different situations after left-shifting*:

+ #[

    *A path ${g^i_1}$ with length 1 in $G_1$.* \ 

    We want to prove that those paths didn't expand in last step will not expand in this step.

    The only bit of $G_2$ that may be affected by $g^i_1$ is $g_2^(i+2)$. 
    
    $g_1^(i+1) = g_0^(i+1) or (g_0^i and p_0^(i+1)) = 0 quad ==> quad g_0^(i+1) = p_0^(i+1) = 0," then we have"$

    $ 
    &g_2^(i+2) = g_1^(i+2) or (g_1^i and p_1^(i+2)) \

    = [&g_0^(i+2) or (g_0^(i+1) and p_0^(i+2))] or [g_1^i and (p_0^(i+2) and p_0^(i+1))] \

    = [&g_0^(i+2) or (0 and p_0^(i+2))] or [1 and (p_0^(i+2) and 0)] \

    = (&g_0^(i+2) or 0) or 0 \

    =#h(0.7em)& g_0^(i+2)
    $
    
    We showed that the value of $g_2^(i+2)$ is regardless of $g^i_1$. Therefore, this path will be moved to $G_2$ while remaining unchanged without any side effect. 

] 

+ #[

    *A path ${g^i_1, g^(i+1)_1}$ with length 2.* \ 

    $"Note that" p_0^(i+1) = 1 "since " g^(i+1)_1 = g_0^(i+1) or (g_0^i and p_0^(i+1)) = 1 "and" g_0^(i+1) = 0 "by the definition".$

    $"If" g_1^(i+1) and p_1^(i+3) = p_1^(i+3) = p_0^(i+3) and p_0^(i+2) = 1, "then" p_0^(i+2) = 1, "which implies" p_1^(i+2) = p_0^(i+2) and p_0^(i+1) = 1. "Hence" g_2^(i+3) = g_1^(i+3) or (g_1^(i+1) and p_1^(i+3)) = g_1^(i+3) or (1 and 1) = 1$. This is to say, a path must remain conjunctive after expansion. Thus a carry can propagate throughout the path without causing bugs.

    Finally we point that a path expands iff $p_0^(i+2)=1$, or both $p_0^(i+2)$ and $p_0^(i+3)$ equals 1, which is equivilant to say a carry can propagate step by step like what we did repeatedly in *@naive*.

]

We repeat this process 5 times to find all path for propagation. Correctness of each step can be prove by following the idea above. The largest length can a path expand in a single step is 1, 2, 4, 8, 16, repectively. Since a path will keep expanding in each step utill reaching its maximum length, this 5 steps can expands the length of the path by up to $31 = 1 + 2 + 4 + 8 + 16$. When computing additon of 2 `int32_t` type integers, a carry can propagate at most 31 bits far, so 5 steps are enough for us.

Now we have $G_5$ that contains all paths with their maximum length. For each path, it terminates at $g_5^i$ iff either another path begins here, or $p_4^(i+1) = 0 <=> p_0^(i+1) = 0$. Also, if a bit of a path $g_5^k = 1$, then $p_0^(k+1) = 1$. Hence only need to compute $P_0 xor (G_5 "<<" 1)$ will we get the result of $a+b$ (recall that $P_0 = a xor b$). 

Complete implementation:

#raw(
"    int32_t add(int32_t a, int32_t b) {

    int32_t P = a ^ b;
    int32_t G = a & b;

    int32_t temp_P = P;

    G |= (G << 1) & P;
    P &= P << 1;
    G |= (G << 2) & P;
    P &= P << 2;
    G |= (G << 4) & P;
    P &= P << 4;
    G |= (G << 8) & P;
    P &= P << 8;
    G |= (G << 16) & P;

    return temp_P ^ (G << 1);

    }
"
)

== Time Complexity

$O(log n)$, where $n$ is the number of bits. 

== Difficulties I met

Almost every step to make this function run appeared to be a big challenge for me. After implemented the method in *@naive*, I just felt unpleasant about its inefficiency and ugliness. When I asked AI for help, none of them offered a better solution. 

Don't know whether I should say it lucky or not, my roommate used to be an Oier. I asked him if he had some advice, and he told me that carries can propagate "exponentially". That's how my self-torture began. I googled to find what he means and found the existence of CLA. Wow. That concept was way ahead of its time for me, and it took me some time to understand what it is.

#link(<CLA_blog>)[The clearest blog I found about CLA which also spent the most of my time to learn the thought of CLA]

However, eventually it turned out that my code would only become uglier instead becoming of more elegant if I just simply copy the mechanism of CLA. But AI started to say some useful after I prompt them with "CLA". Chat-GPT gave a version of implementation that pretty close to the final version I used, except for gpt didn't update the value of P after each step. It worked well on all unit tests except the 2 random number addition. I spent another several hours to check the binary forms of the numbers to find why the function failed on this two. There's no doubt that I found nothing. Those binary numbers are not for human beings.

Unfortunately, I thought the codes gpt gave was junk since gpt couldn't tell how his code works. So I deleted both code and the dialogue with gpt. Hence I am not able to post it here. 

After I gave up, then my roommate asked me to show him the code gpt gave, and pointed out the problem. I corrected it by accident. It runned, but I didn't know why it runned. Deepseek said #link(<ds1>)[nothing useful] about it. Finally I spent 2 days to figure that out and learn how to write it down by typst. These shall be all difficulties I met when implementing `add()`.

== Credit

- My roommate Heng Zhang who provided essential idea of the implementation.
- #link("https://yeyisheng.github.io/2024/11/21/%E4%B8%80%E6%AC%A1%E5%9E%8B%E8%A7%A3%E5%86%B3%E8%B6%85%E5%89%8D%E8%BF%9B%E4%BD%8D%E5%8A%A0%E6%B3%95%E5%99%A8%E2%80%94%E2%80%9432%E4%BD%8DCLA%E7%9A%84%E5%AE%9E%E7%8E%B0/", )[一次型解决超前进位加法器——32位CLA的实现 —— 叶逸昇] <CLA_blog>

#pagebreak()
#set page(
    height: auto,
    margin: 0pt
)
#show image: im => align(center, im)

#image("/images/ds1.png", width: 80%) <ds1>
#image("/images/ds2.png", width: 80%)
#image("/images/ds3.png", width: 60%)
    