#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

// eğer bir child process bitmeden main biterse o child
// asla bitemez, buna zombie process denir

#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* a zombie process or defunct process is a process that has
completed execution (via the exit system call) but still has
an entry in the process table: it is a process in the
"Terminated state". This occurs for the child processes,
where the entry is still needed to allow the parent process
to read its child's exit status: once the exit status is
read via the wait system call, the zombie's entry is
removed from the process table and it is said to be "reaped".
A child process always first becomes a zombie before being
removed from the resource table. In most cases, under normal
system operation zombies are immediately waited on by their
parent and then reaped by the system. */

/* ps aux | grep Z
ile zombi prosesleri kontrol edebilirsin */

int main(void)
{
	pid_t pids[10];
	int i;

	for (i = 9; i >= 0; --i)
	{
		pids[i] = fork();
		if (pids[i] == 0)
		{
			printf("Child%d\n", i);
			sleep(i + 1);
			_exit(0);
		}
	}

	for (i = 9; i >= 0; --i)
	{
		printf("parent%d\n", i);
		waitpid(pids[i], NULL, 0);
	}

	return 0;
}

/* In the first loop, the original (parent) process forks 10 copies of itself.
Each of these child processes (detected by the fact that fork() returned zero)
prints a message, sleeps, and exits. All of the children are created at essentially
the same time (since the parent is doing very little in the loop), so it is
somewhat random when each of them gets scheduled for the first time - thus
the scrambled order of their messages.During the loop, an array of child process
IDs is built. There is a copy of the pids[] array in all 11 processes, but only
in the parent is it complete - the copy in each child will be missing the lower-numbered
child PIDs, and have zero for its own PID. (Not that this really matters, as
only the parent process actually uses this array.)The second loop executes only
in the parent process (because all of the children have exited before this point),
and waits for each child to exit. It waits for the child that slept 10 seconds
first; all the others have long since exited, so all of the messages (except the
first) appear in quick succession. There is no possibility of random ordering
here, since it is driven by a loop in a single process. The first parent message
actually appeared before any of the children messages - the parent was able to
continue into the second loop before any of the child processes were able to start.
This again is just the random behavior of the process scheduler - the "parent9"
message could have appeared anywhere in the sequence prior to "parent8".Child0
through Child8 spend one or more seconds in this state, between the time they
exited and the time the parent did a waitpid() on them. The parent was already
waiting on Child9 before it exited, so that one process spent essentially no time
as a zombie */
