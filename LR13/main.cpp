#include "intmod.h"
#include <stdio.h>

int main() {
    IntMod obj1(3, 7);
    IntMod obj2(4, 7);

    IntMod result = obj1 + obj2;
    printf("%d\n", result.getValue());

    obj1 += obj2;
    printf("%d\n", obj1.getValue());

    result = obj1 - obj2;
    printf("%d\n", result.getValue());

    obj1 -= obj2;
    printf("%d\n", obj1.getValue());

    result = obj1 * obj2;
    printf("%d\n", result.getValue());

    obj1 *= obj2;
    printf("%d\n", obj1.getValue());

    result = obj1 / obj2;
    printf("%d\n", result.getValue());

    obj1 /= obj2;
    printf("%d\n", obj1.getValue());

    printf("%d\n", obj1 == obj2);
    printf("%d\n", obj1 != obj2);
    printf("%d\n", obj1 > obj2);
    printf("%d\n", obj1 >= obj2);
    printf("%d\n", obj1 < obj2);
    printf("%d\n", obj1 <= obj2);

    return 0;
}
