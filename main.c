#include "ft_printf.h"
#include <stdio.h>


int main(){
	char c = 0;
	unsigned long long a;
	long long b= -10371024712094712, d;

	/*printf("%d\n",printf("|%*p%-135.109d|\n", -15,(void*)15603137398285451084lu, 1482420587));
	printf("%d\n",ft_printf("|%*p%-135.109d|\n", -15,(void*)15603137398285451084lu, 1482420587));*/
	/*printf("%-0*.20p|\n", 20, &c);
	ft_printf("%-0*.20p|\n", 20, &c);
	printf("%0*p|\n", 20, &c);
	ft_printf("%0*p|\n", 20, &c);
	printf("%0*d|\n", 8, -123);
	ft_printf("%0*d|\n",8, -123);
	printf("%-.*d|\n", 7, -123);
	ft_printf("%-.*d|\n",7, -123);*/
	printf("%0d|\n",-12);
	ft_printf("%0d|\n",-12);
}
