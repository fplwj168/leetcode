#include <iostream>
#include <stack>
using namespace std;

//方法2：时间复杂度为O（1）--最好方法--辅助栈
#define INT_MAX 10//防止栈为空，赋值最大值
class MinStack{
  public:
    stack<int>stack1,min_stack;
    MinStack(){
      min_stack.push(INT_MAX);
    }
    void push(int x){
      stack1.push(x);
      min_stack.push(std::min(min_stack.top(),x)); //插入最小栈栈顶元素和x中较小的一个
    }
    void pop(){
      stack1.pop();
      min_stack.pop();
    }
    int top(){
      return stack1.top();
    }
    int min(){
      return min_stack.top();
    }
};
/*
//方法1：原始写法
#define INT_MAX 10
class MinStack{
  public:
    stack<int>stack1,min_stack;

    MinStack(){
      min_stack.push(INT_MAX);
    }
    void push(int x){
      stack1.push(x);
      if(min_stack.empty()||stack1.top()<min_stack.top()){//判断最小栈是否为空或者主栈栈顶元素小于最小栈栈顶元素
        min_stack.push(stack1.top());//插入主栈元素到最小栈
      }
    }
    void pop(){
      if(stack1.top()==min_stack.top()){//若栈顶元素相等则删除 
        stack1.pop();
        min_stack.pop();
      }
    }
    int top(){
      return stack1.top();
    }
    int min(){
      return min_stack.top();
    }
};
*/
