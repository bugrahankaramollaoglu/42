
#include <stdio.h>
#include <unistd.h>

/* terminale

echo " \e[1;1H\e[2J"

yazarsan terminal temizlenir. aynı kodu write ya da printf ile kullanırsan da aynı sey olur
 */

int main() {
	write(1, " \e[1;1H\e[2J", 12);
	printf(" \e[1;1H\e[2J");
}
