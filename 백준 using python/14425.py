# 14425: 문자열 집합
import sys
input = sys.stdin.readline

class Node:
	def __init__(self,key,data=None):
		self.key = key  # 한 글자
		self.data = data # 마지막 글자의 경우에만 값이 들어감
		self.children = {} # dict

class Trie:
	def __init__(self):
		self.head = Node(' ') # key = None

	def insert(self, string):
		cur_node = self.head
		for c in string:
			if c not in cur_node.children:
				cur_node.children[c] = Node(c)
			cur_node = cur_node.children[c]
		cur_node.data = string

	def search(self,string):
		cur_node = self.head
		for c in string:
			if c in cur_node.children:
				cur_node = cur_node.children[c]
			else:
				return False
		if cur_node.data != None:
			return True
			
n,m = map(int,input().split(" "))
trie = Trie()
answer = 0
for _ in range(n):
	s = input().rstrip()
	trie.insert(s)
for _ in range(m):
	s = input().rstrip()
	if trie.search(s):
		answer += 1
print(answer)