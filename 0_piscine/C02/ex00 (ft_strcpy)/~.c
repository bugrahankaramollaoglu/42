char	*ft_strcpy(char *dest, char *src)
{
	int i; // sataç

	i = 0;
	while (src[i]) // while src[i] != '\0' yani src bitene kadar

	{
		dest[i] = src[i]; // kopyalama işlemi
		i++;
	}
	dest[i] = '\0'; // sonuna da null koy
	return (dest);  // finalde de döndür
}