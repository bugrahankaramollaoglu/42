## fixed point numbers

	source = [https://slideplayer.biz.tr/slide/15272171/]

	* fixed point numbers bir sayı 43.5239, 2.36, 0.042 vs. gibi olabilir. üç
	bölümden oluşur: sayının integer kısmı, binary point noktası ve fractional partı.

	* bir kesirli sayı fixed point number'a nasıl çevrilir? öncelikle fixed pointin fractional kısma ayıracağı bit sayısını bilmemiz lazım. bu kısma
	ne kadar çok bit ayırırsa o kadar daha hassas ama daha az doğru, az ayırırsa da tersi bir durum geçerli olacak. mesela 6.75 şeklinde bir sayımız olsun.
	bu sayının önce integer partını binarye çeviricez sonra fractional partını daha sonra araya nokta koyacağız.
	6 = 101. peki .75 nasıl çevrilecek? 0.75 sayısını noktanın sağındaki sayı 0 olana ya da 8 bit birikene kadar sürekli kendisiyle topluyoruz, eğer sonucun
	int kısmı 1 ise 1, 0sa 0 yazıyoruz. her bir oldugunda 1 olan integeri 0lıyoruz. mesela

	[6.75 = 101.11]

	0.75 + 0.75 = 1.50

	0.50 + 0.50 = 1.00

	yani 6.75 ondalık kesri 2li sistemde fixedPointNumber gösterimi 101.11'miş.

	* fixed point sayilar floating point sayılara göre hassasiyetleri daha yüksek ama daha dar aralığı kapsayan sayılardır.

	* fixed sayılarda noktanın yeri değişmez. mesela toplamda 4 bit ayrılmış bir fixed point sayı
		01.01
		01.10
		00.11
		11.00 olabilir

	ama floating sayilarda noktanın yeri "kayabilir"

		1.0010
		10.101
		1111.1 şeklinde gösterimler mümkündür

	* floating point sayılar 4 parttan oluşur: sign, mantissa, base ve exponent.
	yani bir floating sayı = +/- mantis x taban^üst şeklinde ifade edilir. eğer en soldaki
	sign biti 0sa sayı (+), 1se sayı (-)dir. eğer mantisin bitleri fazla olursa precision artar,
	exponente ayrılan bitler fazla olursa trueness artar. örnek:

		-241.65 = -0.24165 x 10^3
		bu gösterimde - işaret, 24165 sayısı mantissa, 10 taban 3 de üstür.2

		0.0028 = 0.28 x 10^-2

		110.11 = 0.11011 x 2^3

	bilindiği gibi bilimsel gösterimde taban kısım 0 ile 10 arasında olacak şekilde yeniden yazılır.

