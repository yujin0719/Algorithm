# Level3: 이중우선순위큐 (min,max로 해결)
def solution(operations):
    answer = []
    numbers = []
    for operation in operations:
        command,number = operation.split(" ")
        if command == "I":
            numbers.append(int(number))
        elif len(numbers) == 0:
            continue
        elif number.isdigit():
            numbers.remove(max(numbers))
        else :
            numbers.remove(min(numbers))
    answer = [max(numbers) if len(numbers) > 0 else 0, min(numbers) if len(numbers) > 0 else 0]
    return answer