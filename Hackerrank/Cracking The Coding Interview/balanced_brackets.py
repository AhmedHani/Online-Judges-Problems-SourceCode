# author: Ahmed Hani


class Node:
    def __init__(self, data=None):
        self.data = data
        self.next = None


class Stack:
    def __init__(self):
        self.__head = None

    def get_head(self):
        return self.__head

    def is_empty(self):
        return self.__head is None

    def push(self, data):
        if self.is_empty():
            self.__head = Node(data)
        else:
            new_node = Node(data)

            new_node.next = self.__head
            self.__head = new_node

    def top(self):
        if self.is_empty():
            print("Stack is Empty!")

            return -1
        else:
            return self.__head.data

    def pop(self):
        if self.is_empty():
            print("Stack is Empty!")

            return -1
        else:
            front_value = self.__head.data

            if self.__head.next is not None:
                new_head = self.__head.next
                del self.__head
                self.__head = new_head
            else:
                self.__head = None

            return front_value

    def __len__(self):
        if self.is_empty():
            print("Queue is Empty!")

            return -1
        else:
            counter = 1
            temp = self.__head

            while temp.next is not None:
                counter += 1
                temp = temp.next

        return counter

def is_matched(expression):
    stack = Stack()
    mapping = {'(': ')', '{': '}', '[': ']'}

    for char in expression:
        if char in mapping.keys():
            stack.push(mapping[char])
        else:
            if stack.is_empty():
                return False
            if stack.top() != char:
                return False
            stack.pop()

    return stack.is_empty()

t = int(input().strip())
for a0 in range(t):
    expression = input().strip()
    if is_matched(expression) == True:
        print("YES")
    else:
        print("NO")
