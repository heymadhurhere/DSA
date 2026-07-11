<h2><a href="https://codeforces.com/contest/1648/problem/A" target="_blank" rel="noopener noreferrer">1648A — Weird Sum</a></h2>

| | |
|---|---|
| **Difficulty** | 1400 |
| **Language** | C++23 (GCC 14-64, msys2) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 1648A](https://codeforces.com/contest/1648/problem/A) |

## Topics
`combinatorics` `data structures` `geometry` `math` `matrices` `sortings`

---

## Problem Statement

<div class="header"><div class="title">A. Weird Sum</div><div class="time-limit"><div class="property-title">time limit per test</div>2 seconds</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>Egor has a table of size $$$n \times m$$$, with lines numbered from $$$1$$$ to $$$n$$$ and columns numbered from $$$1$$$ to $$$m$$$. Each cell has a color that can be presented as an integer from $$$1$$$ to $$$10^5$$$.</p><p>Let us denote the cell that lies in the intersection of the $$$r$$$-th row and the $$$c$$$-th column as $$$(r, c)$$$. We define the <span class="tex-font-style-underline">manhattan distance</span> between two cells $$$(r_1, c_1)$$$ and $$$(r_2, c_2)$$$ as the length of a shortest path between them where each consecutive cells in the path must have a common side. The path can go through cells of any color. For example, in the table $$$3 \times 4$$$ the manhattan distance between $$$(1, 2)$$$ and $$$(3, 3)$$$ is $$$3$$$, one of the shortest paths is the following: $$$(1, 2) \to (2, 2) \to (2, 3) \to (3, 3)$$$. </p><p>Egor decided to calculate the sum of manhattan distances between each pair of cells of the same color. Help him to calculate this sum.</p></div><div class="input-specification"><div class="section-title">Input</div><p>The first line contains two integers $$$n$$$ and $$$m$$$ ($$$1 \leq n \le m$$$, $$$n \cdot m \leq 100\,000$$$) — number of rows and columns in the table.</p><p>Each of next $$$n$$$ lines describes a row of the table. The $$$i$$$-th line contains $$$m$$$ integers $$$c_{i1}, c_{i2}, \ldots, c_{im}$$$ ($$$1 \le c_{ij} \le 100\,000$$$) — colors of cells in the $$$i$$$-th row.</p></div><div class="output-specification"><div class="section-title">Output</div><p>Print one integer — the the sum of manhattan distances between each pair of cells of the same color.</p></div><div class="sample-tests"><div class="section-title">Examples</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id004750390179018086" id="id009543260456667373" class="input-output-copier">Copy</div></div><pre id="id004750390179018086">2 3
1 2 3
3 2 1
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id005897440467249938" id="id0047181268022293477" class="input-output-copier">Copy</div></div><pre id="id005897440467249938">7
</pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id0025641074182397483" id="id003999076917277333" class="input-output-copier">Copy</div></div><pre id="id0025641074182397483">3 4
1 1 2 2
2 1 1 2
2 2 1 1
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id008007718276706234" id="id0017164162852241105" class="input-output-copier">Copy</div></div><pre id="id008007718276706234">76
</pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id0031686307382714385" id="id0004637978934812581" class="input-output-copier">Copy</div></div><pre id="id0031686307382714385">4 4
1 1 2 3
2 1 1 2
3 1 2 1
1 1 2 1
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id006135285480992021" id="id006873763457670583" class="input-output-copier">Copy</div></div><pre id="id006135285480992021">129
</pre></div></div></div><div class="note"><div class="section-title">Note</div><p>In the first sample there are three pairs of cells of same color: in cells $$$(1, 1)$$$ and $$$(2, 3)$$$, in cells $$$(1, 2)$$$ and $$$(2, 2)$$$, in cells $$$(1, 3)$$$ and $$$(2, 1)$$$. The manhattan distances between them are $$$3$$$, $$$1$$$ and $$$3$$$, the sum is $$$7$$$.</p></div>