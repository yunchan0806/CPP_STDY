프로그램이 정확하게 실행되기 위해서는 컴파일 시에 모든 변수의 주소값이 확정되어야만 했다. 하지만 이를 위해서는 프로그램에 많은 제약이 따르기 때문에 프로그램 실행 시에 자유롭게 할당하고 해제할 수 있는 힙이라는 공간이 따로 생겼다.

이전에 컴파일러에 의해 어느 정도 안정성이 보장되는 스택과는 다르게 힙은 사용자가 스스로 제어해야 하는 부분인 만큼 책임이 따르게 된다.

C 언어에서는 `malloc`과 `free` 함수를 지원하여 힙 상에서의 메모리 할당을 지원하였다.
C++에서도 마찬가지로 `malloc`과 `free` 함수를 사용할 수 있다.

하지만 언어 차원에서 지원하는 것으로 바로 `new`와 `delete`라고 할 수 있다.
`new`는 말 그대로 `malloc`과 대응되는 것으로 메모리를 할당하고 `delete`는 `free`에 대응되는 것으로 메모리를 해제한다.

```cpp
#include <iostream>

int main() {
  int* p = new int;
  *p = 10;

  std::cout << *p << std::endl;

  delete p;
  return 0;
}
```
실행 결과: 10

`new`를 사용하는 방법:
```cpp
T* pointer = new T;
```

`new`로 배열 할당하기:
```cpp
#include <iostream>
int main() {
    int arr_size;
    std::cout << "Enter the size of the array: ";
    std::cin >> arr_size;
    int* list = new int[arr_size];
    for (int i = 0; i < arr_size; i++) {
        std::cin >> list[i];
    }
    
    for (int i = 0; i < arr_size; i++) {
        std::cout << list[i] << " ";
    }

    delete[] list;
    return 0;
}
```

먼저 위와 같이 배열의 크기를 잡을 `arr_size`라는 변수를 정의하였고 그 값을 입력받는다. 그리고 `list`에 `new`를 이용하여 크기가 `arr_size`인 `int` 배열을 생성하였다.
배열을 생성할 때 `[]`를 이용해 배열의 크기를 넣어주면 된다.

