def solution(phone_book):
    phone_book.sort()
    for idx in range(len(phone_book)-1):
        next_phone = phone_book[idx+1]
        if phone_book[idx] == next_phone[:len(phone_book[idx])]:
            return False
    return True