class Node:
    def __init__(self, value):
        self.val = value
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def append(self, value):
        new = Node(value)
        if self.head == None:
            self.head = new
        if self.tail != None:
            self.tail.next = new
        self.tail = new

    def delete(self, index): #removes node at index i
        cur = self.head
        for i in range(index-1):
            cur = cur.next
        if index == 0:
            self.head = self.head.next
            if self.head == None:
                self.tail = None
        else:
            cur.next = cur.next.next
            if cur.next == None:
                self.tail = cur

    def print_list(self):
        cur = self.head
        while cur != None:
            print cur.val
            cur = cur.next

    def reverse(self):
        cur = self.head.next
        self.head.next = None
        self.tail = self.head
        oldprev = self.head
        while cur != None:
            oldnext = cur.next
            cur.next = oldprev
            oldprev = cur
            cur = oldnext
        self.head = oldprev

ll = LinkedList()
ll.append(52)
ll.append(33)
ll.append(2)
print "PRINT"
ll.print_list()
ll.reverse()
print "PRINT"
ll.print_list()
ll.delete(1)
print "PRINT"
ll.print_list()
ll.delete(0)
print "PRINT"
ll.print_list()