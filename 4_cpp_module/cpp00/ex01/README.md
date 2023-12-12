## 📌 클래스에 대해 알아보자!

**객체 지향 프로그래밍(OOP)이란??**

객체의 상태와 행동을 구체화하는 형태의 프로그래밍이다.

객체 지향 프로그래밍은 다음과 같은 특징을 갖는다.

1. 추상화
2. 캡슐화
3. 정보 은닉
4. 상속성
5. 다형성

**인스턴스란?**

클래스를 사용하려면 클래스 타입의 객체를 선언해야 한다.

해당 클래스 타입의 객체를 인스턴스라고 한다. → 클래스에 소속된 개별적인 객체

**클래스 선언**

```cpp
class 클래스이름
{
	접근제어지시자1 : 
		멤버변수1타입 멤버변수1이름;
		멤버변수2타입 멤버변수2이름;

		멤버함수1원형
};
```

**접근 제어 지시자**

→ 정보 은닉을 위해 필요하다

public : 모든 객체에서 접근 가능

private : 해당 객체 내의 멤버 변수나 멤버 함수만이 접근 가능

**멤버 함수 정의**

클래스 밖에서 멤버 함수를 정의할 때, 범위 지정 연산자(::)을 사용하여 어느 클래스에 소속된 함수인지 명시해야 한다.

```cpp
반환타입 클래스이름::멤버함수이름(매개변수 목록){함수의 몸체;}
```

하나의 클래스에서 생성된 인스턴스는 각각 독립된 메모리 공간에 저장된 자신만의 멤버 변수를 가지지만, 멤버 함수는 모든 인스턴스가 공유함.

**this 포인터**

모든 멤버 함수가 자신만의 this 포인터를 가지고 있음

![Screen Shot 2023-12-06 at 4.24.05 PM.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/61a8a981-c556-43e7-ba92-26dcc7ed460b/e2f24556-b87c-4b0a-a228-432b7ed38613/Screen_Shot_2023-12-06_at_4.24.05_PM.png)

## 생성자

클래스를 가지고 객체를 생성하면, 해당 객체는 메모리에 즉시 생성됨

→ 이 객체는 모든 멤버 변수를 초기화하기 전에 사용 불가능

**생성자**

객체의 생성과 동시에 멤버 변수를 초기화해주는 멤버함수 (해당 클래스의 이름과 같음)

- 초기화를 위한 데이터를 인수로 전달 받음
- 반환값이 없지만, void형으로 선언하지 않음
- 여러 개의 생성자를 가질 수 있음

생성자 선언 

→ 반환값을 명시하지 않음

→ 생성자의 원형은 클래스 선언의 public 에 포함되어야 함

```cpp
Book(const string& title, int total_page);
```

```cpp
// 멤버 변수 초기화
Book::Book(const string& title, int total_page)
{
	title_ = title;
	total_page_ = total_page;
}
```

## 디폴트 생성자

객체가 생성될 때 사용자가 초기값을 명시하지 않으면, 컴파일러가 자동으로 제공하는 생성자

```cpp
Book::Book() {}
```

디폴트 생성자를 정의하는 법

- 함수 오버로딩을 이용한 방법
- 디폴트 인수를 이용한 방법

```cpp
Book web_book;  // 디폴트 생성자의 암시적 호출
Book web_book = Book(); // 디폴트 생성자의 명시적 호출
Book *ptr_book = new Book();  // 디폴트 생성자의 암시적 호출
```

## 복사 생성자

대입 연산자를 사용하면 얕은 복사(shallow copy)가 수행됨

얕은 복사 : 값을 복사하는 것이 아닌, 값을 가리키는 포인터를 복사하는 것

**복사 생성자**
새롭게 생성되는 객체가 원본 객체와 같으면서도, 완벽한 독립성을 가지게 해줌 → 깊은 복사이기 때문

```cpp
Book::Book(const Book& origin)   // 복사 생성자의 선언
{
	title_ = origin.title_;
	totla_page_ = origin.total_page_;
	...
}

int main(void)
{
	Book web_book("HTML과 CSS", 350);
	Book html_book(web_book);  // html_book 객체는 web_book객체를 복사한 객체임 (web_book으로 초기화 한 것임)
}
```

## 소멸자

객체의 수명이 끝나면 컴파일러에 의해 자동으로 호출되며, 사용이 끝난 객체를 정리해줌

```cpp
~Book():   // Book 클래스의 소멸자
Book::~Book() {}
```

**소멸자 호출 시기**

| 메모리 영역 | 소멸자 호출 시기 |
| --- | --- |
| 데이터(data) 영역 | 해당 프로그램이 종료될 때 |
| 스택(stack) 영역 | 해당 객체가 정의된 블록을 벗어날 때 |
| 힙(heap) 영역 | delete를 사용하여 해당 객체의 메모리를 반환할 때 |
| 임시 객체 | 임시 객체의 사용을 마쳤을 때 |