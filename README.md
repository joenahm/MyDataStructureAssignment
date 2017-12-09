# My Data Structure Assignment
数据结构作业(My data structure assignment at college)

[![](https://img.shields.io/badge/%E4%B8%8A%E6%9C%BA%E6%8A%A5%E5%91%8A%E4%B8%8B%E8%BD%BD-%E6%9F%A5%E6%89%BE%E7%BB%BC%E5%90%88-blue.svg?style=for-the-badge)](https://github.com/joenahm/MyDataStructureAssignment/raw/master/5th/5th.zip)
[![](https://img.shields.io/badge/%E4%B8%8A%E6%9C%BA%E6%8A%A5%E5%91%8A%E4%B8%8B%E8%BD%BD-%E6%8E%92%E5%BA%8F%E7%BB%BC%E5%90%88-green.svg?style=for-the-badge)](https://github.com/joenahm/MyDataStructureAssignment/raw/master/6th/6th.zip)
## 作业:
> ### [#1st](1st)
- #### 名称（Name） 		: 顺序表和链表的应用（Application of Sequence List and Link List）
- #### 题目（Question）		: 
```
示例输入（input）: 2x^5-12x^3+3x^90
          	3-3x^90+5x^2-6x^3
示例输出（output）:  3+5x^2-18x^3+2x^5
提示: 识别输入多项式的系数和指数, 将其存入链表, 按指数排序, 然后相加。
```

- #### 主要文件（Main File）: polyPlus.cpp

> ### [#2nd](2nd)
- #### 名称（Name）		: 栈和队列的应用（Application of Stack and Queue）
- #### 题目（Question）	: 
```
输入表达式,包含加减乘除和括号运算;
利用运算符优先矩阵实现优先级比较;
利用运算符栈和操作数栈辅助实现运算;
运算数都是10以内数据。
A calculator supporting four arithmetic operations and parentheses.
例如：
输入（input）:2+3*4-5，输出（output）:9
```
- #### 主要文件（Main File）: functions.c

> ### [#3rd](3rd)
- #### 名称（Name）		： 二叉树的遍历和应用（Traverse and application of binary-tree）
- #### 题目（Question）： 
```
通过输入的字符串先根序创建二叉树(create a binary-tree in pre-order)；
中根序线索化二叉树(threading it in in-order)；
对线索二叉树进行中根序遍历(traverse it in in-order)。
```
- #### 主要文件（Main File）: tbt.c

> ### [#4th](4th)
- #### 名称（Name）		： 图的遍历和应用（Traverse and application of graph）
- #### 题目（Question）： 
```
利用邻接表存储，创建一个有向图，顶点存储字母（A、B、C……）
(create a digraph based on adjacency list, store letters A B C ... in it)；
实现图的广度优先遍历， 输出字符序列
(print the letters by using Breadth First Traversal)。
```
- #### 主要文件（Main File）: dg.c

> ### [#5th](5th)
- #### 名称（Name）		： 查找综合（Search Synthesis）
- #### 题目（Question）： 
```
输入查找表的所有数据，创建分块索引；
块间查找采用折半查找；
块内查找采用顺序查找；
输入待查找的数据，实现分块查找。
accomplish block search, using binary search between blocks, and using sequence search in block.
```
- #### 主要文件（Main File）: main.c

> ### [#6th](6th)
- #### 名称（Name）		： 排序综合（Sort Synthesis）
- #### 题目（Question）： 
```
输入待排序序列；
实现折半插入排序并输出;
实现快速排序并输出。 
accomplish binary insertion sort and quick sort.
```
- #### 主要文件（Main File）: binaryInsertion.c, quick.c

## 习题:
[点击跳转到习题文件夹](exercise) Click to jump to the exercise folder

- [2.11[2] 将元素插入到非递减顺序表中，且不破坏其顺序](exercise/2.11.2)

Insert data into an increment Sequence List without breaking its order

- [2.12 [3] 比较两个顺序表(*A,B*)的大小](exercise/2.12.3)

Compare 2 sqlists(*A,B*)

- [2.19 [3] 删除非递减有序的链表中，大于minv小于maxv区间里的元素](exercise/2.19.3)

Remove a interval between minv and maxv from a increment sllist

- [2.24 [4] 将两个**非递减有序**的链表sll1和sll2合并为一个**非递增有序**的链表sll3, 并且用原来sll1和sll2的空间来构造sll3](exercise/2.24.4)

Combine 2 link-lists sll1 and sll2, which are non-decreasing, to a non-increasing sll3 by using the space of sll1 and sll2

- [2.29 [5] 从顺序表A中删除所有同时也存在于顺序表B和顺序表C中的元素](exercise/2.29.5)

Remove all of the elements which are also present in sqlist B and sqlist C from sqlist A

- [3.19 [4] 括号匹配：()、[]和{}](exercise/3.19.4)

Brackets Matching : () , [] and {}

- [3.21 [3] 中缀表达式转逆波兰表达式](exercise/3.21.3)

Transform an expression from nifix form to reverse polish form 

- [3.28 [2] 实现只有尾指针的循环链队列的初始化、入队列和出队列](exercise/3.28.2)

Implement the **Initialization**, **Enqueue**, **Dequeue** of a link-list-based round-robin queue
