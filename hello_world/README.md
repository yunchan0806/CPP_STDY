```cpp
#include <iostream>
```

C++ 표준 라이브러리로 C++에서 표준 입출력에 필요한 것들을 포함하고 있다. 예를 들어 코드에서 사용되는 `std::cout`이나 `std::endl`과 같은 것들을 말한다. C와 다르게 헤더 파일 뒤에 `.h`가 붙지 않는다.

### Namespace - 이름 공간

`cout` 앞에 붙어있는 `std`는 C++ 표준 라이브러리의 모든 함수, 객체 등이 정의된 이름 공간(namespace)이다. namespace란 어떤 정의된 객체에 대해 어디 소속인지 지정해주는 것과 동일하다.

코드가 길어짐에 따라 중복되는 함수의 이름들이 생기기 시작하여 C++에서는 이름 구분하기 위해 같은 이름이라도 소속된 이름 공간이 다르면 다른 것으로 취급하게 되었다.

```cpp
std::cout
```

위의 경우 `std`라는 이름 공간에 정의되어 있는 `cout`을 의미한다. 만약에 `std::` 없이 그냥 `cout`이라고 한다면 컴파일러가 `cout`을 찾지 못한다.

### 이름 공간을 정의하는 방법

이름 공간을 정의하는 방법은 아래와 같다.

```cpp
namespace header1 {
    int foo();
    void bar();
}

namespace header2 {
    int foo();
    void bar();
}
```

자기 자신이 포함되어 있는 이름 공간 안에서는 굳이 앞에 이름 공간을 명시하지 않고 자유롭게 부를 수 있다. 예를 들어

```cpp
#include <header1.h>

namespace header1 {
    int func() {
        foo(); // 알아서 header1::foo() 가 실행된다.
    }
}
```

`header1` 이름 공간 안에서 `foo`를 부른다면 알아서 `header1::foo()`를 호출하게 된다. 만약 `header1` 공간 안에서 `header2`의 `foo`를 호출하고 싶다면 아래와 같이 표현할 수 있다.

```cpp
#include "header1.h"
#include "header2.h"

namespace header1 {
    int func() {
        foo();
        header2::foo();
    }
}
```

반면 어떠한 이름 공간에 소속되지 않는 경우라면 아래와 같이 명시적으로 이름 공간을 지정해야 한다.

```cpp
#include "header1.h"
#include "header2.h"

int func() {
    header1::foo();
}
```

### using

매번 namespace를 적기 귀찮다면 `using` 선언을 사용하면 된다.

```cpp
#include "header1.h"
#include "header2.h"

using header1::foo;

int main() {
    foo();
}
```

아니면 그냥 기본적으로 `header1`에 정의된 모든 것들을 소속 명시 없이 사용하고 싶다면

```cpp
#include "header1.h"
#include "header2.h"

using namespace header1;

int main() {
    foo();
    bar();
}
```

### namespace로 static 처럼 사용하기

이름 없는 namespace를 사용하면 그 공간 안에 정의된 변수나 함수는 해당 파일 내부에서만 접근이 가능하다.

```cpp
#include <iostream>

namespace {
    int a;
    void hellow();
}

int main() {
    hellow();
    a = 3;
}
```