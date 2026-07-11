<h2><a href="https://codeforces.com/contest/1776/problem/L" target="_blank" rel="noopener noreferrer">1776L — Controllers</a></h2>

| | |
|---|---|
| **Difficulty** | 1500 |
| **Language** | C++23 (GCC 14-64, msys2) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 1776L](https://codeforces.com/contest/1776/problem/L) |

## Topics
`binary search` `math`

---

## Problem Statement

<div class="header"><div class="title">L. Controllers</div><div class="time-limit"><div class="property-title">time limit per test</div>2 seconds</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>You are at your grandparents' house and you are playing an old video game on a strange console. Your controller has only two buttons and each button has a number written on it.</p><p>Initially, your score is $$$0$$$. The game is composed of $$$n$$$ rounds. For each $$$1\le i\le n$$$, the $$$i$$$-th round works as follows.</p><p>On the screen, a symbol $$$s_i$$$ appears, which is either $$$\texttt{+}$$$ (<span class="tex-font-style-it">plus</span>) or $$$\texttt{-}$$$ (<span class="tex-font-style-it">minus</span>). Then you must press one of the two buttons on the controller <span class="tex-font-style-bf">once</span>. Suppose you press a button with the number $$$x$$$ written on it: your score will increase by $$$x$$$ if the symbol was $$$\texttt{+}$$$ and will decrease by $$$x$$$ if the symbol was $$$\texttt{-}$$$. After you press the button, the round ends. </p><p>After you have played all $$$n$$$ rounds, you win if your score is $$$0$$$.</p><p>Over the years, your grandparents bought many different controllers, so you have $$$q$$$ of them. The two buttons on the $$$j$$$-th controller have the numbers $$$a_j$$$ and $$$b_j$$$ written on them. For each controller, you must compute whether you can win the game playing with that controller.</p></div><div class="input-specification"><div class="section-title">Input</div><p>The first line contains a single integer $$$n$$$ ($$$1 \le n \le 2\cdot 10^5$$$) — the number of rounds.</p><p>The second line contains a string $$$s$$$ of length $$$n$$$ — where $$$s_i$$$ is the symbol that will appear on the screen in the $$$i$$$-th round. It is guaranteed that $$$s$$$ contains only the characters $$$\texttt{+}$$$ and $$$\texttt{-}$$$.</p><p>The third line contains an integer $$$q$$$ ($$$1 \le q \le 10^5$$$) — the number of controllers.</p><p>The following $$$q$$$ lines contain two integers $$$a_j$$$ and $$$b_j$$$ each ($$$1 \le a_j, b_j \le 10^9$$$) — the numbers on the buttons of controller $$$j$$$. </p></div><div class="output-specification"><div class="section-title">Output</div><p>Output $$$q$$$ lines. On line $$$j$$$ print $$$\texttt{YES}$$$ if the game is winnable using controller $$$j$$$, otherwise print $$$\texttt{NO}$$$.</p></div><div class="sample-tests"><div class="section-title">Examples</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id007928536162535936" id="id006411688125014259" class="input-output-copier">Copy</div></div><pre id="id007928536162535936">8
+-+---+-
5
2 1
10 3
7 9
10 10
5 3
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id009082302594368427" id="id004333826431820761" class="input-output-copier">Copy</div></div><pre id="id009082302594368427">YES
NO
NO
NO
YES
</pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id008992045749100044" id="id003586476241516562" class="input-output-copier">Copy</div></div><pre id="id008992045749100044">6
+-++--
2
9 7
1 1
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id00025053407532073302" id="id003726637164190907" class="input-output-copier">Copy</div></div><pre id="id00025053407532073302">YES
YES
</pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id005624725251871638" id="id006066871031012535" class="input-output-copier">Copy</div></div><pre id="id005624725251871638">20
+-----+--+--------+-
2
1000000000 99999997
250000000 1000000000
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id005220894923753033" id="id005663231278765242" class="input-output-copier">Copy</div></div><pre id="id005220894923753033">NO
YES
</pre></div></div></div><div class="note"><div class="section-title">Note</div><p>In the <span class="tex-font-style-bf">first sample</span>, one possible way to get score $$$0$$$ using the first controller is by pressing the button with numnber $$$1$$$ in rounds $$$1$$$, $$$2$$$, $$$4$$$, $$$5$$$, $$$6$$$ and $$$8$$$, and pressing the button with number $$$2$$$ in rounds $$$3$$$ and $$$7$$$. It is possible to show that there is no way to get a score of $$$0$$$ using the second controller.</p></div>