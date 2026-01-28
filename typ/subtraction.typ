= Subtraction

== Method

One group only need one operation. There's no need for us to implement addition again. The only thing we need to do is to find the additive inverse of b, which is $1+~b$ in computer.

`    return add(a, add(~b, 1));`

== Time Complexity

$O(log n)$, the same with `add()`.

== Difficulties

None.

== Credit

Should be none. Maybe my algebra textbook should be mentioned? Then

#par(hanging-indent: 2em)[
Kostrikin, A. I. 2007. 代数学引论（第1卷：基础代数）. Translated by 张英伯. 2nd ed. Beijing: Higher Education Press. ISBN 978-7-04-020525-1
]
