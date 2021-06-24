#[1차] 비밀지도
def solution(n, arr1, arr2):
    answer = []
    for a1,a2 in zip(arr1,arr2):
        a1 = list(bin(a1)[2:].rjust(n,'0'))
        a2 = list(bin(a2)[2:].rjust(n,'0'))
        union = [" " if a == '0' and b == '0' else "#" for a,b in zip(a1,a2)]
        answer.append("".join(union))
    return answer