#include "ft_printf.h"
#include <stdio.h>


int main(){
	char c = 'a';
	char s[10] = "dddffff";
	int num = 10;
    int *t = &num;
	int n = 30;

	/*printf("[%c]sdfsdf[%3.4s]dfdfsdf\n",c,s);
	ft_printf("[%c]sdfsdf[%3.4s]dfdfsdf\n",c,s);
	printf("[%c]sdfsdf[%6.4s]dfdfsdf\n",c,s);
	ft_printf("[%c]sdfsdf[%6.4s]dfdfsdf\n",c,s);
	printf("[%c]sdfsdf[%3.10s]dfdfsdf\n",c,s);
	ft_printf("[%c]sdfsdf[%3.10s]dfdfsdf\n",c,s);
	printf("[%c]sdfsdf[%12.10s]dfdfsdf\n",c,s);
	ft_printf("[%c]sdfsdf[%12.10s]dfdfsdf\n",c,s);
	printf("[%-c]sdfsdf[%-12.10s]dfdfsdf\n",c,s);
	ft_printf("[%-c]sdfsdf[%-12.10s]dfdfsdf\n",c,s);
	printf("[%0c]sdfsdf[%03.4s]dfdfsdf\n",c,s);
	ft_printf("[%0c]sdfsdf[%03.4s]dfdfsdf\n",c,s);
	

	printf("ddfsd[%10.3d]k\n", 2000);
	ft_printf("ddfsd[%10.3d]k\n", 2000);
	printf("ddfsd[%10.5d]k\n", 200);
	ft_printf("ddfsd[%10.5d]k\n", 200);
	printf("ddfsd[%010d]k\n", 200);
	ft_printf("ddfsd[%010d]k\n", 200);
	printf("ddfsd[%10.13d]k\n", 200);
	ft_printf("ddfsd[%10.13d]k\n", 200);
	printf("ddfsd[%-*.2d]d\n", 10, 200);
	ft_printf("ddfsd[%-*.2d]d\n", 10,200);
	printf("ddfsd[%-*.5d]d\n", 10, 200);
	ft_printf("ddfsd[%-*.5d]d\n", 10,200);
	printf("ddfsd[%*.2d]d\n", 10, 200);
	ft_printf("ddfsd[%*.2d]d\n", 10,200);
	printf("ddfsd[%*.5d]d\n", 10, 200);
	ft_printf("ddfsd[%*.5d]d\n", 10,200);

	printf("ddfsd[%-*.2u]u\n", 10, 200);
	ft_printf("ddfsd[%-*.2u]u\n", 10,200);
	printf("ddfsd[%-*.5u]u\n", 10, 200);
	ft_printf("ddfsd[%-*.5u]u\n", 10,200);
	printf("ddfsd[%*.2u]u\n", 10, 200);
	ft_printf("ddfsd[%*.2u]u\n", 10,200);
	printf("ddfsd[%*.5u]u\n", 10, 200);
	ft_printf("ddfsd[%*.5u]u\n", 10,200);

	printf("%10.6d\n",-123);
	ft_printf("%10.6d\n",-123);
	printf("%.6d\n",-21474836687);
	ft_printf("%.6d\n",-21474836687);
	printf("%.6d\n",-2147483648);
	ft_printf("%.6d\n",-2147483648);

	printf("x[%-*.10x]x\n", 20, 123456789);
	ft_printf("x[%-*.10x]x\n", 20, 123456789);
	printf("%%[%-*.10X]X\n", 20, 123456789);
	ft_printf("%%%d%%[%-*.10X]X\n", 10, 20, 123456789);

	printf("%.18p\n",s);
	ft_printf("%.18p\n",s);


	printf("1 >%*p<\n", n, t);
    printf("2 >%-*p<\n", n, t);
    printf("3 >%*.*p<\n", n, n, t);	//warning
    printf("4 >%-p<\n", t);
    printf("5 >%-.p<\n", t);
    printf("6 >%.p<\n", t);
    printf("7 >%10.4p<\n", t);	//warning
    printf("8 >%.4p<\n", t);	//warning
    printf("9 >%.1p<\n", t);	//warning
    printf("A >%.p<\n", t);
	
	ft_printf("1 >%*p<\n", n, t);
    ft_printf("2 >%-*p<\n", n, t);
    ft_printf("3 >%*.*p<\n", n, n, t);	//warning
    ft_printf("4 >%-p<\n", t);
    ft_printf("5 >%-.p<\n", t);
    ft_printf("6 >%.p<\n", t);
    ft_printf("7 >%10.4p<\n", t);	//warning
    ft_printf("8 >%.4p<\n", t);	//warning
    ft_printf("9 >%.1p<\n", t);	//warning
    ft_printf("A >%.p<\n", t);
	*/
	int a = 0;
	printf("%0.d\n", a);
	ft_printf("%0.d\n", a);
}
