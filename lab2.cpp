#include <stdio.h>
//Currency constants
/*
Guide to names on constants
CHF = SWISS FRANC = F Suffix
USD = US DOLLAR = U suffix
GBP = BRITISH POUND = B suffix
CAD = CANADIAN DOLLAR = C suffix
EUR = EURO = E suffix
AUD = AUSTRAILIAN DOLLAR = A suffix
*/
const double chfu=1.046873, chfg=0.809468, chfc=1.308991,chfe=0.874051,chfa=1.314145, chf=1;
const double usd=1, usdg=1.293053,	usdc=0.799948, usde=1.19755,	usda=0.796558, usdf=0.955226;
const double gbpu=0.7734,	gbp=1, gbpc=0.61868, gbpe=	0.926117,	gbpa=0.616039, gbpf=1.144098;
const double cadu=1.249946, cadg=	1.616329, cad=	1, cade=1.497088, cada=0.995887, cadf=0.763947;
const double euru=0.835015,	eurg=1.079732, eurc=	0.667956, eur=	1, eura =0.665163, eurf=1.144098;
const double audu=1.255655, audg=1.623394, audc=1.00444,aude=1.503324, aud=1, audf=0.760951;
int main(void)
{	
	float amt;
	printf("Please Enter your amount of currency: "); 
	scanf("%f", &amt);//get usser data
	printf("\n\tUSD\tGBP\tCAD\tEUR\tAUD\tCHF\n"); //top row of table
	printf("=========================================================\n");
	printf("USD|%f|%f|%f|%f|%f|%f\n", amt*usd, amt*usdg, amt*usdc, amt*usde, amt*usda, amt*usdf); //print out amount*each conversion rate
	printf("GBP|%f|%f|%f|%f|%f|%f\n", amt*gbpu, amt*gbp, amt*gbpc, amt*gbpe, amt*gbpa, amt*gbpf);
	printf("CAD|%f|%f|%f|%f|%f|%f\n", amt*cadu, amt*cadg, amt*cad, amt*cade, amt*cada, amt*cadf);
	printf("EUR|%f|%f|%f|%f|%f|%f\n", amt*euru, amt*eurg, amt*eurc, amt*eur, amt*eura, amt*eurf);
	printf("AUD|%f|%f|%f|%f|%f|%f\n", amt*audu, amt*audg, amt*audc, amt*aude, amt*aud, amt*audf);
	printf("CHF|%f|%f|%f|%f|%f|%f\n", amt*chfu, amt*chfg, amt*chfc, amt*chfe, amt*chfa, amt*chf);
	return 0;
}
