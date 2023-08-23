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

int SphereCollider::CheckCollisionBox(SphereCollider sphereCollider)
{                                     //右上のｘ座標
    //if (sphereCollider.location.x > location.x + 100 + sphereCollider.radius) {
    //    //false
    //}
    //                                  //左上のｘ座標
    //if (sphereCollider.location.x < location.x - sphereCollider.radius) {
    //    //false
    //}
    //                                  //右上のｙ座標
    //if (sphereCollider.location.y < location.y - 5 - sphereCollider.radius) {
    //    //false
    //}
    //                                  //左上のｙ座標
    //if (sphereCollider.location.y > location.y + 5 + sphereCollider.radius) {
    //    //false
    //}

    if (sphereCollider.location.x <= location.x + 100 + sphereCollider.radius && sphereCollider.location.x >= location.x - sphereCollider.radius
        && sphereCollider.location.y >= location.y - 5 - sphereCollider.radius && sphereCollider.location.y <= location.y + 5 + sphereCollider.radius) {

        return TRUE;

    }


    return FALSE;;
}

