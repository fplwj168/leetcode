#include <iostream>
#include <stack>
#include <queue>
//用2个栈实现一个队列，队列先进先出，栈先进后出，一个栈作为插入，一个栈作为删除
//第一个栈的底部元素是最后插入的元素。
using namespace std;

class CQueue{
  stack<int>stack1,stack2;//定义2个栈
  public:
  CQueue(){
    while(!stack1.empty())//判断栈1和栈2是否为空，不为空，pop删除
    {
      stack1.pop();
    }
    while(!stack2.empty())
    {
      stack2.pop();
    }
  }
  void appendTail(int value)
  {
    stack1.push(value);//添加push元素value
  }
  int deleteHead()
  {
    if(stack2.empty())//如果栈2为空
    {
      while(!stack1.empty())//栈1不为空
      {
        stack2.push(stack1.top());//则删除栈1元素，压入push栈2
        stack1.pop();//清空栈1
      }
    }
    if(stack2.empty())//判断栈2为空，没元素了。则返回-1
    {
      return -1;
    }
    else{
      int zhanding=stack2.top();//将栈2的栈顶元素返回
      stack2.pop();//清空栈2
      return zhanding;
    }
  }

};
