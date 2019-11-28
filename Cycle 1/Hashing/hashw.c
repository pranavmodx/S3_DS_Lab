#include<stdio.h>
#include<string.h>

int main() {
	const int tableSize = 26, 
		    wordLength = 15, 
			textLength = tableSize * wordLength;

	char hashTable[tableSize][wordLength],
		hashTable2[tableSize][wordLength],
		text[textLength],
		word[wordLength],
		searchWord[wordLength];

	int i, j, k, 
		key,
		searchKey,
		searchKey2,
		searchCount,
		searchCount2;

	for (i=0; i<tableSize; i++)
		strcpy(hashTable[i], "0");

	for (i=0; i<tableSize; i++)
		strcpy(hashTable2[i], "0");

	gets(text);

	// Linear Probing Hashing
	for(i=0; i<strlen(text); i++) {
		j = 0;

		while (text[i] != ' ' && text[i] != '\0')
			word[j++] = text[i++];
		word[j] = '\0';

		key = word[0] % tableSize;
	
		if (strcmp(hashTable[key], "0") == 0) {
			strcpy(hashTable[key], word);
		}

		else {
			while (strcmp(hashTable[key], "0") != 0)
				key = (key + 1) % tableSize;

			strcpy(hashTable[key], word);
		}	
	}

	printf("The hash table after linear probing is : \n");
	for (i=0; i<tableSize; i++)
		printf("%s \n", hashTable[i]);

	// Quadratic Probing Hashing
	for(i=0; text[i] != '\0'; i++) {
		j = 0;
        k = 1;

		while (text[i] != ' ' && text[i] != '\0')
			word[j++] = text[i++];
		word[j] = '\0';

		key = word[0] % tableSize;
	
		if (strcmp(hashTable2[key], "0") == 0)
			strcpy(hashTable2[key], word);

		else {
			while (strcmp(hashTable2[key], "0") != 0 && k <= tableSize) {
				key = (key + (k * k)) % tableSize;
                k++;
            }

			if (k > tableSize) {
				printf("All slots are either filled or there aren't \
				 		any ideal slots for the element to be filled.");
				break;
			}

			strcpy(hashTable2[key], word);
		}	
	}

	printf("The hash table after quadratic probing is : \n");
	for (i=0; i<tableSize; i++)
		printf("%s \n", hashTable2[i]);	

	printf("Enter a word to search : ");
	scanf("%s", searchWord);

	searchKey = searchWord[0] % tableSize;
	searchKey2 = searchWord[0] % tableSize;

	if (hashTable[searchKey] == searchWord) {
		searchCount = 1;
		searchCount2 = 1;
	}

	else {
		searchCount = 1;
		searchCount2 = 1;
		k = 1;

		// Linear Probing Searching
		while (strcmp(hashTable[searchKey], searchWord) != 0 && searchCount <= tableSize) {
			searchKey = (searchKey + 1) % tableSize;
			searchCount++;
		}

		// Quadratic Probing Searching
		while (strcmp(hashTable2[searchKey2], searchWord) != 0 && searchCount2 <= tableSize) {
			searchKey2 = (searchKey2 + (k * k)) % tableSize;
			searchCount2++;
			k++;
		}
	}

	if (searchCount <= tableSize) {
		printf("Linear Probing \n");
		printf("The word is at index : %d \n", searchKey);
		printf("Number of key comparisons done : %d \n", searchCount);
	}
	else {
		printf("Search unsuccessful \n");
	}

	printf("\n");

	if (searchCount2 <= tableSize && k <= tableSize) {
		printf("Quadratic Probing \n");
		printf("The word is at index : %d \n", searchKey2);
		printf("Number of key comparisons done : %d \n", searchCount2);
	}
	else {
		printf("Search unsuccessful \n");
	}
	
	return 0;
}
