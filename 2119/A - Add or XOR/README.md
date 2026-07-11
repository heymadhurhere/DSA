<h2><a href="https://codeforces.com/contest/2119/problem/A" target="_blank" rel="noopener noreferrer">2119A — Add or XOR</a></h2>

| | |
|---|---|
| **Difficulty** | 800 |
| **Language** | C++20 (GCC 13-64) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 2119A](https://codeforces.com/contest/2119/problem/A) |

## Topics
`bitmasks` `greedy` `math`

---

## Problem Statement

<div class="header"><div class="title">A. Add or XOR</div><div class="time-limit"><div class="property-title">time limit per test</div>1 second</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><div class="epigraph"><div class="epigraph-text"><span class="tex-font-style-it"><a href="https://www.youtube.com/watch?v=NMiQmumW0nI">r-906 & IA AI - Psychologic Disco</a></span></div><div class="epigraph-source"> </div></div><p>You are given two non-negative integers $$$a, b$$$. You can apply two types of operations on $$$a$$$ any number of times and in any order:</p><ul> <li> $$$a \gets a + 1$$$. The cost of this operation is $$$x$$$; </li><li> $$$a \gets a \oplus 1$$$, where $$$\oplus$$$ denotes the <a href="https://en.wikipedia.org/wiki/Bitwise_operation#XOR">bitwise XOR operation</a>. The cost of this operation is $$$y$$$. </li></ul><p>Now you are asked to make $$$a = b$$$. If it's possible, output the minimum cost; otherwise, report it.</p></div><div class="input-specification"><div class="section-title">Input</div><p>Each test contains multiple test cases. The first line contains the number of test cases $$$t$$$ ($$$1 \le t \le 10^4$$$). The description of the test cases follows. </p><p>The only line of each test case contains four integers $$$a, b, x, y$$$ ($$$1 \le a, b \le 100, 1 \le x, y \le 10^7$$$) — the two integers given to you and the respective costs of two types of operations.</p></div><div class="output-specification"><div class="section-title">Output</div><p>For each test case, output an integer — the minimum cost to make $$$a = b$$$, or $$$-1$$$ if it is impossible.</p></div><div class="sample-tests"><div class="section-title">Example</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id00709781308417133" id="id00013530329388627527" class="input-output-copier">Copy</div></div><pre id="id00709781308417133"><div class="test-example-line test-example-line-even test-example-line-0">7</div><div class="test-example-line test-example-line-odd test-example-line-1">1 4 1 2</div><div class="test-example-line test-example-line-even test-example-line-2">1 5 2 1</div><div class="test-example-line test-example-line-odd test-example-line-3">3 2 2 1</div><div class="test-example-line test-example-line-even test-example-line-4">1 3 2 1</div><div class="test-example-line test-example-line-odd test-example-line-5">2 1 1 2</div><div class="test-example-line test-example-line-even test-example-line-6">3 1 1 2</div><div class="test-example-line test-example-line-odd test-example-line-7">1 100 10000000 10000000</div></pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id0020796862046769626" id="id0007085512167005947" class="input-output-copier">Copy</div></div><pre id="id0020796862046769626">3
6
1
3
-1
-1
990000000
</pre></div></div></div><div class="note"><div class="section-title">Note</div><p>In the first test case, the optimal strategy is to apply $$$a \gets a + 1$$$ three times. The total cost is $$$1+1+1=3$$$.</p><p>In the second test case, the optimal strategy is to apply $$$a \gets a + 1$$$, $$$a \gets a \oplus 1$$$, $$$a \gets a + 1$$$, $$$a \gets a \oplus 1$$$ in order. The total cost is $$$2+1+2+1=6$$$.</p><p>In the fifth test case, it can be proved that there isn't a way to make $$$a = b$$$.</p></div>