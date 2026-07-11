<h2><a href="https://codeforces.com/contest/1516/problem/B" target="_blank" rel="noopener noreferrer">1516B — AGAGA XOOORRR</a></h2>

| | |
|---|---|
| **Difficulty** | 1500 |
| **Language** | C++23 (GCC 14-64, msys2) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 1516B](https://codeforces.com/contest/1516/problem/B) |

## Topics
`bitmasks` `brute force` `dp` `greedy`

---

## Problem Statement

<div class="header"><div class="title">B. AGAGA XOOORRR</div><div class="time-limit"><div class="property-title">time limit per test</div>1 second</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>Baby Ehab is known for his love for a certain operation. He has an array $$$a$$$ of length $$$n$$$, and he decided to keep doing the following operation on it: </p><ul> <li> he picks $$$2$$$ adjacent elements; he then removes them and places a single integer in their place: their <a href="https://en.wikipedia.org/wiki/Bitwise_operation#XOR">bitwise XOR</a>. Note that the length of the array decreases by one. </li></ul><p>Now he asks you if he can make all elements of the array equal. Since babies like to make your life harder, he requires that you leave at least $$$2$$$ elements remaining.</p></div><div class="input-specification"><div class="section-title">Input</div><p>The first line contains an integer $$$t$$$ ($$$1 \le t \le 15$$$) — the number of test cases you need to solve.</p><p>The first line of each test case contains an integers $$$n$$$ ($$$2 \le n \le 2000$$$) — the number of elements in the array $$$a$$$.</p><p>The second line contains $$$n$$$ space-separated integers $$$a_1$$$, $$$a_2$$$, $$$\ldots$$$, $$$a_{n}$$$ ($$$0 \le a_i  \lt  2^{30}$$$) — the elements of the array $$$a$$$.</p></div><div class="output-specification"><div class="section-title">Output</div><p>If Baby Ehab can make all elements equal while leaving at least $$$2$$$ elements standing, print "<span class="tex-font-style-tt">YES</span>". Otherwise, print "<span class="tex-font-style-tt">NO</span>".</p></div><div class="sample-tests"><div class="section-title">Example</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id002925695930231882" id="id006481608266051218" class="input-output-copier">Copy</div></div><pre id="id002925695930231882">2
3
0 2 2
4
2 3 1 10
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id0046191830317815963" id="id006539745606474878" class="input-output-copier">Copy</div></div><pre id="id0046191830317815963">YES
NO
</pre></div></div></div><div class="note"><div class="section-title">Note</div><p>In the first sample, he can remove the first $$$2$$$ elements, $$$0$$$ and $$$2$$$, and replace them by $$$0 \oplus 2=2$$$. The array will be $$$[2,2]$$$, so all the elements are equal.</p><p>In the second sample, there's no way to make all the elements equal.</p></div>