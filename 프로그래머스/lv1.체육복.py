# Level1: 체육복
def solution(n, lost, reserve):
    for student in range(1,n+1):
        if student in lost and student in reserve:
            lost.remove(student)
            reserve.remove(student)
    for student in range(1,n+1):
        if student in lost and student-1 in reserve:
            lost.remove(student)
            reserve.remove(student-1)
        elif student in lost and student+1 in reserve:
            lost.remove(student)
            reserve.remove(student+1)
    return n - len(lost)