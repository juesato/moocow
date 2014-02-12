class Node:
	def __init__(self, value):
		self.right = None
		self.left = None
		self.val = value

class BST:
	def __init__(self):
		self.root = None
		self.size = 0

	def insert(self, value):
		if self.root == None:
			self.root = Node(value)
		else:
			child = self.root
			while child != None:
				cur = child
				if value > cur.val:
					child = cur.right
				elif value < cur.val:
					child = cur.left

			child = Node(value)
			if value > cur.val:
				cur.right = child
			elif value < cur.val:
				cur.left = child
		
	def inorder(self, cur):
		if cur.left != None:
			self.inorder(cur.left)
		print cur.val
		if cur.right != None:
			self.inorder(cur.right)

	def find(self, value):
		cur = self.root
		while cur != None:
			if value == cur.val:
				return cur
			elif value < cur.val:
				cur = cur.left
			elif value > cur.val:
				cur = cur.right
		return 0

	def delete(self, node, parent):
		print "HELP PLS", (node == node)
		if node.right == None and node.left == None:
			if node.val == parent.right.val:
				
		elif node.right == None and node.left != None:
			print "LOOK", node.val
			node.val = node.left.val
			print "NODE IS NOW", node.val
			self.delete(node.left)
			
		elif node.right != None and node.left == None:
			node.val = node.right.val
			self.delete(node.right)
		else:
			node.val = node.right.val
			self.delete(node.right)

	def deleteVal(self, value):
		par = self.root
		cur = self.root
		while 1:
			if par.right.val == value:

		return 0
		

mybst = BST()
mybst.insert(5)
mybst.insert(10)
mybst.insert(1)
mybst.insert(3)
mybst.insert(2)
mybst.insert(7)
mybst.insert(6)
mybst.inorder(mybst.root)
print mybst.find(4), mybst.find(7)
mybst.delete(mybst.find(10))
tmp = mybst.find(7)
print tmp.val, tmp.left.val, tmp.left.left.val, "HERE"
mybst.inorder(mybst.root)