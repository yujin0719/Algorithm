# Level3: 가장 긴 팰린드롬
def solution(s):
    l = len(s)
    for i in range(l,1,-1):
        arr = [s[x:i+x] for x in range(len(s)+1-i)]
        rev = [x[::-1] for x in arr]
        check = False
        for j in range(len(arr)):
            if arr[j] == rev[j]:
                check = True
                break
        if check:
            return i
    return 1