# 初衷

当初写下这些代码，是看过许多数据结构教程后变得愈发迷茫才开始的。

自己做过几年的Java开发，又接触过Scala、Python、Go，对写代码这件事并不是特别的害怕。但是一涉及到数据结构和C++，整个人好像什么都没开始过，所以觉得要去刷题，要使劲的刷题。

代码是在备考过程中完成的。每天最多能写3道，有时只能写2道，速度相对较慢。我认为，由于初学者的关系，速度慢这件事是很正常的。无论在入门的过程中遇到了什么样困难，想要退缩，请耐心请坚强。

# 代码思想来源于中国大学MOOC王道视频教程，部分有自己的提炼加工。

# C和C++之争

我使用了C++语言，把C++语言作为初选。

在struct和class中，我选择了struct。创建和释放要使用malloc和free。

class的构造函数对数据结构多余，对初学者不友好，引入不相关的概念，造成了学习困难。因而最后选择的是struct。我把两者最大的两个区别放在下面。

区别一：struct和class的访问控制权限默认是不同的。

struct默认是public。

class默认是private，因而要加public才能实现相同的效果。

```c
struct LNode {
    int    data;
    LNode* next;
};
```

等价于

```c++
class LNode {
public:
    int    data;
    LNode* next;
};
```

区别二：class是一个对象，它的创建会默认执行构造函数，它的释放会默认执行析构函数。而struct并不会。class是原汁原味C++，但是我们做算法题目，构造析构根本用不到。容易概念上产生误解，也很容易把代码写得比较复杂，单单析构函数笔者就看到过复杂的玩法。综合考虑，最后选择了struct。

```c
#include <iostream>
using namespace std;

struct LNode {
    int    data;
    LNode* next;
    LNode() {
        cout << "这是构造函数，(LNode*)malloc(sizeof(LNode));时不会默认执行" << endl;
    };
    ~LNode() {
        cout << "这是析构函数，free(node);时不会默认执行" << endl;
    };
};

int main(int argc, char** argv) {
    LNode* node = (LNode*)malloc(sizeof(LNode));
    node->data  = 100;
    cout << node->data << endl;
    free(node);
    cout << node->data << endl;
    return 1;
}
```

等价于

```C++
#include <iostream>
using namespace std;

class LNode {
public:
    int    data;
    LNode* next;
    LNode() {
        cout << "这是构造函数，new LNode();时会默认执行" << endl;
    };
    ~LNode() {
        cout << "这是析构函数，delete(node);时会默认执行" << endl;
    };
};

int main(int argc, char** argv) {
    LNode* node = new LNode();
    node->data  = 100;
    cout << node->data << endl;
    delete (node);
    cout << node->data << endl;
    return 1;
}
```

区别结束。

所有打印语句都使用了cout，没有在printf上做任何纠结。

同样的，我使用了C++的模板template，这使得我能够用出原汁原味的ElemType，C语言中就没有。

总而言之，我用了C++、struct、cout和template。

# 如何选择编译器和IDE

代码一开始是用Visual Studio跑通的，后来了解到Win10可以使用MSYS2和MinGW的集成环境跑GCC和Clang，于是用Win10搭配VSCode用GCC和Clang做了检查。最后在老笔记本刷Manjaro系统使用Clang+VSCode做了最后的检查（Linux环境下的警告会有轻微不同）。总而言之，我对警告做了全面彻底的消除。首先如果大家只是跑了代码就出现警告，情形炒鸡难看还会骂一声作者好水，影响观感。其次来看这份代码的同学也是初学者，很多情况下并不会消除这些问题，自己多一事帮大家少一事。把不爽降至最低。

# 心态

请大家抱着开放包容的心态看待这份代码，快乐拿分是王道。失误在所难免，出现问题或不足，一定要提Issue，尽量翔实。我会抱着学习的心态，去完善去满足，把这份代码做的越来越好。

# 生活可能不顺可能996，学业可能坎坷可能走不通，一定开放包容，接纳所有不愉快。希望大家都能在这一份代码中找到一些解决方法，能够放松平和，越来越好，在未来遇到更好的自己。



