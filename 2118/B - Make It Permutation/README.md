<h2><a href="https://codeforces.com/contest/2118/problem/B" target="_blank" rel="noopener noreferrer">2118B — Make It Permutation</a></h2>

| | |
|---|---|
| **Difficulty** | 1200 |
| **Language** | C++20 (GCC 13-64) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 2118B](https://codeforces.com/contest/2118/problem/B) |

## Topics
`constructive algorithms`

---

## Problem Statement

<div class="header"><div class="title">B. Make It Permutation</div><div class="time-limit"><div class="property-title">time limit per test</div>1 second</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>There is a matrix $$$A$$$ of size $$$n\times n$$$ where $$$A_{i,j}=j$$$ for all $$$1 \le i,j \le n$$$. </p><p>In one operation, you can select a row and reverse any subarray$$$^{\text{∗}}$$$ in it. </p><p>Find a sequence of at most $$$2n$$$ operations such that every column will contain a permutation$$$^{\text{†}}$$$ of length $$$n$$$.</p><p>It can be proven that the construction is always possible. If there are multiple solutions, output any of them.</p><div class="statement-footnote"><p>$$$^{\text{∗}}$$$An array $$$a$$$ is a subarray of an array $$$b$$$ if $$$a$$$ can be obtained from $$$b$$$ by deleting zero or more elements from the beginning and zero or more elements from the end.</p><p>$$$^{\text{†}}$$$A permutation of length $$$n$$$ is an array consisting of $$$n$$$ distinct integers from $$$1$$$ to $$$n$$$ in arbitrary order. For example, $$$[2,3,1,5,4]$$$ is a permutation, but $$$[1,2,2]$$$ is not a permutation ($$$2$$$ appears twice in the array), and $$$[1,3,4]$$$ is also not a permutation ($$$n=3$$$ but there is $$$4$$$ in the array).</p></div></div><div class="input-specification"><div class="section-title">Input</div><p>Each test contains multiple test cases. The first line contains the number of test cases $$$t$$$ ($$$1 \le t \le 100$$$). The description of the test cases follows. </p><p>The first line of each test case contains one integer $$$n$$$ ($$$3 \le n \le 5000$$$) — denoting the number of rows and columns in the matrix.</p><p>It is guaranteed that the sum of $$$n$$$ over all test cases does not exceed $$$5000$$$.</p></div><div class="output-specification"><div class="section-title">Output</div><p>For each test case, on the first line, print an integer $$$k$$$ $$$(0 \le k \le 2n)$$$, the number of operations you wish to perform. On the next lines, you should print the operations.</p><p>To print an operation, use the format "$$$i\;l\;r$$$" ($$$1 \leq l \leq r \leq n$$$ and $$$1 \leq i \leq n$$$) which reverses the subarray $$$A_{i, l}$$$, $$$A_{i, l+1}$$$, $$$\ldots$$$, $$$A_{i, r}$$$.</p></div><div class="sample-tests"><div class="section-title">Example</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id006568193033487465" id="id002819978707849712" class="input-output-copier">Copy</div></div><pre id="id006568193033487465"><div class="test-example-line test-example-line-even test-example-line-0">2</div><div class="test-example-line test-example-line-odd test-example-line-1">3</div><div class="test-example-line test-example-line-even test-example-line-2">4</div></pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id005231605705483454" id="id00583812488972604" class="input-output-copier">Copy</div></div><pre id="id005231605705483454">4
2 1 3
2 2 3
3 1 2
3 2 3
5
2 1 4
3 1 3
3 2 4
4 3 4
4 1 2</pre></div></div></div><div class="note"><div class="section-title">Note</div><p>In the first test case, the following operations are a valid solution:</p><center> <img class="tex-graphics" src="https://espresso.codeforces.com/3b9509868f6d3b65d8a4a7a94688db76911f59b7.png" style="zoom: 70.0%;max-width: 100.0%;max-height: 100.0%;">   </center> </div>