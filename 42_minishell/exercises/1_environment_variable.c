
#include <stdio.h>

/* what is an environment variable?
An environment variable is a named value that is stored in the
OS's environment and can be accessed by programs running on that system.
here are some environment variables
	1) PATH
	2) HOME
	3) USER
	4) LANG */

/* ortam değişkenleri (environment variables) nedir? OS'de tutulan, her program ve proses tarafından
erişilebilen değişkenlere denir. genelde capital yazılır. en bilinenleri sunlardır
	1) PATH: executable dosyaların tutuldugu konumu bilgisini saklar
	2) HOME: kullanıcının ana dizininin konum bilgisini saklar
	3) USER: kullanıcı adının bilgisini saklar
	4) LANG: sistem dil bilgisini saklar vs.
ortam değişkenleri birkaç farklı şekilde yaratılabilir
	1) terminalde [unixlerde] 'export' komutuyla. <export a=10> gibi. [windowsta] ise set ile.
	2) .bashrc'ye script eklenerek.
	3) API çağrılarıyla vs.
[unixlerde] <env> ya da <printenv> diyerek ortam değişkenlerini görebilirsin. [windowsta] set ile. */

int main(int args_count, char **args_array, char **environment)
{
	int i = 0;
	while (environment[++i])
		printf("%s\n", environment[i]);
}
