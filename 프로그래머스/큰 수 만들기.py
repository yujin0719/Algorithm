 # 큰 수 만들기
 # greedy 유형 

def solution(number, k):
    result = []
    for num in number:
        while len(result) > 0 and result[-1] < num and k > 0:
            k -= 1
            result.pop()
        result.append(num)
    if k > 0:
        result = result[:-k]
    answer = ''.join(result)
    return answer
