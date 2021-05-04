# 4358: 생태학
import sys
input = sys.stdin.readline
from collections import defaultdict

dict = defaultdict(int)
total = 0 
while True:
	tree = input().rstrip()
	if not tree:
		break
	dict[tree] += 1
	total += 1
dict = sorted(dict.items())
for tree,cnt in dict:
	print('%s %.4f' %(tree, cnt/total*100))
