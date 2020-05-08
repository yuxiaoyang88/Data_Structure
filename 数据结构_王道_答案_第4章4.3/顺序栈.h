typedef struct {
    int data[20];
    int top;
} SqStack;

//初始化
void SqStack_Init(SqStack& sqstack);
//判栈空
bool SqStack_Empty(SqStack& sqstack);
//判栈满
bool SqStack_Overflow(SqStack& sqstack);
//进栈
bool SqStack_Push(SqStack& sqstack, int x);
//出栈
bool SqStack_Pop(SqStack& sqstack, int& x);
//读取栈顶元素
bool SqStack_GetTop(SqStack& sqstack, int& x);
//打印栈
void SqStack_Show(SqStack& sqstack);