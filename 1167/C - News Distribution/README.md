<h2><a href="https://codeforces.com/contest/1167/problem/C" target="_blank" rel="noopener noreferrer">1167C — News Distribution</a></h2>

| | |
|---|---|
| **Difficulty** | 1400 |
| **Language** | C++23 (GCC 14-64, msys2) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 1167C](https://codeforces.com/contest/1167/problem/C) |

## Topics
`dfs and similar` `dsu` `graphs`

---

## Problem Statement

<div class="header"><div class="title">C. News Distribution</div><div class="time-limit"><div class="property-title">time limit per test</div>2 seconds</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>In some social network, there are $$$n$$$ users communicating with each other in $$$m$$$ groups of friends. Let's analyze the process of distributing some news between users.</p><p>Initially, some user $$$x$$$ receives the news from some source. Then he or she sends the news to his or her friends (two users are friends if there is at least one group such that both of them belong to this group). Friends continue sending the news to their friends, and so on. The process ends when there is no pair of friends such that one of them knows the news, and another one doesn't know.</p><p>For each user $$$x$$$ you have to determine what is the number of users that will know the news if initially only user $$$x$$$ starts distributing it. </p></div><div class="input-specification"><div class="section-title">Input</div><p>The first line contains two integers $$$n$$$ and $$$m$$$ ($$$1 \le n, m \le 5 \cdot 10^5$$$) — the number of users and the number of groups of friends, respectively.</p><p>Then $$$m$$$ lines follow, each describing a group of friends. The $$$i$$$-th line begins with integer $$$k_i$$$ ($$$0 \le k_i \le n$$$) — the number of users in the $$$i$$$-th group. Then $$$k_i$$$ <span class="tex-font-style-bf">distinct</span> integers follow, denoting the users belonging to the $$$i$$$-th group.</p><p>It is guaranteed that $$$\sum \limits_{i = 1}^{m} k_i \le 5 \cdot 10^5$$$.</p></div><div class="output-specification"><div class="section-title">Output</div><p>Print $$$n$$$ integers. The $$$i$$$-th integer should be equal to the number of users that will know the news if user $$$i$$$ starts distributing it.</p></div><div class="sample-tests"><div class="section-title">Example</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id001346891383389539" id="id00375073491364618" class="input-output-copier">Copy</div></div><pre id="id001346891383389539">7 5
3 2 5 4
0
2 1 2
1 1
2 6 7
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id006066976923357061" id="id007804391116544438" class="input-output-copier">Copy</div></div><pre id="id006066976923357061">4 4 1 4 4 2 2 </pre></div></div></div>