# 기둥과 보 설치
def check(answer):
    for x,y,a in answer:
        if a == 0: # 기둥이 설치
    # 바닥위, 보의 한쪽 끝부분 위, 다른 기둥위
            if y == 0 or [x-1,y,1] in answer or [x,y,1] in answer or [x,y-1,0] in answer:
                continue
            return False
        elif a == 1:
      # 한쪽 끝부분이 기둥위, 양족 끝부분이 다른보와 동시에 연결
            if [x,y-1,0] in answer or [x+1,y-1,0] in answer or ([x-1,y,1] in answer and [x+1,y,1] in answer):
                continue
            return False
    return True

def solution(n, build_frame):
    answer = []
    for x,y,a,b in build_frame:
        if b == 0:  # 삭제할 경우
            answer.remove([x,y,a])
            if not check(answer):
                answer.append([x,y,a])
        if b == 1:
            answer.append([x,y,a])
            if not check(answer):
                answer.remove([x,y,a])
    return sorted(answer)
