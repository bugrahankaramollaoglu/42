#include <iostream>

/* fixed ve float sayılar saklanırken 754 standartı kullanılır. */

/* fixed-point-numbers are numbers that have a certain
amount of bit-length for both the integer and the rounding part.
mesela fixed sayimiz AA.BBB ise aralığı 00.001 - 99.999 olur (+ farz edersek)
spesifik sayıda precision istediğimiz durumlarda bunu kullaniyoruz. */

/* a floating point number however does not reserve a spesific
number of bits for the parts. instead, it reserves a certain number of bits
for the whole number (also aka significand, mantissa, coefficient) and a certain
number of bits to say where withiin that number the decimal place sits.

float bir sayı şöyle gösterilir:
12.345 = 12345 x 10^-3

mantissa: 12345
exponent: -3
base: 10

float allocates 23 bit for the number, 8 bit for exponent and 1 bit for sign */

/* accuracy (doğruluk) vs. precision (kesinlik)

if you allocate more bits for the rounding part, you
get more accuracy. If you allocate more bits for the
integer part, you get more precision.

mesela 16 bitimiz olsun. bununla 20.32 gibi bir sayıyı
göstereceğiz. eğer accuracy'yı arttırmak istiyorsak,
16 bitin 8'ini integer part'a, 8'ini rounding part'a
ayırabiliriz. böylece 8 bitlik rounding part ile
-327.67 ile +327.67 arasındaki sayıları gösterebiliriz.
böylece geniş bir aralığı arttırırız yani doğruluk (accuracy)
fazla olur ama derinlik az olur. 20.32 sayisinda 32'den sonraki
ondalık kısımları gösteremeyiz. yani kesinlik (precision) azalır.

precision arttırmak istiyorsak, 16 bitin 4'ünü integer part'a,
12'sini rounding part'a ayırabiliriz. böylece 12 bitlik rounding
part ile -7.9375 ile +7.9375 arasındaki sayıları gösterebiliriz.
böylelikle derinliği artar ama temsil edebildiği sayı aralığı azalır.

fixed point sayılar accuracy'yi arttırmak için kullanılırken,
floating point sayılar precision'ı arttırmak için kullanılır.

*/

/* how to convert from fixed point number to binary?

mesela 19.45 şeklinde bir sayımız olsun. bunu binary'ye çevirmek için
önce 19'un binary karşılığını buluruz (10011). daha sonra ondalık kısmı
başına 0 atarak sürekli kendisiyle toplarız ve integer kısmı 1 çıkmayan
bütün toplamlar için 0, çıkanlar için 1 koyarız. 1 çıktığı durumlarda da
1'i değil yine ondalık kısmını alırız. mesela

0.45 + 0.45 = 0.90 -> 0
0.90 + 0.90 = 1.80 -> 1
0.80 + 0.80 = 1.60 -> 1
0.60 + 0.60 = 1.20 -> 1
0.20 + 0.20 = 0.40 -> 0
0.40 + 0.40 = 0.80 -> 0
0.80 + 0.80 = 1.60 -> 1
0.60 + 0.60 = 1.20 -> 1
0.20 + 0.20 = 0.40 -> 0
0.40 + 0.40 = 0.80 -> 0
0.80 + 0.80 = 1.60 -> 1
0.60 + 0.60 = 1.20 -> 1
...

yani ondalık kısmımız 01110011001100110011... şeklinde sonsuza kadar gider.

19.45 sayısı binary'de : 10011.0111 oldu */
