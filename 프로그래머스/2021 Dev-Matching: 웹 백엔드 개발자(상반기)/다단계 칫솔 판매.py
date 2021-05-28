# 다단계 칫솔 판매
import math
def solution(enroll, referral, seller, amount):
    answer = []
    tree = dict()
    result = dict()
    for e,r in zip(enroll, referral):
        tree[e] = r
        result[e] = 0
    for s,a in zip(seller,amount):
        cur_seller = s
        cur_price = a*100
        while True:
            if cur_seller == '-':
                break
            if cur_price*0.1 < 1:
                result[cur_seller] += cur_price
                break
            result[cur_seller] += math.ceil(cur_price*0.9)
            cur_price = int(cur_price*0.1)
            cur_seller = tree[cur_seller]
    for r in result:
        answer.append(result[r])
    return answer