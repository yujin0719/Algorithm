# String Class
- stl에서 제공하는 string class는 문자열의 크기를 동적으로 변경할 수 있다. 
- string은 배열처럼 사용한다. 

#### 1. 입/출력 : cin,cout,getline (scanf,printf는 사용불가)
```
string str;

cin >> str;           // 스페이스가 들어간 문자열의 경우, 첫번째 것만 입력받음
cout << str;

getline(cin,str);     // 스페이스가 있어도 전체 한줄을 입력받음
cout << str;

getline(cin,str,'a'); // a 문자 앞까지만 입력받음 
cout << str;
```

#### 2. 비교연산
- 문자열 같은지 비교 : "==" 연산자
- 사전순서 비교 : "<" or ">" 연산자 / 문자 전체를 비교한 결과가 나옴
- compare 함수 : a.compare(b); / 문자열이 같으면 0, a가 앞서면 -1, b가 앞서면 1반환

#### 3. 메소드 

메소드명 | 설명 
---|---
length()|문자열 길이반환
size()|문자열 길이반환
capacity()|사용중인 메모리 크기 반환

<hr>

메소드명 | 설명 | 특징
---|---|---
append()|문자열 연결|1. append()는 인자로 char를 사용할 수 없다. <br> 2. char를 더해주고 싶은 경우 "+" 연산을 이용
insert()|문자열 삽입|`str.insert(2,"bbb");` index가 2인 위치에 있는 문자 앞에 삽입
replace()|문자열 대체|`str.replace(2,3,"bbb");` index가 2인 위치에 있는 문자부터 ~ 3개의 문자를 "bbb"로 대체
erase()|부분 지우기|`str.erase(1,4);` index 1~4인 부분을 지움
clear()|전체 지우기|
substr()|문자 자르기|`str.substr(2);` index 2의 위치부터 끝까지 문자를 반환
find()|1. 문자가 존재하는 경우, 해당 위치의 index 반환받기<br>2. 문자열이 존재하는 경우, 문자열이 시작되는 index 반환받기<br>3. 존재하지 않으면 -1을 반환받음|

<hr>

메소드명 | 설명 | 특징
---|---|---
stoi()|1. string->int로 변환<br>2. 반드시 string형을 넘겨야함, char은 안됨|`stoi(str);`
to_string()|int->string로 변환|`str = to_string(a);`
isdigit()|숫자판별|
isalpha()|영어판별|

<hr>

메소드명 | 설명 
---|---
pop_back() | 맨 뒤의 문자를 pop
push_back() | 맨 뒤에 push
front() | 맨 앞의 문자 반환
back() | 맨 뒤의 문자 반환

- pop,push,front,back과 같은 메소드가 코딩테스트에서 유용하게 사용될 수 있다. 

 
