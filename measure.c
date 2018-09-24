#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
    int n,i,j,flag;
    float c[10][2],mal[10][5],dis[10],ang[10],result=0,a=0,b=0,p,q,r,s;
    /*float r,t,phi,x1,x2,y1,y2,z1,z2,ang,result;*/
    char in[10][9];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;;j++)
        {
            scanf("%c",&in[i][j]);
            if(in[i][j]=='E')
            break;
            else if(in[i][j]=='W')
            break;
        }
    }    
    for(i=0;i<n;i++)
    {flag=0;
    a=0;
    b=0;
        for(j=0;;j++)
    {   
        if(flag==0)
        {
            if('0'<=in[i][j]&&in[i][j]<='9')
            {
                a=a*10.0+(in[i][j]-'0');
            }
            else if(in[i][j]=='N')
            {
                c[i][0]=a*(3.14/180.0);
               
            }
            else if(in[i][j]=='S')
            {
                c[i][0]=-a*(3.14/180.0);
                
            }
            else if(in[i][j]==',')
                flag=1;
        }
        else
        {
          if('0'<=in[i][j]&&in[i][j]<='9')
            {
                b=b*10.0+(in[i][j]-'0');
            }
            else if(in[i][j]=='E')
            {
                c[i][1]=b*(3.14/180);
                
                break;
            }
            else if(in[i][j]=='W')
            {   
                b=360-b;
                c[i][1]=b*(3.14/180);
                
                break;
            }
             
        }
    }
    }
   for(j=0;j<n;j++) 
   {
       mal[j][0]=c[j][0];
       mal[j][1]=c[j][1];
   }
   for(j=0;j<n;j++) 
   {
       mal[j][2]=6400*cos(c[j][1])*cos(c[j][0]);
       mal[j][3]=6400*cos(c[j][1])*sin(c[j][0]);
       mal[j][4]=6400*sin(c[j][1]);
   }
   for(j=0;j<n;j++)
   {p=(mal[j][2]-mal[j+1][2])*(mal[j][2]-mal[j+1][2]);
    q=(mal[j][3]-mal[j+1][3])*(mal[j][3]-mal[j+1][3]);
    r=(mal[j][4]-mal[j+1][4])*(mal[j][4]-mal[j+1][4]);
       dis[j]=sqrt(p+q+r);
   }
   for(j=0;j<n;j++)
   {s=dis[j]/(2*6400);
       ang[j]=2*(asin(s));
   }
   for(j=0;j<n;j++)
   {
       result=result+(6400*ang[j]);
   }
   printf("%f",result);
 getch();

}


