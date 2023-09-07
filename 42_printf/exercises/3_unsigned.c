#include <stdio.h>

/* unsigned int veri tipi 0+ sayıları tutar. işaretli sayılardaki
en soldaki sign bitini de sayi olarak kullanabildiği için aralığı
2 katına çıkar. */

/* unsigned bir sayıya negatif verip %d ile yazdırmaya
çalışırsan negatif sayiyi alirsin çünkü unsigned olarak
tanımlasan da %d implicit casting uygular ve integer'a çevirir.
doğal sonucu görmek istiyosan %u ile yazdırmalısın o da -32
sayısını 4294967264'e çevirir. sebebi şu: bir negatif sayının
binary karşılığı şöyle bulunur: önce sayının pozitif halinin
binary karşılığı bulunur. sonra bu binary sayıya 2's complement
uygulanır yani ~num olayı (yani 1ler 0, 0lar 1 yapılır). daha sonra
bu sayıya 1 eklenir. bunu -32 için yaparsak: 32'nin binary karşılığı
00000000000000000000000000100000'dir. 2's complement uyguladığımızda
11111111111111111111111111011111 elde ederiz. 1 eklediğimizde de
11111111111111111111111111100000 elde ederiz. bu sayı da onluk
tabanda 4294967264'tür. */

int main()
{
	unsigned int num = -32;
	printf("%u\n", num); // 4294967264
	printf("%d\n", num); // -32
}
