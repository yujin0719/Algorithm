# 파일명 정렬
def solution(files):
    split_files = [[] for _ in range(len(files))]
    for idx, file in enumerate(files):
        num = 0
        tmp = ''
        while not file[num].isdigit() and num < len(file):
            tmp += file[num]
            num += 1
        split_files[idx].append(tmp)
        tmp = ''
        while num < len(file) and file[num].isdigit() and len(tmp) < 5 :
            tmp += file[num]
            num += 1
        
        split_files[idx].append(tmp)
        split_files[idx].append(file[num:])
    split_files.sort(key=lambda x : (x[0].upper(),int(x[1])))
    return ["".join(file) for file in split_files]