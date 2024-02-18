#include<stdio.h>
#include "2a.h"
static int mode = METRIC;
static int distance;
static double fuel;

void set_mode(int mode_)
{
    if (mode_ != METRIC && mode_ != US)
    {
        printf("Invalid mode specified. ");
        if(mode == METRIC)
        {
            printf("Mode 0(metric) used\n");
        }
        else
        {
            printf("Mode 1(US) used\n");            
        }
    }
    else
    {
        mode = mode_;
    }
}

void get_info()
{
    if (mode == METRIC)
    {
        printf("Enter distance traveled in kilometers: ");
        scanf("%d", &distance);
        printf("Enter fuel consumed in liters: ");
        scanf("%lf", &fuel);
    }
    else
    {
        printf("Enter distance traveled in miles: ");
        scanf("%d", &distance);
        printf("Enter fuel consumed in gallons: ");
        scanf("%lf", &fuel);        
    }
}

void show_info()
{
    if (mode == METRIC)
    {
        printf("Fuel consumption is %.2lf liters per 100km\n", fuel / (double)distance * 100);
    }
    else
    {
        printf("Fuel consumption is %.1lf miles per gallon\n", (double)distance / fuel);       
    }
}
