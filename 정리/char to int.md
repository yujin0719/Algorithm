##### 문자열 string이 아닌 char 데이터 형을 int 변환하는 방법

```
char c ='2';
int num = c-'0';
```


- 주의 해야하는 것

```
char c ='2';
int num = int(c);

이렇게 하면 아스키코드 49가 출력된다.
```


