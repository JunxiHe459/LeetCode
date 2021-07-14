# Merge Sorted Array

做题前：

1. Easy难度
2. 不能开辟额外的空间，in place ！！！



做题中：

1. 因为两个vector都是从小到大排列的，本能的想从小到大merge，未成功。
2. 改变思路，从大到小merge。找两个vector中的最后一位，再排到nums1的最后面。



做题后：

1. 从小到大merge会存在占用nums1储存的元素的位置，不方便。
2. 从大到小则可以直接排，因为最后面都是空（0）。
