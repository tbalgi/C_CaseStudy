#include<stdio.h>
#include<stdlib.h>
#define MAX 50

typedef enum
{
    OPPO,
    REALME,
    SAMSUNG,
    NOKIA,
    APPLE,
    ONEPLUS
}OEM;
typedef struct
{
    unsigned int modelno;
    OEM company;
    unsigned int disp_size;
    unsigned int battery;
    unsigned int ram;
    unsigned int storage;
    unsigned int resolution;
    double price;
}mobile;
void printRecords(mobile *phone,int n)
{
    int i=0;
    mobile *pcurr=phone;
    for(i=0;i<n;i++)
    {
        printf("Model Number %u\n",pcurr->modelno);
        printf("OEM %u\n",pcurr->company);
        printf("Display Size %u\n",pcurr->disp_size);
        printf("Battery %u\n",pcurr->battery);
        printf("RAM Size %u\n",pcurr->ram);
        printf("Storage Memory %u\n",pcurr->storage);
        printf("Resolution %u\n",pcurr->resolution);
        printf("Price %2.f\n\n",pcurr->price);
        pcurr++;
    }
}
double average(mobile *phone,int n)
{
    int i=0;
    double av=0,sum=0;
    mobile *pcurr=phone;
    for(i=0;i<n;i++)
    {
        sum=sum+pcurr->price;
        pcurr++;
    }
    av=sum/n;
    return av;
}
unsigned int max_battery(mobile *phone,int n)
{
    unsigned int max_battery_model;
    int i=0,max=0;
    mobile *pcurrb=phone;
    max=pcurrb->battery;
    max_battery_model=pcurrb->modelno;
    pcurrb++;
    for(i=0;i<n;i++)
    {
        if(pcurrb->battery>max)
        {
            max=pcurrb->battery;
            max_battery_model=pcurrb->modelno;
        }
        pcurrb++;
    }
    return max_battery_model;
}
unsigned int max_resolution(mobile *phone,int n)
{
    unsigned int max_resolution_model;
    int i=0,max=0;
    mobile *pcurr=phone;
    max=pcurr->resolution;
    max_resolution_model=pcurr->modelno;
    pcurr++;
    for(i=0;i<n;i++)
    {
        if(pcurr->resolution>max)
        {
            max=pcurr->resolution;
            max_resolution_model=pcurr->modelno;
        }
        pcurr++;
    }
    return max_resolution_model;
}
void min_storage(mobile *phone,int n)
{
    unsigned int min=0;
    int i=0,count=0;
    mobile *pcurrs=phone;
    min=pcurrs->storage;
   for(i=0;i<n;i++)
    {
        if(pcurrs->storage<min)
        {
            min=pcurrs->storage;
        }
        pcurrs++;
    }
    mobile *pcurr=phone;
    for(i=0;i<n;i++)
       {
           if(pcurr->storage==min)
            count++;
           pcurr++;
       }
   printf("The number of models with the minimum storage of %uGB is %d\n",min,count);
}

int no_pricerange(mobile *phone,int n)
{
    //Taking the price range as 15,000 to 25,000
    int counter=0,i=0;
    mobile *pcurr=phone;
    for(i=0;i<n;i++)
    {
        if(pcurr->price>=15000 && pcurr->price<=25000)
            counter++;
        pcurr++;
    }
    printf("The number of models in the range of 15,000 to 25,000 is %d\n",counter);
}

void model_add(mobile *phone,int *length,unsigned int modelno,int company,unsigned int disp_size,unsigned int battery,unsigned int ram,unsigned int storage,unsigned int resolution,double price)
{
    int l=*length;
    mobile *pcurr=&phone[l];
    pcurr->modelno=modelno;
    switch(company)
    {
        case(0): pcurr->company=OPPO;
                 break;
        case(1): pcurr->company=REALME;
                 break;
        case(2): pcurr->company=SAMSUNG;
                 break;
        case(3): pcurr->company=NOKIA;
                 break;
        case(4): pcurr->company=APPLE;
                 break;
        case(5): pcurr->company=ONEPLUS;
                 break;
    }
    pcurr->disp_size=disp_size;
    pcurr->battery=battery;
    pcurr->ram=ram;
    pcurr->storage=storage;
    pcurr->resolution=resolution;
    pcurr->price=price;
    ++*length;
}
int main()
{
    //int length=4;
    int length=0;
    double avg;
    unsigned int batterymax,resolutionmax;
    mobile *phone=malloc(MAX*sizeof(mobile));
    //mobile phone[MAX]={{100,NOKIA,16,4000,4,64,48,20000},{101,APPLE,15,2000,7,32,16,15000},{102,APPLE,20,4000,8,32,32,50000},{103,ONEPLUS,18,6000,7,128,16,60000}};
    //printRecords(phone,5);
    //fillRecords(phone,1);
    model_add(phone,&length,100,1,16,4000,4,64,48,20000);
    model_add(phone,&length,101,2,15,2000,7,16,16,15000);
    model_add(phone,&length,102,5,20,4000,8,32,32,50000);
    model_add(phone,&length,103,4,18,6000,7,128,16,60000);
    model_add(phone,&length,104,0,16,4000,4,16,32,20000);
    model_add(phone,&length,105,3,16,4000,4,32,128,20000);
    printRecords(phone,length);
    avg=average(phone,length);
    printf("The average price is %lf\n",avg);
    batterymax=max_battery(phone,length);
    printf("The model with the maximum battery is %u\n",batterymax);
    resolutionmax=max_resolution(phone,length);
    printf("The model with the maximum resoltuion is %u\n",resolutionmax);
    no_pricerange(phone,length);
    min_storage(phone,length);
    free(phone);
}
