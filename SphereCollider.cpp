#include "SphereCollider.h"
#include <math.h>
#include <stdio.h>

int SphereCollider::CheckCollision(SphereCollider sphereCollider)
{
    //三平方の定理を使う
    int a = location.x - sphereCollider.location.x;
    int b = location.y - sphereCollider.location.y;
    float c = sqrtf(a * a + b * b);

    //それぞれの半径の合計と2点間の距離を比べる
    if (c <= radius + sphereCollider.radius){
        return 1;
    }
    return 0;
}

