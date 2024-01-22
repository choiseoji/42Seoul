#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int cnt_size(char *cmd)
{
	int i = 0;

	while (cmd[i])
		i++;
	return (i);
}

void execute(char **av, char **ev, int i)
{
	av[i] = 0;
	if (execve(av[0], av, ev) < 0)
	{
		write(2, "error: cannot execute ", cnt_size("error: cannot execute "));
		write(2, av[0], cnt_size(av[0]));
		write(2, "\n", 1);
		exit(1);
	}
}

int main(int ac, char **av, char **ev)
{
	int i;
	int fd[2];
	int prev_fd;
	pid_t pid;

	ac = 0;
	i = 0;
	prev_fd = 0;
	while (av[i] && av[i + 1])
	{
		av = &av[i + 1];   // 새로운 cmd 시작 주소

		// ;나 파이프 만날 때까지 지나가기
		i = 0;
		while (av[i] && strcmp(av[i], ";") != 0 && strcmp(av[i], "|") != 0)
			i++;

		if (i == 0)
			continue;
		if (strcmp(av[0], "cd") == 0)
		{
			if (i != 2)
				write(2, "error: cd: bad arguments\n", cnt_size("error: cd: bad arguments\n"));
			else if (chdir(av[1]) < 0)
			{
				write(2, "error: cd: cannot change directory to ", cnt_size("error: cd: cannot change directory to "));
				write(2, av[1], cnt_size(av[1]));
				write(2, "\n", 1);
			}
		}
		else if (av[i] == 0 || strcmp(av[i], ";") == 0)   // 결과를 stdout으로
		{
			// prev_fd에서 읽어와서 1로 출력
			pid = fork();
			if (pid == 0)
			{
				dup2(prev_fd, 0);
				dup2(1, 1);
				if (prev_fd)
					close(prev_fd);

				execute(av, ev, i);
			}
			else
			{
				// 자식에서는 안쓰는 fd 닫고 wait
				if (prev_fd)
					close(prev_fd);

				while (waitpid(-1, 0, 0) != -1)
					;
				prev_fd = 0;  // 이 다음 명령은 파이프의 이전 값에서 받아올게 없으므로 입력에서 받아와야 함
			}
		}
		else if (strcmp(av[i], "|") == 0)  // 결과를 파이프의 쓰기 쪽에
		{
			// prev_fd에서 읽어와서 fd[1]로 출력
			pipe(fd);
			pid = fork();
			if (pid == 0)
			{
				dup2(prev_fd, 0);
				dup2(fd[1], 1);
				close(fd[0]);
				close(fd[1]);
				if (prev_fd)
					close(prev_fd);

				execute(av, ev, i);
			}
			else
			{
				close(fd[1]);
				if (prev_fd)
					close(prev_fd);
				prev_fd = fd[0];   // 현재 파이프의 읽기 쪽을 복사해둠
			}
		}
	}
	return (0);
}
