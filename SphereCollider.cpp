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

