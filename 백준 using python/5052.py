# 5052: 전화번호 목록
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

	def search_prefix(self,string):
		cur_node = self.head
		for c in string:
			cur_node = cur_node.children[c]
		if cur_node.children:
			return False
		else:
			return True
			
for _ in range(int(input())):
	n = int(input())
	trie = Trie()
	phone_list = []
	for _ in range(n):
		phone = input().rstrip()
		phone_list.append(phone)
		trie.insert(phone)
	flag = True
	phone_list.sort()
	for phone in phone_list:
		if not trie.search_prefix(phone):
			flag = False
			break
	if flag:
		print("YES")
	else:
		print("NO")

