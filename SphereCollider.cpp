#include "SphereCollider.h"
#include <math.h>
#include <stdio.h>

int SphereCollider::CheckCollision(SphereCollider sphereCollider)
{
    //�O�����̒藝���g��
    int a = location.x - sphereCollider.location.x;
    int b = location.y - sphereCollider.location.y;
    float c = sqrtf(a * a + b * b);

    //���ꂼ��̔��a�̍��v��2�_�Ԃ̋������ׂ�
    if (c <= radius + sphereCollider.radius){
        return 1;
    }
    return 0;
}

int SphereCollider::CheckCollisionBox(SphereCollider sphereCollider)
{                                     //�E��̂����W
    //if (sphereCollider.location.x > location.x + 100 + sphereCollider.radius) {
    //    //false
    //}
    //                                  //����̂����W
    //if (sphereCollider.location.x < location.x - sphereCollider.radius) {
    //    //false
    //}
    //                                  //�E��̂����W
    //if (sphereCollider.location.y < location.y - 5 - sphereCollider.radius) {
    //    //false
    //}
    //                                  //����̂����W
    //if (sphereCollider.location.y > location.y + 5 + sphereCollider.radius) {
    //    //false
    //}

    if (sphereCollider.location.x <= location.x + 100 + sphereCollider.radius && sphereCollider.location.x >= location.x - sphereCollider.radius
        && sphereCollider.location.y >= location.y - 5 - sphereCollider.radius && sphereCollider.location.y <= location.y + 5 + sphereCollider.radius) {

        return TRUE;

    }


    return FALSE;;
}

