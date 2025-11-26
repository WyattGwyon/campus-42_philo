#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

pthread_mutex_t lock;
int j;

void *eat_process(void *arg)
{
	pthread_mutex_lock(&lock);

	int i = 0;
	j++;

	printf("Eating\n");
	while (i < 5)
	{
		printf("%d", j);
		sleep(1);
		i++;
	}
	printf("...Done\n");
	pthread_mutex_unlock(&lock);
	return (NULL);
}

int main(void)
{
	pthread_t t1, t2;

	if (pthread_mutex_init(&lock, NULL) != 0)
	{
		printf("Mutex initialization failed.\n");
		return (1);
	}
	j = 0;
	pthread_create(&t1, NULL, eat_process, NULL);
	pthread_create(&t2, NULL, eat_process, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_mutex_destroy(&lock);
	return (0);
}
