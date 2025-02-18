## 참조자의 도입
```cpp
#include <iostream>

int change_val(int *p) {
    *p = 3;
    return 0;
}
int main() {
    int number = 5;
    std::cout << number << std::endl;
    change_val(&number);
    std::cout << number << std::endl;
    return 0;
}
```
위 코드를 보면 단순히 change_val 함수의 인자 p 에 number의 주소값을 전달하여 *p를 통해 number를 참조하여 number의 값을 3으로 바꾸었다.

C 언어에서는 어떠한 변수를 가리키고 싶을 땐 반드시 포인터를 사용해야만 했다 
하지만 C++에서는 다른 변수나 상수를 가리키는 방법으로 또 다른 방식을 제공하는데 이를 **참조자(reference)** 라고 부른다.

```cpp
#include <iostream>

int main() {
    int a = 3;
    int& another_a = a;
    another_a = 5;
    std::cout << a << std::endl;
    std::cout << another_a << std::endl;
    
    return 0;
}
```
실행 결과
```
5
5
```
```cpp
int a = 3;
```
먼저 위와 같이 int 형 변수인 a를 정의하였고 그 안에 3이란 값을 넣어주었다.
```cpp
int& anoter_a = a;
```
그 후에 위리는 a의 참조가 anoter_a를 정의하였다 이 때 참조자를 정의하는 방법은 가리키고자 하는 타입 뒤에 & 를 붙이면 된다.

포인터 타입의 참조자를 만드려면 int*&로 쓰면 된다.

위와 같이 선언함으로써 anoter_a는 a의 참조자다 라고 공표하게 되었다.
이말은 anoter_a는 a의 또다른 이름이라고 컴파일러에게 알려주는 것이다.
따라서 anoter_a에 어떠한 작업을 수행하든 이는 사실상 a에 그 작업을 하는 것과 마찬가지 이다.

```cpp
anoter_a = 5;
std::cout <<" a : " << a std::endl;
std::cout << "another_a : " another_a << std::endl;
```
따라서 위 처럼 anoter_a에 5를 대입하였지만 실제로 a의 값을 확인하면 5로 바뀌었음을 확인할 수 있다.

참조자는 포인터와 상당히 유사한 개념이다. 포인터 역시 다른 어떤 변수의 주소값을 보관함으로써 해당 변수에 간접적으로 연산을 수행할 수 있기 때문이다.

하지만 레퍼런스와 포인터를 몇 가지 중요한 차이점이 있다.
**레퍼런스를 반드시 처음에 누구의 별명이 될 것인지 지정해야 한다.**

따라서 
```cpp
int& anoter_a;
```
와 같은 문장은 불가능하다.

**레퍼런스가 한 번 별명이 되면 절대로 다른 이의 별명이 될 수 없다.**
레퍼런스의 또 한 가지 중요한 특징으로 한 번 어떤 변수의 참조자가 되버린다면 더 이상 다른 변수를 참조할 수 없게 된다.

```cpp
int a = 10;
int &anoter_a = a;
int b = 3;
another_a  = b; ??
```

another_a = b의 의미
마지막에 another_a = b는 another_a 보고 다른 변수인 b를 가리키라고 하는 것인가? 아니다.
아는 그냥 a에 b의 값을 대입하라는 의미이다 따라서 이는 단지 a = b 와 동일한 의미를 가지게 되는 것이다.


**레퍼런스는 메모리 상에 존재하지 않을 수 도 있다.**
포인터의 경우 특정 변수를 참조하면 메모리 상에서 8 또는 4 바이트를 차지하게 된다.

그런데 레퍼런스의 경우 컴파일럿는 anoter_a를 위해서 메모리 상에 공간을 할당할 필요가 없다고 생각한다.
왜냐하면 another_a가 쓰이는 자리는 모두 a로 바꿔치지 하면 되기 때문이다. 따라서 이 경우 레퍼런스는 메모리 상에 존재하지 않고 된다. 물론 그렇다고 해서 항상 존재하지 않는 것은 아니다.

```cpp
#include <iostream>

int change_val(int &p){
    p = 3;
    return 0;
}

int main(){
    int number = 3;
    std::cout<<number << std::endl;
    change_val(number);
    std::cout<< number << std::endl;
}
```

실행 결과
```
5
3
```
위 코드는 앞고 포인터를 사용해서 number를 change_val 안에 전달한 코드를 참조자를 이용해서 바꿔본 것이다.
먼저 가장 중요한 부분으로
```cpp
int change_val(int &p){}
```
와 같이 함수 인자로 참조가를 받게 하였다.
여기서 int &p로 정의하면 오류가 발생한다고 하였는데
사실 p가 정의되는 순산은 change_val(number) 로 호출할 때 이므로 사실상  int& p = number 가 실행된다고 생각하면 된다.
