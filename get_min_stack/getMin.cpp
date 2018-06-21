//特殊的栈，pop push getmin O1
#include <stack>
#include <cassert>
#include <iostream>
#include <gtest/gtest.h>

using std::stack;
using std::cout;

template<typename T>
class stack_o1{

	stack<T> current_;
	stack<T> min_;
	
public:
	size_t size() const
	{
		return current_.size();
	}
	void pop()
	{
		if (current_.empty())
		{
			assert(0);
			return;
		}
		current_.pop();
		min_.pop();
	}
	T top() const
	{
		if (current_.empty())
		{
			assert(0);
			return 0;
		}
		return current_.top();
	}
	T getMin() const
	{
		if (current_.empty())
		{
			assert(0);
			return 0;
		}
		return min_.top();
	}
	
	template<typename H,typename ...Args>
	void push(H head, Args... rest)
	{
		push(head);
		push(rest...);
	}
	void push(const T& v)
	{
		current_.push(v);
		
		if (min_.empty())
		{
			min_.push(v);
			return;
		}
		
		if(min_.top()>v)
		{
			min_.push(v);
		}
		else
		{
			min_.push(min_.top());
		}
	}	
};
void print()
{
	cout<<"\n";
}

template <typename H,typename ...Args>
void print(H head, Args... rest)
{
	cout<<head<<" ";
	print(rest...);
}

//int main()
TEST(stack,o1getmin)
{
	stack_o1<int> s;
	
	s.push(4,5,6,7,4,3,2,1);
	print(4,5,6,7,4,3,2,1);
	ASSERT_EQ(s.getMin(),1);
	s.pop();
	ASSERT_EQ(s.getMin(),2);
	s.pop();
	ASSERT_EQ(s.getMin(),3);
	s.pop();
	ASSERT_EQ(s.getMin(),4);
	s.pop();
	ASSERT_EQ(s.getMin(),4);
	s.pop();
	ASSERT_EQ(s.getMin(),4);
	s.pop();
	ASSERT_EQ(s.getMin(),4);
	s.pop();
	ASSERT_EQ(s.getMin(),4);
	s.pop();
}