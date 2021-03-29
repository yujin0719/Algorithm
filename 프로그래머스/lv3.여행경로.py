# Level3 : 여행경로
def solution(tickets):
    stack = ['ICN']
    dict = {}
    for ticket in tickets:
        dict[ticket[0]] = dict.get(ticket[0], []) + [ticket[1]]
    for d in dict:
        dict[d].sort(reverse = True)
    path = [] 
    while stack:
        top = stack[-1]
        if top in dict and dict[top]:
            stack.append(dict[top].pop())
        else:
            path.append(stack.pop())
    return path[::-1]