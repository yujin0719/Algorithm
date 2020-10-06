#  18310: 안테나

n = int(input())
numbers = list(map(int,input().split()))
numbers.sort()

print(numbers[(n-1)//2])
