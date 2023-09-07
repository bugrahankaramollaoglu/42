// creating and killing child processes

/* proses nedir? bir program hdd'de saklanan komutlar bütünüdür.
bir programı çalıştırdığımzda OS bu komutları sırasıyla RAM'e alarak
çalıştırır. işte bu çalışma sürecindeki her bir programa bir proses diyoruz.
program hdd'de, proses ram'de saklanır. */

/* her prosesin kendine ana stackten ve heapten ayrılmış yeri vardır. bu sayede
bir program default olarak bir başka programın bu hafıza alanlarına erişemez. */

/* tüm prosesleri görmek için <ps -e> komutunu kullanırız. belli bir programın pid'sini
öğrenmek içinse <pidof programName> kullanırız. mesela pidof firefox */

/* her pid'in bir de parent pid'si yani ppid'si vardır. bir prosesten başka alt bir
proses yaratırsan bunun adı child process olur. her child process kendi childlarını yaratabilir
mesela shell'de <ls -l> komutunu kullandık. bu emri işlemek için shell programı kendi child
prosesini yaratır ve bu işlemi ona yaptırır. eğer direkt kendi yapmaya kalksaydı aynı anda (aynı pid ile)
iki proses çalışamayacağından overwritten olurdu ve asıl shell programımız kapanırdı */

/* unixte ilk başta init isimli program çalışır. bunun pid'i 1'dir. bütün diğer şeyler bundan türer. */



