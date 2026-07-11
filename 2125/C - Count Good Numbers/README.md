<h2><a href="https://codeforces.com/contest/2125/problem/C" target="_blank" rel="noopener noreferrer">2125C — Count Good Numbers</a></h2>

| | |
|---|---|
| **Difficulty** | 1100 |
| **Language** | C++20 (GCC 13-64) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 2125C](https://codeforces.com/contest/2125/problem/C) |

## Topics
`bitmasks` `combinatorics` `math` `number theory`

---

## Problem Statement

<div class="header"><div class="title">C. Count Good Numbers</div><div class="time-limit"><div class="property-title">time limit per test</div>2 seconds</div><div class="memory-limit"><div class="property-title">memory limit per test</div>512 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>A prime number is a positive integer that has exactly two divisors: $$$1$$$ and itself. The first several prime numbers are $$$2, 3, 5, 7, 11, \dots$$$.</p><p>Prime factorization of a positive integer is representing it as a product of prime numbers. For example:</p><ul> <li> the prime factorization of $$$111$$$ is $$$3 \cdot 37$$$; </li><li> the prime factorization of $$$43$$$ is $$$43$$$; </li><li> the prime factorization of $$$12$$$ is $$$2 \cdot 2 \cdot 3$$$. </li></ul><p>For every positive integer, its prime factorization is unique (if you don't consider the order of primes in the product).</p><p>We call a positive integer <span class="tex-font-style-bf">good</span> if <span class="tex-font-style-bf">all</span> primes in its factorization consist of at least two digits. For example:</p><ul> <li> $$$343 = 7 \cdot 7 \cdot 7$$$ is not good; </li><li> $$$111 = 3 \cdot 37$$$ is not good; </li><li> $$$1111 = 11 \cdot 101$$$ is good; </li><li> $$$43 = 43$$$ is good. </li></ul><p>You have to calculate the number of good integers from $$$l$$$ to $$$r$$$ (endpoints included).</p></div><div class="input-specification"><div class="section-title">Input</div><p>The first line contains one integer $$$t$$$ ($$$1 \le t \le 10^3$$$) — the number of test cases.</p><p>Each test case consists of one line containing two integers $$$l$$$ and $$$r$$$ ($$$2 \le l \le r \le 10^{18}$$$).</p></div><div class="output-specification"><div class="section-title">Output</div><p>For each test case, print one integer — the number of good integers from $$$l$$$ to $$$r$$$.</p></div><div class="sample-tests"><div class="section-title">Example</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id007688425997893027" id="id008596415045195418" class="input-output-copier">Copy</div></div><pre id="id007688425997893027"><div class="test-example-line test-example-line-even test-example-line-0">4</div><div class="test-example-line test-example-line-odd test-example-line-1">2 100</div><div class="test-example-line test-example-line-even test-example-line-2">2 1000</div><div class="test-example-line test-example-line-odd test-example-line-3">13 37</div><div class="test-example-line test-example-line-even test-example-line-4">2 1000000000000000000</div></pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id001569757796497674" id="id006968579715112685" class="input-output-copier">Copy</div></div><pre id="id001569757796497674">21
227
7
228571428571428570
</pre></div></div></div>