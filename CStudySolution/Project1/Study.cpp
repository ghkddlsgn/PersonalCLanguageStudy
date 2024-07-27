#include <stdio.h>
#include <stdlib.h>

#define CHECK_CNT
#define LEVEL 2

int main()
{
	int *NumberArray;
	int NumberArrayLength = -1;
	int sum = 0;
	float result = -1.f;

	scanf_s("%d", &NumberArrayLength, sizeof(NumberArrayLength));

	NumberArray = (int*)malloc(sizeof(*NumberArray)*NumberArrayLength);

	if (NumberArray == NULL) //assert
	{
		printf("Memory allocate fail on NumberArray");
		return 1;
	}

	for (int i = 0; i < NumberArrayLength; i++) //input
	{
		scanf_s("%d", &NumberArray[i]);
		if (NumberArray[i] <= 0)
		{
			printf("need to input only positive number");
			return 1;
		}
		sum += NumberArray[i];

		#ifdef CHECK_CNT
			printf("Positive Number count : %d, Sum value : %d\n", i+1, sum);
		#endif // print count and sum
		
		#if LEVEL == 2
			printf("Current Average Value %f\n", (float)sum/float(i+1));
		#endif
	}

	if (NumberArrayLength != 0)
	{
		result = sum/NumberArrayLength;
		printf("total average value : %f", result);
	}
	else if (NumberArrayLength == -1)
	{
		printf("NumberArrayLength is -1, it's not initialize");
		return 1;
	}

	return 0;
}