问：c++中.h文件的产生原因、作用以及定义的方式是什么？
答：c++ .h .cpp 
编译器编译cpp文件时，会生成符号表 symbol table 找不到定义的符号会存放进去。链接时，编译器会在别的目标文件中寻找符号的定义
#include 预编译时将.h文件复制粘贴到.cpp文件中，对.cpp文件进行编译生成.o目标文件，通过声明的符号link相关定义执行。
c++不能重复定义避免冲突，
```c++
// main.h
extern int a;
void f();

//error
int a;
void f() {};
```
除了:
- const对象。默认没有extern声明，只在当前文件有效，对其他文件不可见。同理，static对象定义也可以。
- inline函数。编译器在遇到它的地方根据定义内联展开（没有链接）。内联函数可以在程序中定义多次，在一个.cpp文件中只出现一次，并且在所有的.cpp文件中，这个内联函数的定义是一样的。
- class定义。class包括数据成员（具体对象创建时候才会被定义，分配空间）和函数成员（需要在一开始就被定义，即类的实现）
一般在头文件中进行类的定义，在cpp文件中实现函数成员
直接将函数成员的定义写进类定义体中，编译器将视这个函数是内联的，是合法的。（在类定义的头文件内但不在类定义体中就不合法了）
（class会有链接吗？）

头文件中，通过 #define 定义一个名字，并且通过条件编译 #ifndef...#endif / #pragma once可以避免一个cpp文件中，头文件被多次包含的情况（类相互依赖）

```c++
 #include <iostream> //头文件
```

问：visual studio中c++如何向main函数传参？
答：1，生成可执行文件后命令行输入参数；2，configuration -> Debugging -> Command Arguments 调试传参

问：srand是用来干什么的？
答：srand、rand 伪随机数（每次生成一样的）srand ( ( unsigned int ) time ( NULL ) ); 种子

问：深拷贝和浅拷贝分别代表什么？
答：

问：代码在内存中是如何存放的？
答：
栈、 堆 static

DATA段存放初始化的全局变量和静态变量

BSS（blocked started by symbol）段存放未初始化或初始化为0的全局变量和静态变量。
程序执行前BSS段会清零，程序刚运作时完成唯一的一次初始化。 
https://www.runoob.com/w3cnote/cpp-static-usage.html

问：List()没有返回值，构造函数和析构函数默认就没有返回类型吗？
答：

问：class关键字和struct关键字有什么区别，为什么ListNode用struct而List用class？

答：可以使用关键字中的任意一个来定义类，唯一的区别是，struct和class的默认访问权限不太一样。
类可以在第一个访问说明符（public:）之前定义成员，对这种成员的访问权限依赖于类定义的方式。
使用struct关键字，定义在第一个访问说明符之前的成员是public的，// struct也可以使用访问说明符吗
相反，使用class关键字，则这些成员是private的。
通常我们希望定义的类的所有成员是public时，使用struct；相反使用class。

问：int(*p)(int, int);
调用函数是 p(1, 3) 还是 (*p)(1, 3)呢？

答：                                                                                                                                                                      ：
// 两个等价调用，将函数名作为值来使用时，该函数自动转化为指针
bool b1 = pf("hello", "goodbye");
bool b1 = (*pf)("hello", "goodbye");

http://c.biancheng.net/view/228.html

问：lambda表达式、匿名函数和inline函数有什么区别和联系？
答：尽管std::function非常有用，但是它也带来了性能损失。
这是因为为了隐藏包含的函数对象类型，提供通用的调用接口，
std::function使用了叫做type erasure的技术。
简单来说是通过虚函数的调用在运行期来决定具体调用，
因此编译器无法内联（inline）函数调用，也无法进行更多优化。

问：如何设计一个类？
答：类的基本思想是数据抽象和封装。数据抽象是一种依赖于接口和实现
分离的编程（以及设计）技术。类的接口包括用户所能执行的操作；
类的实现包括类的数据成员、负责接口实现的函数体以及定义类所需
的各种私有函数。
封装实现了类的接口和实现的分离。封装后的类隐藏了它的实现细节，
也就是说，类的用户只能使用接口而无法访问实现部分。
类想要实现数据抽象和封装，需要首先定义一个抽象数据类型，在抽象
数据类型中，由类的设计者考虑类的实现过程，使用该类的程序员则只
需要抽象地思考类型做了什么，而无须了解类型的工作细节。

既要有直观易于使用的接口，也必须具备高效的实现过程。

列表接口包括的操作：

问：`Rank size() const { return _size; }`成员函数是如何获得_size数据成员的？
答：调用对象的成员函数`list.size()`时，成员函数通过一个名为this的额外的隐
式参数（常量指针，指针中保存的地址不允许被修改）来访问调用它的对象。编译器负责把list的地址传递给size的隐
式形参this，可以等价看成编译器将调用过程重写成了如下的形式：
List::size(&list); // size在内存中是不是只存了一份，所有对象调用的都是同一个函数
成员函数内部，我们可以直接调用该函数的对象的成员，而无需通过成员访问运算符
当size使用_size时，隐式使用this指向的成员，和书写成this->_size获得的结果
一样。

问：`T& operator[] ( Rank r ) const;`中const是什么含义？
答：const的作用是修改隐式this指针的类型。默认情况下const是指向类类型非常
量版本的常量指针，List *const。默认情况下无法把this绑定到常量对象上，导致
我们不能在常量对象上调用普通的成员函数。this是隐式的不会出现在参数列表，因
此C++允许将const关键字放到成员函数的参数列表之后。像这样使用const的成员函
数被称为常量成员函数。可以想象为：
T& List::operator[] (const List *const this, Rank r) // this是常量指针，同时也指向常量
常量对象及其指针，引用只能调用常量成员函数

问：解读`int *const curErr = &errNumb; // <-`
答：curErr本身是一个常量对象，它是一个指针，指向了一个int对象。

问：如何使代码改动变成可靠、有效的？
答：两个问题：可靠的代码改动和有效的代码改动。单元测试《修改代码的艺术》

问：易于读懂的代码
答：自解释

问：printf ("searching for "); print (e); printf (" :\n");
答：

问：递归函数是如何运行的
答：The key point to remember is when a function returns, it returns to wherever it was called from. Recursive functions are no different in that fundamental respect. Recursive function calls work exactly the same way.

问：static关键字是什么意思
答：