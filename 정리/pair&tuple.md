# Pair & Tuple

### 1. pair (utility 헤더)

- 두개의 변수나 속성을 쌍을 이뤄서 사용해야 할 경우 구조체를 선언해서 사용하는데, 이 때 pair을 사용하면 간편하다.

- pair간의 크기 비교에서는 첫번째 속성을 비교하고, 값이 동일하면 두번째 속성으로 비교한다.

```
pair<int,int> p1;   // first, second 모두 0
pair<char,int> p2 = make_pair('c',3);
pair<int,double> p3 = {3,5}  // c++11 부터 지원
pair<int,int> p4[100];
```

```
pair<int,int> p = {1,2}
cout << p.first;  // 1
cout << p.second;  // 2
```


### 2. tuple (tuple 헤더) : c++11이상 버전에서 지원

- 함수에서 세 개 이상의 변수를 return하거나, 세 개 이상의 속성을 계속 사용해야할 때 tuple을 사용하면 간편하게 처리할 수 있다.

- pair와 마찬가지로 첫번째 속성을 먼저 비교하고, 동일하면 두번째, 그리고 세번째 순서로 비교한다. 

- tuple<int,int,int> == pair<int,pair<int,int>>> 

```
tuple<int,int,double> t1;
tuple<char,int,double> t2 = make_tuple{'c',3,2.0};
tuple<int,double,int> t3 = {3,5.2,5};
```

```
tuple<int,int,double> t1 = {1,2,3,5};
cout << get<0>(t1);   // 1
cout << get<1>(t1);   // 2
cout << get<2>(t1);   // 3.5
```

