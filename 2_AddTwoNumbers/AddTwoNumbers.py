# Definition for singly-linked list.
# class ListNode(object):               #链表的定义
#     def __init__(self, x):
#         self.val = x
#         self.next = None
                                        #总结：已有链表需要提取将l指向l.next后移。
                                        #创建链表需要l.next指向新创建的l。
class Solution(object):
    def addTwoNumbers(self, l1, l2):        #从高位相加，进位保留下来
        carry = 0   ;                        #设置进位标志
        l3 = ListNode(0);
        l4 = l3;                               #创建l4存储最后结果
        l5 = l4;                                #15指向14头，用来返回结果
        while l1 or l2 or carry:

            if l1:
                carry += l1.val;
                l1 = l1.next;
            if l2:
                carry += l2.val;
                l2 = l2.next;
            carry , val = divmod(carry,10);         #求余，carry进位，val当前值

            l3 = ListNode(val);         #create a new listnode
            l4.next  = l3;              #l4.next 指向 新创建的l3节点保存最后数据
            l4 = l4.next ;              #14指向14.next 创建新节点循环
        return l5.next;




         """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
