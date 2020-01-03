#include<stdio.h>
#include<string.h>

int main() {
	const int tSize = 26, 
		    wLen = 15, 
			tLen = tSize * wLen;

	char hashT[tSize][wLen],
		hashT2[tSize][wLen],
		text[tLen],
		word[wLen],
		sWord[wLen];

	int i, j, k, 
		key,
		sKey,
		sKey2,
		sCount,
		sCount2;

	for (i=0; i<tSize; i++)
		strcpy(hashT[i], "0");

	for (i=0; i<tSize; i++)
		strcpy(hashT2[i], "0");

	gets(text);

	// Linear Probing Hashing
	for(i=0; i<strlen(text); i++) {
		j = 0;

		while (text[i] != ' ' && text[i] != '\0')
			word[j++] = text[i++];
		word[j] = '\0';

		key = word[0] % tSize;
	
		if (strcmp(hashT[key], "0") == 0) {
			strcpy(hashT[key], word);
		}

		else {
			while (strcmp(hashT[key], "0") != 0)
				key = (key + 1) % tSize;

			strcpy(hashT[key], word);
		}	
	}

	printf("The hash table after linear probing is : \n");
	for (i=0; i<tSize; i++)
		printf("%s \n", hashT[i]);

	// Quadratic Probing Hashing
	for(i=0; text[i] != '\0'; i++) {
		j = 0;
        k = 1;

		while (text[i] != ' ' && text[i] != '\0')
			word[j++] = text[i++];
		word[j] = '\0';

		key = word[0] % tSize;
	
		if (strcmp(hashT2[key], "0") == 0)
			strcpy(hashT2[key], word);

		else {
			while (strcmp(hashT2[key], "0") != 0 && k <= tSize) {
				key = (key + (k * k)) % tSize;
                k++;
            }

			if (k > tSize) {
				printf("All slots are either filled or there aren't \
				 		any ideal slots for the element to be filled.");
				break;
			}

			strcpy(hashT2[key], word);
		}	
	}

	printf("The hash table after quadratic probing is : \n");
	for (i=0; i<tSize; i++)
		printf("%s \n", hashT2[i]);	

	printf("Enter a word to search : ");
	scanf("%s", sWord);

	sKey = sWord[0] % tSize;
	sKey2 = sWord[0] % tSize;

	if (hashT[sKey] == sWord) {
		sCount = 1;
		sCount2 = 1;
	}

	else {
		sCount = 1;
		sCount2 = 1;
		k = 1;

		// Linear Probing Searching
		while (strcmp(hashT[sKey], sWord) != 0 && sCount <= tSize) {
			sKey = (sKey + 1) % tSize;
			sCount++;
		}

		// Quadratic Probing Searching
		while (strcmp(hashT2[sKey2], sWord) != 0 && sCount2 <= tSize) {
			sKey2 = (sKey2 + (k * k)) % tSize;
			sCount2++;
			k++;
		}
	}

	if (sCount <= tSize) {
		printf("Linear Probing \n");
		printf("The word is at index : %d \n", sKey);
		printf("Number of key comparisons done : %d \n", sCount);
	}
	else {
		printf("Search unsuccessful \n");
	}

	printf("\n");

	if (sCount2 <= tSize && k <= tSize) {
		printf("Quadratic Probing \n");
		printf("The word is at index : %d \n", sKey2);
		printf("Number of key comparisons done : %d \n", sCount2);
	}
	else {
		printf("Search unsuccessful \n");
	}
	
	return 0;
}
