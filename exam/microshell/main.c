// 일단 세미콜론 만날 때 까지 한 처리
// 그 안에서는 파이프 만나면 새로운 프로세스 생성해주기
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct s_info
{
	int prev_fd[2];
	int cur_fd[2];
}	t_info;

void init_fd(t_info *info)
{
	info->prev_fd[0] = 0;
	info->prev_fd[1] = 0;
	info->cur_fd[0] = 0;
	info->cur_fd[1] = 0;
}

void pipex(int st, int en, char **av, char **ev, int cnt_process)
{
	t_info	info;
	int		st_process;
	int		en_process;
	int		cnt = 1;
	pid_t 	pid;

	init_fd(&info);
	while (st < en)
	{
		st_process = st;
		while (av[st] && strcmp(av[st], "|") != 0)
			st++;   // 한 프로세스 그냥 지나가주기
		en_process = st;

		// execve 에 사용할 cmd 완성
		char **cmd = (char **)malloc(sizeof(char *) * (en_process - st_process));
		int i = 0;
		while (st_process < en_process)
		{
			cmd[i] = strdup(av[st_process]);
			st_process++;
			i++;
		}

		// 파이프에 넘겨주기
		if (cnt > 2)
		{
			close(info.prev_fd[0]);
			close(info.prev_fd[1]);
		}
		info.prev_fd[0] = info.cur_fd[0];
		info.prev_fd[1] = info.cur_fd[1];

		pid = fork();
		if (pid == 0)
		{
			if (cnt == 1)  // 내가 첫 프로세스
			{
				dup2(0, 0);
				if (cnt_process != 1)  // 넘겨줄 프로세스가 있음
					dup2(info.cur_fd[1], 1);
				else
					dup2(1, 1);
				if (execve(cmd[0], cmd, ev) < 0)
					exit(1);
			}
			else if (cnt == cnt_process)  // 내가 마지막 프로세스
			{
				dup2(info.prev_fd[0], 0);
				dup2(1, 1);
				if (execve(cmd[0], cmd, ev) < 0)
					exit(1);
			}
			else   // 내가 중간 프로세스
			{
				dup2(info.prev_fd[0], 0);
				dup2(info.cur_fd[1], 1);
				if (execve(cmd[0], cmd, ev) < 0)
					exit(1);
			}
		}
		st++;
		cnt++;
	}
	// wait 해줘야 함
	close(info.cur_fd[0]);
	close(info.cur_fd[1]);
	close(info.prev_fd[0]);
	close(info.prev_fd[1]);

	int j = 0;
	while (j < cnt_process)
	{
		waitpid(-1, 0, 0);
		j++;
	}
}

int main(int ac, char **av, char **ev)
{
	int		i;
	int		cnt_pipe;
	int		start;
	int		end;

	i = 0;
	start = 0;
	while (i < ac - 1)
	{
		start = i;    // 한 묶음의 시작
		cnt_pipe = 0;
		while (av[i] && strcmp(av[i], ";") != 0)
		{
			if (strcmp(av[i], "|") == 0)    // 프로세스 개수 세주기
				cnt_pipe++;
			i++;
		}
		end = i;   // 한 묶음 끝
		pipex(start, end, av, ev, cnt_pipe + 1);
		i++;   // 쉼표 건너뛰기
		write(1, "\n", 1);
	}
	return (0);
}
