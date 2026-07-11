<h2><a href="https://codeforces.com/contest/2181/problem/H" target="_blank" rel="noopener noreferrer">2181H — Honey Cake</a></h2>

| | |
|---|---|
| **Difficulty** | 1200 |
| **Language** | C++23 (GCC 14-64, msys2) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 2181H](https://codeforces.com/contest/2181/problem/H) |

## Topics
`brute force` `math` `number theory`

---

## Problem Statement

<div class="header"><div class="title">H. Honey Cake</div><div class="time-limit"><div class="property-title">time limit per test</div>3 seconds</div><div class="memory-limit"><div class="property-title">memory limit per test</div>1024 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>Hannah and Henry are going to host a party for $$$n$$$ people, including themselves. </p><p>They bought a honey cake of size $$$w \times h \times d$$$ inches for the party, and want to split it into $$$n$$$ equal pieces.</p><p>The honey cake can be cut parallel to any of its faces. To make cuts precise, each edge of length $$$w$$$ is cut into the same number of equal parts, each having integer length; similarly for edges of lengths $$$h$$$ and $$$d$$$.</p><p>Given the dimensions of the honey cake, determine whether it is possible to cut it into $$$n$$$ equal pieces, and if so, how.</p></div><div class="input-specification"><div class="section-title">Input</div><p>The first line of input contains three integers: $$$w$$$, $$$h$$$, and $$$d$$$, the dimensions of the honey cake in inches ($$$1 \le w, h, d \le 10^9$$$).</p><p>The second line contains a single integer $$$n$$$ ($$$1 \le n \le 10^9$$$).</p></div><div class="output-specification"><div class="section-title">Output</div><p>Output three integers $$$w_c$$$, $$$h_c$$$, $$$d_c$$$, the number of cuts to be made along each of the dimensions $$$w$$$, $$$h$$$, and $$$d$$$, respectively, if it is possible to cut the cake, or a single integer $$$-1$$$ otherwise. Note that making zero cuts along a dimension is allowed, too.</p></div><div class="sample-tests"><div class="section-title">Example</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id00647455396400257" id="id00529492561506791" class="input-output-copier">Copy</div></div><pre id="id00647455396400257">10 20 6
40</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id0043019200110648903" id="id0022764300255319359" class="input-output-copier">Copy</div></div><pre id="id0043019200110648903">4 3 1</pre></div></div></div><div class="note"><div class="section-title">Note</div><p>In the first example, the cake will be cut into $$$5 \cdot 4 \cdot 2 = 40$$$ pieces of size $$$2 \times 5 \times 3$$$ inches.</p><center> <img class="tex-graphics" src="https://espresso.codeforces.com/cb10b493232ebb7dd1b3501f222f3dddc15aff95.png" style="max-width: 100.0%;max-height: 100.0%;" width="241px"> </center></div>