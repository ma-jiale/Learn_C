/*极坐标用向量的模和向量相对x轴逆时针旋转的角度来描述该向量。直角坐标用
向量的x轴和y轴的坐标来描述该向量。编写一个程序，读取向量的模和角度（单位度），然后显示x轴和y轴的坐标。*/
#include<stdio.h>
#include<math.h>
#define RECT_TO_POL 4 * atan(1) / 180
typedef struct polar_v   
{
    double magnitude;
    double angle;
} Ploar_v;

typedef struct rect_v
{
    double x;
    double y;
} Rect_v;

Rect_v transform(Ploar_v pv);

int main()
{
    Ploar_v input;
    Rect_v output;
    puts("Enter the magnitude and the angle of the vector");
    while(scanf("%lf %lf", &input.magnitude, &input.angle) == 2)
    {
        output = transform(input);
        printf("The rectangle coordinate of the vector is x = %f y = %f\n", output.x, output.y);
    }
    put("Bye!");
    return 0;
}

Rect_v transform(Ploar_v pv)
{
    Rect_v rv;
    rv.x = pv.magnitude * cos(pv.angle * RECT_TO_POL);
    rv.y = pv.magnitude * sin(pv.angle * RECT_TO_POL);
    return rv;
}
