<h2><a href="https://codeforces.com/contest/1350/problem/B" target="_blank" rel="noopener noreferrer">1350B — Orac and Models</a></h2>

| | |
|---|---|
| **Difficulty** | 1400 |
| **Language** | C++23 (GCC 14-64, msys2) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 1350B](https://codeforces.com/contest/1350/problem/B) |

## Topics
`dp` `math` `number theory`

---

## Problem Statement

<div class="header"><div class="title">B. Orac and Models</div><div class="time-limit"><div class="property-title">time limit per test</div>3 seconds</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>There are $$$n$$$ models in the shop numbered from $$$1$$$ to $$$n$$$, with sizes $$$s_1, s_2, \ldots, s_n$$$.</p><p>Orac will buy some of the models and will arrange them in the order of increasing numbers (i.e. indices, but not sizes).</p><p>Orac thinks that the obtained arrangement is <span class="tex-font-style-bf">beatiful</span>, if for any two adjacent models with indices $$$i_j$$$ and $$$i_{j+1}$$$ (note that $$$i_j  \lt  i_{j+1}$$$, because Orac arranged them properly), $$$i_{j+1}$$$ is divisible by $$$i_j$$$ and $$$s_{i_j}  \lt  s_{i_{j+1}}$$$.</p><p>For example, for $$$6$$$ models with sizes $$$\{3, 6, 7, 7, 7, 7\}$$$, he can buy models with indices $$$1$$$, $$$2$$$, and $$$6$$$, and the obtained arrangement will be beautiful. Also, note that the arrangement with exactly one model is also considered beautiful.</p><p>Orac wants to know the maximum number of models that he can buy, and he may ask you these queries many times.</p></div><div class="input-specification"><div class="section-title">Input</div><p>The first line contains one integer $$$t\ (1 \le t\le 100)$$$: the number of queries.</p><p>Each query contains two lines. The first line contains one integer $$$n\ (1\le n\le 100\,000)$$$: the number of models in the shop, and the second line contains $$$n$$$ integers $$$s_1,\dots,s_n\ (1\le s_i\le 10^9)$$$: the sizes of models.</p><p>It is guaranteed that the total sum of $$$n$$$ is at most $$$100\,000$$$.</p></div><div class="output-specification"><div class="section-title">Output</div><p>Print $$$t$$$ lines, the $$$i$$$-th of them should contain the maximum number of models that Orac can buy for the $$$i$$$-th query.</p></div><div class="sample-tests"><div class="section-title">Example</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id000949209378596867" id="id008203309308795356" class="input-output-copier">Copy</div></div><pre id="id000949209378596867">4
4
5 3 4 6
7
1 4 2 3 6 4 9
5
5 4 3 2 1
1
9
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id0032733582692759977" id="id008976715478850771" class="input-output-copier">Copy</div></div><pre id="id0032733582692759977">2
3
1
1
</pre></div></div></div><div class="note"><div class="section-title">Note</div><p>In the first query, for example, Orac can buy models with indices $$$2$$$ and $$$4$$$, the arrangement will be beautiful because $$$4$$$ is divisible by $$$2$$$ and $$$6$$$ is more than $$$3$$$. By enumerating, we can easily find that there are no beautiful arrangements with more than two models. </p><p>In the second query, Orac can buy models with indices $$$1$$$, $$$3$$$, and $$$6$$$. By enumerating, we can easily find that there are no beautiful arrangements with more than three models. </p><p>In the third query, there are no beautiful arrangements with more than one model.</p></div>