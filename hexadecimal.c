// if positive:
// 
#include <unistd.h> 

int print_hexa(int long num, int len)
{
	static int kount;
	
	kount = num;  
     if (num < 0)
     {
          num *= -1;
          kount +=write (1, "-", 1);
     }
     if (num >= 16)                         //16 cause F is 15
     {
          print_hexa (num / 16, kount);
          print_hexa (num % 16, kount);
     }
     if (num < 16 && num > 9)
     {
          num = num + 39 + '0';//39 cause there are the lowercase letters -> ASCII
          kount += write (1, &num , 1);
     }
     if (num < 16)
     {
          num = num + '0';
          kount += write (1, &num, 1);
     }
	num = kount;
	kount = 0;
     return(num);
}