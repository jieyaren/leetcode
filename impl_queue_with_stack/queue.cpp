#include <stack>
#include <iostream>
#include <gtest/gtest.h>
using std::stack;
namespace test{
    
    template<typename T>
    class queue{
            using value_type = T;            
            stack<T> in;
            stack<T> out;
            void move_in_out()
            {
                if(out.empty())
                {
                    while(!in.empty())
                    {
                        out.push(in.top());
                        in.pop();
                    }
                }
            }
    public:
            value_type top()
            {
                if(out.empty())
                    move_in_out();
                if(out.empty())
                    return T();
                return out.top();
            }
            template<typename H,typename... Args>
            void push(H head, Args... rest)
            {
                push(head);
                push(rest...);
            }
            void push(const value_type& v)
            {
                in.push(v);
            }
            void pop()
            {
                if(out.empty())
                    move_in_out();
                if(out.empty())
                    return;
                out.pop();
            }
    };
}

//int main()
TEST(queue,stack)
{
    test::queue<int> q;
    q.push(1,2,3,4,5,8);    
    
    std::cout << q.top() << std::endl;
	ASSERT_EQ(q.top(),1);
    q.pop();
	
    std::cout << q.top() << std::endl;
	ASSERT_EQ(q.top(),2);
    q.pop();
	
    std::cout << q.top() << std::endl;
	ASSERT_EQ(q.top(),3);
    q.pop();
	
    std::cout << q.top() << std::endl;
	ASSERT_EQ(q.top(),4);
    q.pop();
	
    q.push(9,6);
	
    std::cout << q.top() << std::endl;
	ASSERT_EQ(q.top(),5);
    q.pop();
	
    std::cout << q.top() << std::endl;
    ASSERT_EQ(q.top(),8);
	q.pop();
	
    std::cout << q.top() << std::endl;
    ASSERT_EQ(q.top(),9);
	q.pop();
	
    std::cout << q.top() << std::endl;
    ASSERT_EQ(q.top(),6);
	q.pop();    
}