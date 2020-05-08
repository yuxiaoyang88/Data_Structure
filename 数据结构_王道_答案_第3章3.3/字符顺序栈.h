typedef struct {
    char data[20];
    int  top;
} CharSqStack;
//初始化
void CharSqStack_Init(CharSqStack& stack);
//判栈空
bool CharSqStack_Empty(CharSqStack& stack);
//判栈满
bool CharSqStack_Overflow(CharSqStack& stack);
//进栈
bool CharSqStack_Push(CharSqStack& stack, char x);
//出栈
bool CharSqStack_Pop(CharSqStack& stack, char& x);
//读取栈顶元素
bool CharSqStack_GetTop(CharSqStack& stack, char& x);
//打印栈
void CharSqStack_Show(CharSqStack& stack);