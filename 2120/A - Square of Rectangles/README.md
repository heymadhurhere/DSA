<h2><a href="https://codeforces.com/contest/2120/problem/A" target="_blank" rel="noopener noreferrer">2120A — Square of Rectangles</a></h2>

| | |
|---|---|
| **Difficulty** | 800 |
| **Language** | C++20 (GCC 13-64) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 2120A](https://codeforces.com/contest/2120/problem/A) |

## Topics
`geometry` `math`

---

## Problem Statement

<div class="header"><div class="title">A. Square of Rectangles</div><div class="time-limit"><div class="property-title">time limit per test</div>1 second</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>Aryan is an ardent lover of squares but a hater of rectangles (Yes, he knows all squares are rectangles). But Harshith likes to mess with Aryan. Harshith gives Aryan three rectangles of sizes $$$l_1\times b_1$$$, $$$l_2\times b_2$$$, and $$$l_3\times b_3$$$ such that $$$l_3\leq l_2\leq l_1$$$ and $$$b_3\leq b_2\leq b_1$$$. Aryan, in order to defeat Harshith, decides to arrange these three rectangles to form a square such that no two rectangles overlap and the rectangles are aligned along edges. Rotating rectangles is <span class="tex-font-style-bf">not</span> allowed. Help Aryan determine if he can defeat Harshith.</p></div><div class="input-specification"><div class="section-title">Input</div><p>Each test contains multiple test cases. The first line contains the number of test cases $$$t$$$ ($$$1 \le t \le 100$$$). The description of the test cases follows. </p><p>Each test case contains a single line with $$$6$$$ space-separated integers $$$l_1, b_1, l_2, b_2, l_3$$$, and $$$b_3$$$ ($$$1 \leq l_3\le l_2\le l_1\le 100$$$, $$$1\le b_3\le b_2\le b_1 \leq 100$$$) — the dimensions of the three rectangles.</p></div><div class="output-specification"><div class="section-title">Output</div><p>For each testcase, print "<span class="tex-font-style-tt">YES</span>" if the rectangles can be arranged to form a square; otherwise, "<span class="tex-font-style-tt">NO</span>".</p><p>You can output the answer in any case (upper or lower). For example, the strings "<span class="tex-font-style-tt">yEs</span>", "<span class="tex-font-style-tt">yes</span>", "<span class="tex-font-style-tt">Yes</span>", and "<span class="tex-font-style-tt">YES</span>" will be recognized as positive responses.</p></div><div class="sample-tests"><div class="section-title">Example</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id008841316325239852" id="id001424933004890212" class="input-output-copier">Copy</div></div><pre id="id008841316325239852"><div class="test-example-line test-example-line-even test-example-line-0">5</div><div class="test-example-line test-example-line-odd test-example-line-1">100 100 10 10 1 1</div><div class="test-example-line test-example-line-even test-example-line-2">5 3 5 1 5 1</div><div class="test-example-line test-example-line-odd test-example-line-3">2 3 1 2 1 1</div><div class="test-example-line test-example-line-even test-example-line-4">8 5 3 5 3 3</div><div class="test-example-line test-example-line-odd test-example-line-5">3 3 3 3 2 1</div></pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id005765787570848936" id="id008725579197440074" class="input-output-copier">Copy</div></div><pre id="id005765787570848936">NO
YES
YES
NO
NO
</pre></div></div></div><div class="note"><div class="section-title">Note</div><p>In the second test case, the three rectangles $$$5\times 3$$$, $$$5\times 1$$$, and $$$5\times 1$$$ can be arranged as follows to form a square.</p><center> <img class="tex-graphics" src="https://espresso.codeforces.com/1d9464d4f577e3d9c6bf987d26fea814cf98ee12.png" style="max-width: 100.0%;max-height: 100.0%;"> </center><p>In the fourth test case, it can be proven that the rectangles can't be arranged to form a square with the given constraints.</p></div>