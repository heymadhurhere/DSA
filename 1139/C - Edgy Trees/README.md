<h2><a href="https://codeforces.com/contest/1139/problem/C" target="_blank" rel="noopener noreferrer">1139C — Edgy Trees</a></h2>

| | |
|---|---|
| **Difficulty** | 1500 |
| **Language** | C++23 (GCC 14-64, msys2) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 1139C](https://codeforces.com/contest/1139/problem/C) |

## Topics
`dfs and similar` `dsu` `graphs` `math` `trees`

---

## Problem Statement

<div class="header"><div class="title">C. Edgy Trees</div><div class="time-limit"><div class="property-title">time limit per test</div>2 seconds</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>You are given a tree (a connected undirected graph without cycles) of $$$n$$$ vertices. Each of the $$$n - 1$$$ edges of the tree is colored in either black or red.</p><p>You are also given an integer $$$k$$$. Consider sequences of $$$k$$$ vertices. Let's call a sequence $$$[a_1, a_2, \ldots, a_k]$$$ <span class="tex-font-style-it">good</span> if it satisfies the following criterion:</p><ul> <li> We will walk a path (possibly visiting same edge/vertex multiple times) on the tree, starting from $$$a_1$$$ and ending at $$$a_k$$$. </li><li> Start at $$$a_1$$$, then go to $$$a_2$$$ using the shortest path between $$$a_1$$$ and $$$a_2$$$, then go to $$$a_3$$$ in a similar way, and so on, until you travel the shortest path between $$$a_{k-1}$$$ and $$$a_k$$$.</li><li> If you walked over at least one black edge during this process, then the sequence is good. </li></ul><center> <img class="tex-graphics" src="https://espresso.codeforces.com/6a3d4d9a4b0794f6c1cce0ebced5fe1e66ad945c.png" style="max-width: 100.0%;max-height: 100.0%;"> </center><p>Consider the tree on the picture. If $$$k=3$$$ then the following sequences are good: $$$[1, 4, 7]$$$, $$$[5, 5, 3]$$$ and $$$[2, 3, 7]$$$. The following sequences are not good: $$$[1, 4, 6]$$$, $$$[5, 5, 5]$$$, $$$[3, 7, 3]$$$.</p><p>There are $$$n^k$$$ sequences of vertices, count how many of them are good. Since this number can be quite large, print it modulo $$$10^9+7$$$.</p></div><div class="input-specification"><div class="section-title">Input</div><p>The first line contains two integers $$$n$$$ and $$$k$$$ ($$$2 \le n \le 10^5$$$, $$$2 \le k \le 100$$$), the size of the tree and the length of the vertex sequence.</p><p>Each of the next $$$n - 1$$$ lines contains three integers $$$u_i$$$, $$$v_i$$$ and $$$x_i$$$ ($$$1 \le u_i, v_i \le n$$$, $$$x_i \in \{0, 1\}$$$), where $$$u_i$$$ and $$$v_i$$$ denote the endpoints of the corresponding edge and $$$x_i$$$ is the color of this edge ($$$0$$$ denotes red edge and $$$1$$$ denotes black edge).</p></div><div class="output-specification"><div class="section-title">Output</div><p>Print the number of good sequences modulo $$$10^9 + 7$$$.</p></div><div class="sample-tests"><div class="section-title">Examples</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id009339413320614017" id="id009014530753127564" class="input-output-copier">Copy</div></div><pre id="id009339413320614017">4 4
1 2 1
2 3 1
3 4 1
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id0017584261691486913" id="id006856924414450609" class="input-output-copier">Copy</div></div><pre id="id0017584261691486913">252</pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id0023046937437769688" id="id005152453861610286" class="input-output-copier">Copy</div></div><pre id="id0023046937437769688">4 6
1 2 0
1 3 0
1 4 0
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id0007710752215183125" id="id0011848780585019691" class="input-output-copier">Copy</div></div><pre id="id0007710752215183125">0</pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id007795259322526066" id="id004015684651873538" class="input-output-copier">Copy</div></div><pre id="id007795259322526066">3 5
1 2 1
2 3 0
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id002048629182347077" id="id0024210049429033964" class="input-output-copier">Copy</div></div><pre id="id002048629182347077">210</pre></div></div></div><div class="note"><div class="section-title">Note</div><p>In the first example, all sequences ($$$4^4$$$) of length $$$4$$$ <span class="tex-font-style-bf">except</span> the following are good: </p><ul> <li> $$$[1, 1, 1, 1]$$$</li><li> $$$[2, 2, 2, 2]$$$</li><li> $$$[3, 3, 3, 3]$$$</li><li> $$$[4, 4, 4, 4]$$$ </li></ul><p>In the second example, all edges are red, hence there aren't any good sequences.</p></div>