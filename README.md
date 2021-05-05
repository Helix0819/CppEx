# CppEx



白老师的课程实验
白忠建老师倒真是个有趣的灵魂！！！



## 实验题目：

​	一位小学教师Ken 希望完成这样的任务：针对于小学生正在学习四边形(quadrangle)的特性，编写一个小软件，能够随机在屏幕上显示矩形 (rectangle)、正方形(square) 、平行四边形(parallelogram)、梯型(trapezoid)和菱形(diamond)五种形体之一，同时显示该形体的轮廓形状和关键数据（随机产生），学生根据给出的关键数据计算形体的面积并输入，软件判断其结果的正确性。在学习过程中，软件记录产生的每一个形体，在学生选择不再继续后，将其学习的过程重放一遍（及显示所有学过的形体数据、形状及结果），用以重温，加深印象。
​	根据上述描述，编写程序，完成Ken 老师的需求。

## 编码要求：

**1） 理清形体概念之间的关系，然后用（多）继承来实现这些关系。**
	*提示：在一般的认知中，平行四边形和梯形是同一级别的，矩形和菱形是特殊的平行四边形，正方形即是矩形，也是菱形。*
**2） 使用抽象类来表示顶层概念。**
**3） 矩形、平行四边形用长和高表示；正方形用边长表示；梯形用两条平行边长和高表示；菱形用两条对象线长表示。要求画出继承链的类图。**
*建议：所有的形体中，边长都用width （注意：梯形多了一条平行边 width2 ），高用 height 表示。对于菱形， width 和 height 分别对应两条对角线。*
**4） 使用链表模板来存储数据。请考虑要存储何种数据（并通过这种安排来体现多态）。**
**5） 为链表模板设计迭代器。代码中，通过迭代器来遍历链表。**
**6） 必须体现多态。请考虑如何做到这一点。**
**7） 除了最基础的类型（例如string），不能使用任何现有的STL容器及其相关类。这意味着，链表及其迭代器需自行编码实现。**
**8） 完成的系统采用多源文件模式，使用make工具来建造工程，为工程建造编写Makefile。**
*提示：如果你使用某种如果你使用某种IIDEDE工具，那么在完成调试后也编写一个工具，那么在完成调试后也编写一个Makefile并用并用make来建造。来建造*

## 期望输出：

```
Practicing. Input negative value to halt
trapezoid: width1=5, width2=5, height=5, area=?25
Your answer is correct
square: width=2, area=?4
Your answer is correct
parallelogram: width=4, height=4, area=?16
Your answer is correct
parallelogram: width=9, height=9, area=?15
Your answer is incorrect
diamond: diagnal1=1, diagnal2=1, area=?23
Your answer is incorrect
square: width=7, area=?22
Your answer is incorrect
trapezoid: width1=5, width2=5, height=5, area=?-1
Reviewing...
trapezoid: width1= 5, width2=5, height=5, area=25, answer=25 V
square: width= 2, area=4, answer=4 V
parallelogram: width= 4, height=4, area=16, answer=16 V
parallelogram: width= 9, height=9, area=81, answer=15 X
diamond: diagnal1= 1, diagnal2=1, area=0.5, answer=23 X
square: width= 7, area=49, answer=22 X
Total: 6, Correct: 3
```

## 目前进展：

​	目前只是初步完成了输出要求，链表代码使用了白老师上课时提供的略做了修改，但是遍历链表没有使用迭代器，会在后面进行改进。

