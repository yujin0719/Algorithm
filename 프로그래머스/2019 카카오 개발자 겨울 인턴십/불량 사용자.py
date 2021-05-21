# 불량 사용자
from itertools import permutations

def match(user,ban):
    for idx, b in enumerate(ban):
        if b == '*':
            continue
        if user[idx] != b:
            return False
    return True
        
def check(candidate_user,banned_id):
    for idx, user in enumerate(candidate_user):
        if len(banned_id[idx]) != len(user):
            return False
        if not match(user, banned_id[idx]):
            return False
    return True
        
    
def solution(user_id, banned_id):
    answer = []
    candidates = list(permutations(user_id,len(banned_id)))
    for candidate in candidates:
        if check(candidate,banned_id):
            candidate = tuple(sorted(candidate))
            answer.append(candidate)
    return len(set(answer))