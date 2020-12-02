# 15-Puzzle-Problem-Solution-Using-BackTracking
 There are 2 ways to solve this problem for the user. Either
he can opt for the computer to solve it or he can solve it
manually. When he opts for a computer defined solution,
backtracking algorithm comes into play.

•The backtracking algorithm enumerates a set of partial
candidates that, in principle, could be completed in
various ways to give all the possible solutions to the
given problem. The completion is done incrementally, by
a sequence of candidate extension steps.

•Conceptually, the partial candidates are represented as
the nodes of a tree structure, the potential search tree.
Each partial candidate is the parent of the candidates
that differ from it by a single extension step; the leaves of
the tree are the partial candidates that cannot be
extended any further.

•The backtracking algorithm traverses this search tree
recursively, from the root down, in depth first order. At
each node c, the algorithm checks whether c can be
completed to a valid solution. If it cannot, the whole sub
tree rooted at c is skipped (pruned). Otherwise, the
algorithm (1) checks whether c itself is a valid solution,
and if so reports it to the user; and (2) recursively
enumerates all sub trees of c. The two tests and the
children of each node are defined by
user user-given procedures.

•Therefore, the actual search tree that is traversed Therefore, the actual search tree that is traversed by the algorithm is only a part of the potential tree. by the algorithm is only a part of the potential tree. The total cost of the algorithm is the number of The total cost of the algorithm is the number of nodes of the actual tree times the cost of obtaining nodes of the actual tree times the cost of obtaining and processing each node. This fact should be and processing each node. This fact should be considered when choosing the potential search tree considered when choosing the potential search tree and implementing the pruning test. and implementing the pruning test.

**DEMO IMAGES OF CODE EXECUTION**

![](https://github.com/kartik0406/15-Puzzle-Problem-Solution-Using-BackTracking/blob/main/img1.PNG)
![](https://github.com/kartik0406/15-Puzzle-Problem-Solution-Using-BackTracking/blob/main/img2.PNG)
