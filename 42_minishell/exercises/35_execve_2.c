#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// execve(programName, argsProgramMayTake, EnvVars);

int main(int ac, char **av, char **env)
{
	char *s = "/usr/bin/gcc";
	char *argList[] = {"gcc", "./35_execve_2.c", NULL};
	execve(s, argList, env);
}

// bu proses içinde gcc prosesini çalıştırdık.
