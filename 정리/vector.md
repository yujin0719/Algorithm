# vector container

> STL 컨테이너: vetor, map, set, stack


### 1. vector container란?

- vector contianer는 동적배열이다.
- 배열처럼 각각의 원소가 메모리 상에서 연속저긍로 존재한다. -> 원소를 참조할 때 iterator(반복자)를 이용할 수 있다. 
- 배열과는 달리 스스로 공간을 할당하여 크기를 변화시킬 수 있다. 

<hr> 

### 2. vector 생성 

- 선언 : <strong> std::vector<[data type]>[변수이름] </strong>

      vector<int> v;
      
      1. vector<int> v(3);  
          - 원소로 0을 3개 가지는 vector 생성
      2. vector<int> v(3,1); 
          - 원소로 1을 3개 가지는 vector 생성
      3. vector<int> v2(v1); 
          - v2는 v1을 복사
      
<hr> 

### 3. vector의 멤버함수 

 함수 | 설명 
---|:---
v[idx]|idx번째 원소 참조
v.front()|첫번째 원소 참조
v.back()|마지막 원소 참조
v.begin()|첫번째 원소 가리킴(iterator와 사용)
v.end()|마지막 원소 가리킴(iterator와 사용)


 함수 | 설명 
---|:---
v.size()|원소의 개수 return
v.capacity()|할당된 공간의 크기 return
v.push_back(a)|마지막 원소 뒤에 원소 a를 삽입
v.pop_back()|마지막 원소 제거
v.clear()|모든 원소 제거 <br> 원소만 제거하고 메모리는 남아있다. <br> size만 줄어들고 capacity는 유지
v.empty()|vector가 비어있으면 true 리턴


 함수 | 설명 
---|:---
v.insert(a,b)|a번째 위치에 b를 삽입
v.insert(a,b,c)|a번째 위치에 b개의 c를 삽입

* vector는 뒤에서만 원소를 추가할 수 있기 때문에 insert에 index를 0로 줘 앞에 추가할 수 있다. 

<hr>

### 4. vector 중복제거 : unique, erase 활용 
- unique는 algorithm 헤더에 포함되어 있다.
- unique 함수는 vector에서 중복되지 않는 원소들을 앞에서부터 채워나가는 함수이다.
- erase 함수는 vector에서 특정 원소를 삭제하는 함수이다.
- v.erase(v.begin()+s, v.begin()+e) :  s부터 e-1까지의 원소가 삭제

```
v.erase(unique(v.begin(),v.end()),v.end());
```

 
