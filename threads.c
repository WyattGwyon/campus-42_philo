/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouden <clouden@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 17:22:05 by clouden           #+#    #+#             */
/*   Updated: 2025/11/26 19:36:57 by clouden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

pthread_t tid;

void eat(char *str)
{
	printf("%s is eating\n", str);
}

void *foo(void *arg)
{
	printf("you have created a thread: FOO\n");
	eat("FOO");
	pthread_exit(NULL);

	printf("This will not print\n");
	return (NULL);
}

void *threadFunc(void *arg)
{
	printf("Thread function \n");
	return ((void *)0);
}

void *thread_routine(void *arg)
{
	printf("New created thread\n");
	return (arg);
}

void *bar(void *arg)
{
	printf("you have created thread: BAR\n");
	eat("BAR");
	pthread_exit(NULL);
}

void *wait_fn(void *arg)
{
	sleep(2);
	printf("Done.\n");
	return (NULL);
}

int main(void)
{
//	pthread_t thread_id;
//	void *thread_result;

//	pthread_create(&thread_id, NULL, thread_routine, NULL);
//	printf("Master thread\n");
//	pthread_join(thread_id, &thread_result);

	pthread_t thread;

	int err = pthread_create(&thread, NULL, wait_fn, NULL);
	if (err != 0)
	{
		printf("ERROR: %d\n", err);
		return 1;
	}
	printf("waiting for the thread to end...\n");
	pthread_join(thread, NULL);
	printf("Thread ended.\n");

	return (0);

return (0);
}

