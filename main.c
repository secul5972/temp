#include "ft_printf.h"
#include <stdio.h>


int main(){
	char c = 0;
	unsigned long long a;
	long long b= -10371024712094712, d;

	printf("%d\n",printf("|%*p%-135.109d|\n", -15,(void*)15603137398285451084lu, 1482420587));
	printf("%d\n",ft_printf("|%*p%-135.109d|\n", -15,(void*)15603137398285451084lu, 1482420587));
}
