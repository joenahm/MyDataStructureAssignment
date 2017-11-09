# 2.12 [3]
比较两个顺序表(*A,B*)的大小，比较算法为：<br>
Compare 2 sqlists(*A,B*), algorithm :

```
（1）
从两顺序表第一个位置相同、值不同的元素开始构建子表(SA,SB)。
create 2 sublists(SA,SB) from these 2 sqlists,
which begin with the first position-same but value-different elements.

（2）
如果两子表均为空，则两顺序表相等；
if SA = SB = empty, then they are the same;

如果SA为空，SB不为空 或者 SA,SB均不为空且SA的首元小于SB的首元，则SA<SB；
if SA = empty but SB != empty, OR SA,SB != empty and the first elements of them, SA's < SB's,
then SA<SB;

否则，SA>SB；
else SA>SB;
```